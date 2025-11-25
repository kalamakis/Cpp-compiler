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
#line 1 "syntax.y" /* yacc.c:339  */

    #include <stdio.h>
    #include <stdlib.h>

    #include "settings.h"
    #include "types.h"
    #include "symbolTable.h" 
    #include "semantics.h"

    #define YYERROR_BUFFER_SIZE 256
    #define YYERROR_FMT(...)                                      \
    do {                                                      \
        char _yyerrbuf[YYERROR_BUFFER_SIZE];                  \
        snprintf(_yyerrbuf, sizeof(_yyerrbuf), __VA_ARGS__);  \
        yyerror(_yyerrbuf);                                   \
    } while (0)

    extern FILE *yyin;
    extern int yylex();
    extern int yylineno;
    void yyerror(const char *s);
    int yyerrorno = 0;

    static Type *current_type = NULL;
    

#line 93 "syntax.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "syntax.tab.h".  */
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
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
    T_EOF = 0,
    T_TYPEDEF = 258,
    T_CHAR = 259,
    T_INT = 260,
    T_FLOAT = 261,
    T_STRING = 262,
    T_CONST = 263,
    T_CLASS = 264,
    T_PRIVATE = 265,
    T_PROTECTED = 266,
    T_PUBLIC = 267,
    T_VOID = 268,
    T_STATIC = 269,
    T_UNION = 270,
    T_ENUM = 271,
    T_LIST = 272,
    T_CONTINUE = 273,
    T_BREAK = 274,
    T_IF = 275,
    T_ELSE = 276,
    T_WHILE = 277,
    T_FOR = 278,
    T_RETURN = 279,
    T_LENGTH = 280,
    T_CIN = 281,
    T_COUT = 282,
    T_MAIN = 283,
    T_THIS = 284,
    T_ID = 285,
    T_NUM = 286,
    T_ICONST = 287,
    T_UNKNOWN = 288,
    T_FCONST = 289,
    T_SCONST = 290,
    T_CCONST = 291,
    T_OROP = 292,
    T_ANDOP = 293,
    T_EQUOP = 294,
    T_RELOP = 295,
    T_ADDOP = 296,
    T_MULOP = 297,
    T_NOTOP = 298,
    T_INCDEC = 299,
    T_SIZEOP = 300,
    T_LISTFUNC = 301,
    T_LPAREN = 302,
    T_RPAREN = 303,
    T_SEMI = 304,
    T_DOT = 305,
    T_COMMA = 306,
    T_ASSIGN = 307,
    T_COLON = 308,
    T_LBRACK = 309,
    T_RBRACK = 310,
    T_REFER = 311,
    T_LBRACE = 312,
    T_RBRACE = 313,
    T_METH = 314,
    T_INP = 315,
    T_OUT = 316,
    T_ERROR = 317,
    PREFIX = 318,
    POSTFIX = 319,
    LOWER_THAN_ELSE = 320
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 30 "syntax.y" /* yacc.c:355  */

    int   intval;
    float floatval;
    char *strval;
    char  charval;
    Type *type;

#line 208 "syntax.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 225 "syntax.tab.c" /* yacc.c:358  */

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
#define YYLAST   646

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  85
/* YYNRULES -- Number of rules.  */
#define YYNRULES  178
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  343

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   320

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   129,   129,   131,   132,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   144,   151,   152,   161,   162,   163,
     164,   165,   167,   167,   169,   170,   172,   173,   175,   175,
     177,   178,   180,   186,   187,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   208,   209,   210,   211,   212,   214,   215,
     217,   218,   220,   221,   223,   224,   225,   226,   229,   231,
     232,   234,   240,   241,   246,   251,   252,   254,   260,   260,
     261,   266,   268,   269,   271,   271,   271,   271,   272,   273,
     275,   276,   279,   283,   284,   287,   300,   302,   302,   304,
     305,   307,   309,   311,   312,   315,   318,   326,   327,   329,
     330,   332,   334,   341,   345,   346,   348,   350,   351,   353,
     354,   355,   357,   358,   360,   367,   373,   374,   376,   377,
     383,   385,   386,   387,   388,   390,   390,   391,   391,   393,
     393,   394,   395,   396,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   409,   410,   411,   412,   414,   415,
     416,   417,   419,   420,   421,   423,   424,   426,   427,   428,
     430,   431,   431,   432,   433,   434,   435,   436,   437
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"eof\"", "error", "$undefined", "\"typedef\"", "\"char\"", "\"int\"",
  "\"float\"", "\"string\"", "\"const\"", "\"class\"", "\"private\"",
  "\"protected\"", "\"public\"", "\"void\"", "\"static\"", "\"union\"",
  "\"enum\"", "\"list\"", "\"continue\"", "\"break\"", "\"if\"",
  "\"else\"", "\"while\"", "\"for\"", "\"return\"", "\"length\"",
  "\"cin\"", "\"cout\"", "\"main\"", "\"this\"", "\"id\"", "\"num\"",
  "\"iconst\"", "\"unknown\"", "\"fconst\"", "\"sconst\"", "\"cconst\"",
  "\"orop\"", "\"andop\"", "\"equop\"", "\"relop\"", "\"addop\"",
  "\"mulop\"", "\"notop\"", "\"incdec\"", "\"sizeop\"", "\"listfunc\"",
  "\"lparen\"", "\"rparen\"", "\"semi\"", "\"dot\"", "\"comma\"",
  "\"assign\"", "\"colon\"", "\"lbrack\"", "\"rbrack\"", "\"refer\"",
  "\"lbrace\"", "\"rbrace\"", "\"meth\"", "\"inp\"", "\"out\"",
  "\"error\"", "PREFIX", "POSTFIX", "LOWER_THAN_ELSE", "$accept",
  "program", "global_declarations", "global_declaration",
  "typedef_declaration", "typename", "standard_type", "listspec", "dims",
  "dim", "const_declaration", "$@1", "constdefs", "constdef", "init_value",
  "expression", "variable", "general_expression", "assignment",
  "expression_list", "constant", "listexpression", "init_values",
  "enum_declaration", "enum_body", "id_list", "initializer",
  "class_declaration", "class_body", "$@2", "parent", "members_methods",
  "access", "member_or_method", "member", "var_declaration",
  "variabledefs", "variabledef", "anonymous_union", "union_body", "$@3",
  "fields", "field", "method", "short_func_declaration",
  "short_par_func_header", "func_header_start", "parameter_types",
  "pass_list_dims", "nopar_func_header", "union_declaration",
  "global_var_declaration", "init_variabledefs", "init_variabledef",
  "func_declaration", "full_func_declaration", "full_par_func_header",
  "class_func_header_start", "func_class", "parameter_list",
  "pass_variabledef", "nopar_class_func_header", "decl_statements",
  "declarations", "$@4", "$@5", "decltype", "statements", "statement",
  "expression_statement", "if_statement", "if_tail", "while_statement",
  "for_statement", "optexpr", "return_statement", "io_statement",
  "in_list", "in_item", "out_list", "out_item", "comp_statement", "$@6",
  "main_function", "main_header", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320
};
# endif

#define YYPACT_NINF -228

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-228)))

#define YYTABLE_NINF -162

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -228,    76,   603,  -228,    20,   183,  -228,   150,  -228,  -228,
     183,    68,  -228,    80,    94,  -228,  -228,  -228,    89,  -228,
    -228,  -228,  -228,  -228,   105,   116,     3,  -228,  -228,  -228,
    -228,   129,   126,   135,  -228,   141,   154,  -228,  -228,  -228,
      89,   159,    14,  -228,   102,  -228,   148,  -228,   184,   169,
      83,  -228,  -228,    95,  -228,   373,   373,   131,   373,   373,
     190,   217,   204,   218,    25,   228,   252,   216,  -228,   230,
     223,   256,   238,    11,   258,   249,  -228,  -228,    89,  -228,
       0,    97,    98,  -228,   248,   262,   251,   254,   260,   481,
     271,   239,   244,  -228,  -228,  -228,  -228,  -228,   551,   551,
      36,   551,   276,   336,  -228,   504,  -228,   314,   106,    90,
    -228,  -228,  -228,   269,   414,   616,   210,  -228,  -228,  -228,
    -228,  -228,  -228,  -228,  -228,   272,  -228,    10,   117,   274,
     280,  -228,  -228,  -228,  -228,  -228,  -228,  -228,   108,  -228,
    -228,  -228,   288,  -228,   183,   169,    37,  -228,  -228,   275,
    -228,   249,  -228,   314,   127,   316,   327,  -228,   328,   327,
    -228,  -228,  -228,  -228,   183,  -228,   183,  -228,  -228,   551,
     551,   481,   308,   311,   551,    36,   551,   320,  -228,    53,
    -228,   551,   315,   121,   308,   309,   373,   551,   551,   551,
     551,   551,   551,  -228,   504,   337,   551,   551,  -228,   551,
    -228,   616,   290,    24,  -228,   317,  -228,  -228,   328,  -228,
    -228,  -228,    26,   158,  -228,   228,   250,    89,  -228,    29,
    -228,  -228,   339,  -228,    17,  -228,  -228,    46,  -228,  -228,
    -228,   275,    15,    10,   146,   152,   324,  -228,   168,    53,
      34,  -228,   308,    18,  -228,   175,  -228,  -228,  -228,   318,
     561,   231,   235,    74,   320,  -228,   326,  -228,  -228,     2,
    -228,  -228,    89,  -228,  -228,   249,  -228,   322,   325,   331,
      35,   178,   176,  -228,  -228,  -228,   169,   330,  -228,   249,
    -228,  -228,  -228,  -228,  -228,   455,   455,   481,  -228,  -228,
      36,  -228,   551,  -228,  -228,  -228,  -228,    89,   192,  -228,
    -228,  -228,  -228,  -228,   178,  -228,    89,  -228,  -228,  -228,
    -228,  -228,  -228,   341,   340,  -228,    89,  -228,  -228,  -228,
     365,  -228,   345,  -228,  -228,   199,  -228,  -228,   352,   374,
      95,  -228,   455,  -228,   527,  -228,  -228,   356,    15,  -228,
     358,   455,  -228
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,     0,     0,    17,     0,    19,    20,
       0,     0,    21,     0,     0,    16,     3,     5,    23,    15,
       6,     7,     8,   117,     0,     0,     0,     9,    10,    11,
     118,     0,     0,     0,     2,     0,     0,    12,    13,    18,
      23,     0,     0,    28,    81,    97,     0,    22,     0,    76,
       0,   115,   103,     0,   104,   140,   140,     0,   140,   140,
       0,     0,     0,     0,     0,     0,     0,     0,    78,     0,
       0,     0,     0,    25,     0,   140,   116,   113,    23,   111,
      23,     0,     0,   139,     0,     0,     0,     0,     0,   140,
       0,     0,     0,    57,    65,    66,    67,    64,   140,   140,
     140,   140,     0,   140,   153,    63,   171,    61,    46,     0,
      59,    49,    52,     0,   140,     0,     0,   142,   144,   145,
     146,   147,   148,   149,   150,     0,   130,    23,     0,     0,
       0,   175,    25,   176,   177,   178,   174,    25,     0,    31,
      80,    77,     0,   112,     0,    76,     0,    71,   125,    95,
     124,   140,    75,    33,    46,     0,     0,   114,   109,    25,
     128,   108,   127,   105,     0,   123,     0,   151,   152,   140,
     140,   140,   160,     0,   140,   140,   140,    42,    41,    44,
      43,   140,     0,     0,    62,     0,   140,   140,   140,   140,
     140,   140,   140,    45,    63,     0,   140,   140,   154,   140,
     121,     0,     0,    56,   137,     0,   141,   119,     0,   122,
     120,   173,     0,     0,    29,     0,    87,    23,   101,     0,
     100,    74,     0,    72,     0,    24,    70,     0,    56,    25,
     129,   110,    23,    23,     0,     0,     0,   162,     0,   167,
       0,   166,   170,     0,   169,     0,    51,    50,    68,     0,
      35,    36,    37,    38,    39,    40,     0,    54,    60,     0,
      58,   135,    23,   143,    14,   140,    30,     0,     0,     0,
      87,     0,     0,    94,    98,    99,    76,     0,    27,   140,
      34,   109,    25,   107,   126,   140,   140,   140,    48,   163,
     140,   164,   140,    55,   172,    47,    53,    23,     0,    32,
      84,    85,    86,    79,     0,    97,    23,    83,    88,    90,
      91,    89,   102,     0,     0,    92,    23,    73,    26,    69,
     157,   158,     0,   165,   168,     0,   138,    82,     0,     0,
       0,    93,   140,   155,   140,   136,    96,    25,    23,   156,
       0,   140,   159
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -228,  -228,  -228,  -228,  -228,    -2,   307,   -17,  -116,  -228,
    -228,  -228,  -228,   196,  -132,   -61,   -70,   -85,   219,   227,
    -228,  -228,  -228,  -228,  -228,  -228,  -134,  -228,  -228,  -228,
    -228,  -228,   142,   109,  -228,  -227,  -223,   -16,  -228,   118,
    -228,  -228,   205,  -228,   423,  -228,   424,  -228,   197,   433,
    -228,  -228,  -228,   364,  -228,  -228,  -228,  -228,  -228,   387,
     212,  -228,   -34,  -228,  -228,  -228,   -46,   333,  -110,  -228,
    -228,  -228,  -228,  -228,  -164,  -228,  -228,  -228,   161,  -228,
     160,  -228,  -228,  -228,  -228
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    16,    17,   217,    19,   156,   149,   225,
      20,    65,   138,   139,   152,   107,   108,   109,   110,   185,
     111,   112,   227,    21,    72,   146,    76,    22,    67,   142,
      68,   270,   271,   307,   308,   218,   272,   273,   310,    69,
      70,   219,   220,   311,   312,    24,   313,    81,   161,   314,
      27,    28,    50,    51,    29,    30,    31,    32,    74,    82,
     162,    33,   113,   114,   297,   262,   155,   116,   117,   118,
     119,   333,   120,   121,   173,   122,   123,   240,   241,   243,
     244,   124,   186,    34,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,    48,    49,    40,   172,   154,   206,   236,    43,   115,
     115,   221,   115,   115,   153,    63,   212,    47,   183,   226,
     184,   213,   125,    61,   129,   130,   135,    47,   154,   154,
     179,   154,    47,     6,    39,     8,     9,   177,   178,   298,
     180,   -16,    12,   231,   309,   267,   268,   269,    36,   277,
      83,    80,    54,   199,   -16,   127,   158,   296,  -106,    15,
      55,    64,    49,   159,   160,    93,   208,   291,   201,    37,
     148,   281,   278,   136,   325,   264,     3,   309,    38,   292,
     224,   154,   102,   289,   234,   235,   172,   274,   222,   238,
     153,   242,   206,   303,   290,   223,   245,   279,    44,     6,
      39,     8,     9,   195,   280,   239,    47,   197,    12,   184,
      45,   160,   259,   204,   260,   191,   192,   154,   154,   154,
     154,   154,   154,   322,    46,    15,   250,   251,   252,   253,
     254,   255,    77,   299,    78,     6,    39,     8,     9,   198,
     115,   199,   317,    79,    12,   163,   165,   319,   164,   166,
     193,    41,   249,   194,    52,    66,   195,   214,   196,   215,
     197,    15,   232,    53,   233,   209,   231,   -18,   166,   247,
     340,   193,   199,    57,   194,   320,   321,   195,    42,   126,
     -18,   197,     6,    39,     8,     9,    56,     6,    39,     8,
       9,    12,    58,   305,   285,   154,    12,   199,    59,   261,
     286,    60,   172,   199,   153,    71,    62,   242,    15,   154,
     265,   205,   224,    15,    73,   282,   288,   160,   153,   199,
     239,    75,   339,   293,    83,   315,   199,   316,    84,    85,
      86,   342,    87,    88,    89,    90,    91,    92,   131,    93,
    -140,   326,    94,   316,    95,    96,    97,   132,   335,   172,
     316,    98,   133,    99,   100,   101,   102,   103,   137,   104,
     267,   268,   269,    83,   105,   141,   134,   106,  -133,   306,
     189,   190,   191,   192,    90,   190,   191,   192,    93,   143,
     144,    94,   140,    95,    96,    97,   145,   147,   150,   329,
      98,   205,    99,   100,   101,   102,   103,   167,   169,   175,
     331,   170,   306,   105,    83,   176,   151,   171,    84,    85,
      86,   168,    87,    88,    89,    90,    91,    92,   174,    93,
    -140,   282,    94,   181,    95,    96,    97,   200,   338,   224,
     207,    98,   210,    99,   100,   101,   102,   103,   211,   104,
       6,    39,     8,     9,   105,   216,   228,   106,  -131,    12,
      83,   187,   188,   189,   190,   191,   192,   229,   230,   199,
     237,    90,   192,   246,   248,    93,   263,   257,    94,   276,
      95,    96,    97,   287,   295,   300,   294,    98,   301,    99,
     100,   101,   102,   103,   302,   318,   332,    83,   330,    54,
     105,    84,    85,    86,   334,    87,    88,    89,    90,    91,
      92,   336,    93,  -106,   337,    94,   341,    95,    96,    97,
     182,   266,   304,   327,    98,   258,    99,   100,   101,   102,
     103,   256,   104,   328,   275,    23,    25,   105,    83,   283,
     106,  -134,    84,    85,    86,    26,    87,    88,    89,    90,
      91,    92,   157,    93,   128,   284,    94,   202,    95,    96,
      97,   323,   324,     0,     0,    98,     0,    99,   100,   101,
     102,   103,     0,   104,     0,     0,     0,     0,   105,    83,
       0,   106,  -132,    84,    85,    86,     0,    87,    88,    89,
      90,    91,    92,     0,    93,     0,     0,    94,     0,    95,
      96,    97,     0,     0,     0,    83,    98,     0,    99,   100,
     101,   102,   103,     0,   104,     0,    90,     0,     0,   105,
      93,     0,   106,    94,     0,    95,    96,    97,    83,     0,
       0,     0,    98,     0,    99,   100,   101,   102,   103,    90,
    -161,     0,     0,    93,  -140,   105,    94,     0,    95,    96,
      97,    83,     0,     0,     0,    98,     0,    99,   100,   101,
     102,   103,    90,     0,     0,     0,    93,     0,   105,    94,
       0,    95,    96,    97,     0,    83,     0,     0,    98,     0,
      99,   100,   101,   102,   103,  -161,    90,     0,     0,     0,
      93,   105,     0,    94,     0,    95,    96,    97,     0,     0,
       0,     0,    98,     0,    99,   100,   101,   102,   103,   188,
     189,   190,   191,   192,     4,   105,     5,     6,     7,     8,
       9,    10,    11,     0,     0,     0,    12,     0,    13,    14,
       6,    39,     8,     9,     0,     0,     0,     0,     0,    12,
       0,     0,     0,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   203
};

static const yytype_int16 yycheck[] =
{
       2,    18,    18,     5,    89,    75,   116,   171,    10,    55,
      56,   145,    58,    59,    75,     1,   132,    17,   103,   151,
     105,   137,    56,    40,    58,    59,     1,    17,    98,    99,
     100,   101,    17,     4,     5,     6,     7,    98,    99,   262,
     101,    17,    13,   159,   271,    10,    11,    12,    28,    32,
      14,    53,    49,    51,    30,    57,    56,    55,    47,    30,
      57,    47,    78,    80,    80,    29,    56,    49,   114,    49,
      59,    56,    55,    48,   297,    49,     0,   304,    58,    61,
      54,   151,    46,    49,   169,   170,   171,    58,    51,   174,
     151,   176,   202,    58,    60,    58,   181,    51,    30,     4,
       5,     6,     7,    50,    58,   175,    17,    54,    13,   194,
      30,   127,   197,   115,   199,    41,    42,   187,   188,   189,
     190,   191,   192,   287,    30,    30,   187,   188,   189,   190,
     191,   192,    49,   265,    51,     4,     5,     6,     7,    49,
     186,    51,   276,    48,    13,    48,    48,   279,    51,    51,
      44,     1,   186,    47,    49,    53,    50,    49,    52,    51,
      54,    30,   164,    47,   166,    48,   282,    17,    51,    48,
     334,    44,    51,    47,    47,   285,   286,    50,    28,    48,
      30,    54,     4,     5,     6,     7,    57,     4,     5,     6,
       7,    13,    57,    15,    48,   265,    13,    51,    57,   201,
      48,    47,   287,    51,   265,    57,    47,   292,    30,   279,
      52,     1,    54,    30,    30,   232,    48,   233,   279,    51,
     290,    52,   332,    48,    14,    49,    51,    51,    18,    19,
      20,   341,    22,    23,    24,    25,    26,    27,    48,    29,
      30,    49,    32,    51,    34,    35,    36,    30,    49,   334,
      51,    41,    48,    43,    44,    45,    46,    47,    30,    49,
      10,    11,    12,    14,    54,    49,    48,    57,    58,   271,
      39,    40,    41,    42,    25,    40,    41,    42,    29,    49,
      57,    32,    30,    34,    35,    36,    30,    49,    30,   306,
      41,     1,    43,    44,    45,    46,    47,    49,    47,    60,
     316,    47,   304,    54,    14,    61,    57,    47,    18,    19,
      20,    49,    22,    23,    24,    25,    26,    27,    47,    29,
      30,   338,    32,    47,    34,    35,    36,    58,   330,    54,
      58,    41,    58,    43,    44,    45,    46,    47,    58,    49,
       4,     5,     6,     7,    54,    57,    30,    57,    58,    13,
      14,    37,    38,    39,    40,    41,    42,    30,    30,    51,
      49,    25,    42,    48,    55,    29,    49,    30,    32,    30,
      34,    35,    36,    49,    48,    53,    58,    41,    53,    43,
      44,    45,    46,    47,    53,    55,    21,    14,    47,    49,
      54,    18,    19,    20,    49,    22,    23,    24,    25,    26,
      27,    49,    29,    47,    30,    32,    48,    34,    35,    36,
     103,   215,   270,   304,    41,   196,    43,    44,    45,    46,
      47,   194,    49,   305,   219,     2,     2,    54,    14,   232,
      57,    58,    18,    19,    20,     2,    22,    23,    24,    25,
      26,    27,    78,    29,    57,   233,    32,   114,    34,    35,
      36,   290,   292,    -1,    -1,    41,    -1,    43,    44,    45,
      46,    47,    -1,    49,    -1,    -1,    -1,    -1,    54,    14,
      -1,    57,    58,    18,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    29,    -1,    -1,    32,    -1,    34,
      35,    36,    -1,    -1,    -1,    14,    41,    -1,    43,    44,
      45,    46,    47,    -1,    49,    -1,    25,    -1,    -1,    54,
      29,    -1,    57,    32,    -1,    34,    35,    36,    14,    -1,
      -1,    -1,    41,    -1,    43,    44,    45,    46,    47,    25,
      49,    -1,    -1,    29,    30,    54,    32,    -1,    34,    35,
      36,    14,    -1,    -1,    -1,    41,    -1,    43,    44,    45,
      46,    47,    25,    -1,    -1,    -1,    29,    -1,    54,    32,
      -1,    34,    35,    36,    -1,    14,    -1,    -1,    41,    -1,
      43,    44,    45,    46,    47,    48,    25,    -1,    -1,    -1,
      29,    54,    -1,    32,    -1,    34,    35,    36,    -1,    -1,
      -1,    -1,    41,    -1,    43,    44,    45,    46,    47,    38,
      39,    40,    41,    42,     1,    54,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    13,    -1,    15,    16,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    67,    68,     0,     1,     3,     4,     5,     6,     7,
       8,     9,    13,    15,    16,    30,    69,    70,    71,    72,
      76,    89,    93,   110,   111,   112,   115,   116,   117,   120,
     121,   122,   123,   127,   149,   150,    28,    49,    58,     5,
      71,     1,    28,    71,    30,    30,    30,    17,    73,   103,
     118,   119,    49,    47,    49,    57,    57,    47,    57,    57,
      47,    73,    47,     1,    47,    77,    53,    94,    96,   105,
     106,    57,    90,    30,   124,    52,    92,    49,    51,    48,
      71,   113,   125,    14,    18,    19,    20,    22,    23,    24,
      25,    26,    27,    29,    32,    34,    35,    36,    41,    43,
      44,    45,    46,    47,    49,    54,    57,    81,    82,    83,
      84,    86,    87,   128,   129,   132,   133,   134,   135,   136,
     138,   139,   141,   142,   147,   128,    48,    71,   125,   128,
     128,    48,    30,    48,    48,     1,    48,    30,    78,    79,
      30,    49,    95,    49,    57,    30,    91,    49,    59,    74,
      30,    57,    80,    81,    82,   132,    73,   119,    56,    73,
     103,   114,   126,    48,    51,    48,    51,    49,    49,    47,
      47,    47,    83,   140,    47,    60,    61,    81,    81,    82,
      81,    47,    72,    83,    83,    85,   148,    37,    38,    39,
      40,    41,    42,    44,    47,    50,    52,    54,    49,    51,
      58,   132,   133,    30,    71,     1,   134,    58,    56,    48,
      58,    58,    74,    74,    49,    51,    57,    71,   101,   107,
     108,    92,    51,    58,    54,    75,    80,    88,    30,    30,
      30,    74,    71,    71,    83,    83,   140,    49,    83,    82,
     143,   144,    83,   145,   146,    83,    48,    48,    55,   128,
      81,    81,    81,    81,    81,    81,    85,    30,    84,    83,
      83,    71,   131,    49,    49,    52,    79,    10,    11,    12,
      97,    98,   102,   103,    58,   108,    30,    32,    55,    51,
      58,    56,    73,   114,   126,    48,    48,    49,    48,    49,
      60,    49,    61,    48,    58,    48,    55,   130,   102,    80,
      53,    53,    53,    58,    98,    15,    71,    99,   100,   101,
     104,   109,   110,   112,   115,    49,    51,    92,    55,    80,
     134,   134,   140,   144,   146,   102,    49,    99,   105,    73,
      47,   103,    21,   137,    49,    49,    49,    30,    71,   134,
     140,    48,   134
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    68,    68,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    70,    71,    71,    72,    72,    72,
      72,    72,    73,    73,    74,    74,    75,    75,    77,    76,
      78,    78,    79,    80,    80,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    82,    82,    82,    82,    82,    83,    83,
      84,    84,    85,    85,    86,    86,    86,    86,    87,    88,
      88,    89,    90,    91,    91,    92,    92,    93,    95,    94,
      96,    96,    97,    97,    98,    98,    98,    98,    99,    99,
     100,   100,   101,   102,   102,   103,   104,   106,   105,   107,
     107,   108,   109,   110,   110,   111,   112,   113,   113,   114,
     114,   115,   116,   117,   118,   118,   119,   120,   120,   121,
     121,   121,   122,   122,   123,   124,   125,   125,   126,   126,
     127,   128,   128,   128,   128,   130,   129,   131,   129,   132,
     132,   133,   133,   133,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   135,   136,   137,   137,   138,   139,
     140,   140,   141,   142,   142,   143,   143,   144,   145,   145,
     146,   148,   147,   149,   150,   150,   150,   150,   150
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     6,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     2,     0,     3,     2,     0,     5,
       3,     1,     4,     1,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     2,     1,     4,     4,     1,
       3,     3,     1,     4,     3,     4,     2,     1,     3,     1,
       3,     1,     1,     0,     1,     1,     1,     1,     3,     3,
       1,     4,     3,     4,     2,     2,     0,     4,     0,     5,
       2,     0,     3,     2,     2,     2,     2,     0,     1,     1,
       1,     1,     3,     3,     1,     3,     3,     0,     4,     2,
       1,     1,     1,     2,     2,     4,     3,     4,     2,     1,
       2,     3,     4,     3,     3,     1,     2,     1,     1,     4,
       4,     4,     4,     4,     4,     2,     4,     2,     1,     2,
       3,     2,     1,     1,     0,     0,     6,     0,     5,     1,
       0,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     2,     6,     2,     0,     5,     9,
       1,     0,     3,     4,     4,     3,     1,     1,     3,     1,
       1,     0,     4,     4,     4,     4,     4,     4,     4
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
#line 132 "syntax.y" /* yacc.c:1646  */
    {;}
#line 1632 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 141 "syntax.y" /* yacc.c:1646  */
    {yyerror(" HINT: syntax error in global declaration\n"); yyerrok;}
#line 1638 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 142 "syntax.y" /* yacc.c:1646  */
    {yyerror(" HINT: in global declaration\n"); yyerrok; }
#line 1644 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 144 "syntax.y" /* yacc.c:1646  */
    {
                                                                                    /* αγνοούμε προς το παρόν listspec/dims για σύνθετους, κρατάμε base type */
                                                                                    if (!symtab_insert((yyvsp[-2].strval), SYM_TYPE, (yyvsp[-4].type))) {
                                                                                        YYERROR_FMT("Redeclaration of typedef '%s'", (yyvsp[-2].strval));
                                                                                    }
                                                                                }
#line 1655 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 152 "syntax.y" /* yacc.c:1646  */
    {Symbol *s = symtab_lookup((yyvsp[0].strval));
                                                                                    if (!s || s->kind != SYM_TYPE || !s->type) {
                                                                                        YYERROR_FMT("Unknown type '%s'", (yyvsp[0].strval));
                                                                                        (yyval.type) = type_error;
                                                                                    } else {
                                                                                        (yyval.type) = s->type;
                                                                                    }
                                                                                }
#line 1668 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 161 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = type_char;}
#line 1674 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 162 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = type_int;}
#line 1680 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 163 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = type_float;}
#line 1686 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 164 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = type_string;}
#line 1692 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 165 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = type_void;}
#line 1698 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 167 "syntax.y" /* yacc.c:1646  */
    {;}
#line 1704 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 169 "syntax.y" /* yacc.c:1646  */
    { (yyval.type) = attach_nested_array((yyvsp[-1].type), (yyvsp[0].type)); }
#line 1710 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 170 "syntax.y" /* yacc.c:1646  */
    { (yyval.type) = NULL; }
#line 1716 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 172 "syntax.y" /* yacc.c:1646  */
    { (yyval.type) = make_array_type(NULL, (yyvsp[-1].intval)); }
#line 1722 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 173 "syntax.y" /* yacc.c:1646  */
    { (yyval.type) = make_array_type(NULL, 0); }
#line 1728 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 175 "syntax.y" /* yacc.c:1646  */
    { current_type = (yyvsp[0].type); }
#line 1734 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 180 "syntax.y" /* yacc.c:1646  */
    {if (!current_type) current_type = type_error;
                                                                                    if (!symtab_insert((yyvsp[-3].strval), SYM_CONST, current_type)) {
                                                                                        YYERROR_FMT("Redeclaration of const '%s'", (yyvsp[-3].strval));
                                                                                    }
                                                                                }
#line 1744 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 189 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = sem_binary_logical((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1750 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 190 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = sem_binary_logical((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1756 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 191 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = sem_binary_equality((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1762 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 192 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = sem_binary_relational((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1768 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 193 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = sem_binary_arith((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1774 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 194 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = sem_binary_arith((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1780 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 195 "syntax.y" /* yacc.c:1646  */
    { (yyval.type) = sem_unary_not((yyvsp[0].type), yylineno); }
#line 1786 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 196 "syntax.y" /* yacc.c:1646  */
    { (yyval.type) = sem_unary_not((yyvsp[0].type), yylineno); }
#line 1792 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 197 "syntax.y" /* yacc.c:1646  */
    { (yyval.type) = type_int; }
#line 1798 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 198 "syntax.y" /* yacc.c:1646  */
    { (yyval.type) = sem_unary_incdec((yyvsp[0].type), yylineno); }
#line 1804 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 199 "syntax.y" /* yacc.c:1646  */
    { (yyval.type) = sem_unary_incdec((yyvsp[-1].type), yylineno); }
#line 1810 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 200 "syntax.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].type);}
#line 1816 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 201 "syntax.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[-3].type);}
#line 1822 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 202 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = type_int;}
#line 1828 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 203 "syntax.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].type);}
#line 1834 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 204 "syntax.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[-1].type);}
#line 1840 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 205 "syntax.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[-1].type);}
#line 1846 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 206 "syntax.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].type);}
#line 1852 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 208 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = sem_index((yyvsp[-3].type), (yyvsp[-1].type), yylineno);}
#line 1858 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 209 "syntax.y" /* yacc.c:1646  */
    {(yyval.type)= type_error;}
#line 1864 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 210 "syntax.y" /* yacc.c:1646  */
    {(yyval.type)= type_error;}
#line 1870 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 211 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = sem_use_variable((yyvsp[0].strval), yylineno); }
#line 1876 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 212 "syntax.y" /* yacc.c:1646  */
    {(yyval.type)= type_error;}
#line 1882 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 214 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = (yyvsp[0].type);}
#line 1888 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 215 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = (yyvsp[0].type);}
#line 1894 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 217 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = sem_check_assignment((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1900 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 218 "syntax.y" /* yacc.c:1646  */
    {(yyval.type)=type_error;}
#line 1906 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 220 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = (yyvsp[0].type);}
#line 1912 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 221 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = type_void;}
#line 1918 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 223 "syntax.y" /* yacc.c:1646  */
    { (yyval.type) = type_char;   }
#line 1924 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 224 "syntax.y" /* yacc.c:1646  */
    { (yyval.type) = type_int;    }
#line 1930 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 225 "syntax.y" /* yacc.c:1646  */
    { (yyval.type) = type_float;  }
#line 1936 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 226 "syntax.y" /* yacc.c:1646  */
    { (yyval.type) = type_string; }
#line 1942 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 229 "syntax.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[-1].type);}
#line 1948 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 234 "syntax.y" /* yacc.c:1646  */
    {Type *t = make_type(TYPE_ENUM);
                                                                                    if (!symtab_insert((yyvsp[-2].strval), SYM_TYPE, t)) {
                                                                                        YYERROR_FMT("Redeclaration of enum '%s'", (yyvsp[-2].strval));
                                                                                    }
                                                                                }
#line 1958 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 241 "syntax.y" /* yacc.c:1646  */
    {/* enum constants -> ακέραιοι */
                                                                                    if (!symtab_insert((yyvsp[-1].strval), SYM_ENUM_CONST, type_int)) {
                                                                                        YYERROR_FMT("Redeclaration of enum const '%s'", (yyvsp[-1].strval));
                                                                                    }
                                                                                }
#line 1968 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 246 "syntax.y" /* yacc.c:1646  */
    {if (!symtab_insert((yyvsp[-1].strval), SYM_ENUM_CONST, type_int)) {
                                                                                        YYERROR_FMT("Redeclaration of enum const '%s'", (yyvsp[-1].strval));
                                                                                    }
                                                                                }
#line 1977 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 252 "syntax.y" /* yacc.c:1646  */
    {;}
#line 1983 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 254 "syntax.y" /* yacc.c:1646  */
    {Type *t = make_type(TYPE_CLASS);
                                                                                    if (!symtab_insert((yyvsp[-2].strval), SYM_TYPE, t)) {
                                                                                        YYERROR_FMT("Redeclaration of class '%s'", (yyvsp[-2].strval));
                                                                                    }
                                                                                }
#line 1993 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 260 "syntax.y" /* yacc.c:1646  */
    {symtab_enter_scope();}
#line 1999 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 260 "syntax.y" /* yacc.c:1646  */
    { symtab_leave_scope();}
#line 2005 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 261 "syntax.y" /* yacc.c:1646  */
    {Symbol *base = symtab_lookup((yyvsp[0].strval));
                                                                                    if (!base || base->kind != SYM_TYPE) {
                                                                                        YYERROR_FMT("Unknown base class '%s'", (yyvsp[0].strval));
                                                                                    }
                                                                                }
#line 2015 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 266 "syntax.y" /* yacc.c:1646  */
    {;}
#line 2021 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 271 "syntax.y" /* yacc.c:1646  */
    { }
#line 2027 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 279 "syntax.y" /* yacc.c:1646  */
    { current_type = (yyvsp[-2].type); }
#line 2033 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 287 "syntax.y" /* yacc.c:1646  */
    {if (!current_type) current_type = type_error;
                                                                                    Type *final_type;
                                                                                    if ((yyvsp[0].type) == NULL)
                                                                                        final_type = current_type;
                                                                                    else
                                                                                        final_type = attach_array_to_base(current_type, (yyvsp[0].type));

                                                                                    if (!symtab_insert((yyvsp[-1].strval), SYM_VAR, final_type)) {
                                                                                        YYERROR_FMT("Redeclaration of '%s'", (yyvsp[-1].strval));
                                                                                    }
                                                                                }
#line 2049 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 302 "syntax.y" /* yacc.c:1646  */
    {symtab_enter_scope();}
#line 2055 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 302 "syntax.y" /* yacc.c:1646  */
    { symtab_leave_scope();}
#line 2061 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 311 "syntax.y" /* yacc.c:1646  */
    { symtab_leave_scope();}
#line 2067 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 312 "syntax.y" /* yacc.c:1646  */
    { symtab_leave_scope();}
#line 2073 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 318 "syntax.y" /* yacc.c:1646  */
    {Type *ret = (yyvsp[-2].type);
                                                                                    if (!symtab_insert((yyvsp[0].strval), SYM_FUNC, ret)) {
                                                                                        YYERROR_FMT("Redeclaration of function '%s'", (yyvsp[0].strval));
                                                                                    }
                                                                                    symtab_enter_scope();   /* νέο scope για παραμέτρους+σώμα */
                                                                                }
#line 2084 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 334 "syntax.y" /* yacc.c:1646  */
    {Type *t = make_type(TYPE_UNION);
                                                                                    if (!symtab_insert((yyvsp[-2].strval), SYM_TYPE, t)) {
                                                                                        YYERROR_FMT("Redeclaration of union '%s'", (yyvsp[-2].strval));
                                                                                    }
                                                                                }
#line 2094 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 341 "syntax.y" /* yacc.c:1646  */
    { current_type = (yyvsp[-2].type); }
#line 2100 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 353 "syntax.y" /* yacc.c:1646  */
    { symtab_leave_scope();}
#line 2106 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 354 "syntax.y" /* yacc.c:1646  */
    { symtab_leave_scope();}
#line 2112 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 355 "syntax.y" /* yacc.c:1646  */
    { symtab_leave_scope();}
#line 2118 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 360 "syntax.y" /* yacc.c:1646  */
    {Type *ret = (yyvsp[-3].type);
                                                                                    if (!symtab_insert((yyvsp[0].strval), SYM_FUNC, ret)) {
                                                                                        YYERROR_FMT("Redeclaration of method '%s'", (yyvsp[0].strval));
                                                                                    }
                                                                                    symtab_enter_scope();
                                                                                }
#line 2129 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 367 "syntax.y" /* yacc.c:1646  */
    {Symbol *cls = symtab_lookup((yyvsp[-1].strval));
                                                                                    if (!cls || cls->kind != SYM_TYPE) {
                                                                                        YYERROR_FMT("Unknown class type '%s'", (yyvsp[-1].strval));
                                                                                    }
                                                                                }
#line 2139 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 374 "syntax.y" /* yacc.c:1646  */
    { current_type = (yyvsp[-1].type); }
#line 2145 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 377 "syntax.y" /* yacc.c:1646  */
    {if (!current_type) current_type = type_error;
                                                                                    if (!symtab_insert((yyvsp[0].strval), SYM_VAR, current_type)) {
                                                                                        YYERROR_FMT("Redeclaration of parameter '%s'", (yyvsp[0].strval));
                                                                                    }
                                                                                }
#line 2155 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 388 "syntax.y" /* yacc.c:1646  */
    {;}
#line 2161 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 390 "syntax.y" /* yacc.c:1646  */
    { current_type = (yyvsp[0].type); }
#line 2167 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 391 "syntax.y" /* yacc.c:1646  */
    { current_type = (yyvsp[0].type); }
#line 2173 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 393 "syntax.y" /* yacc.c:1646  */
    {;}
#line 2179 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 396 "syntax.y" /* yacc.c:1646  */
    { YYERROR_FMT(" HINT:  error in statement - skipping until ';'"); yyerrok; }
#line 2185 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 412 "syntax.y" /* yacc.c:1646  */
    {;}
#line 2191 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 417 "syntax.y" /* yacc.c:1646  */
    {;}
#line 2197 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 431 "syntax.y" /* yacc.c:1646  */
    {symtab_enter_scope();}
#line 2203 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 431 "syntax.y" /* yacc.c:1646  */
    { symtab_leave_scope();}
#line 2209 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 432 "syntax.y" /* yacc.c:1646  */
    { symtab_leave_scope();}
#line 2215 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 433 "syntax.y" /* yacc.c:1646  */
    {symtab_enter_scope();}
#line 2221 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 434 "syntax.y" /* yacc.c:1646  */
    {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; symtab_enter_scope();}
#line 2227 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 435 "syntax.y" /* yacc.c:1646  */
    {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; symtab_enter_scope();}
#line 2233 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 436 "syntax.y" /* yacc.c:1646  */
    {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; symtab_enter_scope();}
#line 2239 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 437 "syntax.y" /* yacc.c:1646  */
    {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; symtab_enter_scope();}
#line 2245 "syntax.tab.c" /* yacc.c:1646  */
    break;


#line 2249 "syntax.tab.c" /* yacc.c:1646  */
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
#line 439 "syntax.y" /* yacc.c:1906  */


int main(int argc, char *argv[]){
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL) {
            perror("error opening file");
            return T_ERROR;
        }
    } else {
        printf("No input file provided.\n");
        return T_ERROR;
    }

    symtab_init(); 

    yyparse();

    fclose(yyin);

    //free?????????
    return 0;
}

void yyerror (const char *str){
    yyerrorno++;
    fprintf(stderr, "ERROR: [line: %d]: %s\n", yylineno, str);
    if (yyerrorno >= MAX_ERRORS) {
        fprintf(stderr, "MAX ERRORS FOUND\n");
        exit(EXIT_FAILURE);
    }
}
