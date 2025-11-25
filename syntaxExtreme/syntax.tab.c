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
#define YYLAST   615

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  87
/* YYNRULES -- Number of rules.  */
#define YYNRULES  181
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  348

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
     139,   140,   141,   142,   144,   152,   159,   160,   169,   170,
     171,   172,   173,   175,   176,   178,   179,   181,   182,   184,
     184,   186,   187,   189,   195,   196,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   217,   218,   219,   220,   221,   223,
     224,   226,   227,   229,   230,   232,   233,   234,   235,   238,
     240,   241,   243,   244,   246,   252,   253,   258,   263,   264,
     266,   272,   272,   273,   278,   280,   281,   283,   283,   283,
     283,   284,   285,   287,   288,   291,   294,   295,   298,   314,
     316,   316,   318,   319,   321,   323,   325,   326,   329,   332,
     340,   341,   343,   344,   346,   348,   355,   359,   360,   362,
     364,   365,   367,   368,   369,   371,   372,   374,   381,   387,
     388,   390,   391,   397,   399,   400,   401,   402,   404,   404,
     405,   405,   407,   407,   408,   409,   410,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   423,   424,   425,
     426,   428,   429,   430,   431,   433,   434,   435,   437,   438,
     440,   441,   442,   444,   445,   445,   446,   447,   448,   449,
     450,   451
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
  "typedef_declaration", "typed_typename", "typename", "standard_type",
  "listspec", "dims", "dim", "const_declaration", "$@1", "constdefs",
  "constdef", "init_value", "expression", "variable", "general_expression",
  "assignment", "expression_list", "constant", "listexpression",
  "list_elements", "init_values", "enum_declaration", "enum_body",
  "id_list", "initializer", "class_declaration", "class_body", "$@2",
  "parent", "members_methods", "access", "member_or_method", "member",
  "var_declaration", "variabledefs", "variabledef", "anonymous_union",
  "union_body", "$@3", "fields", "field", "method",
  "short_func_declaration", "short_par_func_header", "func_header_start",
  "parameter_types", "pass_list_dims", "nopar_func_header",
  "union_declaration", "global_var_declaration", "init_variabledefs",
  "init_variabledef", "func_declaration", "full_func_declaration",
  "full_par_func_header", "class_func_header_start", "func_class",
  "parameter_list", "pass_variabledef", "nopar_class_func_header",
  "decl_statements", "declarations", "$@4", "$@5", "decltype",
  "statements", "statement", "expression_statement", "if_statement",
  "if_tail", "while_statement", "for_statement", "optexpr",
  "return_statement", "io_statement", "in_list", "in_item", "out_list",
  "out_item", "comp_statement", "$@6", "main_function", "main_header", YY_NULLPTR
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

#define YYPACT_NINF -232

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-232)))

#define YYTABLE_NINF -165

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -232,    51,   152,  -232,    49,   185,  -232,   146,  -232,  -232,
     185,    31,  -232,    42,    53,  -232,  -232,  -232,   106,   106,
    -232,  -232,  -232,  -232,  -232,    84,   123,    -3,  -232,  -232,
    -232,  -232,   126,   141,   137,  -232,   155,   166,  -232,  -232,
    -232,   106,   182,    27,  -232,   177,  -232,   189,  -232,   225,
     250,    64,  -232,   234,  -232,    63,  -232,   359,   359,   132,
     359,   359,   255,   274,   272,   273,    10,   283,   300,   282,
    -232,   285,   275,   312,   294,  -232,   467,  -232,  -232,   106,
     286,   314,  -232,    19,    83,   101,  -232,   297,   299,   302,
     303,   305,   491,   306,   295,   301,  -232,  -232,  -232,  -232,
    -232,   561,   561,    35,   561,   313,   322,  -232,   561,  -232,
     572,    56,    92,  -232,  -232,  -232,   316,   400,   311,   213,
    -232,  -232,  -232,  -232,  -232,  -232,  -232,  -232,   317,  -232,
      38,   148,   329,   331,  -232,  -232,  -232,  -232,  -232,  -232,
    -232,   130,  -232,  -232,  -232,   304,  -232,   185,   250,     8,
    -232,   310,   467,  -232,   572,   174,   340,  -232,  -232,  -232,
     341,   225,  -232,  -232,  -232,  -232,   185,  -232,   185,  -232,
    -232,   561,   561,   491,   308,   323,   561,    35,   561,   338,
    -232,   100,  -232,   561,   342,   169,  -232,   118,   359,   561,
     561,   561,   561,   561,   561,  -232,   514,   362,   561,   561,
    -232,   561,  -232,   311,   265,    17,  -232,   347,  -232,  -232,
     341,  -232,  -232,  -232,    86,   199,  -232,   283,   196,   106,
    -232,  -232,    20,  -232,  -232,   367,  -232,     7,  -232,  -232,
      46,  -232,  -232,   310,    39,    38,   175,   193,   349,  -232,
     217,   100,    -8,  -232,   308,    -1,  -232,   221,  -232,  -232,
     561,  -232,   343,   236,   298,   240,    60,   338,  -232,   308,
     351,  -232,  -232,   120,  -232,  -232,   106,  -232,  -232,   467,
    -232,   354,   356,   357,    32,   180,   151,  -232,  -232,  -232,
     250,   360,  -232,   467,  -232,  -232,  -232,  -232,  -232,   441,
     441,   491,  -232,  -232,    35,  -232,   561,  -232,  -232,  -232,
    -232,  -232,   106,   212,  -232,  -232,  -232,  -232,  -232,   180,
    -232,   106,  -232,  -232,  -232,  -232,  -232,  -232,   364,   363,
    -232,   106,  -232,  -232,  -232,   407,  -232,   372,  -232,  -232,
     247,  -232,  -232,   381,   401,    63,  -232,   441,  -232,   537,
    -232,  -232,  -232,    39,  -232,   385,   441,  -232
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,     0,     0,    18,     0,    20,    21,
       0,     0,    22,     0,     0,    17,     3,     5,    24,    15,
      16,     6,     7,     8,   120,     0,     0,     0,     9,    10,
      11,   121,     0,     0,     0,     2,     0,     0,    12,    13,
      19,    24,     0,     0,    29,    84,   100,     0,    23,     0,
      79,     0,   118,     0,   106,     0,   107,   143,   143,     0,
     143,   143,     0,     0,     0,     0,     0,     0,     0,     0,
      81,     0,     0,     0,     0,    26,   143,   119,   116,    24,
     109,     0,   114,    24,     0,     0,   142,     0,     0,     0,
       0,     0,   143,     0,     0,     0,    58,    66,    67,    68,
      65,   143,   143,   143,   143,     0,   143,   156,   143,   174,
      62,    47,     0,    60,    50,    53,     0,   143,     0,     0,
     145,   147,   148,   149,   150,   151,   152,   153,     0,   133,
      24,     0,     0,     0,   178,    26,   179,   180,   181,   177,
      26,     0,    32,    83,    80,     0,   115,     0,    79,     0,
      74,    98,   143,    78,    34,    47,     0,   117,   128,   127,
     112,    26,   131,   111,   130,   108,     0,   126,     0,   154,
     155,   143,   143,   143,   163,     0,   143,   143,   143,    43,
      42,    45,    44,   143,     0,     0,    71,     0,   143,   143,
     143,   143,   143,   143,   143,    46,    64,     0,   143,   143,
     157,   143,   124,     0,     0,    57,   140,     0,   144,   122,
       0,   125,   123,   176,     0,     0,    30,     0,    90,    24,
      15,   104,     0,   103,    77,     0,    75,     0,    25,    73,
       0,    57,   132,   113,    24,    24,     0,     0,     0,   165,
       0,   170,     0,   169,   173,     0,   172,     0,    52,    51,
     143,    69,     0,    36,    37,    38,    39,    40,    41,    63,
       0,    55,    61,     0,    59,   138,    24,   146,    14,   143,
      31,     0,     0,     0,    90,     0,     0,    97,   101,   102,
      79,     0,    28,   143,    35,   112,    26,   110,   129,   143,
     143,   143,    49,   166,   143,   167,   143,    56,    70,   175,
      48,    54,    24,     0,    33,    87,    88,    89,    82,     0,
     100,    15,    86,    91,    93,    94,    92,   105,     0,     0,
      95,    24,    76,    27,    72,   160,   161,     0,   168,   171,
       0,   141,    85,     0,     0,     0,    96,   143,   158,   143,
     139,    99,   109,    24,   159,     0,   143,   162
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -232,  -232,  -232,  -232,  -232,   435,    -2,   332,   -18,   -53,
    -232,  -232,  -232,  -232,   222,  -137,   -64,   -72,   -87,   -99,
    -232,  -232,  -232,  -232,  -232,  -232,  -232,  -232,  -138,  -232,
    -232,  -232,  -232,  -232,   168,   131,  -232,  -230,  -231,   -16,
    -232,   138,  -232,  -232,   228,  -232,   449,  -232,   450,  -232,
     219,   454,  -232,  -232,  -232,   383,  -232,  -232,  -232,  -232,
    -232,   410,   237,  -232,   -40,  -232,  -232,  -232,   -44,   361,
    -112,  -232,  -232,  -232,  -232,  -232,  -167,  -232,  -232,  -232,
     186,  -232,   178,  -232,  -232,  -232,  -232
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    16,    17,   219,   220,    20,    49,   233,
     228,    21,    67,   141,   142,   153,   110,   111,   112,   113,
     260,   114,   115,   187,   230,    22,    74,   149,    77,    23,
      69,   145,    70,   274,   275,   312,   313,   221,   276,   162,
     315,    71,    72,   222,   223,   316,   317,    25,   318,    84,
     163,   319,    28,    29,    51,    52,    30,    31,    32,    33,
      81,    85,   164,    34,   116,   117,   302,   266,   156,   119,
     120,   121,   122,   338,   123,   124,   175,   125,   126,   242,
     243,   245,   246,   127,   188,    35,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    53,    50,    41,   155,   174,   238,   208,    44,   186,
     224,   138,   154,   118,   118,   229,   118,   118,   128,   185,
     132,   133,   151,    63,     6,    40,     8,     9,    65,   155,
     155,   181,   155,    12,   -17,   303,    48,   179,   180,   281,
     182,   293,   271,   272,   273,   314,    56,   -17,   295,    86,
      15,     3,   294,    83,    57,    48,    48,   130,   139,   225,
     296,    45,   282,    50,    96,   161,   226,     6,    40,     8,
       9,   330,    46,   203,    66,   160,    12,    37,   278,   314,
     155,   105,   214,    47,   236,   237,   174,   215,   154,   240,
     308,   244,   208,    15,   210,   285,   247,   283,    38,   262,
     195,   193,   194,   196,   284,   241,   197,    39,   198,   259,
     199,    82,   263,    78,   264,    79,   206,   155,   155,   155,
     155,   155,   155,    48,   327,   253,   254,   255,   256,   257,
     258,   165,   304,    54,   166,   268,     6,    40,     8,     9,
     227,   200,   322,   201,   118,    12,   324,    42,   252,   167,
     197,   298,   168,     4,   199,     5,     6,     7,     8,     9,
      10,    11,    15,   -19,   234,    12,   235,    13,    14,   250,
      55,   201,   345,   251,    43,   301,   -19,   325,   326,   216,
     129,   217,    15,    58,     6,    40,     8,     9,    59,     6,
      40,     8,     9,    12,    60,   310,   211,   155,    12,   168,
     320,   265,   321,   277,   174,   154,   271,   272,   273,   244,
      15,   155,    61,    62,   207,    15,   286,   249,   195,   154,
     201,   196,   241,   289,   197,   344,   201,    86,   199,    64,
      68,    87,    88,    89,   347,    90,    91,    92,    93,    94,
      95,   290,    96,  -143,   201,    97,    73,    98,    99,   100,
     277,   269,   174,   227,   101,    75,   102,   103,   104,   105,
     106,   331,   107,   321,    80,   292,   207,   108,   201,   297,
     109,  -136,   201,   311,   190,   191,   192,   193,   194,    86,
     192,   193,   194,    87,    88,    89,   277,    90,    91,    92,
      93,    94,    95,   334,    96,  -143,   340,    97,   321,    98,
      99,   100,    76,   134,   135,   336,   101,   311,   102,   103,
     104,   105,   106,   140,   107,     6,    40,     8,     9,   108,
     136,   137,   109,  -134,    12,   286,     6,    40,     8,     9,
     143,   144,   147,   343,   146,    12,    86,   191,   192,   193,
     194,   205,   148,   150,   159,   158,   169,    93,   170,   171,
     172,    96,   173,   176,    97,   177,    98,    99,   100,   201,
     183,   218,   178,   101,   227,   102,   103,   104,   105,   106,
     231,   232,   239,    86,   202,   209,   108,    87,    88,    89,
     194,    90,    91,    92,    93,    94,    95,   212,    96,   213,
     248,    97,   261,    98,    99,   100,   267,   280,   291,   300,
     101,   299,   102,   103,   104,   105,   106,   305,   107,   306,
     307,   335,    56,   108,    86,   323,   109,  -137,    87,    88,
      89,   339,    90,    91,    92,    93,    94,    95,   337,    96,
     341,   342,    97,   346,    98,    99,   100,    18,   184,   270,
     332,   101,   309,   102,   103,   104,   105,   106,   333,   107,
     279,    24,    26,   287,   108,    86,    27,   109,  -135,    87,
      88,    89,   157,    90,    91,    92,    93,    94,    95,   131,
      96,     0,   288,    97,   329,    98,    99,   100,   204,     0,
     328,    86,   101,     0,   102,   103,   104,   105,   106,     0,
     107,     0,    93,     0,     0,   108,    96,     0,   109,    97,
       0,    98,    99,   100,     0,    86,     0,     0,   101,     0,
     102,   103,   104,   105,   106,     0,    93,     0,     0,     0,
      96,   108,     0,    97,   152,    98,    99,   100,    86,     0,
       0,     0,   101,     0,   102,   103,   104,   105,   106,    93,
    -164,     0,     0,    96,  -143,   108,    97,     0,    98,    99,
     100,    86,     0,     0,     0,   101,     0,   102,   103,   104,
     105,   106,    93,     0,     0,     0,    96,     0,   108,    97,
       0,    98,    99,   100,     0,    86,     0,     0,   101,     0,
     102,   103,   104,   105,   106,  -164,    93,     0,     0,     0,
      96,   108,     0,    97,     0,    98,    99,   100,     0,     0,
       0,     0,   101,     0,   102,   103,   104,   105,   106,   189,
     190,   191,   192,   193,   194,   108
};

static const yytype_int16 yycheck[] =
{
       2,    19,    18,     5,    76,    92,   173,   119,    10,   108,
     148,     1,    76,    57,    58,   152,    60,    61,    58,   106,
      60,    61,    75,    41,     4,     5,     6,     7,     1,   101,
     102,   103,   104,    13,    17,   266,    17,   101,   102,    32,
     104,    49,    10,    11,    12,   275,    49,    30,    49,    14,
      30,     0,    60,    55,    57,    17,    17,    59,    48,    51,
      61,    30,    55,    79,    29,    83,    58,     4,     5,     6,
       7,   302,    30,   117,    47,    56,    13,    28,    58,   309,
     152,    46,   135,    30,   171,   172,   173,   140,   152,   176,
      58,   178,   204,    30,    56,    56,   183,    51,    49,   198,
      44,    41,    42,    47,    58,   177,    50,    58,    52,   196,
      54,    48,   199,    49,   201,    51,   118,   189,   190,   191,
     192,   193,   194,    17,   291,   189,   190,   191,   192,   193,
     194,    48,   269,    49,    51,    49,     4,     5,     6,     7,
      54,    49,   280,    51,   188,    13,   283,     1,   188,    48,
      50,   250,    51,     1,    54,     3,     4,     5,     6,     7,
       8,     9,    30,    17,   166,    13,   168,    15,    16,    51,
      47,    51,   339,    55,    28,    55,    30,   289,   290,    49,
      48,    51,    30,    57,     4,     5,     6,     7,    47,     4,
       5,     6,     7,    13,    57,    15,    48,   269,    13,    51,
      49,   203,    51,   219,   291,   269,    10,    11,    12,   296,
      30,   283,    57,    47,     1,    30,   234,    48,    44,   283,
      51,    47,   294,    48,    50,   337,    51,    14,    54,    47,
      53,    18,    19,    20,   346,    22,    23,    24,    25,    26,
      27,    48,    29,    30,    51,    32,    57,    34,    35,    36,
     266,    52,   339,    54,    41,    30,    43,    44,    45,    46,
      47,    49,    49,    51,    30,    48,     1,    54,    51,    48,
      57,    58,    51,   275,    38,    39,    40,    41,    42,    14,
      40,    41,    42,    18,    19,    20,   302,    22,    23,    24,
      25,    26,    27,   311,    29,    30,    49,    32,    51,    34,
      35,    36,    52,    48,    30,   321,    41,   309,    43,    44,
      45,    46,    47,    30,    49,     4,     5,     6,     7,    54,
      48,    48,    57,    58,    13,   343,     4,     5,     6,     7,
      30,    49,    57,   335,    49,    13,    14,    39,    40,    41,
      42,    30,    30,    49,    30,    59,    49,    25,    49,    47,
      47,    29,    47,    47,    32,    60,    34,    35,    36,    51,
      47,    57,    61,    41,    54,    43,    44,    45,    46,    47,
      30,    30,    49,    14,    58,    58,    54,    18,    19,    20,
      42,    22,    23,    24,    25,    26,    27,    58,    29,    58,
      48,    32,    30,    34,    35,    36,    49,    30,    49,    48,
      41,    58,    43,    44,    45,    46,    47,    53,    49,    53,
      53,    47,    49,    54,    14,    55,    57,    58,    18,    19,
      20,    49,    22,    23,    24,    25,    26,    27,    21,    29,
      49,    30,    32,    48,    34,    35,    36,     2,   106,   217,
     309,    41,   274,    43,    44,    45,    46,    47,   310,    49,
     222,     2,     2,   234,    54,    14,     2,    57,    58,    18,
      19,    20,    79,    22,    23,    24,    25,    26,    27,    59,
      29,    -1,   235,    32,   296,    34,    35,    36,   117,    -1,
     294,    14,    41,    -1,    43,    44,    45,    46,    47,    -1,
      49,    -1,    25,    -1,    -1,    54,    29,    -1,    57,    32,
      -1,    34,    35,    36,    -1,    14,    -1,    -1,    41,    -1,
      43,    44,    45,    46,    47,    -1,    25,    -1,    -1,    -1,
      29,    54,    -1,    32,    57,    34,    35,    36,    14,    -1,
      -1,    -1,    41,    -1,    43,    44,    45,    46,    47,    25,
      49,    -1,    -1,    29,    30,    54,    32,    -1,    34,    35,
      36,    14,    -1,    -1,    -1,    41,    -1,    43,    44,    45,
      46,    47,    25,    -1,    -1,    -1,    29,    -1,    54,    32,
      -1,    34,    35,    36,    -1,    14,    -1,    -1,    41,    -1,
      43,    44,    45,    46,    47,    48,    25,    -1,    -1,    -1,
      29,    54,    -1,    32,    -1,    34,    35,    36,    -1,    -1,
      -1,    -1,    41,    -1,    43,    44,    45,    46,    47,    37,
      38,    39,    40,    41,    42,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    67,    68,     0,     1,     3,     4,     5,     6,     7,
       8,     9,    13,    15,    16,    30,    69,    70,    71,    72,
      73,    77,    91,    95,   112,   113,   114,   117,   118,   119,
     122,   123,   124,   125,   129,   151,   152,    28,    49,    58,
       5,    72,     1,    28,    72,    30,    30,    30,    17,    74,
     105,   120,   121,    74,    49,    47,    49,    57,    57,    47,
      57,    57,    47,    74,    47,     1,    47,    78,    53,    96,
      98,   107,   108,    57,    92,    30,    52,    94,    49,    51,
      30,   126,    48,    72,   115,   127,    14,    18,    19,    20,
      22,    23,    24,    25,    26,    27,    29,    32,    34,    35,
      36,    41,    43,    44,    45,    46,    47,    49,    54,    57,
      82,    83,    84,    85,    87,    88,   130,   131,   134,   135,
     136,   137,   138,   140,   141,   143,   144,   149,   130,    48,
      72,   127,   130,   130,    48,    30,    48,    48,     1,    48,
      30,    79,    80,    30,    49,    97,    49,    57,    30,    93,
      49,    75,    57,    81,    82,    83,   134,   121,    59,    30,
      56,    74,   105,   116,   128,    48,    51,    48,    51,    49,
      49,    47,    47,    47,    84,   142,    47,    60,    61,    82,
      82,    83,    82,    47,    73,    84,    85,    89,   150,    37,
      38,    39,    40,    41,    42,    44,    47,    50,    52,    54,
      49,    51,    58,   134,   135,    30,    72,     1,   136,    58,
      56,    48,    58,    58,    75,    75,    49,    51,    57,    71,
      72,   103,   109,   110,    94,    51,    58,    54,    76,    81,
      90,    30,    30,    75,    72,    72,    84,    84,   142,    49,
      84,    83,   145,   146,    84,   147,   148,    84,    48,    48,
      51,    55,   130,    82,    82,    82,    82,    82,    82,    84,
      86,    30,    85,    84,    84,    72,   133,    49,    49,    52,
      80,    10,    11,    12,    99,   100,   104,   105,    58,   110,
      30,    32,    55,    51,    58,    56,    74,   116,   128,    48,
      48,    49,    48,    49,    60,    49,    61,    48,    85,    58,
      48,    55,   132,   104,    81,    53,    53,    53,    58,   100,
      15,    72,   101,   102,   103,   106,   111,   112,   114,   117,
      49,    51,    94,    55,    81,   136,   136,   142,   146,   148,
     104,    49,   101,   107,    74,    47,   105,    21,   139,    49,
      49,    49,    30,    72,   136,   142,    48,   136
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    68,    68,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    70,    71,    72,    72,    73,    73,
      73,    73,    73,    74,    74,    75,    75,    76,    76,    78,
      77,    79,    79,    80,    81,    81,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    83,    83,    83,    83,    83,    84,
      84,    85,    85,    86,    86,    87,    87,    87,    87,    88,
      89,    89,    90,    90,    91,    92,    93,    93,    94,    94,
      95,    97,    96,    98,    98,    99,    99,   100,   100,   100,
     100,   101,   101,   102,   102,   103,   104,   104,   105,   106,
     108,   107,   109,   109,   110,   111,   112,   112,   113,   114,
     115,   115,   116,   116,   117,   118,   119,   120,   120,   121,
     122,   122,   123,   123,   123,   124,   124,   125,   126,   127,
     127,   128,   128,   129,   130,   130,   130,   130,   132,   131,
     133,   131,   134,   134,   135,   135,   135,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   137,   138,   139,
     139,   140,   141,   142,   142,   143,   144,   144,   145,   145,
     146,   147,   147,   148,   150,   149,   151,   152,   152,   152,
     152,   152
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     6,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     2,     0,     3,     2,     0,
       5,     3,     1,     4,     1,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     2,     1,     4,     4,
       1,     3,     3,     1,     4,     3,     4,     2,     1,     3,
       1,     3,     1,     1,     0,     1,     1,     1,     1,     3,
       3,     1,     3,     1,     4,     3,     4,     2,     2,     0,
       4,     0,     5,     2,     0,     3,     2,     2,     2,     2,
       0,     1,     1,     1,     1,     3,     3,     1,     3,     3,
       0,     4,     2,     1,     1,     1,     2,     2,     4,     3,
       4,     2,     1,     2,     3,     4,     3,     3,     1,     2,
       1,     1,     4,     4,     4,     4,     4,     4,     2,     4,
       2,     1,     2,     3,     2,     1,     1,     0,     0,     6,
       0,     5,     1,     0,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     2,     6,     2,
       0,     5,     9,     1,     0,     3,     4,     4,     3,     1,
       1,     3,     1,     1,     0,     4,     4,     4,     4,     4,
       4,     4
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
#line 1629 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 141 "syntax.y" /* yacc.c:1646  */
    {yyerror(" HINT: syntax error in global declaration\n"); yyerrok;}
#line 1635 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 142 "syntax.y" /* yacc.c:1646  */
    {yyerror(" HINT: in global declaration\n"); yyerrok; }
#line 1641 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 144 "syntax.y" /* yacc.c:1646  */
    {
                                                                                    /* αγνοούμε προς το παρόν listspec/dims για σύνθετους, κρατάμε base type */
                                                                                    if (!symtab_insert((yyvsp[-2].strval), SYM_TYPE, (yyvsp[-4].type))) {
                                                                                        YYERROR_FMT("Redeclaration of typedef '%s'", (yyvsp[-2].strval));
                                                                                    }
                                                                                }
#line 1652 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 153 "syntax.y" /* yacc.c:1646  */
    {
          current_type = (yyvsp[0].type);  /* εδώ κάνουμε το side-effect */
          (yyval.type) = (yyvsp[0].type);            /* και περνάμε το Type* προς τα κάτω αν χρειαστεί */
      }
#line 1661 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 160 "syntax.y" /* yacc.c:1646  */
    {Symbol *s = symtab_lookup((yyvsp[0].strval));
                                                                                    if (!s || s->kind != SYM_TYPE || !s->type) {
                                                                                        YYERROR_FMT("Unknown type '%s'", (yyvsp[0].strval));
                                                                                        (yyval.type) = type_error;
                                                                                    } else {
                                                                                        (yyval.type) = s->type;
                                                                                    }
                                                                                }
#line 1674 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 169 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = type_char;}
#line 1680 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 170 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = type_int;}
#line 1686 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 171 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = type_float;}
#line 1692 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 172 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = type_string;}
#line 1698 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 173 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = type_void;}
#line 1704 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 175 "syntax.y" /* yacc.c:1646  */
    {(yyval.intval) = 1;}
#line 1710 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 176 "syntax.y" /* yacc.c:1646  */
    {(yyval.intval) = 0;}
#line 1716 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 178 "syntax.y" /* yacc.c:1646  */
    { (yyval.type) = attach_nested_array((yyvsp[-1].type), (yyvsp[0].type)); }
#line 1722 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 179 "syntax.y" /* yacc.c:1646  */
    { (yyval.type) = NULL; }
#line 1728 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 181 "syntax.y" /* yacc.c:1646  */
    { (yyval.type) = make_array_type(NULL, (yyvsp[-1].intval)); }
#line 1734 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 182 "syntax.y" /* yacc.c:1646  */
    { (yyval.type) = make_array_type(NULL, 0); }
#line 1740 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 184 "syntax.y" /* yacc.c:1646  */
    { current_type = (yyvsp[0].type); }
#line 1746 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 189 "syntax.y" /* yacc.c:1646  */
    {if (!current_type) current_type = type_error;
                                                                                    if (!symtab_insert((yyvsp[-3].strval), SYM_CONST, current_type)) {
                                                                                        YYERROR_FMT("Redeclaration of const '%s'", (yyvsp[-3].strval));
                                                                                    }
                                                                                }
#line 1756 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 198 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = sem_binary_logical((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1762 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 199 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = sem_binary_logical((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1768 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 200 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = sem_binary_equality((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1774 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 201 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = sem_binary_relational((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1780 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 202 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = sem_binary_arith((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1786 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 203 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = sem_binary_arith((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1792 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 204 "syntax.y" /* yacc.c:1646  */
    { (yyval.type) = sem_unary_not((yyvsp[0].type), yylineno); }
#line 1798 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 205 "syntax.y" /* yacc.c:1646  */
    { (yyval.type) = sem_unary_not((yyvsp[0].type), yylineno); }
#line 1804 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 206 "syntax.y" /* yacc.c:1646  */
    { (yyval.type) = type_int; }
#line 1810 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 207 "syntax.y" /* yacc.c:1646  */
    { (yyval.type) = sem_unary_incdec((yyvsp[0].type), yylineno); }
#line 1816 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 208 "syntax.y" /* yacc.c:1646  */
    { (yyval.type) = sem_unary_incdec((yyvsp[-1].type), yylineno); }
#line 1822 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 209 "syntax.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].type);}
#line 1828 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 210 "syntax.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[-3].type);}
#line 1834 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 211 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = type_int;}
#line 1840 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 212 "syntax.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].type);}
#line 1846 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 213 "syntax.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[-1].type);}
#line 1852 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 214 "syntax.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[-1].type);}
#line 1858 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 215 "syntax.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].type);}
#line 1864 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 217 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = sem_index((yyvsp[-3].type), (yyvsp[-1].type), yylineno);}
#line 1870 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 218 "syntax.y" /* yacc.c:1646  */
    {(yyval.type)= type_error;}
#line 1876 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 219 "syntax.y" /* yacc.c:1646  */
    {(yyval.type)= type_error;}
#line 1882 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 220 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = sem_use_variable((yyvsp[0].strval), yylineno); }
#line 1888 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 221 "syntax.y" /* yacc.c:1646  */
    {(yyval.type)= type_error;}
#line 1894 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 223 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = (yyvsp[0].type);}
#line 1900 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 224 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = (yyvsp[0].type);}
#line 1906 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 226 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = sem_check_assignment((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1912 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 227 "syntax.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].type);}
#line 1918 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 229 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = (yyvsp[0].type);}
#line 1924 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 230 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = type_void;}
#line 1930 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 232 "syntax.y" /* yacc.c:1646  */
    { (yyval.type) = type_char;   }
#line 1936 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 233 "syntax.y" /* yacc.c:1646  */
    { (yyval.type) = type_int;    }
#line 1942 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 234 "syntax.y" /* yacc.c:1646  */
    { (yyval.type) = type_float;  }
#line 1948 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 235 "syntax.y" /* yacc.c:1646  */
    { (yyval.type) = type_string; }
#line 1954 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 238 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = sem_make_list_type((yyvsp[-1].type), yylineno);}
#line 1960 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 240 "syntax.y" /* yacc.c:1646  */
    { (yyval.type) = sem_find_list_element_type((yyvsp[-2].type), (yyvsp[0].type), yylineno); }
#line 1966 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 241 "syntax.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 1972 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 246 "syntax.y" /* yacc.c:1646  */
    {Type *t = make_simple_type(TYPE_ENUM);
                                                                                    if (!symtab_insert((yyvsp[-2].strval), SYM_TYPE, t)) {
                                                                                        YYERROR_FMT("Redeclaration of enum '%s'", (yyvsp[-2].strval));
                                                                                    }
                                                                                }
#line 1982 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 253 "syntax.y" /* yacc.c:1646  */
    {/* enum constants -> ακέραιοι */
                                                                                    if (!symtab_insert((yyvsp[-1].strval), SYM_ENUM_CONST, type_int)) {
                                                                                        YYERROR_FMT("Redeclaration of enum const '%s'", (yyvsp[-1].strval));
                                                                                    }
                                                                                }
#line 1992 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 258 "syntax.y" /* yacc.c:1646  */
    {if (!symtab_insert((yyvsp[-1].strval), SYM_ENUM_CONST, type_int)) {
                                                                                        YYERROR_FMT("Redeclaration of enum const '%s'", (yyvsp[-1].strval));
                                                                                    }
                                                                                }
#line 2001 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 264 "syntax.y" /* yacc.c:1646  */
    {;}
#line 2007 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 266 "syntax.y" /* yacc.c:1646  */
    {Type *t = make_simple_type(TYPE_CLASS);
                                                                                    if (!symtab_insert((yyvsp[-2].strval), SYM_TYPE, t)) {
                                                                                        YYERROR_FMT("Redeclaration of class '%s'", (yyvsp[-2].strval));
                                                                                    }
                                                                                }
#line 2017 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 272 "syntax.y" /* yacc.c:1646  */
    {symtab_enter_scope();}
#line 2023 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 272 "syntax.y" /* yacc.c:1646  */
    { symtab_leave_scope();}
#line 2029 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 273 "syntax.y" /* yacc.c:1646  */
    {Symbol *base = symtab_lookup((yyvsp[0].strval));
                                                                                    if (!base || base->kind != SYM_TYPE) {
                                                                                        YYERROR_FMT("Unknown base class '%s'", (yyvsp[0].strval));
                                                                                    }
                                                                                }
#line 2039 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 278 "syntax.y" /* yacc.c:1646  */
    {;}
#line 2045 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 283 "syntax.y" /* yacc.c:1646  */
    { }
#line 2051 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 298 "syntax.y" /* yacc.c:1646  */
    {if (!current_type) current_type = type_error;
                                                                                    Type *t = current_type;
                                                                                    if ((yyvsp[-2].intval)) {  /* αν listspec == 1 → είναι λίστα */
                                                                                        t = sem_make_list_type(current_type, yylineno);
                                                                                    }
                                                                                    else if ((yyvsp[0].type) == NULL)
                                                                                        t = current_type;
                                                                                    else
                                                                                        t = attach_array_to_base(current_type, (yyvsp[0].type));

                                                                                    if (!symtab_insert((yyvsp[-1].strval), SYM_VAR, t)) {
                                                                                        YYERROR_FMT("Redeclaration of '%s'", (yyvsp[-1].strval));
                                                                                    }
                                                                                }
#line 2070 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 316 "syntax.y" /* yacc.c:1646  */
    {symtab_enter_scope();}
#line 2076 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 316 "syntax.y" /* yacc.c:1646  */
    { symtab_leave_scope();}
#line 2082 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 325 "syntax.y" /* yacc.c:1646  */
    { symtab_leave_scope();}
#line 2088 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 326 "syntax.y" /* yacc.c:1646  */
    { symtab_leave_scope();}
#line 2094 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 332 "syntax.y" /* yacc.c:1646  */
    {Type *ret = (yyvsp[-2].type);
                                                                                    if (!symtab_insert((yyvsp[0].strval), SYM_FUNC, ret)) {
                                                                                        YYERROR_FMT("Redeclaration of function '%s'", (yyvsp[0].strval));
                                                                                    }
                                                                                    symtab_enter_scope();   /* νέο scope για παραμέτρους+σώμα */
                                                                                }
#line 2105 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 348 "syntax.y" /* yacc.c:1646  */
    {Type *t = make_simple_type(TYPE_UNION);
                                                                                    if (!symtab_insert((yyvsp[-2].strval), SYM_TYPE, t)) {
                                                                                        YYERROR_FMT("Redeclaration of union '%s'", (yyvsp[-2].strval));
                                                                                    }
                                                                                }
#line 2115 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 367 "syntax.y" /* yacc.c:1646  */
    { symtab_leave_scope();}
#line 2121 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 368 "syntax.y" /* yacc.c:1646  */
    { symtab_leave_scope();}
#line 2127 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 369 "syntax.y" /* yacc.c:1646  */
    { symtab_leave_scope();}
#line 2133 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 374 "syntax.y" /* yacc.c:1646  */
    {Type *ret = (yyvsp[-3].type);
                                                                                    if (!symtab_insert((yyvsp[0].strval), SYM_FUNC, ret)) {
                                                                                        YYERROR_FMT("Redeclaration of method '%s'", (yyvsp[0].strval));
                                                                                    }
                                                                                    symtab_enter_scope();
                                                                                }
#line 2144 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 381 "syntax.y" /* yacc.c:1646  */
    {Symbol *cls = symtab_lookup((yyvsp[-1].strval));
                                                                                    if (!cls || cls->kind != SYM_TYPE) {
                                                                                        YYERROR_FMT("Unknown class type '%s'", (yyvsp[-1].strval));
                                                                                    }
                                                                                }
#line 2154 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 388 "syntax.y" /* yacc.c:1646  */
    { current_type = (yyvsp[-1].type); }
#line 2160 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 391 "syntax.y" /* yacc.c:1646  */
    {if (!current_type) current_type = type_error;
                                                                                    if (!symtab_insert((yyvsp[0].strval), SYM_VAR, current_type)) {
                                                                                        YYERROR_FMT("Redeclaration of parameter '%s'", (yyvsp[0].strval));
                                                                                    }
                                                                                }
#line 2170 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 402 "syntax.y" /* yacc.c:1646  */
    {;}
#line 2176 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 404 "syntax.y" /* yacc.c:1646  */
    { current_type = (yyvsp[0].type); }
#line 2182 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 405 "syntax.y" /* yacc.c:1646  */
    { current_type = (yyvsp[0].type); }
#line 2188 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 407 "syntax.y" /* yacc.c:1646  */
    {;}
#line 2194 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 410 "syntax.y" /* yacc.c:1646  */
    { YYERROR_FMT(" HINT:  error in statement - skipping until ';'"); yyerrok; }
#line 2200 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 426 "syntax.y" /* yacc.c:1646  */
    {;}
#line 2206 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 431 "syntax.y" /* yacc.c:1646  */
    {;}
#line 2212 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 445 "syntax.y" /* yacc.c:1646  */
    {symtab_enter_scope();}
#line 2218 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 445 "syntax.y" /* yacc.c:1646  */
    { symtab_leave_scope();}
#line 2224 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 446 "syntax.y" /* yacc.c:1646  */
    { symtab_leave_scope();}
#line 2230 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 447 "syntax.y" /* yacc.c:1646  */
    {symtab_enter_scope();}
#line 2236 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 448 "syntax.y" /* yacc.c:1646  */
    {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; symtab_enter_scope();}
#line 2242 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 449 "syntax.y" /* yacc.c:1646  */
    {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; symtab_enter_scope();}
#line 2248 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 450 "syntax.y" /* yacc.c:1646  */
    {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; symtab_enter_scope();}
#line 2254 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 451 "syntax.y" /* yacc.c:1646  */
    {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; symtab_enter_scope();}
#line 2260 "syntax.tab.c" /* yacc.c:1646  */
    break;


#line 2264 "syntax.tab.c" /* yacc.c:1646  */
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
#line 453 "syntax.y" /* yacc.c:1906  */


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
    init_types(); 

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
