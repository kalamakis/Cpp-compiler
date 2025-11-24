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
    #include "hashtable.h"
    #include "functions.h"

    
    int yyerrorno = 0;
    int scope = 0;
    HASHTBL *htable;
    extern FILE *yyin;
    extern int yylex();
    extern yylineno;
    void yyerror(char *s);

    TypeKind current_type = TYPE_ERROR;

    

#line 91 "syntax.tab.c"

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
  YYSYMBOL_constdefs = 77,                 /* constdefs  */
  YYSYMBOL_constdef = 78,                  /* constdef  */
  YYSYMBOL_init_value = 79,                /* init_value  */
  YYSYMBOL_expression = 80,                /* expression  */
  YYSYMBOL_variable = 81,                  /* variable  */
  YYSYMBOL_general_expression = 82,        /* general_expression  */
  YYSYMBOL_assignment = 83,                /* assignment  */
  YYSYMBOL_expression_list = 84,           /* expression_list  */
  YYSYMBOL_constant = 85,                  /* constant  */
  YYSYMBOL_listexpression = 86,            /* listexpression  */
  YYSYMBOL_init_values = 87,               /* init_values  */
  YYSYMBOL_enum_declaration = 88,          /* enum_declaration  */
  YYSYMBOL_enum_body = 89,                 /* enum_body  */
  YYSYMBOL_id_list = 90,                   /* id_list  */
  YYSYMBOL_initializer = 91,               /* initializer  */
  YYSYMBOL_class_declaration = 92,         /* class_declaration  */
  YYSYMBOL_class_body = 93,                /* class_body  */
  YYSYMBOL_94_1 = 94,                      /* $@1  */
  YYSYMBOL_parent = 95,                    /* parent  */
  YYSYMBOL_members_methods = 96,           /* members_methods  */
  YYSYMBOL_access = 97,                    /* access  */
  YYSYMBOL_member_or_method = 98,          /* member_or_method  */
  YYSYMBOL_member = 99,                    /* member  */
  YYSYMBOL_var_declaration = 100,          /* var_declaration  */
  YYSYMBOL_variabledefs = 101,             /* variabledefs  */
  YYSYMBOL_variabledef = 102,              /* variabledef  */
  YYSYMBOL_anonymous_union = 103,          /* anonymous_union  */
  YYSYMBOL_union_body = 104,               /* union_body  */
  YYSYMBOL_105_2 = 105,                    /* $@2  */
  YYSYMBOL_fields = 106,                   /* fields  */
  YYSYMBOL_field = 107,                    /* field  */
  YYSYMBOL_method = 108,                   /* method  */
  YYSYMBOL_short_func_declaration = 109,   /* short_func_declaration  */
  YYSYMBOL_short_par_func_header = 110,    /* short_par_func_header  */
  YYSYMBOL_func_header_start = 111,        /* func_header_start  */
  YYSYMBOL_parameter_types = 112,          /* parameter_types  */
  YYSYMBOL_pass_list_dims = 113,           /* pass_list_dims  */
  YYSYMBOL_nopar_func_header = 114,        /* nopar_func_header  */
  YYSYMBOL_union_declaration = 115,        /* union_declaration  */
  YYSYMBOL_global_var_declaration = 116,   /* global_var_declaration  */
  YYSYMBOL_init_variabledefs = 117,        /* init_variabledefs  */
  YYSYMBOL_init_variabledef = 118,         /* init_variabledef  */
  YYSYMBOL_func_declaration = 119,         /* func_declaration  */
  YYSYMBOL_full_func_declaration = 120,    /* full_func_declaration  */
  YYSYMBOL_full_par_func_header = 121,     /* full_par_func_header  */
  YYSYMBOL_class_func_header_start = 122,  /* class_func_header_start  */
  YYSYMBOL_func_class = 123,               /* func_class  */
  YYSYMBOL_parameter_list = 124,           /* parameter_list  */
  YYSYMBOL_pass_variabledef = 125,         /* pass_variabledef  */
  YYSYMBOL_nopar_class_func_header = 126,  /* nopar_class_func_header  */
  YYSYMBOL_decl_statements = 127,          /* decl_statements  */
  YYSYMBOL_declarations = 128,             /* declarations  */
  YYSYMBOL_decltype = 129,                 /* decltype  */
  YYSYMBOL_statements = 130,               /* statements  */
  YYSYMBOL_statement = 131,                /* statement  */
  YYSYMBOL_expression_statement = 132,     /* expression_statement  */
  YYSYMBOL_if_statement = 133,             /* if_statement  */
  YYSYMBOL_if_tail = 134,                  /* if_tail  */
  YYSYMBOL_while_statement = 135,          /* while_statement  */
  YYSYMBOL_for_statement = 136,            /* for_statement  */
  YYSYMBOL_optexpr = 137,                  /* optexpr  */
  YYSYMBOL_return_statement = 138,         /* return_statement  */
  YYSYMBOL_io_statement = 139,             /* io_statement  */
  YYSYMBOL_in_list = 140,                  /* in_list  */
  YYSYMBOL_in_item = 141,                  /* in_item  */
  YYSYMBOL_out_list = 142,                 /* out_list  */
  YYSYMBOL_out_item = 143,                 /* out_item  */
  YYSYMBOL_comp_statement = 144,           /* comp_statement  */
  YYSYMBOL_145_3 = 145,                    /* $@3  */
  YYSYMBOL_main_function = 146,            /* main_function  */
  YYSYMBOL_main_header = 147               /* main_header  */
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
#define YYLAST   632

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  82
/* YYNRULES -- Number of rules.  */
#define YYNRULES  177
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
       0,   124,   124,   126,   127,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   139,   141,   142,   156,   157,   158,
     159,   160,   163,   163,   165,   166,   168,   168,   170,   172,
     173,   175,   176,   177,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   198,   199,   200,   201,   202,   204,   205,   207,
     208,   210,   211,   213,   213,   213,   213,   214,   215,   216,
     217,   219,   220,   221,   223,   224,   226,   227,   227,   228,
     229,   231,   232,   234,   234,   234,   234,   235,   236,   238,
     239,   242,   243,   245,   246,   249,   251,   253,   253,   255,
     256,   258,   260,   262,   263,   266,   269,   271,   272,   274,
     275,   277,   279,   281,   282,   285,   286,   288,   290,   291,
     293,   294,   295,   297,   298,   300,   302,   304,   305,   307,
     308,   310,   312,   313,   314,   315,   317,   318,   320,   320,
     321,   322,   323,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   336,   337,   338,   339,   341,   342,   343,
     344,   346,   347,   348,   350,   351,   353,   354,   355,   357,
     358,   358,   359,   360,   361,   362,   363,   364
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
  "dim", "const_declaration", "constdefs", "constdef", "init_value",
  "expression", "variable", "general_expression", "assignment",
  "expression_list", "constant", "listexpression", "init_values",
  "enum_declaration", "enum_body", "id_list", "initializer",
  "class_declaration", "class_body", "$@1", "parent", "members_methods",
  "access", "member_or_method", "member", "var_declaration",
  "variabledefs", "variabledef", "anonymous_union", "union_body", "$@2",
  "fields", "field", "method", "short_func_declaration",
  "short_par_func_header", "func_header_start", "parameter_types",
  "pass_list_dims", "nopar_func_header", "union_declaration",
  "global_var_declaration", "init_variabledefs", "init_variabledef",
  "func_declaration", "full_func_declaration", "full_par_func_header",
  "class_func_header_start", "func_class", "parameter_list",
  "pass_variabledef", "nopar_class_func_header", "decl_statements",
  "declarations", "decltype", "statements", "statement",
  "expression_statement", "if_statement", "if_tail", "while_statement",
  "for_statement", "optexpr", "return_statement", "io_statement",
  "in_list", "in_item", "out_list", "out_item", "comp_statement", "$@3",
  "main_function", "main_header", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-235)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-161)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -235,    83,   584,  -235,    72,   597,  -235,   121,  -235,  -235,
     597,    59,  -235,    75,    78,  -235,  -235,  -235,   101,  -235,
    -235,  -235,  -235,  -235,    96,   105,    60,  -235,  -235,  -235,
    -235,   102,   117,   115,  -235,   130,   147,  -235,  -235,  -235,
     101,   156,    51,   174,   159,  -235,   158,  -235,   193,   191,
      28,  -235,  -235,   149,  -235,   330,   330,   292,   330,   330,
     179,   222,   223,   234,    27,  -235,   175,  -235,   253,   237,
    -235,   238,   236,   265,   251,    -3,   271,   438,  -235,  -235,
    -235,   101,  -235,    13,   110,   112,  -235,   257,   261,   255,
     270,   279,   462,   280,   268,   276,  -235,  -235,  -235,  -235,
    -235,   532,   532,    35,   532,   284,   164,  -235,   485,  -235,
     579,    52,   197,  -235,  -235,  -235,   281,   371,   602,   231,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,   283,  -235,
      14,   125,   287,   293,  -235,  -235,  -235,  -235,  -235,  -235,
     210,  -235,   174,  -235,  -235,   285,  -235,   597,   191,     3,
    -235,  -235,   304,  -235,   438,  -235,   579,   136,   331,   333,
    -235,   337,   333,  -235,  -235,  -235,  -235,   597,  -235,   597,
    -235,  -235,   532,   532,   462,   309,   319,   532,    35,   532,
     327,  -235,    57,  -235,   532,   322,   133,   309,   317,   330,
     532,   532,   532,   532,   532,   532,  -235,   485,   348,   532,
     532,  -235,   532,  -235,   602,   289,    23,   101,   332,  -235,
    -235,   337,  -235,  -235,  -235,     9,   438,     7,  -235,  -235,
     219,   101,  -235,    20,  -235,  -235,   350,  -235,  -235,    86,
    -235,  -235,  -235,   304,    17,    14,   134,   140,   334,  -235,
     144,    57,     8,  -235,   309,    42,  -235,   165,  -235,  -235,
    -235,   324,   199,   100,   228,    18,   327,  -235,   338,  -235,
    -235,    68,  -235,   101,   230,  -235,  -235,  -235,  -235,   344,
    -235,   339,   349,   351,    36,   229,    31,  -235,  -235,   191,
     438,  -235,  -235,  -235,  -235,  -235,   412,   412,   462,  -235,
    -235,    35,  -235,   532,  -235,  -235,  -235,  -235,   243,  -235,
     101,  -235,  -235,  -235,  -235,  -235,   229,  -235,   101,  -235,
    -235,  -235,  -235,  -235,  -235,   354,   359,  -235,  -235,  -235,
    -235,   388,  -235,   361,  -235,  -235,  -235,  -235,  -235,   362,
     383,   149,   412,  -235,   508,  -235,   372,    17,  -235,   373,
     412,  -235
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,     0,     0,    19,     0,    18,    20,
       0,     0,    21,     0,     0,    16,     3,     5,    23,    15,
       6,     7,     8,   118,     0,     0,     0,     9,    10,    11,
     119,     0,     0,     0,     2,     0,     0,    12,    13,    17,
      23,     0,     0,     0,    80,    97,     0,    22,     0,    75,
       0,   116,   103,     0,   104,   139,   139,     0,   139,   139,
       0,     0,     0,     0,     0,    25,     0,    30,     0,     0,
      77,     0,     0,     0,     0,    25,     0,   139,   117,   114,
     113,    23,   111,    23,     0,     0,   138,     0,     0,     0,
       0,     0,   139,     0,     0,     0,    56,    64,    65,    66,
      63,   139,   139,   139,   139,     0,   139,   152,    62,   170,
      60,    45,     0,    58,    48,    51,     0,   139,     0,     0,
     141,   143,   144,   145,   146,   147,   148,   149,     0,   131,
      23,     0,     0,     0,   174,    25,   175,   176,   177,   173,
       0,    28,     0,    79,    76,     0,   112,     0,    75,     0,
      70,   126,    95,   125,   139,    74,    32,    45,     0,     0,
     115,   109,    25,   129,   108,   128,   105,     0,   124,     0,
     150,   151,   139,   139,   139,   159,     0,   139,   139,   139,
      41,    40,    43,    42,   139,     0,     0,    61,     0,   139,
     139,   139,   139,   139,   139,   139,    44,    62,     0,   139,
     139,   153,   139,   122,     0,     0,    55,    23,     0,   140,
     120,     0,   123,   121,   172,     0,   139,     0,    24,    29,
      86,    23,   101,     0,   100,    73,     0,    71,    69,     0,
      55,    25,   130,   110,    23,    23,     0,     0,     0,   161,
       0,   166,     0,   165,   169,     0,   168,     0,    50,    49,
      67,     0,    34,    35,    36,    37,    38,    39,     0,    53,
      59,     0,    57,    23,     0,    94,   142,    14,    31,     0,
      27,     0,     0,     0,    86,     0,     0,    98,    99,    75,
     139,    33,   109,    25,   107,   127,   139,   139,   139,    47,
     162,   139,   163,   139,    54,   171,    46,    52,     0,   137,
      23,    26,    83,    84,    85,    78,     0,    97,    23,    82,
      87,    89,    90,    88,   102,     0,     0,    92,    91,    72,
      68,   156,   157,     0,   164,   167,   136,    93,    81,     0,
       0,     0,   139,   154,   139,    96,    25,    23,   155,     0,
     139,   158
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -235,  -235,  -235,  -235,  -235,    -2,   316,   -17,   -61,  -235,
    -235,  -235,   282,  -132,   -59,   -66,   -87,   224,   245,  -235,
    -235,  -235,  -235,  -235,  -235,  -133,  -235,  -235,  -235,  -235,
    -235,   153,   127,  -235,  -234,  -187,   -16,  -235,   138,  -235,
    -235,   217,  -235,   441,  -235,   447,  -235,   216,   449,  -235,
    -235,  -235,   379,  -235,  -235,  -235,  -235,  -235,   397,   227,
    -235,   -42,  -235,   -46,   347,  -112,  -235,  -235,  -235,  -235,
    -235,  -168,  -235,  -235,  -235,   177,  -235,   172,  -235,  -235,
    -235,  -235
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,    16,    17,   221,    19,   159,   152,   218,
      20,    66,    67,   155,   110,   111,   112,   113,   188,   114,
     115,   229,    21,    74,   149,    78,    22,    69,   145,    70,
     274,   275,   309,   310,   222,   276,   265,   312,    71,    72,
     223,   224,   313,   314,    24,   315,    84,   164,   316,    27,
      28,    50,    51,    29,    30,    31,    32,    76,    85,   165,
      33,   116,   117,   158,   119,   120,   121,   122,   333,   123,
     124,   176,   125,   126,   242,   243,   245,   246,   127,   189,
      34,    35
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,    48,    49,    40,   140,   175,   238,   209,    43,   118,
     118,   157,   118,   118,   128,   225,   132,   133,   156,   186,
     264,   187,   228,    61,     6,    39,     8,     9,   138,    79,
      47,    47,   317,    12,    47,   157,   157,   182,   157,   269,
     -16,   311,   180,   181,  -106,   183,   271,   272,   273,    86,
      15,    83,    63,   -16,   226,   130,   151,   290,   267,   194,
     195,   227,   270,   217,    96,    49,   162,   163,   291,   161,
     211,   204,   311,   282,   215,   139,   298,    80,   277,    81,
     318,   105,   300,     3,   268,   236,   237,   175,   157,    44,
     240,   292,   244,   209,   305,   156,   196,   247,    64,   197,
      36,   233,   198,   293,   199,    45,   200,   198,    46,    54,
     187,   200,   241,   261,   163,   262,   207,    55,    47,   202,
     323,    37,    41,   297,   157,   157,   157,   157,   157,   157,
      38,   252,   253,   254,   255,   256,   257,   280,   -17,   192,
     193,   194,   195,   118,   281,    52,   319,   251,   320,    42,
     157,   -17,    53,     6,    39,     8,     9,   156,   166,    56,
     168,   167,    12,   169,    57,   234,   339,   235,     6,    39,
       8,     9,    58,   212,   321,   322,   169,    12,    86,    15,
     196,   249,   286,   197,   202,   202,   198,    59,   287,    93,
     200,   202,   289,    96,    60,   202,    97,    82,    98,    99,
     100,   175,   263,    62,    65,   101,   244,   102,   103,   104,
     105,   106,    68,   294,   157,    73,   202,   283,   108,   163,
     338,   156,   233,    75,   141,   241,   142,   134,   341,   271,
     272,   273,   208,     6,    39,     8,     9,   191,   192,   193,
     194,   195,    12,    77,   307,    86,   201,   175,   202,    87,
      88,    89,   135,    90,    91,    92,    93,    94,    95,    15,
      96,  -139,   216,    97,   217,    98,    99,   100,   193,   194,
     195,   136,   101,   308,   102,   103,   104,   105,   106,   299,
     107,   300,   137,   143,   327,   108,   144,   146,   109,  -134,
     208,   330,   326,   147,   300,   148,     6,    39,     8,     9,
     150,   153,   172,    86,   308,    12,   170,    87,    88,    89,
     171,    90,    91,    92,    93,    94,    95,   173,    96,  -139,
     283,    97,    15,    98,    99,   100,   174,   177,   178,   337,
     101,   184,   102,   103,   104,   105,   106,   179,   107,   203,
     129,   210,   220,   108,    86,   213,   109,  -132,    87,    88,
      89,   214,    90,    91,    92,    93,    94,    95,   217,    96,
     202,   230,    97,   231,    98,    99,   100,   232,   239,   195,
     248,   101,   250,   102,   103,   104,   105,   106,   259,   107,
     279,   266,   295,   288,   108,    86,   296,   109,  -135,    87,
      88,    89,   302,    90,    91,    92,    93,    94,    95,   301,
      96,   331,   303,    97,   304,    98,    99,   100,    54,   332,
     334,   335,   101,   336,   102,   103,   104,   105,   106,  -106,
     107,   340,   185,   260,   219,   108,    86,   306,   109,  -133,
      87,    88,    89,   328,    90,    91,    92,    93,    94,    95,
     278,    96,   258,    23,    97,   329,    98,    99,   100,    25,
     284,    26,    86,   101,   131,   102,   103,   104,   105,   106,
     160,   107,   285,    93,   205,   325,   108,    96,   324,   109,
      97,     0,    98,    99,   100,     0,    86,     0,     0,   101,
       0,   102,   103,   104,   105,   106,     0,    93,     0,     0,
       0,    96,   108,     0,    97,   154,    98,    99,   100,    86,
       0,     0,     0,   101,     0,   102,   103,   104,   105,   106,
      93,  -160,     0,     0,    96,  -139,   108,    97,     0,    98,
      99,   100,    86,     0,     0,     0,   101,     0,   102,   103,
     104,   105,   106,    93,     0,     0,     0,    96,     0,   108,
      97,     0,    98,    99,   100,     0,    86,     0,     0,   101,
       0,   102,   103,   104,   105,   106,  -160,    93,     0,     0,
       0,    96,   108,     0,    97,     0,    98,    99,   100,     0,
       0,     0,     0,   101,     0,   102,   103,   104,   105,   106,
       0,     0,     0,     0,     0,     4,   108,     5,     6,     7,
       8,     9,    10,    11,     0,     0,     0,    12,     0,    13,
      14,     6,    39,     8,     9,     0,     6,    39,     8,     9,
      12,     0,     0,     0,    15,    12,   190,   191,   192,   193,
     194,   195,     0,     0,     0,     0,     0,    15,     0,     0,
       0,     0,   206
};

static const yytype_int16 yycheck[] =
{
       2,    18,    18,     5,    65,    92,   174,   119,    10,    55,
      56,    77,    58,    59,    56,   148,    58,    59,    77,   106,
     207,   108,   154,    40,     4,     5,     6,     7,     1,     1,
      17,    17,     1,    13,    17,   101,   102,   103,   104,    32,
      17,   275,   101,   102,    47,   104,    10,    11,    12,    14,
      30,    53,     1,    30,    51,    57,    59,    49,    49,    41,
      42,    58,    55,    54,    29,    81,    83,    83,    60,    56,
      56,   117,   306,    56,   135,    48,   263,    49,    58,    51,
      49,    46,    51,     0,   216,   172,   173,   174,   154,    30,
     177,    49,   179,   205,    58,   154,    44,   184,    47,    47,
      28,   162,    50,    61,    52,    30,    54,    50,    30,    49,
     197,    54,   178,   200,   130,   202,   118,    57,    17,    51,
     288,    49,     1,    55,   190,   191,   192,   193,   194,   195,
      58,   190,   191,   192,   193,   194,   195,    51,    17,    39,
      40,    41,    42,   189,    58,    49,   279,   189,   280,    28,
     216,    30,    47,     4,     5,     6,     7,   216,    48,    57,
      48,    51,    13,    51,    47,   167,   334,   169,     4,     5,
       6,     7,    57,    48,   286,   287,    51,    13,    14,    30,
      44,    48,    48,    47,    51,    51,    50,    57,    48,    25,
      54,    51,    48,    29,    47,    51,    32,    48,    34,    35,
      36,   288,   204,    47,    30,    41,   293,    43,    44,    45,
      46,    47,    53,    48,   280,    57,    51,   234,    54,   235,
     332,   280,   283,    30,    49,   291,    51,    48,   340,    10,
      11,    12,     1,     4,     5,     6,     7,    38,    39,    40,
      41,    42,    13,    52,    15,    14,    49,   334,    51,    18,
      19,    20,    30,    22,    23,    24,    25,    26,    27,    30,
      29,    30,    52,    32,    54,    34,    35,    36,    40,    41,
      42,    48,    41,   275,    43,    44,    45,    46,    47,    49,
      49,    51,    48,    30,   300,    54,    49,    49,    57,    58,
       1,   308,    49,    57,    51,    30,     4,     5,     6,     7,
      49,    30,    47,    14,   306,    13,    49,    18,    19,    20,
      49,    22,    23,    24,    25,    26,    27,    47,    29,    30,
     337,    32,    30,    34,    35,    36,    47,    47,    60,   331,
      41,    47,    43,    44,    45,    46,    47,    61,    49,    58,
      48,    58,    57,    54,    14,    58,    57,    58,    18,    19,
      20,    58,    22,    23,    24,    25,    26,    27,    54,    29,
      51,    30,    32,    30,    34,    35,    36,    30,    49,    42,
      48,    41,    55,    43,    44,    45,    46,    47,    30,    49,
      30,    49,    58,    49,    54,    14,    48,    57,    58,    18,
      19,    20,    53,    22,    23,    24,    25,    26,    27,    55,
      29,    47,    53,    32,    53,    34,    35,    36,    49,    21,
      49,    49,    41,    30,    43,    44,    45,    46,    47,    47,
      49,    48,   106,   199,   142,    54,    14,   274,    57,    58,
      18,    19,    20,   306,    22,    23,    24,    25,    26,    27,
     223,    29,   197,     2,    32,   307,    34,    35,    36,     2,
     234,     2,    14,    41,    57,    43,    44,    45,    46,    47,
      81,    49,   235,    25,   117,   293,    54,    29,   291,    57,
      32,    -1,    34,    35,    36,    -1,    14,    -1,    -1,    41,
      -1,    43,    44,    45,    46,    47,    -1,    25,    -1,    -1,
      -1,    29,    54,    -1,    32,    57,    34,    35,    36,    14,
      -1,    -1,    -1,    41,    -1,    43,    44,    45,    46,    47,
      25,    49,    -1,    -1,    29,    30,    54,    32,    -1,    34,
      35,    36,    14,    -1,    -1,    -1,    41,    -1,    43,    44,
      45,    46,    47,    25,    -1,    -1,    -1,    29,    -1,    54,
      32,    -1,    34,    35,    36,    -1,    14,    -1,    -1,    41,
      -1,    43,    44,    45,    46,    47,    48,    25,    -1,    -1,
      -1,    29,    54,    -1,    32,    -1,    34,    35,    36,    -1,
      -1,    -1,    -1,    41,    -1,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,     1,    54,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    13,    -1,    15,
      16,     4,     5,     6,     7,    -1,     4,     5,     6,     7,
      13,    -1,    -1,    -1,    30,    13,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    67,    68,     0,     1,     3,     4,     5,     6,     7,
       8,     9,    13,    15,    16,    30,    69,    70,    71,    72,
      76,    88,    92,   109,   110,   111,   114,   115,   116,   119,
     120,   121,   122,   126,   146,   147,    28,    49,    58,     5,
      71,     1,    28,    71,    30,    30,    30,    17,    73,   102,
     117,   118,    49,    47,    49,    57,    57,    47,    57,    57,
      47,    73,    47,     1,    47,    30,    77,    78,    53,    93,
      95,   104,   105,    57,    89,    30,   123,    52,    91,     1,
      49,    51,    48,    71,   112,   124,    14,    18,    19,    20,
      22,    23,    24,    25,    26,    27,    29,    32,    34,    35,
      36,    41,    43,    44,    45,    46,    47,    49,    54,    57,
      80,    81,    82,    83,    85,    86,   127,   128,   129,   130,
     131,   132,   133,   135,   136,   138,   139,   144,   127,    48,
      71,   124,   127,   127,    48,    30,    48,    48,     1,    48,
      74,    49,    51,    30,    49,    94,    49,    57,    30,    90,
      49,    59,    74,    30,    57,    79,    80,    81,   129,    73,
     118,    56,    73,   102,   113,   125,    48,    51,    48,    51,
      49,    49,    47,    47,    47,    82,   137,    47,    60,    61,
      80,    80,    81,    80,    47,    72,    82,    82,    84,   145,
      37,    38,    39,    40,    41,    42,    44,    47,    50,    52,
      54,    49,    51,    58,   129,   130,    30,    71,     1,   131,
      58,    56,    48,    58,    58,    74,    52,    54,    75,    78,
      57,    71,   100,   106,   107,    91,    51,    58,    79,    87,
      30,    30,    30,    74,    71,    71,    82,    82,   137,    49,
      82,    81,   140,   141,    82,   142,   143,    82,    48,    48,
      55,   127,    80,    80,    80,    80,    80,    80,    84,    30,
      83,    82,    82,    71,   101,   102,    49,    49,    79,    32,
      55,    10,    11,    12,    96,    97,   101,    58,   107,    30,
      51,    58,    56,    73,   113,   125,    48,    48,    49,    48,
      49,    60,    49,    61,    48,    58,    48,    55,   101,    49,
      51,    55,    53,    53,    53,    58,    97,    15,    71,    98,
      99,   100,   103,   108,   109,   111,   114,     1,    49,    91,
      79,   131,   131,   137,   141,   143,    49,   102,    98,   104,
      73,    47,    21,   134,    49,    49,    30,    71,   131,   137,
      48,   131
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    68,    68,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    70,    71,    71,    72,    72,    72,
      72,    72,    73,    73,    74,    74,    75,    75,    76,    77,
      77,    78,    79,    79,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    81,    81,    81,    81,    81,    82,    82,    83,
      83,    84,    84,    85,    85,    85,    85,    86,    87,    87,
      88,    89,    90,    90,    91,    91,    92,    94,    93,    95,
      95,    96,    96,    97,    97,    97,    97,    98,    98,    99,
      99,   100,   100,   101,   101,   102,   103,   105,   104,   106,
     106,   107,   108,   109,   109,   110,   111,   112,   112,   113,
     113,   114,   115,   116,   116,   117,   117,   118,   119,   119,
     120,   120,   120,   121,   121,   122,   123,   124,   124,   125,
     125,   126,   127,   127,   127,   127,   128,   128,   129,   129,
     130,   130,   130,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   132,   133,   134,   134,   135,   136,   137,
     137,   138,   139,   139,   140,   140,   141,   142,   142,   143,
     145,   144,   146,   147,   147,   147,   147,   147
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     6,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     2,     0,     3,     2,     4,     3,
       1,     4,     1,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     2,     1,     4,     4,     1,     3,
       3,     1,     4,     3,     4,     2,     1,     3,     1,     3,
       1,     1,     0,     1,     1,     1,     1,     3,     3,     1,
       4,     3,     4,     2,     2,     0,     4,     0,     5,     2,
       0,     3,     2,     2,     2,     2,     0,     1,     1,     1,
       1,     3,     3,     3,     1,     3,     3,     0,     4,     2,
       1,     1,     1,     2,     2,     4,     3,     4,     2,     1,
       2,     3,     4,     3,     3,     3,     1,     2,     1,     1,
       4,     4,     4,     4,     4,     4,     2,     4,     2,     1,
       2,     3,     2,     1,     1,     0,     5,     4,     1,     0,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     2,     6,     2,     0,     5,     9,     1,
       0,     3,     4,     4,     3,     1,     1,     3,     1,     1,
       0,     4,     4,     4,     4,     4,     4,     4
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
#line 124 "syntax.y"
                                                                                {hashtbl_get(htable,scope);}
#line 1815 "syntax.tab.c"
    break;

  case 4: /* global_declarations: %empty  */
#line 127 "syntax.y"
                                             {;}
#line 1821 "syntax.tab.c"
    break;

  case 12: /* global_declaration: error "semi"  */
#line 136 "syntax.y"
                                                                                {fprintf(stderr, " HINT: syntax error in global declaration\n"); yyerrok;}
#line 1827 "syntax.tab.c"
    break;

  case 13: /* global_declaration: error "rbrace"  */
#line 137 "syntax.y"
                                                                                {fprintf(stderr, " HINT: in global declaration\n"); yyerrok; }
#line 1833 "syntax.tab.c"
    break;

  case 14: /* typedef_declaration: "typedef" typename listspec "id" dims "semi"  */
#line 139 "syntax.y"
                                                                                {hashtbl_insert(htable,(yyvsp[-2].strval),create_info(SYM_TYPE, current_type),scope);}
#line 1839 "syntax.tab.c"
    break;

  case 15: /* typename: standard_type  */
#line 141 "syntax.y"
                                                                                { (yyval.type) = (yyvsp[0].type); current_type=(yyvsp[0].type); }
#line 1845 "syntax.tab.c"
    break;

  case 16: /* typename: "id"  */
#line 142 "syntax.y"
                                                                                {
                                                                                    SymbolInfo *info = hashtbl_lookup(htable, (yyvsp[0].strval), scope); /* or your lookup */ ///ΑΝ ΔΕΝ ΕΙΝΑΙ ΣΤΑΝΤΑΡ ΤΥΠΟΣ ΕΛΕΓΧΕΙ ΑΝΑ 
                                                                                    if (!info || info->kind != SYM_TYPE) {
                                                                                        fprintf(stderr,
                                                                                                "ERROR: [line: %d]: '%s' is not a type name\n",
                                                                                                yylineno, (yyvsp[0].strval));
                                                                                        (yyval.type) = TYPE_ERROR;
                                                                                        current_type = TYPE_ERROR;
                                                                                    } else {
                                                                                        (yyval.type) = info->type;  /* e.g. TYPE_CLASS, TYPE_ENUM, TYPE_TYPEDEF... */
                                                                                        current_type = info->type;
                                                                                    }
                                                                                }
#line 1863 "syntax.tab.c"
    break;

  case 17: /* standard_type: "int"  */
#line 156 "syntax.y"
                                     { (yyval.type) = TYPE_INT; }
#line 1869 "syntax.tab.c"
    break;

  case 18: /* standard_type: "float"  */
#line 157 "syntax.y"
                                       { (yyval.type) = TYPE_FLOAT; }
#line 1875 "syntax.tab.c"
    break;

  case 19: /* standard_type: "char"  */
#line 158 "syntax.y"
                                       { (yyval.type) = TYPE_CHAR; }
#line 1881 "syntax.tab.c"
    break;

  case 20: /* standard_type: "string"  */
#line 159 "syntax.y"
                                       { (yyval.type) = TYPE_STRING; }
#line 1887 "syntax.tab.c"
    break;

  case 21: /* standard_type: "void"  */
#line 160 "syntax.y"
                                       { (yyval.type) = TYPE_VOID; }
#line 1893 "syntax.tab.c"
    break;

  case 23: /* listspec: %empty  */
#line 163 "syntax.y"
                                                    {;}
#line 1899 "syntax.tab.c"
    break;

  case 25: /* dims: %empty  */
#line 166 "syntax.y"
                                             {;}
#line 1905 "syntax.tab.c"
    break;

  case 31: /* constdef: "id" dims "assign" init_value  */
#line 175 "syntax.y"
                                                                                {hashtbl_insert(htable,(yyvsp[-3].strval),NULL,scope);}
#line 1911 "syntax.tab.c"
    break;

  case 53: /* variable: variable "dot" "id"  */
#line 199 "syntax.y"
                                                                                {hashtbl_insert(htable,(yyvsp[0].strval),NULL,scope);}
#line 1917 "syntax.tab.c"
    break;

  case 55: /* variable: decltype "id"  */
#line 201 "syntax.y"
                                                                                {hashtbl_insert(htable,(yyvsp[0].strval),NULL,scope);}
#line 1923 "syntax.tab.c"
    break;

  case 62: /* expression_list: %empty  */
#line 211 "syntax.y"
                                             {;}
#line 1929 "syntax.tab.c"
    break;

  case 70: /* enum_declaration: "enum" "id" enum_body "semi"  */
#line 217 "syntax.y"
                                                                                {hashtbl_insert(htable,(yyvsp[-2].strval),create_info(SYM_TYPE, current_type),scope);}
#line 1935 "syntax.tab.c"
    break;

  case 72: /* id_list: id_list "comma" "id" initializer  */
#line 220 "syntax.y"
                                                                                {hashtbl_insert(htable,(yyvsp[-1].strval),NULL,scope);}
#line 1941 "syntax.tab.c"
    break;

  case 73: /* id_list: "id" initializer  */
#line 221 "syntax.y"
                                                                                {hashtbl_insert(htable,(yyvsp[-1].strval),NULL,scope);}
#line 1947 "syntax.tab.c"
    break;

  case 75: /* initializer: %empty  */
#line 224 "syntax.y"
                                             {;}
#line 1953 "syntax.tab.c"
    break;

  case 76: /* class_declaration: "class" "id" class_body "semi"  */
#line 226 "syntax.y"
                                                                                {hashtbl_insert(htable,(yyvsp[-2].strval),create_info(SYM_TYPE, current_type),scope);}
#line 1959 "syntax.tab.c"
    break;

  case 77: /* $@1: %empty  */
#line 227 "syntax.y"
                                   {scope++;}
#line 1965 "syntax.tab.c"
    break;

  case 78: /* class_body: parent $@1 "lbrace" members_methods "rbrace"  */
#line 227 "syntax.y"
                                                                                {hashtbl_get(htable, scope); scope--;}
#line 1971 "syntax.tab.c"
    break;

  case 79: /* parent: "colon" "id"  */
#line 228 "syntax.y"
                                                                                {hashtbl_insert(htable,(yyvsp[0].strval),NULL,scope);}
#line 1977 "syntax.tab.c"
    break;

  case 80: /* parent: %empty  */
#line 229 "syntax.y"
                                             {;}
#line 1983 "syntax.tab.c"
    break;

  case 86: /* access: %empty  */
#line 234 "syntax.y"
                                                                                                        { }
#line 1989 "syntax.tab.c"
    break;

  case 92: /* var_declaration: typename variabledefs error  */
#line 243 "syntax.y"
                                                                                {fprintf(stderr, " HINT: missing ';'"); yyerrok;}
#line 1995 "syntax.tab.c"
    break;

  case 95: /* variabledef: listspec "id" dims  */
#line 249 "syntax.y"
                                                                                {hashtbl_insert(htable, (yyvsp[-1].strval), create_info(SYM_VAR, current_type), scope);}
#line 2001 "syntax.tab.c"
    break;

  case 97: /* $@2: %empty  */
#line 253 "syntax.y"
                            {scope++;}
#line 2007 "syntax.tab.c"
    break;

  case 98: /* union_body: $@2 "lbrace" fields "rbrace"  */
#line 253 "syntax.y"
                                                                                {hashtbl_get(htable, scope); scope--;}
#line 2013 "syntax.tab.c"
    break;

  case 103: /* short_func_declaration: short_par_func_header "semi"  */
#line 262 "syntax.y"
                                                                                {hashtbl_get(htable, scope); scope--;}
#line 2019 "syntax.tab.c"
    break;

  case 104: /* short_func_declaration: nopar_func_header "semi"  */
#line 263 "syntax.y"
                                                                                {hashtbl_get(htable, scope); scope--;}
#line 2025 "syntax.tab.c"
    break;

  case 106: /* func_header_start: typename listspec "id"  */
#line 269 "syntax.y"
                                                                                {hashtbl_insert(htable,(yyvsp[0].strval),create_info(SYM_FUNC, current_type),scope); scope++; }
#line 2031 "syntax.tab.c"
    break;

  case 112: /* union_declaration: "union" "id" union_body "semi"  */
#line 279 "syntax.y"
                                                                                {hashtbl_insert(htable,(yyvsp[-2].strval),create_info(SYM_TYPE, current_type),scope);}
#line 2037 "syntax.tab.c"
    break;

  case 114: /* global_var_declaration: typename init_variabledefs error  */
#line 282 "syntax.y"
                                                                                {fprintf(stderr, " HINT: missing ';' \n"); yyerrok;}
#line 2043 "syntax.tab.c"
    break;

  case 120: /* full_func_declaration: full_par_func_header "lbrace" decl_statements "rbrace"  */
#line 293 "syntax.y"
                                                                                                        {hashtbl_get(htable, scope); scope--;}
#line 2049 "syntax.tab.c"
    break;

  case 121: /* full_func_declaration: nopar_class_func_header "lbrace" decl_statements "rbrace"  */
#line 294 "syntax.y"
                                                                                                        {hashtbl_get(htable, scope); scope--;}
#line 2055 "syntax.tab.c"
    break;

  case 122: /* full_func_declaration: nopar_func_header "lbrace" decl_statements "rbrace"  */
#line 295 "syntax.y"
                                                                                                        {hashtbl_get(htable, scope); scope--;}
#line 2061 "syntax.tab.c"
    break;

  case 125: /* class_func_header_start: typename listspec func_class "id"  */
#line 300 "syntax.y"
                                                                                {hashtbl_insert(htable,(yyvsp[0].strval),NULL,scope); scope++; }
#line 2067 "syntax.tab.c"
    break;

  case 130: /* pass_variabledef: "refer" "id"  */
#line 308 "syntax.y"
                                                                                {hashtbl_insert(htable,(yyvsp[0].strval),NULL,scope);}
#line 2073 "syntax.tab.c"
    break;

  case 135: /* decl_statements: %empty  */
#line 315 "syntax.y"
                                             {;}
#line 2079 "syntax.tab.c"
    break;

  case 139: /* decltype: %empty  */
#line 320 "syntax.y"
                                                      {;}
#line 2085 "syntax.tab.c"
    break;

  case 142: /* statements: statements error "semi"  */
#line 323 "syntax.y"
                                                                                { fprintf(stderr, " HINT:  error in statement - skipping until ';'"); yyerrok; }
#line 2091 "syntax.tab.c"
    break;

  case 156: /* if_tail: %empty  */
#line 339 "syntax.y"
                                                                     {;}
#line 2097 "syntax.tab.c"
    break;

  case 160: /* optexpr: %empty  */
#line 344 "syntax.y"
                                             {;}
#line 2103 "syntax.tab.c"
    break;

  case 170: /* $@3: %empty  */
#line 358 "syntax.y"
                                     {scope++;}
#line 2109 "syntax.tab.c"
    break;

  case 171: /* comp_statement: "lbrace" $@3 decl_statements "rbrace"  */
#line 358 "syntax.y"
                                                                            {hashtbl_get(htable, scope); scope--;}
#line 2115 "syntax.tab.c"
    break;

  case 172: /* main_function: main_header "lbrace" decl_statements "rbrace"  */
#line 359 "syntax.y"
                                                                            {hashtbl_get(htable, scope); scope--;}
#line 2121 "syntax.tab.c"
    break;

  case 173: /* main_header: "int" "main" "lparen" "rparen"  */
#line 360 "syntax.y"
                                                                            {scope++;}
#line 2127 "syntax.tab.c"
    break;

  case 174: /* main_header: error "main" "lparen" "rparen"  */
#line 361 "syntax.y"
                                                                            {fprintf(stderr, " HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; scope++;}
#line 2133 "syntax.tab.c"
    break;

  case 175: /* main_header: "int" error "lparen" "rparen"  */
#line 362 "syntax.y"
                                                                            {fprintf(stderr, " HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; scope++;}
#line 2139 "syntax.tab.c"
    break;

  case 176: /* main_header: "int" "main" error "rparen"  */
#line 363 "syntax.y"
                                                                            {fprintf(stderr, " HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; scope++;}
#line 2145 "syntax.tab.c"
    break;

  case 177: /* main_header: "int" "main" "lparen" error  */
#line 364 "syntax.y"
                                                                            {fprintf(stderr, " HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; scope++;}
#line 2151 "syntax.tab.c"
    break;


#line 2155 "syntax.tab.c"

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

#line 366 "syntax.y"




int main(int argc, char *argv[]){
    int token;

    if(!(htable = hashtbl_create(10, NULL))) {
        puts("Error initializing Hashtable!");
        return(EXIT_FAILURE);
    }

    if(argc > 1){
        yyin = fopen(argv[1],"r");
        if(yyin==NULL){
            perror("error opening file");
            return T_ERROR;
        }
    }
    else{
        printf("No input file provided.\n");
        return T_ERROR;
    }


    yyparse();

    fclose(yyin);
    hashtbl_get(htable,0);
    hashtbl_get(htable,1);
    hashtbl_destroy(htable);
    return 0;
}

void yyerror (char *str){
    yyerrorno++;
    printf("ERROR: [line: %d]: %s\n", yylineno, str);
    if (yyerrorno >= 5) {
        printf("MAX ERRORS FOUND\n");
        exit(EXIT_FAILURE);   // or EXIT_FAILURE instead of T_ERROR
    }
}
