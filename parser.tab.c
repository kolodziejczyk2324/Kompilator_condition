/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <cstdio>
#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include "Biblioteki/library.h"
#include "Biblioteki/MyStack.h"

#define STORE(X) code.push_back(concatStringInt("STORE ", X));
#define LOAD(X) code.push_back(concatStringInt("LOAD ", X));
#define ADD(X) code.push_back(concatStringInt("ADD ", X));
#define SUB(X) code.push_back(concatStringInt("SUB ", X));
#define PUT(X) code.push_back(concatStringInt("PUT ", X));
#define GET(X) code.push_back(concatStringInt("GET ", X));
#define ZERO(X) code.push_back(concatStringInt("ZERO ", X));
#define COPY(X) code.push_back(concatStringInt("COPY ", X));
#define JZERO(X, Y) code.push_back(concatStringInt("JZERO ", X)+string(" ")+Y);
#define JUMP(X) code.push_back("JUMP " + X);

#define PUSH_ETYK(X) etykiety.push(concatStringInt("E", X));
#define POP_AND_WRITE_ETYK code.push_back(etykiety.pop());

#define EQ_1 PUSH_ETYK(ety+1) PUSH_ETYK(ety+2) PUSH_ETYK(ety+1)\
	PUSH_ETYK(ety+2) PUSH_ETYK(ety) PUSH_ETYK(ety+1)\
	PUSH_ETYK(ety) ety+=3;
#define EQ_2 JZERO(1, etykiety.pop())\
	create_number(code, 0, 1);\
	JUMP(etykiety.pop())\
	POP_AND_WRITE_ETYK
#define EQ_3 JZERO(1, etykiety.pop())\
	create_number(code, 0, 1);\
	JUMP(etykiety.pop())\
	POP_AND_WRITE_ETYK\
	create_number(code, 1, 1);\
	POP_AND_WRITE_ETYK

#define NEQ_1 PUSH_ETYK(ety+1) PUSH_ETYK(ety) PUSH_ETYK(ety+1)\
	PUSH_ETYK(ety) ety+=2;
#define NEQ_2 JZERO(1, etykiety.pop())\
	JUMP(etykiety.pop())\
	POP_AND_WRITE_ETYK
#define NEQ_3 POP_AND_WRITE_ETYK

#define XOET_1 PUSH_ETYK(ety+1) PUSH_ETYK(ety) PUSH_ETYK(ety+1)\
	PUSH_ETYK(ety) ety+=2;
#define XOET_2 JZERO(1, etykiety.pop())\
	JUMP(etykiety.pop())\
	POP_AND_WRITE_ETYK
#define XOET_3 POP_AND_WRITE_ETYK

using namespace std;

void yyerror(const char *s);
void check_identifier(string name, int isArray);
void check_double_declaration(string name);
void load_memory_to_register(int memory, int reg);
void save_register_to_memory(int reg, int memory);
void save_number_to_memory(int number, int memory);

void odejmowanie_number_number(int a, int b);
void odejmowanie_identifier_number(int num);
void odejmowanie_number_identifier(int num);
void odejmowanie_identifier_identifier(int a, int b);
void rowne_number_number(int a, int b);
void rowne_identifier_number(int num);
void rowne_identifier_identifier();

extern "C" int yylex();
extern int yylineno;

struct var_data{
	int store;
	int isArray;
};

vector<string> code;
map<string, struct var_data> zmienne;
MyStack etykiety;
int i = 4;
int mem_to_save_id = 1;
int ety = 1;


#line 153 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    IDENTIFIER = 258,
    VAR = 259,
    _BEGIN = 260,
    END = 261,
    READ = 262,
    WRITE = 263,
    SKIP = 264,
    IF = 265,
    THEN = 266,
    ELSE = 267,
    ENDIF = 268,
    GT = 269,
    LT = 270,
    EQ = 271,
    NEQ = 272,
    GOET = 273,
    LOET = 274,
    LB = 275,
    RB = 276,
    SREDNIK = 277,
    PRZYPISANIE = 278,
    PLUS = 279,
    MINUS = 280,
    NUMBER = 281
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 87 "parser.y" /* yacc.c:355  */

	int	ival;
        char*	sval;

#line 225 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 242 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   116

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  27
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  97

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   281

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   105,   105,   108,   109,   112,   118,   119,   121,   124,
     126,   130,   130,   139,   141,   143,   139,   148,   150,   151,
     158,   159,   162,   165,   172,   173,   174,   175,   186,   187,
     188,   189,   194,   195,   196,   197,   202,   203,   204,   205,
     213,   218,   223,   228,   240,   245,   250,   255,   267,   272,
     277,   282,   289,   294,   302
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "VAR", "_BEGIN", "END",
  "READ", "WRITE", "SKIP", "IF", "THEN", "ELSE", "ENDIF", "GT", "LT", "EQ",
  "NEQ", "GOET", "LOET", "LB", "RB", "SREDNIK", "PRZYPISANIE", "PLUS",
  "MINUS", "NUMBER", "$accept", "program", "vdeclarations", "commands",
  "command", "$@1", "$@2", "$@3", "$@4", "exp", "condition", "identifier", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281
};
# endif

#define YYPACT_NINF -66

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-66)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      16,   -66,     5,    14,   -66,    -2,    93,    24,    39,    62,
       1,    44,   -66,    85,   -66,   -66,    46,     4,    47,    67,
      68,   -66,    11,   -66,   -66,    45,   -66,    49,    76,   -66,
     -66,   -66,    90,   -66,    96,    18,   -66,   -66,    19,    20,
      21,    22,    23,    48,    87,    51,    52,    53,    54,    55,
      57,   -16,    77,    28,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,    93,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,    58,
      59,   -66,    60,    61,    93,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   104,    93,     3,   -66
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,     1,     4,     0,     0,    52,     0,
       0,     0,    13,     0,     7,    11,     0,     0,     0,     0,
       0,    17,     0,     2,     6,     0,     5,     0,     0,     8,
       9,    10,     0,    14,     0,     0,    53,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,     0,    19,    28,    30,    32,    34,    36,    38,
      48,    50,    40,    42,    44,    46,     0,    29,    31,    33,
      35,    37,    39,    49,    51,    41,    43,    45,    47,     0,
       0,    12,     0,     0,    15,    20,    22,    24,    26,    21,
      23,    25,    27,     0,     0,     0,    16
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -66,   -66,   -66,   -65,   -13,   -66,   -66,   -66,   -66,   -66,
     -66,    -7
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    13,    14,    25,    22,    44,    93,    52,
      33,    15
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      24,    84,    18,    20,     8,     4,     8,    27,    79,    80,
       9,    10,    11,    12,     8,    34,    96,     5,     7,     6,
       1,     8,     8,     8,     8,     8,     8,    19,    53,    95,
      28,    55,    57,    59,    61,    63,    65,    32,    68,    70,
      72,    74,    76,    78,    51,    54,    56,    58,    60,    62,
      16,     8,    82,    83,     8,     8,     8,     8,     8,    17,
       8,     8,     8,     8,     8,     8,    21,    26,    35,    29,
      36,    24,    86,    88,    64,    90,    92,    67,    69,    71,
      73,    75,    24,    77,    85,    87,    89,    91,     8,    30,
      31,    23,     9,    10,    11,    12,     8,    37,    66,    81,
       9,    10,    11,    12,    38,    39,    40,    41,    42,    43,
      45,    46,    47,    48,    49,    50,    94
};

static const yytype_uint8 yycheck[] =
{
      13,    66,     9,    10,     3,     0,     3,     3,    24,    25,
       7,     8,     9,    10,     3,    22,    13,     3,    20,     5,
       4,     3,     3,     3,     3,     3,     3,    26,    35,    94,
      26,    38,    39,    40,    41,    42,    43,    26,    45,    46,
      47,    48,    49,    50,    26,    26,    26,    26,    26,    26,
      26,     3,    24,    25,     3,     3,     3,     3,     3,    20,
       3,     3,     3,     3,     3,     3,    22,    21,    23,    22,
      21,    84,    79,    80,    26,    82,    83,    26,    26,    26,
      26,    26,    95,    26,    26,    26,    26,    26,     3,    22,
      22,     6,     7,     8,     9,    10,     3,    21,    11,    22,
       7,     8,     9,    10,    14,    15,    16,    17,    18,    19,
      14,    15,    16,    17,    18,    19,    12
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    28,    29,     0,     3,     5,    20,     3,     7,
       8,     9,    10,    30,    31,    38,    26,    20,    38,    26,
      38,    22,    33,     6,    31,    32,    21,     3,    26,    22,
      22,    22,    26,    37,    38,    23,    21,    21,    14,    15,
      16,    17,    18,    19,    34,    14,    15,    16,    17,    18,
      19,    26,    36,    38,    26,    38,    26,    38,    26,    38,
      26,    38,    26,    38,    26,    38,    11,    26,    38,    26,
      38,    26,    38,    26,    38,    26,    38,    26,    38,    24,
      25,    22,    24,    25,    30,    26,    38,    26,    38,    26,
      38,    26,    38,    35,    12,    30,    13
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    27,    28,    29,    29,    29,    30,    30,    31,    31,
      31,    32,    31,    33,    34,    35,    31,    31,    36,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    37,    38,    38,    38
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     0,     2,     5,     2,     1,     3,     3,
       3,     0,     5,     0,     0,     0,    10,     2,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     4,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 4:
#line 109 "parser.y" /* yacc.c:1646  */
    {	check_double_declaration((yyvsp[0].sval));
							struct var_data v = { i++, 0 };
							zmienne[(yyvsp[0].sval)] = v;				}
#line 1383 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 113 "parser.y" /* yacc.c:1646  */
    {	check_double_declaration((yyvsp[-3].sval));
							struct var_data v = { i, 1 };
							zmienne[(yyvsp[-3].sval)] = v;
							i += (yyvsp[-1].ival);					}
#line 1392 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 121 "parser.y" /* yacc.c:1646  */
    {	load_memory_to_register(1,0);
							GET(1) 
							STORE(1)				}
#line 1400 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 124 "parser.y" /* yacc.c:1646  */
    {	create_number(code, (yyvsp[-1].ival), 1);
							PUT(1)						}
#line 1407 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 126 "parser.y" /* yacc.c:1646  */
    {	mem_to_save_id = 1;
							load_memory_to_register(1,0);
							LOAD(1)
							PUT(1)						}
#line 1416 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 130 "parser.y" /* yacc.c:1646  */
    {	mem_to_save_id = 1;
							load_memory_to_register(1, 1);
							save_register_to_memory(1, 3);			}
#line 1424 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 133 "parser.y" /* yacc.c:1646  */
    {	load_memory_to_register(3, 0);
							STORE(1)
							mem_to_save_id = 1;				}
#line 1432 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 139 "parser.y" /* yacc.c:1646  */
    {       PUSH_ETYK(ety+1) PUSH_ETYK(ety)
                                                        PUSH_ETYK(ety+1) PUSH_ETYK(ety) ety+=2;         }
#line 1439 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 141 "parser.y" /* yacc.c:1646  */
    {       JZERO(1, etykiety.pop()) mem_to_save_id=1;	}
#line 1445 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 143 "parser.y" /* yacc.c:1646  */
    {       JUMP(etykiety.pop())
                                                        POP_AND_WRITE_ETYK				}
#line 1452 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 147 "parser.y" /* yacc.c:1646  */
    {       POP_AND_WRITE_ETYK				}
#line 1458 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 148 "parser.y" /* yacc.c:1646  */
    { }
#line 1464 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 150 "parser.y" /* yacc.c:1646  */
    {       create_number(code, (yyvsp[0].ival), 1);                     }
#line 1470 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 151 "parser.y" /* yacc.c:1646  */
    {       create_number(code, 1, 0);
                                                        LOAD(1)
                                                        COPY(1)
                                                        LOAD(1)                                         }
#line 1479 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 158 "parser.y" /* yacc.c:1646  */
    {	create_number(code, (yyvsp[-2].ival)+(yyvsp[0].ival), 1);			}
#line 1485 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 159 "parser.y" /* yacc.c:1646  */
    {	load_memory_to_register(1, 0);
							create_number(code, (yyvsp[0].ival), 1);
							ADD(1)						}
#line 1493 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 162 "parser.y" /* yacc.c:1646  */
    {	load_memory_to_register(1,0);
							create_number(code, (yyvsp[-2].ival), 1);
							ADD(1)						}
#line 1501 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 165 "parser.y" /* yacc.c:1646  */
    {	load_memory_to_register(1,0);
							LOAD(1)						
							load_memory_to_register(2,0);						
							ADD(1)						}
#line 1510 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 172 "parser.y" /* yacc.c:1646  */
    {	odejmowanie_number_number((yyvsp[-2].ival), (yyvsp[0].ival));		}
#line 1516 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 173 "parser.y" /* yacc.c:1646  */
    {	odejmowanie_identifier_number((yyvsp[0].ival));		}
#line 1522 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 174 "parser.y" /* yacc.c:1646  */
    {	odejmowanie_number_identifier((yyvsp[-2].ival));		}
#line 1528 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 175 "parser.y" /* yacc.c:1646  */
    {	odejmowanie_identifier_identifier(1,2);		}
#line 1534 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 186 "parser.y" /* yacc.c:1646  */
    {	odejmowanie_number_number((yyvsp[-2].ival), (yyvsp[0].ival));		}
#line 1540 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 187 "parser.y" /* yacc.c:1646  */
    {       odejmowanie_identifier_number((yyvsp[0].ival));		}
#line 1546 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 188 "parser.y" /* yacc.c:1646  */
    {       odejmowanie_number_identifier((yyvsp[-2].ival));		}
#line 1552 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 189 "parser.y" /* yacc.c:1646  */
    {       odejmowanie_identifier_identifier(1,2);		}
#line 1558 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 194 "parser.y" /* yacc.c:1646  */
    {	odejmowanie_number_number((yyvsp[0].ival), (yyvsp[-2].ival));	}
#line 1564 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 195 "parser.y" /* yacc.c:1646  */
    {	odejmowanie_number_identifier((yyvsp[0].ival));	}
#line 1570 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 196 "parser.y" /* yacc.c:1646  */
    {	odejmowanie_identifier_number((yyvsp[-2].ival));	}
#line 1576 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 197 "parser.y" /* yacc.c:1646  */
    {	odejmowanie_identifier_identifier(2,1);	}
#line 1582 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 202 "parser.y" /* yacc.c:1646  */
    {	rowne_number_number((yyvsp[-2].ival), (yyvsp[0].ival));		}
#line 1588 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 203 "parser.y" /* yacc.c:1646  */
    {	rowne_identifier_number((yyvsp[0].ival));		}
#line 1594 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 204 "parser.y" /* yacc.c:1646  */
    {	rowne_identifier_number((yyvsp[-2].ival));		}
#line 1600 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 205 "parser.y" /* yacc.c:1646  */
    {	rowne_identifier_identifier();		}
#line 1606 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 213 "parser.y" /* yacc.c:1646  */
    {	XOET_1
                                                        odejmowanie_number_number((yyvsp[-2].ival), (yyvsp[0].ival)); 	//wieksze
                                                        XOET_2
                                                        rowne_number_number((yyvsp[-2].ival), (yyvsp[0].ival));		//rowne
                                                        XOET_3				}
#line 1616 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 218 "parser.y" /* yacc.c:1646  */
    {	XOET_1
							odejmowanie_identifier_number((yyvsp[0].ival));	//wieksze
							XOET_2
							rowne_identifier_number((yyvsp[0].ival));		//rowne
							XOET_3				}
#line 1626 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 223 "parser.y" /* yacc.c:1646  */
    {	XOET_1
							odejmowanie_number_identifier((yyvsp[-2].ival));	//wieksze
							XOET_2
							rowne_identifier_number((yyvsp[-2].ival));		//rowne
							XOET_3				}
#line 1636 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 228 "parser.y" /* yacc.c:1646  */
    {	XOET_1
							odejmowanie_identifier_identifier(1,2);	//wieksze
							XOET_2
							rowne_identifier_identifier();		//rowne
							XOET_3				}
#line 1646 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 240 "parser.y" /* yacc.c:1646  */
    {	XOET_1
							odejmowanie_number_number((yyvsp[0].ival), (yyvsp[-2].ival)); 	//mniejsze
							XOET_2
							rowne_number_number((yyvsp[-2].ival), (yyvsp[0].ival));		//rowne
							XOET_3				}
#line 1656 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 245 "parser.y" /* yacc.c:1646  */
    {	XOET_1
							odejmowanie_number_identifier((yyvsp[0].ival));
							XOET_2
							rowne_identifier_number((yyvsp[0].ival));
							XOET_3				}
#line 1666 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 250 "parser.y" /* yacc.c:1646  */
    {	XOET_1
							odejmowanie_identifier_number((yyvsp[-2].ival));
							XOET_2
							rowne_identifier_number((yyvsp[-2].ival));
							XOET_3				}
#line 1676 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 255 "parser.y" /* yacc.c:1646  */
    {	XOET_1
							odejmowanie_identifier_identifier(2,1);
							XOET_2
							rowne_identifier_identifier();
							XOET_3				}
#line 1686 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 267 "parser.y" /* yacc.c:1646  */
    {	NEQ_1
							odejmowanie_number_number((yyvsp[-2].ival), (yyvsp[0].ival));
							NEQ_2
							odejmowanie_number_number((yyvsp[0].ival), (yyvsp[-2].ival));
							NEQ_3				}
#line 1696 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 272 "parser.y" /* yacc.c:1646  */
    {	NEQ_1
							odejmowanie_identifier_number((yyvsp[0].ival));
							NEQ_2
							odejmowanie_number_identifier((yyvsp[0].ival));
							NEQ_3				}
#line 1706 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 277 "parser.y" /* yacc.c:1646  */
    {	NEQ_1
							odejmowanie_number_identifier((yyvsp[-2].ival));
							NEQ_2
							odejmowanie_identifier_number((yyvsp[-2].ival));
							NEQ_3				}
#line 1716 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 282 "parser.y" /* yacc.c:1646  */
    {	NEQ_1
							odejmowanie_identifier_identifier(1,2);
							NEQ_2
							odejmowanie_identifier_identifier(2,1);
							NEQ_3				}
#line 1726 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 289 "parser.y" /* yacc.c:1646  */
    {	check_identifier((yyvsp[0].sval), 0);
							create_number(code, mem_to_save_id, 0);
							create_number(code, zmienne[(yyvsp[0].sval)].store, 1);
							STORE(1)
							mem_to_save_id++;				}
#line 1736 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 294 "parser.y" /* yacc.c:1646  */
    {	check_identifier((yyvsp[-3].sval), 1);
							check_identifier((yyvsp[-1].sval), 0);
							create_number(code, zmienne[(yyvsp[-1].sval)].store, 0);
							create_number(code, zmienne[(yyvsp[-3].sval)].store, 1);
							ADD(1)
							create_number(code, mem_to_save_id, 0);
							STORE(1)
							mem_to_save_id++;				}
#line 1749 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 302 "parser.y" /* yacc.c:1646  */
    {	check_identifier((yyvsp[-3].sval), 1);
							create_number(code, (yyvsp[-1].ival), 1);
							ZERO(0)
							STORE(1)
							create_number(code, zmienne[(yyvsp[-3].sval)].store, 1);
							ADD(1)
							create_number(code, mem_to_save_id, 0);
							STORE(1)
							mem_to_save_id++;				}
#line 1763 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1767 "parser.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 313 "parser.y" /* yacc.c:1906  */


/****** CHECK *******************************************************************************************/
/********************************************************************************************************/
/*
Sprawdzenie czy zmienna o nazwie 'name' nie zostala zadeklarowana kolejny raz
Jezeli tak sie stalo, zakoncz program z odpowiednia wiadomoscia					
*/
void check_double_declaration(string name){
	if( zmienne.find(name) != zmienne.end() ){
                string err = string("Deklaracja istniejacej zmiennej \"") + string(name) + string("\"");
                yyerror(err.c_str());
        }
}

/* 
Sprawdzamy czy przeczytany identyfikator o nazwie 'name' zostal wczesniej zadeklarowany, oraz
czy jest on tablica (wtedy isArray = 1), czy jest zmienna (isArray = 0).
Jezeli ktorys z tych warunkow zawiedzie konczymy program z odpowiednim komunikatem.		
*/ 
void check_identifier(string name, int isArray){
	if( zmienne.find(name) == zmienne.end() ){
		string err = string("Niezadeklarowana zmienna \"") + string(name) + string("\"");
		yyerror(err.c_str());
	}
	else if( zmienne[name].isArray != isArray ){
		string err = string("Niewlasciwe uzycie identyfikatora \"") + string(name) +string("\"");
		yyerror(err.c_str());
	}
}

/*
Funkcja generujaca asembler ktory dziala na rejestrze 0. Wczytuje on dana z komorki pamieci
'memory' do rejestru 'reg'.
*/
void load_memory_to_register(int memory, int reg){
	create_number(code, memory, 0);
	LOAD(reg)
}

void save_register_to_memory(int reg, int memory){
	create_number(code, memory, 0);
	STORE(reg)
}

void save_number_to_memory(int number, int memory){
	create_number(code, number, 1);
	create_number(code, memory, 0);
	STORE(1)
}

/************************************************************************/
/***** OPERACJE *********************************************************/
/************************************************************************/

void odejmowanie_number_number(int a, int b){
	create_number(code, numbSub(a, b), 1);
}

void odejmowanie_identifier_number(int num){
	save_number_to_memory(num, 0);
	load_memory_to_register(1, 0);		
	LOAD(1)
	ZERO(0)
	SUB(1)
}

void odejmowanie_number_identifier(int num){
	load_memory_to_register(1, 0);
	create_number(code, num, 1);
	SUB(1)
}

/*zmienne a b oznaczaja ktory identifier jest odejmowany od ktorego, czyli:
	a=1, b=2 -> odejmujemy id1 - id2
	a=2, b=1 -> odejmujemy id2 - id1	*/
void odejmowanie_identifier_identifier(int a, int b){
	load_memory_to_register(a,0);
	LOAD(1)
	load_memory_to_register(b,0);
	SUB(1)
}

/************************************************************************/
/***** WARUNKI **********************************************************/
/************************************************************************/
void rowne_number_number(int a, int b){
	EQ_1
	odejmowanie_number_number(a, b);	//odejmowanie
	EQ_2
	odejmowanie_number_number(b, a);	//odejmowanie
	EQ_3
}

void rowne_identifier_number(int num){
	EQ_1
	odejmowanie_identifier_number(num);	//odejmowanie
	EQ_2
	odejmowanie_number_identifier(num);	//odejmowanie
	EQ_3
}

void rowne_identifier_identifier(){
	EQ_1
	odejmowanie_identifier_identifier(1,2);	//odejmowanie
	EQ_2
	odejmowanie_identifier_identifier(2,1);	//odejmowanie
	EQ_3
}


/************************************************************************/
/***** PRZEBIEGI ********************************************************/
/************************************************************************/

void zapamietajPozycjeEtykiet(map<string, string> &ety_pos){
        for(int j=0 ; j<code.size(); j++){
                if(isPrefix("E", code[j])){
                        ostringstream ss;
                        ss << j;
                        ety_pos[code[j]] = ss.str();
                        code.erase(code.begin()+j);
                        j--;
                }
        }
}

void podmienEtykiety(map<string, string> &ety_pos){
       for(int j=0 ; j<code.size() ; j++)
                if(isPrefix("JUMP", code[j]) || isPrefix("JZERO", code[j]) || isPrefix("JODD", code[j]))
                        code[j] = replaceLastWord( code[j], ety_pos[ getLastWord(code[j]) ] );
}

void wypiszAssembler(){
	for(int j=0; j<code.size(); j++)
		cout << code[j] << endl;
	cout << "HALT" << endl;
}

/************************************************************************/
/******** MAIN **********************************************************/
/************************************************************************/

int main()
{
	yyparse();
	map<string, string> ety_pos;
	zapamietajPozycjeEtykiet(ety_pos);
	podmienEtykiety(ety_pos);
	wypiszAssembler();
}


void yyerror(const char *s){
        cout << "Blad. " << s << " w linii " << yylineno << endl;
        exit(0);
}
