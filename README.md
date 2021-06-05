# Simple C/C++ Compiler

A simple C/C++ compiler implemented in _LEX_ __(Flex)__ and _YACC_ __(Bison)__.

## Prerequisites

-   gcc
-   g++
-   flex
-   bison

## Usage (Ubuntu)

-   Add the required code to `code.c` file.

__NOTE :__ A sample code is included in `code.c` file that covers the syntax.

-   Compile and run the lexer and parser on the code in `code.c` file :
    ```bash
    bison --yacc parser.y -d # compile parser using bison
    flex lexer.l # compile lexer using flex
    gcc -c lex.yy.c y.tab.c compiling.c # compile c files and get final object file
    ./cpp.out code.c # run object file ("syntax error" is printed in case of incorrect code)
    ```
