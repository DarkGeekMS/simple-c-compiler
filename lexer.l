/* definitions */

%{
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "y.tab.h"

void yyerror(char *);
%}

/* rules */

%%

 /* keywords */

"if"            return IF;
"then"          return THEN;
"else"          return ELSE; 

"do"            return DO;
"while"         return WHILE;
"for"           return FOR;

"switch"        return SWITCH;
"case"          return CASE;
"break"         return BREAK;
"default"       return DEFAULT;

"return"        return RETURN;
"void"          return VOID;


 /* data types */

"int"           return INT;
"float"         return FLOAT;
"string"        return STRING;
"char"          return CHAR;
"bool"          return BOOL;
"const"         return CONST;

 /* logical operators and comparators */

"=="	        return EQEQ;
"!="            return NOTEQ;
">"             return G;
"<"             return L;
">="            return GE;
"<="            return LE;
"&&"        	return AND;
"||"            return OR;
"!"             return NOT;

 /* operators */

"="             return ASSIGNMENT
"+"             return PLUS
"-"             return MINUS
"*"             return MUL
"/"             return DIV
"%"             return MOD
"++"            return PLUSPLUS
"--"            return MINUSMINUS

 /* identifiers */

[a-zA-Z]([a-zA-Z]|[0-9]|_)*     { 
                                    yylval.sIndex = malloc(strlen(yytext));
                                    return VARIABLE;
                            }


 /* strings */

\"[a-zA-Z]*|[0-9]*\"            {
                                    yylval.sValue = *(yytext+1);
                                    return STRING;
                            } 


 /* characters */

\'[a-zA-Z]|[0-9]\'              {
                                    yylval.cValue = *(yytext+1);
                                    return CHAR;
                            } 


 /* special characters */

[();{}:]                        {
                                    return *yytext;
                            }
 /* zero numeral */

0                               {
                                    yylval.iValue = atoi(yytext);
                                    return INTEGER;
                            }


 /* integers */

[1-9][0-9]*                     {
                                    yylval.iValue = atoi(yytext);
                                    return INTEGER;
                            } 


 /* floats */

[0-9]+"."[0-9]+                 {
                                    yylval.fValue = atof(yytext);
                                    return FLOAT;
                            } 


 /* booleans */

"true"                          {
                                    yylval.bValue = 1;
                                    return BOOLEAN;
                            }

"false"                         {
                                    yylval.bValue = 0;
                                    return BOOLEAN;
                            }

 
 /* line breaks */

[\n]+                           { 
                                    yylineno++;
                            }


 /* whitespaces */

[ \t]+                      ;   /* skip whitespace */


 /* others */

.                           yyerror("Unknown character");

%%

/* functions */

int main(void) {
    yylex();
    return 0;
}
