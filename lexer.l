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

"while"         return WHILE;
"break"         return BREAK;
"for"           return FOR;

"switch"        return SWITCH;
"case"          return CASE;
"default"       return DEFAULT;

"repeat"        return REPEAT;
"until"         return UNTIL;
"print"         return PRINT;
"exit"          return EXIT;


 /* data types */

"int"           return INT;
"float"         return FLOAT;
"string"        return STRING;
"char"          return CHAR;
"bool"          return BOOL;
"double"        return DOUBLE;
"long"          return LONG;


 /* logical operators and comparators */

"=="	        return EQ;
"!="            return NE;
">"             return GT;
"<"             return LT;
">="            return GTE;
"<="            return LTE;
"&&"        	return AND;
"||"            return OR;
"!"             return NOT;


 /* identifiers */

[a-zA-Z]([a-zA-Z]|[0-9]|_)*     { 

                                    return IDENTIFIER;
                            }


 /* strings */

\"[a-zA-Z]*|[0-9]*\"            {
                                    yylval.fValue = *(yytext+1);
                                    return STRING;
                            } 


 /* characters */

\'[a-zA-Z]|[0-9]\'          {
                                yylval.fValue = *(yytext+1);
                                return CHAR;
                        } 


 /* special characters */

[-()=+*/%;{}:]              {  
                                return *yytext;
                        }


 /* zero numeral */

0                           {
                                yylval.iValue = atoi(yytext);
                                return INTEGER;
                        }


 /* integers */

[1-9][0-9]*                 {
                                yylval.iValue = atoi(yytext);
                                return INTEGER;
                        } 


 /* floats */

[0-9]+"."[0-9]*             {
                                yylval.iValue = atof(yytext);
                                return FLOAT;
                        } 


 /* line breaks */

[\n]+                      { 
                                yylineno++;
                        }


 /* whitespaces */

[ \t]+                      ;       /* skip whitespace */


 /* others */

.                           yyerror("Unknown character");

%%

/* functions */

int main(void) {
    yylex();
    return 0;
}
