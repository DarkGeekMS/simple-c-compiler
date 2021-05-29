%{
    #include <stdio.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include "parser.h"
    /* prototypes */
    nodeType *opr(int oper, int nops, ...);
    nodeType *id(int i);
    nodeType *con(int value);
    void freeNode(nodeType *p);
    int yylex(void);
    void yyerror(char *);
    
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
%token <sIndex> VARIABLE
%token WHILE IF PRINT
%nonassoc IFX
%nonassoc ELSE
%token DECLARATION
%token DEFINITION

%right ASSIGNMENT
%left OR
%left AND
%left EQEQ NOTEQ
%left G L GE LE
%left PLUS MINUS
%left MUL DIV MOD
%right NOT
%nonassoc UMINUS
%left PLUSPLUS MINUSMINUS 

%type <nPtr> stmt expr stmt_list

%%


program:
        function                { exit(0); }
        ;

function:
          function stmt         { ex($2); freeNode($2); }
        | /* NULL */
        ;


stmt:
          ';'                                       { $$ = opr(';', 2, NULL, NULL); }
        | expr ';'                                  { $$ = $1; }
        | PRINT expr ';'                            { $$ = opr(PRINT, 1, id($2)); }
        | INTEGER VARIABLE ';'                      { $$ = opr(DECLARATION, 2, $1, id($2)); }    
        | INTEGER VARIABLE ASSIGNMENT expr ';'      { $$ = opr(DEFINITION, 3, $1, id($2), $4); }
        | FLOAT VARIABLE ';'                        { $$ = opr(DECLARATION, 2, $1, id($2)); }   
        | FLOAT VARIABLE ASSIGNMENT expr ';'        { $$ = opr(DEFINITION, 3, $1, id($2), $4); }              
        | CHAR VARIABLE ';'                         { $$ = opr(DECLARATION, 2, $1, id($2)); }   
        | CHAR VARIABLE ASSIGNMENT expr ';'         { $$ = opr(DEFINITION, 3, $1, id($2), $4); }
        | STRING VARIABLE ';'                       { $$ = opr(DECLARATION, 2, $1, id($2)); }   
        | STRING VARIABLE ASSIGNMENT expr ';'       { $$ = opr(DEFINITION, 3, $1, id($2), $4); }
        | BOOLEAN VARIABLE ';'                      { $$ = opr(DECLARATION, 2, $1, id($2)); }   
        | BOOLEAN VARIABLE ASSIGNMENT expr ';'      { $$ = opr(DEFINITION, 3, $1, id($2), $4); }
        | VARIABLE ASSIGNMENT expr ';'              { $$ = opr(ASSIGNMENT, 2, id($1), $3); }
        | WHILE '(' expr ')' stmt                   { $$ = opr(WHILE, 2, $3, $5); }
        | IF '(' expr ')' stmt %prec IFX            { $$ = opr(IF, 2, $3, $5); }
        | IF '(' expr ')' stmt ELSE stmt            { $$ = opr(IF, 3, $3, $5, $7); }
        | '{' stmt_list '}'                         { $$ = $2; }
        ;

stmt_list:
          stmt                  { $$ = $1; }
        | stmt_list stmt        { $$ = opr(';', 2, $1, $2); }
        ;

expr:
          INTEGER                   { $$ = con($1); }
        | VARIABLE                  { $$ = id($1); }
        | '-' expr %prec UMINUS     { $$ = opr(UMINUS, 1, $2); }
        | expr PLUS expr            { $$ = opr(PLUS, 2, $1, $3); }
        | expr MINUS expr           { $$ = opr(MINUS, 2, $1, $3); }
        | expr MUL expr             { $$ = opr(MUL, 2, $1, $3); }
        | expr DIV expr             { $$ = opr(DIV, 2, $1, $3); }
        | expr L expr               { $$ = opr(L, 2, $1, $3); }
        | expr G expr               { $$ = opr(G, 2, $1, $3); }
        | expr GE expr              { $$ = opr(GE, 2, $1, $3); }
        | expr LE expr              { $$ = opr(LE, 2, $1, $3); }
        | expr NOTEQ expr           { $$ = opr(NOTEQ, 2, $1, $3); }
        | expr EQEQ expr            { $$ = opr(EQEQ, 2, $1, $3); }
        | '(' expr ')'              { $$ = $2; }
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
