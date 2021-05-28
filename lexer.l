/*definitions*/

%{

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

 /* Data types */

"int"           return INT;
"float"         return FLOAT;
"string"        return STRING;
"char"          return CHAR;
"bool"          return BOOL;
"double"        return DOUBLE;
"long"          return LONG;


"=="	        return EQ;
"!="            return NE;
">"             return GT;
"<"             return LT;
">="            return GTE;
"<="            return LTE;
"&&"        	return AND;
"||"            return OR;
"!"             return NOT;


[-()=+*/%;{}:]      {  
                        return *yytext;
                }

0                   {
                        yylval.iValue = atoi(yytext);
                        return INTEGER;
                }

[1-9][0-9]*         {
                        yylval.iValue = atoi(yytext);
                        return INTEGER;
                } 

[0-9]+"."[0-9]*     {
                        yylval.iValue = atof(yytext);
                        return FLOAT;
                } 

[ \t]           ;       /* skip whitespace */

.               yyerror("Unknown character");

%%

/* functions */

int yywrap(void) {
    return 1;
}

int main(void) {
    yylex();
    return 0;
}
