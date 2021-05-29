/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER = 258,
    FLOAT = 259,
    CHAR = 260,
    STRING = 261,
    BOOLEAN = 262,
    VARIABLE = 263,
    WHILE = 264,
    IF = 265,
    PRINT = 266,
    IFX = 267,
    ELSE = 268,
    DECLARATION = 269,
    DEFINITION = 270,
    ASSIGNMENT = 271,
    OR = 272,
    AND = 273,
    EQEQ = 274,
    NOTEQ = 275,
    G = 276,
    L = 277,
    GE = 278,
    LE = 279,
    PLUS = 280,
    MINUS = 281,
    MUL = 282,
    DIV = 283,
    MOD = 284,
    NOT = 285,
    UMINUS = 286,
    PLUSPLUS = 287,
    MINUSMINUS = 288
  };
#endif
/* Tokens.  */
#define INTEGER 258
#define FLOAT 259
#define CHAR 260
#define STRING 261
#define BOOLEAN 262
#define VARIABLE 263
#define WHILE 264
#define IF 265
#define PRINT 266
#define IFX 267
#define ELSE 268
#define DECLARATION 269
#define DEFINITION 270
#define ASSIGNMENT 271
#define OR 272
#define AND 273
#define EQEQ 274
#define NOTEQ 275
#define G 276
#define L 277
#define GE 278
#define LE 279
#define PLUS 280
#define MINUS 281
#define MUL 282
#define DIV 283
#define MOD 284
#define NOT 285
#define UMINUS 286
#define PLUSPLUS 287
#define MINUSMINUS 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 18 "parser.y" /* yacc.c:1909  */

    int iValue;                 /* integer value */
    float fValue;
    char cValue;
    char* sValue;
    int bValue;

    char sIndex;                /* symbol table index */
    nodeType *nPtr;             /* node pointer */

#line 131 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
