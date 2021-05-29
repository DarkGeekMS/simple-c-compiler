/* definitions */

%{
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "parser.h"
#include "y.tab.h"

void yyerror(char *);
%}

/* rules */

%%

 /* keywords */

"if"            return IF;
"else"          return ELSE; 

"while"         return WHILE;
"break"         return BREAK;
"for"           return FOR;

"switch"        return SWITCH;
"case"          return CASE;
"default"       return DEFAULT;

"do"            return DO;
"return"        return RETURN;

 /* data types */

"int"           return INT_TYPE;
"float"         return FLOAT_TYPE;
"string"        return STRING_TYPE;
"char"          return CHAR_TYPE;
"bool"          return BOOLEAN_TYPE;
"const"         return CONST;
"void"          return VOID;


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

"="             return ASSIGNMENT;
"+"             return PLUS;
"-"             return MINUS;
"*"             return MUL;
"/"             return DIV;
"%"             return MOD;


 /* booleans */

"true"                          {
                                    yylval.bValue = 1;
                                    return BOOLEAN;
                            }

"false"                         {
                                    yylval.bValue = 0;
                                    return BOOLEAN;
                            }


 /* identifiers */

[a-zA-Z]([a-zA-Z]|[0-9]|_)*     { 

                                    return VARIABLE;
                            }


 /* strings */
\"[a-zA-Z0-9 ]*\"               {
                                    yylval.sValue = *(yytext+1);
                                    return STRING;
                            } 


 /* characters */

\'[a-zA-Z0-9 ]\'                {
                                    yylval.cValue = *(yytext+1);
                                    return CHAR;
                            } 


 /* special characters */

[();{}:,]                        {  
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

[0-9]+"."[0-9]*                 {
                                    yylval.fValue = atof(yytext);
                                    return FLOAT;
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

int yywrap(void) {
    return 1;
}
