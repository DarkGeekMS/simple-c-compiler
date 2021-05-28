/*definitions*/

%{


%}

/* rules */

%%

 
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

"=="	        return EQ;
"!="            return NE;
">"             return LT;
"<"             return GT;
">="            return GTE;
"<="            return LTE;
"&&"        	return AND;
"||"            return OR;
"!"             return NOT;

"="             return ASN;
"+"             return ADD;
"-"             return SUB;
"*"             return MUL;
"/"             return DIV;
"%"             return MOD;
%%

/* functions */

int yywrap(void) {
    return 1;
}

int main(void) {
    yylex();
    return 0;
}
