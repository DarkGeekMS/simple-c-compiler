%{
    #include <stdio.h>
    int yylex(void);
    void yyerror(char *);
%}

%token  IF THEN ELSE WHILE BREAK FOR SWITCH CASE DEFAULT  REPEAT UNTIL PRINT 
