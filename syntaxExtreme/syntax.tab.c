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
  YYSYMBOL_typed_typename = 71,            /* typed_typename  */
  YYSYMBOL_typename = 72,                  /* typename  */
  YYSYMBOL_standard_type = 73,             /* standard_type  */
  YYSYMBOL_listspec = 74,                  /* listspec  */
  YYSYMBOL_dims = 75,                      /* dims  */
  YYSYMBOL_dim = 76,                       /* dim  */
  YYSYMBOL_const_declaration = 77,         /* const_declaration  */
  YYSYMBOL_78_1 = 78,                      /* $@1  */
  YYSYMBOL_constdefs = 79,                 /* constdefs  */
  YYSYMBOL_constdef = 80,                  /* constdef  */
  YYSYMBOL_init_value = 81,                /* init_value  */
  YYSYMBOL_expression = 82,                /* expression  */
  YYSYMBOL_variable = 83,                  /* variable  */
  YYSYMBOL_general_expression = 84,        /* general_expression  */
  YYSYMBOL_assignment = 85,                /* assignment  */
  YYSYMBOL_expression_list = 86,           /* expression_list  */
  YYSYMBOL_constant = 87,                  /* constant  */
  YYSYMBOL_listexpression = 88,            /* listexpression  */
  YYSYMBOL_list_elements = 89,             /* list_elements  */
  YYSYMBOL_init_values = 90,               /* init_values  */
  YYSYMBOL_enum_declaration = 91,          /* enum_declaration  */
  YYSYMBOL_enum_body = 92,                 /* enum_body  */
  YYSYMBOL_id_list = 93,                   /* id_list  */
  YYSYMBOL_initializer = 94,               /* initializer  */
  YYSYMBOL_class_declaration = 95,         /* class_declaration  */
  YYSYMBOL_class_body = 96,                /* class_body  */
  YYSYMBOL_97_2 = 97,                      /* $@2  */
  YYSYMBOL_parent = 98,                    /* parent  */
  YYSYMBOL_members_methods = 99,           /* members_methods  */
  YYSYMBOL_access = 100,                   /* access  */
  YYSYMBOL_member_or_method = 101,         /* member_or_method  */
  YYSYMBOL_member = 102,                   /* member  */
  YYSYMBOL_var_declaration = 103,          /* var_declaration  */
  YYSYMBOL_variabledefs = 104,             /* variabledefs  */
  YYSYMBOL_variabledef = 105,              /* variabledef  */
  YYSYMBOL_anonymous_union = 106,          /* anonymous_union  */
  YYSYMBOL_union_body = 107,               /* union_body  */
  YYSYMBOL_108_3 = 108,                    /* $@3  */
  YYSYMBOL_fields = 109,                   /* fields  */
  YYSYMBOL_field = 110,                    /* field  */
  YYSYMBOL_method = 111,                   /* method  */
  YYSYMBOL_short_func_declaration = 112,   /* short_func_declaration  */
  YYSYMBOL_short_par_func_header = 113,    /* short_par_func_header  */
  YYSYMBOL_func_header_start = 114,        /* func_header_start  */
  YYSYMBOL_parameter_types = 115,          /* parameter_types  */
  YYSYMBOL_pass_list_dims = 116,           /* pass_list_dims  */
  YYSYMBOL_nopar_func_header = 117,        /* nopar_func_header  */
  YYSYMBOL_union_declaration = 118,        /* union_declaration  */
  YYSYMBOL_global_var_declaration = 119,   /* global_var_declaration  */
  YYSYMBOL_init_variabledefs = 120,        /* init_variabledefs  */
  YYSYMBOL_init_variabledef = 121,         /* init_variabledef  */
  YYSYMBOL_func_declaration = 122,         /* func_declaration  */
  YYSYMBOL_full_func_declaration = 123,    /* full_func_declaration  */
  YYSYMBOL_full_par_func_header = 124,     /* full_par_func_header  */
  YYSYMBOL_class_func_header_start = 125,  /* class_func_header_start  */
  YYSYMBOL_func_class = 126,               /* func_class  */
  YYSYMBOL_parameter_list = 127,           /* parameter_list  */
  YYSYMBOL_pass_variabledef = 128,         /* pass_variabledef  */
  YYSYMBOL_nopar_class_func_header = 129,  /* nopar_class_func_header  */
  YYSYMBOL_decl_statements = 130,          /* decl_statements  */
  YYSYMBOL_declarations = 131,             /* declarations  */
  YYSYMBOL_132_4 = 132,                    /* $@4  */
  YYSYMBOL_133_5 = 133,                    /* $@5  */
  YYSYMBOL_decltype = 134,                 /* decltype  */
  YYSYMBOL_statements = 135,               /* statements  */
  YYSYMBOL_statement = 136,                /* statement  */
  YYSYMBOL_expression_statement = 137,     /* expression_statement  */
  YYSYMBOL_if_statement = 138,             /* if_statement  */
  YYSYMBOL_if_tail = 139,                  /* if_tail  */
  YYSYMBOL_while_statement = 140,          /* while_statement  */
  YYSYMBOL_for_statement = 141,            /* for_statement  */
  YYSYMBOL_optexpr = 142,                  /* optexpr  */
  YYSYMBOL_return_statement = 143,         /* return_statement  */
  YYSYMBOL_io_statement = 144,             /* io_statement  */
  YYSYMBOL_in_list = 145,                  /* in_list  */
  YYSYMBOL_in_item = 146,                  /* in_item  */
  YYSYMBOL_out_list = 147,                 /* out_list  */
  YYSYMBOL_out_item = 148,                 /* out_item  */
  YYSYMBOL_comp_statement = 149,           /* comp_statement  */
  YYSYMBOL_150_6 = 150,                    /* $@6  */
  YYSYMBOL_main_function = 151,            /* main_function  */
  YYSYMBOL_main_header = 152               /* main_header  */
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
#define YYLAST   615

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  87
/* YYNRULES -- Number of rules.  */
#define YYNRULES  181
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  348

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
       0,   129,   129,   131,   132,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   144,   152,   159,   160,   169,   170,
     171,   172,   173,   175,   176,   178,   179,   181,   181,   183,
     183,   185,   186,   188,   194,   195,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   216,   217,   218,   219,   220,   222,
     223,   225,   226,   228,   229,   231,   232,   233,   234,   237,
     239,   240,   242,   243,   245,   251,   252,   257,   262,   263,
     265,   271,   271,   272,   277,   279,   280,   282,   282,   282,
     282,   283,   284,   286,   287,   290,   293,   294,   297,   308,
     310,   310,   312,   313,   315,   317,   319,   320,   323,   326,
     334,   335,   337,   338,   340,   342,   349,   353,   354,   356,
     358,   359,   361,   362,   363,   365,   366,   368,   375,   381,
     382,   384,   385,   391,   393,   394,   395,   396,   398,   398,
     399,   399,   401,   401,   402,   403,   404,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   417,   418,   419,
     420,   422,   423,   424,   425,   427,   428,   429,   431,   432,
     434,   435,   436,   438,   439,   439,   440,   441,   442,   443,
     444,   445
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

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-232)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-165)

#define yytable_value_is_error(Yyn) \
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
       0,     1,     2,    16,    17,   219,   220,    20,    49,   233,
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
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

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
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

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
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
#line 132 "syntax.y"
                                             {;}
#line 1826 "syntax.tab.c"
    break;

  case 12: /* global_declaration: error "semi"  */
#line 141 "syntax.y"
                                                                                {yyerror(" HINT: syntax error in global declaration\n"); yyerrok;}
#line 1832 "syntax.tab.c"
    break;

  case 13: /* global_declaration: error "rbrace"  */
#line 142 "syntax.y"
                                                                                {yyerror(" HINT: in global declaration\n"); yyerrok; }
#line 1838 "syntax.tab.c"
    break;

  case 14: /* typedef_declaration: "typedef" typename listspec "id" dims "semi"  */
#line 144 "syntax.y"
                                                                                {
                                                                                    /* αγνοούμε προς το παρόν listspec/dims για σύνθετους, κρατάμε base type */
                                                                                    if (!symtab_insert((yyvsp[-2].strval), SYM_TYPE, (yyvsp[-4].type))) {
                                                                                        YYERROR_FMT("Redeclaration of typedef '%s'", (yyvsp[-2].strval));
                                                                                    }
                                                                                }
#line 1849 "syntax.tab.c"
    break;

  case 15: /* typed_typename: typename  */
#line 153 "syntax.y"
      {
          current_type = (yyvsp[0].type);  /* εδώ κάνουμε το side-effect */
          (yyval.type) = (yyvsp[0].type);            /* και περνάμε το Type* προς τα κάτω αν χρειαστεί */
      }
#line 1858 "syntax.tab.c"
    break;

  case 17: /* typename: "id"  */
#line 160 "syntax.y"
                                                                                {Symbol *s = symtab_lookup((yyvsp[0].strval));
                                                                                    if (!s || s->kind != SYM_TYPE || !s->type) {
                                                                                        YYERROR_FMT("Unknown type '%s'", (yyvsp[0].strval));
                                                                                        (yyval.type) = type_error;
                                                                                    } else {
                                                                                        (yyval.type) = s->type;
                                                                                    }
                                                                                }
#line 1871 "syntax.tab.c"
    break;

  case 18: /* standard_type: "char"  */
#line 169 "syntax.y"
                                                                                {(yyval.type) = type_char;}
#line 1877 "syntax.tab.c"
    break;

  case 19: /* standard_type: "int"  */
#line 170 "syntax.y"
                                                                                {(yyval.type) = type_int;}
#line 1883 "syntax.tab.c"
    break;

  case 20: /* standard_type: "float"  */
#line 171 "syntax.y"
                                                                                {(yyval.type) = type_float;}
#line 1889 "syntax.tab.c"
    break;

  case 21: /* standard_type: "string"  */
#line 172 "syntax.y"
                                                                                {(yyval.type) = type_string;}
#line 1895 "syntax.tab.c"
    break;

  case 22: /* standard_type: "void"  */
#line 173 "syntax.y"
                                                                                {(yyval.type) = type_void;}
#line 1901 "syntax.tab.c"
    break;

  case 23: /* listspec: "list"  */
#line 175 "syntax.y"
                                                                                {(yyval.intval) = 1;}
#line 1907 "syntax.tab.c"
    break;

  case 24: /* listspec: %empty  */
#line 176 "syntax.y"
                                                                                {(yyval.intval) = 0;}
#line 1913 "syntax.tab.c"
    break;

  case 26: /* dims: %empty  */
#line 179 "syntax.y"
                                             {;}
#line 1919 "syntax.tab.c"
    break;

  case 29: /* $@1: %empty  */
#line 183 "syntax.y"
                                             { current_type = (yyvsp[0].type); }
#line 1925 "syntax.tab.c"
    break;

  case 33: /* constdef: "id" dims "assign" init_value  */
#line 188 "syntax.y"
                                                                                {if (!current_type) current_type = type_error;
                                                                                    if (!symtab_insert((yyvsp[-3].strval), SYM_CONST, current_type)) {
                                                                                        YYERROR_FMT("Redeclaration of const '%s'", (yyvsp[-3].strval));
                                                                                    }
                                                                                }
#line 1935 "syntax.tab.c"
    break;

  case 36: /* expression: expression "orop" expression  */
#line 197 "syntax.y"
                                                                                {(yyval.type) = sem_binary_logical((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1941 "syntax.tab.c"
    break;

  case 37: /* expression: expression "andop" expression  */
#line 198 "syntax.y"
                                                                                {(yyval.type) = sem_binary_logical((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1947 "syntax.tab.c"
    break;

  case 38: /* expression: expression "equop" expression  */
#line 199 "syntax.y"
                                                                                {(yyval.type) = sem_binary_equality((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1953 "syntax.tab.c"
    break;

  case 39: /* expression: expression "relop" expression  */
#line 200 "syntax.y"
                                                                                {(yyval.type) = sem_binary_relational((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1959 "syntax.tab.c"
    break;

  case 40: /* expression: expression "addop" expression  */
#line 201 "syntax.y"
                                                                                {(yyval.type) = sem_binary_arith((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1965 "syntax.tab.c"
    break;

  case 41: /* expression: expression "mulop" expression  */
#line 202 "syntax.y"
                                                                                {(yyval.type) = sem_binary_arith((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1971 "syntax.tab.c"
    break;

  case 42: /* expression: "notop" expression  */
#line 203 "syntax.y"
                                                                                { (yyval.type) = sem_unary_not((yyvsp[0].type), yylineno); }
#line 1977 "syntax.tab.c"
    break;

  case 43: /* expression: "addop" expression  */
#line 204 "syntax.y"
                                                                                { (yyval.type) = sem_unary_not((yyvsp[0].type), yylineno); }
#line 1983 "syntax.tab.c"
    break;

  case 44: /* expression: "sizeop" expression  */
#line 205 "syntax.y"
                                                                                { (yyval.type) = type_int; }
#line 1989 "syntax.tab.c"
    break;

  case 45: /* expression: "incdec" variable  */
#line 206 "syntax.y"
                                                                                { (yyval.type) = sem_unary_incdec((yyvsp[0].type), yylineno); }
#line 1995 "syntax.tab.c"
    break;

  case 46: /* expression: variable "incdec"  */
#line 207 "syntax.y"
                                                                                { (yyval.type) = sem_unary_incdec((yyvsp[-1].type), yylineno); }
#line 2001 "syntax.tab.c"
    break;

  case 47: /* expression: variable  */
#line 208 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[0].type);}
#line 2007 "syntax.tab.c"
    break;

  case 48: /* expression: variable "lparen" expression_list "rparen"  */
#line 209 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[-3].type);}
#line 2013 "syntax.tab.c"
    break;

  case 49: /* expression: "length" "lparen" general_expression "rparen"  */
#line 210 "syntax.y"
                                                                                {(yyval.type) = type_int;}
#line 2019 "syntax.tab.c"
    break;

  case 50: /* expression: constant  */
#line 211 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[0].type);}
#line 2025 "syntax.tab.c"
    break;

  case 51: /* expression: "lparen" general_expression "rparen"  */
#line 212 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[-1].type);}
#line 2031 "syntax.tab.c"
    break;

  case 52: /* expression: "lparen" standard_type "rparen"  */
#line 213 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[-1].type);}
#line 2037 "syntax.tab.c"
    break;

  case 53: /* expression: listexpression  */
#line 214 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[0].type);}
#line 2043 "syntax.tab.c"
    break;

  case 54: /* variable: variable "lbrack" general_expression "rbrack"  */
#line 216 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[-3].type);}
#line 2049 "syntax.tab.c"
    break;

  case 55: /* variable: variable "dot" "id"  */
#line 217 "syntax.y"
                                                                                {(yyval.type)= type_error;}
#line 2055 "syntax.tab.c"
    break;

  case 56: /* variable: "listfunc" "lparen" general_expression "rparen"  */
#line 218 "syntax.y"
                                                                                {(yyval.type)= type_error;}
#line 2061 "syntax.tab.c"
    break;

  case 57: /* variable: decltype "id"  */
#line 219 "syntax.y"
                                                                                {(yyval.type) = sem_use_variable((yyvsp[0].strval), yylineno); }
#line 2067 "syntax.tab.c"
    break;

  case 58: /* variable: "this"  */
#line 220 "syntax.y"
                                                                                {(yyval.type)= type_error;}
#line 2073 "syntax.tab.c"
    break;

  case 59: /* general_expression: general_expression "comma" general_expression  */
#line 222 "syntax.y"
                                                                                {(yyval.type) = (yyvsp[0].type);}
#line 2079 "syntax.tab.c"
    break;

  case 60: /* general_expression: assignment  */
#line 223 "syntax.y"
                                                                                {(yyval.type) = (yyvsp[0].type);}
#line 2085 "syntax.tab.c"
    break;

  case 61: /* assignment: variable "assign" assignment  */
#line 225 "syntax.y"
                                                                                {(yyval.type) = sem_check_assignment((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 2091 "syntax.tab.c"
    break;

  case 62: /* assignment: expression  */
#line 226 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[0].type);}
#line 2097 "syntax.tab.c"
    break;

  case 63: /* expression_list: general_expression  */
#line 228 "syntax.y"
                                                                                {(yyval.type) = (yyvsp[0].type);}
#line 2103 "syntax.tab.c"
    break;

  case 64: /* expression_list: %empty  */
#line 229 "syntax.y"
                                                                                {(yyval.type) = type_void;}
#line 2109 "syntax.tab.c"
    break;

  case 65: /* constant: "cconst"  */
#line 231 "syntax.y"
                                                                                { (yyval.type) = type_char;   }
#line 2115 "syntax.tab.c"
    break;

  case 66: /* constant: "iconst"  */
#line 232 "syntax.y"
                                                                                { (yyval.type) = type_int;    }
#line 2121 "syntax.tab.c"
    break;

  case 67: /* constant: "fconst"  */
#line 233 "syntax.y"
                                                                                { (yyval.type) = type_float;  }
#line 2127 "syntax.tab.c"
    break;

  case 68: /* constant: "sconst"  */
#line 234 "syntax.y"
                                                                                { (yyval.type) = type_string; }
#line 2133 "syntax.tab.c"
    break;

  case 69: /* listexpression: "lbrack" list_elements "rbrack"  */
#line 237 "syntax.y"
                                                                              {(yyval.type) = sem_make_list_type((yyvsp[-1].type), yylineno);}
#line 2139 "syntax.tab.c"
    break;

  case 70: /* list_elements: list_elements "comma" assignment  */
#line 239 "syntax.y"
                                                                                { (yyval.type) = sem_find_list_element_type((yyvsp[-2].type), (yyvsp[0].type), yylineno); }
#line 2145 "syntax.tab.c"
    break;

  case 71: /* list_elements: assignment  */
#line 240 "syntax.y"
                                                                                { (yyval.type) = (yyvsp[0].type); }
#line 2151 "syntax.tab.c"
    break;

  case 74: /* enum_declaration: "enum" "id" enum_body "semi"  */
#line 245 "syntax.y"
                                                                                {Type *t = make_simple_type(TYPE_ENUM);
                                                                                    if (!symtab_insert((yyvsp[-2].strval), SYM_TYPE, t)) {
                                                                                        YYERROR_FMT("Redeclaration of enum '%s'", (yyvsp[-2].strval));
                                                                                    }
                                                                                }
#line 2161 "syntax.tab.c"
    break;

  case 76: /* id_list: id_list "comma" "id" initializer  */
#line 252 "syntax.y"
                                                                                {/* enum constants -> ακέραιοι */
                                                                                    if (!symtab_insert((yyvsp[-1].strval), SYM_ENUM_CONST, type_int)) {
                                                                                        YYERROR_FMT("Redeclaration of enum const '%s'", (yyvsp[-1].strval));
                                                                                    }
                                                                                }
#line 2171 "syntax.tab.c"
    break;

  case 77: /* id_list: "id" initializer  */
#line 257 "syntax.y"
                                                                                {if (!symtab_insert((yyvsp[-1].strval), SYM_ENUM_CONST, type_int)) {
                                                                                        YYERROR_FMT("Redeclaration of enum const '%s'", (yyvsp[-1].strval));
                                                                                    }
                                                                                }
#line 2180 "syntax.tab.c"
    break;

  case 79: /* initializer: %empty  */
#line 263 "syntax.y"
                                             {;}
#line 2186 "syntax.tab.c"
    break;

  case 80: /* class_declaration: "class" "id" class_body "semi"  */
#line 265 "syntax.y"
                                                                                {Type *t = make_simple_type(TYPE_CLASS);
                                                                                    if (!symtab_insert((yyvsp[-2].strval), SYM_TYPE, t)) {
                                                                                        YYERROR_FMT("Redeclaration of class '%s'", (yyvsp[-2].strval));
                                                                                    }
                                                                                }
#line 2196 "syntax.tab.c"
    break;

  case 81: /* $@2: %empty  */
#line 271 "syntax.y"
                                   {symtab_enter_scope();}
#line 2202 "syntax.tab.c"
    break;

  case 82: /* class_body: parent $@2 "lbrace" members_methods "rbrace"  */
#line 271 "syntax.y"
                                                                                             { symtab_leave_scope();}
#line 2208 "syntax.tab.c"
    break;

  case 83: /* parent: "colon" "id"  */
#line 272 "syntax.y"
                                                                                {Symbol *base = symtab_lookup((yyvsp[0].strval));
                                                                                    if (!base || base->kind != SYM_TYPE) {
                                                                                        YYERROR_FMT("Unknown base class '%s'", (yyvsp[0].strval));
                                                                                    }
                                                                                }
#line 2218 "syntax.tab.c"
    break;

  case 84: /* parent: %empty  */
#line 277 "syntax.y"
                                             {;}
#line 2224 "syntax.tab.c"
    break;

  case 90: /* access: %empty  */
#line 282 "syntax.y"
                                                                                                        { }
#line 2230 "syntax.tab.c"
    break;

  case 98: /* variabledef: listspec "id" dims  */
#line 297 "syntax.y"
                                                                                {if (!current_type) current_type = type_error;
                                                                                    Type *t = current_type;
                                                                                    if ((yyvsp[-2].intval)) {  /* αν listspec == 1 → είναι λίστα */
                                                                                        t = sem_make_list_type(current_type, yylineno);
                                                                                    }
                                                                                    if (!symtab_insert((yyvsp[-1].strval), SYM_VAR, t)) {
                                                                                        YYERROR_FMT("Redeclaration of '%s'", (yyvsp[-1].strval));
                                                                                    }
                                                                                }
#line 2244 "syntax.tab.c"
    break;

  case 100: /* $@3: %empty  */
#line 310 "syntax.y"
                            {symtab_enter_scope();}
#line 2250 "syntax.tab.c"
    break;

  case 101: /* union_body: $@3 "lbrace" fields "rbrace"  */
#line 310 "syntax.y"
                                                                                             { symtab_leave_scope();}
#line 2256 "syntax.tab.c"
    break;

  case 106: /* short_func_declaration: short_par_func_header "semi"  */
#line 319 "syntax.y"
                                                                                { symtab_leave_scope();}
#line 2262 "syntax.tab.c"
    break;

  case 107: /* short_func_declaration: nopar_func_header "semi"  */
#line 320 "syntax.y"
                                                                                { symtab_leave_scope();}
#line 2268 "syntax.tab.c"
    break;

  case 109: /* func_header_start: typename listspec "id"  */
#line 326 "syntax.y"
                                                                                {Type *ret = (yyvsp[-2].type);
                                                                                    if (!symtab_insert((yyvsp[0].strval), SYM_FUNC, ret)) {
                                                                                        YYERROR_FMT("Redeclaration of function '%s'", (yyvsp[0].strval));
                                                                                    }
                                                                                    symtab_enter_scope();   /* νέο scope για παραμέτρους+σώμα */
                                                                                }
#line 2279 "syntax.tab.c"
    break;

  case 115: /* union_declaration: "union" "id" union_body "semi"  */
#line 342 "syntax.y"
                                                                                {Type *t = make_simple_type(TYPE_UNION);
                                                                                    if (!symtab_insert((yyvsp[-2].strval), SYM_TYPE, t)) {
                                                                                        YYERROR_FMT("Redeclaration of union '%s'", (yyvsp[-2].strval));
                                                                                    }
                                                                                }
#line 2289 "syntax.tab.c"
    break;

  case 122: /* full_func_declaration: full_par_func_header "lbrace" decl_statements "rbrace"  */
#line 361 "syntax.y"
                                                                                                        { symtab_leave_scope();}
#line 2295 "syntax.tab.c"
    break;

  case 123: /* full_func_declaration: nopar_class_func_header "lbrace" decl_statements "rbrace"  */
#line 362 "syntax.y"
                                                                                                        { symtab_leave_scope();}
#line 2301 "syntax.tab.c"
    break;

  case 124: /* full_func_declaration: nopar_func_header "lbrace" decl_statements "rbrace"  */
#line 363 "syntax.y"
                                                                                                        { symtab_leave_scope();}
#line 2307 "syntax.tab.c"
    break;

  case 127: /* class_func_header_start: typename listspec func_class "id"  */
#line 368 "syntax.y"
                                                                                {Type *ret = (yyvsp[-3].type);
                                                                                    if (!symtab_insert((yyvsp[0].strval), SYM_FUNC, ret)) {
                                                                                        YYERROR_FMT("Redeclaration of method '%s'", (yyvsp[0].strval));
                                                                                    }
                                                                                    symtab_enter_scope();
                                                                                }
#line 2318 "syntax.tab.c"
    break;

  case 128: /* func_class: "id" "meth"  */
#line 375 "syntax.y"
                                                                                {Symbol *cls = symtab_lookup((yyvsp[-1].strval));
                                                                                    if (!cls || cls->kind != SYM_TYPE) {
                                                                                        YYERROR_FMT("Unknown class type '%s'", (yyvsp[-1].strval));
                                                                                    }
                                                                                }
#line 2328 "syntax.tab.c"
    break;

  case 130: /* parameter_list: typename pass_variabledef  */
#line 382 "syntax.y"
                                                        { current_type = (yyvsp[-1].type); }
#line 2334 "syntax.tab.c"
    break;

  case 132: /* pass_variabledef: "refer" "id"  */
#line 385 "syntax.y"
                                                                                {if (!current_type) current_type = type_error;
                                                                                    if (!symtab_insert((yyvsp[0].strval), SYM_VAR, current_type)) {
                                                                                        YYERROR_FMT("Redeclaration of parameter '%s'", (yyvsp[0].strval));
                                                                                    }
                                                                                }
#line 2344 "syntax.tab.c"
    break;

  case 137: /* decl_statements: %empty  */
#line 396 "syntax.y"
                                             {;}
#line 2350 "syntax.tab.c"
    break;

  case 138: /* $@4: %empty  */
#line 398 "syntax.y"
                                                           { current_type = (yyvsp[0].type); }
#line 2356 "syntax.tab.c"
    break;

  case 140: /* $@5: %empty  */
#line 399 "syntax.y"
                                                { current_type = (yyvsp[0].type); }
#line 2362 "syntax.tab.c"
    break;

  case 143: /* decltype: %empty  */
#line 401 "syntax.y"
                                                      {;}
#line 2368 "syntax.tab.c"
    break;

  case 146: /* statements: statements error "semi"  */
#line 404 "syntax.y"
                                                                                { YYERROR_FMT(" HINT:  error in statement - skipping until ';'"); yyerrok; }
#line 2374 "syntax.tab.c"
    break;

  case 160: /* if_tail: %empty  */
#line 420 "syntax.y"
                                                                     {;}
#line 2380 "syntax.tab.c"
    break;

  case 164: /* optexpr: %empty  */
#line 425 "syntax.y"
                                             {;}
#line 2386 "syntax.tab.c"
    break;

  case 174: /* $@6: %empty  */
#line 439 "syntax.y"
                                     {symtab_enter_scope();}
#line 2392 "syntax.tab.c"
    break;

  case 175: /* comp_statement: "lbrace" $@6 decl_statements "rbrace"  */
#line 439 "syntax.y"
                                                                                         { symtab_leave_scope();}
#line 2398 "syntax.tab.c"
    break;

  case 176: /* main_function: main_header "lbrace" decl_statements "rbrace"  */
#line 440 "syntax.y"
                                                                            { symtab_leave_scope();}
#line 2404 "syntax.tab.c"
    break;

  case 177: /* main_header: "int" "main" "lparen" "rparen"  */
#line 441 "syntax.y"
                                                                            {symtab_enter_scope();}
#line 2410 "syntax.tab.c"
    break;

  case 178: /* main_header: error "main" "lparen" "rparen"  */
#line 442 "syntax.y"
                                                                            {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; symtab_enter_scope();}
#line 2416 "syntax.tab.c"
    break;

  case 179: /* main_header: "int" error "lparen" "rparen"  */
#line 443 "syntax.y"
                                                                            {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; symtab_enter_scope();}
#line 2422 "syntax.tab.c"
    break;

  case 180: /* main_header: "int" "main" error "rparen"  */
#line 444 "syntax.y"
                                                                            {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; symtab_enter_scope();}
#line 2428 "syntax.tab.c"
    break;

  case 181: /* main_header: "int" "main" "lparen" error  */
#line 445 "syntax.y"
                                                                            {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; symtab_enter_scope();}
#line 2434 "syntax.tab.c"
    break;


#line 2438 "syntax.tab.c"

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

#line 447 "syntax.y"


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
