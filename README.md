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
    bison --yacc parser.y -d # process parser using bison
    flex lexer.l # process lexer using flex
    g++ -c symbolTable.cpp # compile symbol table file and object file
    gcc -c lex.yy.c y.tab.c compiling.c # compile c files and get object files
    g++ -o cpp.out symbolTable.o compiling.o lex.yy.o y.tab.o # link output object files
    ./cpp.out input/code.c # run output file providing required code file
    ```
