/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse compilerparse
#define yylex   compilerlex
#define yyerror compilererror
#define yylval  compilerlval
#define yychar  compilerchar
#define yydebug compilerdebug
#define yynerrs compilernerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     tMain = 258,
     tOpenBracket = 259,
     tCloseBracket = 260,
     tOpenBrace = 261,
     tCloseBrace = 262,
     tConstantKey = 263,
     tIntegerKey = 264,
     tName = 265,
     tAdd = 266,
     tSubstract = 267,
     tMultiply = 268,
     tDivide = 269,
     tEqual = 270,
     tSpace = 271,
     tTab = 272,
     tComma = 273,
     tSemiColon = 274,
     tPrintKey = 275,
     tNumber = 276,
     tCompEqual = 277,
     tLt = 278,
     tGt = 279,
     tDifferent = 280,
     tElseKey = 281,
     tWhileKey = 282,
     tNullKey = 283,
     tRef = 284,
     tStringKey = 285,
     tString = 286,
     tIfKey = 287,
     tIfX = 288
   };
#endif
/* Tokens.  */
#define tMain 258
#define tOpenBracket 259
#define tCloseBracket 260
#define tOpenBrace 261
#define tCloseBrace 262
#define tConstantKey 263
#define tIntegerKey 264
#define tName 265
#define tAdd 266
#define tSubstract 267
#define tMultiply 268
#define tDivide 269
#define tEqual 270
#define tSpace 271
#define tTab 272
#define tComma 273
#define tSemiColon 274
#define tPrintKey 275
#define tNumber 276
#define tCompEqual 277
#define tLt 278
#define tGt 279
#define tDifferent 280
#define tElseKey 281
#define tWhileKey 282
#define tNullKey 283
#define tRef 284
#define tStringKey 285
#define tString 286
#define tIfKey 287
#define tIfX 288




/* Copy the first part of user declarations.  */
#line 1 "compiler.y"

#include <stdio.h>
#include <stdlib.h>
#include "compiler_table.h"
#include "list.h"
#include "utils.h"

#define yyparse compiler_parse
#define yylex compiler_lex
#define yyerror compiler_error

int_list jumpList;

int declarationAddress = 0;

int currentAddress = -1;
int cptIf = 0;
int cptLine = 0;
extern int currentLine;

FILE *file = NULL;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 61 "compiler.y"
{char* string ; int integer; int line;}
/* Line 193 of yacc.c.  */
#line 195 "compiler.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 208 "compiler.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   102

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  45
/* YYNRULES -- Number of states.  */
#define YYNSTATES  101

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    11,    13,    14,    18,    21,    25,    28,
      31,    34,    39,    45,    50,    52,    58,    65,    67,    70,
      72,    75,    78,    82,    87,    88,    98,    99,   105,   107,
     108,   117,   121,   125,   129,   131,   136,   140,   145,   149,
     153,   157,   161,   163,   165,   167
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      35,     0,    -1,     9,     3,     4,     5,     6,    36,     7,
      -1,    38,    -1,    -1,    38,    37,    41,    -1,    39,    38,
      -1,    39,    19,    38,    -1,    39,    19,    -1,    18,    10,
      -1,     9,    10,    -1,     9,    10,    15,    21,    -1,     8,
       9,    10,    15,    21,    -1,    30,    10,    15,    31,    -1,
      40,    -1,     9,    13,    10,    15,    28,    -1,     9,    13,
      10,    15,    29,    10,    -1,    42,    -1,    42,    41,    -1,
      47,    -1,    47,    41,    -1,    50,    19,    -1,    50,    19,
      41,    -1,    44,     6,    41,     7,    -1,    -1,    44,     6,
      41,     7,    43,    46,     6,    41,     7,    -1,    -1,    32,
       4,    49,    45,     5,    -1,    26,    -1,    -1,    27,     4,
      49,    48,     5,     6,    41,     7,    -1,    10,    22,    52,
      -1,    10,    23,    52,    -1,    10,    24,    52,    -1,    51,
      -1,    20,     4,    51,     5,    -1,    10,    15,    51,    -1,
      13,    10,    15,    51,    -1,    51,    11,    51,    -1,    51,
      12,    51,    -1,    51,    13,    51,    -1,    51,    14,    51,
      -1,    52,    -1,    10,    -1,    21,    -1,    13,    10,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    72,    72,    78,    80,    79,    89,    90,    91,    94,
     103,   112,   126,   140,   162,   165,   171,   187,   189,   191,
     193,   195,   197,   201,   207,   206,   217,   216,   224,   233,
     232,   250,   265,   280,   296,   298,   307,   320,   334,   345,
     355,   366,   377,   381,   393,   401
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tMain", "tOpenBracket", "tCloseBracket",
  "tOpenBrace", "tCloseBrace", "tConstantKey", "tIntegerKey", "tName",
  "tAdd", "tSubstract", "tMultiply", "tDivide", "tEqual", "tSpace", "tTab",
  "tComma", "tSemiColon", "tPrintKey", "tNumber", "tCompEqual", "tLt",
  "tGt", "tDifferent", "tElseKey", "tWhileKey", "tNullKey", "tRef",
  "tStringKey", "tString", "tIfKey", "tIfX", "$accept", "Start", "Body",
  "@1", "Vars", "Var", "Pointer", "Functions", "Condition", "@2", "If",
  "@3", "Else", "While", "@4", "Comparison", "Function", "Operation",
  "Term", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    36,    37,    36,    38,    38,    38,    39,
      39,    39,    39,    39,    39,    40,    40,    41,    41,    41,
      41,    41,    41,    42,    43,    42,    45,    44,    46,    48,
      47,    49,    49,    49,    50,    50,    50,    50,    51,    51,
      51,    51,    51,    52,    52,    52
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     1,     0,     3,     2,     3,     2,     2,
       2,     4,     5,     4,     1,     5,     6,     1,     2,     1,
       2,     2,     3,     4,     0,     9,     0,     5,     1,     0,
       8,     3,     3,     3,     1,     4,     3,     4,     3,     3,
       3,     3,     1,     1,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     4,     0,    14,     0,    10,     0,     9,
       0,     2,     0,     8,     6,     0,     0,     0,     0,    43,
       0,     0,    44,     0,     0,     5,    17,     0,    19,     0,
      34,    42,     7,     0,    11,     0,    13,     0,    45,     0,
       0,     0,    18,     0,    20,    21,     0,     0,     0,     0,
      12,    15,     0,    43,     0,    36,     0,     0,     0,    29,
      26,     0,    22,    38,    39,    40,    41,    16,    45,    37,
      35,     0,     0,     0,     0,     0,    23,    31,    32,    33,
       0,    27,     0,     0,    28,     0,     0,     0,    30,     0,
      25
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    12,    22,    13,    14,    15,    35,    36,    92,
      37,    85,    95,    38,    84,    69,    39,    40,    41
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -37
static const yytype_int8 yypact[] =
{
      -6,    36,    35,    52,   -37,    53,    34,    12,    50,    16,
      54,    55,    56,    59,    -3,   -37,    57,    45,    58,   -37,
      47,   -37,    -9,    12,   -37,    60,    48,    61,    39,    62,
      63,    67,   -37,    68,    70,   -37,    -9,    72,    -9,    64,
      -4,   -37,   -37,    65,   -37,   -15,   -37,    15,    66,    15,
      69,    69,   -37,    -9,   -37,    -9,    15,    15,    15,    15,
     -37,   -37,    74,   -37,    75,    -4,    15,    32,    26,   -37,
     -37,    73,   -37,    41,    41,    41,    41,   -37,   -37,    -4,
     -37,    15,    15,    15,    77,    82,    71,   -37,   -37,   -37,
      83,   -37,    76,    -9,   -37,    84,    81,    -9,   -37,    85,
     -37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -37,   -37,   -37,   -37,    24,   -37,   -37,   -36,   -37,   -37,
     -37,   -37,   -37,   -37,   -37,    40,   -37,   -25,   -30
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -25
static const yytype_int8 yytable[] =
{
      52,    29,    54,     1,    30,     8,     9,    56,    57,    58,
      59,    31,    32,    61,    62,    10,    23,    71,    33,    72,
       8,     9,    65,    34,    67,    63,    17,    11,    64,    18,
      10,    73,    74,    75,    76,     4,    32,    80,    24,     3,
       7,    79,    11,    56,    57,    58,    59,    42,    81,    82,
      83,    87,    88,    89,    58,    59,     5,    96,     6,    16,
      26,    99,    28,    21,    19,    20,    -3,    25,    27,    44,
      46,    49,    50,    48,    51,    43,    45,    47,    53,    68,
      86,    66,    90,    55,    77,    78,    60,    91,    98,    93,
      97,    70,   100,     0,     0,     0,     0,   -24,     0,     0,
       0,     0,    94
};

static const yytype_int8 yycheck[] =
{
      36,    10,    38,     9,    13,     8,     9,    11,    12,    13,
      14,    20,    21,    28,    29,    18,    19,    53,    27,    55,
       8,     9,    47,    32,    49,    10,    10,    30,    13,    13,
      18,    56,    57,    58,    59,     0,    21,     5,    14,     3,
       6,    66,    30,    11,    12,    13,    14,    23,    22,    23,
      24,    81,    82,    83,    13,    14,     4,    93,     5,     9,
      15,    97,    15,     7,    10,    10,     7,    10,    10,    21,
      31,     4,     4,    10,     4,    15,    15,    15,     6,    10,
       7,    15,     5,    19,    10,    10,    21,     5,     7,     6,
       6,    51,     7,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    26
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    35,     3,     0,     4,     5,     6,     8,     9,
      18,    30,    36,    38,    39,    40,     9,    10,    13,    10,
      10,     7,    37,    19,    38,    10,    15,    10,    15,    10,
      13,    20,    21,    27,    32,    41,    42,    44,    47,    50,
      51,    52,    38,    15,    21,    15,    31,    15,    10,     4,
       4,     4,    41,     6,    41,    19,    11,    12,    13,    14,
      21,    28,    29,    10,    13,    51,    15,    51,    10,    49,
      49,    41,    41,    51,    51,    51,    51,    10,    10,    51,
       5,    22,    23,    24,    48,    45,     7,    52,    52,    52,
       5,     5,    43,     6,    26,    46,    41,     6,     7,    41,
       7
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 73 "compiler.y"
    {
                    printf("Compiler : Syntax correct\n");
                ;}
    break;

  case 4:
#line 80 "compiler.y"
    {
                    if(currentAddress == -1) {
                        currentAddress = declarationAddress;
                    }
                ;}
    break;

  case 9:
#line 95 "compiler.y"
    {
                    compiler_element *element = find_by_name((yyvsp[(2) - (2)].string),1);
                    
                    element->address = declarationAddress;
                    element->pointer = 0;
                    declarationAddress += INT_SIZE;
                ;}
    break;

  case 10:
#line 104 "compiler.y"
    {
                    compiler_element *element = find_by_name((yyvsp[(2) - (2)].string),1);
                    
                    element->address = declarationAddress;
                    element->pointer = 0;
                    declarationAddress += INT_SIZE;
                ;}
    break;

  case 11:
#line 113 "compiler.y"
    {
                    compiler_element *element = find_by_name((yyvsp[(2) - (4)].string),1);
                    
                    element->value = (yyvsp[(4) - (4)].integer);
                    element->address = declarationAddress;
                    element->pointer = 0;
                    
                    fprintf(file,"AFC %d %d\n",element->address,element->value);
                    
                    cptLine++;
                    declarationAddress += INT_SIZE;
                ;}
    break;

  case 12:
#line 127 "compiler.y"
    {
                    compiler_element *element = find_by_name((yyvsp[(3) - (5)].string),1);
                    
                    element->value = (yyvsp[(5) - (5)].integer);
                    element->address = declarationAddress;
                    element->pointer = 0;
                    
                    fprintf(file,"AFC %d %d\n",element->address,element->value);
                    
                    cptLine++;
                    declarationAddress += INT_SIZE;
                ;}
    break;

  case 13:
#line 141 "compiler.y"
    {
                    compiler_element *element = find_by_name((yyvsp[(2) - (4)].string),1);
                    int size = strlen((yyvsp[(4) - (4)].string));
                    int i;
                    int j = 0;
                    
                    element->address = declarationAddress;
                    element->pointer = 0;

                    for(i=0; i < size ; i++) {
                        if((yyvsp[(4) - (4)].string)[i] != '"') {
                            fprintf(file,"AFC %d %d\n",element->address + j,(int)(yyvsp[(4) - (4)].string)[i]);
                            cptLine++;
                            j++;
                        }
                    }
                    fprintf(file,"AFC %d %d\n",element->address + size - 2,-1);
                    
                    declarationAddress += size - 1;
                ;}
    break;

  case 15:
#line 166 "compiler.y"
    {
                    compiler_element *element = find_by_name((yyvsp[(3) - (5)].string),1);
                    element->pointer = 1;
                ;}
    break;

  case 16:
#line 172 "compiler.y"
    {
                    compiler_element *element = find_by_name((yyvsp[(3) - (6)].string),1);
                    
                    element->value = find_by_name((yyvsp[(6) - (6)].string),0)->address;
                    element->address = declarationAddress;
                    element->pointer = 1;
                    
                    fprintf(file,"AFC %d %d\n",element->address,element->value);
                    
                    cptLine++;
                    declarationAddress += INT_SIZE;
                ;}
    break;

  case 23:
#line 202 "compiler.y"
    {
                    jumpList = addLast(jumpList,cptLine + 1);
                ;}
    break;

  case 24:
#line 207 "compiler.y"
    {
                    jumpList = addLast(jumpList,cptLine + 2);
                ;}
    break;

  case 25:
#line 211 "compiler.y"
    {
                    jumpList = addLast(jumpList,cptLine + 1);
                ;}
    break;

  case 26:
#line 217 "compiler.y"
    {
                    cptIf++;
                    fprintf(file,"JMF %d [%d]\n",(yyvsp[(3) - (3)].integer), cptIf - 1);
                    cptLine++;
                ;}
    break;

  case 28:
#line 225 "compiler.y"
    {
                    cptIf++;
                    fprintf(file,"JMP [%d]\n", cptIf - 1);
                    cptLine++;
                ;}
    break;

  case 29:
#line 233 "compiler.y"
    {
                    cptIf++;
                    fprintf(file,"JMF %d [%d]\n",(yyvsp[(3) - (3)].integer), cptIf - 1);
                    cptLine++;
                    jumpList = addLast(jumpList,cptLine -  1);
                ;}
    break;

  case 30:
#line 240 "compiler.y"
    {
                    cptIf++;
                    jumpList = addBeforelast(jumpList,cptLine + 2);
                    fprintf(file,"JMP [%d]\n", cptIf - 1);
                    cptLine++;
                    compiler_free(currentAddress);
                    currentAddress -= INT_SIZE;
                ;}
    break;

  case 31:
#line 251 "compiler.y"
    {
                    int min = currentAddress < (yyvsp[(3) - (3)].integer) ? currentAddress : (yyvsp[(3) - (3)].integer);
                    
                    compiler_element *element = find_by_name((yyvsp[(1) - (3)].string),0);
                    if(element == NULL)
                        compiler_error("Variable non déclarée.");
                    
                    fprintf(file,"EQU %d %d %d\n",min,element->address,(yyvsp[(3) - (3)].integer));
                    
                    cptLine++;
                    (yyval.integer) = min;
                    //currentAddress -= INT_SIZE;
                ;}
    break;

  case 32:
#line 266 "compiler.y"
    {
                    int min = currentAddress < (yyvsp[(3) - (3)].integer) ? currentAddress : (yyvsp[(3) - (3)].integer);
                    
                    compiler_element *element = find_by_name((yyvsp[(1) - (3)].string),0);
                    if(element == NULL)
                        compiler_error("Variable non déclarée.");
                    
                    fprintf(file,"INF %d %d %d\n",min,element->address,(yyvsp[(3) - (3)].integer));
                    
                    cptLine++;
                    (yyval.integer) = min;
                    //currentAddress -= INT_SIZE;
                ;}
    break;

  case 33:
#line 281 "compiler.y"
    {
                    int min = currentAddress < (yyvsp[(3) - (3)].integer) ? currentAddress : (yyvsp[(3) - (3)].integer);
                    
                    compiler_element *element = find_by_name((yyvsp[(1) - (3)].string),0);
                    if(element == NULL)
                        compiler_error("Variable non déclarée.");
                    
                    fprintf(file,"SUP %d %d %d\n",min,element->address,(yyvsp[(3) - (3)].integer));
                    
                    cptLine++;
                    (yyval.integer) = min;
                    //currentAddress -= INT_SIZE;
                ;}
    break;

  case 35:
#line 299 "compiler.y"
    {
                    fprintf(file,"PRI %d\n",(yyvsp[(3) - (4)].integer));
                    
                    cptLine++;
                    compiler_free(currentAddress);
                    currentAddress -= INT_SIZE;
                ;}
    break;

  case 36:
#line 308 "compiler.y"
    {
                    compiler_element *element = find_by_name((yyvsp[(1) - (3)].string),0);
                    if(element == NULL)
                        compiler_error("Variable non déclarée.");
                    
                    fprintf(file,"COP %d %d\n",element->address,(yyvsp[(3) - (3)].integer));
                    
                    cptLine++;
                    compiler_free(currentAddress);
                    currentAddress -= INT_SIZE;
                ;}
    break;

  case 37:
#line 321 "compiler.y"
    {
                    compiler_element *element = find_by_name((yyvsp[(2) - (4)].string),0);
                    if(element == NULL)
                        compiler_error("Variable non déclarée.");
                    
                    fprintf(file,"COP %d %d\n",element->value,(yyvsp[(4) - (4)].integer));
                    
                    cptLine++;
                    compiler_free(currentAddress);
                    currentAddress -= INT_SIZE;
                ;}
    break;

  case 38:
#line 335 "compiler.y"
    {
                    int min = (yyvsp[(1) - (3)].integer) < (yyvsp[(3) - (3)].integer) ? (yyvsp[(1) - (3)].integer) : (yyvsp[(3) - (3)].integer);
                    
                    fprintf(file,"ADD %d %d %d\n",min,(yyvsp[(1) - (3)].integer),(yyvsp[(3) - (3)].integer));
                    
                    cptLine++;
                    compiler_free(currentAddress);
                    currentAddress -= INT_SIZE;
                ;}
    break;

  case 39:
#line 346 "compiler.y"
    {
                    int min = (yyvsp[(1) - (3)].integer) < (yyvsp[(3) - (3)].integer) ? (yyvsp[(1) - (3)].integer) : (yyvsp[(3) - (3)].integer);
                    
                    fprintf(file,"SOU %d %d %d\n",min,(yyvsp[(1) - (3)].integer),(yyvsp[(3) - (3)].integer));
                    
                    cptLine++;
                    compiler_free(currentAddress);
                    currentAddress -= INT_SIZE;
                ;}
    break;

  case 40:
#line 356 "compiler.y"
    {
                    int min = (yyvsp[(1) - (3)].integer) < (yyvsp[(3) - (3)].integer) ? (yyvsp[(1) - (3)].integer) : (yyvsp[(3) - (3)].integer);
                    
                    fprintf(file,"MUL %d %d %d\n",min,(yyvsp[(1) - (3)].integer),(yyvsp[(3) - (3)].integer));
                    
                    cptLine++;
                    compiler_free(currentAddress);
                    currentAddress -= INT_SIZE;
                ;}
    break;

  case 41:
#line 367 "compiler.y"
    {
                    int min = (yyvsp[(1) - (3)].integer) < (yyvsp[(3) - (3)].integer) ? (yyvsp[(1) - (3)].integer) : (yyvsp[(3) - (3)].integer);
                    
                    fprintf(file,"DIV %d %d %d\n",min,(yyvsp[(1) - (3)].integer),(yyvsp[(3) - (3)].integer));
                    
                    cptLine++;
                    compiler_free(currentAddress);
                    currentAddress -= INT_SIZE;
                ;}
    break;

  case 43:
#line 382 "compiler.y"
    {
                    compiler_element *element = find_by_name((yyvsp[(1) - (1)].string),0);
                    if(element == NULL)
                        compiler_error("Variable non déclarée.");
                    
                    fprintf(file,"COP %d %d\n",currentAddress,element->address);
                    cptLine++;
                    (yyval.integer) = currentAddress;
                    currentAddress += INT_SIZE;
                ;}
    break;

  case 44:
#line 394 "compiler.y"
    {
                    fprintf(file,"AFC %d %d\n",currentAddress,(yyvsp[(1) - (1)].integer));
                    cptLine++;
                    (yyval.integer) = currentAddress;
                    currentAddress += INT_SIZE;
                ;}
    break;

  case 45:
#line 402 "compiler.y"
    {
                    compiler_element *element = find_by_name((yyvsp[(2) - (2)].string),0);
                    if(element == NULL)
                        compiler_error("Variable non déclarée.");
                    
                    
                    if(element->pointer == 0)
                        compiler_error("Given variable is not a pointer");
                    
                    fprintf(file,"COP %d %d\n",currentAddress,element->value);
                    
                    cptLine++;
                    (yyval.integer) = currentAddress;
                    currentAddress += INT_SIZE;
                ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1850 "compiler.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 419 "compiler.y"


int secondTime() {
    int i ;
    char c[4];
    
    if(file != NULL) {
        fseek(file, 0, SEEK_END);
        long fsize = ftell(file);
        fseek(file, 0, SEEK_SET);
        
        char *string = malloc(fsize + 1);
        fread(string, fsize, 1, file);
        
        fclose(file);                       //esay way to clear a file
        file = fopen("output.txt","w+");
        
        for(i=0; i<size(jumpList); i++) {
            char cat[10];
            sprintf(c, "%d", value(get(jumpList,i)));
            sprintf(cat,"[%d]",i);
            replaceAllString(string,cat,c);
        }
        
        fprintf(file,"%s\n",string);
    }

    return 0;
}

int main(void) {
    
    file = fopen("output.txt","w+");
    
    if(file != NULL) {
        compiler_parse();
        secondTime();
        fclose(file);
        system("./interpreter");
    }
    else {
        compiler_error("Impossible to execute second time parser");
    }
	return 0;
}

int compiler_error(char *err)
{
    printf("Error (line %d) : %s\n", currentLine, err);
    exit(EXIT_FAILURE);
    return -1;
}


