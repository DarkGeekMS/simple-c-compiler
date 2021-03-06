# Simple C/C++ Compiler

A simple C/C++ compiler implemented in _LEX_ __(Flex)__ and _YACC_ __(Bison)__.

## Prerequisites

-   gcc
-   g++
-   flex
-   bison
-   Python (`PyQT5`)

## Usage (Ubuntu)

-   Add the required code to `.c` or `.cpp` file.

-   Compile and run the lexer and parser on the code :
    ```bash
    bison --yacc parser.y -d # process parser using bison
    flex lexer.l # process lexer using flex
    g++ -c symbolTable.cpp # compile symbol table file and object file
    gcc -c lex.yy.c y.tab.c compiling.c # compile c files and get object files
    g++ -o cpp.out symbolTable.o compiling.o lex.yy.o y.tab.o # link output object files
    ./cpp.out /path/to/input/file /path/to/output/directory # run output file providing required code file
    ```

-   Alternatively, use `run.bash` to compile and run the compiler :
    ```bash
    ./run.bash /path/to/input/file /path/to/output/directory
    ```

-   Use GUI :
    -   First, compile the code and get `cpp.out`.
    -   Second, copy `cpp.out` to `gui` folder.
    -   Third, run GUI :
        ```bash
        cd gui/
        python gui.py
        ```
    -   Finally, choose the input file and the output directory, then press _compile button_.
