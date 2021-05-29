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
    CONST = 264,
    WHILE = 265,
    IF = 266,
    PRINT = 267,
    DECLARATION = 268,
    DEFINITION = 269,
    DO = 270,
    FOR = 271,
    SWITCH = 272,
    CASE = 273,
    BREAK = 274,
    DEFAULT = 275,
    RETURN = 276,
    VOID = 277,
    IFX = 278,
    ELSE = 279,
    ASSIGNMENT = 280,
    OR = 281,
    AND = 282,
    EQEQ = 283,
    NOTEQ = 284,
    G = 285,
    L = 286,
    GE = 287,
    LE = 288,
    PLUS = 289,
    MINUS = 290,
    MUL = 291,
    DIV = 292,
    MOD = 293,
    NOT = 294,
    UMINUS = 295,
    PLUSPLUS = 296,
    MINUSMINUS = 297
  };
#endif
/* Tokens.  */
#define INTEGER 258
#define FLOAT 259
#define CHAR 260
#define STRING 261
#define BOOLEAN 262
#define VARIABLE 263
#define CONST 264
#define WHILE 265
#define IF 266
#define PRINT 267
#define DECLARATION 268
#define DEFINITION 269
#define DO 270
#define FOR 271
#define SWITCH 272
#define CASE 273
#define BREAK 274
#define DEFAULT 275
#define RETURN 276
#define VOID 277
#define IFX 278
#define ELSE 279
#define ASSIGNMENT 280
#define OR 281
#define AND 282
#define EQEQ 283
#define NOTEQ 284
#define G 285
#define L 286
#define GE 287
#define LE 288
#define PLUS 289
#define MINUS 290
#define MUL 291
#define DIV 292
#define MOD 293
#define NOT 294
#define UMINUS 295
#define PLUSPLUS 296
#define MINUSMINUS 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 20 "parser.y" /* yacc.c:1909  */

    int iValue;                 /* integer value */
    float fValue;
    char cValue;
    char* sValue;
    int bValue;

    char sIndex;                /* symbol table index */
    nodeType *nPtr;             /* node pointer */

#line 149 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
