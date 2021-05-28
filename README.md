# Simple C/C++ Compiler

A simple C/C++ compiler implemented in _LEX_ __(Flex)__ and _YACC_ __(Bison)__.

## Prerequisites

-   gcc
-   g++
-   flex
-   bison

## Usage (Ubuntu)

```bash
bison --yacc parser.y -d # compile parser using bison
flex lexer.l # compile lexer using flex
gcc -o cpp.out lex.yy.c y.tab.c # compile c files and get final object file
./cpp.out # run object file and provide your source code
```

## Lexical Analyzer Tokens:
1- Type: 
- `INTEGER`: int
- `CHAR`: char
- `FLOAT`: float
2- `VARIABLE`: identifier
3- Operators
- `PLUS`: +
- `MINUS`: -
- `MUL`: *
- `DIV`: /
- `G`: >
- `L`: <
- `GE`: >=
- `LE`: <=
- `EQEQ`: ==
- `NOTEQ`: !=
- `AND`: &&
- `OR`: ||
- `NOT`: !
- `PLUSPLUS`: ++
- `MINUSMINUS`: --

4- `ASSIGNMENT`: =

5- Keywords: `IF`/ `ELSE`/ `WHILE`/ `DO`/ `FOR`/ `SWITCH`/ `CASE`

6- `RETURN`: return

