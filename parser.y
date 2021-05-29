%{
    #include <stdio.h>
    #include <stdarg.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdbool.h>
    int yylex(void);
    void yyerror(char *);
%}

%union {
    float fValue;               /* float  */
    int   iValue;               /* inreger */
    bool  bValue;               /* boolean */
    char  cValue;               /* character */
    char* sValue;               /* string  */
    char*  sIndex;               /* symbol table index */
    nodeType *nPtr;
    
};

 // tokens
%token <iValue> INTEGER
%token <fValue> FLOAT
%token <cValue> CHAR
%token <sValue> STRING
%token <bValue> 1             // true
%token <bValue> 0             // false
%token <sIndex> VARIABLE

%token  INT FLOAT STRING CHAR BOOL VOID CONST                               // data types
%token  IF THEN ELSE DO WHILE FOR SWITCH CASE BREAK DEFAULT  RETURN         // key words

 // associativity rules
%nonassoc ELSE 
%nonassoc IF

%right ASSIGNMENT NOT
%left OR AND EQEQ NOTEQ G L GE LE
%left ADD SUB MUL DIV MOD
