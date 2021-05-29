/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "parser.h"

/* prototypes */
nodeType *opr(int oper, int nops, ...);
nodeType *id(int i);
nodeType *con(int value);
void freeNode(nodeType *p);
int yylex(void);

void yyerror(char *s);
int sym[26];                    /* symbol table */

<<<<<<< HEAD
#line 83 "y.tab.c" /* yacc.c:339  */
=======
#line 88 "y.tab.c"
>>>>>>> 6a92f0340834dbcb3a059f25e309a6f9ce357925

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    INT_TYPE = 263,
    FLOAT_TYPE = 264,
    CHAR_TYPE = 265,
    STRING_TYPE = 266,
    BOOLEAN_TYPE = 267,
    VARIABLE = 268,
    CONST = 269,
    WHILE = 270,
    IF = 271,
<<<<<<< HEAD
    DECLARATION = 272,
    DEFINITION = 273,
    DO = 274,
    FOR = 275,
    SWITCH = 276,
    CASE = 277,
    BREAK = 278,
    DEFAULT = 279,
    RETURN = 280,
    VOID = 281,
    FUNCTION = 282,
    VOIDFUNCTION = 283,
    FUNCVARLIST = 284,
    CALLVARLIST = 285,
    CALL = 286,
    IFX = 287,
    ELSE = 288,
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
=======
    PRINT = 272,
    DECLARATION = 273,
    DEFINITION = 274,
    DO = 275,
    FOR = 276,
    SWITCH = 277,
    CASE = 278,
    BREAK = 279,
    DEFAULT = 280,
    RETURN = 281,
    VOID = 282,
    FUNCTION = 283,
    VOIDFUNCTION = 284,
    FUNCVARLIST = 285,
    CALLVARLIST = 286,
    CALL = 287,
    IFX = 288,
    ELSE = 289,
    ASSIGNMENT = 290,
    OR = 291,
    AND = 292,
    EQEQ = 293,
    NOTEQ = 294,
    G = 295,
    L = 296,
    GE = 297,
    LE = 298,
    PLUS = 299,
    MINUS = 300,
    MUL = 301,
    DIV = 302,
    MOD = 303,
    NOT = 304,
    UMINUS = 305
>>>>>>> 6a92f0340834dbcb3a059f25e309a6f9ce357925
  };
#endif
/* Tokens.  */
#define INTEGER 258
#define FLOAT 259
#define CHAR 260
#define STRING 261
#define BOOLEAN 262
#define INT_TYPE 263
#define FLOAT_TYPE 264
#define CHAR_TYPE 265
#define STRING_TYPE 266
#define BOOLEAN_TYPE 267
#define VARIABLE 268
#define CONST 269
#define WHILE 270
#define IF 271
<<<<<<< HEAD
#define DECLARATION 272
#define DEFINITION 273
#define DO 274
#define FOR 275
#define SWITCH 276
#define CASE 277
#define BREAK 278
#define DEFAULT 279
#define RETURN 280
#define VOID 281
#define FUNCTION 282
#define VOIDFUNCTION 283
#define FUNCVARLIST 284
#define CALLVARLIST 285
#define CALL 286
#define IFX 287
#define ELSE 288
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
=======
#define PRINT 272
#define DECLARATION 273
#define DEFINITION 274
#define DO 275
#define FOR 276
#define SWITCH 277
#define CASE 278
#define BREAK 279
#define DEFAULT 280
#define RETURN 281
#define VOID 282
#define FUNCTION 283
#define VOIDFUNCTION 284
#define FUNCVARLIST 285
#define CALLVARLIST 286
#define CALL 287
#define IFX 288
#define ELSE 289
#define ASSIGNMENT 290
#define OR 291
#define AND 292
#define EQEQ 293
#define NOTEQ 294
#define G 295
#define L 296
#define GE 297
#define LE 298
#define PLUS 299
#define MINUS 300
#define MUL 301
#define DIV 302
#define MOD 303
#define NOT 304
#define UMINUS 305
>>>>>>> 6a92f0340834dbcb3a059f25e309a6f9ce357925

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
<<<<<<< HEAD
#line 19 "parser.y" /* yacc.c:355  */
=======
#line 20 "parser.y"
>>>>>>> 6a92f0340834dbcb3a059f25e309a6f9ce357925

    int iValue;                 /* integer value */
    float fValue;
    char cValue;
    char* sValue;
    int bValue;

    char sIndex;                /* symbol table index */
    nodeType *nPtr;             /* node pointer */

<<<<<<< HEAD
#line 232 "y.tab.c" /* yacc.c:355  */
};
=======
#line 251 "y.tab.c"
>>>>>>> 6a92f0340834dbcb3a059f25e309a6f9ce357925

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */


<<<<<<< HEAD
#line 249 "y.tab.c" /* yacc.c:358  */
=======
>>>>>>> 6a92f0340834dbcb3a059f25e309a6f9ce357925

#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
<<<<<<< HEAD
#define YYLAST   537

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153
=======
#define YYLAST   403

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151
>>>>>>> 6a92f0340834dbcb3a059f25e309a6f9ce357925

#define YYUNDEFTOK  2
<<<<<<< HEAD
#define YYMAXUTOK   304
=======
#define YYMAXUTOK   305
>>>>>>> 6a92f0340834dbcb3a059f25e309a6f9ce357925


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
<<<<<<< HEAD
      51,    52,     2,     2,    55,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    56,    50,
=======
      52,    53,     2,     2,    56,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    57,    51,
>>>>>>> 6a92f0340834dbcb3a059f25e309a6f9ce357925
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
<<<<<<< HEAD
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
=======
       2,     2,     2,    54,     2,    55,     2,     2,     2,     2,
>>>>>>> 6a92f0340834dbcb3a059f25e309a6f9ce357925
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
<<<<<<< HEAD
      45,    46,    47,    48,    49
=======
      45,    46,    47,    48,    49,    50
>>>>>>> 6a92f0340834dbcb3a059f25e309a6f9ce357925
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
<<<<<<< HEAD
       0,    70,    70,    71,    77,    80,    81,    82,    83,    84,
      88,    89,    90,    91,    92,    96,    97,    99,   100,   102,
     104,   106,   107,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   122,   126,   127,   131,   132,   136,   137,
     141,   142,   151,   152,   157,   159,   162,   163,   164,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187
=======
       0,    70,    70,    74,    75,    79,    82,    83,    84,    85,
      86,    90,    91,    92,    93,    94,    98,    99,   100,   103,
     104,   106,   108,   110,   111,   113,   114,   115,   116,   117,
     118,   119,   120,   124,   125,   129,   130,   134,   135,   144,
     145,   148,   150,   153,   154,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177
>>>>>>> 6a92f0340834dbcb3a059f25e309a6f9ce357925
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "FLOAT", "CHAR", "STRING",
  "BOOLEAN", "INT_TYPE", "FLOAT_TYPE", "CHAR_TYPE", "STRING_TYPE",
<<<<<<< HEAD
  "BOOLEAN_TYPE", "VARIABLE", "CONST", "WHILE", "IF", "DECLARATION",
  "DEFINITION", "DO", "FOR", "SWITCH", "CASE", "BREAK", "DEFAULT",
  "RETURN", "VOID", "FUNCTION", "VOIDFUNCTION", "FUNCVARLIST",
  "CALLVARLIST", "CALL", "IFX", "ELSE", "ASSIGNMENT", "OR", "AND", "EQEQ",
  "NOTEQ", "G", "L", "GE", "LE", "PLUS", "MINUS", "MUL", "DIV", "MOD",
  "NOT", "UMINUS", "';'", "'('", "')'", "'{'", "'}'", "','", "':'",
  "$accept", "program", "assign", "data", "data_type", "stmt",
  "return_stmt", "func_stmt_list", "func_var_list", "func_list",
  "call_var_list", "stmt_list", "case_stmt", "default_stmt", "case_list",
  "expr", YY_NULLPTR
=======
  "BOOLEAN_TYPE", "VARIABLE", "CONST", "WHILE", "IF", "PRINT",
  "DECLARATION", "DEFINITION", "DO", "FOR", "SWITCH", "CASE", "BREAK",
  "DEFAULT", "RETURN", "VOID", "FUNCTION", "VOIDFUNCTION", "FUNCVARLIST",
  "CALLVARLIST", "CALL", "IFX", "ELSE", "ASSIGNMENT", "OR", "AND", "EQEQ",
  "NOTEQ", "G", "L", "GE", "LE", "PLUS", "MINUS", "MUL", "DIV", "MOD",
  "NOT", "UMINUS", "';'", "'('", "')'", "'{'", "'}'", "','", "':'",
  "$accept", "program", "function", "assign", "data", "data_type", "stmt",
  "func_var_list", "func_list", "call_var_list", "stmt_list", "case_stmt",
  "default_stmt", "case_list", "expr", YY_NULLPTR
>>>>>>> 6a92f0340834dbcb3a059f25e309a6f9ce357925
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
<<<<<<< HEAD
      59,    40,    41,   123,   125,    44,    58
};
# endif

#define YYPACT_NINF -81

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-81)))
=======
     305,    59,    40,    41,   123,   125,    44,    58
};
# endif

#define YYPACT_NINF (-45)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)
>>>>>>> 6a92f0340834dbcb3a059f25e309a6f9ce357925

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
<<<<<<< HEAD
     -81,   150,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,    -6,    76,   -46,   -43,   332,    -2,     0,
     -18,    39,     6,     6,   -81,     6,   176,     3,   -81,    42,
     -81,   387,   -81,     6,   -35,    43,     6,     6,    46,    52,
       6,   -81,    16,    55,   -81,   -81,    91,   -81,   -81,   202,
     -81,    -4,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,   -81,   467,   -81,    67,    47,
     248,   325,    38,    62,    50,   351,    14,    44,   -81,   -81,
     -81,     6,   -81,    56,   479,   490,    31,    31,    48,    48,
      48,    48,    13,    13,   -81,   -81,   -81,   -81,     6,   332,
     332,     6,     6,    57,   -81,    88,    59,   228,   403,   306,
     419,   -81,    79,   369,   435,     7,    58,   -81,   -81,   254,
     -81,     6,   306,   -81,    60,   -81,   332,    65,    52,   100,
      61,     7,   -81,    66,    76,   -81,   451,   -81,   -81,   -81,
     -81,    64,    63,   332,   -81,   -81,   -81,   -81,   332,   332,
     332,   -81,   332
=======
     -45,    22,   149,   -45,   -45,   -45,   -45,   -45,   -45,   -45,
     -45,   -45,   -45,   -45,    -8,    25,   -24,   -23,    49,   149,
     -21,     5,     7,    48,    49,    49,   -45,    49,   149,   -45,
     -45,    50,   -45,    34,   -45,    49,   -44,    51,    49,    49,
      73,   240,    23,    75,    49,   -45,    40,   -45,   -45,   143,
     -45,   123,   -32,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,   -45,   256,   -45,    82,
      61,   168,   186,   -45,    45,    64,    56,   204,     6,   149,
     -45,   -45,   -45,    49,   -45,    46,   335,   346,   355,   355,
      58,    58,    58,    58,    20,    20,   -45,   -45,   -45,   -45,
     -45,    49,   149,   149,    49,    49,   -17,   -45,    95,   -30,
     -45,   272,   149,   288,   -45,    77,   222,   304,   112,    52,
     -17,   -45,   -45,   -45,   -45,    25,   -45,    87,   -45,   149,
      69,    75,    66,   149,   -45,   111,    49,   -45,   -45,    88,
     149,    91,   -45,   320,   149,    97,   -45,    94,   -45,   -45,
     -45
>>>>>>> 6a92f0340834dbcb3a059f25e309a6f9ce357925
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
<<<<<<< HEAD
       3,     0,     1,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    15,     0,     0,     0,    49,     0,
       2,     0,    40,     0,     0,     0,     0,     0,     0,     0,
       0,    27,     0,    50,    51,    52,     0,    32,    42,     0,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,     4,    66,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    67,    31,
      43,     0,    17,     0,    65,    64,    63,    62,    59,    58,
      60,    61,    53,    54,    55,    56,    57,    41,     0,     0,
       0,     0,     0,     0,    39,     0,     0,     0,     0,     0,
       0,    21,    23,     0,     0,     0,    36,    38,    30,     0,
      18,     0,     0,    34,     0,    19,     0,     0,     0,     0,
       0,    47,    46,     0,     0,    29,     0,    35,    28,    24,
      22,     0,     0,     0,    48,    26,    37,    33,     0,     0,
      45,    25,    44
=======
       4,     0,     2,     1,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,     0,     0,    22,
      45,     0,     3,     0,    37,     0,     0,     0,     0,     0,
      46,     0,     0,     0,     0,    29,     0,    47,    48,     0,
      39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,     0,    62,     0,
       0,     0,     0,    18,     0,     0,     0,     0,     0,     0,
      63,    32,    40,     0,    19,     0,    61,    60,    59,    58,
      55,    54,    56,    57,    49,    50,    51,    52,    53,     5,
      38,     0,     0,     0,     0,     0,     0,    36,     0,     0,
      31,     0,     0,     0,    23,    25,     0,     0,     0,     0,
       0,    43,    28,    33,    35,     0,    20,     0,    21,     0,
       0,     0,     0,     0,    44,     0,     0,    26,    24,     0,
       0,     0,    34,     0,     0,     0,    42,     0,    27,    41,
      30
>>>>>>> 6a92f0340834dbcb3a059f25e309a6f9ce357925
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
<<<<<<< HEAD
     -81,   -81,   -38,    -5,   -12,    -1,   -81,     1,     5,    89,
     -81,   -80,   -81,   -81,    10,   -19
=======
     -45,   -45,   -45,   -42,    28,   -13,   -19,   -45,    99,   -45,
     -45,   -45,   -45,    47,   -14
>>>>>>> 6a92f0340834dbcb3a059f25e309a6f9ce357925
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
<<<<<<< HEAD
      -1,     1,    27,    28,    29,    48,   123,   124,   106,    77,
      34,    49,   131,   132,   133,    31
=======
      -1,     1,     2,    29,    30,    31,    32,   109,    79,    36,
      51,   120,   121,   122,    33
>>>>>>> 6a92f0340834dbcb3a059f25e309a6f9ce357925
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
<<<<<<< HEAD
      30,    74,    35,    44,    45,    36,    46,    32,    37,     3,
       4,     5,     6,     7,    66,    67,    38,    70,    71,    43,
      68,    75,     8,     9,    10,    11,    12,   119,    33,   129,
      81,   130,    41,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    82,    76,    80,    39,
      22,    40,    42,    50,    23,    51,    69,    25,    62,    63,
      64,    72,   108,   150,   105,    73,   104,    76,    32,   152,
      56,    57,    58,    59,    60,    61,    62,    63,    64,   110,
      97,    98,   113,   114,     8,     9,    10,    11,    12,   101,
     141,    60,    61,    62,    63,    64,    33,   107,   111,   112,
     102,   116,   136,     3,     4,     5,     6,     7,   122,   109,
     115,   117,   126,   134,   138,   140,   148,   143,    80,   149,
     145,   122,   105,   137,   142,   139,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,   146,
      83,   144,     0,    78,     0,     0,     0,   151,     0,    80,
       2,    80,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     0,     0,    17,
      18,    19,     0,    20,     0,     0,    21,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     0,    22,    17,    18,    19,    23,    20,
      24,    25,    21,    26,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     0,
      22,    17,    18,    19,    23,    20,    24,    25,    21,    26,
      47,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     0,    22,    17,    18,    19,
      23,    20,    24,    25,    21,    26,    79,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    22,    17,    18,    19,    23,    20,    24,    25,
      21,    26,   118,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,     0,    22,     0,
      99,     0,    23,     0,    24,    25,     0,    26,   135,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     0,     0,    17,    18,    19,     0,    20,
       0,   121,    21,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     0,
      22,    17,    18,    19,    23,    20,    24,    25,    21,    26,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,     0,     0,     0,    22,   100,     0,     0,
      23,     0,    24,    25,     0,    26,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     0,
       0,     0,     0,   103,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,     0,     0,     0,
       0,   127,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     0,     0,    65,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,     0,   120,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,     0,     0,   125,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,     0,     0,   128,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     0,
       0,   147,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64
=======
      42,    76,    37,    83,    41,    34,   118,    68,   119,    50,
      47,    48,    69,    49,     9,    10,    11,    12,    13,    84,
      78,    67,     3,   124,    71,    72,   125,    35,    38,    39,
      77,    43,    82,     9,    10,    11,    12,    13,    74,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,     4,     5,     6,     7,     8,    44,    45,   107,
     110,    46,    40,    52,    70,   108,    63,    64,    65,   111,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   114,   115,    66,    34,   113,    75,   139,
     116,   117,    78,   127,    24,   100,   101,   104,    25,    35,
     112,    27,    61,    62,    63,    64,    65,   105,   123,   133,
     137,   129,   135,   136,   141,     4,     5,     6,     7,     8,
     138,   145,   143,   140,   142,   148,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,   144,   146,    19,    20,    21,   132,    22,   149,   150,
      23,    85,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,   134,    24,    19,
      20,    21,    25,    22,    26,    27,    23,    28,    81,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,     0,     0,    24,     0,    80,     0,    25,     0,
      26,    27,     0,    28,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,     0,     0,     0,
       0,   102,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,     0,     0,     0,     0,   103,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,     0,     0,     0,     0,   106,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,     0,     0,     0,     0,   130,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,     0,
       0,    73,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,     0,     0,    99,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,     0,     0,   126,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,     0,     0,   128,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,     0,     0,   131,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,     0,
       0,   147,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    57,    58,    59,    60,    61,
      62,    63,    64,    65
>>>>>>> 6a92f0340834dbcb3a059f25e309a6f9ce357925
};

static const yytype_int16 yycheck[] =
{
<<<<<<< HEAD
       1,    39,    14,    22,    23,    51,    25,    13,    51,     3,
       4,     5,     6,     7,    33,    50,    17,    36,    37,    13,
      55,    40,     8,     9,    10,    11,    12,   107,    34,    22,
      34,    24,    50,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    50,    51,    49,    51,
      44,    51,    13,    50,    48,    13,    13,    51,    45,    46,
      47,    15,    81,   143,    76,    13,    52,    51,    13,   149,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    98,
      13,    34,   101,   102,     8,     9,    10,    11,    12,    51,
     128,    43,    44,    45,    46,    47,    34,    53,    99,   100,
      50,    13,   121,     3,     4,     5,     6,     7,   109,    53,
      53,    52,    33,    55,    54,    50,    52,    56,   119,    56,
      54,   122,   134,   122,   129,   126,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,   134,
      51,   131,    -1,    52,    -1,    -1,    -1,   148,    -1,   150,
       0,   152,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    19,
      20,    21,    -1,    23,    -1,    -1,    26,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    44,    19,    20,    21,    48,    23,
      50,    51,    26,    53,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      44,    19,    20,    21,    48,    23,    50,    51,    26,    53,
      54,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    44,    19,    20,    21,
      48,    23,    50,    51,    26,    53,    54,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    44,    19,    20,    21,    48,    23,    50,    51,
      26,    53,    54,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    44,    -1,
      52,    -1,    48,    -1,    50,    51,    -1,    53,    54,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    19,    20,    21,    -1,    23,
      -1,    25,    26,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      44,    19,    20,    21,    48,    23,    50,    51,    26,    53,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    44,    52,    -1,    -1,
      48,    -1,    50,    51,    -1,    53,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    -1,    52,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      -1,    52,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    50,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    50,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    50,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    50,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    50,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47
=======
      19,    43,    15,    35,    18,    13,    23,    51,    25,    28,
      24,    25,    56,    27,     8,     9,    10,    11,    12,    51,
      52,    35,     0,    53,    38,    39,    56,    35,    52,    52,
      44,    52,    51,     8,     9,    10,    11,    12,    15,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,     3,     4,     5,     6,     7,    52,    51,    53,
      79,    13,    13,    13,    13,    78,    46,    47,    48,    83,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,   102,   103,    51,    13,   101,    13,   131,
     104,   105,    52,   112,    45,    13,    35,    52,    49,    35,
      54,    52,    44,    45,    46,    47,    48,    51,    13,    57,
     129,    34,   125,    26,   133,     3,     4,     5,     6,     7,
      51,   140,   136,    57,    13,   144,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    53,    51,    20,    21,    22,   118,    24,    51,    55,
      27,    52,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,   120,    45,    20,
      21,    22,    49,    24,    51,    52,    27,    54,    55,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    45,    -1,    53,    -1,    49,    -1,
      51,    52,    -1,    54,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    -1,    -1,
      -1,    53,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,    53,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    -1,    -1,    -1,    53,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,    53,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      -1,    51,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    -1,    51,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    -1,    51,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    -1,    51,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    -1,    51,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      -1,    51,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    40,    41,    42,    43,    44,
      45,    46,    47,    48
>>>>>>> 6a92f0340834dbcb3a059f25e309a6f9ce357925
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
<<<<<<< HEAD
       0,    58,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    19,    20,    21,
      23,    26,    44,    48,    50,    51,    53,    59,    60,    61,
      62,    72,    13,    34,    67,    61,    51,    51,    62,    51,
      51,    50,    13,    13,    72,    72,    72,    54,    62,    68,
      50,    13,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    50,    72,    50,    55,    13,
      72,    72,    15,    13,    59,    72,    51,    66,    52,    54,
      62,    34,    50,    66,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    13,    34,    52,
      52,    51,    50,    52,    52,    61,    65,    53,    72,    53,
      72,    62,    62,    72,    72,    53,    13,    52,    54,    68,
      50,    25,    62,    63,    64,    50,    33,    52,    50,    22,
      24,    69,    70,    71,    55,    54,    72,    64,    54,    62,
      50,    59,    60,    56,    71,    54,    65,    50,    52,    56,
      68,    62,    68
=======
       0,    59,    60,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    20,
      21,    22,    24,    27,    45,    49,    51,    52,    54,    61,
      62,    63,    64,    72,    13,    35,    67,    63,    52,    52,
      13,    72,    64,    52,    52,    51,    13,    72,    72,    72,
      64,    68,    13,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    51,    72,    51,    56,
      13,    72,    72,    51,    15,    13,    61,    72,    52,    66,
      53,    55,    64,    35,    51,    66,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    51,
      13,    35,    53,    53,    52,    51,    53,    53,    63,    65,
      64,    72,    54,    72,    64,    64,    72,    72,    23,    25,
      69,    70,    71,    13,    53,    56,    51,    64,    51,    34,
      53,    51,    62,    57,    71,    63,    26,    64,    51,    61,
      57,    64,    13,    72,    53,    64,    51,    51,    64,    51,
      55
>>>>>>> 6a92f0340834dbcb3a059f25e309a6f9ce357925
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
<<<<<<< HEAD
       0,    57,    58,    58,    59,    60,    60,    60,    60,    60,
      61,    61,    61,    61,    61,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    63,    64,    64,    65,    65,    66,    66,
      67,    67,    68,    68,    69,    70,    71,    71,    71,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72
=======
       0,    58,    59,    60,    60,    61,    62,    62,    62,    62,
      62,    63,    63,    63,    63,    63,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    65,    65,    66,    66,    67,    67,    68,
      68,    69,    70,    71,    71,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72
>>>>>>> 6a92f0340834dbcb3a059f25e309a6f9ce357925
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
<<<<<<< HEAD
       0,     2,     2,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     5,     6,
       2,     5,     7,     5,     7,     9,     7,     2,     6,     6,
       5,     3,     2,     3,     1,     2,     2,     4,     3,     2,
       1,     3,     1,     2,     4,     3,     1,     1,     2,     1,
       1,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3
=======
       0,     2,     1,     2,     0,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     3,
       5,     6,     1,     5,     7,     5,     7,     9,     5,     2,
       9,     4,     3,     2,     4,     3,     2,     1,     3,     1,
       2,     5,     4,     1,     2,     1,     1,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3
>>>>>>> 6a92f0340834dbcb3a059f25e309a6f9ce357925
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
<<<<<<< HEAD
        case 2:
#line 70 "parser.y" /* yacc.c:1646  */
    { exit(0); }
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 77 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(ASSIGNMENT, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 80 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = con((yyvsp[0].iValue));}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 81 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = con((yyvsp[0].fValue));}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 82 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = con((yyvsp[0].cValue));}
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 83 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = con((yyvsp[0].sValue));}
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 84 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = con((yyvsp[0].bValue));}
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 88 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = INT_TYPE;}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 89 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = FLOAT_TYPE;}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 90 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = CHAR_TYPE;}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 91 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = STRING_TYPE;}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 92 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = BOOLEAN_TYPE;}
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 96 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(';', 2, NULL, NULL); }
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 97 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 99 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(DECLARATION, 2, (yyvsp[-2].nPtr), id((yyvsp[-1].sIndex))); }
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 100 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(DEFINITION, 3, (yyvsp[-4].nPtr), id((yyvsp[-3].sIndex)), (yyvsp[-1].nPtr)); }
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 102 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(CONST, 3, (yyvsp[-4].nPtr), id((yyvsp[-3].sIndex)), (yyvsp[-1].nPtr)); }
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 104 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 106 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(WHILE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 107 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(DO, 2, (yyvsp[-2].nPtr), (yyvsp[-5].nPtr)); }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 109 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(IF, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 110 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(IF, 3, (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 111 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(FOR, 4, (yyvsp[-6].nPtr), (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 112 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(SWITCH, 2, (yyvsp[-4].nPtr), (yyvsp[-1].nPtr)); }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 113 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = BREAK;}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 114 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(FUNCTION, 5, (yyvsp[-5].nPtr), id((yyvsp[-4].sIndex)), (yyvsp[-3].nPtr), (yyvsp[-1].nPtr));}
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 115 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(VOIDFUNCTION, 3, id((yyvsp[-4].sIndex)), (yyvsp[-3].nPtr), (yyvsp[-1].nPtr));}
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 116 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(VOIDFUNCTION, 3, id((yyvsp[-3].sIndex)), (yyvsp[-2].nPtr), NULL);}
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 117 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 118 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = NULL; }
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 122 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(RETURN, 1, (yyvsp[-1].nPtr)); }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 126 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 127 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(';', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 131 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(DECLARATION, 2, (yyvsp[-1].nPtr), id((yyvsp[0].sIndex))); }
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 132 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(FUNCVARLIST, 3, (yyvsp[-3].nPtr), id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 136 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 137 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = NULL;}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 141 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = id((yyvsp[0].sIndex)); }
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 142 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(CALLVARLIST, 2, (yyvsp[-2].nPtr), id((yyvsp[0].sIndex))); }
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 151 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 152 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(';', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 157 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(CASE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 159 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(DEFAULT, 1, (yyvsp[0].nPtr)); }
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 162 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 163 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 164 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr('CASE_LIST', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 169 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 170 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = id((yyvsp[0].sIndex)); }
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 171 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(UMINUS, 1, (yyvsp[0].nPtr)); }
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 172 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(NOT, 1, (yyvsp[0].nPtr)); }
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 173 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(PLUS, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 174 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(MINUS, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 175 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(MUL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 176 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(DIV, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 177 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(MOD, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 178 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(L, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(G, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 180 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(GE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 181 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(LE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 182 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(NOTEQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 183 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(EQEQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 184 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(AND, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 185 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(OR, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 186 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(CALL, 2, id((yyvsp[-2].sIndex)), (yyvsp[-1].nPtr));}
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 187 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1889 "y.tab.c" /* yacc.c:1646  */
=======
  case 2:
#line 70 "parser.y"
                                { exit(0); }
#line 1577 "y.tab.c"
    break;

  case 3:
#line 74 "parser.y"
                                { ex((yyvsp[0].nPtr)); freeNode((yyvsp[0].nPtr)); }
#line 1583 "y.tab.c"
    break;

  case 5:
#line 79 "parser.y"
                                              { (yyval.nPtr) = opr(ASSIGNMENT, 2, id((yyvsp[-3].sIndex)), (yyvsp[-1].nPtr)); }
#line 1589 "y.tab.c"
    break;

  case 6:
#line 82 "parser.y"
                        {(yyval.nPtr) = con((yyvsp[0].iValue));}
#line 1595 "y.tab.c"
    break;

  case 7:
#line 83 "parser.y"
                        {(yyval.nPtr) = con((yyvsp[0].fValue));}
#line 1601 "y.tab.c"
    break;

  case 8:
#line 84 "parser.y"
                        {(yyval.nPtr) = con((yyvsp[0].cValue));}
#line 1607 "y.tab.c"
    break;

  case 9:
#line 85 "parser.y"
                        {(yyval.nPtr) = con((yyvsp[0].sValue));}
#line 1613 "y.tab.c"
    break;

  case 10:
#line 86 "parser.y"
                        {(yyval.nPtr) = con((yyvsp[0].bValue));}
#line 1619 "y.tab.c"
    break;

  case 11:
#line 90 "parser.y"
                             {(yyval.nPtr) = INT_TYPE;}
#line 1625 "y.tab.c"
    break;

  case 12:
#line 91 "parser.y"
                             {(yyval.nPtr) = FLOAT_TYPE;}
#line 1631 "y.tab.c"
    break;

  case 13:
#line 92 "parser.y"
                             {(yyval.nPtr) = CHAR_TYPE;}
#line 1637 "y.tab.c"
    break;

  case 14:
#line 93 "parser.y"
                             {(yyval.nPtr) = STRING_TYPE;}
#line 1643 "y.tab.c"
    break;

  case 15:
#line 94 "parser.y"
                             {(yyval.nPtr) = BOOLEAN_TYPE;}
#line 1649 "y.tab.c"
    break;

  case 16:
#line 98 "parser.y"
                                                                            { (yyval.nPtr) = opr(';', 2, NULL, NULL); }
#line 1655 "y.tab.c"
    break;

  case 17:
#line 99 "parser.y"
                                                                            { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1661 "y.tab.c"
    break;

  case 18:
#line 100 "parser.y"
                                                                            { (yyval.nPtr) = opr(PRINT, 1, id((yyvsp[-1].nPtr))); }
#line 1667 "y.tab.c"
    break;

  case 19:
#line 103 "parser.y"
                                                                            { (yyval.nPtr) = opr(DECLARATION, 2, (yyvsp[-2].nPtr), id((yyvsp[-1].sIndex))); }
#line 1673 "y.tab.c"
    break;

  case 20:
#line 104 "parser.y"
                                                                            { (yyval.nPtr) = opr(DEFINITION, 3, (yyvsp[-4].nPtr), id((yyvsp[-3].sIndex)), (yyvsp[-1].nPtr)); }
#line 1679 "y.tab.c"
    break;

  case 21:
#line 106 "parser.y"
                                                                            { (yyval.nPtr) = opr(CONST, 3, (yyvsp[-4].nPtr), id((yyvsp[-3].sIndex)), (yyvsp[-1].nPtr)); }
#line 1685 "y.tab.c"
    break;

  case 22:
#line 108 "parser.y"
                                                                            { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1691 "y.tab.c"
    break;

  case 23:
#line 110 "parser.y"
                                                                            { (yyval.nPtr) = opr(WHILE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1697 "y.tab.c"
    break;

  case 24:
#line 111 "parser.y"
                                                                            { (yyval.nPtr) = opr(DO, 2, (yyvsp[-2].nPtr), (yyvsp[-5].nPtr)); }
#line 1703 "y.tab.c"
    break;

  case 25:
#line 113 "parser.y"
                                                                            { (yyval.nPtr) = opr(IF, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1709 "y.tab.c"
    break;

  case 26:
#line 114 "parser.y"
                                                                            { (yyval.nPtr) = opr(IF, 3, (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1715 "y.tab.c"
    break;

  case 27:
#line 115 "parser.y"
                                                                            { (yyval.nPtr) = opr(FOR, 4, (yyvsp[-6].nPtr), (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1721 "y.tab.c"
    break;

  case 28:
#line 116 "parser.y"
                                                                            { (yyval.nPtr) = opr(SWITCH, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1727 "y.tab.c"
    break;

  case 29:
#line 117 "parser.y"
                                                                            { (yyval.nPtr) = BREAK;}
#line 1733 "y.tab.c"
    break;

  case 30:
#line 118 "parser.y"
                                                                            {(yyval.nPtr) = opr(FUNCTION, 5, (yyvsp[-8].nPtr), id((yyvsp[-7].sIndex)), (yyvsp[-6].nPtr), (yyvsp[-4].nPtr), (yyvsp[-2].nPtr));}
#line 1739 "y.tab.c"
    break;

  case 31:
#line 119 "parser.y"
                                                                            {(yyval.nPtr) = opr(VOIDFUNCTION, 3, id((yyvsp[-2].sIndex)), (yyvsp[-1].nPtr), (yyvsp[0].nPtr));}
#line 1745 "y.tab.c"
    break;

  case 32:
#line 120 "parser.y"
                                                                            { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1751 "y.tab.c"
    break;

  case 33:
#line 124 "parser.y"
                                                                            { (yyval.nPtr) = opr(DECLARATION, 2, (yyvsp[-1].nPtr), id((yyvsp[0].sIndex))); }
#line 1757 "y.tab.c"
    break;

  case 34:
#line 125 "parser.y"
                                                                            { (yyval.nPtr) = opr(FUNCVARLIST, 3, (yyvsp[-3].nPtr), (yyvsp[-1].nPtr), id((yyvsp[0].sIndex))); }
#line 1763 "y.tab.c"
    break;

  case 35:
#line 129 "parser.y"
                                 {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1769 "y.tab.c"
    break;

  case 36:
#line 130 "parser.y"
                                 {(yyval.nPtr) = NULL;}
#line 1775 "y.tab.c"
    break;

  case 37:
#line 134 "parser.y"
                                                                            { (yyval.nPtr) = id((yyvsp[0].sIndex)); }
#line 1781 "y.tab.c"
    break;

  case 38:
#line 135 "parser.y"
                                                                            { (yyval.nPtr) = opr(CALLVARLIST, 2, (yyvsp[-2].nPtr), id((yyvsp[0].sIndex))); }
#line 1787 "y.tab.c"
    break;

  case 39:
#line 144 "parser.y"
                                   { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1793 "y.tab.c"
    break;

  case 40:
#line 145 "parser.y"
                                   { (yyval.nPtr) = opr(';', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 1799 "y.tab.c"
    break;

  case 41:
#line 148 "parser.y"
                                      { (yyval.nPtr) = opr(CASE, 2, (yyvsp[-3].nPtr), (yyvsp[-1].nPtr)); }
#line 1805 "y.tab.c"
    break;

  case 42:
#line 150 "parser.y"
                                      { (yyval.nPtr) = opr(DEFAULT, 1, (yyvsp[-1].nPtr)); }
#line 1811 "y.tab.c"
    break;

  case 43:
#line 153 "parser.y"
                                   { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1817 "y.tab.c"
    break;

  case 44:
#line 154 "parser.y"
                                   { (yyval.nPtr) = opr('CASE_LIST', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 1823 "y.tab.c"
    break;

  case 45:
#line 159 "parser.y"
                                                            { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1829 "y.tab.c"
>>>>>>> 6a92f0340834dbcb3a059f25e309a6f9ce357925
    break;

  case 46:
#line 160 "parser.y"
                                                            { (yyval.nPtr) = id((yyvsp[0].sIndex)); }
#line 1835 "y.tab.c"
    break;

  case 47:
#line 161 "parser.y"
                                                            { (yyval.nPtr) = opr(UMINUS, 1, (yyvsp[0].nPtr)); }
#line 1841 "y.tab.c"
    break;

  case 48:
#line 162 "parser.y"
                                                            { (yyval.nPtr) = opr(NOT, 1, (yyvsp[0].nPtr)); }
#line 1847 "y.tab.c"
    break;

  case 49:
#line 163 "parser.y"
                                                            { (yyval.nPtr) = opr(PLUS, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1853 "y.tab.c"
    break;

  case 50:
#line 164 "parser.y"
                                                            { (yyval.nPtr) = opr(MINUS, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1859 "y.tab.c"
    break;

  case 51:
#line 165 "parser.y"
                                                            { (yyval.nPtr) = opr(MUL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1865 "y.tab.c"
    break;

  case 52:
#line 166 "parser.y"
                                                            { (yyval.nPtr) = opr(DIV, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1871 "y.tab.c"
    break;

  case 53:
#line 167 "parser.y"
                                                            { (yyval.nPtr) = opr(MOD, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1877 "y.tab.c"
    break;

  case 54:
#line 168 "parser.y"
                                                            { (yyval.nPtr) = opr(L, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1883 "y.tab.c"
    break;

  case 55:
#line 169 "parser.y"
                                                            { (yyval.nPtr) = opr(G, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1889 "y.tab.c"
    break;

  case 56:
#line 170 "parser.y"
                                                            { (yyval.nPtr) = opr(GE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1895 "y.tab.c"
    break;

  case 57:
#line 171 "parser.y"
                                                            { (yyval.nPtr) = opr(LE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1901 "y.tab.c"
    break;

  case 58:
#line 172 "parser.y"
                                                            { (yyval.nPtr) = opr(NOTEQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1907 "y.tab.c"
    break;

  case 59:
#line 173 "parser.y"
                                                            { (yyval.nPtr) = opr(EQEQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1913 "y.tab.c"
    break;

  case 60:
#line 174 "parser.y"
                                                            { (yyval.nPtr) = opr(AND, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1919 "y.tab.c"
    break;

  case 61:
#line 175 "parser.y"
                                                            { (yyval.nPtr) = opr(OR, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1925 "y.tab.c"
    break;

  case 62:
#line 176 "parser.y"
                                                            { (yyval.nPtr) = opr(CALL, 2, id((yyvsp[-2].sIndex)), (yyvsp[-1].nPtr));}
#line 1931 "y.tab.c"
    break;

  case 63:
#line 177 "parser.y"
                                                            { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1937 "y.tab.c"
    break;


#line 1941 "y.tab.c"

<<<<<<< HEAD
#line 1893 "y.tab.c" /* yacc.c:1646  */
=======
>>>>>>> 6a92f0340834dbcb3a059f25e309a6f9ce357925
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
<<<<<<< HEAD
#line 190 "parser.y" /* yacc.c:1906  */
=======
#line 180 "parser.y"
>>>>>>> 6a92f0340834dbcb3a059f25e309a6f9ce357925


nodeType *con(int value) {
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeCon;
    p->con.value = value;

    return p;
}

nodeType *id(int i) {
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeId;
    p->id.i = i;

    return p;
}

nodeType *opr(int oper, int nops, ...) {
    va_list ap;
    nodeType *p;
    int i;

    /* allocate node, extending op array */
    if ((p = malloc(sizeof(nodeType) + (nops-1) * sizeof(nodeType *))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    return p;
}

void freeNode(nodeType *p) {
    int i;

    if (!p) return;
    if (p->type == typeOpr) {
        for (i = 0; i < p->opr.nops; i++)
            freeNode(p->opr.op[i]);
    }
    free (p);
}

void yyerror(char *s) {
    fprintf(stdout, "%s\n", s);
}



int main(void) {
    yyparse();
    return 0;
}
