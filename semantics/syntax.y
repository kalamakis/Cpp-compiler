%{
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

    
%}

%define parse.error verbose

%union {
    int intval;
    float floatval;
    char *strval;
    char charval;

    TypeKind type;
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
%token T_OROP               "orop"
%token T_ANDOP              "andop"
%token T_EQUOP              "equop"
%token T_RELOP              "relop"
%token T_ADDOP              "addop"
%token T_MULOP              "mulop"
%token T_NOTOP              "notop"
%token T_INCDEC             "incdec"
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
 
%type <type> typename standard_type


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

program :                   global_declarations main_function                   {hashtbl_get(htable,scope);}
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
                            | error T_SEMI                                      {fprintf(stderr, " HINT: syntax error in global declaration\n"); yyerrok;}
                            | error T_RBRACE                                    {fprintf(stderr, " HINT: in global declaration\n"); yyerrok; }
                            ;
typedef_declaration :       T_TYPEDEF typename listspec T_ID dims T_SEMI        {hashtbl_insert(htable,$4,create_info(SYM_TYPE, current_type),scope);}
                            ;
typename :                  standard_type                                       { $$ = $1; current_type=$1; }
                            | T_ID                                              {
                                                                                    SymbolInfo *info = hashtbl_lookup(htable, $1, scope); /* or your lookup */ ///ΑΝ ΔΕΝ ΕΙΝΑΙ ΣΤΑΝΤΑΡ ΤΥΠΟΣ ΕΛΕΓΧΕΙ ΑΝΑ 
                                                                                    if (!info || info->kind != SYM_TYPE) {
                                                                                        fprintf(stderr,
                                                                                                "ERROR: [line: %d]: '%s' is not a type name\n",
                                                                                                yylineno, $1);
                                                                                        $$ = TYPE_ERROR;
                                                                                        current_type = TYPE_ERROR;
                                                                                    } else {
                                                                                        $$ = info->type;  /* e.g. TYPE_CLASS, TYPE_ENUM, TYPE_TYPEDEF... */
                                                                                        current_type = info->type;
                                                                                    }
                                                                                }
                            ;
standard_type :             T_INT    { $$ = TYPE_INT; }
                            | T_FLOAT  { $$ = TYPE_FLOAT; }
                            | T_CHAR   { $$ = TYPE_CHAR; }
                            | T_STRING { $$ = TYPE_STRING; }
                            | T_VOID   { $$ = TYPE_VOID; }
                            ;
                                     
listspec :                  T_LIST | %empty         {;}
                            ;
dims :                      dims dim
                            | %empty         {;}
                            ;
dim :                       T_LBRACK T_ICONST T_RBRACK | T_LBRACK T_RBRACK
                            ;
const_declaration :         T_CONST typename constdefs T_SEMI
                            ;
constdefs :                 constdefs T_COMMA constdef
                            | constdef
                            ;
constdef :                  T_ID dims T_ASSIGN init_value                       {hashtbl_insert(htable,$1,NULL,scope);};
init_value :                expression
                            | T_LBRACE init_values T_RBRACE          
                            ;
expression :                expression T_OROP expression
                            | expression T_ANDOP expression
                            | expression T_EQUOP expression
                            | expression T_RELOP expression
                            | expression T_ADDOP expression
                            | expression T_MULOP expression
                            | T_NOTOP expression
                            | T_ADDOP expression
                            | T_SIZEOP expression
                            | T_INCDEC variable %prec PREFIX
                            | variable T_INCDEC %prec POSTFIX
                            | variable
                            | variable T_LPAREN expression_list T_RPAREN
                            | T_LENGTH T_LPAREN general_expression T_RPAREN
                            | constant
                            | T_LPAREN general_expression T_RPAREN
                            | T_LPAREN standard_type T_RPAREN
                            | listexpression
                            ;
variable :                  variable T_LBRACK general_expression T_RBRACK
                            | variable T_DOT T_ID                               {hashtbl_insert(htable,$3,NULL,scope);}
                            | T_LISTFUNC T_LPAREN general_expression T_RPAREN
                            | decltype T_ID                                     {hashtbl_insert(htable,$2,NULL,scope);}
                            | T_THIS
                            ;
general_expression :        general_expression T_COMMA general_expression
                            | assignment
                            ;
assignment :                variable T_ASSIGN assignment
                            | expression
                            ;
expression_list :           general_expression
                            | %empty         {;}
                            ;
constant :                  T_CCONST | T_ICONST | T_FCONST | T_SCONST;
listexpression :            T_LBRACK expression_list T_RBRACK;
init_values :               init_values T_COMMA init_value
                            | init_value
enum_declaration :          T_ENUM T_ID enum_body T_SEMI                        {hashtbl_insert(htable,$2,create_info(SYM_TYPE, current_type),scope);}
                            ;
enum_body :                 T_LBRACE id_list T_RBRACE                           
id_list :                   id_list T_COMMA T_ID initializer                    {hashtbl_insert(htable,$3,NULL,scope);}
                            | T_ID initializer                                  {hashtbl_insert(htable,$1,NULL,scope);}
                            ;
initializer :               T_ASSIGN init_value
                            | %empty         {;}
                            ;
class_declaration :         T_CLASS T_ID class_body T_SEMI                      {hashtbl_insert(htable,$2,create_info(SYM_TYPE, current_type),scope);};
class_body :                parent {scope++;} T_LBRACE members_methods T_RBRACE {hashtbl_get(htable, scope); scope--;};
parent :                    T_COLON T_ID                                        {hashtbl_insert(htable,$2,NULL,scope);}
                            | %empty         {;}    
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

var_declaration :           typename variabledefs T_SEMI
                            | typename variabledefs error                       {fprintf(stderr, " HINT: missing ';'"); yyerrok;};

variabledefs :              variabledefs T_COMMA variabledef
                            | variabledef
                            ;

variabledef :               listspec T_ID dims                                  {hashtbl_insert(htable, $2, create_info(SYM_VAR, current_type), scope);};

anonymous_union :           T_UNION union_body T_SEMI;

union_body :                {scope++;} T_LBRACE fields T_RBRACE                 {hashtbl_get(htable, scope); scope--;};

fields :                    fields field
                            | field
                            ;
field :                     var_declaration;

method :                    short_func_declaration;

short_func_declaration :    short_par_func_header T_SEMI                        {hashtbl_get(htable, scope); scope--;}
                            | nopar_func_header T_SEMI                          {hashtbl_get(htable, scope); scope--;}  
                            ;

short_par_func_header :     func_header_start T_LPAREN parameter_types T_RPAREN 
                            ;

func_header_start :         typename listspec T_ID                              {hashtbl_insert(htable,$3,create_info(SYM_FUNC, current_type),scope); scope++; };

parameter_types :           parameter_types T_COMMA typename pass_list_dims
                            | typename pass_list_dims
                            ;
pass_list_dims :            T_REFER
                            | listspec dims
                            ;
nopar_func_header :         func_header_start T_LPAREN T_RPAREN ; 

union_declaration :         T_UNION T_ID union_body T_SEMI                      {hashtbl_insert(htable,$2,create_info(SYM_TYPE, current_type),scope);};

global_var_declaration :    typename init_variabledefs T_SEMI
                            |typename init_variabledefs error                   {fprintf(stderr, " HINT: missing ';' \n"); yyerrok;}
                            ;

init_variabledefs :         init_variabledefs T_COMMA init_variabledef;
                            | init_variabledef
                            ;
init_variabledef :          variabledef initializer;

func_declaration :          short_func_declaration
                            | full_func_declaration;

full_func_declaration :     full_par_func_header T_LBRACE decl_statements T_RBRACE                      {hashtbl_get(htable, scope); scope--;};
                            | nopar_class_func_header T_LBRACE decl_statements T_RBRACE                 {hashtbl_get(htable, scope); scope--;};
                            | nopar_func_header T_LBRACE  decl_statements T_RBRACE                      {hashtbl_get(htable, scope); scope--;};
                            ;
full_par_func_header :      class_func_header_start T_LPAREN parameter_list T_RPAREN
                            | func_header_start T_LPAREN parameter_list T_RPAREN
                            ;
class_func_header_start :   typename listspec func_class T_ID                   {hashtbl_insert(htable,$4,NULL,scope); scope++; }; // edw prepei na doume ti skata ginetai me tis classes kai ta methodes kai na prosthesoume analoga ston pinaka

func_class :                T_ID T_METH                                         ;//{hashtbl_insert(htable,$1,NULL,scope);};

parameter_list :            parameter_list T_COMMA typename pass_variabledef
                            | typename pass_variabledef
                            ;
pass_variabledef :          variabledef
                            | T_REFER T_ID                                      {hashtbl_insert(htable,$2,NULL,scope);}
                            ;
nopar_class_func_header     : class_func_header_start T_LPAREN T_RPAREN ;

decl_statements :           declarations statements
                            | declarations
                            | statements
                            | %empty         {;}
                            ;
declarations :              declarations decltype typename variabledefs T_SEMI
                            | decltype typename variabledefs T_SEMI
                            ;
decltype :                  T_STATIC | %empty         {;};
statements :                statements statement
                            | statement
                            | statements error T_SEMI                           { fprintf(stderr, " HINT:  error in statement - skipping until ';'"); yyerrok; }
                            ;
statement :                 expression_statement
                            | if_statement
                            | while_statement
                            | for_statement
                            | return_statement
                            | io_statement
                            | comp_statement
                            | T_CONTINUE T_SEMI
                            | T_BREAK T_SEMI
                            | T_SEMI
                            ;
expression_statement :      general_expression T_SEMI;
if_statement :              T_IF T_LPAREN general_expression T_RPAREN statement if_tail;
if_tail:                    T_ELSE statement
                            | %empty          %prec LOWER_THAN_ELSE  {;}
                            ;
while_statement :           T_WHILE T_LPAREN general_expression T_RPAREN statement;
for_statement :             T_FOR T_LPAREN optexpr T_SEMI optexpr T_SEMI optexpr T_RPAREN statement;
optexpr :                   general_expression
                            | %empty         {;}
                            ;
return_statement :          T_RETURN optexpr T_SEMI;
io_statement :              T_CIN T_INP in_list T_SEMI
                            | T_COUT T_OUT out_list T_SEMI
                            ;
in_list :                   in_list T_INP in_item
                            | in_item
                            ;
in_item :                   variable;
out_list :                  out_list T_OUT out_item
                            | out_item
                            ;
out_item :                  general_expression;
comp_statement :            T_LBRACE {scope++;} decl_statements T_RBRACE    {hashtbl_get(htable, scope); scope--;};
main_function :             main_header T_LBRACE decl_statements T_RBRACE   {hashtbl_get(htable, scope); scope--;};
main_header :               T_INT T_MAIN  T_LPAREN T_RPAREN                 {scope++;}   
                            | error T_MAIN  T_LPAREN    T_RPAREN            {fprintf(stderr, " HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; scope++;}
                            | T_INT error   T_LPAREN    T_RPAREN            {fprintf(stderr, " HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; scope++;}
                            | T_INT T_MAIN  error       T_RPAREN            {fprintf(stderr, " HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; scope++;}
                            | T_INT T_MAIN  T_LPAREN    error               {fprintf(stderr, " HINT: wrong use of int main() or failed due to earlier errors\n"); yyerrok; scope++;}
                            ;
%%



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