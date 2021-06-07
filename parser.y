%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "parser.h"
#define YYERROR_VERBOSE

/* prototypes */

    nodeType *opr(int oper, int nops, ...);     // for operations
    nodeType *id(char* id);                     // for identifiers
    nodeType *typ(conEnum value);               // for types defining
    nodeType *con();
    nodeType *conInt(int value);                // to add integer value
    nodeType *conFloat(float value);            // to add float value
    nodeType *conBool(bool value);
    nodeType *conChar(char value);
    nodeType *conString(char* value);
    void freeNode(nodeType *p);
    void yyerror(char *);
    int yylex(void);

    int execute(nodeType *p);                   // to execute the program code

    extern FILE* yyin;                          // the input file

    int yylineno;
%}


%union {
    int iValue;                 /* integer value */
    float fValue;               // float value
    char cValue;                // character value
    char* sValue;               // string
    char* sIndex;                /* symbol table index */
    nodeType *nPtr;             /* node pointer */
};

// Data
%token <iValue> INTEGER
%token <fValue> FLOAT
%token <cValue> CHAR
%token <sValue> STRING
%token <iValue> BOOLEAN_TRUE 
%token <iValue> BOOLEAN_FALSE
%token <sIndex> VARIABLE

// data types
%token INT_TYPE FLOAT_TYPE CHAR_TYPE STRING_TYPE BOOLEAN_TYPE CONST VOID

// identifiers
%token IF ELSE DO WHILE FOR SWITCH CASE DEFAULT BREAK  RETURN     // Keywords

%token FUNCTION VOIDFUNCTION FUNCVARLIST CALLVARLIST CALL SYMBOLTABLE

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

%type <nPtr> stmt expr stmt_list type func_var_list func_list call_var_list call_list case_default case_list func_stmt_list

%%

program:
                        
         program stmt                                                                          {execute($2); freeNode($2);}    
        | /* NULL */
        ;

type:
        INT_TYPE                                                                                { $$ =  typ(typeInt); } 
    |   FLOAT_TYPE                                                                              { $$ =  typ(typeFloat); }
    |   CHAR_TYPE                                                                               { $$ =  typ(typeChar); }
    |   BOOLEAN_TYPE                                                                            { $$ =  typ(typeBool); }
    |   STRING_TYPE                                                                             { $$ =  typ(typeString); }
    |   VOID                                                                                    { $$ =  typ(typeVoid); }
    ;

stmt:
          ';'                                                                                   { $$ = opr(';', 2, NULL, NULL); }
        | expr ';'                                                                              { $$ = $1; }

        | type VARIABLE ';'                                                                     { $$ = opr('d', 2, $1, id($2)); }    
        | type VARIABLE ASSIGNMENT expr ';'                                                     { $$ = opr(ASSIGNMENT, 3, $1, id($2), $4); }
        | CONST type VARIABLE ASSIGNMENT expr ';'                                               { $$ = opr(ASSIGNMENT,4,typ(typeConst),$2,id($3),$5); }
        | VARIABLE ASSIGNMENT expr ';'                                                          { $$ = opr(ASSIGNMENT, 2, id($1), $3); } 

        | WHILE '(' expr ')' stmt                                                               { $$ = opr(WHILE, 2, $3, $5); }
        | DO stmt WHILE '(' expr ')' ';'                                                        { $$ = opr(DO, 2, $2, $5); }
        | FOR '(' VARIABLE ASSIGNMENT expr ';' expr ';' VARIABLE ASSIGNMENT expr ')' stmt       { $$ = opr(FOR,4,     opr(ASSIGNMENT, 2, id($3), $5)   ,$7,    opr(ASSIGNMENT, 2, id($9), $11)    ,$13); }
                                                                                                    
        | IF '(' expr ')' stmt %prec IFX                                                        { $$ = opr(IF, 2, $3, $5); }
        | IF '(' expr ')' stmt ELSE stmt                                                        { $$ = opr(IF, 3, $3, $5, $7); }

        | SWITCH '(' VARIABLE ')' '{' case_list case_default '}'                                { $$ = opr(SWITCH,3,id($3),$6,$7); }
        | BREAK ';'                                                                             { $$ = opr(BREAK,0); }
        | type VARIABLE func_list '{' func_stmt_list '}'                                        { $$ = opr(FUNCTION, 4, $1, id($2), $3, $5);}
        | VOID VARIABLE func_list '{' stmt_list '}'                                             { $$ = opr(VOIDFUNCTION, 3, id($2), $3, $5);}
        | VOID VARIABLE func_list '{' '}'                                                       { $$ = opr(VOIDFUNCTION, 3, id($2), $3, NULL);}
        | '{' stmt_list '}'                                                                     { $$ = opr('s', 1, $2); }
        | '{' '}'                                                                               { $$ = NULL; }
        |   error ';'                                                                           { $$ = NULL; }
        |   error '}'                                                                           { $$ = NULL; }
        ;

stmt_list:
          stmt                                                                                  { $$ = $1; }
        | stmt_list stmt                                                                        { $$ = opr(';', 2, $1, $2); }
        ;

case_list:
        case_list CASE INTEGER ':' stmt_list                                                    { $$ = opr(CASE,3,$1,conInt($3),$5); }
    |   case_list CASE CHAR ':' stmt_list                                                       { $$ = opr(CASE,3,$1,conChar($3),$5); }
    |   case_list CASE STRING ':' stmt_list                                                     { $$ = opr(CASE,3,$1,conString($3),$5); }  
    |   case_list CASE BOOLEAN_FALSE ':' stmt_list                                              { $$ = opr(CASE,3,$1,conBool($3),$5);  }
    |   case_list CASE BOOLEAN_TRUE ':' stmt_list                                               { $$ = opr(CASE,3,$1,conBool($3),$5); }
    |  /* NULL */                                                                               { $$ = NULL; }
    ;


case_default: DEFAULT ':' stmt_list                                                             { $$ = opr(DEFAULT, 1, $3); };

expr:
    INTEGER                                                                                     { $$ = conInt($1); }
    | FLOAT                                                                                     { $$ = conFloat($1); }
    | CHAR                                                                                      { $$ = conChar($1); }
    | STRING                                                                                    { $$ = conString($1); }
    | BOOLEAN_TRUE                                                                              { $$ = conBool($1); }
    | BOOLEAN_FALSE                                                                             { $$ = conBool($1); }
    | VARIABLE                                                                                  { $$ = id($1); }
    | MINUS expr %prec UMINUS                                                                   { $$ = opr(UMINUS, 1, $2); }
    | NOT expr                                                                                  { $$ = opr(NOT, 1, $2); }
    | expr PLUS expr                                                                            { $$ = opr(PLUS, 2, $1, $3); }
    | expr MINUS expr                                                                           { $$ = opr(MINUS, 2, $1, $3); }
    | expr MUL expr                                                                             { $$ = opr(MUL, 2, $1, $3); }
    | expr DIV expr                                                                             { $$ = opr(DIV, 2, $1, $3); }
    | expr MOD expr                                                                             { $$ = opr(MOD, 2, $1, $3); }
    | expr L expr                                                                               { $$ = opr(L, 2, $1, $3); }
    | expr G expr                                                                               { $$ = opr(G, 2, $1, $3); }
    | expr GE expr                                                                              { $$ = opr(GE, 2, $1, $3); }
    | expr LE expr                                                                              { $$ = opr(LE, 2, $1, $3); }
    | expr NOTEQ expr                                                                           { $$ = opr(NOTEQ, 2, $1, $3); }
    | expr EQEQ expr                                                                            { $$ = opr(EQEQ, 2, $1, $3); }
    | expr AND expr                                                                             { $$ = opr(AND, 2, $1, $3); }
    | expr OR expr                                                                              { $$ = opr(OR, 2, $1, $3); }
    | VARIABLE call_list                                                                        { $$ = opr('v', 2, id($1), $2);}
    | '(' expr ')'                                                                              { $$ = $2; }
    ;


func_stmt_list:
          RETURN expr ';'                                                                       { $$ = opr(RETURN, 1, $2); }
        | stmt func_stmt_list                                                                   { $$ = opr(';', 2, $1, $2); }
        ;

func_var_list:
          type VARIABLE                                                                         { $$ = opr('r', 2, $1, id($2)); }
        | type VARIABLE ',' func_var_list                                                       { $$ = opr(';', 3, $1, id($2), $4); }
        ;

func_list:
    '(' func_var_list ')'                                                                       {$$ = $2;}
    | '(' ')'                                                                                   {$$ = NULL;}
;

call_var_list:
          expr                                                                                  { $$ = $1; }
        | call_var_list ',' expr                                                                { $$ = opr('c', 2, $1, $3); }
        ;

call_list:
    '(' call_var_list ')'                                                                       {$$ = $2;}
    | '(' ')'                                                                                   {$$ = NULL;}
;



%%

/* routines */

nodeType *typ(conEnum type){
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeDef;
    p->typ.type = type;

    return p;
}

nodeType *con(){
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeCon;
    return p;
}

nodeType *conInt(int value) {
    nodeType *p = con();
    p->con.type = typeInt;
    p->con.iValue = value;
    
    return p;
}

nodeType *conFloat(float value) {
    nodeType *p = con();

    p->con.type = typeFloat;
    p->con.fValue = value;

    return p;
}

nodeType *conBool(bool value) {
    nodeType *p = con();

    p->con.type = typeBool;
    p->con.iValue = value;

    return p;
}


nodeType *conChar(char value) {
    nodeType *p = con();

    p->con.type = typeChar;
    p->con.cValue = value;

    return p;
}

nodeType *conString(char* value) {
    nodeType *p = con();

    p->con.type = typeString;
    p->con.sValue = value;

    return p;
}


nodeType *id(char* id) {
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeId;
    p->id.id = id;

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
    fprintf(stdout, "line [%d]: %s\n", yylineno, s);
    // fprintf (stderr, "%s\n", s);
}

/* 
    main functions take 1 input:
     path to the input program to be compiled
*/

int main(int argc, char* argv[]) {

    if(argc != 2){
        printf("wrong Number of arguments \n");
        exit(0);
    }

    FILE* inputFile;

    if((inputFile = fopen(argv[1], "r")) == NULL){
        printf("Please Enter a valid input file \n");
        exit(0);
    }
    yyin = inputFile;
    FILE* outFile;
    outFile = fopen("output/assembly.txt", "w");
    yyparse();
    fclose(yyin);
    return 0;
}
