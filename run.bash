bison --yacc parser.y -d # process parser using bison
flex lexer.l # process lexer using flex
g++ -c symbolTable.cpp # compile symbol table file and object file
gcc -c lex.yy.c y.tab.c compiling.c # compile c files and get object files
g++ -o cpp.out symbolTable.o compiling.o lex.yy.o y.tab.o # link output object files
./cpp.out input/code.c # run output file providing required code file