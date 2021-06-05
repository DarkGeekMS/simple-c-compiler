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
    BOOLEAN_TRUE = 262,
    BOOLEAN_FALSE = 263,
    VARIABLE = 264,
    INT_TYPE = 265,
    FLOAT_TYPE = 266,
    CHAR_TYPE = 267,
    STRING_TYPE = 268,
    BOOLEAN_TYPE = 269,
    CONST = 270,
    VOID = 271,
    IF = 272,
    ELSE = 273,
    DO = 274,
    WHILE = 275,
    FOR = 276,
    SWITCH = 277,
    CASE = 278,
    DEFAULT = 279,
    BREAK = 280,
    RETURN = 281,
    FUNCTION = 282,
    VOIDFUNCTION = 283,
    FUNCVARLIST = 284,
    CALLVARLIST = 285,
    CALL = 286,
    SYMBOLTABLE = 287,
    IFX = 288,
    ASSIGNMENT = 289,
    OR = 290,
    AND = 291,
    EQEQ = 292,
    NOTEQ = 293,
    G = 294,
    L = 295,
    GE = 296,
    LE = 297,
    PLUS = 298,
    MINUS = 299,
    MUL = 300,
    DIV = 301,
    MOD = 302,
    NOT = 303,
    UMINUS = 304
  };
#endif
/* Tokens.  */
#define INTEGER 258
#define FLOAT 259
#define CHAR 260
#define STRING 261
#define BOOLEAN_TRUE 262
#define BOOLEAN_FALSE 263
#define VARIABLE 264
#define INT_TYPE 265
#define FLOAT_TYPE 266
#define CHAR_TYPE 267
#define STRING_TYPE 268
#define BOOLEAN_TYPE 269
#define CONST 270
#define VOID 271
#define IF 272
#define ELSE 273
#define DO 274
#define WHILE 275
#define FOR 276
#define SWITCH 277
#define CASE 278
#define DEFAULT 279
#define BREAK 280
#define RETURN 281
#define FUNCTION 282
#define VOIDFUNCTION 283
#define FUNCVARLIST 284
#define CALLVARLIST 285
#define CALL 286
#define SYMBOLTABLE 287
#define IFX 288
#define ASSIGNMENT 289
#define OR 290
#define AND 291
#define EQEQ 292
#define NOTEQ 293
#define G 294
#define L 295
#define GE 296
#define LE 297
#define PLUS 298
#define MINUS 299
#define MUL 300
#define DIV 301
#define MOD 302
#define NOT 303
#define UMINUS 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 31 "parser.y" /* yacc.c:1909  */

    int iValue;                 /* integer value */
    float fValue;               // float value
    char cValue;                // character value
    char* sValue;               // string
    char* sIndex;                /* symbol table index */
    nodeType *nPtr;             /* node pointer */

#line 161 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
