%code requires {
    #include "types.h"
    #include "symbol.h"
    #include "ast.h"
    #include "astinfo.h"
}

%{
    #include <stdio.h>
    #include <stdlib.h>

    #include "settings.h"
    #include "symbolTable.h" 
    #include "semantics.h"

    extern FILE *yyin;
    extern int yylex();
    extern int yylineno;
    void yyerror(const char *s);
    int yyerrorno = 0;

    static Type *current_type = NULL;
    static Type *current_function_type = NULL;
    static Type *current_enum_type = NULL;
    static int current_enum_value = 0;
    static EnumBuilder *current_enum_builder = NULL;

    #define YYERROR_BUFFER_SIZE 256
    #define YYERROR_FMT(...) \
        do { \
            char _yyerrbuf[YYERROR_BUFFER_SIZE]; \
            snprintf(_yyerrbuf, sizeof(_yyerrbuf), __VA_ARGS__); \
            yyerror(_yyerrbuf); \
        } while (0)
%}

%define parse.error verbose

%union {
    int      intval;
    float    floatval;
    char    *strval;
    char     charval;
    Type    *type;
    ExprInfo expr;    // for expressions
    StmtInfo stmt;    // for statements/blocks
}


%token T_EOF    0           "eof"
%token T_TYPEDEF            "typedef"
%token T_CHAR               "char"
%token T_INT                "int"
%token T_FLOAT              "float"
%token T_STRING             "string"
%token T_CONST              "const"
%token T_CLASS              "class"
%token T_PRIVATE            "private"
%token T_PROTECTED          "protected"
%token T_PUBLIC             "public"
%token T_VOID               "void"
%token T_STATIC             "static"
%token T_UNION              "union"
%token T_ENUM               "enum"
%token T_LIST               "list"
%token T_CONTINUE           "continue"
%token T_BREAK              "break"
%token T_IF                 "if"
%token T_ELSE               "else"
%token T_WHILE              "while"
%token T_FOR                "for"
%token T_RETURN             "return"
%token T_LENGTH             "length"
%token T_CIN                "cin"
%token T_COUT               "cout"
%token T_MAIN               "main"
%token T_THIS               "this"
%token <strval>     T_ID                 "id"
%token T_NUM                "num"
%token <intval>     T_ICONST            "iconst"
%token T_UNKNOWN            "unknown"
%token <floatval>   T_FCONST            "fconst"
%token <strval>     T_SCONST            "sconst"
%token <charval>    T_CCONST            "cconst"
%token <strval>     T_OROP               "orop"
%token <strval>     T_ANDOP              "andop"
%token <strval>     T_EQUOP              "equop"
%token <strval>     T_RELOP              "relop"
%token <strval>     T_ADDOP              "addop"
%token <strval>     T_MULOP              "mulop"
%token <strval>     T_NOTOP              "notop"
%token <strval>     T_INCDEC             "incdec"
%token T_SIZEOP             "sizeop"
%token T_LISTFUNC           "listfunc"
%token T_LPAREN             "lparen"
%token T_RPAREN             "rparen"
%token T_SEMI               "semi"
%token T_DOT                "dot"
%token T_COMMA              "comma"
%token T_ASSIGN             "assign"
%token T_COLON              "colon"
%token T_LBRACK             "lbrack"
%token T_RBRACK             "rbrack"
%token T_REFER              "refer"
%token T_LBRACE             "lbrace"
%token T_RBRACE             "rbrace"
%token T_METH               "meth"
%token T_INP                "inp"
%token T_OUT                "out"
%token T_ERROR              "error"

// %type <strval> program global_declarations global_declaration typedef_declaration typename standard_type listspec dims dim const_declaration constdefs
// %type <strval> init_value expression variable general_expression assignment expression_list constant listexpression init_values enum_declaration
// %type <strval> enum_body id_list initializer class_declaration class_body parent members_methods access member_or_method member var_declaration
// %type <strval> variabledefs variabledef anonymous_union union_body fields field method short_func_declaration short_par_func_header func_header_start
// %type <strval> parameter_types pass_list_dims nopar_func_header union_declaration global_var_declaration init_variabledefs init_variabledef func_declaration
// %type <strval> full_func_declaration full_par_func_header class_func_header_start func_class parameter_list pass_variabledef nopar_class_func_header
// %type <strval> decl_statements declarations decltype statements statement expression_statement if_statement if_tail while_statement for_statement optexpr
// %type <strval> return_statement io_statement in_list in_item out_list out_item comp_statement main_function main_header
%type <type> typename standard_type list_elements type_with_list dims dim 
%type <intval> listspec initializer

%type <expr> expression general_expression assignment variable constant listexpression expression_list optexpr
%type <stmt> statement if_statement if_tail while_statement for_statement return_statement comp_statement io_statement expression_statement 
%type <stmt> statements decl_statements main_function program 
 

%left T_COMMA
%right T_ASSIGN
%left T_OROP
%left T_ANDOP
%left T_EQUOP
%left T_RELOP
%left T_ADDOP
%left T_MULOP
%right T_INCDEC T_NOTOP T_REFER T_SIZEOP PREFIX
%left T_LPAREN T_RPAREN T_LBRACE T_RBRACE POSTFIX

%nonassoc T_METH
%nonassoc LOWER_THAN_ELSE
%nonassoc T_ELSE


%%

program :                   global_declarations main_function                   {
                                                                                    extern ASTNode *ast_root;
                                                                                    ast_root = $2.node;
                                                                                }             
                            ;
global_declarations :       global_declarations global_declaration
                            | %empty         {;}
                            ;
global_declaration :        typedef_declaration
                            | const_declaration
                            | enum_declaration
                            | class_declaration
                            | union_declaration
                            | global_var_declaration
                            | func_declaration
                            /* | error T_SEMI                                      {yyerror(" HINT: syntax error in global declaration\n"); yyerrok;} */
                            /* | error T_RBRACE                                    {yyerror(" HINT: in global declaration\n"); yyerrok; } */
                            ;
typedef_declaration :       T_TYPEDEF typename listspec T_ID dims T_SEMI        {
                                                                                    /* αγνοούμε προς το παρόν listspec/dims για σύνθετους, κρατάμε base type */
                                                                                    if (!symtab_insert($4, SYM_TYPE, $2)) {
                                                                                        YYERROR_FMT("Redeclaration of typedef '%s'", $4);
                                                                                    }
                                                                                }
                            ;
type_with_list:             typename listspec                                   {
                                                                                    Type *t = $1;
                                                                                    if ($2) {
                                                                                       $$ = sem_make_list_type(t, yylineno);
                                                                                    } else {
                                                                                        $$ = t;
                                                                                    }
                                                                                    current_type = $$;
                                                                                    }
                            ;

typename :                  standard_type
                            | T_ID                                              {Symbol *s = symtab_lookup($1);
                                                                                    if (!s || s->kind != SYM_TYPE || !s->type) {
                                                                                        YYERROR_FMT("Unknown type '%s'", $1);
                                                                                        $$ = type_error;
                                                                                    } else {
                                                                                        $$ = s->type;
                                                                                    }
                                                                                }
                            ;
standard_type :             T_CHAR                                              {$$ = type_char;} 
                            | T_INT                                             {$$ = type_int;}
                            | T_FLOAT                                           {$$ = type_float;}
                            | T_STRING                                          {$$ = type_string;}   
                            | T_VOID                                            {$$ = type_void;}
                            ;           
listspec :                  T_LIST                                              {$$ = 1;} 
                            | %empty                                            {$$ = 0;}
                            ;
dims :                      dims dim                                            { $$ = attach_nested_array($1, $2); }
                            | %empty                                            { $$ = NULL; } 
                            ;
dim :                       T_LBRACK T_ICONST T_RBRACK                          { $$ = make_array_type(NULL, $2); }
                            | T_LBRACK T_RBRACK                                 { $$ = make_array_type(NULL, 0); }
                            ;
const_declaration :         T_CONST typename { current_type = $2; } constdefs T_SEMI
                            ;
constdefs :                 constdefs T_COMMA constdef
                            | constdef
                            ;
constdef :                  T_ID dims T_ASSIGN init_value                       {if (!current_type) current_type = type_error;
                                                                                    if (!symtab_insert($1, SYM_CONST, current_type)) {
                                                                                        YYERROR_FMT("Redeclaration of const '%s'", $1);
                                                                                    }
                                                                                }
                            ;
init_value :                expression
                            | T_LBRACE init_values T_RBRACE          
                            ;
expression
                            : expression T_OROP expression
                                                                                {
                                                                                    Type *t = sem_binary_logical($1.type, $3.type, yylineno);
                                                                                    ASTOp op = OP_OR;
                                                                                    $$.node = ast_make_binop(op, $1.node, $3.node, t, yylineno);
                                                                                    $$.type = t;
                                                                                }
                            | expression T_ANDOP expression
                                                                                {
                                                                                    Type *t = sem_binary_logical($1.type, $3.type, yylineno);
                                                                                    ASTOp op = OP_AND;
                                                                                    $$.node = ast_make_binop(op, $1.node, $3.node, t, yylineno);
                                                                                    $$.type = t;
                                                                                }
                            | expression T_EQUOP expression
                                                                                {
                                                                                    Type *t = sem_binary_equality($1.type, $3.type, yylineno);
                                                                                    ASTOp op = (strcmp($2, "==") == 0) ? OP_EQ : OP_NE;
                                                                                    $$.node = ast_make_binop(op, $1.node, $3.node, t, yylineno);
                                                                                    $$.type = t;
                                                                                }
                            | expression T_RELOP expression
                                                                                {
                                                                                    Type *t = sem_binary_relational($1.type, $3.type, yylineno);
                                                                                    ASTOp op;
                                                                                    if      (strcmp($2, "<")  == 0) op = OP_LT;
                                                                                    else if (strcmp($2, "<=") == 0) op = OP_LE;
                                                                                    else if (strcmp($2, ">")  == 0) op = OP_GT;
                                                                                    else                            op = OP_GE;
                                                                                    $$.node = ast_make_binop(op, $1.node, $3.node, t, yylineno);
                                                                                    $$.type = t;
                                                                                }
                            | expression T_ADDOP expression
                                                                                {
                                                                                    Type *t = sem_binary_arith($1.type, $3.type, yylineno);
                                                                                    ASTOp op = (strcmp($2, "+") == 0) ? OP_ADD : OP_SUB;
                                                                                    $$.node = ast_make_binop(op, $1.node, $3.node, t, yylineno);
                                                                                    $$.type = t;
                                                                                }
                            | expression T_MULOP expression
                                                                                {
                                                                                    Type *t = sem_binary_arith($1.type, $3.type, yylineno);
                                                                                    ASTOp op;
                                                                                    if      (strcmp($2, "*") == 0) op = OP_MUL;
                                                                                    else if (strcmp($2, "/") == 0) op = OP_DIV;
                                                                                    else                           op = OP_MOD;
                                                                                    $$.node = ast_make_binop(op, $1.node, $3.node, t, yylineno);
                                                                                    $$.type = t;
                                                                                }
                            | T_NOTOP expression
                                                                                {
                                                                                    Type *t = sem_unary_not($2.type, yylineno);
                                                                                    ASTOp op = OP_NOT;
                                                                                    $$.node = ast_make_unop(op, $2.node, t, yylineno);
                                                                                    $$.type = t;
                                                                                }
                            | T_ADDOP expression
                                                                                {
                                                                                    Type *t = sem_unary_sign($2.type, yylineno);
                                                                                    ASTOp op = (strcmp($1, "+") == 0) ? OP_ADD : OP_SUB;
                                                                                    $$.node = ast_make_unop(op, $2.node, t, yylineno);
                                                                                    $$.type = t;
                                                                                }
                            | T_SIZEOP expression
                                                                                {
                                                                                    $$.type = type_int;
                                                                                    $$.node = ast_make_unop(OP_SIZEOF, $2.node, type_int, yylineno);
                                                                                }
                            | T_INCDEC variable %prec PREFIX
                                                                                {
                                                                                    Type *t = sem_unary_incdec($2.type, yylineno);
                                                                                    ASTOp op = (strcmp($1, "++") == 0) ? OP_PRE_INC : OP_PRE_DEC;
                                                                                    $$.type = t;
                                                                                    $$.node = ast_make_unop(op, $2.node, t, yylineno);
                                                                                }
                            | variable T_INCDEC %prec POSTFIX
                                                                                {
                                                                                    Type *t = sem_unary_incdec($1.type, yylineno);
                                                                                    ASTOp op = (strcmp($2, "++") == 0) ? OP_POST_INC : OP_POST_DEC;
                                                                                    $$.type = t;
                                                                                    $$.node = ast_make_unop(op, $1.node, t, yylineno);
                                                                                }
                            | variable
                                                                                {
                                                                                    $$.type = $1.type;
                                                                                    $$.node = $1.node;
                                                                                }
                            | variable T_LPAREN expression_list T_RPAREN
                                                                                {
                                                                                    Type *t = sem_call_check($1.node, $3.node, yylineno);
                                                                                    $$.type = t;
                                                                                    $$.node = ast_make_call($1.node, $3.node, t, yylineno);
                                                                                }
                            | T_LENGTH T_LPAREN general_expression T_RPAREN
                                                                                {
                                                                                    Type *t = sem_length($3.type, yylineno);
                                                                                    $$.type = t;
                                                                                    $$.node = ast_make_unop(OP_LENGTH, $3.node, t, yylineno);
                                                                                }
                            | constant
                                                                                {
                                                                                    $$.type = $1.type;
                                                                                    $$.node = $1.node;
                                                                                }
                            | T_LPAREN general_expression T_RPAREN
                                                                                {
                                                                                    $$.type = $2.type;
                                                                                    $$.node = $2.node;
                                                                                }
                            | T_LPAREN standard_type T_RPAREN
                                                                                {
                                                                                    /* cast expression TODO: for now just type info, no AST */
                                                                                    $$.type = $2;
                                                                                    $$.node = NULL;
                                                                                }
                            | listexpression
                                                                                {
                                                                                    $$.type = $1.type;
                                                                                    $$.node = $1.node;
                                                                                }
                            ;

variable
                            : variable T_LBRACK general_expression T_RBRACK
                                                                                {
                                                                                    Type *t = sem_index($1.type, $3.type, yylineno);
                                                                                    $$.type = t;
                                                                                    $$.node = ast_make_index($1.node, $3.node, t, yylineno);
                                                                                }
                            | variable T_DOT T_ID
                                                                                {
                                                                                    if (is_enum($1.type->kind)) {
                                                                                        Type *t = sem_use_enum_constant($1.type, $3, yylineno);
                                                                                        $$.type = t;
                                                                                        $$.node = ast_make_var($3, t, yylineno);
                                                                                    } else {
                                                                                        $$.type = type_error;
                                                                                        $$.node = NULL;
                                                                                    }
                                                                                }
                            | T_LISTFUNC T_LPAREN general_expression T_RPAREN
                                                                                {
                                                                                    /* TODO: listfunc semantics */
                                                                                    $$.type = type_error;
                                                                                    $$.node = NULL;
                                                                                }
                            | decltype T_ID
                                                                                {
                                                                                    Type *t = sem_use_variable($2, yylineno);
                                                                                    $$.type = t;
                                                                                    $$.node = ast_make_var($2, t, yylineno);
                                                                                }
                            | T_THIS
                                                                                {
                                                                                    $$.type = type_error;  /* placeholder */
                                                                                    $$.node = NULL;
                                                                                }
                            ;
general_expression
                            : general_expression T_COMMA general_expression     { $$ = $3; }
                            | assignment                                        { $$ = $1; }
                            ;
assignment :                variable T_ASSIGN assignment                        {
                                                                                    Type *t = sem_check_assignment($1.type, $3.type, yylineno);
                                                                                    $$.type = t;
                                                                                    $$.node = ast_make_assign($1.node, $3.node, t, yylineno);
                                                                                }
                            | expression                                        {$$ = $1;}
                            ;
expression_list             :general_expression                                 {$$ = $1;}
                            | %empty                                            {$$.type = type_void; $$.node = NULL;}
                            ;
constant :                  T_CCONST                                            { 
                                                                                    Type *t = type_char;
                                                                                    $$.node = ast_make_const_char($1, yylineno);
                                                                                    $$.type = t;
                                                                                }
                            | T_ICONST                                          {
                                                                                    Type *t = type_int;
                                                                                    $$.node = ast_make_const_int($1, yylineno);
                                                                                    $$.type = t;
                                                                                }
                            | T_FCONST                                          { 
                                                                                    Type *t = type_float;
                                                                                    $$.node = ast_make_const_float($1, yylineno);
                                                                                    $$.type = t;
                                                                                }
                            | T_SCONST                                          { 
                                                                                    Type *t = type_string;
                                                                                    $$.node = ast_make_const_string($1, yylineno);
                                                                                    $$.type = t;
                                                                                }
                            ;

listexpression :            T_LBRACK list_elements T_RBRACK                     {
                                                                                    Type *t   = sem_make_list_type($2, yylineno);
                                                                                    $$.type   = t;
                                                                                    $$.node   = NULL;  //TODO μελλοντικά AST_LIST node
                                                                                }

list_elements:              list_elements T_COMMA assignment                    { $$ = sem_find_list_element_type($1, $3.type, yylineno); }
                            | assignment                                        { $$ = $1.type; }
                            ;
init_values :               init_values T_COMMA init_value
                            | init_value
                            ;
enum_declaration :          T_ENUM T_ID                                        {current_enum_builder = start_enum($2); // δική σου συνάρτηση που επιστρέφει builder
                                                                                    if (!current_enum_builder) {
                                                                                        YYERROR_FMT("Redeclaration of enum '%s'", $2);
                                                                                    }
                                                                                    //Include enum type on global scope
                                                                                    Symbol *etype = symtab_insert($2, SYM_TYPE, current_enum_builder->enum_type);
                                                                                    if (!etype) {
                                                                                        YYERROR_FMT("Redeclaration of enum type '%s'", $2);
                                                                                    }
                                                                                }
                            enum_body T_SEMI
                                                                                {
                                                                                    /* τελειώσαμε με το enum */
                                                                                    Type *t = end_enum(current_enum_builder); // επιστρέφει Type*
                                                                                    current_enum_builder = NULL;
                                                                                    current_enum_type = t; //Hold on to current type for parser
                                                                                }
                            ;
enum_body :                 T_LBRACE id_list T_RBRACE;                           
id_list :                   id_list T_COMMA T_ID initializer                    {
                                                                                    int val = ($4 == -1) ? current_enum_builder->next_value : $4;
                                                                                    if (!add_enum_constant(current_enum_builder, $3, val, $4 != -1)) {
                                                                                        YYERROR_FMT("Redeclaration of enum constant '%s'", $3);
                                                                                    }
                                                                                }
                            | T_ID initializer                                  { 
                                                                                    int val = ($2 == -1) ? current_enum_builder->next_value : $2;
                                                                                    if (!add_enum_constant(current_enum_builder, $1, val, $2 != -1)) {
                                                                                        YYERROR_FMT("Redeclaration of enum constant '%s'", $1);
                                                                                    }
                                                                                }
                            ;
initializer :               T_ASSIGN T_ICONST                                   {$$ = $2;} /* explicit integer initializer */
                            | %empty                                            {$$ = -1;} /*-1 = no initializer*/
                            ;
class_declaration :         T_CLASS T_ID class_body T_SEMI                      {Type *t = make_simple_type(TYPE_CLASS);
                                                                                    if (!symtab_insert($2, SYM_TYPE, t)) {
                                                                                        YYERROR_FMT("Redeclaration of class '%s'", $2);
                                                                                    }
                                                                                }
                            ;
class_body :                parent                                              {symtab_enter_scope();} 
                            T_LBRACE members_methods T_RBRACE                   { symtab_leave_scope();}
                            ;

parent :                    T_COLON T_ID                                        {Symbol *base = symtab_lookup($2);
                                                                                    if (!base || base->kind != SYM_TYPE) {
                                                                                        YYERROR_FMT("Unknown base class '%s'", $2);
                                                                                    }
                                                                                }
                            | %empty                                            {;}    
                            ;                           
members_methods :           members_methods access member_or_method
                            | access member_or_method
                            ;
access :                    T_PRIVATE T_COLON | T_PROTECTED T_COLON | T_PUBLIC T_COLON | %empty         { };
member_or_method :          member
                            | method
                            ;
member :                    var_declaration
                            | anonymous_union
                            ;

var_declaration :           type_with_list variabledefs T_SEMI
                            ;

variabledefs :              variabledefs T_COMMA variabledef
                            | variabledef
                            ;

variabledef :               T_ID dims                                           {if (!current_type) current_type = type_error;
                                                                                    Type *t = current_type;
                                                                                    if ($2 != NULL)         // piankas
                                                                                        t = attach_array_to_base(current_type, $2);
                                                                                    if (!symtab_insert($1, SYM_VAR, t)) {
                                                                                        YYERROR_FMT("Redeclaration of '%s'", $1);
                                                                                    }
                                                                                }
                            ;

anonymous_union :           T_UNION union_body T_SEMI;

union_body :                {symtab_enter_scope();} T_LBRACE fields T_RBRACE                 { symtab_leave_scope();};

fields :                    fields field
                            | field
                            ;
field :                     var_declaration;

method :                    short_func_declaration;

short_func_declaration :    short_par_func_header T_SEMI                        { symtab_leave_scope();   current_function_type = NULL;}
                            | nopar_func_header T_SEMI                          { symtab_leave_scope();   current_function_type = NULL;}  
                            ;

short_par_func_header :     func_header_start T_LPAREN parameter_types T_RPAREN 
                            ;

func_header_start :         type_with_list T_ID                                 {
                                                                                    Type *ret = sem_check_function_return_type($1, yylineno);
                                                                                    Symbol *func =symtab_insert($2, SYM_FUNC, ret);
                                                                                    if (!func) {
                                                                                        YYERROR_FMT("Redeclaration of function '%s'", $2);
                                                                                    }
                                                                                    current_function_type = ret;
                                                                                    symtab_enter_scope();
                                                                                }
                            ;

parameter_types :           parameter_types T_COMMA typename pass_list_dims
                            | typename pass_list_dims
                            ;
pass_list_dims :            T_REFER
                            | listspec dims
                            ;
nopar_func_header :         func_header_start T_LPAREN T_RPAREN ; 

union_declaration :         T_UNION T_ID union_body T_SEMI                      {Type *t = make_simple_type(TYPE_UNION);
                                                                                    if (!symtab_insert($2, SYM_TYPE, t)) {
                                                                                        YYERROR_FMT("Redeclaration of union '%s'", $2);
                                                                                    }
                                                                                }
                            ;

global_var_declaration :    type_with_list init_variabledefs T_SEMI
                            /* |typename { current_type = $1; } init_variabledefs error                   {YYERROR_FMT(" HINT: missing ';' \n"); yyerrok;} */
                            ;

init_variabledefs :         init_variabledefs T_COMMA init_variabledef;
                            | init_variabledef
                            ;
init_variabledef :          variabledef initializer;

func_declaration :          short_func_declaration
                            | full_func_declaration;

full_func_declaration :     full_par_func_header T_LBRACE decl_statements T_RBRACE                      { symtab_leave_scope();   current_function_type = NULL;};
                            | nopar_class_func_header T_LBRACE decl_statements T_RBRACE                 { symtab_leave_scope();   current_function_type = NULL;};
                            | nopar_func_header T_LBRACE  decl_statements T_RBRACE                      { symtab_leave_scope();   current_function_type = NULL;};
                            ;
full_par_func_header :      class_func_header_start T_LPAREN parameter_list T_RPAREN
                            | func_header_start T_LPAREN parameter_list T_RPAREN
                            ;
class_func_header_start :   type_with_list func_class T_ID                      {Type *ret = $1;
                                                                                    if (!symtab_insert($3, SYM_FUNC, ret)) {
                                                                                        YYERROR_FMT("Redeclaration of method '%s'", $3);
                                                                                    }
                                                                                    current_function_type = ret;
                                                                                    symtab_enter_scope();
                                                                                }
                            ;
func_class :                T_ID T_METH                                         {Symbol *cls = symtab_lookup($1);
                                                                                    if (!cls || cls->kind != SYM_TYPE) {
                                                                                        YYERROR_FMT("Unknown class type '%s'", $1);
                                                                                    }
                                                                                }
                            ;
parameter_list :            parameter_list T_COMMA typename pass_variabledef
                            | typename pass_variabledef { current_type = $1; }
                            ;
pass_variabledef :          variabledef
                            | T_REFER T_ID                                      {if (!current_type) current_type = type_error;
                                                                                    if (!symtab_insert($2, SYM_VAR, current_type)) {
                                                                                        YYERROR_FMT("Redeclaration of parameter '%s'", $2);
                                                                                    }
                                                                                }
                            ;
nopar_class_func_header     : class_func_header_start T_LPAREN T_RPAREN ;

decl_statements :           declarations statements                             {$$.node = $2.node;}
                            | declarations                                      {$$.node = NULL; }
                            | statements                                        {$$.node = $1.node;}
                            | %empty         {;}
                            ;
declarations :              declarations decltype type_with_list  variabledefs T_SEMI
                            | decltype type_with_list variabledefs T_SEMI
                            ;
decltype :                  T_STATIC | %empty         {;};
statements :                statements statement                                {$$.node = $2.node;}
                            | statement                                         { $$ = $1; }
                            /* | statements error T_SEMI                           { YYERROR_FMT(" HINT:  error in statement - skipping until ';'"); yyerrok; } */
                            ;
statement :                 expression_statement                                             { $$ = $1; }
                            | if_statement                                                   { $$ = $1; }                                                         
                            | while_statement                                                { $$ = $1; }
                            | for_statement                                                  { $$ = $1; }
                            | return_statement                                               { $$ = $1; }
                            | io_statement                                                   { $$ = $1; }
                            | comp_statement                                                 { $$ = $1; }
                            | T_CONTINUE T_SEMI                                              {$$.node = NULL;}
                            | T_BREAK T_SEMI                                                 {$$.node = NULL;}
                            | T_SEMI                                                         {$$.node = NULL;}
                            ;
expression_statement :      general_expression T_SEMI                                        {$$.node = $1.node;};
if_statement :              T_IF T_LPAREN general_expression T_RPAREN statement if_tail    {
                                                                                                /* type-check condition */
                                                                                                sem_check_condition($3.type, yylineno);
                                                                                                ASTNode *ifn = ast_make_if($3.node,
                                                                                                                            $5.node,
                                                                                                                            $6.node,
                                                                                                                            yylineno);
                                                                                                $$.node = ifn;
                                                                                            } 
                            
                            ;
if_tail:                    T_ELSE statement                                                { $$.node = $2.node; }
                            | %empty          %prec LOWER_THAN_ELSE                         { $$.node = NULL; }
                            ;
while_statement :           T_WHILE T_LPAREN general_expression T_RPAREN statement          {
                                                                                                sem_check_condition($3.type, yylineno);
                                                                                                $$.node = ast_make_while($3.node, $5.node, yylineno);
                                                                                            }
                            
                            ;
for_statement :             T_FOR T_LPAREN optexpr T_SEMI optexpr T_SEMI general_expression T_RPAREN statement {
                                                                                                            sem_check_condition($5.type, yylineno);
                                                                                                            $$.node = ast_make_for($3.node, $5.node, $7.node, $9.node, yylineno);
                                                                                                        }
                            ;
optexpr :                   general_expression                                              {$$ = $1;}
                            | %empty                                                        { $$.type = type_void; $$.node = NULL; }
                            ;
return_statement :          T_RETURN optexpr T_SEMI                                         {
                                                                                                sem_check_return(current_function_type, $2.type, yylineno);
                                                                                                $$.node = ast_make_return($2.node, yylineno);
                                                                                            }
                            ;
io_statement :              T_CIN T_INP in_list T_SEMI                                      {//TODO: φτιάξε AST για cin
                                                                                                $$.node = NULL;
                                                                                            }
                            | T_COUT T_OUT out_list T_SEMI                                  {$$.node = NULL;}
                            ;
in_list :                   in_list T_INP in_item
                            | in_item
                            ;
in_item :                   variable;
out_list :                  out_list T_OUT out_item
                            | out_item
                            ;
out_item :                  general_expression;
comp_statement :            T_LBRACE {symtab_enter_scope();} decl_statements T_RBRACE    { symtab_leave_scope(); $$.node = $3.node;};
main_function :             main_header T_LBRACE decl_statements T_RBRACE   { symtab_leave_scope();  current_function_type = NULL; $$.node = $3.node;};
main_header :               T_INT T_MAIN  T_LPAREN T_RPAREN                 { current_function_type = type_int; symtab_enter_scope();}   
                            | error T_MAIN  T_LPAREN    T_RPAREN            {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; symtab_enter_scope();}
                            | T_INT error   T_LPAREN    T_RPAREN            {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; symtab_enter_scope();}
                            | T_INT T_MAIN  error       T_RPAREN            {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; symtab_enter_scope();}
                            | T_INT T_MAIN  T_LPAREN    error               {YYERROR_FMT(" HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; symtab_enter_scope();}
                            ;
%%

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

    extern ASTNode *ast_root;
    if (ast_root) {
        FILE *f = fopen("ast.dot", "w");
        if (!f) {
            perror("ast.dot");
        } else {
            ast_print(ast_root, f);
            fclose(f);
            printf("AST written to ast.dot\n");
            system("dot -Tpdf ast.dot -o ast.pdf");
        }
    } else {
        printf("No AST (parse errors?)\n");
    }

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
