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
#line 10 "src/syntax.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>

    #include "settings.h"
    #include "symbolTable.h" 
    #include "semantics.h"
    #include "ir.h"
    
    extern FILE *yyin;
    extern char *yytext;
    extern IROperand codegen(ASTNode *node);
    extern void ir_print();
    extern int yylex();
    extern int yylineno;
    void yyerror(const char *s);
    int yyerrorno = 0;

    //functions
    static Type *current_type = NULL;
    static Type *current_function_type = NULL;
    static char *current_function_name = NULL;
    static int in_param_context = 0;

    /*class parsing state */
    static Type *current_class_type = NULL;
    static int   in_class_body = 0;
    static AccessKind current_member_access = ACC_PUBLIC;
    static const char *current_function_unqual = NULL;
    static int current_function_name_owned = 0;
    static Type       *current_method_class_type = NULL;
    static const char *current_method_class_name = NULL;


    #define YYERROR_BUFFER_SIZE 256
    #define YYERROR_FMT(...) \
        do { \
            char _yyerrbuf[YYERROR_BUFFER_SIZE]; \
            snprintf(_yyerrbuf, sizeof(_yyerrbuf), __VA_ARGS__); \
            yyerror(_yyerrbuf); \
        } while (0)

    //breaks down qualified names like "Class::method"
    static char *mk_qname(const char *cls, const char *meth) {
        if (!cls || !meth) return NULL;
        size_t n = strlen(cls) + 2 + strlen(meth) + 1; /* "::" */
        char *s = (char*)malloc(n);
        if (!s) return NULL;
        snprintf(s, n, "%s::%s", cls, meth);
        return s;
    }

#line 126 "build/generated/syntax.tab.c"

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
  YYSYMBOL_91_1 = 91,                      /* $@1  */
  YYSYMBOL_enum_body = 92,                 /* enum_body  */
  YYSYMBOL_id_list = 93,                   /* id_list  */
  YYSYMBOL_initializer = 94,               /* initializer  */
  YYSYMBOL_class_declaration = 95,         /* class_declaration  */
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
  YYSYMBOL_parameter_decl = 126,           /* parameter_decl  */
  YYSYMBOL_parameter_list = 127,           /* parameter_list  */
  YYSYMBOL_pass_variabledef = 128,         /* pass_variabledef  */
  YYSYMBOL_nopar_class_func_header = 129,  /* nopar_class_func_header  */
  YYSYMBOL_decl_statements = 130,          /* decl_statements  */
  YYSYMBOL_declarations = 131,             /* declarations  */
  YYSYMBOL_decltype = 132,                 /* decltype  */
  YYSYMBOL_loop_enter = 133,               /* loop_enter  */
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
  YYSYMBOL_149_4 = 149,                    /* $@4  */
  YYSYMBOL_150_5 = 150,                    /* $@5  */
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
#define YYLAST   539

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  87
/* YYNRULES -- Number of rules.  */
#define YYNRULES  179
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  342

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
       0,   179,   179,   185,   188,   190,   191,   192,   193,   194,
     195,   196,   200,   207,   218,   219,   229,   230,   231,   232,
     233,   235,   236,   238,   239,   241,   242,   244,   246,   247,
     249,   254,   255,   258,   265,   272,   279,   290,   297,   307,
     314,   321,   327,   335,   343,   348,   364,   370,   375,   380,
     386,   394,   400,   417,   423,   429,   443,   452,   456,   462,
     464,   465,   467,   472,   477,   482,   489,   495,   502,   508,
     509,   511,   511,   520,   522,   529,   538,   539,   542,   541,
     560,   569,   571,   572,   574,   575,   576,   577,   579,   580,
     582,   583,   586,   589,   590,   593,   624,   626,   626,   628,
     629,   631,   633,   635,   659,   685,   688,   714,   718,   723,
     724,   726,   728,   735,   738,   739,   741,   751,   752,   753,
     766,   777,   790,   791,   793,   800,   810,   812,   813,   817,
     818,   823,   825,   826,   827,   828,   830,   831,   837,   837,
     838,   840,   846,   848,   849,   850,   851,   852,   853,   854,
     855,   859,   863,   865,   866,   877,   878,   880,   887,   893,
     894,   896,   901,   904,   908,   909,   911,   916,   917,   919,
     924,   924,   925,   925,   927,   934,   943,   944,   945,   946
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
  "listspec", "dims", "dim", "const_declaration", "constdefs", "constdef",
  "init_value", "expression", "variable", "general_expression",
  "assignment", "expression_list", "constant", "listexpression",
  "list_elements", "init_values", "enum_declaration", "$@1", "enum_body",
  "id_list", "initializer", "class_declaration", "$@2", "parent",
  "members_methods", "access", "member_or_method", "member",
  "var_declaration", "variabledefs", "variabledef", "anonymous_union",
  "union_body", "$@3", "fields", "field", "method",
  "short_func_declaration", "short_par_func_header", "func_header_start",
  "parameter_types", "pass_list_dims", "nopar_func_header",
  "union_declaration", "global_var_declaration", "init_variabledefs",
  "init_variabledef", "func_declaration", "full_func_declaration",
  "full_par_func_header", "class_func_header_start", "func_class",
  "parameter_decl", "parameter_list", "pass_variabledef",
  "nopar_class_func_header", "decl_statements", "declarations", "decltype",
  "loop_enter", "statements", "statement", "expression_statement",
  "if_statement", "if_tail", "while_statement", "for_statement", "optexpr",
  "return_statement", "io_statement", "in_list", "in_item", "out_list",
  "out_item", "comp_statement", "$@4", "$@5", "main_function",
  "main_header", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-256)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-173)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -256,    92,   496,  -256,    11,   145,  -256,    99,  -256,  -256,
     145,    10,  -256,    80,    96,  -256,  -256,  -256,   111,   131,
    -256,  -256,  -256,  -256,  -256,   105,   112,   104,  -256,  -256,
    -256,  -256,   110,   124,   137,  -256,   164,   157,  -256,   131,
     185,    27,   203,   184,  -256,  -256,    44,   195,   241,  -256,
     228,  -256,  -256,  -256,    39,  -256,   216,   216,   126,   216,
     216,   206,   234,   219,   223,    20,  -256,   244,  -256,   247,
    -256,   229,   226,   242,  -256,   250,   278,  -256,  -256,   288,
    -256,  -256,    45,   115,  -256,   125,  -256,   279,   286,   300,
     308,   310,   398,   311,   299,   315,  -256,  -256,  -256,  -256,
    -256,   444,   444,    19,   444,   313,   173,  -256,   444,   362,
     490,   118,   251,  -256,  -256,  -256,   291,   262,   509,   307,
    -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,   320,  -256,
      29,   155,   321,   323,  -256,  -256,  -256,  -256,  -256,  -256,
     170,  -256,   203,  -256,   312,  -256,   145,   335,   336,     9,
    -256,  -256,  -256,  -256,   356,  -256,  -256,  -256,  -256,  -256,
     145,  -256,   145,  -256,  -256,   444,   444,   398,   339,   357,
     347,   444,    19,   444,   358,   146,  -256,    58,  -256,   444,
     350,   175,  -256,    60,   216,   400,   444,   444,   444,   444,
     444,   444,  -256,   421,   377,   444,   444,  -256,   444,  -256,
     509,   307,    40,   288,  -256,  -256,   356,  -256,  -256,  -256,
       7,   374,  -256,   302,   288,  -256,    25,  -256,   195,    30,
    -256,   349,  -256,  -256,   250,    33,  -256,   180,   198,   364,
    -256,  -256,   205,    58,    -2,  -256,   339,    -7,  -256,   218,
    -256,  -256,   444,  -256,   353,   366,   143,   171,   304,   147,
     358,  -256,   339,   368,  -256,  -256,    87,  -256,   288,   266,
    -256,  -256,   374,  -256,   490,   361,   369,   372,    14,   130,
     273,  -256,  -256,  -256,   396,  -256,  -256,  -256,  -256,   348,
    -256,   398,  -256,  -256,    19,  -256,   444,  -256,  -256,  -256,
    -256,  -256,  -256,   289,  -256,   288,  -256,    55,  -256,  -256,
    -256,   380,   130,  -256,   406,  -256,  -256,  -256,  -256,  -256,
    -256,   390,   389,  -256,   195,   419,   348,   399,  -256,  -256,
    -256,  -256,   374,  -256,  -256,  -256,   405,   402,    39,  -256,
     348,  -256,  -256,   444,  -256,  -256,    33,  -256,   224,  -256,
     348,  -256
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,     0,     0,    16,     0,    18,    19,
       0,     0,    20,     0,     0,    15,     3,     5,     0,    22,
      14,     6,     7,     8,   117,     0,     0,     0,     9,    10,
      11,   118,     0,     0,     0,     2,     0,     0,    17,    22,
       0,     0,     0,    81,    97,    71,    24,    77,     0,   115,
       0,    21,    13,   103,     0,   104,   139,   139,     0,   139,
     139,     0,     0,     0,     0,     0,    24,     0,    29,     0,
      78,     0,     0,     0,   125,    95,     0,   116,   113,     0,
     124,   111,    22,     0,   128,     0,   138,     0,     0,     0,
       0,     0,   139,     0,     0,     0,    55,    63,    64,    65,
      62,   139,   139,   139,   139,     0,   139,   152,   139,   170,
      59,    44,     0,    57,    47,    50,     0,   139,     0,   134,
     142,   143,   144,   145,   146,   147,   148,   149,     0,   131,
       0,     0,     0,     0,   176,    24,   177,   178,   179,   175,
       0,    27,     0,    80,     0,   112,     0,     0,     0,     0,
      23,    76,    24,   114,   109,    24,   129,   108,   126,   105,
       0,   123,     0,   150,   151,   139,   139,   139,   159,     0,
       0,   139,   139,   139,    40,    44,    39,    42,    41,   139,
       0,     0,    68,     0,   139,     0,   139,   139,   139,   139,
     139,   139,    43,    61,     0,   139,   139,   153,   139,   121,
       0,   132,    54,     0,   141,   119,     0,   122,   120,   174,
       0,   139,    28,    87,     0,   101,     0,   100,    77,     0,
      72,     0,    26,   130,   110,    22,   127,     0,     0,     0,
      54,   161,     0,   166,     0,   165,   169,     0,   168,     0,
      49,    48,   139,    66,     0,     0,    33,    34,    35,    36,
      37,    38,    60,     0,    52,    58,     0,    56,     0,     0,
      94,    12,   139,    30,    31,     0,     0,     0,    87,     0,
       0,    98,    99,    75,     0,    73,    25,   109,   107,   139,
     140,   139,    46,   162,   139,   163,   139,    53,    67,   171,
     173,    45,    51,     0,   137,     0,    70,     0,    84,    85,
      86,     0,     0,    97,     0,    83,    88,    90,    91,    89,
     102,     0,     0,    92,    77,   156,   139,     0,   164,   167,
     136,    93,   139,    32,    79,    82,     0,    24,     0,    74,
     139,   154,   157,   139,    69,    96,    22,   155,     0,   140,
     139,   158
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -256,  -256,  -256,  -256,  -256,    -1,    -5,   354,    32,   -30,
    -256,  -256,  -256,   317,  -255,   -67,   -93,   -89,   -96,  -256,
    -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -212,  -256,
    -256,  -256,  -256,   193,   161,  -256,  -242,  -185,   -16,  -256,
     167,  -256,  -256,   255,  -256,   470,  -256,   472,  -256,   252,
     479,  -256,  -256,  -256,   403,  -256,  -256,  -256,  -256,  -256,
     322,   425,  -256,  -256,   -44,  -256,   -37,   153,   376,  -115,
    -256,  -256,  -256,  -256,  -256,  -153,  -256,  -256,  -256,   202,
    -256,   208,  -256,  -256,  -256,  -256,  -256
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,    16,    17,   214,    19,    20,   155,    75,
     150,    21,    67,    68,   263,   110,   111,   112,   113,   253,
     114,   115,   183,   297,    22,    73,   148,   219,    77,    23,
     144,    70,   268,   269,   305,   306,   215,   270,   260,   308,
      71,    72,   216,   217,   309,   310,    25,   311,    83,   157,
     312,    28,    29,    48,    49,    30,    31,    32,    33,    50,
      84,    85,   158,    34,   116,   117,   169,   316,   119,   120,
     121,   122,   331,   123,   124,   170,   125,   126,   234,   235,
     237,   238,   127,   184,   185,    35,    36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    18,    47,   168,   204,    42,   273,   296,   175,   175,
     177,   175,   182,   128,   229,   132,   133,   181,   259,   118,
     118,   138,   118,   118,   265,   266,   267,   307,    64,     6,
      38,     8,     9,    86,   174,   176,   140,   178,    12,    37,
      43,   221,   285,     6,    38,     8,     9,   283,    96,    82,
      51,    52,    12,   130,   286,    15,   261,   -15,   284,   152,
     307,   149,    51,    47,   222,   105,   156,   334,   139,    15,
     -15,    62,   301,   293,    65,   152,   227,   228,   168,   233,
     200,   274,   232,   271,   236,   206,   204,    81,   275,   277,
     239,  -106,     3,   175,   175,   175,   175,   175,   175,   255,
      40,   154,   329,    74,   252,   210,   322,   256,   194,   257,
      44,   242,   196,   323,   156,   243,   -17,   203,   175,   246,
     247,   248,   249,   250,   251,   224,    45,    41,   317,   -17,
       6,    38,     8,     9,     6,    38,     8,     9,   198,    12,
     244,    46,   292,    12,   264,   303,   288,   118,    51,     6,
      38,     8,     9,    55,    53,   225,    15,   130,    12,    54,
      15,    56,   192,   159,   315,   193,   160,    57,   194,   175,
     195,    58,   196,   161,   129,    15,   162,     6,    38,     8,
       9,   187,   188,   189,   190,   191,    12,    86,   190,   191,
     192,   233,   168,   193,    59,   264,   194,   236,    93,   258,
     196,   332,    96,   207,    61,    97,   162,    98,    99,   100,
     188,   189,   190,   191,   101,   337,   102,   103,   104,   105,
     106,    60,   211,   241,   149,   341,   198,   108,   279,   175,
      86,   198,    63,    66,    87,    88,    89,    69,    90,    91,
      92,    93,    94,    95,   338,    96,   280,    76,    97,   198,
      98,    99,   100,   282,   134,   264,   198,   101,    80,   102,
     103,   104,   105,   106,   135,   107,   287,   136,   304,   198,
     108,   137,   339,   109,  -135,   198,    86,   143,   145,   321,
      87,    88,    89,   146,    90,    91,    92,    93,    94,    95,
      78,    96,    79,   141,    97,   142,    98,    99,   100,   147,
     197,   304,   198,   101,   149,   102,   103,   104,   105,   106,
     151,   107,   265,   266,   267,   294,   108,   295,   152,   109,
    -133,    86,   313,   336,   295,    87,    88,    89,   163,    90,
      91,    92,    93,    94,    95,   164,    96,  -139,   320,    97,
     295,    98,    99,   100,   189,   190,   191,   165,   101,   199,
     102,   103,   104,   105,   106,   166,   107,   167,   171,   172,
     179,   108,    86,  -172,   109,   218,    87,    88,    89,   213,
      90,    91,    92,    93,    94,    95,   173,    96,   205,   208,
      97,   209,    98,    99,   100,   220,   223,   230,    86,   101,
     198,   102,   103,   104,   105,   106,   231,   107,   240,    93,
     191,   245,   108,    96,   276,   109,    97,   254,    98,    99,
     100,   289,    86,   281,   298,   101,   291,   102,   103,   104,
     105,   106,   299,    93,   290,   300,   314,    96,   108,   324,
      97,   262,    98,    99,   100,    86,   327,   328,    55,   101,
     330,   102,   103,   104,   105,   106,    93,  -160,   333,  -106,
      96,  -139,   108,    97,   335,    98,    99,   100,    86,   212,
     180,   302,   101,   325,   102,   103,   104,   105,   106,    93,
     326,   272,    24,    96,    26,   108,    97,   278,    98,    99,
     100,    27,   153,   131,   226,   101,   318,   102,   103,   104,
     105,   106,   340,   201,   319,     0,     0,     4,   108,     5,
       6,     7,     8,     9,    10,    11,     0,     0,     0,    12,
       0,    13,    14,     6,    38,     8,     9,     0,     0,     0,
       0,     0,    12,     0,     0,     0,    15,   186,   187,   188,
     189,   190,   191,     0,     0,     0,     0,     0,     0,   202
};

static const yytype_int16 yycheck[] =
{
       5,     2,    18,    92,   119,    10,   218,   262,   101,   102,
     103,   104,   108,    57,   167,    59,    60,   106,   203,    56,
      57,     1,    59,    60,    10,    11,    12,   269,     1,     4,
       5,     6,     7,    14,   101,   102,    66,   104,    13,    28,
      30,    32,    49,     4,     5,     6,     7,    49,    29,    54,
      17,    19,    13,    58,    61,    30,    49,    17,    60,    30,
     302,    54,    17,    79,    55,    46,    82,   322,    48,    30,
      30,    39,    58,   258,    47,    30,   165,   166,   167,   172,
     117,    51,   171,    58,   173,    56,   201,    48,    58,    56,
     179,    47,     0,   186,   187,   188,   189,   190,   191,   195,
       1,    56,   314,    59,   193,   135,    51,   196,    50,   198,
      30,    51,    54,    58,   130,    55,    17,   118,   211,   186,
     187,   188,   189,   190,   191,   155,    30,    28,   281,    30,
       4,     5,     6,     7,     4,     5,     6,     7,    51,    13,
     184,    30,    55,    13,   211,    15,   242,   184,    17,     4,
       5,     6,     7,    49,    49,   160,    30,   162,    13,    47,
      30,    57,    44,    48,   279,    47,    51,    57,    50,   262,
      52,    47,    54,    48,    48,    30,    51,     4,     5,     6,
       7,    38,    39,    40,    41,    42,    13,    14,    41,    42,
      44,   284,   281,    47,    57,   262,    50,   286,    25,   200,
      54,   316,    29,    48,    47,    32,    51,    34,    35,    36,
      39,    40,    41,    42,    41,   330,    43,    44,    45,    46,
      47,    57,    52,    48,    54,   340,    51,    54,    48,   322,
      14,    51,    47,    30,    18,    19,    20,    53,    22,    23,
      24,    25,    26,    27,   333,    29,    48,    52,    32,    51,
      34,    35,    36,    48,    48,   322,    51,    41,    30,    43,
      44,    45,    46,    47,    30,    49,    48,    48,   269,    51,
      54,    48,    48,    57,    58,    51,    14,    30,    49,   295,
      18,    19,    20,    57,    22,    23,    24,    25,    26,    27,
      49,    29,    51,    49,    32,    51,    34,    35,    36,    57,
      49,   302,    51,    41,    54,    43,    44,    45,    46,    47,
      32,    49,    10,    11,    12,    49,    54,    51,    30,    57,
      58,    14,    49,   328,    51,    18,    19,    20,    49,    22,
      23,    24,    25,    26,    27,    49,    29,    30,    49,    32,
      51,    34,    35,    36,    40,    41,    42,    47,    41,    58,
      43,    44,    45,    46,    47,    47,    49,    47,    47,    60,
      47,    54,    14,     1,    57,    30,    18,    19,    20,    57,
      22,    23,    24,    25,    26,    27,    61,    29,    58,    58,
      32,    58,    34,    35,    36,    49,    30,    30,    14,    41,
      51,    43,    44,    45,    46,    47,    49,    49,    48,    25,
      42,     1,    54,    29,    55,    57,    32,    30,    34,    35,
      36,    58,    14,    49,    53,    41,    48,    43,    44,    45,
      46,    47,    53,    25,    58,    53,    30,    29,    54,    49,
      32,    57,    34,    35,    36,    14,    30,    47,    49,    41,
      21,    43,    44,    45,    46,    47,    25,    49,    49,    47,
      29,    30,    54,    32,    49,    34,    35,    36,    14,   142,
     106,   268,    41,   302,    43,    44,    45,    46,    47,    25,
     303,   216,     2,    29,     2,    54,    32,   225,    34,    35,
      36,     2,    79,    58,   162,    41,   284,    43,    44,    45,
      46,    47,   339,   117,   286,    -1,    -1,     1,    54,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    13,
      -1,    15,    16,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    13,    -1,    -1,    -1,    30,    37,    38,    39,
      40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    67,    68,     0,     1,     3,     4,     5,     6,     7,
       8,     9,    13,    15,    16,    30,    69,    70,    71,    72,
      73,    77,    90,    95,   111,   112,   113,   116,   117,   118,
     121,   122,   123,   124,   129,   151,   152,    28,     5,    72,
       1,    28,    72,    30,    30,    30,    30,   104,   119,   120,
     125,    17,    74,    49,    47,    49,    57,    57,    47,    57,
      57,    47,    74,    47,     1,    47,    30,    78,    79,    53,
      97,   106,   107,    91,    59,    75,    52,    94,    49,    51,
      30,    48,    72,   114,   126,   127,    14,    18,    19,    20,
      22,    23,    24,    25,    26,    27,    29,    32,    34,    35,
      36,    41,    43,    44,    45,    46,    47,    49,    54,    57,
      81,    82,    83,    84,    86,    87,   130,   131,   132,   134,
     135,   136,   137,   139,   140,   142,   143,   148,   130,    48,
      72,   127,   130,   130,    48,    30,    48,    48,     1,    48,
      75,    49,    51,    30,    96,    49,    57,    57,    92,    54,
      76,    32,    30,   120,    56,    74,   104,   115,   128,    48,
      51,    48,    51,    49,    49,    47,    47,    47,    83,   132,
     141,    47,    60,    61,    81,    82,    81,    82,    81,    47,
      73,    83,    84,    88,   149,   150,    37,    38,    39,    40,
      41,    42,    44,    47,    50,    52,    54,    49,    51,    58,
     132,   134,    30,    71,   135,    58,    56,    48,    58,    58,
      75,    52,    79,    57,    71,   102,   108,   109,    30,    93,
      49,    32,    55,    30,    75,    72,   126,    83,    83,   141,
      30,    49,    83,    82,   144,   145,    83,   146,   147,    83,
      48,    48,    51,    55,   130,     1,    81,    81,    81,    81,
      81,    81,    83,    85,    30,    84,    83,    83,    71,   103,
     104,    49,    57,    80,    81,    10,    11,    12,    98,    99,
     103,    58,   109,    94,    51,    58,    55,    56,   115,    48,
      48,    49,    48,    49,    60,    49,    61,    48,    84,    58,
      58,    48,    55,   103,    49,    51,    80,    89,    53,    53,
      53,    58,    99,    15,    71,   100,   101,   102,   105,   110,
     111,   113,   116,    49,    30,   135,   133,   141,   145,   147,
      49,   104,    51,    58,    49,   100,   106,    30,    47,    94,
      21,   138,   135,    49,    80,    49,    72,   135,    83,    48,
     133,   135
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    68,    68,    69,    69,    69,    69,    69,
      69,    69,    70,    71,    72,    72,    73,    73,    73,    73,
      73,    74,    74,    75,    75,    76,    76,    77,    78,    78,
      79,    80,    80,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    82,    82,    82,    82,    82,    83,    83,    84,    84,
      85,    85,    86,    86,    86,    86,    87,    88,    88,    89,
      89,    91,    90,    92,    93,    93,    94,    94,    96,    95,
      97,    97,    98,    98,    99,    99,    99,    99,   100,   100,
     101,   101,   102,   103,   103,   104,   105,   107,   106,   108,
     108,   109,   110,   111,   111,   112,   113,   114,   114,   115,
     115,   116,   117,   118,   119,   119,   120,   121,   121,   122,
     122,   122,   123,   123,   124,   125,   126,   127,   127,   128,
     128,   129,   130,   130,   130,   130,   131,   131,   132,   132,
     133,   134,   134,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   136,   137,   138,   138,   139,   140,   141,
     141,   142,   143,   143,   144,   144,   145,   146,   146,   147,
     149,   148,   150,   148,   151,   152,   152,   152,   152,   152
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     6,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     2,     0,     3,     2,     4,     3,     1,
       4,     1,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     2,     1,     4,     4,     1,     3,     3,
       1,     4,     3,     4,     2,     1,     3,     1,     3,     1,
       1,     0,     1,     1,     1,     1,     3,     3,     1,     3,
       1,     0,     5,     3,     4,     2,     2,     0,     0,     8,
       2,     0,     3,     2,     2,     2,     2,     0,     1,     1,
       1,     1,     3,     3,     1,     2,     3,     0,     4,     2,
       1,     1,     1,     2,     2,     4,     2,     4,     2,     1,
       2,     3,     4,     3,     3,     1,     2,     1,     1,     4,
       4,     4,     4,     4,     3,     2,     2,     3,     1,     1,
       2,     3,     2,     1,     1,     0,     5,     4,     1,     0,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     2,     6,     2,     0,     6,    10,     1,
       0,     3,     4,     4,     3,     1,     1,     3,     1,     1,
       0,     4,     0,     4,     4,     4,     4,     4,     4,     4
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
  case 2: /* program: global_declarations main_function  */
#line 179 "src/syntax.y"
                                                                                {
                                                                                    extern ASTNode *ast_root;
                                                                                    ast_root = ast_make_program((yyvsp[-1].node), (yyvsp[0].stmt).node, yylineno);
                                                                                    //sem_check_undefined_prototypes();
                                                                                }
#line 1840 "build/generated/syntax.tab.c"
    break;

  case 3: /* global_declarations: global_declarations global_declaration  */
#line 185 "src/syntax.y"
                                                                                {   if ((yyvsp[-1].node)) (yyval.node) = ast_list_append((yyvsp[-1].node), (yyvsp[0].node),yylineno);
                                                                                    else (yyval.node) = (yyvsp[0].node);
                                                                                }
#line 1848 "build/generated/syntax.tab.c"
    break;

  case 4: /* global_declarations: %empty  */
#line 188 "src/syntax.y"
                                                                                {(yyval.node) = NULL;}
#line 1854 "build/generated/syntax.tab.c"
    break;

  case 5: /* global_declaration: typedef_declaration  */
#line 190 "src/syntax.y"
                                                                                {(yyval.node) = NULL;}
#line 1860 "build/generated/syntax.tab.c"
    break;

  case 6: /* global_declaration: const_declaration  */
#line 191 "src/syntax.y"
                                                                                {(yyval.node) = NULL;}
#line 1866 "build/generated/syntax.tab.c"
    break;

  case 7: /* global_declaration: enum_declaration  */
#line 192 "src/syntax.y"
                                                                                {(yyval.node) = NULL;}
#line 1872 "build/generated/syntax.tab.c"
    break;

  case 8: /* global_declaration: class_declaration  */
#line 193 "src/syntax.y"
                                                                                {(yyval.node) = NULL;}
#line 1878 "build/generated/syntax.tab.c"
    break;

  case 9: /* global_declaration: union_declaration  */
#line 194 "src/syntax.y"
                                                                                {(yyval.node) = NULL;}
#line 1884 "build/generated/syntax.tab.c"
    break;

  case 10: /* global_declaration: global_var_declaration  */
#line 195 "src/syntax.y"
                                                                                {(yyval.node) = (yyvsp[0].node); }
#line 1890 "build/generated/syntax.tab.c"
    break;

  case 11: /* global_declaration: func_declaration  */
#line 196 "src/syntax.y"
                                                                                {(yyval.node) = (yyvsp[0].stmt).node;}
#line 1896 "build/generated/syntax.tab.c"
    break;

  case 12: /* typedef_declaration: "typedef" typename listspec "id" dims "semi"  */
#line 200 "src/syntax.y"
                                                                                {
                                                                                    /* αγνοούμε προς το παρόν listspec/dims για σύνθετους, κρατάμε base type */
                                                                                    if (!symtab_insert((yyvsp[-2].strval), SYM_TYPE, (yyvsp[-4].type))) {
                                                                                        YYERROR_FMT("Redeclaration of typedef '%s'", (yyvsp[-2].strval));
                                                                                    }
                                                                                }
#line 1907 "build/generated/syntax.tab.c"
    break;

  case 13: /* type_with_list: typename listspec  */
#line 207 "src/syntax.y"
                                                                                {
                                                                                    Type *t = (yyvsp[-1].type);
                                                                                    if ((yyvsp[0].intval)) {
                                                                                       (yyval.type) = sem_make_list_type(t, yylineno);
                                                                                    } else {
                                                                                        (yyval.type) = t;
                                                                                    }
                                                                                    current_type = (yyval.type);
                                                                                    }
#line 1921 "build/generated/syntax.tab.c"
    break;

  case 14: /* typename: standard_type  */
#line 218 "src/syntax.y"
                                                                                {(yyval.type) = (yyvsp[0].type); current_type = (yyval.type);}
#line 1927 "build/generated/syntax.tab.c"
    break;

  case 15: /* typename: "id"  */
#line 219 "src/syntax.y"
                                                                                {Symbol *s = symtab_lookup((yyvsp[0].strval));
                                                                                    if (!s || s->kind != SYM_TYPE || !s->type) {
                                                                                        YYERROR_FMT("Unknown type '%s'", (yyvsp[0].strval));
                                                                                        (yyval.type) = type_error;
                                                                                    } else {
                                                                                        (yyval.type) = s->type;
                                                                                    }
                                                                                    current_type = (yyval.type); 
                                                                                }
#line 1941 "build/generated/syntax.tab.c"
    break;

  case 16: /* standard_type: "char"  */
#line 229 "src/syntax.y"
                                                                                {(yyval.type) = type_char;}
#line 1947 "build/generated/syntax.tab.c"
    break;

  case 17: /* standard_type: "int"  */
#line 230 "src/syntax.y"
                                                                                {(yyval.type) = type_int;}
#line 1953 "build/generated/syntax.tab.c"
    break;

  case 18: /* standard_type: "float"  */
#line 231 "src/syntax.y"
                                                                                {(yyval.type) = type_float;}
#line 1959 "build/generated/syntax.tab.c"
    break;

  case 19: /* standard_type: "string"  */
#line 232 "src/syntax.y"
                                                                                {(yyval.type) = type_string;}
#line 1965 "build/generated/syntax.tab.c"
    break;

  case 20: /* standard_type: "void"  */
#line 233 "src/syntax.y"
                                                                                {(yyval.type) = type_void;}
#line 1971 "build/generated/syntax.tab.c"
    break;

  case 21: /* listspec: "list"  */
#line 235 "src/syntax.y"
                                                                                {(yyval.intval) = 1;}
#line 1977 "build/generated/syntax.tab.c"
    break;

  case 22: /* listspec: %empty  */
#line 236 "src/syntax.y"
                                                                                {(yyval.intval) = 0;}
#line 1983 "build/generated/syntax.tab.c"
    break;

  case 23: /* dims: dims dim  */
#line 238 "src/syntax.y"
                                                                                { (yyval.type) = attach_nested_array((yyvsp[-1].type), (yyvsp[0].type)); }
#line 1989 "build/generated/syntax.tab.c"
    break;

  case 24: /* dims: %empty  */
#line 239 "src/syntax.y"
                                                                                { (yyval.type) = NULL; }
#line 1995 "build/generated/syntax.tab.c"
    break;

  case 25: /* dim: "lbrack" "iconst" "rbrack"  */
#line 241 "src/syntax.y"
                                                                                { (yyval.type) = make_array_type(NULL, (yyvsp[-1].intval)); }
#line 2001 "build/generated/syntax.tab.c"
    break;

  case 26: /* dim: "lbrack" "rbrack"  */
#line 242 "src/syntax.y"
                                                                                { (yyval.type) = make_array_type(NULL, 0); }
#line 2007 "build/generated/syntax.tab.c"
    break;

  case 30: /* constdef: "id" dims "assign" init_value  */
#line 249 "src/syntax.y"
                                                                                {   if (!current_type) current_type = type_error;
                                                                                    if ((yyvsp[-2].type) != NULL) {YYERROR_FMT("const arrays not supported (line %d)", yylineno);} //TODO array consts
                                                                                    sem_define_const(current_type, (yyvsp[-3].strval), (yyvsp[0].expr).node, yylineno);
                                                                                }
#line 2016 "build/generated/syntax.tab.c"
    break;

  case 31: /* init_value: expression  */
#line 254 "src/syntax.y"
                                                                                {(yyval.expr) = (yyvsp[0].expr);}
#line 2022 "build/generated/syntax.tab.c"
    break;

  case 32: /* init_value: "lbrace" init_values "rbrace"  */
#line 255 "src/syntax.y"
                                                                                {(yyval.expr).type = type_error; (yyval.expr).node = NULL;}
#line 2028 "build/generated/syntax.tab.c"
    break;

  case 33: /* expression: expression "orop" expression  */
#line 259 "src/syntax.y"
                                                                                {
                                                                                    Type *t = sem_binary_logical((yyvsp[-2].expr).type, (yyvsp[0].expr).type, yylineno);
                                                                                    ASTOp op = OP_OR;
                                                                                    (yyval.expr).node = ast_make_binop(op, (yyvsp[-2].expr).node, (yyvsp[0].expr).node, t, yylineno);
                                                                                    (yyval.expr).type = t;
                                                                                }
#line 2039 "build/generated/syntax.tab.c"
    break;

  case 34: /* expression: expression "andop" expression  */
#line 266 "src/syntax.y"
                                                                                {
                                                                                    Type *t = sem_binary_logical((yyvsp[-2].expr).type, (yyvsp[0].expr).type, yylineno);
                                                                                    ASTOp op = OP_AND;
                                                                                    (yyval.expr).node = ast_make_binop(op, (yyvsp[-2].expr).node, (yyvsp[0].expr).node, t, yylineno);
                                                                                    (yyval.expr).type = t;
                                                                                }
#line 2050 "build/generated/syntax.tab.c"
    break;

  case 35: /* expression: expression "equop" expression  */
#line 273 "src/syntax.y"
                                                                                {
                                                                                    Type *t = sem_binary_equality((yyvsp[-2].expr).type, (yyvsp[0].expr).type, yylineno);
                                                                                    ASTOp op = (strcmp((yyvsp[-1].strval), "==") == 0) ? OP_EQ : OP_NE;
                                                                                    (yyval.expr).node = ast_make_binop(op, (yyvsp[-2].expr).node, (yyvsp[0].expr).node, t, yylineno);
                                                                                    (yyval.expr).type = t;
                                                                                }
#line 2061 "build/generated/syntax.tab.c"
    break;

  case 36: /* expression: expression "relop" expression  */
#line 280 "src/syntax.y"
                                                                                {
                                                                                    Type *t = sem_binary_relational((yyvsp[-2].expr).type, (yyvsp[0].expr).type, yylineno);
                                                                                    ASTOp op;
                                                                                    if      (strcmp((yyvsp[-1].strval), "<")  == 0) op = OP_LT;
                                                                                    else if (strcmp((yyvsp[-1].strval), "<=") == 0) op = OP_LE;
                                                                                    else if (strcmp((yyvsp[-1].strval), ">")  == 0) op = OP_GT;
                                                                                    else                            op = OP_GE;
                                                                                    (yyval.expr).node = ast_make_binop(op, (yyvsp[-2].expr).node, (yyvsp[0].expr).node, t, yylineno);
                                                                                    (yyval.expr).type = t;
                                                                                }
#line 2076 "build/generated/syntax.tab.c"
    break;

  case 37: /* expression: expression "addop" expression  */
#line 291 "src/syntax.y"
                                                                                {
                                                                                    Type *t = sem_binary_arith((yyvsp[-2].expr).type, (yyvsp[0].expr).type, yylineno);
                                                                                    ASTOp op = (strcmp((yyvsp[-1].strval), "+") == 0) ? OP_ADD : OP_SUB;
                                                                                    (yyval.expr).node = ast_make_binop(op, (yyvsp[-2].expr).node, (yyvsp[0].expr).node, t, yylineno);
                                                                                    (yyval.expr).type = t;
                                                                                }
#line 2087 "build/generated/syntax.tab.c"
    break;

  case 38: /* expression: expression "mulop" expression  */
#line 298 "src/syntax.y"
                                                                                {
                                                                                    Type *t = sem_binary_arith((yyvsp[-2].expr).type, (yyvsp[0].expr).type, yylineno);
                                                                                    ASTOp op;
                                                                                    if      (strcmp((yyvsp[-1].strval), "*") == 0) op = OP_MUL;
                                                                                    else if (strcmp((yyvsp[-1].strval), "/") == 0) op = OP_DIV;
                                                                                    else                           op = OP_MOD;
                                                                                    (yyval.expr).node = ast_make_binop(op, (yyvsp[-2].expr).node, (yyvsp[0].expr).node, t, yylineno);
                                                                                    (yyval.expr).type = t;
                                                                                }
#line 2101 "build/generated/syntax.tab.c"
    break;

  case 39: /* expression: "notop" expression  */
#line 308 "src/syntax.y"
                                                                                {
                                                                                    Type *t = sem_unary_not((yyvsp[0].expr).type, yylineno);
                                                                                    ASTOp op = OP_NOT;
                                                                                    (yyval.expr).node = ast_make_unop(op, (yyvsp[0].expr).node, t, yylineno);
                                                                                    (yyval.expr).type = t;
                                                                                }
#line 2112 "build/generated/syntax.tab.c"
    break;

  case 40: /* expression: "addop" expression  */
#line 315 "src/syntax.y"
                                                                                {
                                                                                    Type *t = sem_unary_sign((yyvsp[0].expr).type, yylineno);
                                                                                    ASTOp op = (strcmp((yyvsp[-1].strval), "+") == 0) ? OP_ADD : OP_SUB;
                                                                                    (yyval.expr).node = ast_make_unop(op, (yyvsp[0].expr).node, t, yylineno);
                                                                                    (yyval.expr).type = t;
                                                                                }
#line 2123 "build/generated/syntax.tab.c"
    break;

  case 41: /* expression: "sizeop" expression  */
#line 322 "src/syntax.y"
                                                                                {
                                                                                    long sz = sem_sizeof_bytes((yyvsp[0].expr).type, yylineno);
                                                                                    (yyval.expr).type = type_int;
                                                                                    (yyval.expr).node = ast_make_const_int(sz, yylineno);
                                                                                }
#line 2133 "build/generated/syntax.tab.c"
    break;

  case 42: /* expression: "incdec" variable  */
#line 328 "src/syntax.y"
                                                                                {
                                                                                    sem_check_writable_lvalue((yyvsp[0].expr).node, yylineno);
                                                                                    Type *t = sem_unary_incdec((yyvsp[0].expr).type, yylineno);
                                                                                    ASTOp op = (strcmp((yyvsp[-1].strval), "++") == 0) ? OP_PRE_INC : OP_PRE_DEC;
                                                                                    (yyval.expr).type = t;
                                                                                    (yyval.expr).node = ast_make_unop(op, (yyvsp[0].expr).node, t, yylineno);
                                                                                }
#line 2145 "build/generated/syntax.tab.c"
    break;

  case 43: /* expression: variable "incdec"  */
#line 336 "src/syntax.y"
                                                                                {
                                                                                    sem_check_writable_lvalue((yyvsp[-1].expr).node, yylineno);
                                                                                    Type *t = sem_unary_incdec((yyvsp[-1].expr).type, yylineno);
                                                                                    ASTOp op = (strcmp((yyvsp[0].strval), "++") == 0) ? OP_POST_INC : OP_POST_DEC;
                                                                                    (yyval.expr).type = t;
                                                                                    (yyval.expr).node = ast_make_unop(op, (yyvsp[-1].expr).node, t, yylineno);
                                                                                }
#line 2157 "build/generated/syntax.tab.c"
    break;

  case 44: /* expression: variable  */
#line 344 "src/syntax.y"
                                                                                {
                                                                                    (yyval.expr).type = (yyvsp[0].expr).type;
                                                                                    (yyval.expr).node = (yyvsp[0].expr).node;
                                                                                }
#line 2166 "build/generated/syntax.tab.c"
    break;

  case 45: /* expression: variable "lparen" expression_list "rparen"  */
#line 349 "src/syntax.y"
                                                                                {
                                                                                    Type *t = NULL;
                                                                                    ASTNode *call = NULL;
                                                                                    
                                                                                    //if methode rewrite the function call to method call (Class::method(obj, args))
                                                                                    if (sem_try_rewrite_method_call((yyvsp[-3].expr).node, (yyvsp[-1].expr).node, yylineno, &t, &call)) {
                                                                                        (yyval.expr).type = t;
                                                                                        (yyval.expr).node = call;
                                                                                    } else {
                                                                                        //noraml function
                                                                                        t = sem_call_check((yyvsp[-3].expr).node, (yyvsp[-1].expr).node, yylineno);
                                                                                        (yyval.expr).type = t;
                                                                                        (yyval.expr).node = ast_make_call((yyvsp[-3].expr).node, (yyvsp[-1].expr).node, t, yylineno);
                                                                                    }
                                                                                }
#line 2186 "build/generated/syntax.tab.c"
    break;

  case 46: /* expression: "length" "lparen" general_expression "rparen"  */
#line 365 "src/syntax.y"
                                                                                {
                                                                                    Type *t = sem_length((yyvsp[-1].expr).type, yylineno);
                                                                                    (yyval.expr).type = t;
                                                                                    (yyval.expr).node = ast_make_unop(OP_LENGTH, (yyvsp[-1].expr).node, t, yylineno);
                                                                                }
#line 2196 "build/generated/syntax.tab.c"
    break;

  case 47: /* expression: constant  */
#line 371 "src/syntax.y"
                                                                                {
                                                                                    (yyval.expr).type = (yyvsp[0].expr).type;
                                                                                    (yyval.expr).node = (yyvsp[0].expr).node;
                                                                                }
#line 2205 "build/generated/syntax.tab.c"
    break;

  case 48: /* expression: "lparen" general_expression "rparen"  */
#line 376 "src/syntax.y"
                                                                                {
                                                                                    (yyval.expr).type = (yyvsp[-1].expr).type;
                                                                                    (yyval.expr).node = (yyvsp[-1].expr).node;
                                                                                }
#line 2214 "build/generated/syntax.tab.c"
    break;

  case 49: /* expression: "lparen" standard_type "rparen"  */
#line 381 "src/syntax.y"
                                                                                {
                                                                                    /* cast expression TODO: for now just type info, no AST */
                                                                                    (yyval.expr).type = (yyvsp[-1].type);
                                                                                    (yyval.expr).node = NULL;
                                                                                }
#line 2224 "build/generated/syntax.tab.c"
    break;

  case 50: /* expression: listexpression  */
#line 387 "src/syntax.y"
                                                                                {
                                                                                    (yyval.expr).type = (yyvsp[0].expr).type;
                                                                                    (yyval.expr).node = (yyvsp[0].expr).node;
                                                                                }
#line 2233 "build/generated/syntax.tab.c"
    break;

  case 51: /* variable: variable "lbrack" general_expression "rbrack"  */
#line 395 "src/syntax.y"
                                                                                {
                                                                                    Type *t = sem_index((yyvsp[-3].expr).type, (yyvsp[-1].expr).type, yylineno);
                                                                                    (yyval.expr).type = t;
                                                                                    (yyval.expr).node = ast_make_index((yyvsp[-3].expr).node, (yyvsp[-1].expr).node, t, yylineno);
                                                                                }
#line 2243 "build/generated/syntax.tab.c"
    break;

  case 52: /* variable: variable "dot" "id"  */
#line 401 "src/syntax.y"
                                                                                {
                                                                                    if ((yyvsp[-2].expr).type && is_enum((yyvsp[-2].expr).type->kind)) {
                                                                                        Type *t = sem_use_enum_constant((yyvsp[-2].expr).type, (yyvsp[0].strval), yylineno);
                                                                                        (yyval.expr).type = t;
                                                                                        (yyval.expr).node = ast_make_var((yyvsp[0].strval), t, yylineno);
                                                                                    }
                                                                                    else if ((yyvsp[-2].expr).type && ((yyvsp[-2].expr).type->kind == TYPE_CLASS || (yyvsp[-2].expr).type->kind == TYPE_UNION)) {
                                                                                        Symbol *m = sem_lookup_field_symbol((yyvsp[-2].expr).type, (yyvsp[0].strval), yylineno);
                                                                                        (yyval.expr).type = m ? m->type : type_error;
                                                                                        (yyval.expr).node = m ? ast_make_field((yyvsp[-2].expr).node, m, (yyval.expr).type, yylineno) : NULL;
                                                                                    }
                                                                                    else {
                                                                                        (yyval.expr).type = type_error;
                                                                                        (yyval.expr).node = NULL;
                                                                                    }
                                                                                }
#line 2264 "build/generated/syntax.tab.c"
    break;

  case 53: /* variable: "listfunc" "lparen" general_expression "rparen"  */
#line 418 "src/syntax.y"
                                                                                {
                                                                                    Type *t = sem_list_func((yyvsp[-3].strval), (yyvsp[-1].expr).type, yylineno); 
                                                                                    (yyval.expr).type = t;
                                                                                    (yyval.expr).node = ast_make_list_func((yyvsp[-3].strval), (yyvsp[-1].expr).node, t, yylineno);
                                                                                }
#line 2274 "build/generated/syntax.tab.c"
    break;

  case 54: /* variable: decltype "id"  */
#line 424 "src/syntax.y"
                                                                                {
                                                                                    Type *t = sem_use_variable((yyvsp[0].strval), yylineno);
                                                                                    (yyval.expr).type = t;
                                                                                    (yyval.expr).node = ast_make_var((yyvsp[0].strval), t, yylineno);
                                                                                }
#line 2284 "build/generated/syntax.tab.c"
    break;

  case 55: /* variable: "this"  */
#line 430 "src/syntax.y"
                                                                                {
                                                                                    Symbol *s = symtab_lookup("this");
                                                                                    if (!s) {
                                                                                        YYERROR_FMT("line %d: 'this' used outside of method", yylineno);
                                                                                        (yyval.expr).type = type_error;
                                                                                        (yyval.expr).node = NULL;
                                                                                    } else {
                                                                                        (yyval.expr).type = s->type;
                                                                                        (yyval.expr).node = ast_make_var("this", s->type, yylineno);
                                                                                    }
                                                                                }
#line 2300 "build/generated/syntax.tab.c"
    break;

  case 56: /* general_expression: general_expression "comma" general_expression  */
#line 443 "src/syntax.y"
                                                                                { 
                                                                                    (yyval.expr) = (yyvsp[0].expr); 
                                                                                    // AST: χτίζουμε λίστα εκφράσεων (AST_LIST)
                                                                                    if ((yyvsp[-2].expr).node) {
                                                                                        (yyval.expr).node = ast_list_append((yyvsp[-2].expr).node, (yyvsp[0].expr).node, yylineno);
                                                                                    } else {
                                                                                        (yyval.expr).node = (yyvsp[0].expr).node;
                                                                                    }
                                                                                }
#line 2314 "build/generated/syntax.tab.c"
    break;

  case 57: /* general_expression: assignment  */
#line 452 "src/syntax.y"
                                                                                {   (yyval.expr).type = (yyvsp[0].expr).type;
                                                                                    (yyval.expr).node = (yyvsp[0].expr).node;
                                                                                }
#line 2322 "build/generated/syntax.tab.c"
    break;

  case 58: /* assignment: variable "assign" assignment  */
#line 456 "src/syntax.y"
                                                                                {
                                                                                    sem_check_writable_lvalue((yyvsp[-2].expr).node, yylineno);
                                                                                    Type *t = sem_check_assignment((yyvsp[-2].expr).type, (yyvsp[0].expr).type, yylineno);
                                                                                    (yyval.expr).type = t;
                                                                                    (yyval.expr).node = ast_make_assign((yyvsp[-2].expr).node, (yyvsp[0].expr).node, t, yylineno);
                                                                                }
#line 2333 "build/generated/syntax.tab.c"
    break;

  case 59: /* assignment: expression  */
#line 462 "src/syntax.y"
                                                                                {(yyval.expr) = (yyvsp[0].expr);}
#line 2339 "build/generated/syntax.tab.c"
    break;

  case 60: /* expression_list: general_expression  */
#line 464 "src/syntax.y"
                                                                                {(yyval.expr) = (yyvsp[0].expr);}
#line 2345 "build/generated/syntax.tab.c"
    break;

  case 61: /* expression_list: %empty  */
#line 465 "src/syntax.y"
                                                                                {(yyval.expr).type = type_void; (yyval.expr).node = NULL;}
#line 2351 "build/generated/syntax.tab.c"
    break;

  case 62: /* constant: "cconst"  */
#line 467 "src/syntax.y"
                                                                                { 
                                                                                    Type *t = type_char;
                                                                                    (yyval.expr).node = ast_make_const_char((yyvsp[0].charval), yylineno);
                                                                                    (yyval.expr).type = t;
                                                                                }
#line 2361 "build/generated/syntax.tab.c"
    break;

  case 63: /* constant: "iconst"  */
#line 472 "src/syntax.y"
                                                                                {
                                                                                    Type *t = type_int;
                                                                                    (yyval.expr).node = ast_make_const_int((yyvsp[0].intval), yylineno);
                                                                                    (yyval.expr).type = t;
                                                                                }
#line 2371 "build/generated/syntax.tab.c"
    break;

  case 64: /* constant: "fconst"  */
#line 477 "src/syntax.y"
                                                                                { 
                                                                                    Type *t = type_float;
                                                                                    (yyval.expr).node = ast_make_const_float((yyvsp[0].floatval), yylineno);
                                                                                    (yyval.expr).type = t;
                                                                                }
#line 2381 "build/generated/syntax.tab.c"
    break;

  case 65: /* constant: "sconst"  */
#line 482 "src/syntax.y"
                                                                                { 
                                                                                    Type *t = type_string;
                                                                                    (yyval.expr).node = ast_make_const_string((yyvsp[0].strval), yylineno);
                                                                                    (yyval.expr).type = t;
                                                                                }
#line 2391 "build/generated/syntax.tab.c"
    break;

  case 66: /* listexpression: "lbrack" list_elements "rbrack"  */
#line 489 "src/syntax.y"
                                                                                {
                                                                                    Type *t   = sem_make_list_type((yyvsp[-1].expr).type, yylineno);
                                                                                    (yyval.expr).type   = t;
                                                                                    (yyval.expr).node   = (yyvsp[-1].expr).node;
                                                                                }
#line 2401 "build/generated/syntax.tab.c"
    break;

  case 67: /* list_elements: list_elements "comma" assignment  */
#line 496 "src/syntax.y"
                                                                                { 
                                                                                    Type *elemType = sem_find_list_element_type((yyvsp[-2].expr).type, (yyvsp[0].expr).type, yylineno);
                                                                                    (yyval.expr).type = elemType;
                                                                                    (yyval.expr).node = ast_list_append((yyvsp[-2].expr).node, (yyvsp[0].expr).node, yylineno);

                                                                                }
#line 2412 "build/generated/syntax.tab.c"
    break;

  case 68: /* list_elements: assignment  */
#line 503 "src/syntax.y"
                                                                                { 
                                                                                    (yyval.expr).type = (yyvsp[0].expr).type;
                                                                                    (yyval.expr).node = ast_make_list((yyvsp[0].expr).node, NULL, yylineno); 
                                                                                }
#line 2421 "build/generated/syntax.tab.c"
    break;

  case 71: /* $@1: %empty  */
#line 511 "src/syntax.y"
                                                                                {
                                                                                    sem_enum_start((yyvsp[0].strval), yylineno);
                                                                                }
#line 2429 "build/generated/syntax.tab.c"
    break;

  case 72: /* enum_declaration: "enum" "id" $@1 enum_body "semi"  */
#line 515 "src/syntax.y"
                                                                                {
                                                                                    sem_enum_end();
                                                                                    (yyval.node) = ast_make_enum_decl((yyvsp[-3].strval), (yyvsp[-1].node), yylineno);
                                                                                }
#line 2438 "build/generated/syntax.tab.c"
    break;

  case 73: /* enum_body: "lbrace" id_list "rbrace"  */
#line 520 "src/syntax.y"
                                                                                {(yyval.node) = (yyvsp[-1].node);}
#line 2444 "build/generated/syntax.tab.c"
    break;

  case 74: /* id_list: id_list "comma" "id" initializer  */
#line 522 "src/syntax.y"
                                                                                {
                                                                                    int has_val = ((yyvsp[0].intval) != -999); // Χρησιμοποιούμε το -999 ως "no value"
                                                                                    int val = (has_val) ? (yyvsp[0].intval) : 0;
                                                                                    sem_enum_add_const((yyvsp[-1].strval), has_val, val, yylineno);
                                                                                    ASTNode *new_const = ast_make_enum_const((yyvsp[-1].strval), val, yylineno);
                                                                                    (yyval.node) = ast_list_append((yyvsp[-3].node), new_const, yylineno);
                                                                                }
#line 2456 "build/generated/syntax.tab.c"
    break;

  case 75: /* id_list: "id" initializer  */
#line 529 "src/syntax.y"
                                                                                { 
                                                                                    int has_val = ((yyvsp[0].intval) != -999);
                                                                                    int val = (has_val) ? (yyvsp[0].intval) : 0;
                                                                                    sem_enum_add_const((yyvsp[-1].strval), has_val, val, yylineno);

                                                                                    ASTNode *new_const = ast_make_enum_const((yyvsp[-1].strval), val, yylineno);
                                                                                    (yyval.node) = new_const;
                                                                                }
#line 2469 "build/generated/syntax.tab.c"
    break;

  case 76: /* initializer: "assign" "iconst"  */
#line 538 "src/syntax.y"
                                                                                {(yyval.intval) = (yyvsp[0].intval);}
#line 2475 "build/generated/syntax.tab.c"
    break;

  case 77: /* initializer: %empty  */
#line 539 "src/syntax.y"
                                                                                {(yyval.intval) = -999;}
#line 2481 "build/generated/syntax.tab.c"
    break;

  case 78: /* $@2: %empty  */
#line 542 "src/syntax.y"
                                                                                {
                                                                                    Type *base = ((yyvsp[0].type) == type_error) ? NULL : (yyvsp[0].type);
                                                                                    current_class_type = make_class_type((yyvsp[-1].strval), base);
                                                                                    current_member_access = ACC_PUBLIC;
                                                                                    in_class_body = 1;

                                                                                    
                                                                                    if (!symtab_insert((yyvsp[-1].strval), SYM_TYPE, current_class_type)) {
                                                                                        YYERROR_FMT("Redeclaration of class '%s'", (yyvsp[-1].strval));
                                                                                    }
                                                                                }
#line 2497 "build/generated/syntax.tab.c"
    break;

  case 79: /* class_declaration: "class" "id" parent $@2 "lbrace" members_methods "rbrace" "semi"  */
#line 554 "src/syntax.y"
                                                                                {
                                                                                    in_class_body = 0;
                                                                                    current_class_type = NULL;
                                                                                }
#line 2506 "build/generated/syntax.tab.c"
    break;

  case 80: /* parent: "colon" "id"  */
#line 560 "src/syntax.y"
                                                                                {
                                                                                    Symbol *base = symtab_lookup((yyvsp[0].strval));
                                                                                    if (!base || base->kind != SYM_TYPE || !base->type || base->type->kind != TYPE_CLASS) {
                                                                                        YYERROR_FMT("Unknown base class '%s'", (yyvsp[0].strval));
                                                                                        (yyval.type) = type_error;
                                                                                    } else {
                                                                                        (yyval.type) = base->type;
                                                                                    }
                                                                                }
#line 2520 "build/generated/syntax.tab.c"
    break;

  case 81: /* parent: %empty  */
#line 569 "src/syntax.y"
                                                                                {(yyval.type) = NULL;}
#line 2526 "build/generated/syntax.tab.c"
    break;

  case 84: /* access: "private" "colon"  */
#line 574 "src/syntax.y"
                                                                                { current_member_access = ACC_PRIVATE; }
#line 2532 "build/generated/syntax.tab.c"
    break;

  case 85: /* access: "protected" "colon"  */
#line 575 "src/syntax.y"
                                                                                { current_member_access = ACC_PROTECTED; }
#line 2538 "build/generated/syntax.tab.c"
    break;

  case 86: /* access: "public" "colon"  */
#line 576 "src/syntax.y"
                                                                                { current_member_access = ACC_PUBLIC; }
#line 2544 "build/generated/syntax.tab.c"
    break;

  case 87: /* access: %empty  */
#line 577 "src/syntax.y"
                                                                                { ;}
#line 2550 "build/generated/syntax.tab.c"
    break;

  case 92: /* var_declaration: type_with_list variabledefs "semi"  */
#line 586 "src/syntax.y"
                                                                                { (yyval.node) = (yyvsp[-1].node); }
#line 2556 "build/generated/syntax.tab.c"
    break;

  case 93: /* variabledefs: variabledefs "comma" variabledef  */
#line 589 "src/syntax.y"
                                                                                { (yyval.node) = ast_make_list((yyvsp[-2].node), (yyvsp[0].node), yylineno); }
#line 2562 "build/generated/syntax.tab.c"
    break;

  case 94: /* variabledefs: variabledef  */
#line 590 "src/syntax.y"
                                                                                { (yyval.node) = (yyvsp[0].node); }
#line 2568 "build/generated/syntax.tab.c"
    break;

  case 95: /* variabledef: "id" dims  */
#line 593 "src/syntax.y"
                                                                                {
                                                                                    if (!current_type) current_type = type_error;
                                                                                    Type *t = current_type;
                                                                                    if ((yyvsp[0].type) != NULL) t = attach_array_to_base(current_type, (yyvsp[0].type));
                                                                                    if (in_param_context) {
                                                                                        sem_declare_param((yyvsp[-1].strval), t, 0, yylineno);   /* is_ref = 0*/
                                                                                    } else if (in_class_body && current_class_type) {
                                                                                        /* class field */
                                                                                        if (hashtbl_lookup(current_class_type->members, (yyvsp[-1].strval), 0)) {
                                                                                            YYERROR_FMT("Redeclaration of class member '%s'", (yyvsp[-1].strval));
                                                                                        } else {
                                                                                            Symbol *m = malloc(sizeof(Symbol));
                                                                                            memset(m, 0, sizeof(Symbol));
                                                                                            m->name = strdup((yyvsp[-1].strval));
                                                                                            m->kind = SYM_VAR;
                                                                                            m->type = t;
                                                                                            m->storage = STOR_FIELD;
                                                                                            m->access = current_member_access;
                                                                                            m->offset = -1;
                                                                                            hashtbl_insert(current_class_type->members, (yyvsp[-1].strval), m, 0);
                                                                                            sem_class_add_field(current_class_type, m);
                                                                                        }
                                                                                    } else {
                                                                                        Symbol *s = symtab_insert((yyvsp[-1].strval), SYM_VAR, t);
                                                                                        if (!s) YYERROR_FMT("Redeclaration of '%s'", (yyvsp[-1].strval));
                                                                                        if (s) sem_bind_var_symbol(s, yylineno); //for memory (locals only is in function)
                                                                                    }
                                                                                    (yyval.node) = ast_make_var_decl((yyvsp[-1].strval), t, NULL, yylineno);
                                                                                }
#line 2602 "build/generated/syntax.tab.c"
    break;

  case 97: /* $@3: %empty  */
#line 626 "src/syntax.y"
                            {symtab_enter_scope();}
#line 2608 "build/generated/syntax.tab.c"
    break;

  case 98: /* union_body: $@3 "lbrace" fields "rbrace"  */
#line 626 "src/syntax.y"
                                                                                             { symtab_leave_scope();}
#line 2614 "build/generated/syntax.tab.c"
    break;

  case 103: /* short_func_declaration: short_par_func_header "semi"  */
#line 635 "src/syntax.y"
                                                                                            {
                                                                                                symtab_leave_scope();
                                                                                                Symbol *fsym = sem_declare_function(current_function_name,current_function_type,yylineno);

                                                                                                if (fsym && fsym->kind == SYM_FUNC) {
                                                                                                    fsym->u.func.is_forward_decl = 1;   /* prototype only */
                                                                                                }
                                                                                                /* αν είναι class method prototype, add στο members table */
                                                                                                if (in_class_body && current_class_type && fsym) {
                                                                                                    fsym->access = current_member_access;
                                                                                                    if (hashtbl_lookup(current_class_type->members, current_function_unqual, 0)) {
                                                                                                        YYERROR_FMT("Redeclaration of method '%s'", current_function_unqual);
                                                                                                    } else {
                                                                                                        hashtbl_insert(current_class_type->members, current_function_unqual, fsym, 0);
                                                                                                    }
                                                                                                }
                                                                                                sem_frame_end(current_function_name, yylineno);  //for memory binding tables
                                                                                                current_function_type = NULL;
                                                                                                if (current_function_name_owned) { free(current_function_name); }
                                                                                                current_function_name_owned = 0;
                                                                                                current_function_name  = NULL;
                                                                                                current_function_unqual = NULL;
                                                                                                in_param_context       = 0;
                                                                                            }
#line 2643 "build/generated/syntax.tab.c"
    break;

  case 104: /* short_func_declaration: nopar_func_header "semi"  */
#line 660 "src/syntax.y"
                                                                                            {
                                                                                                symtab_leave_scope();
                                                                                                Symbol *fsym = sem_declare_function(current_function_name,current_function_type,yylineno);
                                                                                                if (fsym && fsym->kind == SYM_FUNC) {
                                                                                                    fsym->u.func.is_forward_decl = 1;   /* prototype only */
                                                                                                }
                                                                                                if (in_class_body && current_class_type && fsym) {
                                                                                                    fsym->access = current_member_access;
                                                                                                    if (hashtbl_lookup(current_class_type->members, current_function_unqual, 0)) {
                                                                                                        YYERROR_FMT("Redeclaration of method '%s'", current_function_unqual);
                                                                                                    } else {
                                                                                                        hashtbl_insert(current_class_type->members, current_function_unqual, fsym, 0);
                                                                                                    }
                                                                                                }
                                                                                                sem_frame_end(current_function_name, yylineno);  
                                                                                                current_function_type = NULL;
                                                                                                if (current_function_name_owned) { free(current_function_name); }
                                                                                                current_function_name_owned = 0;
                                                                                                current_function_name  = NULL;
                                                                                                current_function_unqual = NULL;
                                                                                                in_param_context = 0;
                                                                                            }
#line 2670 "build/generated/syntax.tab.c"
    break;

  case 105: /* short_par_func_header: func_header_start "lparen" parameter_types "rparen"  */
#line 685 "src/syntax.y"
                                                                                            {in_param_context = 0;}
#line 2676 "build/generated/syntax.tab.c"
    break;

  case 106: /* func_header_start: type_with_list "id"  */
#line 688 "src/syntax.y"
                                                                                            {
                                                                                                Type *ret = sem_check_function_return_type((yyvsp[-1].type), yylineno);

                                                                                                sem_param_list_reset();

                                                                                                current_function_type  = ret;
                                                                                                current_function_unqual = (yyvsp[0].strval);
                                                                                                //class
                                                                                                if (in_class_body && current_class_type && current_class_type->tag_name) {
                                                                                                    char *qualif = mk_qname(current_class_type->tag_name, (yyvsp[0].strval));
                                                                                                    current_function_name = qualif;
                                                                                                    current_function_name_owned = 1;
                                                                                                } else {
                                                                                                    current_function_name  = (yyvsp[0].strval);
                                                                                                    current_function_name_owned = 0;
                                                                                                }
                                                                                                
                                                                                                in_param_context       = 1;
                                                                                                symtab_enter_scope();
                                                                                                sem_frame_begin(current_function_name, yylineno); //for memory tables
                                                                                                if(in_class_body && current_class_type && current_class_type->tag_name){
                                                                                                    sem_declare_param("this", current_class_type, 1, yylineno);
                                                                                                }
                                                                                            }
#line 2705 "build/generated/syntax.tab.c"
    break;

  case 107: /* parameter_types: parameter_types "comma" typename pass_list_dims  */
#line 714 "src/syntax.y"
                                                                                            {
                                                                                                int is_ref = (yyvsp[0].intval);
                                                                                                sem_param_list_add((yyvsp[-1].type),is_ref);
                                                                                            }
#line 2714 "build/generated/syntax.tab.c"
    break;

  case 108: /* parameter_types: typename pass_list_dims  */
#line 718 "src/syntax.y"
                                                                                            {
                                                                                                int is_ref = (yyvsp[0].intval);
                                                                                                sem_param_list_add((yyvsp[-1].type),is_ref);
                                                                                            }
#line 2723 "build/generated/syntax.tab.c"
    break;

  case 109: /* pass_list_dims: "refer"  */
#line 723 "src/syntax.y"
                                                                                                        { (yyval.intval) = 1; }
#line 2729 "build/generated/syntax.tab.c"
    break;

  case 110: /* pass_list_dims: listspec dims  */
#line 724 "src/syntax.y"
                                                                                                        { (yyval.intval) = 0; }
#line 2735 "build/generated/syntax.tab.c"
    break;

  case 111: /* nopar_func_header: func_header_start "lparen" "rparen"  */
#line 726 "src/syntax.y"
                                                                                                        {sem_define_function(current_function_name, current_function_type, yylineno); in_param_context = 0;}
#line 2741 "build/generated/syntax.tab.c"
    break;

  case 112: /* union_declaration: "union" "id" union_body "semi"  */
#line 728 "src/syntax.y"
                                                                                                        {Type *t = make_simple_type(TYPE_UNION);
                                                                                                            if (!symtab_insert((yyvsp[-2].strval), SYM_TYPE, t)) {
                                                                                                                YYERROR_FMT("Redeclaration of union '%s'", (yyvsp[-2].strval));
                                                                                                            }
                                                                                                        }
#line 2751 "build/generated/syntax.tab.c"
    break;

  case 113: /* global_var_declaration: type_with_list init_variabledefs "semi"  */
#line 735 "src/syntax.y"
                                                                                                         {(yyval.node) = (yyvsp[-1].node);}
#line 2757 "build/generated/syntax.tab.c"
    break;

  case 114: /* init_variabledefs: init_variabledefs "comma" init_variabledef  */
#line 738 "src/syntax.y"
                                                                                                        {(yyval.node) = ast_list_append((yyvsp[-2].node), (yyvsp[0].node),yylineno); }
#line 2763 "build/generated/syntax.tab.c"
    break;

  case 115: /* init_variabledefs: init_variabledef  */
#line 739 "src/syntax.y"
                                                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 2769 "build/generated/syntax.tab.c"
    break;

  case 116: /* init_variabledef: variabledef initializer  */
#line 741 "src/syntax.y"
                                                                                                        { (yyval.node) = (yyvsp[-1].node); 
                                                                                                            int val = (yyvsp[0].intval);                                                                                                            
                                                                                                            Symbol *s = symtab_lookup((yyval.node)->u.var_decl.name); 
                                                                                                            if (s && s->scope == 0) {
                                                                                                                s->u.c.ival = val;
                                                                                                            }
                                                                                                            (yyval.node)->u.var_decl.init = ast_make_const_int(val, yylineno);
                                                                                                        
                                                                                                        }
#line 2783 "build/generated/syntax.tab.c"
    break;

  case 117: /* func_declaration: short_func_declaration  */
#line 751 "src/syntax.y"
                                                                                                        {(yyval.stmt).node = NULL;}
#line 2789 "build/generated/syntax.tab.c"
    break;

  case 118: /* func_declaration: full_func_declaration  */
#line 752 "src/syntax.y"
                                                                                                        {(yyval.stmt).node = (yyvsp[0].stmt).node;}
#line 2795 "build/generated/syntax.tab.c"
    break;

  case 119: /* full_func_declaration: full_par_func_header "lbrace" decl_statements "rbrace"  */
#line 753 "src/syntax.y"
                                                                                                        {
                                                                                                            symtab_leave_scope();
                                                                                                            //sem_define_function(current_function_name, current_function_type, yylineno);

                                                                                                            ASTNode *body = (yyvsp[-1].stmt).node;
                                                                                                            (yyval.stmt).node = ast_make_func_decl(current_function_name, body, yylineno);

                                                                                                            sem_frame_end(current_function_name, yylineno);//for memory binding tables

                                                                                                            current_function_type = NULL;
                                                                                                            current_function_name = NULL;
                                                                                                            in_param_context = 0;
                                                                                                        }
#line 2813 "build/generated/syntax.tab.c"
    break;

  case 120: /* full_func_declaration: nopar_class_func_header "lbrace" decl_statements "rbrace"  */
#line 766 "src/syntax.y"
                                                                                                        {
                                                                                                            symtab_leave_scope();
                                                                                                            sem_frame_end(current_function_name, yylineno);

                                                                                                            ASTNode *body = (yyvsp[-1].stmt).node;
                                                                                                            (yyval.stmt).node = ast_make_func_decl(current_function_name, body, yylineno);

                                                                                                            in_param_context = 0;
                                                                                                            current_function_type = NULL;
                                                                                                            current_function_name = NULL;   
                                                                                                        }
#line 2829 "build/generated/syntax.tab.c"
    break;

  case 121: /* full_func_declaration: nopar_func_header "lbrace" decl_statements "rbrace"  */
#line 777 "src/syntax.y"
                                                                                                        {
                                                                                                            symtab_leave_scope();
                                                                                                            //sem_define_function(current_function_name, current_function_type, yylineno);

                                                                                                            ASTNode *body = (yyvsp[-1].stmt).node;
                                                                                                            (yyval.stmt).node = ast_make_func_decl(current_function_name, body, yylineno);

                                                                                                            sem_frame_end(current_function_name, yylineno);  
                                                                                                            current_function_type  = NULL;
                                                                                                            current_function_name  = NULL;
                                                                                                            in_param_context       = 0;
                                                                                                        }
#line 2846 "build/generated/syntax.tab.c"
    break;

  case 122: /* full_par_func_header: class_func_header_start "lparen" parameter_list "rparen"  */
#line 790 "src/syntax.y"
                                                                                                        {sem_define_function(current_function_name, current_function_type, yylineno); in_param_context = 0;}
#line 2852 "build/generated/syntax.tab.c"
    break;

  case 123: /* full_par_func_header: func_header_start "lparen" parameter_list "rparen"  */
#line 791 "src/syntax.y"
                                                                                                        {sem_define_function(current_function_name, current_function_type, yylineno); in_param_context = 0;}
#line 2858 "build/generated/syntax.tab.c"
    break;

  case 124: /* class_func_header_start: type_with_list func_class "id"  */
#line 793 "src/syntax.y"
                                                                                                        {
                                                                                                            sem_begin_qualified_method_def((yyvsp[-2].type), current_method_class_type,
                                                                                                                current_method_class_name, (yyvsp[0].strval), yylineno, &current_function_type,
                                                                                                                &current_function_name, &current_function_unqual, &current_function_name_owned,
                                                                                                                &in_param_context);
                                                                                                        }
#line 2869 "build/generated/syntax.tab.c"
    break;

  case 125: /* func_class: "id" "meth"  */
#line 800 "src/syntax.y"
                                                                                {Symbol *cls = symtab_lookup((yyvsp[-1].strval));
                                                                                    if (!cls || cls->kind != SYM_TYPE) {
                                                                                        YYERROR_FMT("Unknown class type '%s'", (yyvsp[-1].strval));
                                                                                    }
                                                                                    else {
                                                                                        current_method_class_type = cls->type;
                                                                                        current_method_class_name = cls->name; 
                                                                                    }
                                                                                }
#line 2883 "build/generated/syntax.tab.c"
    break;

  case 126: /* parameter_decl: typename pass_variabledef  */
#line 810 "src/syntax.y"
                                                                                {(yyval.type) = (yyvsp[-1].type);}
#line 2889 "build/generated/syntax.tab.c"
    break;

  case 127: /* parameter_list: parameter_list "comma" parameter_decl  */
#line 812 "src/syntax.y"
                                                                                {(yyval.type) = (yyvsp[-2].type);}
#line 2895 "build/generated/syntax.tab.c"
    break;

  case 128: /* parameter_list: parameter_decl  */
#line 813 "src/syntax.y"
                                                                                {(yyval.type) = (yyvsp[0].type);}
#line 2901 "build/generated/syntax.tab.c"
    break;

  case 130: /* pass_variabledef: "refer" "id"  */
#line 818 "src/syntax.y"
                                                                                {
                                                                                    if (!current_type) current_type = type_error;
                                                                                    sem_declare_param((yyvsp[0].strval), current_type, 1, yylineno);  /* is_ref = 1 */
                                                                                }
#line 2910 "build/generated/syntax.tab.c"
    break;

  case 132: /* decl_statements: declarations statements  */
#line 825 "src/syntax.y"
                                                                                {(yyval.stmt).node = (yyvsp[0].stmt).node;}
#line 2916 "build/generated/syntax.tab.c"
    break;

  case 133: /* decl_statements: declarations  */
#line 826 "src/syntax.y"
                                                                                {(yyval.stmt).node = NULL; }
#line 2922 "build/generated/syntax.tab.c"
    break;

  case 134: /* decl_statements: statements  */
#line 827 "src/syntax.y"
                                                                                {(yyval.stmt).node = (yyvsp[0].stmt).node;}
#line 2928 "build/generated/syntax.tab.c"
    break;

  case 135: /* decl_statements: %empty  */
#line 828 "src/syntax.y"
                                                                                { (yyval.stmt).node = NULL; }
#line 2934 "build/generated/syntax.tab.c"
    break;

  case 139: /* decltype: %empty  */
#line 837 "src/syntax.y"
                                                      {;}
#line 2940 "build/generated/syntax.tab.c"
    break;

  case 140: /* loop_enter: %empty  */
#line 838 "src/syntax.y"
                                                                                { sem_enter_loop(); }
#line 2946 "build/generated/syntax.tab.c"
    break;

  case 141: /* statements: statements statement  */
#line 840 "src/syntax.y"
                                                                                {
                                                                                    if ((yyvsp[-1].stmt).node)
                                                                                        (yyval.stmt).node = ast_list_append((yyvsp[-1].stmt).node, (yyvsp[0].stmt).node, yylineno);
                                                                                    else
                                                                                        (yyval.stmt).node = (yyvsp[0].stmt).node;
                                                                                }
#line 2957 "build/generated/syntax.tab.c"
    break;

  case 142: /* statements: statement  */
#line 846 "src/syntax.y"
                                                                                { (yyval.stmt).node = (yyvsp[0].stmt).node; }
#line 2963 "build/generated/syntax.tab.c"
    break;

  case 143: /* statement: expression_statement  */
#line 848 "src/syntax.y"
                                                                                             { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2969 "build/generated/syntax.tab.c"
    break;

  case 144: /* statement: if_statement  */
#line 849 "src/syntax.y"
                                                                                             { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2975 "build/generated/syntax.tab.c"
    break;

  case 145: /* statement: while_statement  */
#line 850 "src/syntax.y"
                                                                                             { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2981 "build/generated/syntax.tab.c"
    break;

  case 146: /* statement: for_statement  */
#line 851 "src/syntax.y"
                                                                                             { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2987 "build/generated/syntax.tab.c"
    break;

  case 147: /* statement: return_statement  */
#line 852 "src/syntax.y"
                                                                                             { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2993 "build/generated/syntax.tab.c"
    break;

  case 148: /* statement: io_statement  */
#line 853 "src/syntax.y"
                                                                                             { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2999 "build/generated/syntax.tab.c"
    break;

  case 149: /* statement: comp_statement  */
#line 854 "src/syntax.y"
                                                                                             { (yyval.stmt) = (yyvsp[0].stmt); }
#line 3005 "build/generated/syntax.tab.c"
    break;

  case 150: /* statement: "continue" "semi"  */
#line 855 "src/syntax.y"
                                                                                             {
                                                                                                sem_check_break_continue("continue", yylineno);
                                                                                                (yyval.stmt).node = ast_make_continue(yylineno); 
                                                                                             }
#line 3014 "build/generated/syntax.tab.c"
    break;

  case 151: /* statement: "break" "semi"  */
#line 859 "src/syntax.y"
                                                                                             {
                                                                                                sem_check_break_continue("break", yylineno);
                                                                                                (yyval.stmt).node = ast_make_break(yylineno); 
                                                                                             }
#line 3023 "build/generated/syntax.tab.c"
    break;

  case 152: /* statement: "semi"  */
#line 863 "src/syntax.y"
                                                                                             {(yyval.stmt).node = NULL;}
#line 3029 "build/generated/syntax.tab.c"
    break;

  case 153: /* expression_statement: general_expression "semi"  */
#line 865 "src/syntax.y"
                                                                                             {(yyval.stmt).node = (yyvsp[-1].expr).node;}
#line 3035 "build/generated/syntax.tab.c"
    break;

  case 154: /* if_statement: "if" "lparen" general_expression "rparen" statement if_tail  */
#line 866 "src/syntax.y"
                                                                                           {
                                                                                                /* type-check condition */
                                                                                                sem_check_condition((yyvsp[-3].expr).type, yylineno);
                                                                                                ASTNode *ifn = ast_make_if((yyvsp[-3].expr).node,
                                                                                                                            (yyvsp[-1].stmt).node,
                                                                                                                            (yyvsp[0].stmt).node,
                                                                                                                            yylineno);
                                                                                                (yyval.stmt).node = ifn;
                                                                                            }
#line 3049 "build/generated/syntax.tab.c"
    break;

  case 155: /* if_tail: "else" statement  */
#line 877 "src/syntax.y"
                                                                                            { (yyval.stmt).node = (yyvsp[0].stmt).node; }
#line 3055 "build/generated/syntax.tab.c"
    break;

  case 156: /* if_tail: %empty  */
#line 878 "src/syntax.y"
                                                                                            { (yyval.stmt).node = NULL; }
#line 3061 "build/generated/syntax.tab.c"
    break;

  case 157: /* while_statement: "while" "lparen" general_expression "rparen" loop_enter statement  */
#line 880 "src/syntax.y"
                                                                                              {
                                                                                                sem_leave_loop();
                                                                                                sem_check_condition((yyvsp[-3].expr).type, yylineno);
                                                                                                (yyval.stmt).node = ast_make_while((yyvsp[-3].expr).node, (yyvsp[0].stmt).node, yylineno);
                                                                                            }
#line 3071 "build/generated/syntax.tab.c"
    break;

  case 158: /* for_statement: "for" "lparen" optexpr "semi" optexpr "semi" general_expression "rparen" loop_enter statement  */
#line 887 "src/syntax.y"
                                                                                                                          {
                                                                                                            sem_leave_loop();
                                                                                                            sem_check_condition((yyvsp[-5].expr).type, yylineno);
                                                                                                            (yyval.stmt).node = ast_make_for((yyvsp[-7].expr).node, (yyvsp[-5].expr).node, (yyvsp[-3].expr).node, (yyvsp[0].stmt).node, yylineno);
                                                                                                        }
#line 3081 "build/generated/syntax.tab.c"
    break;

  case 159: /* optexpr: general_expression  */
#line 893 "src/syntax.y"
                                                                                            {(yyval.expr) = (yyvsp[0].expr);}
#line 3087 "build/generated/syntax.tab.c"
    break;

  case 160: /* optexpr: %empty  */
#line 894 "src/syntax.y"
                                                                                            { (yyval.expr).type = type_void; (yyval.expr).node = NULL; }
#line 3093 "build/generated/syntax.tab.c"
    break;

  case 161: /* return_statement: "return" optexpr "semi"  */
#line 896 "src/syntax.y"
                                                                                            {
                                                                                                sem_check_return(current_function_type, (yyvsp[-1].expr).type, yylineno);
                                                                                                (yyval.stmt).node = ast_make_return((yyvsp[-1].expr).node, yylineno);
                                                                                            }
#line 3102 "build/generated/syntax.tab.c"
    break;

  case 162: /* io_statement: "cin" "inp" in_list "semi"  */
#line 901 "src/syntax.y"
                                                                                            {
                                                                                                (yyval.stmt).node = ast_make_cin((yyvsp[-1].node), yylineno);
                                                                                            }
#line 3110 "build/generated/syntax.tab.c"
    break;

  case 163: /* io_statement: "cout" "out" out_list "semi"  */
#line 904 "src/syntax.y"
                                                                                            {
                                                                                                (yyval.stmt).node = ast_make_cout((yyvsp[-1].node), yylineno);
                                                                                            }
#line 3118 "build/generated/syntax.tab.c"
    break;

  case 164: /* in_list: in_list "inp" in_item  */
#line 908 "src/syntax.y"
                                                                                            {(yyval.node) = ast_list_append((yyvsp[-2].node), (yyvsp[0].node), yylineno);}
#line 3124 "build/generated/syntax.tab.c"
    break;

  case 165: /* in_list: in_item  */
#line 909 "src/syntax.y"
                                                                                            {(yyval.node) = (yyvsp[0].node);}
#line 3130 "build/generated/syntax.tab.c"
    break;

  case 166: /* in_item: variable  */
#line 911 "src/syntax.y"
                                                                                            {
                                                                                                sem_check_writable_lvalue((yyvsp[0].expr).node, yylineno);
                                                                                                (yyval.node) = (yyvsp[0].expr).node;
                                                                                            }
#line 3139 "build/generated/syntax.tab.c"
    break;

  case 167: /* out_list: out_list "out" out_item  */
#line 916 "src/syntax.y"
                                                                                            {(yyval.node) = ast_list_append((yyvsp[-2].node), (yyvsp[0].node), yylineno);}
#line 3145 "build/generated/syntax.tab.c"
    break;

  case 168: /* out_list: out_item  */
#line 917 "src/syntax.y"
                                                                                            {(yyval.node) = (yyvsp[0].node);}
#line 3151 "build/generated/syntax.tab.c"
    break;

  case 169: /* out_item: general_expression  */
#line 919 "src/syntax.y"
                                                                                            {
                                                                                                sem_check_printable((yyvsp[0].expr).type, yylineno);
                                                                                                (yyval.node) = (yyvsp[0].expr).node;
                                                                                            }
#line 3160 "build/generated/syntax.tab.c"
    break;

  case 170: /* $@4: %empty  */
#line 924 "src/syntax.y"
                                     {symtab_enter_scope(); sem_scope_push_offsets();}
#line 3166 "build/generated/syntax.tab.c"
    break;

  case 171: /* comp_statement: "lbrace" $@4 decl_statements "rbrace"  */
#line 924 "src/syntax.y"
                                                                                                                { sem_scope_pop_offsets(); symtab_leave_scope(); (yyval.stmt).node = (yyvsp[-1].stmt).node; }
#line 3172 "build/generated/syntax.tab.c"
    break;

  case 172: /* $@5: %empty  */
#line 925 "src/syntax.y"
                                       {symtab_enter_scope(); sem_scope_push_offsets();}
#line 3178 "build/generated/syntax.tab.c"
    break;

  case 173: /* comp_statement: "lbrace" $@5 error "rbrace"  */
#line 925 "src/syntax.y"
                                                                                                        { sem_scope_pop_offsets(); symtab_leave_scope(); yyerrok; (yyval.stmt).node = NULL; }
#line 3184 "build/generated/syntax.tab.c"
    break;

  case 174: /* main_function: main_header "lbrace" decl_statements "rbrace"  */
#line 927 "src/syntax.y"
                                                                            { 
                                                                                sem_frame_end(current_function_name, yylineno);
                                                                                symtab_leave_scope();    
                                                                                current_function_type = NULL; 
                                                                                ASTNode *body = (yyvsp[-1].stmt).node;
                                                                                (yyval.stmt).node = ast_make_func_decl("main", body, yylineno);
                                                                            }
#line 3196 "build/generated/syntax.tab.c"
    break;

  case 175: /* main_header: "int" "main" "lparen" "rparen"  */
#line 934 "src/syntax.y"
                                                                            {
                                                                                current_function_type = type_int;
                                                                                current_function_name = "main";
                                                                                if (!symtab_insert("main", SYM_FUNC, type_int)) {
                                                                                    YYERROR_FMT("Redeclaration of function 'main'");
                                                                                }
                                                                                symtab_enter_scope();
                                                                                sem_frame_begin("main", yylineno);
                                                                            }
#line 3210 "build/generated/syntax.tab.c"
    break;

  case 176: /* main_header: error "main" "lparen" "rparen"  */
#line 943 "src/syntax.y"
                                                                            {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors"); yyerrok; symtab_enter_scope();}
#line 3216 "build/generated/syntax.tab.c"
    break;

  case 177: /* main_header: "int" error "lparen" "rparen"  */
#line 944 "src/syntax.y"
                                                                            {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors"); yyerrok; symtab_enter_scope();}
#line 3222 "build/generated/syntax.tab.c"
    break;

  case 178: /* main_header: "int" "main" error "rparen"  */
#line 945 "src/syntax.y"
                                                                            {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors"); yyerrok; symtab_enter_scope();}
#line 3228 "build/generated/syntax.tab.c"
    break;

  case 179: /* main_header: "int" "main" "lparen" error  */
#line 946 "src/syntax.y"
                                                                            {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors"); yyerrok; symtab_enter_scope();}
#line 3234 "build/generated/syntax.tab.c"
    break;


#line 3238 "build/generated/syntax.tab.c"

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

#line 948 "src/syntax.y"


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
    sem_check_undefined_prototypes();

    extern ASTNode *ast_root;
    if (ast_root && AST_DEBUG) {
       ast_print(ast_root, "ast.dot");
    }
    
    //--IR generation--
    codegen(ast_root);
    if(IR_DEBUG){
        ir_print();
    }

    //--MIPS assembly generation--
    mips_init("out.asm");             // Δημιουργία αρχείου
    mips_data_section();            // Εγγραφή .data (Strings κλπ)
    generate_mips();                // Μετάφραση Quads σε MIPS
    mips_finish();                  // Κλείσιμο αρχείου


    fclose(yyin);

    //free?????????
    return 0;
}

void yyerror (const char *str){
    yyerrorno++;
    if (yytext && *yytext)
        fprintf(stderr, "ERROR: [line: %d]: %s near '%s'\n", yylineno, str, yytext);
    else
        fprintf(stderr, "ERROR: [line: %d]: %s\n", yylineno, str);

    if (yyerrorno >= MAX_ERRORS) {
        fprintf(stderr, "MAX ERRORS FOUND\n");
        exit(EXIT_FAILURE);
    }
}
