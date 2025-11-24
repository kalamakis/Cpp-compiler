/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "syntax.y"

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
    

#line 98 "syntax.tab.c"

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

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "eof"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_TYPEDEF = 3,                  /* "typedef"  */
  YYSYMBOL_T_CHAR = 4,                     /* "char"  */
  YYSYMBOL_T_INT = 5,                      /* "int"  */
  YYSYMBOL_T_FLOAT = 6,                    /* "float"  */
  YYSYMBOL_T_STRING = 7,                   /* "string"  */
  YYSYMBOL_T_CONST = 8,                    /* "const"  */
  YYSYMBOL_T_CLASS = 9,                    /* "class"  */
  YYSYMBOL_T_PRIVATE = 10,                 /* "private"  */
  YYSYMBOL_T_PROTECTED = 11,               /* "protected"  */
  YYSYMBOL_T_PUBLIC = 12,                  /* "public"  */
  YYSYMBOL_T_VOID = 13,                    /* "void"  */
  YYSYMBOL_T_STATIC = 14,                  /* "static"  */
  YYSYMBOL_T_UNION = 15,                   /* "union"  */
  YYSYMBOL_T_ENUM = 16,                    /* "enum"  */
  YYSYMBOL_T_LIST = 17,                    /* "list"  */
  YYSYMBOL_T_CONTINUE = 18,                /* "continue"  */
  YYSYMBOL_T_BREAK = 19,                   /* "break"  */
  YYSYMBOL_T_IF = 20,                      /* "if"  */
  YYSYMBOL_T_ELSE = 21,                    /* "else"  */
  YYSYMBOL_T_WHILE = 22,                   /* "while"  */
  YYSYMBOL_T_FOR = 23,                     /* "for"  */
  YYSYMBOL_T_RETURN = 24,                  /* "return"  */
  YYSYMBOL_T_LENGTH = 25,                  /* "length"  */
  YYSYMBOL_T_CIN = 26,                     /* "cin"  */
  YYSYMBOL_T_COUT = 27,                    /* "cout"  */
  YYSYMBOL_T_MAIN = 28,                    /* "main"  */
  YYSYMBOL_T_THIS = 29,                    /* "this"  */
  YYSYMBOL_T_ID = 30,                      /* "id"  */
  YYSYMBOL_T_NUM = 31,                     /* "num"  */
  YYSYMBOL_T_ICONST = 32,                  /* "iconst"  */
  YYSYMBOL_T_UNKNOWN = 33,                 /* "unknown"  */
  YYSYMBOL_T_FCONST = 34,                  /* "fconst"  */
  YYSYMBOL_T_SCONST = 35,                  /* "sconst"  */
  YYSYMBOL_T_CCONST = 36,                  /* "cconst"  */
  YYSYMBOL_T_OROP = 37,                    /* "orop"  */
  YYSYMBOL_T_ANDOP = 38,                   /* "andop"  */
  YYSYMBOL_T_EQUOP = 39,                   /* "equop"  */
  YYSYMBOL_T_RELOP = 40,                   /* "relop"  */
  YYSYMBOL_T_ADDOP = 41,                   /* "addop"  */
  YYSYMBOL_T_MULOP = 42,                   /* "mulop"  */
  YYSYMBOL_T_NOTOP = 43,                   /* "notop"  */
  YYSYMBOL_T_INCDEC = 44,                  /* "incdec"  */
  YYSYMBOL_T_SIZEOP = 45,                  /* "sizeop"  */
  YYSYMBOL_T_LISTFUNC = 46,                /* "listfunc"  */
  YYSYMBOL_T_LPAREN = 47,                  /* "lparen"  */
  YYSYMBOL_T_RPAREN = 48,                  /* "rparen"  */
  YYSYMBOL_T_SEMI = 49,                    /* "semi"  */
  YYSYMBOL_T_DOT = 50,                     /* "dot"  */
  YYSYMBOL_T_COMMA = 51,                   /* "comma"  */
  YYSYMBOL_T_ASSIGN = 52,                  /* "assign"  */
  YYSYMBOL_T_COLON = 53,                   /* "colon"  */
  YYSYMBOL_T_LBRACK = 54,                  /* "lbrack"  */
  YYSYMBOL_T_RBRACK = 55,                  /* "rbrack"  */
  YYSYMBOL_T_REFER = 56,                   /* "refer"  */
  YYSYMBOL_T_LBRACE = 57,                  /* "lbrace"  */
  YYSYMBOL_T_RBRACE = 58,                  /* "rbrace"  */
  YYSYMBOL_T_METH = 59,                    /* "meth"  */
  YYSYMBOL_T_INP = 60,                     /* "inp"  */
  YYSYMBOL_T_OUT = 61,                     /* "out"  */
  YYSYMBOL_T_ERROR = 62,                   /* "error"  */
  YYSYMBOL_PREFIX = 63,                    /* PREFIX  */
  YYSYMBOL_POSTFIX = 64,                   /* POSTFIX  */
  YYSYMBOL_LOWER_THAN_ELSE = 65,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 66,                  /* $accept  */
  YYSYMBOL_program = 67,                   /* program  */
  YYSYMBOL_global_declarations = 68,       /* global_declarations  */
  YYSYMBOL_global_declaration = 69,        /* global_declaration  */
  YYSYMBOL_typedef_declaration = 70,       /* typedef_declaration  */
  YYSYMBOL_typename = 71,                  /* typename  */
  YYSYMBOL_standard_type = 72,             /* standard_type  */
  YYSYMBOL_listspec = 73,                  /* listspec  */
  YYSYMBOL_dims = 74,                      /* dims  */
  YYSYMBOL_dim = 75,                       /* dim  */
  YYSYMBOL_const_declaration = 76,         /* const_declaration  */
  YYSYMBOL_77_1 = 77,                      /* $@1  */
  YYSYMBOL_constdefs = 78,                 /* constdefs  */
  YYSYMBOL_constdef = 79,                  /* constdef  */
  YYSYMBOL_init_value = 80,                /* init_value  */
  YYSYMBOL_expression = 81,                /* expression  */
  YYSYMBOL_variable = 82,                  /* variable  */
  YYSYMBOL_general_expression = 83,        /* general_expression  */
  YYSYMBOL_assignment = 84,                /* assignment  */
  YYSYMBOL_expression_list = 85,           /* expression_list  */
  YYSYMBOL_constant = 86,                  /* constant  */
  YYSYMBOL_listexpression = 87,            /* listexpression  */
  YYSYMBOL_init_values = 88,               /* init_values  */
  YYSYMBOL_enum_declaration = 89,          /* enum_declaration  */
  YYSYMBOL_enum_body = 90,                 /* enum_body  */
  YYSYMBOL_id_list = 91,                   /* id_list  */
  YYSYMBOL_initializer = 92,               /* initializer  */
  YYSYMBOL_class_declaration = 93,         /* class_declaration  */
  YYSYMBOL_class_body = 94,                /* class_body  */
  YYSYMBOL_95_2 = 95,                      /* $@2  */
  YYSYMBOL_parent = 96,                    /* parent  */
  YYSYMBOL_members_methods = 97,           /* members_methods  */
  YYSYMBOL_access = 98,                    /* access  */
  YYSYMBOL_member_or_method = 99,          /* member_or_method  */
  YYSYMBOL_member = 100,                   /* member  */
  YYSYMBOL_var_declaration = 101,          /* var_declaration  */
  YYSYMBOL_variabledefs = 102,             /* variabledefs  */
  YYSYMBOL_variabledef = 103,              /* variabledef  */
  YYSYMBOL_anonymous_union = 104,          /* anonymous_union  */
  YYSYMBOL_union_body = 105,               /* union_body  */
  YYSYMBOL_106_3 = 106,                    /* $@3  */
  YYSYMBOL_fields = 107,                   /* fields  */
  YYSYMBOL_field = 108,                    /* field  */
  YYSYMBOL_method = 109,                   /* method  */
  YYSYMBOL_short_func_declaration = 110,   /* short_func_declaration  */
  YYSYMBOL_short_par_func_header = 111,    /* short_par_func_header  */
  YYSYMBOL_func_header_start = 112,        /* func_header_start  */
  YYSYMBOL_parameter_types = 113,          /* parameter_types  */
  YYSYMBOL_pass_list_dims = 114,           /* pass_list_dims  */
  YYSYMBOL_nopar_func_header = 115,        /* nopar_func_header  */
  YYSYMBOL_union_declaration = 116,        /* union_declaration  */
  YYSYMBOL_global_var_declaration = 117,   /* global_var_declaration  */
  YYSYMBOL_init_variabledefs = 118,        /* init_variabledefs  */
  YYSYMBOL_init_variabledef = 119,         /* init_variabledef  */
  YYSYMBOL_func_declaration = 120,         /* func_declaration  */
  YYSYMBOL_full_func_declaration = 121,    /* full_func_declaration  */
  YYSYMBOL_full_par_func_header = 122,     /* full_par_func_header  */
  YYSYMBOL_class_func_header_start = 123,  /* class_func_header_start  */
  YYSYMBOL_func_class = 124,               /* func_class  */
  YYSYMBOL_parameter_list = 125,           /* parameter_list  */
  YYSYMBOL_pass_variabledef = 126,         /* pass_variabledef  */
  YYSYMBOL_nopar_class_func_header = 127,  /* nopar_class_func_header  */
  YYSYMBOL_decl_statements = 128,          /* decl_statements  */
  YYSYMBOL_declarations = 129,             /* declarations  */
  YYSYMBOL_130_4 = 130,                    /* $@4  */
  YYSYMBOL_131_5 = 131,                    /* $@5  */
  YYSYMBOL_decltype = 132,                 /* decltype  */
  YYSYMBOL_statements = 133,               /* statements  */
  YYSYMBOL_statement = 134,                /* statement  */
  YYSYMBOL_expression_statement = 135,     /* expression_statement  */
  YYSYMBOL_if_statement = 136,             /* if_statement  */
  YYSYMBOL_if_tail = 137,                  /* if_tail  */
  YYSYMBOL_while_statement = 138,          /* while_statement  */
  YYSYMBOL_for_statement = 139,            /* for_statement  */
  YYSYMBOL_optexpr = 140,                  /* optexpr  */
  YYSYMBOL_return_statement = 141,         /* return_statement  */
  YYSYMBOL_io_statement = 142,             /* io_statement  */
  YYSYMBOL_in_list = 143,                  /* in_list  */
  YYSYMBOL_in_item = 144,                  /* in_item  */
  YYSYMBOL_out_list = 145,                 /* out_list  */
  YYSYMBOL_out_item = 146,                 /* out_item  */
  YYSYMBOL_comp_statement = 147,           /* comp_statement  */
  YYSYMBOL_148_6 = 148,                    /* $@6  */
  YYSYMBOL_main_function = 149,            /* main_function  */
  YYSYMBOL_main_header = 150               /* main_header  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int16 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if 1

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
#endif /* 1 */

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

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   320


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
static const yytype_int16 yyrline[] =
{
       0,   128,   128,   130,   131,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   143,   150,   151,   160,   161,   162,
     163,   164,   166,   166,   168,   169,   171,   171,   173,   173,
     175,   176,   178,   184,   185,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   206,   207,   208,   209,   210,   212,   213,
     215,   216,   218,   219,   221,   222,   223,   224,   227,   229,
     230,   232,   238,   239,   244,   249,   250,   252,   258,   258,
     259,   264,   266,   267,   269,   269,   269,   269,   270,   271,
     273,   274,   277,   281,   282,   285,   293,   295,   295,   297,
     298,   300,   302,   304,   305,   308,   311,   319,   320,   322,
     323,   325,   327,   334,   338,   339,   341,   343,   344,   346,
     347,   348,   350,   351,   353,   360,   366,   367,   369,   370,
     376,   378,   379,   380,   381,   383,   383,   384,   384,   386,
     386,   387,   388,   389,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   402,   403,   404,   405,   407,   408,
     409,   410,   412,   413,   414,   416,   417,   419,   420,   421,
     423,   424,   424,   425,   426,   427,   428,   429,   430
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"eof\"", "error", "\"invalid token\"", "\"typedef\"", "\"char\"",
  "\"int\"", "\"float\"", "\"string\"", "\"const\"", "\"class\"",
  "\"private\"", "\"protected\"", "\"public\"", "\"void\"", "\"static\"",
  "\"union\"", "\"enum\"", "\"list\"", "\"continue\"", "\"break\"",
  "\"if\"", "\"else\"", "\"while\"", "\"for\"", "\"return\"", "\"length\"",
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

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-228)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-162)

#define yytable_value_is_error(Yyn) \
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
       0,     1,     2,    16,    17,   217,    19,   156,   149,   225,
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
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

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
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

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
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


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= T_EOF)
    {
      yychar = T_EOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 4: /* global_declarations: %empty  */
#line 131 "syntax.y"
                                             {;}
#line 1827 "syntax.tab.c"
    break;

  case 12: /* global_declaration: error "semi"  */
#line 140 "syntax.y"
                                                                                {yyerror(" HINT: syntax error in global declaration\n"); yyerrok;}
#line 1833 "syntax.tab.c"
    break;

  case 13: /* global_declaration: error "rbrace"  */
#line 141 "syntax.y"
                                                                                {yyerror(" HINT: in global declaration\n"); yyerrok; }
#line 1839 "syntax.tab.c"
    break;

  case 14: /* typedef_declaration: "typedef" typename listspec "id" dims "semi"  */
#line 143 "syntax.y"
                                                                                {
                                                                                    /* αγνοούμε προς το παρόν listspec/dims για σύνθετους, κρατάμε base type */
                                                                                    if (!symtab_insert((yyvsp[-2].strval), SYM_TYPE, (yyvsp[-4].type))) {
                                                                                        YYERROR_FMT("Redeclaration of typedef '%s'", (yyvsp[-2].strval));
                                                                                    }
                                                                                }
#line 1850 "syntax.tab.c"
    break;

  case 16: /* typename: "id"  */
#line 151 "syntax.y"
                                                                                {Symbol *s = symtab_lookup((yyvsp[0].strval));
                                                                                    if (!s || s->kind != SYM_TYPE || !s->type) {
                                                                                        YYERROR_FMT("Unknown type '%s'", (yyvsp[0].strval));
                                                                                        (yyval.type) = type_error;
                                                                                    } else {
                                                                                        (yyval.type) = s->type;
                                                                                    }
                                                                                }
#line 1863 "syntax.tab.c"
    break;

  case 17: /* standard_type: "char"  */
#line 160 "syntax.y"
                                                                                {(yyval.type) = type_char;}
#line 1869 "syntax.tab.c"
    break;

  case 18: /* standard_type: "int"  */
#line 161 "syntax.y"
                                                                                {(yyval.type) = type_int;}
#line 1875 "syntax.tab.c"
    break;

  case 19: /* standard_type: "float"  */
#line 162 "syntax.y"
                                                                                {(yyval.type) = type_float;}
#line 1881 "syntax.tab.c"
    break;

  case 20: /* standard_type: "string"  */
#line 163 "syntax.y"
                                                                                {(yyval.type) = type_string;}
#line 1887 "syntax.tab.c"
    break;

  case 21: /* standard_type: "void"  */
#line 164 "syntax.y"
                                                                                {(yyval.type) = type_void;}
#line 1893 "syntax.tab.c"
    break;

  case 23: /* listspec: %empty  */
#line 166 "syntax.y"
                                                    {;}
#line 1899 "syntax.tab.c"
    break;

  case 25: /* dims: %empty  */
#line 169 "syntax.y"
                                             {;}
#line 1905 "syntax.tab.c"
    break;

  case 28: /* $@1: %empty  */
#line 173 "syntax.y"
                                             { current_type = (yyvsp[0].type); }
#line 1911 "syntax.tab.c"
    break;

  case 32: /* constdef: "id" dims "assign" init_value  */
#line 178 "syntax.y"
                                                                                {if (!current_type) current_type = type_error;
                                                                                    if (!symtab_insert((yyvsp[-3].strval), SYM_CONST, current_type)) {
                                                                                        YYERROR_FMT("Redeclaration of const '%s'", (yyvsp[-3].strval));
                                                                                    }
                                                                                }
#line 1921 "syntax.tab.c"
    break;

  case 35: /* expression: expression "orop" expression  */
#line 187 "syntax.y"
                                                                                {(yyval.type) = sem_binary_logical((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1927 "syntax.tab.c"
    break;

  case 36: /* expression: expression "andop" expression  */
#line 188 "syntax.y"
                                                                                {(yyval.type) = sem_binary_logical((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1933 "syntax.tab.c"
    break;

  case 37: /* expression: expression "equop" expression  */
#line 189 "syntax.y"
                                                                                {(yyval.type) = sem_binary_equality((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1939 "syntax.tab.c"
    break;

  case 38: /* expression: expression "relop" expression  */
#line 190 "syntax.y"
                                                                                {(yyval.type) = sem_binary_relational((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1945 "syntax.tab.c"
    break;

  case 39: /* expression: expression "addop" expression  */
#line 191 "syntax.y"
                                                                                {(yyval.type) = sem_binary_arith((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1951 "syntax.tab.c"
    break;

  case 40: /* expression: expression "mulop" expression  */
#line 192 "syntax.y"
                                                                                {(yyval.type) = sem_binary_arith((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1957 "syntax.tab.c"
    break;

  case 41: /* expression: "notop" expression  */
#line 193 "syntax.y"
                                                                                { (yyval.type) = sem_unary_not((yyvsp[0].type), yylineno); }
#line 1963 "syntax.tab.c"
    break;

  case 42: /* expression: "addop" expression  */
#line 194 "syntax.y"
                                                                                { (yyval.type) = sem_unary_not((yyvsp[0].type), yylineno); }
#line 1969 "syntax.tab.c"
    break;

  case 43: /* expression: "sizeop" expression  */
#line 195 "syntax.y"
                                                                                { (yyval.type) = type_int; }
#line 1975 "syntax.tab.c"
    break;

  case 44: /* expression: "incdec" variable  */
#line 196 "syntax.y"
                                                                                { (yyval.type) = sem_unary_incdec((yyvsp[0].type), yylineno); }
#line 1981 "syntax.tab.c"
    break;

  case 45: /* expression: variable "incdec"  */
#line 197 "syntax.y"
                                                                                { (yyval.type) = sem_unary_incdec((yyvsp[-1].type), yylineno); }
#line 1987 "syntax.tab.c"
    break;

  case 46: /* expression: variable  */
#line 198 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[0].type);}
#line 1993 "syntax.tab.c"
    break;

  case 47: /* expression: variable "lparen" expression_list "rparen"  */
#line 199 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[-3].type);}
#line 1999 "syntax.tab.c"
    break;

  case 48: /* expression: "length" "lparen" general_expression "rparen"  */
#line 200 "syntax.y"
                                                                                {(yyval.type) = type_int;}
#line 2005 "syntax.tab.c"
    break;

  case 49: /* expression: constant  */
#line 201 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[0].type);}
#line 2011 "syntax.tab.c"
    break;

  case 50: /* expression: "lparen" general_expression "rparen"  */
#line 202 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[-1].type);}
#line 2017 "syntax.tab.c"
    break;

  case 51: /* expression: "lparen" standard_type "rparen"  */
#line 203 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[-1].type);}
#line 2023 "syntax.tab.c"
    break;

  case 52: /* expression: listexpression  */
#line 204 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[0].type);}
#line 2029 "syntax.tab.c"
    break;

  case 53: /* variable: variable "lbrack" general_expression "rbrack"  */
#line 206 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[-3].type);}
#line 2035 "syntax.tab.c"
    break;

  case 54: /* variable: variable "dot" "id"  */
#line 207 "syntax.y"
                                                                                {(yyval.type)= type_error;}
#line 2041 "syntax.tab.c"
    break;

  case 55: /* variable: "listfunc" "lparen" general_expression "rparen"  */
#line 208 "syntax.y"
                                                                                {(yyval.type)= type_error;}
#line 2047 "syntax.tab.c"
    break;

  case 56: /* variable: decltype "id"  */
#line 209 "syntax.y"
                                                                                {(yyval.type) = sem_use_variable((yyvsp[0].strval), yylineno); }
#line 2053 "syntax.tab.c"
    break;

  case 57: /* variable: "this"  */
#line 210 "syntax.y"
                                                                                {(yyval.type)= type_error;}
#line 2059 "syntax.tab.c"
    break;

  case 58: /* general_expression: general_expression "comma" general_expression  */
#line 212 "syntax.y"
                                                                                {(yyval.type) = (yyvsp[0].type);}
#line 2065 "syntax.tab.c"
    break;

  case 59: /* general_expression: assignment  */
#line 213 "syntax.y"
                                                                                {(yyval.type) = (yyvsp[0].type);}
#line 2071 "syntax.tab.c"
    break;

  case 60: /* assignment: variable "assign" assignment  */
#line 215 "syntax.y"
                                                                                {(yyval.type) = sem_check_assignment((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 2077 "syntax.tab.c"
    break;

  case 61: /* assignment: expression  */
#line 216 "syntax.y"
                                                                                {(yyval.type)=type_error;}
#line 2083 "syntax.tab.c"
    break;

  case 62: /* expression_list: general_expression  */
#line 218 "syntax.y"
                                                                                {(yyval.type) = (yyvsp[0].type);}
#line 2089 "syntax.tab.c"
    break;

  case 63: /* expression_list: %empty  */
#line 219 "syntax.y"
                                                                                {(yyval.type) = type_void;}
#line 2095 "syntax.tab.c"
    break;

  case 64: /* constant: "cconst"  */
#line 221 "syntax.y"
                                                                                { (yyval.type) = type_char;   }
#line 2101 "syntax.tab.c"
    break;

  case 65: /* constant: "iconst"  */
#line 222 "syntax.y"
                                                                                { (yyval.type) = type_int;    }
#line 2107 "syntax.tab.c"
    break;

  case 66: /* constant: "fconst"  */
#line 223 "syntax.y"
                                                                                { (yyval.type) = type_float;  }
#line 2113 "syntax.tab.c"
    break;

  case 67: /* constant: "sconst"  */
#line 224 "syntax.y"
                                                                                { (yyval.type) = type_string; }
#line 2119 "syntax.tab.c"
    break;

  case 68: /* listexpression: "lbrack" expression_list "rbrack"  */
#line 227 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[-1].type);}
#line 2125 "syntax.tab.c"
    break;

  case 71: /* enum_declaration: "enum" "id" enum_body "semi"  */
#line 232 "syntax.y"
                                                                                {Type *t = make_type(TYPE_ENUM);
                                                                                    if (!symtab_insert((yyvsp[-2].strval), SYM_TYPE, t)) {
                                                                                        YYERROR_FMT("Redeclaration of enum '%s'", (yyvsp[-2].strval));
                                                                                    }
                                                                                }
#line 2135 "syntax.tab.c"
    break;

  case 73: /* id_list: id_list "comma" "id" initializer  */
#line 239 "syntax.y"
                                                                                {/* enum constants -> ακέραιοι */
                                                                                    if (!symtab_insert((yyvsp[-1].strval), SYM_ENUM_CONST, type_int)) {
                                                                                        YYERROR_FMT("Redeclaration of enum const '%s'", (yyvsp[-1].strval));
                                                                                    }
                                                                                }
#line 2145 "syntax.tab.c"
    break;

  case 74: /* id_list: "id" initializer  */
#line 244 "syntax.y"
                                                                                {if (!symtab_insert((yyvsp[-1].strval), SYM_ENUM_CONST, type_int)) {
                                                                                        YYERROR_FMT("Redeclaration of enum const '%s'", (yyvsp[-1].strval));
                                                                                    }
                                                                                }
#line 2154 "syntax.tab.c"
    break;

  case 76: /* initializer: %empty  */
#line 250 "syntax.y"
                                             {;}
#line 2160 "syntax.tab.c"
    break;

  case 77: /* class_declaration: "class" "id" class_body "semi"  */
#line 252 "syntax.y"
                                                                                {Type *t = make_type(TYPE_CLASS);
                                                                                    if (!symtab_insert((yyvsp[-2].strval), SYM_TYPE, t)) {
                                                                                        YYERROR_FMT("Redeclaration of class '%s'", (yyvsp[-2].strval));
                                                                                    }
                                                                                }
#line 2170 "syntax.tab.c"
    break;

  case 78: /* $@2: %empty  */
#line 258 "syntax.y"
                                   {symtab_enter_scope();}
#line 2176 "syntax.tab.c"
    break;

  case 79: /* class_body: parent $@2 "lbrace" members_methods "rbrace"  */
#line 258 "syntax.y"
                                                                                             { symtab_leave_scope();}
#line 2182 "syntax.tab.c"
    break;

  case 80: /* parent: "colon" "id"  */
#line 259 "syntax.y"
                                                                                {Symbol *base = symtab_lookup((yyvsp[0].strval));
                                                                                    if (!base || base->kind != SYM_TYPE) {
                                                                                        YYERROR_FMT("Unknown base class '%s'", (yyvsp[0].strval));
                                                                                    }
                                                                                }
#line 2192 "syntax.tab.c"
    break;

  case 81: /* parent: %empty  */
#line 264 "syntax.y"
                                             {;}
#line 2198 "syntax.tab.c"
    break;

  case 87: /* access: %empty  */
#line 269 "syntax.y"
                                                                                                        { }
#line 2204 "syntax.tab.c"
    break;

  case 92: /* var_declaration: typename variabledefs "semi"  */
#line 277 "syntax.y"
                                                         { current_type = (yyvsp[-2].type); }
#line 2210 "syntax.tab.c"
    break;

  case 95: /* variabledef: listspec "id" dims  */
#line 285 "syntax.y"
                                                                                {if (!current_type) current_type = type_error;
                                                                                    /* Προς το παρόν αγνοούμε listspec/dims και δηλώνουμε απλό type */
                                                                                    if (!symtab_insert((yyvsp[-1].strval), SYM_VAR, current_type)) {
                                                                                        YYERROR_FMT("Redeclaration of '%s'", (yyvsp[-1].strval));
                                                                                    }
                                                                                }
#line 2221 "syntax.tab.c"
    break;

  case 97: /* $@3: %empty  */
#line 295 "syntax.y"
                            {symtab_enter_scope();}
#line 2227 "syntax.tab.c"
    break;

  case 98: /* union_body: $@3 "lbrace" fields "rbrace"  */
#line 295 "syntax.y"
                                                                                             { symtab_leave_scope();}
#line 2233 "syntax.tab.c"
    break;

  case 103: /* short_func_declaration: short_par_func_header "semi"  */
#line 304 "syntax.y"
                                                                                { symtab_leave_scope();}
#line 2239 "syntax.tab.c"
    break;

  case 104: /* short_func_declaration: nopar_func_header "semi"  */
#line 305 "syntax.y"
                                                                                { symtab_leave_scope();}
#line 2245 "syntax.tab.c"
    break;

  case 106: /* func_header_start: typename listspec "id"  */
#line 311 "syntax.y"
                                                                                {Type *ret = (yyvsp[-2].type);
                                                                                    if (!symtab_insert((yyvsp[0].strval), SYM_FUNC, ret)) {
                                                                                        YYERROR_FMT("Redeclaration of function '%s'", (yyvsp[0].strval));
                                                                                    }
                                                                                    symtab_enter_scope();   /* νέο scope για παραμέτρους+σώμα */
                                                                                }
#line 2256 "syntax.tab.c"
    break;

  case 112: /* union_declaration: "union" "id" union_body "semi"  */
#line 327 "syntax.y"
                                                                                {Type *t = make_type(TYPE_UNION);
                                                                                    if (!symtab_insert((yyvsp[-2].strval), SYM_TYPE, t)) {
                                                                                        YYERROR_FMT("Redeclaration of union '%s'", (yyvsp[-2].strval));
                                                                                    }
                                                                                }
#line 2266 "syntax.tab.c"
    break;

  case 113: /* global_var_declaration: typename init_variabledefs "semi"  */
#line 334 "syntax.y"
                                                              { current_type = (yyvsp[-2].type); }
#line 2272 "syntax.tab.c"
    break;

  case 119: /* full_func_declaration: full_par_func_header "lbrace" decl_statements "rbrace"  */
#line 346 "syntax.y"
                                                                                                        { symtab_leave_scope();}
#line 2278 "syntax.tab.c"
    break;

  case 120: /* full_func_declaration: nopar_class_func_header "lbrace" decl_statements "rbrace"  */
#line 347 "syntax.y"
                                                                                                        { symtab_leave_scope();}
#line 2284 "syntax.tab.c"
    break;

  case 121: /* full_func_declaration: nopar_func_header "lbrace" decl_statements "rbrace"  */
#line 348 "syntax.y"
                                                                                                        { symtab_leave_scope();}
#line 2290 "syntax.tab.c"
    break;

  case 124: /* class_func_header_start: typename listspec func_class "id"  */
#line 353 "syntax.y"
                                                                                {Type *ret = (yyvsp[-3].type);
                                                                                    if (!symtab_insert((yyvsp[0].strval), SYM_FUNC, ret)) {
                                                                                        YYERROR_FMT("Redeclaration of method '%s'", (yyvsp[0].strval));
                                                                                    }
                                                                                    symtab_enter_scope();
                                                                                }
#line 2301 "syntax.tab.c"
    break;

  case 125: /* func_class: "id" "meth"  */
#line 360 "syntax.y"
                                                                                {Symbol *cls = symtab_lookup((yyvsp[-1].strval));
                                                                                    if (!cls || cls->kind != SYM_TYPE) {
                                                                                        YYERROR_FMT("Unknown class type '%s'", (yyvsp[-1].strval));
                                                                                    }
                                                                                }
#line 2311 "syntax.tab.c"
    break;

  case 127: /* parameter_list: typename pass_variabledef  */
#line 367 "syntax.y"
                                                        { current_type = (yyvsp[-1].type); }
#line 2317 "syntax.tab.c"
    break;

  case 129: /* pass_variabledef: "refer" "id"  */
#line 370 "syntax.y"
                                                                                {if (!current_type) current_type = type_error;
                                                                                    if (!symtab_insert((yyvsp[0].strval), SYM_VAR, current_type)) {
                                                                                        YYERROR_FMT("Redeclaration of parameter '%s'", (yyvsp[0].strval));
                                                                                    }
                                                                                }
#line 2327 "syntax.tab.c"
    break;

  case 134: /* decl_statements: %empty  */
#line 381 "syntax.y"
                                             {;}
#line 2333 "syntax.tab.c"
    break;

  case 135: /* $@4: %empty  */
#line 383 "syntax.y"
                                                           { current_type = (yyvsp[0].type); }
#line 2339 "syntax.tab.c"
    break;

  case 137: /* $@5: %empty  */
#line 384 "syntax.y"
                                                { current_type = (yyvsp[0].type); }
#line 2345 "syntax.tab.c"
    break;

  case 140: /* decltype: %empty  */
#line 386 "syntax.y"
                                                      {;}
#line 2351 "syntax.tab.c"
    break;

  case 143: /* statements: statements error "semi"  */
#line 389 "syntax.y"
                                                                                { YYERROR_FMT(" HINT:  error in statement - skipping until ';'"); yyerrok; }
#line 2357 "syntax.tab.c"
    break;

  case 157: /* if_tail: %empty  */
#line 405 "syntax.y"
                                                                     {;}
#line 2363 "syntax.tab.c"
    break;

  case 161: /* optexpr: %empty  */
#line 410 "syntax.y"
                                             {;}
#line 2369 "syntax.tab.c"
    break;

  case 171: /* $@6: %empty  */
#line 424 "syntax.y"
                                     {symtab_enter_scope();}
#line 2375 "syntax.tab.c"
    break;

  case 172: /* comp_statement: "lbrace" $@6 decl_statements "rbrace"  */
#line 424 "syntax.y"
                                                                                         { symtab_leave_scope();}
#line 2381 "syntax.tab.c"
    break;

  case 173: /* main_function: main_header "lbrace" decl_statements "rbrace"  */
#line 425 "syntax.y"
                                                                            { symtab_leave_scope();}
#line 2387 "syntax.tab.c"
    break;

  case 174: /* main_header: "int" "main" "lparen" "rparen"  */
#line 426 "syntax.y"
                                                                            {symtab_enter_scope();}
#line 2393 "syntax.tab.c"
    break;

  case 175: /* main_header: error "main" "lparen" "rparen"  */
#line 427 "syntax.y"
                                                                            {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; symtab_enter_scope();}
#line 2399 "syntax.tab.c"
    break;

  case 176: /* main_header: "int" error "lparen" "rparen"  */
#line 428 "syntax.y"
                                                                            {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; symtab_enter_scope();}
#line 2405 "syntax.tab.c"
    break;

  case 177: /* main_header: "int" "main" error "rparen"  */
#line 429 "syntax.y"
                                                                            {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; symtab_enter_scope();}
#line 2411 "syntax.tab.c"
    break;

  case 178: /* main_header: "int" "main" "lparen" error  */
#line 430 "syntax.y"
                                                                            {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; symtab_enter_scope();}
#line 2417 "syntax.tab.c"
    break;


#line 2421 "syntax.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= T_EOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == T_EOF)
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 432 "syntax.y"


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
