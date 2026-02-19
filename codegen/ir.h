#ifndef IR_H
#define IR_H

#include "symbol.h" 
#include "ast.h"

typedef enum {
    /* Arithmetic */
    IR_ADD,     // x = y + z
    IR_SUB,     // x = y - z
    IR_MUL,     // x = y * z
    IR_DIV,     // x = y / z
    IR_MOD,     // x = y % z

    /* Relational (για if/while) */
    IR_EQ,      // x = (y == z)
    IR_NE,      // x = (y != z)
    IR_GT,      // x = (y > z)
    IR_LT,      // x = (y < z)
    IR_GE,      // x = (y >= z)
    IR_LE,      // x = (y <= z)

    /* Logical */
    IR_AND,     // x = y && z
    IR_OR,      // x = y || z
    IR_NOT,     // x = !y

    /* Assignment */
    IR_ASSIGN,  // x = y
    /* Control Flow */
    IR_GOTO,    // goto L
    IR_IF,      // if x goto L (Conditional Jump)
    IR_IF_FALSE,// ifFalse x goto L 
    IR_LABEL,   // Label L:

    /* Functions */
    IR_PARAM,   // param x
    IR_CALL,    // x = call func, n
    IR_RETURN,  // return x

    /* Arrays / Pointers */
    IR_INDEX,   // x = y[z] (Load array)
    IR_SET_INDEX, // x[y] = z (Store array)

    /* Unary Ops */
    IR_NEG,     // x = -y
    /* I/O Operations */
    IR_PRINT,   // cout << x
    IR_READ,     // cin >> x
    IR_CVT_I2F,  // Convert Int to Float (μετατροπή σε πραγματικό)
    IR_CVT_F2I,  // Convert Float to Int (μετατροπή σε ακέραιο)
    IR_LOAD_ADDR,  // result = &arg1 (διεύθυνση μνήμης)
    IR_GET_FIELD, // result = base_addr + offset (ανάγνωση πεδίου)
    IR_SET_FIELD, // base_addr + offset = value (ανάθεση σε πεδίο)

    //---lists ops//

    IR_CONS,        //
    IR_CAR,
    IR_CDR
} IROp;

typedef enum {
    OT_VAR,         // Μεταβλητή από το Symbol Table (x, y, i...)
    OT_CONST_INT,   // Σταθερά int (5, 10...)
    OT_CONST_FLOAT, // Σταθερά float (3.14...)
    OT_CONST_CHAR,  // Σταθερά char ('a')
    OT_CONST_STR,   // String literal ("hello")
    OT_TEMP,        // Προσωρινή μεταβλητή (t1, t2...)
    OT_LABEL,       // Ετικέτα (L1, L2...)
    OT_NONE         // Κενό (π.χ. το return χωρίς τιμή ή το goto που δεν έχει arg2)
} IROperandType;

typedef struct {
    IROperandType type;
    union {
        Symbol *sym;      // Αν είναι VAR (έχεις ήδη το struct Symbol)
        int     ival;     // Αν είναι INT ή TEMP ID ή LABEL ID
        double  fval;     // Αν είναι FLOAT
        char    cval;     // Αν είναι CHAR
        char   *sval;     // Αν είναι STRING
    } val;
} IROperand;

typedef struct Quad {
    IROp op;
    IROperand arg1;
    IROperand arg2;
    IROperand result;
    int label_id;        // Αν η εντολή είναι OP_LABEL, ποιο είναι το νούμερο;
    struct Quad *next;   // Για να τα βάζουμε σε λίστα
} Quad;

/* Global λίστα με τα Quads */
extern Quad *quad_head;
extern Quad *quad_tail;

typedef struct {
    int continue_label;
    int break_label;
} LoopLabels;

typedef struct StringLiteral {
    int id;
    char *value;
    struct StringLiteral *next;
} StringLiteral;

void push_loop(int continue_lbl, int break_lbl);
void pop_loop();
int get_current_break_label();
int get_current_continue_label();
int add_string_literal(const char *str);
IROperand make_operand_var(Symbol *s);
IROperand make_operand_int(int v);
IROperand make_operand_temp(int temp_id);
IROperand make_operand_label(int label_id);
IROperand make_operand_none();
int new_temp();
int new_label();
void emit(IROp op, IROperand arg1, IROperand arg2, IROperand result);
void emit_label_ext(int label_id, char* name);
void emit_label(int label_id);
void print_operand(IROperand op);
void ir_print();
IROp map_binary_op(ASTOp op);
int gen_args(ASTNode *node, Symbol *func_sym, int *arg_idx);
IROperand codegen(ASTNode *node);
#endif