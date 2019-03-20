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

#include <stdio.h>
#include <iostream>
extern "C" void yyerror (std::string);
extern int yylex(void);
extern int yylineno;
Symbol_Table gst;
Symbol_Table lst;
int scope = 1;

#line 77 "parser.tab.c" /* yacc.c:339  */

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
    INTEGER_NUMBER = 258,
    DOUBLE_NUMBER = 259,
    INTEGER = 260,
    FLOAT = 261,
    VOID = 262,
    IF = 263,
    ELSE = 264,
    WHILE = 265,
    DO = 266,
    RETURN = 267,
    ASSIGN = 268,
    LESS_THAN_EQUAL = 269,
    GREATER_THAN_EQUAL = 270,
    EQUAL = 271,
    NOT_EQUAL = 272,
    NOT = 273,
    LESS_THAN = 274,
    GREATER_THAN = 275,
    AND = 276,
    OR = 277,
    NAME = 278
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 11 "parser.y" /* yacc.c:355  */

	int ival;
	double fval;
	std::string * sval;
	//list<std::string *> * ast_li;
	list<Ast *> * ast_list;
	Ast * ast;
	Sequence_Ast * sast;
	Symbol_Table * symbol_table;
	Symbol_Table_Entry * symbol_entry;
	list<Symbol_Table_Entry *> * sym_entry_list;
	Basic_Block * basic_block;
	Procedure * procedure;

#line 156 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 173 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   157

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  117

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   278

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
      28,    29,    26,    24,    33,    25,     2,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    32,
       2,     2,     2,    34,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,    31,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    65,    65,    73,    98,   115,   149,   155,   164,   175,
     182,   191,   195,   204,   210,   219,   223,   227,   231,   235,
     242,   267,   272,   276,   281,   285,   291,   296,   300,   305,
     311,   317,   323,   329,   335,   342,   346,   352,   357,   364,
     369,   374,   381,   385,   389,   393,   399,   406,   413,   419,
     426,   435,   442,   462,   468,   474,   480,   486,   492
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER_NUMBER", "DOUBLE_NUMBER",
  "INTEGER", "FLOAT", "VOID", "IF", "ELSE", "WHILE", "DO", "RETURN",
  "ASSIGN", "LESS_THAN_EQUAL", "GREATER_THAN_EQUAL", "EQUAL", "NOT_EQUAL",
  "NOT", "LESS_THAN", "GREATER_THAN", "AND", "OR", "NAME", "'+'", "'-'",
  "'*'", "'/'", "'('", "')'", "'{'", "'}'", "';'", "','", "'?'", "':'",
  "$accept", "program", "procedure_definition",
  "variable_declaration_list", "variable_declaration", "declaration",
  "variable_list", "total_list_main", "total_list", "single_element",
  "assignment_statement", "Logexp", "L1", "L2", "L3", "Relexp",
  "if_else_block", "match_st", "unmatch_st", "other_st", "while_block",
  "do_wh_block", "TernExp", "E", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    43,    45,    42,    47,    40,    41,
     123,   125,    59,    44,    63,    58
};
# endif

#define YYPACT_NINF -65

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-65)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -65,     9,   115,   -65,     5,     5,    15,   -65,   -65,   -12,
     -65,    14,    14,    25,   -65,    19,    33,   -65,    47,   -65,
      51,    44,    35,    53,    78,    71,    78,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,    18,    18,    77,    18,    68,
     -65,   -65,   -65,    18,   -65,    36,    18,     1,    73,   -65,
     -65,   -65,   134,     0,    75,    89,   -15,    -3,   -65,   -65,
     -65,    18,   -65,   111,   112,    18,    82,    18,    18,    18,
      18,    18,    18,    18,    18,    36,    36,    36,    36,    78,
      18,   -65,   -65,   -65,    73,    78,   -65,   -65,    87,    91,
     -65,   -65,    99,   -65,   134,   134,   134,   134,   134,   134,
      80,    80,   -65,   -65,   -65,   113,    72,   116,   100,    36,
      93,   -65,   -65,   -65,   -65,     0,   -65
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,     0,     0,     0,     2,     5,     0,
       9,     7,     8,     0,     6,     0,     0,    10,     0,     4,
      11,     0,     0,     0,     0,     0,     0,     3,    12,    18,
      15,    35,    36,    16,    17,     0,     0,     0,     0,     0,
      13,    50,    51,     0,    52,     0,     0,     0,    22,    24,
      26,    27,     0,    49,     0,     0,     0,     0,    19,    14,
      25,     0,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,    28,    58,    21,     0,    42,    39,    35,    41,
      44,    45,     0,    23,    30,    32,    33,    34,    29,    31,
      53,    54,    55,    56,    46,     0,     0,     0,     0,     0,
       0,    43,    37,    40,    38,    48,    47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -65,   -65,   -65,   117,   -65,   -65,   132,   -65,    54,   -21,
     -64,   -31,    79,    70,   103,   -65,    86,   -56,    48,    49,
     -60,   -58,    -1,   -44
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     7,     2,     8,     9,    11,    21,    39,    40,
      29,    56,    48,    49,    50,    51,    30,    31,    32,    89,
      33,    34,    52,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      28,    62,    86,    37,    47,    54,    90,    65,    91,     3,
      88,    69,    70,    71,    72,    63,    73,    74,    59,    67,
      14,    41,    42,    65,    75,    76,    77,    78,    10,    81,
      66,   100,   101,   102,   103,    67,    43,    57,    13,    41,
      42,    44,    17,    45,    86,    64,    46,    15,    90,   105,
      91,   112,    22,    16,    23,    24,     4,     5,   104,    44,
      64,    45,    18,    35,    61,   115,    92,    25,    94,    95,
      96,    97,    98,    99,    26,    27,    22,    19,    23,    24,
      22,    36,    23,    24,    38,    59,    22,    55,    23,    24,
      22,    25,    23,    24,    68,    25,   107,    65,    26,    58,
     108,    25,    26,   111,    79,    25,    77,    78,    26,    67,
      23,    24,    85,    69,    70,    71,    72,    80,    73,    74,
       4,     5,     6,    25,    22,   116,    69,    70,    71,    72,
      85,    73,    74,    65,   109,    65,    20,    12,    93,   106,
      82,    83,   110,     0,    84,    67,    60,    67,    69,    70,
      71,    72,    87,    73,    74,   113,     0,   114
};

static const yytype_int8 yycheck[] =
{
      21,    45,    66,    24,    35,    36,    66,    22,    66,     0,
      66,    14,    15,    16,    17,    46,    19,    20,    39,    34,
      32,     3,     4,    22,    24,    25,    26,    27,    23,    32,
      29,    75,    76,    77,    78,    34,    18,    38,    23,     3,
       4,    23,    23,    25,   108,    46,    28,    33,   108,    80,
     108,   107,     8,    28,    10,    11,     5,     6,    79,    23,
      61,    25,    29,    28,    28,   109,    67,    23,    69,    70,
      71,    72,    73,    74,    30,    31,     8,    30,    10,    11,
       8,    28,    10,    11,    13,   106,     8,    10,    10,    11,
       8,    23,    10,    11,    21,    23,     9,    22,    30,    31,
       9,    23,    30,    31,    29,    23,    26,    27,    30,    34,
      10,    11,    30,    14,    15,    16,    17,    28,    19,    20,
       5,     6,     7,    23,     8,    32,    14,    15,    16,    17,
      30,    19,    20,    22,    35,    22,    19,     5,    68,    85,
      29,    29,    29,    -1,    65,    34,    43,    34,    14,    15,
      16,    17,    66,    19,    20,   107,    -1,   108
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    39,     0,     5,     6,     7,    38,    40,    41,
      23,    42,    42,    23,    32,    33,    28,    23,    29,    30,
      39,    43,     8,    10,    11,    23,    30,    31,    45,    46,
      52,    53,    54,    56,    57,    28,    28,    45,    13,    44,
      45,     3,     4,    18,    23,    25,    28,    47,    48,    49,
      50,    51,    58,    59,    47,    10,    47,    58,    31,    45,
      50,    28,    59,    47,    58,    22,    29,    34,    21,    14,
      15,    16,    17,    19,    20,    24,    25,    26,    27,    29,
      28,    32,    29,    29,    48,    30,    46,    52,    53,    55,
      56,    57,    58,    49,    58,    58,    58,    58,    58,    58,
      59,    59,    59,    59,    45,    47,    44,     9,     9,    35,
      29,    31,    53,    54,    55,    59,    32
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    38,    39,    39,    40,    41,    41,    42,
      42,    43,    43,    44,    44,    45,    45,    45,    45,    45,
      46,    47,    47,    48,    48,    49,    49,    50,    50,    51,
      51,    51,    51,    51,    51,    52,    52,    53,    53,    54,
      54,    54,    55,    55,    55,    55,    56,    57,    58,    58,
      59,    59,    59,    59,    59,    59,    59,    59,    59
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     8,     0,     2,     2,     2,     2,     1,
       3,     0,     2,     1,     2,     1,     1,     1,     1,     3,
       4,     3,     1,     3,     1,     2,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     7,     7,     5,
       7,     5,     1,     3,     1,     1,     5,     7,     5,     1,
       1,     1,     1,     3,     3,     3,     3,     2,     3
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
        case 2:
#line 67 "parser.y" /* yacc.c:1646  */
    {
					program_object.set_procedure((yyvsp[0].procedure), yylineno);
					program_object.set_global_table(*(yyvsp[-1].symbol_table));
				}
#line 1337 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 78 "parser.y" /* yacc.c:1646  */
    {			
					Procedure *main = new Procedure(void_data_type,*(yyvsp[-6].sval),yylineno);
					
					
					main->set_local_list(*(yyvsp[-2].symbol_table));
					//$<symbol_table>6->print(std::cout);
					
//					astl_t = *($<ast_list>7);
					list<Ast *> :: iterator i;
					/*for(i=astl_t.begin();i!=astl_t.end();++i)
					{
						(*i)->print(std::cout);
					}*/
					main->set_ast_list(*((yyvsp[-1].ast_list)));
					//printf("sa%dsa\n",$<ast_list>7->size());
					(yyval.procedure) = main;
				}
#line 1359 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 98 "parser.y" /* yacc.c:1646  */
    {					
					Symbol_Table* sym_table = new Symbol_Table();					
					if(scope==1)
					{
						scope=0;
						sym_table->set_table_scope(global);
						//printf("scope = 1\n");
					}
					else
					{
						sym_table->set_table_scope(local);
						//printf("scope = 1\n");
					}
					(yyval.symbol_table) = sym_table;
					
				}
#line 1380 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 117 "parser.y" /* yacc.c:1646  */
    {
					(yyval.symbol_table) = (yyvsp[-1].symbol_table);
					list<Symbol_Table_Entry *> ::iterator ls;					
					if((yyval.symbol_table)->get_table_scope() == global)
					{
						for(ls = (yyvsp[0].sym_entry_list)->begin(); ls != (yyvsp[0].sym_entry_list)->end(); ++ls)
						{
							if((yyval.symbol_table)->variable_in_symbol_list_check((*ls)->get_variable_name()))
							{
								yyerror(YY_("varibale " + (*ls)->get_variable_name() + " is defined twice" ));
							}
							(*ls)->set_symbol_scope(global);
							(yyval.symbol_table)->push_symbol(*ls);
							gst.push_symbol(*ls);
						}
					}
					else
					{
						for(ls = (yyvsp[0].sym_entry_list)->begin(); ls != (yyvsp[0].sym_entry_list)->end(); ++ls)
						{
							if((yyval.symbol_table)->variable_in_symbol_list_check((*ls)->get_variable_name()))
							{
								yyerror(YY_("varibale " + (*ls)->get_variable_name() + " is defined twice" ));
							}							
							(*ls)->set_symbol_scope(local);
							(yyval.symbol_table)->push_symbol(*ls);
							lst.push_symbol(*ls);
						}
					}	
				}
#line 1415 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 150 "parser.y" /* yacc.c:1646  */
    {				
					(yyval.sym_entry_list) = (yyvsp[-1].sym_entry_list);
				}
#line 1423 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 156 "parser.y" /* yacc.c:1646  */
    {
					list<Symbol_Table_Entry *> ::iterator ls;
					for(ls = (yyvsp[0].sym_entry_list)->begin(); ls != (yyvsp[0].sym_entry_list)->end(); ++ls)
					{
						(*ls)->set_data_type(int_data_type);
					}
					(yyval.sym_entry_list) = (yyvsp[0].sym_entry_list);
				}
#line 1436 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 165 "parser.y" /* yacc.c:1646  */
    {
					list<Symbol_Table_Entry *> ::iterator ls;
					for(ls = (yyvsp[0].sym_entry_list)->begin(); ls != (yyvsp[0].sym_entry_list)->end(); ++ls)
					{
						(*ls)->set_data_type(double_data_type);
					}
					(yyval.sym_entry_list) = (yyvsp[0].sym_entry_list);
				}
#line 1449 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 176 "parser.y" /* yacc.c:1646  */
    {
					list<Symbol_Table_Entry *> *l = new list<Symbol_Table_Entry *>();
					Symbol_Table_Entry* s = new Symbol_Table_Entry(*(yyvsp[0].sval),void_data_type,yylineno);
					l->push_back(s);
					(yyval.sym_entry_list) = l; 
				}
#line 1460 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 183 "parser.y" /* yacc.c:1646  */
    {
					Symbol_Table_Entry* s = new Symbol_Table_Entry(*(yyvsp[0].sval),void_data_type,yylineno);
					(yyval.sym_entry_list) = (yyvsp[-2].sym_entry_list);
					(yyval.sym_entry_list)->push_back(s);
				}
#line 1470 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 191 "parser.y" /* yacc.c:1646  */
    {
					list<Ast *> * astl = new list<Ast *>();
					(yyval.ast_list) = astl;	
				}
#line 1479 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 197 "parser.y" /* yacc.c:1646  */
    {
					//$<ast>2->print(std::cout);				
					(yyval.ast_list) = (yyvsp[-1].ast_list);
					(yyval.ast_list)->push_back((yyvsp[0].ast));
				}
#line 1489 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 205 "parser.y" /* yacc.c:1646  */
    {
					Sequence_Ast* S = new Sequence_Ast(yylineno);
					(yyval.sast) = S;
					(yyval.sast)->ast_push_back((yyvsp[0].ast));
				}
#line 1499 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 212 "parser.y" /* yacc.c:1646  */
    {
					//$<ast>2->print(std::cout);				
					(yyval.sast) = (yyvsp[-1].sast);
					(yyval.sast)->ast_push_back((yyvsp[0].ast));
				}
#line 1509 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 220 "parser.y" /* yacc.c:1646  */
    {
					(yyval.ast) = (yyvsp[0].ast);
				}
#line 1517 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 224 "parser.y" /* yacc.c:1646  */
    {
					(yyval.ast) = (yyvsp[0].ast);
				}
#line 1525 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 228 "parser.y" /* yacc.c:1646  */
    {
					(yyval.ast) = (yyvsp[0].ast);
				}
#line 1533 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 232 "parser.y" /* yacc.c:1646  */
    {
					(yyval.ast) = (yyvsp[0].ast);
				}
#line 1541 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 236 "parser.y" /* yacc.c:1646  */
    {
					(yyval.ast) = (yyvsp[-1].ast);
				}
#line 1549 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 243 "parser.y" /* yacc.c:1646  */
    {
					Name_Ast* nast;				
					
					if(lst.variable_in_symbol_list_check(*(yyvsp[-3].sval)))
					{
						nast = new Name_Ast(*(yyvsp[-3].sval),lst.get_symbol_table_entry(*(yyvsp[-3].sval)),yylineno) ;
						nast->set_data_type(lst.get_symbol_table_entry(*(yyvsp[-3].sval)).get_data_type());					
					}
					else if(gst.variable_in_symbol_list_check(*(yyvsp[-3].sval)))
					{
						nast = new Name_Ast(*(yyvsp[-3].sval),gst.get_symbol_table_entry(*(yyvsp[-3].sval)),yylineno) ;
						nast->set_data_type(gst.get_symbol_table_entry(*(yyvsp[-3].sval)).get_data_type());
					}
					else
					{
						yyerror(YY_("variable " + *(yyvsp[-3].sval) +" not declared"));
					}						
					Assignment_Ast* pls = new Assignment_Ast(nast,(yyvsp[-1].ast),yylineno);
					(yyval.ast) = pls;
					(yyval.ast)->check_ast();					
				}
#line 1575 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 268 "parser.y" /* yacc.c:1646  */
    {
				Logical_Expr_Ast* L = new Logical_Expr_Ast((yyvsp[-2].ast),_logical_or,(yyvsp[0].ast),yylineno);
				(yyval.ast) = L;
			}
#line 1584 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 273 "parser.y" /* yacc.c:1646  */
    {
				(yyval.ast) = (yyvsp[0].ast);
			}
#line 1592 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 277 "parser.y" /* yacc.c:1646  */
    {
				Logical_Expr_Ast* L = new Logical_Expr_Ast((yyvsp[-2].ast),_logical_and,(yyvsp[0].ast),yylineno);
				(yyval.ast) = L;
			}
#line 1601 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 282 "parser.y" /* yacc.c:1646  */
    {
				(yyval.ast) = (yyvsp[0].ast);
			}
#line 1609 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 286 "parser.y" /* yacc.c:1646  */
    {
				Logical_Expr_Ast* L = new Logical_Expr_Ast(NULL,_logical_not,(yyvsp[0].ast),yylineno);
				(yyval.ast) = L;
			}
#line 1618 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 292 "parser.y" /* yacc.c:1646  */
    {
				(yyval.ast) = (yyvsp[0].ast);
			}
#line 1626 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 297 "parser.y" /* yacc.c:1646  */
    {
				(yyval.ast) = (yyvsp[0].ast);
			}
#line 1634 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 301 "parser.y" /* yacc.c:1646  */
    {
				(yyval.ast) = (yyvsp[-1].ast);
			}
#line 1642 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 306 "parser.y" /* yacc.c:1646  */
    {
					Relational_Expr_Ast* R = new Relational_Expr_Ast((yyvsp[-2].ast),less_than,(yyvsp[0].ast),yylineno);
					(yyval.ast) = R;
					(yyval.ast)->check_ast();
				}
#line 1652 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 312 "parser.y" /* yacc.c:1646  */
    {
					Relational_Expr_Ast* R = new Relational_Expr_Ast((yyvsp[-2].ast),less_equalto,(yyvsp[0].ast),yylineno);
					(yyval.ast) = R;
					(yyval.ast)->check_ast();
				}
#line 1662 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 318 "parser.y" /* yacc.c:1646  */
    {
					Relational_Expr_Ast* R = new Relational_Expr_Ast((yyvsp[-2].ast),greater_than,(yyvsp[0].ast),yylineno);
					(yyval.ast) = R;
					(yyval.ast)->check_ast();
				}
#line 1672 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 324 "parser.y" /* yacc.c:1646  */
    {
					Relational_Expr_Ast* R = new Relational_Expr_Ast((yyvsp[-2].ast),greater_equalto,(yyvsp[0].ast),yylineno);
					(yyval.ast) = R;
					(yyval.ast)->check_ast();
				}
#line 1682 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 330 "parser.y" /* yacc.c:1646  */
    {
					Relational_Expr_Ast* R = new Relational_Expr_Ast((yyvsp[-2].ast),equalto,(yyvsp[0].ast),yylineno);
					(yyval.ast) = R;
					(yyval.ast)->check_ast();
				}
#line 1692 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 336 "parser.y" /* yacc.c:1646  */
    {
					Relational_Expr_Ast* R = new Relational_Expr_Ast((yyvsp[-2].ast),not_equalto,(yyvsp[0].ast),yylineno);
					(yyval.ast) = R;
					(yyval.ast)->check_ast();
				}
#line 1702 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 343 "parser.y" /* yacc.c:1646  */
    {
					(yyval.ast) = (yyvsp[0].ast);
				}
#line 1710 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 347 "parser.y" /* yacc.c:1646  */
    {
					(yyval.ast) = (yyvsp[0].ast);
				}
#line 1718 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 353 "parser.y" /* yacc.c:1646  */
    {
					Selection_Statement_Ast* S = new Selection_Statement_Ast((yyvsp[-4].ast),(yyvsp[-2].ast),(yyvsp[0].ast),yylineno);
					(yyval.ast) = S;						
				}
#line 1727 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 358 "parser.y" /* yacc.c:1646  */
    {
					Selection_Statement_Ast* S = new Selection_Statement_Ast((yyvsp[-4].ast),(yyvsp[-2].ast),(yyvsp[0].ast),yylineno);
					(yyval.ast) = S;						
				}
#line 1736 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 365 "parser.y" /* yacc.c:1646  */
    {
					Selection_Statement_Ast* S = new Selection_Statement_Ast((yyvsp[-2].ast),(yyvsp[0].ast),NULL,yylineno);
					(yyval.ast) = S;						
				}
#line 1745 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 370 "parser.y" /* yacc.c:1646  */
    {
					Selection_Statement_Ast* S = new Selection_Statement_Ast((yyvsp[-4].ast),(yyvsp[-2].ast),(yyvsp[0].ast),yylineno);
					(yyval.ast) = S;						
				}
#line 1754 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 375 "parser.y" /* yacc.c:1646  */
    {
					Selection_Statement_Ast* S = new Selection_Statement_Ast((yyvsp[-2].ast),(yyvsp[0].ast),NULL,yylineno);
					(yyval.ast) = S;					
				}
#line 1763 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 382 "parser.y" /* yacc.c:1646  */
    {
					(yyval.ast) = (yyvsp[0].ast);
				}
#line 1771 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 386 "parser.y" /* yacc.c:1646  */
    {
					(yyval.ast) = (yyvsp[-1].ast);
				}
#line 1779 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 390 "parser.y" /* yacc.c:1646  */
    {
					(yyval.ast) = (yyvsp[0].ast);
				}
#line 1787 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 394 "parser.y" /* yacc.c:1646  */
    {
					(yyval.ast) = (yyvsp[0].ast);
				}
#line 1795 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 400 "parser.y" /* yacc.c:1646  */
    {
					Iteration_Statement_Ast* I = new Iteration_Statement_Ast((yyvsp[-2].ast),(yyvsp[0].ast),yylineno,0);
					(yyval.ast) = I; 
				}
#line 1804 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 407 "parser.y" /* yacc.c:1646  */
    {
					Iteration_Statement_Ast* I = new Iteration_Statement_Ast((yyvsp[-2].ast),(yyvsp[-5].ast),yylineno,1);
					(yyval.ast) = I; 
				}
#line 1813 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 414 "parser.y" /* yacc.c:1646  */
    {
					Conditional_Expression_Ast* C = new Conditional_Expression_Ast((yyvsp[-4].ast),(yyvsp[-2].ast),(yyvsp[0].ast),yylineno);
					(yyval.ast) = C;
					(yyval.ast)->check_ast(); 					
				}
#line 1823 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 420 "parser.y" /* yacc.c:1646  */
    {
					(yyval.ast) = (yyvsp[0].ast);
				}
#line 1831 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 427 "parser.y" /* yacc.c:1646  */
    {
					//printf("%d\n",$1);					
					Number_Ast<int>* num = new Number_Ast<int>((yyvsp[0].ival), int_data_type, yylineno);
					num->set_data_type(int_data_type);
					(yyval.ast) = num;
					//num->print(std::cout);
				}
#line 1843 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 436 "parser.y" /* yacc.c:1646  */
    {
					Number_Ast<double>* num = new Number_Ast<double>((yyvsp[0].fval), double_data_type, yylineno);
					num->set_data_type(double_data_type);
					(yyval.ast) = num;
				}
#line 1853 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 443 "parser.y" /* yacc.c:1646  */
    {
					Name_Ast* nast;				
					if(lst.variable_in_symbol_list_check(*(yyvsp[0].sval)))
					{
						nast = new Name_Ast(*(yyvsp[0].sval),lst.get_symbol_table_entry(*(yyvsp[0].sval)),yylineno) ;
						nast->set_data_type(lst.get_symbol_table_entry(*(yyvsp[0].sval)).get_data_type());					
					}
					else if(gst.variable_in_symbol_list_check(*(yyvsp[0].sval)))
					{
						nast = new Name_Ast(*(yyvsp[0].sval),gst.get_symbol_table_entry(*(yyvsp[0].sval)),yylineno) ;
						nast->set_data_type(gst.get_symbol_table_entry(*(yyvsp[0].sval)).get_data_type());
					}
					else
					{
						yyerror(YY_("variable " + *(yyvsp[0].sval) +" not declared"));
					}				
					(yyval.ast) = nast;
					
				}
#line 1877 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 463 "parser.y" /* yacc.c:1646  */
    {
					Plus_Ast* pls = new Plus_Ast((yyvsp[-2].ast),(yyvsp[0].ast),yylineno);
					(yyval.ast) = pls;
					(yyval.ast)->check_ast();					
				}
#line 1887 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 469 "parser.y" /* yacc.c:1646  */
    {
					Minus_Ast* pls = new Minus_Ast((yyvsp[-2].ast),(yyvsp[0].ast),yylineno);
					(yyval.ast) = pls;
					(yyval.ast)->check_ast();
				}
#line 1897 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 475 "parser.y" /* yacc.c:1646  */
    {
					Mult_Ast* pls = new Mult_Ast((yyvsp[-2].ast),(yyvsp[0].ast),yylineno);
					(yyval.ast) = pls;
					(yyval.ast)->check_ast();
				}
#line 1907 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 481 "parser.y" /* yacc.c:1646  */
    {
					Divide_Ast* pls = new Divide_Ast((yyvsp[-2].ast),(yyvsp[0].ast),yylineno);
					(yyval.ast) = pls;
					(yyval.ast)->check_ast();
				}
#line 1917 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 487 "parser.y" /* yacc.c:1646  */
    {
					UMinus_Ast* pls = new UMinus_Ast((yyvsp[0].ast),NULL,yylineno);
					(yyval.ast) = pls;
					(yyval.ast)->check_ast();
				}
#line 1927 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 493 "parser.y" /* yacc.c:1646  */
    {
					(yyval.ast) = (yyvsp[-1].ast);
				}
#line 1935 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1939 "parser.tab.c" /* yacc.c:1646  */
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
#line 497 "parser.y" /* yacc.c:1906  */

void yyerror(string s) {
	cout<<"cs316: Error in line "<<yylineno<<": "<<s<<"\n";
	exit(0);
}
