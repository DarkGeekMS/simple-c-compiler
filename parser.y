%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "parser.h"

/* prototypes */
nodeType *opr(int oper, int nops, ...);
nodeType *id(int i);
nodeType *con(int value);
void freeNode(nodeType *p);
int ex(nodeType *p);
int yylex(void);

void yyerror(char *s);
int sym[26];                    /* symbol table */
%}


%union {
    int iValue;                 /* integer value */
    float fValue;
    char cValue;
    char* sValue;
    int bValue;

    char sIndex;                /* symbol table index */
    nodeType *nPtr;             /* node pointer */
};

%token <iValue> INTEGER
%token <fValue> FLOAT
%token <cValue> CHAR
%token <sValue> STRING
%token <bValue> BOOLEAN

%token INT_TYPE
%token FLOAT_TYPE
%token CHAR_TYPE
%token STRING_TYPE
%token BOOLEAN_TYPE


%token <sIndex> VARIABLE
%token CONST
%token WHILE IF PRINT
%token DECLARATION
%token DEFINITION
%token DO FOR SWITCH CASE BREAK DEFAULT RETURN VOID FUNCTION VOIDFUNCTION FUNCVARLIST CALLVARLIST CALL
%nonassoc IFX
%nonassoc ELSE


%right ASSIGNMENT
%left OR
%left AND
%left EQEQ NOTEQ
%left G L GE LE
%left PLUS MINUS
%left MUL DIV MOD
%right NOT
%nonassoc UMINUS

%type <nPtr> stmt expr stmt_list

%%


program:
        function                { exit(0); }
        ;

function:
          function stmt         { ex($2); freeNode($2); }
        | /* NULL */
        ;

assign: 
    VARIABLE ASSIGNMENT expr ';'              { $$ = opr(ASSIGNMENT, 2, id($1), $3); }   
;
data:
    INTEGER             {$$ = con($1);}
    | FLOAT             {$$ = con($1);}
    | CHAR              {$$ = con($1);}
    | STRING            {$$ = con($1);}
    | BOOLEAN           {$$ = con($1);} 
;

data_type:
    INT_TYPE                 {$$ = $1;}
    | FLOAT_TYPE             {$$ = $1;}
    | CHAR_TYPE              {$$ = $1;}
    | STRING_TYPE            {$$ = $1;}
    | BOOLEAN_TYPE           {$$ = $1;} 
;

stmt:
          ';'                                                               { $$ = opr(';', 2, NULL, NULL); }
        | expr ';'                                                          { $$ = $1; }
        | PRINT expr ';'                                                    { $$ = opr(PRINT, 1, id($2)); }


        | data_type VARIABLE ';'                                            { $$ = opr(DECLARATION, 2, $1, id($2)); }    
        | data_type VARIABLE ASSIGNMENT expr ';'                            { $$ = opr(DEFINITION, 3, $1, id($2), $4); }
        
        | CONST data_type VARIABLE ASSIGNMENT expr ';'                      { $$ = opr(CONST, 3, $2, id($3), $5); }
        
        | assign                                                            { $$ = $1; }

        | WHILE '(' expr ')' stmt                                           { $$ = opr(WHILE, 2, $3, $5); }
        | DO stmt WHILE '(' expr ')' ';'                                    { $$ = opr(DO, 2, $5, $2); }

        | IF '(' expr ')' stmt %prec IFX                                    { $$ = opr(IF, 2, $3, $5); }
        | IF '(' expr ')' stmt ELSE stmt                                    { $$ = opr(IF, 3, $3, $5, $7); }
        | FOR '(' assign ';' expr ';' assign ')' stmt                       { $$ = opr(FOR, 4, $3, $5, $7, $9); }
        | SWITCH '(' expr ')' case_list                                     { $$ = opr(SWITCH, 2, $3, $5); }
        | BREAK ';'                                                         { $$ = $1;}
        | data_type VARIABLE func_list '{' stmt RETURN expr ';' '}'         {$$ = opr(FUNCTION, 5, $1, id($2), $3, $5, $7);}
        | VOID VARIABLE func_list stmt                                      {$$ = opr(VOIDFUNCTION, 3, id($2), $3, $4);}
        | '{' stmt_list '}'                                                 { $$ = $2; }
        ;

func_var_list:
          data_type VARIABLE                                                { $$ = opr(DECLARATION, 2, $1, id($2)); }
        | func_var_list ',' data_type VARIABLE                              { $$ = opr(FUNCVARLIST, 3, $1, $3, id($4)); }
        ;

func_list:
    '(' func_var_list ')'        {$$ = $2;}
    | '(' ')'                    {$$ = NULL;}
;

call_var_list:
          VARIABLE                                                          { $$ = id($1); }
        | call_var_list ',' VARIABLE                                        { $$ = opr(CALLVARLIST, 2, $1, id($3)); }
        ;

call_list:
    '(' call_var_list ')'          {$$ = $2;}
    | '(' ')'                      {$$ = NULL;}
;

stmt_list:
          stmt                     { $$ = $1; }
        | stmt_list stmt           { $$ = opr(';', 2, $1, $2); }
        ;

case_stmt: CASE data ':' stmt;     { $$ = opr(CASE, 2, $2, $4); };

default_stmt: DEFAULT ':' stmt;    { $$ = opr(DEFAULT, 1, $3); };

case_list:
        default_stmt               { $$ = $1; }
    | case_stmt case_list          { $$ = opr('CASE_LIST', 2, $1, $2); }
        ;


expr:
          data                                              { $$ = $1; }
        | VARIABLE                                          { $$ = id($1); }
        | MINUS expr %prec UMINUS                           { $$ = opr(UMINUS, 1, $2); }
        | NOT expr                                          { $$ = opr(NOT, 1, $2); }
        | expr PLUS expr                                    { $$ = opr(PLUS, 2, $1, $3); }
        | expr MINUS expr                                   { $$ = opr(MINUS, 2, $1, $3); }
        | expr MUL expr                                     { $$ = opr(MUL, 2, $1, $3); }
        | expr DIV expr                                     { $$ = opr(DIV, 2, $1, $3); }
        | expr MOD expr                                     { $$ = opr(MOD, 2, $1, $3); }
        | expr L expr                                       { $$ = opr(L, 2, $1, $3); }
        | expr G expr                                       { $$ = opr(G, 2, $1, $3); }
        | expr GE expr                                      { $$ = opr(GE, 2, $1, $3); }
        | expr LE expr                                      { $$ = opr(LE, 2, $1, $3); }
        | expr NOTEQ expr                                   { $$ = opr(NOTEQ, 2, $1, $3); }
        | expr EQEQ expr                                    { $$ = opr(EQEQ, 2, $1, $3); }
        | expr AND expr                                     { $$ = opr(AND, 2, $1, $3); }
        | expr OR expr                                      { $$ = opr(OR, 2, $1, $3); }
        | VARIABLE call_var_list ';'                        { $$ = opr(CALL, 2, id($1), $2);}
        | '(' expr ')'                                      { $$ = $2; }
        ;

%%

nodeType *con(int value) {
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeCon;
    p->con.value = value;

    return p;
}

nodeType *id(int i) {
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeId;
    p->id.i = i;

    return p;
}

nodeType *opr(int oper, int nops, ...) {
    va_list ap;
    nodeType *p;
    int i;

    /* allocate node, extending op array */
    if ((p = malloc(sizeof(nodeType) + (nops-1) * sizeof(nodeType *))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    return p;
}

void freeNode(nodeType *p) {
    int i;

    if (!p) return;
    if (p->type == typeOpr) {
        for (i = 0; i < p->opr.nops; i++)
            freeNode(p->opr.op[i]);
    }
    free (p);
}

void yyerror(char *s) {
    fprintf(stdout, "%s\n", s);
}

int main(void) {
    yyparse();
    return 0;
}
