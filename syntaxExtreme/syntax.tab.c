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
  YYSYMBOL_type_with_list = 71,            /* type_with_list  */
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
#define YYLAST   643

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  87
/* YYNRULES -- Number of rules.  */
#define YYNRULES  181
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  344

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
     139,   140,   141,   142,   144,   151,   162,   163,   172,   173,
     174,   175,   176,   178,   179,   181,   182,   184,   185,   187,
     187,   189,   190,   192,   198,   199,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   220,   221,   222,   223,   224,   226,
     227,   229,   230,   232,   233,   235,   236,   237,   238,   241,
     243,   244,   246,   247,   249,   255,   256,   261,   266,   267,
     269,   275,   275,   276,   281,   283,   284,   286,   286,   286,
     286,   287,   288,   290,   291,   294,   297,   298,   301,   311,
     313,   313,   315,   316,   318,   320,   322,   323,   326,   329,
     337,   338,   340,   341,   343,   345,   352,   356,   357,   359,
     361,   362,   364,   365,   366,   368,   369,   371,   378,   384,
     385,   387,   388,   394,   396,   397,   398,   399,   401,   401,
     402,   402,   404,   404,   405,   406,   407,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   420,   421,   422,
     423,   425,   426,   427,   428,   430,   431,   432,   434,   435,
     437,   438,   439,   441,   442,   442,   443,   444,   445,   446,
     447,   448
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
  "typedef_declaration", "type_with_list", "typename", "standard_type",
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

#define YYPACT_NINF (-247)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-165)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -247,    49,   600,  -247,    11,   205,  -247,    79,  -247,  -247,
     205,    52,  -247,    76,    89,  -247,  -247,  -247,   131,   119,
    -247,  -247,  -247,  -247,  -247,   127,   138,    98,  -247,  -247,
    -247,  -247,   134,   207,   137,  -247,   221,   234,  -247,  -247,
    -247,   119,   235,    12,  -247,   149,  -247,   233,    81,   239,
     166,  -247,   262,  -247,  -247,  -247,    57,  -247,   367,   367,
      68,   367,   367,   248,   278,   264,   265,     8,   284,   285,
     268,  -247,   274,   269,   295,   279,  -247,   276,   475,  -247,
    -247,   301,  -247,  -247,    23,   145,   147,  -247,   289,   290,
     293,   294,   304,   143,   305,   282,   292,  -247,  -247,  -247,
    -247,  -247,   548,   548,     2,   548,   307,   330,  -247,   548,
    -247,   308,   106,   181,  -247,  -247,  -247,   298,   408,   613,
     226,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,   299,
    -247,    36,   155,   300,   302,  -247,  -247,  -247,  -247,  -247,
    -247,  -247,   208,  -247,  -247,  -247,   306,  -247,   205,   239,
     108,  -247,    80,  -247,   475,  -247,   308,   179,   331,  -247,
    -247,   337,  -247,  -247,  -247,  -247,  -247,   205,  -247,   205,
    -247,  -247,   548,   548,   143,   317,   320,   548,     2,   548,
     328,  -247,    67,  -247,   548,   324,   156,  -247,    86,   367,
     548,   548,   548,   548,   548,   548,  -247,   501,   348,   548,
     548,  -247,   548,  -247,   613,   275,   349,  -247,   333,  -247,
    -247,   337,  -247,  -247,  -247,    -2,   214,  -247,   284,   231,
     301,  -247,    20,  -247,  -247,   350,  -247,   340,  -247,  -247,
     112,  -247,  -247,   276,    21,    36,   165,   174,   334,  -247,
     183,    67,   -17,  -247,   317,    -3,  -247,   188,  -247,  -247,
     548,  -247,   339,    62,   141,   223,   196,   328,  -247,   317,
     352,  -247,  -247,   116,  -247,  -247,   301,  -247,  -247,   475,
    -247,   335,   345,   351,    18,   139,   228,  -247,  -247,  -247,
     239,  -247,   475,  -247,  -247,  -247,  -247,   449,   449,   143,
    -247,  -247,     2,  -247,   548,  -247,  -247,  -247,  -247,  -247,
     301,   236,  -247,  -247,  -247,  -247,  -247,   139,  -247,   375,
    -247,  -247,  -247,  -247,  -247,  -247,   359,   358,  -247,   301,
    -247,  -247,   388,  -247,   366,  -247,  -247,   237,  -247,  -247,
     368,   371,    57,  -247,   449,  -247,   524,  -247,  -247,    21,
    -247,   372,   449,  -247
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,     0,     0,    18,     0,    20,    21,
       0,     0,    22,     0,     0,    17,     3,     5,     0,    24,
      16,     6,     7,     8,   120,     0,     0,     0,     9,    10,
      11,   121,     0,     0,     0,     2,     0,     0,    12,    13,
      19,    24,     0,     0,    29,    84,   100,     0,    26,    79,
       0,   118,     0,    23,    15,   106,     0,   107,   143,   143,
       0,   143,   143,     0,     0,     0,     0,     0,     0,     0,
       0,    81,     0,     0,     0,     0,   128,    98,   143,   119,
     116,     0,   127,   114,    24,     0,     0,   142,     0,     0,
       0,     0,     0,   143,     0,     0,     0,    58,    66,    67,
      68,    65,   143,   143,   143,   143,     0,   143,   156,   143,
     174,    62,    47,     0,    60,    50,    53,     0,   143,     0,
       0,   145,   147,   148,   149,   150,   151,   152,   153,     0,
     133,     0,     0,     0,     0,   178,    26,   179,   180,   181,
     177,    26,     0,    32,    83,    80,     0,   115,     0,    79,
       0,    74,     0,    25,   143,    78,    34,    47,     0,    26,
     117,   112,    26,   131,   111,   130,   108,     0,   126,     0,
     154,   155,   143,   143,   143,   163,     0,   143,   143,   143,
      43,    42,    45,    44,   143,     0,     0,    71,     0,   143,
     143,   143,   143,   143,   143,   143,    46,    64,     0,   143,
     143,   157,   143,   124,     0,     0,    57,   140,     0,   144,
     122,     0,   125,   123,   176,     0,     0,    30,     0,    90,
       0,   104,     0,   103,    77,     0,    75,     0,    28,    73,
       0,    57,   132,   113,    24,     0,     0,     0,     0,   165,
       0,   170,     0,   169,   173,     0,   172,     0,    52,    51,
     143,    69,     0,    36,    37,    38,    39,    40,    41,    63,
       0,    55,    61,     0,    59,   138,     0,   146,    14,   143,
      31,     0,     0,     0,    90,     0,     0,    97,   101,   102,
      79,    27,   143,    35,   112,   110,   129,   143,   143,   143,
      49,   166,   143,   167,   143,    56,    70,   175,    48,    54,
       0,     0,    33,    87,    88,    89,    82,     0,   100,     0,
      86,    91,    93,    94,    92,   105,     0,     0,    95,     0,
      76,    72,   160,   161,     0,   168,   171,     0,   141,    85,
       0,    26,     0,    96,   143,   158,   143,   139,    99,    24,
     159,     0,   143,   162
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -247,  -247,  -247,  -247,  -247,    -1,    -5,   312,    26,   -42,
    -247,  -247,  -247,  -247,   211,  -131,   -61,   -68,   -89,  -102,
    -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -141,  -247,
    -247,  -247,  -247,  -247,   162,   132,  -247,  -218,  -246,   -16,
    -247,   115,  -247,  -247,   216,  -247,   439,  -247,   443,  -247,
     212,   445,  -247,  -247,  -247,   369,  -247,  -247,  -247,  -247,
    -247,   396,   213,  -247,   -40,  -247,  -247,  -247,   -47,   341,
    -114,  -247,  -247,  -247,  -247,  -247,  -171,  -247,  -247,  -247,
     168,  -247,   164,  -247,  -247,  -247,  -247
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,    16,    17,   220,    19,    20,   162,    77,
     153,    21,    68,   142,   143,   155,   111,   112,   113,   114,
     260,   115,   116,   188,   230,    22,    75,   150,    79,    23,
      70,   146,    71,   274,   275,   310,   311,   221,   276,   277,
     313,    72,    73,   222,   223,   314,   315,    25,   316,    85,
     164,   317,    28,    29,    50,    51,    30,    31,    32,    33,
      52,    86,   165,    34,   117,   118,   300,   266,   158,   120,
     121,   122,   123,   335,   124,   125,   176,   126,   127,   242,
     243,   245,   246,   128,   189,    35,    36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,    18,    49,   238,   175,    44,   209,   187,   224,   139,
     157,   119,   119,    66,   119,   119,    87,   156,   186,   129,
     301,   133,   134,   229,     6,    40,     8,     9,   271,   272,
     273,    97,   291,    12,   157,   157,   182,   157,    53,    37,
      53,   180,   181,   292,   183,    54,   293,   268,   106,     3,
      15,    84,   152,   159,   327,   131,   140,   312,   294,    67,
      38,     6,    40,     8,     9,    49,   159,    64,   163,    39,
      12,   204,     6,    40,     8,     9,   306,   284,   278,   161,
      42,    12,    45,   236,   237,   175,   157,    15,   240,   312,
     244,   209,   211,   156,   215,   247,   -19,   262,    15,   216,
     191,   192,   193,   194,   195,    83,    46,    43,   259,   -19,
     241,   263,   227,   264,   207,   163,   130,   198,   324,    47,
     233,   200,   157,   157,   157,   157,   157,   157,  -109,   253,
     254,   255,   256,   257,   258,   228,    53,   250,   302,   320,
      76,   251,   119,     6,    40,     8,     9,    57,   296,   252,
     196,   321,    12,   197,   308,    58,   198,    87,   199,   225,
     200,    48,   234,   282,   235,   341,   226,   202,    94,    15,
     283,   299,    97,   322,   323,    98,    55,    99,   100,   101,
     192,   193,   194,   195,   102,    56,   103,   104,   105,   106,
     107,    59,  -164,   166,    61,   168,   167,   109,   169,   265,
     175,   157,    69,   212,   249,   244,   169,   202,   156,     6,
      40,     8,     9,   287,   157,    80,   202,    81,    12,   163,
     340,   156,   288,   196,   241,   202,   197,   208,   343,   198,
     201,   290,   202,   200,   202,    15,   295,   194,   195,   202,
      87,   271,   272,   273,    88,    89,    90,   175,    91,    92,
      93,    94,    95,    96,    60,    97,  -143,   217,    98,   218,
      99,   100,   101,   193,   194,   195,   269,   102,   152,   103,
     104,   105,   106,   107,   309,   108,   208,   318,    62,   319,
     109,    63,    65,   110,  -136,   328,   337,   319,   319,    87,
      74,    78,    82,    88,    89,    90,   135,    91,    92,    93,
      94,    95,    96,   333,    97,  -143,   309,    98,   136,    99,
     100,   101,   137,   138,   141,   144,   102,   145,   103,   104,
     105,   106,   107,   147,   108,   149,   148,   339,   151,   109,
     152,   159,   110,  -134,     6,    40,     8,     9,   170,   171,
     172,   173,   178,    12,    87,   190,   191,   192,   193,   194,
     195,   174,   177,   179,   184,    94,   203,   210,   213,    97,
     214,   231,    98,   219,    99,   100,   101,   232,   202,   239,
     195,   102,   248,   103,   104,   105,   106,   107,   261,   -17,
     280,    87,   267,   289,   109,    88,    89,    90,   303,    91,
      92,    93,    94,    95,    96,   281,    97,   297,   304,    98,
     298,    99,   100,   101,   305,   331,   332,    57,   102,   334,
     103,   104,   105,   106,   107,   336,   108,   338,  -109,   185,
     342,   109,    87,   330,   110,  -137,    88,    89,    90,   270,
      91,    92,    93,    94,    95,    96,   307,    97,   279,   329,
      98,    24,    99,   100,   101,    26,   285,    27,   286,   102,
     160,   103,   104,   105,   106,   107,   132,   108,   326,   205,
     325,     0,   109,    87,     0,   110,  -135,    88,    89,    90,
       0,    91,    92,    93,    94,    95,    96,     0,    97,     0,
       0,    98,     0,    99,   100,   101,     0,     0,     0,    87,
     102,     0,   103,   104,   105,   106,   107,     0,   108,     0,
      94,     0,     0,   109,    97,     0,   110,    98,     0,    99,
     100,   101,     0,     0,     0,    87,   102,     0,   103,   104,
     105,   106,   107,     0,     0,     0,    94,     0,     0,   109,
      97,  -143,   154,    98,     0,    99,   100,   101,    87,     0,
       0,     0,   102,     0,   103,   104,   105,   106,   107,    94,
       0,     0,     0,    97,     0,   109,    98,     0,    99,   100,
     101,     0,    87,     0,     0,   102,     0,   103,   104,   105,
     106,   107,  -164,    94,     0,     0,     0,    97,   109,     0,
      98,     0,    99,   100,   101,     0,     0,     0,     0,   102,
       0,   103,   104,   105,   106,   107,     0,     0,     0,     0,
       0,     4,   109,     5,     6,     7,     8,     9,    10,    11,
       0,     0,     0,    12,     0,    13,    14,     6,    40,     8,
       9,     0,     0,     0,     0,     0,    12,     0,     0,     0,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   206
};

static const yytype_int16 yycheck[] =
{
       5,     2,    18,   174,    93,    10,   120,   109,   149,     1,
      78,    58,    59,     1,    61,    62,    14,    78,   107,    59,
     266,    61,    62,   154,     4,     5,     6,     7,    10,    11,
      12,    29,    49,    13,   102,   103,   104,   105,    17,    28,
      17,   102,   103,    60,   105,    19,    49,    49,    46,     0,
      30,    56,    54,    30,   300,    60,    48,   275,    61,    47,
      49,     4,     5,     6,     7,    81,    30,    41,    84,    58,
      13,   118,     4,     5,     6,     7,    58,    56,    58,    56,
       1,    13,    30,   172,   173,   174,   154,    30,   177,   307,
     179,   205,    56,   154,   136,   184,    17,   199,    30,   141,
      38,    39,    40,    41,    42,    48,    30,    28,   197,    30,
     178,   200,    32,   202,   119,   131,    48,    50,   289,    30,
     162,    54,   190,   191,   192,   193,   194,   195,    47,   190,
     191,   192,   193,   194,   195,    55,    17,    51,   269,   280,
      59,    55,   189,     4,     5,     6,     7,    49,   250,   189,
      44,   282,    13,    47,    15,    57,    50,    14,    52,    51,
      54,    30,   167,    51,   169,   336,    58,    51,    25,    30,
      58,    55,    29,   287,   288,    32,    49,    34,    35,    36,
      39,    40,    41,    42,    41,    47,    43,    44,    45,    46,
      47,    57,    49,    48,    57,    48,    51,    54,    51,   204,
     289,   269,    53,    48,    48,   294,    51,    51,   269,     4,
       5,     6,     7,    48,   282,    49,    51,    51,    13,   235,
     334,   282,    48,    44,   292,    51,    47,     1,   342,    50,
      49,    48,    51,    54,    51,    30,    48,    41,    42,    51,
      14,    10,    11,    12,    18,    19,    20,   336,    22,    23,
      24,    25,    26,    27,    47,    29,    30,    49,    32,    51,
      34,    35,    36,    40,    41,    42,    52,    41,    54,    43,
      44,    45,    46,    47,   275,    49,     1,    49,    57,    51,
      54,    47,    47,    57,    58,    49,    49,    51,    51,    14,
      57,    52,    30,    18,    19,    20,    48,    22,    23,    24,
      25,    26,    27,   319,    29,    30,   307,    32,    30,    34,
      35,    36,    48,    48,    30,    30,    41,    49,    43,    44,
      45,    46,    47,    49,    49,    30,    57,   332,    49,    54,
      54,    30,    57,    58,     4,     5,     6,     7,    49,    49,
      47,    47,    60,    13,    14,    37,    38,    39,    40,    41,
      42,    47,    47,    61,    47,    25,    58,    58,    58,    29,
      58,    30,    32,    57,    34,    35,    36,    30,    51,    49,
      42,    41,    48,    43,    44,    45,    46,    47,    30,    30,
      30,    14,    49,    49,    54,    18,    19,    20,    53,    22,
      23,    24,    25,    26,    27,    55,    29,    58,    53,    32,
      48,    34,    35,    36,    53,    30,    47,    49,    41,    21,
      43,    44,    45,    46,    47,    49,    49,    49,    47,   107,
      48,    54,    14,   308,    57,    58,    18,    19,    20,   218,
      22,    23,    24,    25,    26,    27,   274,    29,   222,   307,
      32,     2,    34,    35,    36,     2,   234,     2,   235,    41,
      81,    43,    44,    45,    46,    47,    60,    49,   294,   118,
     292,    -1,    54,    14,    -1,    57,    58,    18,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,    29,    -1,
      -1,    32,    -1,    34,    35,    36,    -1,    -1,    -1,    14,
      41,    -1,    43,    44,    45,    46,    47,    -1,    49,    -1,
      25,    -1,    -1,    54,    29,    -1,    57,    32,    -1,    34,
      35,    36,    -1,    -1,    -1,    14,    41,    -1,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    25,    -1,    -1,    54,
      29,    30,    57,    32,    -1,    34,    35,    36,    14,    -1,
      -1,    -1,    41,    -1,    43,    44,    45,    46,    47,    25,
      -1,    -1,    -1,    29,    -1,    54,    32,    -1,    34,    35,
      36,    -1,    14,    -1,    -1,    41,    -1,    43,    44,    45,
      46,    47,    48,    25,    -1,    -1,    -1,    29,    54,    -1,
      32,    -1,    34,    35,    36,    -1,    -1,    -1,    -1,    41,
      -1,    43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,
      -1,     1,    54,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    13,    -1,    15,    16,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    67,    68,     0,     1,     3,     4,     5,     6,     7,
       8,     9,    13,    15,    16,    30,    69,    70,    71,    72,
      73,    77,    91,    95,   112,   113,   114,   117,   118,   119,
     122,   123,   124,   125,   129,   151,   152,    28,    49,    58,
       5,    72,     1,    28,    72,    30,    30,    30,    30,   105,
     120,   121,   126,    17,    74,    49,    47,    49,    57,    57,
      47,    57,    57,    47,    74,    47,     1,    47,    78,    53,
      96,    98,   107,   108,    57,    92,    59,    75,    52,    94,
      49,    51,    30,    48,    72,   115,   127,    14,    18,    19,
      20,    22,    23,    24,    25,    26,    27,    29,    32,    34,
      35,    36,    41,    43,    44,    45,    46,    47,    49,    54,
      57,    82,    83,    84,    85,    87,    88,   130,   131,   134,
     135,   136,   137,   138,   140,   141,   143,   144,   149,   130,
      48,    72,   127,   130,   130,    48,    30,    48,    48,     1,
      48,    30,    79,    80,    30,    49,    97,    49,    57,    30,
      93,    49,    54,    76,    57,    81,    82,    83,   134,    30,
     121,    56,    74,   105,   116,   128,    48,    51,    48,    51,
      49,    49,    47,    47,    47,    84,   142,    47,    60,    61,
      82,    82,    83,    82,    47,    73,    84,    85,    89,   150,
      37,    38,    39,    40,    41,    42,    44,    47,    50,    52,
      54,    49,    51,    58,   134,   135,    30,    72,     1,   136,
      58,    56,    48,    58,    58,    75,    75,    49,    51,    57,
      71,   103,   109,   110,    94,    51,    58,    32,    55,    81,
      90,    30,    30,    75,    72,    72,    84,    84,   142,    49,
      84,    83,   145,   146,    84,   147,   148,    84,    48,    48,
      51,    55,   130,    82,    82,    82,    82,    82,    82,    84,
      86,    30,    85,    84,    84,    72,   133,    49,    49,    52,
      80,    10,    11,    12,    99,   100,   104,   105,    58,   110,
      30,    55,    51,    58,    56,   116,   128,    48,    48,    49,
      48,    49,    60,    49,    61,    48,    85,    58,    48,    55,
     132,   104,    81,    53,    53,    53,    58,   100,    15,    71,
     101,   102,   103,   106,   111,   112,   114,   117,    49,    51,
      94,    81,   136,   136,   142,   146,   148,   104,    49,   101,
     107,    30,    47,   105,    21,   139,    49,    49,    49,    72,
     136,   142,    48,   136
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
       1,     1,     2,     2,     6,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     2,     0,     3,     2,     0,
       5,     3,     1,     4,     1,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     2,     1,     4,     4,
       1,     3,     3,     1,     4,     3,     4,     2,     1,     3,
       1,     3,     1,     1,     0,     1,     1,     1,     1,     3,
       3,     1,     3,     1,     4,     3,     4,     2,     2,     0,
       4,     0,     5,     2,     0,     3,     2,     2,     2,     2,
       0,     1,     1,     1,     1,     3,     3,     1,     2,     3,
       0,     4,     2,     1,     1,     1,     2,     2,     4,     2,
       4,     2,     1,     2,     3,     4,     3,     3,     1,     2,
       1,     1,     4,     4,     4,     4,     4,     3,     2,     4,
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
#line 1832 "syntax.tab.c"
    break;

  case 12: /* global_declaration: error "semi"  */
#line 141 "syntax.y"
                                                                                {yyerror(" HINT: syntax error in global declaration\n"); yyerrok;}
#line 1838 "syntax.tab.c"
    break;

  case 13: /* global_declaration: error "rbrace"  */
#line 142 "syntax.y"
                                                                                {yyerror(" HINT: in global declaration\n"); yyerrok; }
#line 1844 "syntax.tab.c"
    break;

  case 14: /* typedef_declaration: "typedef" typename listspec "id" dims "semi"  */
#line 144 "syntax.y"
                                                                                {
                                                                                    /* αγνοούμε προς το παρόν listspec/dims για σύνθετους, κρατάμε base type */
                                                                                    if (!symtab_insert((yyvsp[-2].strval), SYM_TYPE, (yyvsp[-4].type))) {
                                                                                        YYERROR_FMT("Redeclaration of typedef '%s'", (yyvsp[-2].strval));
                                                                                    }
                                                                                }
#line 1855 "syntax.tab.c"
    break;

  case 15: /* type_with_list: typename listspec  */
#line 151 "syntax.y"
                                                                                {
                                                                                    Type *t = (yyvsp[-1].type);
                                                                                    if ((yyvsp[0].intval)) {
                                                                                       (yyval.type) = sem_make_list_type(t, yylineno);
                                                                                    } else {
                                                                                        (yyval.type) = t;
                                                                                    }
                                                                                    current_type = (yyval.type);
                                                                                    }
#line 1869 "syntax.tab.c"
    break;

  case 17: /* typename: "id"  */
#line 163 "syntax.y"
                                                                                {Symbol *s = symtab_lookup((yyvsp[0].strval));
                                                                                    if (!s || s->kind != SYM_TYPE || !s->type) {
                                                                                        YYERROR_FMT("Unknown type '%s'", (yyvsp[0].strval));
                                                                                        (yyval.type) = type_error;
                                                                                    } else {
                                                                                        (yyval.type) = s->type;
                                                                                    }
                                                                                }
#line 1882 "syntax.tab.c"
    break;

  case 18: /* standard_type: "char"  */
#line 172 "syntax.y"
                                                                                {(yyval.type) = type_char;}
#line 1888 "syntax.tab.c"
    break;

  case 19: /* standard_type: "int"  */
#line 173 "syntax.y"
                                                                                {(yyval.type) = type_int;}
#line 1894 "syntax.tab.c"
    break;

  case 20: /* standard_type: "float"  */
#line 174 "syntax.y"
                                                                                {(yyval.type) = type_float;}
#line 1900 "syntax.tab.c"
    break;

  case 21: /* standard_type: "string"  */
#line 175 "syntax.y"
                                                                                {(yyval.type) = type_string;}
#line 1906 "syntax.tab.c"
    break;

  case 22: /* standard_type: "void"  */
#line 176 "syntax.y"
                                                                                {(yyval.type) = type_void;}
#line 1912 "syntax.tab.c"
    break;

  case 23: /* listspec: "list"  */
#line 178 "syntax.y"
                                                                                {(yyval.intval) = 1;}
#line 1918 "syntax.tab.c"
    break;

  case 24: /* listspec: %empty  */
#line 179 "syntax.y"
                                                                                {(yyval.intval) = 0;}
#line 1924 "syntax.tab.c"
    break;

  case 25: /* dims: dims dim  */
#line 181 "syntax.y"
                                                                                { (yyval.type) = attach_nested_array((yyvsp[-1].type), (yyvsp[0].type)); }
#line 1930 "syntax.tab.c"
    break;

  case 26: /* dims: %empty  */
#line 182 "syntax.y"
                                                                                { (yyval.type) = NULL; }
#line 1936 "syntax.tab.c"
    break;

  case 27: /* dim: "lbrack" "iconst" "rbrack"  */
#line 184 "syntax.y"
                                                                                { (yyval.type) = make_array_type(NULL, (yyvsp[-1].intval)); }
#line 1942 "syntax.tab.c"
    break;

  case 28: /* dim: "lbrack" "rbrack"  */
#line 185 "syntax.y"
                                                                                { (yyval.type) = make_array_type(NULL, 0); }
#line 1948 "syntax.tab.c"
    break;

  case 29: /* $@1: %empty  */
#line 187 "syntax.y"
                                             { current_type = (yyvsp[0].type); }
#line 1954 "syntax.tab.c"
    break;

  case 33: /* constdef: "id" dims "assign" init_value  */
#line 192 "syntax.y"
                                                                                {if (!current_type) current_type = type_error;
                                                                                    if (!symtab_insert((yyvsp[-3].strval), SYM_CONST, current_type)) {
                                                                                        YYERROR_FMT("Redeclaration of const '%s'", (yyvsp[-3].strval));
                                                                                    }
                                                                                }
#line 1964 "syntax.tab.c"
    break;

  case 36: /* expression: expression "orop" expression  */
#line 201 "syntax.y"
                                                                                {(yyval.type) = sem_binary_logical((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1970 "syntax.tab.c"
    break;

  case 37: /* expression: expression "andop" expression  */
#line 202 "syntax.y"
                                                                                {(yyval.type) = sem_binary_logical((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1976 "syntax.tab.c"
    break;

  case 38: /* expression: expression "equop" expression  */
#line 203 "syntax.y"
                                                                                {(yyval.type) = sem_binary_equality((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1982 "syntax.tab.c"
    break;

  case 39: /* expression: expression "relop" expression  */
#line 204 "syntax.y"
                                                                                {(yyval.type) = sem_binary_relational((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1988 "syntax.tab.c"
    break;

  case 40: /* expression: expression "addop" expression  */
#line 205 "syntax.y"
                                                                                {(yyval.type) = sem_binary_arith((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1994 "syntax.tab.c"
    break;

  case 41: /* expression: expression "mulop" expression  */
#line 206 "syntax.y"
                                                                                {(yyval.type) = sem_binary_arith((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 2000 "syntax.tab.c"
    break;

  case 42: /* expression: "notop" expression  */
#line 207 "syntax.y"
                                                                                { (yyval.type) = sem_unary_not((yyvsp[0].type), yylineno); }
#line 2006 "syntax.tab.c"
    break;

  case 43: /* expression: "addop" expression  */
#line 208 "syntax.y"
                                                                                { (yyval.type) = sem_unary_not((yyvsp[0].type), yylineno); }
#line 2012 "syntax.tab.c"
    break;

  case 44: /* expression: "sizeop" expression  */
#line 209 "syntax.y"
                                                                                { (yyval.type) = type_int; }
#line 2018 "syntax.tab.c"
    break;

  case 45: /* expression: "incdec" variable  */
#line 210 "syntax.y"
                                                                                { (yyval.type) = sem_unary_incdec((yyvsp[0].type), yylineno); }
#line 2024 "syntax.tab.c"
    break;

  case 46: /* expression: variable "incdec"  */
#line 211 "syntax.y"
                                                                                { (yyval.type) = sem_unary_incdec((yyvsp[-1].type), yylineno); }
#line 2030 "syntax.tab.c"
    break;

  case 47: /* expression: variable  */
#line 212 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[0].type);}
#line 2036 "syntax.tab.c"
    break;

  case 48: /* expression: variable "lparen" expression_list "rparen"  */
#line 213 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[-3].type);}
#line 2042 "syntax.tab.c"
    break;

  case 49: /* expression: "length" "lparen" general_expression "rparen"  */
#line 214 "syntax.y"
                                                                                {(yyval.type) = type_int;}
#line 2048 "syntax.tab.c"
    break;

  case 50: /* expression: constant  */
#line 215 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[0].type);}
#line 2054 "syntax.tab.c"
    break;

  case 51: /* expression: "lparen" general_expression "rparen"  */
#line 216 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[-1].type);}
#line 2060 "syntax.tab.c"
    break;

  case 52: /* expression: "lparen" standard_type "rparen"  */
#line 217 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[-1].type);}
#line 2066 "syntax.tab.c"
    break;

  case 53: /* expression: listexpression  */
#line 218 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[0].type);}
#line 2072 "syntax.tab.c"
    break;

  case 54: /* variable: variable "lbrack" general_expression "rbrack"  */
#line 220 "syntax.y"
                                                                                {(yyval.type) = sem_index((yyvsp[-3].type), (yyvsp[-1].type), yylineno);}
#line 2078 "syntax.tab.c"
    break;

  case 55: /* variable: variable "dot" "id"  */
#line 221 "syntax.y"
                                                                                {(yyval.type)= type_error;}
#line 2084 "syntax.tab.c"
    break;

  case 56: /* variable: "listfunc" "lparen" general_expression "rparen"  */
#line 222 "syntax.y"
                                                                                {(yyval.type)= type_error;}
#line 2090 "syntax.tab.c"
    break;

  case 57: /* variable: decltype "id"  */
#line 223 "syntax.y"
                                                                                {(yyval.type) = sem_use_variable((yyvsp[0].strval), yylineno); }
#line 2096 "syntax.tab.c"
    break;

  case 58: /* variable: "this"  */
#line 224 "syntax.y"
                                                                                {(yyval.type)= type_error;}
#line 2102 "syntax.tab.c"
    break;

  case 59: /* general_expression: general_expression "comma" general_expression  */
#line 226 "syntax.y"
                                                                                {(yyval.type) = (yyvsp[0].type);}
#line 2108 "syntax.tab.c"
    break;

  case 60: /* general_expression: assignment  */
#line 227 "syntax.y"
                                                                                {(yyval.type) = (yyvsp[0].type);}
#line 2114 "syntax.tab.c"
    break;

  case 61: /* assignment: variable "assign" assignment  */
#line 229 "syntax.y"
                                                                                {(yyval.type) = sem_check_assignment((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 2120 "syntax.tab.c"
    break;

  case 62: /* assignment: expression  */
#line 230 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[0].type);}
#line 2126 "syntax.tab.c"
    break;

  case 63: /* expression_list: general_expression  */
#line 232 "syntax.y"
                                                                                {(yyval.type) = (yyvsp[0].type);}
#line 2132 "syntax.tab.c"
    break;

  case 64: /* expression_list: %empty  */
#line 233 "syntax.y"
                                                                                {(yyval.type) = type_void;}
#line 2138 "syntax.tab.c"
    break;

  case 65: /* constant: "cconst"  */
#line 235 "syntax.y"
                                                                                { (yyval.type) = type_char;   }
#line 2144 "syntax.tab.c"
    break;

  case 66: /* constant: "iconst"  */
#line 236 "syntax.y"
                                                                                { (yyval.type) = type_int;    }
#line 2150 "syntax.tab.c"
    break;

  case 67: /* constant: "fconst"  */
#line 237 "syntax.y"
                                                                                { (yyval.type) = type_float;  }
#line 2156 "syntax.tab.c"
    break;

  case 68: /* constant: "sconst"  */
#line 238 "syntax.y"
                                                                                { (yyval.type) = type_string; }
#line 2162 "syntax.tab.c"
    break;

  case 69: /* listexpression: "lbrack" list_elements "rbrack"  */
#line 241 "syntax.y"
                                                                                {(yyval.type) = sem_make_list_type((yyvsp[-1].type), yylineno);}
#line 2168 "syntax.tab.c"
    break;

  case 70: /* list_elements: list_elements "comma" assignment  */
#line 243 "syntax.y"
                                                                                { (yyval.type) = sem_find_list_element_type((yyvsp[-2].type), (yyvsp[0].type), yylineno); }
#line 2174 "syntax.tab.c"
    break;

  case 71: /* list_elements: assignment  */
#line 244 "syntax.y"
                                                                                { (yyval.type) = (yyvsp[0].type); }
#line 2180 "syntax.tab.c"
    break;

  case 74: /* enum_declaration: "enum" "id" enum_body "semi"  */
#line 249 "syntax.y"
                                                                                {Type *t = make_simple_type(TYPE_ENUM);
                                                                                    if (!symtab_insert((yyvsp[-2].strval), SYM_TYPE, t)) {
                                                                                        YYERROR_FMT("Redeclaration of enum '%s'", (yyvsp[-2].strval));
                                                                                    }
                                                                                }
#line 2190 "syntax.tab.c"
    break;

  case 76: /* id_list: id_list "comma" "id" initializer  */
#line 256 "syntax.y"
                                                                                {/* enum constants -> ακέραιοι */
                                                                                    if (!symtab_insert((yyvsp[-1].strval), SYM_ENUM_CONST, type_int)) {
                                                                                        YYERROR_FMT("Redeclaration of enum const '%s'", (yyvsp[-1].strval));
                                                                                    }
                                                                                }
#line 2200 "syntax.tab.c"
    break;

  case 77: /* id_list: "id" initializer  */
#line 261 "syntax.y"
                                                                                {if (!symtab_insert((yyvsp[-1].strval), SYM_ENUM_CONST, type_int)) {
                                                                                        YYERROR_FMT("Redeclaration of enum const '%s'", (yyvsp[-1].strval));
                                                                                    }
                                                                                }
#line 2209 "syntax.tab.c"
    break;

  case 79: /* initializer: %empty  */
#line 267 "syntax.y"
                                             {;}
#line 2215 "syntax.tab.c"
    break;

  case 80: /* class_declaration: "class" "id" class_body "semi"  */
#line 269 "syntax.y"
                                                                                {Type *t = make_simple_type(TYPE_CLASS);
                                                                                    if (!symtab_insert((yyvsp[-2].strval), SYM_TYPE, t)) {
                                                                                        YYERROR_FMT("Redeclaration of class '%s'", (yyvsp[-2].strval));
                                                                                    }
                                                                                }
#line 2225 "syntax.tab.c"
    break;

  case 81: /* $@2: %empty  */
#line 275 "syntax.y"
                                   {symtab_enter_scope();}
#line 2231 "syntax.tab.c"
    break;

  case 82: /* class_body: parent $@2 "lbrace" members_methods "rbrace"  */
#line 275 "syntax.y"
                                                                                             { symtab_leave_scope();}
#line 2237 "syntax.tab.c"
    break;

  case 83: /* parent: "colon" "id"  */
#line 276 "syntax.y"
                                                                                {Symbol *base = symtab_lookup((yyvsp[0].strval));
                                                                                    if (!base || base->kind != SYM_TYPE) {
                                                                                        YYERROR_FMT("Unknown base class '%s'", (yyvsp[0].strval));
                                                                                    }
                                                                                }
#line 2247 "syntax.tab.c"
    break;

  case 84: /* parent: %empty  */
#line 281 "syntax.y"
                                             {;}
#line 2253 "syntax.tab.c"
    break;

  case 90: /* access: %empty  */
#line 286 "syntax.y"
                                                                                                        { }
#line 2259 "syntax.tab.c"
    break;

  case 98: /* variabledef: "id" dims  */
#line 301 "syntax.y"
                                                                                {if (!current_type) current_type = type_error;
                                                                                    Type *t = current_type;
                                                                                    if ((yyvsp[0].type) != NULL)         // piankas
                                                                                        t = attach_array_to_base(current_type, (yyvsp[0].type));
                                                                                    if (!symtab_insert((yyvsp[-1].strval), SYM_VAR, t)) {
                                                                                        YYERROR_FMT("Redeclaration of '%s'", (yyvsp[-1].strval));
                                                                                    }
                                                                                }
#line 2272 "syntax.tab.c"
    break;

  case 100: /* $@3: %empty  */
#line 313 "syntax.y"
                            {symtab_enter_scope();}
#line 2278 "syntax.tab.c"
    break;

  case 101: /* union_body: $@3 "lbrace" fields "rbrace"  */
#line 313 "syntax.y"
                                                                                             { symtab_leave_scope();}
#line 2284 "syntax.tab.c"
    break;

  case 106: /* short_func_declaration: short_par_func_header "semi"  */
#line 322 "syntax.y"
                                                                                { symtab_leave_scope();}
#line 2290 "syntax.tab.c"
    break;

  case 107: /* short_func_declaration: nopar_func_header "semi"  */
#line 323 "syntax.y"
                                                                                { symtab_leave_scope();}
#line 2296 "syntax.tab.c"
    break;

  case 109: /* func_header_start: type_with_list "id"  */
#line 329 "syntax.y"
                                                                                {Type *ret = (yyvsp[-1].type);
                                                                                    if (!symtab_insert((yyvsp[0].strval), SYM_FUNC, ret)) {
                                                                                        YYERROR_FMT("Redeclaration of function '%s'", (yyvsp[0].strval));
                                                                                    }
                                                                                    symtab_enter_scope();
                                                                                }
#line 2307 "syntax.tab.c"
    break;

  case 115: /* union_declaration: "union" "id" union_body "semi"  */
#line 345 "syntax.y"
                                                                                {Type *t = make_simple_type(TYPE_UNION);
                                                                                    if (!symtab_insert((yyvsp[-2].strval), SYM_TYPE, t)) {
                                                                                        YYERROR_FMT("Redeclaration of union '%s'", (yyvsp[-2].strval));
                                                                                    }
                                                                                }
#line 2317 "syntax.tab.c"
    break;

  case 122: /* full_func_declaration: full_par_func_header "lbrace" decl_statements "rbrace"  */
#line 364 "syntax.y"
                                                                                                        { symtab_leave_scope();}
#line 2323 "syntax.tab.c"
    break;

  case 123: /* full_func_declaration: nopar_class_func_header "lbrace" decl_statements "rbrace"  */
#line 365 "syntax.y"
                                                                                                        { symtab_leave_scope();}
#line 2329 "syntax.tab.c"
    break;

  case 124: /* full_func_declaration: nopar_func_header "lbrace" decl_statements "rbrace"  */
#line 366 "syntax.y"
                                                                                                        { symtab_leave_scope();}
#line 2335 "syntax.tab.c"
    break;

  case 127: /* class_func_header_start: type_with_list func_class "id"  */
#line 371 "syntax.y"
                                                                                {Type *ret = (yyvsp[-2].type);
                                                                                    if (!symtab_insert((yyvsp[0].strval), SYM_FUNC, ret)) {
                                                                                        YYERROR_FMT("Redeclaration of method '%s'", (yyvsp[0].strval));
                                                                                    }
                                                                                    symtab_enter_scope();
                                                                                }
#line 2346 "syntax.tab.c"
    break;

  case 128: /* func_class: "id" "meth"  */
#line 378 "syntax.y"
                                                                                {Symbol *cls = symtab_lookup((yyvsp[-1].strval));
                                                                                    if (!cls || cls->kind != SYM_TYPE) {
                                                                                        YYERROR_FMT("Unknown class type '%s'", (yyvsp[-1].strval));
                                                                                    }
                                                                                }
#line 2356 "syntax.tab.c"
    break;

  case 130: /* parameter_list: typename pass_variabledef  */
#line 385 "syntax.y"
                                                        { current_type = (yyvsp[-1].type); }
#line 2362 "syntax.tab.c"
    break;

  case 132: /* pass_variabledef: "refer" "id"  */
#line 388 "syntax.y"
                                                                                {if (!current_type) current_type = type_error;
                                                                                    if (!symtab_insert((yyvsp[0].strval), SYM_VAR, current_type)) {
                                                                                        YYERROR_FMT("Redeclaration of parameter '%s'", (yyvsp[0].strval));
                                                                                    }
                                                                                }
#line 2372 "syntax.tab.c"
    break;

  case 137: /* decl_statements: %empty  */
#line 399 "syntax.y"
                                             {;}
#line 2378 "syntax.tab.c"
    break;

  case 138: /* $@4: %empty  */
#line 401 "syntax.y"
                                                           { current_type = (yyvsp[0].type); }
#line 2384 "syntax.tab.c"
    break;

  case 140: /* $@5: %empty  */
#line 402 "syntax.y"
                                                { current_type = (yyvsp[0].type); }
#line 2390 "syntax.tab.c"
    break;

  case 143: /* decltype: %empty  */
#line 404 "syntax.y"
                                                      {;}
#line 2396 "syntax.tab.c"
    break;

  case 146: /* statements: statements error "semi"  */
#line 407 "syntax.y"
                                                                                { YYERROR_FMT(" HINT:  error in statement - skipping until ';'"); yyerrok; }
#line 2402 "syntax.tab.c"
    break;

  case 160: /* if_tail: %empty  */
#line 423 "syntax.y"
                                                                     {;}
#line 2408 "syntax.tab.c"
    break;

  case 164: /* optexpr: %empty  */
#line 428 "syntax.y"
                                             {;}
#line 2414 "syntax.tab.c"
    break;

  case 174: /* $@6: %empty  */
#line 442 "syntax.y"
                                     {symtab_enter_scope();}
#line 2420 "syntax.tab.c"
    break;

  case 175: /* comp_statement: "lbrace" $@6 decl_statements "rbrace"  */
#line 442 "syntax.y"
                                                                                         { symtab_leave_scope();}
#line 2426 "syntax.tab.c"
    break;

  case 176: /* main_function: main_header "lbrace" decl_statements "rbrace"  */
#line 443 "syntax.y"
                                                                            { symtab_leave_scope();}
#line 2432 "syntax.tab.c"
    break;

  case 177: /* main_header: "int" "main" "lparen" "rparen"  */
#line 444 "syntax.y"
                                                                            {symtab_enter_scope();}
#line 2438 "syntax.tab.c"
    break;

  case 178: /* main_header: error "main" "lparen" "rparen"  */
#line 445 "syntax.y"
                                                                            {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; symtab_enter_scope();}
#line 2444 "syntax.tab.c"
    break;

  case 179: /* main_header: "int" error "lparen" "rparen"  */
#line 446 "syntax.y"
                                                                            {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; symtab_enter_scope();}
#line 2450 "syntax.tab.c"
    break;

  case 180: /* main_header: "int" "main" error "rparen"  */
#line 447 "syntax.y"
                                                                            {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; symtab_enter_scope();}
#line 2456 "syntax.tab.c"
    break;

  case 181: /* main_header: "int" "main" "lparen" error  */
#line 448 "syntax.y"
                                                                            {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; symtab_enter_scope();}
#line 2462 "syntax.tab.c"
    break;


#line 2466 "syntax.tab.c"

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

#line 450 "syntax.y"


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
