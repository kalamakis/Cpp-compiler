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
  YYSYMBOL_list_elements = 88,             /* list_elements  */
  YYSYMBOL_init_values = 89,               /* init_values  */
  YYSYMBOL_enum_declaration = 90,          /* enum_declaration  */
  YYSYMBOL_enum_body = 91,                 /* enum_body  */
  YYSYMBOL_id_list = 92,                   /* id_list  */
  YYSYMBOL_initializer = 93,               /* initializer  */
  YYSYMBOL_class_declaration = 94,         /* class_declaration  */
  YYSYMBOL_class_body = 95,                /* class_body  */
  YYSYMBOL_96_2 = 96,                      /* $@2  */
  YYSYMBOL_parent = 97,                    /* parent  */
  YYSYMBOL_members_methods = 98,           /* members_methods  */
  YYSYMBOL_access = 99,                    /* access  */
  YYSYMBOL_member_or_method = 100,         /* member_or_method  */
  YYSYMBOL_member = 101,                   /* member  */
  YYSYMBOL_var_declaration = 102,          /* var_declaration  */
  YYSYMBOL_variabledefs = 103,             /* variabledefs  */
  YYSYMBOL_variabledef = 104,              /* variabledef  */
  YYSYMBOL_anonymous_union = 105,          /* anonymous_union  */
  YYSYMBOL_union_body = 106,               /* union_body  */
  YYSYMBOL_107_3 = 107,                    /* $@3  */
  YYSYMBOL_fields = 108,                   /* fields  */
  YYSYMBOL_field = 109,                    /* field  */
  YYSYMBOL_method = 110,                   /* method  */
  YYSYMBOL_short_func_declaration = 111,   /* short_func_declaration  */
  YYSYMBOL_short_par_func_header = 112,    /* short_par_func_header  */
  YYSYMBOL_func_header_start = 113,        /* func_header_start  */
  YYSYMBOL_parameter_types = 114,          /* parameter_types  */
  YYSYMBOL_pass_list_dims = 115,           /* pass_list_dims  */
  YYSYMBOL_nopar_func_header = 116,        /* nopar_func_header  */
  YYSYMBOL_union_declaration = 117,        /* union_declaration  */
  YYSYMBOL_global_var_declaration = 118,   /* global_var_declaration  */
  YYSYMBOL_init_variabledefs = 119,        /* init_variabledefs  */
  YYSYMBOL_init_variabledef = 120,         /* init_variabledef  */
  YYSYMBOL_func_declaration = 121,         /* func_declaration  */
  YYSYMBOL_full_func_declaration = 122,    /* full_func_declaration  */
  YYSYMBOL_full_par_func_header = 123,     /* full_par_func_header  */
  YYSYMBOL_class_func_header_start = 124,  /* class_func_header_start  */
  YYSYMBOL_func_class = 125,               /* func_class  */
  YYSYMBOL_parameter_list = 126,           /* parameter_list  */
  YYSYMBOL_pass_variabledef = 127,         /* pass_variabledef  */
  YYSYMBOL_nopar_class_func_header = 128,  /* nopar_class_func_header  */
  YYSYMBOL_decl_statements = 129,          /* decl_statements  */
  YYSYMBOL_declarations = 130,             /* declarations  */
  YYSYMBOL_131_4 = 131,                    /* $@4  */
  YYSYMBOL_132_5 = 132,                    /* $@5  */
  YYSYMBOL_decltype = 133,                 /* decltype  */
  YYSYMBOL_statements = 134,               /* statements  */
  YYSYMBOL_statement = 135,                /* statement  */
  YYSYMBOL_expression_statement = 136,     /* expression_statement  */
  YYSYMBOL_if_statement = 137,             /* if_statement  */
  YYSYMBOL_if_tail = 138,                  /* if_tail  */
  YYSYMBOL_while_statement = 139,          /* while_statement  */
  YYSYMBOL_for_statement = 140,            /* for_statement  */
  YYSYMBOL_optexpr = 141,                  /* optexpr  */
  YYSYMBOL_return_statement = 142,         /* return_statement  */
  YYSYMBOL_io_statement = 143,             /* io_statement  */
  YYSYMBOL_in_list = 144,                  /* in_list  */
  YYSYMBOL_in_item = 145,                  /* in_item  */
  YYSYMBOL_out_list = 146,                 /* out_list  */
  YYSYMBOL_out_item = 147,                 /* out_item  */
  YYSYMBOL_comp_statement = 148,           /* comp_statement  */
  YYSYMBOL_149_6 = 149,                    /* $@6  */
  YYSYMBOL_main_function = 150,            /* main_function  */
  YYSYMBOL_main_header = 151               /* main_header  */
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
#define YYLAST   639

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  86
/* YYNRULES -- Number of rules.  */
#define YYNRULES  180
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  346

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
     230,   232,   233,   235,   241,   242,   247,   252,   253,   255,
     261,   261,   262,   267,   269,   270,   272,   272,   272,   272,
     273,   274,   276,   277,   280,   284,   285,   288,   296,   298,
     298,   300,   301,   303,   305,   307,   308,   311,   314,   322,
     323,   325,   326,   328,   330,   337,   341,   342,   344,   346,
     347,   349,   350,   351,   353,   354,   356,   363,   369,   370,
     372,   373,   379,   381,   382,   383,   384,   386,   386,   387,
     387,   389,   389,   390,   391,   392,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   405,   406,   407,   408,
     410,   411,   412,   413,   415,   416,   417,   419,   420,   422,
     423,   424,   426,   427,   427,   428,   429,   430,   431,   432,
     433
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
  "expression_list", "constant", "listexpression", "list_elements",
  "init_values", "enum_declaration", "enum_body", "id_list", "initializer",
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

#define YYPACT_NINF (-249)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-164)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -249,    60,   609,  -249,    49,   150,  -249,    40,  -249,  -249,
     150,    69,  -249,    85,    86,  -249,  -249,  -249,   106,  -249,
    -249,  -249,  -249,  -249,    75,    98,    38,  -249,  -249,  -249,
    -249,   124,   143,   125,  -249,   174,   195,  -249,  -249,  -249,
     106,   199,    33,  -249,   220,  -249,   207,  -249,   253,   234,
      83,  -249,  -249,   131,  -249,   376,   376,   135,   376,   376,
     239,   260,   243,   245,    31,   269,   270,   252,  -249,   257,
     251,   272,   261,     6,   279,   484,  -249,  -249,   106,  -249,
      18,    21,   141,  -249,   265,   277,   283,   285,   286,   194,
     288,   281,   287,  -249,  -249,  -249,  -249,  -249,   557,   557,
      47,   557,   302,   339,  -249,   557,  -249,   317,   144,   102,
    -249,  -249,  -249,   303,   417,   291,   231,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,   304,  -249,    19,   165,   305,
     307,  -249,  -249,  -249,  -249,  -249,  -249,  -249,   119,  -249,
    -249,  -249,   309,  -249,   150,   234,    43,  -249,  -249,   306,
    -249,   484,  -249,   317,   122,   337,   340,  -249,   342,   340,
    -249,  -249,  -249,  -249,   150,  -249,   150,  -249,  -249,   557,
     557,   194,   318,   327,   557,    47,   557,   335,  -249,    56,
    -249,   557,   330,   170,  -249,    95,   376,   557,   557,   557,
     557,   557,   557,  -249,   510,   349,   557,   557,  -249,   557,
    -249,   291,   293,    28,  -249,   332,  -249,  -249,   342,  -249,
    -249,  -249,    54,   153,  -249,   269,   148,   106,  -249,    20,
    -249,  -249,   357,  -249,    16,  -249,  -249,    46,  -249,  -249,
    -249,   306,    32,    19,   176,   185,   343,  -249,   196,    56,
       7,  -249,   318,     5,  -249,   211,  -249,  -249,   557,  -249,
     331,   567,   161,   228,    41,   335,  -249,   318,   356,  -249,
    -249,   120,  -249,  -249,   106,  -249,  -249,   484,  -249,   338,
     344,   353,     1,   180,   163,  -249,  -249,  -249,   234,   333,
    -249,   484,  -249,  -249,  -249,  -249,  -249,   458,   458,   194,
    -249,  -249,    47,  -249,   557,  -249,  -249,  -249,  -249,  -249,
     106,   230,  -249,  -249,  -249,  -249,  -249,   180,  -249,   106,
    -249,  -249,  -249,  -249,  -249,  -249,   360,   364,  -249,   106,
    -249,  -249,  -249,   388,  -249,   365,  -249,  -249,   233,  -249,
    -249,   366,   386,   131,  -249,   458,  -249,   533,  -249,  -249,
     371,    32,  -249,   378,   458,  -249
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,     0,     0,    17,     0,    19,    20,
       0,     0,    21,     0,     0,    16,     3,     5,    23,    15,
       6,     7,     8,   119,     0,     0,     0,     9,    10,    11,
     120,     0,     0,     0,     2,     0,     0,    12,    13,    18,
      23,     0,     0,    28,    83,    99,     0,    22,     0,    78,
       0,   117,   105,     0,   106,   142,   142,     0,   142,   142,
       0,     0,     0,     0,     0,     0,     0,     0,    80,     0,
       0,     0,     0,    25,     0,   142,   118,   115,    23,   113,
      23,     0,     0,   141,     0,     0,     0,     0,     0,   142,
       0,     0,     0,    57,    65,    66,    67,    64,   142,   142,
     142,   142,     0,   142,   155,   142,   173,    61,    46,     0,
      59,    49,    52,     0,   142,     0,     0,   144,   146,   147,
     148,   149,   150,   151,   152,     0,   132,    23,     0,     0,
       0,   177,    25,   178,   179,   180,   176,    25,     0,    31,
      82,    79,     0,   114,     0,    78,     0,    73,   127,    97,
     126,   142,    77,    33,    46,     0,     0,   116,   111,    25,
     130,   110,   129,   107,     0,   125,     0,   153,   154,   142,
     142,   142,   162,     0,   142,   142,   142,    42,    41,    44,
      43,   142,     0,     0,    70,     0,   142,   142,   142,   142,
     142,   142,   142,    45,    63,     0,   142,   142,   156,   142,
     123,     0,     0,    56,   139,     0,   143,   121,     0,   124,
     122,   175,     0,     0,    29,     0,    89,    23,   103,     0,
     102,    76,     0,    74,     0,    24,    72,     0,    56,    25,
     131,   112,    23,    23,     0,     0,     0,   164,     0,   169,
       0,   168,   172,     0,   171,     0,    51,    50,   142,    68,
       0,    35,    36,    37,    38,    39,    40,    62,     0,    54,
      60,     0,    58,   137,    23,   145,    14,   142,    30,     0,
       0,     0,    89,     0,     0,    96,   100,   101,    78,     0,
      27,   142,    34,   111,    25,   109,   128,   142,   142,   142,
      48,   165,   142,   166,   142,    55,    69,   174,    47,    53,
      23,     0,    32,    86,    87,    88,    81,     0,    99,    23,
      85,    90,    92,    93,    91,   104,     0,     0,    94,    23,
      75,    26,    71,   159,   160,     0,   167,   170,     0,   140,
      84,     0,     0,     0,    95,   142,   157,   142,   138,    98,
      25,    23,   158,     0,   142,   161
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -249,  -249,  -249,  -249,  -249,    -2,   321,   -17,  -117,  -249,
    -249,  -249,  -249,   212,  -134,   -61,   -70,   -85,   -96,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -135,  -249,  -249,
    -249,  -249,  -249,   156,   138,  -249,  -234,  -248,   -16,  -249,
     121,  -249,  -249,   213,  -249,   436,  -249,   445,  -249,   216,
     448,  -249,  -249,  -249,   377,  -249,  -249,  -249,  -249,  -249,
     397,   223,  -249,   -37,  -249,  -249,  -249,   -12,   345,  -110,
    -249,  -249,  -249,  -249,  -249,  -164,  -249,  -249,  -249,   173,
    -249,   175,  -249,  -249,  -249,  -249
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,    16,    17,   217,    19,   156,   149,   225,
      20,    65,   138,   139,   152,   107,   108,   109,   110,   258,
     111,   112,   185,   227,    21,    72,   146,    76,    22,    67,
     142,    68,   272,   273,   310,   311,   218,   274,   275,   313,
      69,    70,   219,   220,   314,   315,    24,   316,    81,   161,
     317,    27,    28,    50,    51,    29,    30,    31,    32,    74,
      82,   162,    33,   113,   114,   300,   264,   155,   116,   117,
     118,   119,   336,   120,   121,   173,   122,   123,   240,   241,
     243,   244,   124,   186,    34,    35
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,    48,    49,    40,   172,   154,   206,   236,    43,   184,
     221,   269,   270,   271,   153,   212,   301,   226,   183,   125,
     213,   129,   130,    61,     6,    39,     8,     9,   154,   154,
     179,   154,   135,    12,    63,    47,    47,   177,   178,   312,
     180,    41,   231,   115,   115,   -16,   115,   115,   279,    47,
      15,    80,   328,  -108,   293,   127,   291,   -18,   -16,   306,
       3,    83,    49,   159,   160,   148,   294,   292,    42,   163,
     -18,   280,   164,   312,   158,   208,    93,    36,   276,   136,
      64,   154,   191,   192,   234,   235,   172,    54,   283,   238,
     153,   242,   206,   102,   222,    55,   245,   281,    37,    44,
     260,   223,   201,   266,   282,   239,   195,    38,   224,   257,
     197,   160,   261,   204,   262,    45,    46,   154,   154,   154,
     154,   154,   154,    47,    52,   325,   251,   252,   253,   254,
     255,   256,    77,   302,    78,     6,    39,     8,     9,     6,
      39,     8,     9,   320,    12,    53,   248,   322,    12,   250,
     249,   198,   296,   199,     6,    39,     8,     9,   269,   270,
     271,    15,   232,    12,   233,    15,   193,   231,   214,   194,
     215,   199,   195,   343,   115,   299,   197,   323,   324,    79,
      15,    56,    58,   126,     6,    39,     8,     9,   193,   165,
      57,   194,   166,    12,   195,   308,   196,   154,   197,   263,
     189,   190,   191,   192,   172,   267,   153,   224,    83,   242,
      15,   154,   318,   209,   319,   284,   166,   160,   247,    90,
     153,   199,   239,    93,   287,   342,    94,   199,    95,    96,
      97,    59,   205,   288,   345,    98,   199,    99,   100,   101,
     102,   103,    60,  -163,   290,    83,    62,   199,   105,    84,
      85,    86,   172,    87,    88,    89,    90,    91,    92,   295,
      93,  -142,   199,    94,    71,    95,    96,    97,   190,   191,
     192,   309,    98,    66,    99,   100,   101,   102,   103,   329,
     104,   319,   338,    73,   319,   105,    75,   131,   106,  -135,
     132,   133,   332,   134,   205,     6,    39,     8,     9,   137,
     140,   141,   145,   334,    12,   309,   143,    83,   144,   150,
     147,    84,    85,    86,   167,    87,    88,    89,    90,    91,
      92,   203,    93,  -142,   284,    94,   168,    95,    96,    97,
     169,   341,   170,   171,    98,   174,    99,   100,   101,   102,
     103,   175,   104,     6,    39,     8,     9,   105,   176,   181,
     106,  -133,    12,    83,   187,   188,   189,   190,   191,   192,
     224,   200,   207,   210,    90,   211,   216,   228,    93,   199,
     229,    94,   230,    95,    96,    97,   237,   192,   246,   259,
      98,   265,    99,   100,   101,   102,   103,   278,   321,   297,
      83,   303,   289,   105,    84,    85,    86,   304,    87,    88,
      89,    90,    91,    92,   298,    93,   305,   333,    94,   335,
      95,    96,    97,    54,   337,   339,   340,    98,  -108,    99,
     100,   101,   102,   103,   182,   104,   344,   268,   307,   331,
     105,    83,   277,   106,  -136,    84,    85,    86,    23,    87,
      88,    89,    90,    91,    92,   330,    93,    25,   285,    94,
      26,    95,    96,    97,   128,   157,   286,     0,    98,   202,
      99,   100,   101,   102,   103,   326,   104,     0,     0,   327,
       0,   105,    83,     0,   106,  -134,    84,    85,    86,     0,
      87,    88,    89,    90,    91,    92,     0,    93,     0,     0,
      94,     0,    95,    96,    97,     0,     0,     0,    83,    98,
       0,    99,   100,   101,   102,   103,     0,   104,     0,    90,
       0,     0,   105,    93,     0,   106,    94,     0,    95,    96,
      97,     0,     0,     0,    83,    98,     0,    99,   100,   101,
     102,   103,     0,     0,     0,    90,     0,     0,   105,    93,
    -142,   151,    94,     0,    95,    96,    97,    83,     0,     0,
       0,    98,     0,    99,   100,   101,   102,   103,    90,     0,
       0,     0,    93,     0,   105,    94,     0,    95,    96,    97,
       0,    83,     0,     0,    98,     0,    99,   100,   101,   102,
     103,  -163,    90,     0,     0,     0,    93,   105,     0,    94,
       0,    95,    96,    97,     0,     0,     0,     0,    98,     0,
      99,   100,   101,   102,   103,   188,   189,   190,   191,   192,
       4,   105,     5,     6,     7,     8,     9,    10,    11,     0,
       0,     0,    12,     0,    13,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15
};

static const yytype_int16 yycheck[] =
{
       2,    18,    18,     5,    89,    75,   116,   171,    10,   105,
     145,    10,    11,    12,    75,   132,   264,   151,   103,    56,
     137,    58,    59,    40,     4,     5,     6,     7,    98,    99,
     100,   101,     1,    13,     1,    17,    17,    98,    99,   273,
     101,     1,   159,    55,    56,    17,    58,    59,    32,    17,
      30,    53,   300,    47,    49,    57,    49,    17,    30,    58,
       0,    14,    78,    80,    80,    59,    61,    60,    28,    48,
      30,    55,    51,   307,    56,    56,    29,    28,    58,    48,
      47,   151,    41,    42,   169,   170,   171,    49,    56,   174,
     151,   176,   202,    46,    51,    57,   181,    51,    49,    30,
     196,    58,   114,    49,    58,   175,    50,    58,    54,   194,
      54,   127,   197,   115,   199,    30,    30,   187,   188,   189,
     190,   191,   192,    17,    49,   289,   187,   188,   189,   190,
     191,   192,    49,   267,    51,     4,     5,     6,     7,     4,
       5,     6,     7,   278,    13,    47,    51,   281,    13,   186,
      55,    49,   248,    51,     4,     5,     6,     7,    10,    11,
      12,    30,   164,    13,   166,    30,    44,   284,    49,    47,
      51,    51,    50,   337,   186,    55,    54,   287,   288,    48,
      30,    57,    57,    48,     4,     5,     6,     7,    44,    48,
      47,    47,    51,    13,    50,    15,    52,   267,    54,   201,
      39,    40,    41,    42,   289,    52,   267,    54,    14,   294,
      30,   281,    49,    48,    51,   232,    51,   233,    48,    25,
     281,    51,   292,    29,    48,   335,    32,    51,    34,    35,
      36,    57,     1,    48,   344,    41,    51,    43,    44,    45,
      46,    47,    47,    49,    48,    14,    47,    51,    54,    18,
      19,    20,   337,    22,    23,    24,    25,    26,    27,    48,
      29,    30,    51,    32,    57,    34,    35,    36,    40,    41,
      42,   273,    41,    53,    43,    44,    45,    46,    47,    49,
      49,    51,    49,    30,    51,    54,    52,    48,    57,    58,
      30,    48,   309,    48,     1,     4,     5,     6,     7,    30,
      30,    49,    30,   319,    13,   307,    49,    14,    57,    30,
      49,    18,    19,    20,    49,    22,    23,    24,    25,    26,
      27,    30,    29,    30,   341,    32,    49,    34,    35,    36,
      47,   333,    47,    47,    41,    47,    43,    44,    45,    46,
      47,    60,    49,     4,     5,     6,     7,    54,    61,    47,
      57,    58,    13,    14,    37,    38,    39,    40,    41,    42,
      54,    58,    58,    58,    25,    58,    57,    30,    29,    51,
      30,    32,    30,    34,    35,    36,    49,    42,    48,    30,
      41,    49,    43,    44,    45,    46,    47,    30,    55,    58,
      14,    53,    49,    54,    18,    19,    20,    53,    22,    23,
      24,    25,    26,    27,    48,    29,    53,    47,    32,    21,
      34,    35,    36,    49,    49,    49,    30,    41,    47,    43,
      44,    45,    46,    47,   103,    49,    48,   215,   272,   308,
      54,    14,   219,    57,    58,    18,    19,    20,     2,    22,
      23,    24,    25,    26,    27,   307,    29,     2,   232,    32,
       2,    34,    35,    36,    57,    78,   233,    -1,    41,   114,
      43,    44,    45,    46,    47,   292,    49,    -1,    -1,   294,
      -1,    54,    14,    -1,    57,    58,    18,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      32,    -1,    34,    35,    36,    -1,    -1,    -1,    14,    41,
      -1,    43,    44,    45,    46,    47,    -1,    49,    -1,    25,
      -1,    -1,    54,    29,    -1,    57,    32,    -1,    34,    35,
      36,    -1,    -1,    -1,    14,    41,    -1,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    25,    -1,    -1,    54,    29,
      30,    57,    32,    -1,    34,    35,    36,    14,    -1,    -1,
      -1,    41,    -1,    43,    44,    45,    46,    47,    25,    -1,
      -1,    -1,    29,    -1,    54,    32,    -1,    34,    35,    36,
      -1,    14,    -1,    -1,    41,    -1,    43,    44,    45,    46,
      47,    48,    25,    -1,    -1,    -1,    29,    54,    -1,    32,
      -1,    34,    35,    36,    -1,    -1,    -1,    -1,    41,    -1,
      43,    44,    45,    46,    47,    38,    39,    40,    41,    42,
       1,    54,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    -1,    13,    -1,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    67,    68,     0,     1,     3,     4,     5,     6,     7,
       8,     9,    13,    15,    16,    30,    69,    70,    71,    72,
      76,    90,    94,   111,   112,   113,   116,   117,   118,   121,
     122,   123,   124,   128,   150,   151,    28,    49,    58,     5,
      71,     1,    28,    71,    30,    30,    30,    17,    73,   104,
     119,   120,    49,    47,    49,    57,    57,    47,    57,    57,
      47,    73,    47,     1,    47,    77,    53,    95,    97,   106,
     107,    57,    91,    30,   125,    52,    93,    49,    51,    48,
      71,   114,   126,    14,    18,    19,    20,    22,    23,    24,
      25,    26,    27,    29,    32,    34,    35,    36,    41,    43,
      44,    45,    46,    47,    49,    54,    57,    81,    82,    83,
      84,    86,    87,   129,   130,   133,   134,   135,   136,   137,
     139,   140,   142,   143,   148,   129,    48,    71,   126,   129,
     129,    48,    30,    48,    48,     1,    48,    30,    78,    79,
      30,    49,    96,    49,    57,    30,    92,    49,    59,    74,
      30,    57,    80,    81,    82,   133,    73,   120,    56,    73,
     104,   115,   127,    48,    51,    48,    51,    49,    49,    47,
      47,    47,    83,   141,    47,    60,    61,    81,    81,    82,
      81,    47,    72,    83,    84,    88,   149,    37,    38,    39,
      40,    41,    42,    44,    47,    50,    52,    54,    49,    51,
      58,   133,   134,    30,    71,     1,   135,    58,    56,    48,
      58,    58,    74,    74,    49,    51,    57,    71,   102,   108,
     109,    93,    51,    58,    54,    75,    80,    89,    30,    30,
      30,    74,    71,    71,    83,    83,   141,    49,    83,    82,
     144,   145,    83,   146,   147,    83,    48,    48,    51,    55,
     129,    81,    81,    81,    81,    81,    81,    83,    85,    30,
      84,    83,    83,    71,   132,    49,    49,    52,    79,    10,
      11,    12,    98,    99,   103,   104,    58,   109,    30,    32,
      55,    51,    58,    56,    73,   115,   127,    48,    48,    49,
      48,    49,    60,    49,    61,    48,    84,    58,    48,    55,
     131,   103,    80,    53,    53,    53,    58,    99,    15,    71,
     100,   101,   102,   105,   110,   111,   113,   116,    49,    51,
      93,    55,    80,   135,   135,   141,   145,   147,   103,    49,
     100,   106,    73,    47,   104,    21,   138,    49,    49,    49,
      30,    71,   135,   141,    48,   135
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
      88,    89,    89,    90,    91,    92,    92,    93,    93,    94,
      96,    95,    97,    97,    98,    98,    99,    99,    99,    99,
     100,   100,   101,   101,   102,   103,   103,   104,   105,   107,
     106,   108,   108,   109,   110,   111,   111,   112,   113,   114,
     114,   115,   115,   116,   117,   118,   119,   119,   120,   121,
     121,   122,   122,   122,   123,   123,   124,   125,   126,   126,
     127,   127,   128,   129,   129,   129,   129,   131,   130,   132,
     130,   133,   133,   134,   134,   134,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   136,   137,   138,   138,
     139,   140,   141,   141,   142,   143,   143,   144,   144,   145,
     146,   146,   147,   149,   148,   150,   151,   151,   151,   151,
     151
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
       1,     3,     1,     4,     3,     4,     2,     2,     0,     4,
       0,     5,     2,     0,     3,     2,     2,     2,     2,     0,
       1,     1,     1,     1,     3,     3,     1,     3,     3,     0,
       4,     2,     1,     1,     1,     2,     2,     4,     3,     4,
       2,     1,     2,     3,     4,     3,     3,     1,     2,     1,
       1,     4,     4,     4,     4,     4,     4,     2,     4,     2,
       1,     2,     3,     2,     1,     1,     0,     0,     6,     0,
       5,     1,     0,     2,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     2,     6,     2,     0,
       5,     9,     1,     0,     3,     4,     4,     3,     1,     1,
       3,     1,     1,     0,     4,     4,     4,     4,     4,     4,
       4
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
#line 1829 "syntax.tab.c"
    break;

  case 12: /* global_declaration: error "semi"  */
#line 140 "syntax.y"
                                                                                {yyerror(" HINT: syntax error in global declaration\n"); yyerrok;}
#line 1835 "syntax.tab.c"
    break;

  case 13: /* global_declaration: error "rbrace"  */
#line 141 "syntax.y"
                                                                                {yyerror(" HINT: in global declaration\n"); yyerrok; }
#line 1841 "syntax.tab.c"
    break;

  case 14: /* typedef_declaration: "typedef" typename listspec "id" dims "semi"  */
#line 143 "syntax.y"
                                                                                {
                                                                                    /* αγνοούμε προς το παρόν listspec/dims για σύνθετους, κρατάμε base type */
                                                                                    if (!symtab_insert((yyvsp[-2].strval), SYM_TYPE, (yyvsp[-4].type))) {
                                                                                        YYERROR_FMT("Redeclaration of typedef '%s'", (yyvsp[-2].strval));
                                                                                    }
                                                                                }
#line 1852 "syntax.tab.c"
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
#line 1865 "syntax.tab.c"
    break;

  case 17: /* standard_type: "char"  */
#line 160 "syntax.y"
                                                                                {(yyval.type) = type_char;}
#line 1871 "syntax.tab.c"
    break;

  case 18: /* standard_type: "int"  */
#line 161 "syntax.y"
                                                                                {(yyval.type) = type_int;}
#line 1877 "syntax.tab.c"
    break;

  case 19: /* standard_type: "float"  */
#line 162 "syntax.y"
                                                                                {(yyval.type) = type_float;}
#line 1883 "syntax.tab.c"
    break;

  case 20: /* standard_type: "string"  */
#line 163 "syntax.y"
                                                                                {(yyval.type) = type_string;}
#line 1889 "syntax.tab.c"
    break;

  case 21: /* standard_type: "void"  */
#line 164 "syntax.y"
                                                                                {(yyval.type) = type_void;}
#line 1895 "syntax.tab.c"
    break;

  case 23: /* listspec: %empty  */
#line 166 "syntax.y"
                                                    {;}
#line 1901 "syntax.tab.c"
    break;

  case 25: /* dims: %empty  */
#line 169 "syntax.y"
                                             {;}
#line 1907 "syntax.tab.c"
    break;

  case 28: /* $@1: %empty  */
#line 173 "syntax.y"
                                             { current_type = (yyvsp[0].type); }
#line 1913 "syntax.tab.c"
    break;

  case 32: /* constdef: "id" dims "assign" init_value  */
#line 178 "syntax.y"
                                                                                {if (!current_type) current_type = type_error;
                                                                                    if (!symtab_insert((yyvsp[-3].strval), SYM_CONST, current_type)) {
                                                                                        YYERROR_FMT("Redeclaration of const '%s'", (yyvsp[-3].strval));
                                                                                    }
                                                                                }
#line 1923 "syntax.tab.c"
    break;

  case 35: /* expression: expression "orop" expression  */
#line 187 "syntax.y"
                                                                                {(yyval.type) = sem_binary_logical((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1929 "syntax.tab.c"
    break;

  case 36: /* expression: expression "andop" expression  */
#line 188 "syntax.y"
                                                                                {(yyval.type) = sem_binary_logical((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1935 "syntax.tab.c"
    break;

  case 37: /* expression: expression "equop" expression  */
#line 189 "syntax.y"
                                                                                {(yyval.type) = sem_binary_equality((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1941 "syntax.tab.c"
    break;

  case 38: /* expression: expression "relop" expression  */
#line 190 "syntax.y"
                                                                                {(yyval.type) = sem_binary_relational((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1947 "syntax.tab.c"
    break;

  case 39: /* expression: expression "addop" expression  */
#line 191 "syntax.y"
                                                                                {(yyval.type) = sem_binary_arith((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1953 "syntax.tab.c"
    break;

  case 40: /* expression: expression "mulop" expression  */
#line 192 "syntax.y"
                                                                                {(yyval.type) = sem_binary_arith((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 1959 "syntax.tab.c"
    break;

  case 41: /* expression: "notop" expression  */
#line 193 "syntax.y"
                                                                                { (yyval.type) = sem_unary_not((yyvsp[0].type), yylineno); }
#line 1965 "syntax.tab.c"
    break;

  case 42: /* expression: "addop" expression  */
#line 194 "syntax.y"
                                                                                { (yyval.type) = sem_unary_not((yyvsp[0].type), yylineno); }
#line 1971 "syntax.tab.c"
    break;

  case 43: /* expression: "sizeop" expression  */
#line 195 "syntax.y"
                                                                                { (yyval.type) = type_int; }
#line 1977 "syntax.tab.c"
    break;

  case 44: /* expression: "incdec" variable  */
#line 196 "syntax.y"
                                                                                { (yyval.type) = sem_unary_incdec((yyvsp[0].type), yylineno); }
#line 1983 "syntax.tab.c"
    break;

  case 45: /* expression: variable "incdec"  */
#line 197 "syntax.y"
                                                                                { (yyval.type) = sem_unary_incdec((yyvsp[-1].type), yylineno); }
#line 1989 "syntax.tab.c"
    break;

  case 46: /* expression: variable  */
#line 198 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[0].type);}
#line 1995 "syntax.tab.c"
    break;

  case 47: /* expression: variable "lparen" expression_list "rparen"  */
#line 199 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[-3].type);}
#line 2001 "syntax.tab.c"
    break;

  case 48: /* expression: "length" "lparen" general_expression "rparen"  */
#line 200 "syntax.y"
                                                                                {(yyval.type) = type_int;}
#line 2007 "syntax.tab.c"
    break;

  case 49: /* expression: constant  */
#line 201 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[0].type);}
#line 2013 "syntax.tab.c"
    break;

  case 50: /* expression: "lparen" general_expression "rparen"  */
#line 202 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[-1].type);}
#line 2019 "syntax.tab.c"
    break;

  case 51: /* expression: "lparen" standard_type "rparen"  */
#line 203 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[-1].type);}
#line 2025 "syntax.tab.c"
    break;

  case 52: /* expression: listexpression  */
#line 204 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[0].type);}
#line 2031 "syntax.tab.c"
    break;

  case 53: /* variable: variable "lbrack" general_expression "rbrack"  */
#line 206 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[-3].type);}
#line 2037 "syntax.tab.c"
    break;

  case 54: /* variable: variable "dot" "id"  */
#line 207 "syntax.y"
                                                                                {(yyval.type)= type_error;}
#line 2043 "syntax.tab.c"
    break;

  case 55: /* variable: "listfunc" "lparen" general_expression "rparen"  */
#line 208 "syntax.y"
                                                                                {(yyval.type)= type_error;}
#line 2049 "syntax.tab.c"
    break;

  case 56: /* variable: decltype "id"  */
#line 209 "syntax.y"
                                                                                {(yyval.type) = sem_use_variable((yyvsp[0].strval), yylineno); }
#line 2055 "syntax.tab.c"
    break;

  case 57: /* variable: "this"  */
#line 210 "syntax.y"
                                                                                {(yyval.type)= type_error;}
#line 2061 "syntax.tab.c"
    break;

  case 58: /* general_expression: general_expression "comma" general_expression  */
#line 212 "syntax.y"
                                                                                {(yyval.type) = (yyvsp[0].type);}
#line 2067 "syntax.tab.c"
    break;

  case 59: /* general_expression: assignment  */
#line 213 "syntax.y"
                                                                                {(yyval.type) = (yyvsp[0].type);}
#line 2073 "syntax.tab.c"
    break;

  case 60: /* assignment: variable "assign" assignment  */
#line 215 "syntax.y"
                                                                                {(yyval.type) = sem_check_assignment((yyvsp[-2].type), (yyvsp[0].type), yylineno);}
#line 2079 "syntax.tab.c"
    break;

  case 61: /* assignment: expression  */
#line 216 "syntax.y"
                                                                                {(yyval.type)=(yyvsp[0].type);}
#line 2085 "syntax.tab.c"
    break;

  case 62: /* expression_list: general_expression  */
#line 218 "syntax.y"
                                                                                {(yyval.type) = (yyvsp[0].type);}
#line 2091 "syntax.tab.c"
    break;

  case 63: /* expression_list: %empty  */
#line 219 "syntax.y"
                                                                                {(yyval.type) = type_void;}
#line 2097 "syntax.tab.c"
    break;

  case 64: /* constant: "cconst"  */
#line 221 "syntax.y"
                                                                                { (yyval.type) = type_char;   }
#line 2103 "syntax.tab.c"
    break;

  case 65: /* constant: "iconst"  */
#line 222 "syntax.y"
                                                                                { (yyval.type) = type_int;    }
#line 2109 "syntax.tab.c"
    break;

  case 66: /* constant: "fconst"  */
#line 223 "syntax.y"
                                                                                { (yyval.type) = type_float;  }
#line 2115 "syntax.tab.c"
    break;

  case 67: /* constant: "sconst"  */
#line 224 "syntax.y"
                                                                                { (yyval.type) = type_string; }
#line 2121 "syntax.tab.c"
    break;

  case 68: /* listexpression: "lbrack" list_elements "rbrack"  */
#line 227 "syntax.y"
                                                                              {(yyval.type) = sem_make_list_type((yyvsp[-1].type), yylineno);}
#line 2127 "syntax.tab.c"
    break;

  case 69: /* list_elements: list_elements "comma" assignment  */
#line 229 "syntax.y"
                                                                                { (yyval.type) = sem_find_list_element_type((yyvsp[-2].type), (yyvsp[0].type), yylineno); }
#line 2133 "syntax.tab.c"
    break;

  case 70: /* list_elements: assignment  */
#line 230 "syntax.y"
                                                                                { (yyval.type) = (yyvsp[0].type); }
#line 2139 "syntax.tab.c"
    break;

  case 73: /* enum_declaration: "enum" "id" enum_body "semi"  */
#line 235 "syntax.y"
                                                                                {Type *t = make_simple_type(TYPE_ENUM);
                                                                                    if (!symtab_insert((yyvsp[-2].strval), SYM_TYPE, t)) {
                                                                                        YYERROR_FMT("Redeclaration of enum '%s'", (yyvsp[-2].strval));
                                                                                    }
                                                                                }
#line 2149 "syntax.tab.c"
    break;

  case 75: /* id_list: id_list "comma" "id" initializer  */
#line 242 "syntax.y"
                                                                                {/* enum constants -> ακέραιοι */
                                                                                    if (!symtab_insert((yyvsp[-1].strval), SYM_ENUM_CONST, type_int)) {
                                                                                        YYERROR_FMT("Redeclaration of enum const '%s'", (yyvsp[-1].strval));
                                                                                    }
                                                                                }
#line 2159 "syntax.tab.c"
    break;

  case 76: /* id_list: "id" initializer  */
#line 247 "syntax.y"
                                                                                {if (!symtab_insert((yyvsp[-1].strval), SYM_ENUM_CONST, type_int)) {
                                                                                        YYERROR_FMT("Redeclaration of enum const '%s'", (yyvsp[-1].strval));
                                                                                    }
                                                                                }
#line 2168 "syntax.tab.c"
    break;

  case 78: /* initializer: %empty  */
#line 253 "syntax.y"
                                             {;}
#line 2174 "syntax.tab.c"
    break;

  case 79: /* class_declaration: "class" "id" class_body "semi"  */
#line 255 "syntax.y"
                                                                                {Type *t = make_simple_type(TYPE_CLASS);
                                                                                    if (!symtab_insert((yyvsp[-2].strval), SYM_TYPE, t)) {
                                                                                        YYERROR_FMT("Redeclaration of class '%s'", (yyvsp[-2].strval));
                                                                                    }
                                                                                }
#line 2184 "syntax.tab.c"
    break;

  case 80: /* $@2: %empty  */
#line 261 "syntax.y"
                                   {symtab_enter_scope();}
#line 2190 "syntax.tab.c"
    break;

  case 81: /* class_body: parent $@2 "lbrace" members_methods "rbrace"  */
#line 261 "syntax.y"
                                                                                             { symtab_leave_scope();}
#line 2196 "syntax.tab.c"
    break;

  case 82: /* parent: "colon" "id"  */
#line 262 "syntax.y"
                                                                                {Symbol *base = symtab_lookup((yyvsp[0].strval));
                                                                                    if (!base || base->kind != SYM_TYPE) {
                                                                                        YYERROR_FMT("Unknown base class '%s'", (yyvsp[0].strval));
                                                                                    }
                                                                                }
#line 2206 "syntax.tab.c"
    break;

  case 83: /* parent: %empty  */
#line 267 "syntax.y"
                                             {;}
#line 2212 "syntax.tab.c"
    break;

  case 89: /* access: %empty  */
#line 272 "syntax.y"
                                                                                                        { }
#line 2218 "syntax.tab.c"
    break;

  case 94: /* var_declaration: typename variabledefs "semi"  */
#line 280 "syntax.y"
                                                         { current_type = (yyvsp[-2].type); }
#line 2224 "syntax.tab.c"
    break;

  case 97: /* variabledef: listspec "id" dims  */
#line 288 "syntax.y"
                                                                                {if (!current_type) current_type = type_error;
                                                                                    /* Προς το παρόν αγνοούμε listspec/dims και δηλώνουμε απλό type */
                                                                                    if (!symtab_insert((yyvsp[-1].strval), SYM_VAR, current_type)) {
                                                                                        YYERROR_FMT("Redeclaration of '%s'", (yyvsp[-1].strval));
                                                                                    }
                                                                                }
#line 2235 "syntax.tab.c"
    break;

  case 99: /* $@3: %empty  */
#line 298 "syntax.y"
                            {symtab_enter_scope();}
#line 2241 "syntax.tab.c"
    break;

  case 100: /* union_body: $@3 "lbrace" fields "rbrace"  */
#line 298 "syntax.y"
                                                                                             { symtab_leave_scope();}
#line 2247 "syntax.tab.c"
    break;

  case 105: /* short_func_declaration: short_par_func_header "semi"  */
#line 307 "syntax.y"
                                                                                { symtab_leave_scope();}
#line 2253 "syntax.tab.c"
    break;

  case 106: /* short_func_declaration: nopar_func_header "semi"  */
#line 308 "syntax.y"
                                                                                { symtab_leave_scope();}
#line 2259 "syntax.tab.c"
    break;

  case 108: /* func_header_start: typename listspec "id"  */
#line 314 "syntax.y"
                                                                                {Type *ret = (yyvsp[-2].type);
                                                                                    if (!symtab_insert((yyvsp[0].strval), SYM_FUNC, ret)) {
                                                                                        YYERROR_FMT("Redeclaration of function '%s'", (yyvsp[0].strval));
                                                                                    }
                                                                                    symtab_enter_scope();   /* νέο scope για παραμέτρους+σώμα */
                                                                                }
#line 2270 "syntax.tab.c"
    break;

  case 114: /* union_declaration: "union" "id" union_body "semi"  */
#line 330 "syntax.y"
                                                                                {Type *t = make_simple_type(TYPE_UNION);
                                                                                    if (!symtab_insert((yyvsp[-2].strval), SYM_TYPE, t)) {
                                                                                        YYERROR_FMT("Redeclaration of union '%s'", (yyvsp[-2].strval));
                                                                                    }
                                                                                }
#line 2280 "syntax.tab.c"
    break;

  case 115: /* global_var_declaration: typename init_variabledefs "semi"  */
#line 337 "syntax.y"
                                                              { current_type = (yyvsp[-2].type); }
#line 2286 "syntax.tab.c"
    break;

  case 121: /* full_func_declaration: full_par_func_header "lbrace" decl_statements "rbrace"  */
#line 349 "syntax.y"
                                                                                                        { symtab_leave_scope();}
#line 2292 "syntax.tab.c"
    break;

  case 122: /* full_func_declaration: nopar_class_func_header "lbrace" decl_statements "rbrace"  */
#line 350 "syntax.y"
                                                                                                        { symtab_leave_scope();}
#line 2298 "syntax.tab.c"
    break;

  case 123: /* full_func_declaration: nopar_func_header "lbrace" decl_statements "rbrace"  */
#line 351 "syntax.y"
                                                                                                        { symtab_leave_scope();}
#line 2304 "syntax.tab.c"
    break;

  case 126: /* class_func_header_start: typename listspec func_class "id"  */
#line 356 "syntax.y"
                                                                                {Type *ret = (yyvsp[-3].type);
                                                                                    if (!symtab_insert((yyvsp[0].strval), SYM_FUNC, ret)) {
                                                                                        YYERROR_FMT("Redeclaration of method '%s'", (yyvsp[0].strval));
                                                                                    }
                                                                                    symtab_enter_scope();
                                                                                }
#line 2315 "syntax.tab.c"
    break;

  case 127: /* func_class: "id" "meth"  */
#line 363 "syntax.y"
                                                                                {Symbol *cls = symtab_lookup((yyvsp[-1].strval));
                                                                                    if (!cls || cls->kind != SYM_TYPE) {
                                                                                        YYERROR_FMT("Unknown class type '%s'", (yyvsp[-1].strval));
                                                                                    }
                                                                                }
#line 2325 "syntax.tab.c"
    break;

  case 129: /* parameter_list: typename pass_variabledef  */
#line 370 "syntax.y"
                                                        { current_type = (yyvsp[-1].type); }
#line 2331 "syntax.tab.c"
    break;

  case 131: /* pass_variabledef: "refer" "id"  */
#line 373 "syntax.y"
                                                                                {if (!current_type) current_type = type_error;
                                                                                    if (!symtab_insert((yyvsp[0].strval), SYM_VAR, current_type)) {
                                                                                        YYERROR_FMT("Redeclaration of parameter '%s'", (yyvsp[0].strval));
                                                                                    }
                                                                                }
#line 2341 "syntax.tab.c"
    break;

  case 136: /* decl_statements: %empty  */
#line 384 "syntax.y"
                                             {;}
#line 2347 "syntax.tab.c"
    break;

  case 137: /* $@4: %empty  */
#line 386 "syntax.y"
                                                           { current_type = (yyvsp[0].type); }
#line 2353 "syntax.tab.c"
    break;

  case 139: /* $@5: %empty  */
#line 387 "syntax.y"
                                                { current_type = (yyvsp[0].type); }
#line 2359 "syntax.tab.c"
    break;

  case 142: /* decltype: %empty  */
#line 389 "syntax.y"
                                                      {;}
#line 2365 "syntax.tab.c"
    break;

  case 145: /* statements: statements error "semi"  */
#line 392 "syntax.y"
                                                                                { YYERROR_FMT(" HINT:  error in statement - skipping until ';'"); yyerrok; }
#line 2371 "syntax.tab.c"
    break;

  case 159: /* if_tail: %empty  */
#line 408 "syntax.y"
                                                                     {;}
#line 2377 "syntax.tab.c"
    break;

  case 163: /* optexpr: %empty  */
#line 413 "syntax.y"
                                             {;}
#line 2383 "syntax.tab.c"
    break;

  case 173: /* $@6: %empty  */
#line 427 "syntax.y"
                                     {symtab_enter_scope();}
#line 2389 "syntax.tab.c"
    break;

  case 174: /* comp_statement: "lbrace" $@6 decl_statements "rbrace"  */
#line 427 "syntax.y"
                                                                                         { symtab_leave_scope();}
#line 2395 "syntax.tab.c"
    break;

  case 175: /* main_function: main_header "lbrace" decl_statements "rbrace"  */
#line 428 "syntax.y"
                                                                            { symtab_leave_scope();}
#line 2401 "syntax.tab.c"
    break;

  case 176: /* main_header: "int" "main" "lparen" "rparen"  */
#line 429 "syntax.y"
                                                                            {symtab_enter_scope();}
#line 2407 "syntax.tab.c"
    break;

  case 177: /* main_header: error "main" "lparen" "rparen"  */
#line 430 "syntax.y"
                                                                            {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; symtab_enter_scope();}
#line 2413 "syntax.tab.c"
    break;

  case 178: /* main_header: "int" error "lparen" "rparen"  */
#line 431 "syntax.y"
                                                                            {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; symtab_enter_scope();}
#line 2419 "syntax.tab.c"
    break;

  case 179: /* main_header: "int" "main" error "rparen"  */
#line 432 "syntax.y"
                                                                            {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; symtab_enter_scope();}
#line 2425 "syntax.tab.c"
    break;

  case 180: /* main_header: "int" "main" "lparen" error  */
#line 433 "syntax.y"
                                                                            {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; symtab_enter_scope();}
#line 2431 "syntax.tab.c"
    break;


#line 2435 "syntax.tab.c"

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

#line 435 "syntax.y"


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
