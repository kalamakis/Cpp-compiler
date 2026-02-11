#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semantics.h"
#include "ir.h"
#include "ast.h"
#include "symbolTable.h"

/* --- Loop Label Stack --- */
#define MAX_NESTED_LOOPS 50

static int is_reachable = 1;

static LoopLabels loop_stack[MAX_NESTED_LOOPS];
static int loop_stack_top = -1;

void push_loop(int continue_lbl, int break_lbl) {
    if (loop_stack_top >= MAX_NESTED_LOOPS - 1) {
        fprintf(stderr, "Error: Loop nesting too deep\n");
        exit(1);
    }
    loop_stack_top++;
    loop_stack[loop_stack_top].continue_label = continue_lbl;
    loop_stack[loop_stack_top].break_label = break_lbl;
}

void pop_loop() {
    if (loop_stack_top < 0) {
        fprintf(stderr, "Error: Loop stack underflow (break/continue outside loop?)\n");
        // Δεν κάνουμε exit απαραίτητα, αλλά είναι bug του parser/semantics αν συμβεί
        return;
    }
    loop_stack_top--;
}

int get_current_break_label() {
    if (loop_stack_top < 0) return -1; // Error
    return loop_stack[loop_stack_top].break_label;
}

int get_current_continue_label() {
    if (loop_stack_top < 0) return -1; // Error
    return loop_stack[loop_stack_top].continue_label;
}

/* --- String Literals Management --- */
StringLiteral *string_head = NULL;
StringLiteral *string_tail = NULL;
static int string_counter = 0;

Quad *quad_head = NULL;
Quad *quad_tail = NULL;

/* Προσθέτει ένα string στη λίστα και επιστρέφει το ID του */
int add_string_literal(const char *str) {
    // Ψάχνουμε αν υπάρχει ήδη (optimization: string interning)
    StringLiteral *curr = string_head;
    while (curr) {
        if (strcmp(curr->value, str) == 0) {
            return curr->id;
        }
        curr = curr->next;
    }

    // Αν δεν υπάρχει, φτιάχνουμε νέο
    StringLiteral *new_str = malloc(sizeof(StringLiteral));
    new_str->id = ++string_counter;
    new_str->value = strdup(str);
    new_str->next = NULL;

    if (!string_head) {
        string_head = new_str;
        string_tail = new_str;
    } else {
        string_tail->next = new_str;
        string_tail = new_str;
    }

    return new_str->id;
}

/* Μετρητές για Temps και Labels */
static int temp_counter = 0;
static int label_counter = 0;

IROperand make_operand_var(Symbol *s) {
    IROperand op;
    op.type = OT_VAR;
    op.val.sym = s;
    return op;
}

IROperand make_operand_int(int v) {
    IROperand op;
    op.type = OT_CONST_INT;
    op.val.ival = v;
    return op;
}

IROperand make_operand_temp(int temp_id) {
    IROperand op;
    op.type = OT_TEMP;
    op.val.ival = temp_id;
    return op;
}

IROperand make_operand_label(int label_id) {
    IROperand op;
    op.type = OT_LABEL;
    op.val.ival = label_id;
    return op;
}

IROperand make_operand_none() {
    IROperand op;
    op.type = OT_NONE;
    return op;
}

/* Δημιουργία νέας προσωρινής μεταβλητής (t1, t2...) */
int new_temp() {
    return ++temp_counter;
}

/* Δημιουργία νέου label (L1, L2...) */
int new_label() {
    return ++label_counter;
}

/* Προσθήκη εντολής (Quad) στη λίστα */
void emit(IROp op, IROperand arg1, IROperand arg2, IROperand result) {
    // Αν η σημαία είναι 0, αγνοούμε την παραγωγή της εντολής
    if (!is_reachable) return;

    Quad *q = malloc(sizeof(Quad));
    q->op = op;
    q->arg1 = arg1;
    q->arg2 = arg2;
    q->result = result;
    q->next = NULL;

    if (!quad_head) {
        quad_head = q;
        quad_tail = q;
    } else {
        quad_tail->next = q;
        quad_tail = q;
    }

    // Αν η εντολή είναι GOTO ή RETURN, ο κώδικας που ακολουθεί είναι νεκρός
    if (op == IR_GOTO || op == IR_RETURN) {
        is_reachable = 0;
    }
}

// Νέα, ενιαία συνάρτηση για labels (αριθμητικά ή ονομαστικά)
void emit_label_ext(int label_id, Symbol* func_sym) {
    is_reachable = 1; 

    Quad *q = malloc(sizeof(Quad));
    q->op = IR_LABEL;
    q->label_id = label_id;
    
    if (func_sym) {
        // Αποθήκευση ως OT_VAR για να μεταφερθεί το Symbol*
        q->arg1.type = OT_VAR;
        q->arg1.val.sym = func_sym;
    } else {
        q->arg1 = make_operand_none();
    }
    
    q->arg2 = make_operand_none();
    q->result = make_operand_none();
    q->next = NULL;

    if (!quad_head) { quad_head = q; quad_tail = q; }
    else { quad_tail->next = q; quad_tail = q; }
}

// Διατηρούμε την παλιά για συμβατότητα με τα loops/if
void emit_label(int label_id) {
    emit_label_ext(label_id, NULL);
}

void print_operand(IROperand op) {
    switch(op.type) {
        case OT_VAR: printf("%s", op.val.sym->name); break;
        case OT_CONST_INT: printf("%d", op.val.ival); break;
        case OT_CONST_FLOAT: printf("%.2f", op.val.fval); break;
        case OT_CONST_CHAR: printf("'%c'", op.val.cval); break;
        
        // ΝΕΟ: Υποστήριξη για Strings (Labels)
        case OT_CONST_STR: printf("%s", op.val.sval); break; 
        
        case OT_TEMP: printf("_t%d", op.val.ival); break;
        case OT_LABEL: printf("L%d", op.val.ival); break;
        case OT_NONE: break;
        default: printf("?");
    }
}

void ir_print() {
    // --- 1. Data Section (Strings) ---
    printf("\n--- Data Section ---\n");
    StringLiteral *str_curr = string_head;
    while (str_curr) {
        // Τυπώνουμε: _str_1: "Hello World"
        printf("_str_%d: \"%s\"\n", str_curr->id, str_curr->value);
        str_curr = str_curr->next;
    }

    // --- 2. Global Variables ---
    extern HASHTBL *g_symtab;
    if (g_symtab) {
        for (hash_size i = 0; i < g_symtab->size; i++) {
            struct hashnode_s *node = g_symtab->nodes[i];
            while (node) {
                Symbol *s = (Symbol *)node->data;
                if (s->scope == 0 && s->kind == SYM_VAR) {
                    printf("%s: %ld (Global)\n", s->name, s->u.c.ival);
                }
                node = node->next;
            }
        }
    }

    // --- 3. Code Section (Instructions) ---
    printf("\n--- Code Section ---\n");
    Quad *curr = quad_head;
    while (curr) {
        if (curr->op == IR_LABEL) {
            printf("L%d:", curr->label_id);
            // Αν είναι συνάρτηση, τυπώνουμε και το όνομα για σαφήνεια
            if (curr->arg1.type == OT_VAR) {
                printf(" (%s)\n", curr->arg1.val.sym->name);
            } else if (curr->arg1.type == OT_CONST_STR) {
                printf(" (%s)\n", curr->arg1.val.sval);
            } else {
                printf("\n");
            }
        } else {
            printf("\t");
            
            int is_assignment = (curr->result.type != OT_NONE) && 
                                (curr->op != IR_SET_INDEX) && 
                                (curr->op != IR_SET_FIELD) &&
                                (curr->op != IR_IF_FALSE) &&
                                (curr->op != IR_GOTO) &&
                                (curr->op != IR_READ) &&
                                (curr->op != IR_PRINT) &&
                                (curr->op != IR_PARAM) &&
                                (curr->op != IR_RETURN) &&
                                (curr->op != IR_CALL); 

            if (curr->op == IR_CALL && curr->result.type != OT_NONE) {
                is_assignment = 1;
            }

            if (is_assignment) {
                print_operand(curr->result);
                printf(" = ");
            }
            
            switch(curr->op) {
                case IR_ADD: print_operand(curr->arg1); printf(" + "); print_operand(curr->arg2); break;
                case IR_SUB: print_operand(curr->arg1); printf(" - "); print_operand(curr->arg2); break;
                case IR_MUL: print_operand(curr->arg1); printf(" * "); print_operand(curr->arg2); break;
                case IR_DIV: print_operand(curr->arg1); printf(" / "); print_operand(curr->arg2); break;
                case IR_MOD: print_operand(curr->arg1); printf(" %% "); print_operand(curr->arg2); break;
                
                case IR_EQ: print_operand(curr->arg1); printf(" == "); print_operand(curr->arg2); break;
                case IR_NE: print_operand(curr->arg1); printf(" != "); print_operand(curr->arg2); break;
                case IR_GT: print_operand(curr->arg1); printf(" > "); print_operand(curr->arg2); break;
                case IR_LT: print_operand(curr->arg1); printf(" < "); print_operand(curr->arg2); break;
                case IR_GE: print_operand(curr->arg1); printf(" >= "); print_operand(curr->arg2); break;
                case IR_LE: print_operand(curr->arg1); printf(" <= "); print_operand(curr->arg2); break;

                case IR_AND: print_operand(curr->arg1); printf(" && "); print_operand(curr->arg2); break;
                case IR_OR:  print_operand(curr->arg1); printf(" || "); print_operand(curr->arg2); break;
                
                case IR_NEG: printf("-"); print_operand(curr->arg1); break;
                case IR_NOT: printf("!"); print_operand(curr->arg1); break;

                case IR_ASSIGN: print_operand(curr->arg1); break;
                case IR_CVT_I2F: printf("(float) "); print_operand(curr->arg1); break;
                case IR_CVT_F2I: printf("(int) "); print_operand(curr->arg1); break;
                case IR_IF_FALSE: 
                    printf("ifFalse "); 
                    print_operand(curr->arg1); 
                    printf(" GOTO "); 
                    print_operand(curr->arg2); 
                    break;
                
                case IR_GOTO: 
                    printf("GOTO "); 
                    print_operand(curr->arg1); 
                    break;

                case IR_PARAM: printf("param "); print_operand(curr->arg1); break;
                
                case IR_CALL: 
                    printf("call "); 
                    print_operand(curr->arg1); 
                    printf(", "); 
                    print_operand(curr->arg2); 
                    break;
                    
                case IR_RETURN: 
                    printf("return "); 
                    if (curr->arg1.type != OT_NONE) print_operand(curr->arg1);
                    break;

                case IR_PRINT: printf("PRINT "); print_operand(curr->arg1); break;
                case IR_READ:  printf("READ ");  print_operand(curr->result); break;

                case IR_INDEX:     
                    print_operand(curr->arg1); 
                    printf("["); 
                    print_operand(curr->arg2); 
                    printf("]"); 
                    break; 

                case IR_SET_INDEX: 
                    print_operand(curr->result); 
                    printf("["); 
                    print_operand(curr->arg1);   
                    printf("] = "); 
                    print_operand(curr->arg2);   
                    break;

                case IR_LOAD_ADDR:
                    printf("&"); // Σύμβολο διεύθυνσης
                    print_operand(curr->arg1);
                    break;

                case IR_GET_FIELD: 
                    print_operand(curr->arg1); printf(".(+%d)", curr->arg2.val.ival); break;
                case IR_SET_FIELD: 
                    print_operand(curr->arg1); printf(".(+%d) = ", curr->arg2.val.ival); print_operand(curr->result); break;

                default: printf(" (unknown op) ");
            }
            printf("\n");
        }
        curr = curr->next;
    }
    printf("------------------------------\n");
}

// Βοηθητική για να μετατρέπουμε AST Ops σε IR Ops
IROp map_binary_op(ASTOp op) {
    switch(op) {
        case OP_ADD: return IR_ADD;
        case OP_SUB: return IR_SUB;
        case OP_MUL: return IR_MUL;
        case OP_DIV: return IR_DIV;
        case OP_MOD: return IR_MOD;
        case OP_EQ:  return IR_EQ;
        case OP_NE:  return IR_NE;
        case OP_GT:  return IR_GT;
        case OP_LT:  return IR_LT;
        case OP_GE:  return IR_GE;
        case OP_LE:  return IR_LE;
        case OP_AND: return IR_AND;
        case OP_OR:  return IR_OR;
        default:     return IR_ADD; // Fallback (ή error)
    }
}

/* λιστα ορισμάτων για κλήση συνάρτησης */
/* Νέα gen_args που υποστηρίζει Pass-by-Reference */
int gen_args(ASTNode *node, Symbol *func_sym, int *arg_idx) {
    if (!node) return 0;

    // Αν είναι κόμβος λίστας, πάμε αναδρομικά
    if (node->kind == AST_LIST) {
        int count = 0;
        count += gen_args(node->u.list.head, func_sym, arg_idx);
        count += gen_args(node->u.list.tail, func_sym, arg_idx);
        return count;
    }

    // Ελέγχουμε αν η συνάρτηση περιμένει Reference (&) σε αυτή τη θέση
    int is_ref = 0;
    if (func_sym && *arg_idx < func_sym->u.func.param_count) {
        is_ref = func_sym->u.func.params[*arg_idx]->is_ref_param;
    }

    IROperand op;
    if (is_ref) {
        // Αν είναι reference, στέλνουμε τη ΔΙΕΥΘΥΝΣΗ
        if (node->kind == AST_VAR) {
            int t_addr = new_temp();
            IROperand addr_op = make_operand_temp(t_addr);
            emit(IR_LOAD_ADDR, make_operand_var(node->u.var.sym), make_operand_none(), addr_op);
            op = addr_op;
        } else {
            // Fallback για πίνακες/πεδία ή αν δεν είναι απλή μεταβλητή
            op = codegen(node);
        }
    } else {
        // Pass by Value (Κλασική περίπτωση)
        op = codegen(node);
        
        // Arrays και Classes περνάνε πάντα ως pointers
        if (node->type && (node->type->kind == TYPE_ARRAY || node->type->kind == TYPE_CLASS)) {
             if (op.type == OT_VAR || op.type == OT_TEMP) {
                int t_addr = new_temp();
                IROperand addr_op = make_operand_temp(t_addr);
                emit(IR_LOAD_ADDR, op, make_operand_none(), addr_op);
                op = addr_op;
             }
        }
    }

    (*arg_idx)++; // Αυξάνουμε τον δείκτη ορίσματος
    emit(IR_PARAM, op, make_operand_none(), make_operand_none());
    return 1;
}

// Η κύρια αναδρομική συνάρτηση
IROperand codegen(ASTNode *node) {
    if (!node) return make_operand_none();

    switch (node->kind) {
        // --- 1. Σταθερές ---
        case AST_CONST: {
            // Ελέγχουμε τον τύπο της σταθεράς (int, float, char...)
            // Εδώ υποθέτουμε ότι το AST node έχει τα πεδία στο union
            if (node->type == type_int) {
                return make_operand_int(node->u.constant.ival);
            } else if (node->type == type_float) {
                IROperand op; 
                op.type = OT_CONST_FLOAT; 
                op.val.fval = node->u.constant.fval; 
                return op;
            } else if (node->type == type_char) {
                IROperand op; op.type = OT_CONST_CHAR; op.val.cval = node->u.constant.cval; return op;
            } else if (node->type == type_string) {
                // Καταχωρούμε το string και παίρνουμε πίσω το ID (π.χ. 1 για το _str_1)
                int str_id = add_string_literal(node->u.constant.sval);

                IROperand op;
                op.type = OT_CONST_STR; 
                // Φτιάχνουμε το όνομα του label: _str_1, _str_2, ...
                char buffer[32];
                sprintf(buffer, "_str_%d", str_id);
                op.val.sval = strdup(buffer); 
                return op;
            }
            return make_operand_int(0); // Fallback
        }

        // --- 2. Μεταβλητές ---
        case AST_VAR: {
            Symbol *s = node->u.var.sym;
            
            // Αν το σύμβολο είναι σταθερά Enum, επέστρεψε την τιμή του ως Integer Literal
            if (s->kind == SYM_ENUM_CONST) {
                return make_operand_int(s->u.enum_const.value);
            }

            // Διαφορετικά, επέστρεψε την κανονική μεταβλητή
            return make_operand_var(s);
        }

        // --- 3. Binary Operations ---
        case AST_BINOP: {
            // Περίπτωση Short-Circuit AND (expr1 && expr2)
            if (node->u.binop.op == OP_AND) {
                int L_end = new_label();
                int t = new_temp();
                IROperand result = make_operand_temp(t);

                // Αρχικοποίηση αποτελέσματος σε 0 (False)
                emit(IR_ASSIGN, make_operand_int(0), make_operand_none(), result);

                // Αριστερό μέρος
                IROperand left = codegen(node->u.binop.left);
                // Αν αριστερό False, πήγαινε στο τέλος (το result μένει 0)
                emit(IR_IF_FALSE, left, make_operand_label(L_end), make_operand_none());

                // Δεξί μέρος (εκτελείται μόνο αν αριστερό True)
                IROperand right = codegen(node->u.binop.right);
                // Αν δεξί False, πήγαινε στο τέλος (το result μένει 0)
                emit(IR_IF_FALSE, right, make_operand_label(L_end), make_operand_none());

                // Αν φτάσαμε εδώ, και τα δύο είναι True
                emit(IR_ASSIGN, make_operand_int(1), make_operand_none(), result);

                emit_label(L_end);
                return result;
            }

            // Περίπτωση Short-Circuit OR (expr1 || expr2)
            else if (node->u.binop.op == OP_OR) {
                int L_true = new_label(); // Label για να θέσουμε 1
                int L_end  = new_label();
                int t = new_temp();
                IROperand result = make_operand_temp(t);

                // Αρχικοποίηση αποτελέσματος σε 0
                emit(IR_ASSIGN, make_operand_int(0), make_operand_none(), result);

                // Αριστερό μέρος
                IROperand left = codegen(node->u.binop.left);
                // Αν το αριστερό είναι FALSE, πρέπει να ελέγξουμε το δεξί.
                // ΑΡΑ: Αν το αριστερό είναι TRUE, τελειώσαμε -> GOTO L_true.
                // Επειδή έχουμε μόνο ifFalse, κάνουμε το ανάποδο:
                // ifFalse left GOTO L_check_right
                // GOTO L_true
                int L_check_right = new_label();
                
                emit(IR_IF_FALSE, left, make_operand_label(L_check_right), make_operand_none());
                emit(IR_GOTO, make_operand_label(L_true), make_operand_none(), make_operand_none());

                emit_label(L_check_right);
                IROperand right = codegen(node->u.binop.right);
                emit(IR_IF_FALSE, right, make_operand_label(L_end), make_operand_none());
                
                emit_label(L_true);
                emit(IR_ASSIGN, make_operand_int(1), make_operand_none(), result);

                emit_label(L_end);
                return result;
            }

            // --- Κανονικές Αριθμητικές Πράξεις (+, -, *, <, > ...) ---
            // --- Κανονικές Αριθμητικές Πράξεις (+, -, *, <, > ...) ---
            else {
                IROperand left = codegen(node->u.binop.left);
                IROperand right = codegen(node->u.binop.right);
                
                Type *t_left = node->u.binop.left->type;
                Type *t_right = node->u.binop.right->type;

                // Implicit Casting: Μετατροπή αν ένας είναι float και ο άλλος int
                if (t_left == type_int && t_right == type_float) {
                    int t_new = new_temp();
                    IROperand cast_res = make_operand_temp(t_new);
                    emit(IR_CVT_I2F, left, make_operand_none(), cast_res);
                    left = cast_res;
                }
                else if (t_left == type_float && t_right == type_int) {
                    int t_new = new_temp();
                    IROperand cast_res = make_operand_temp(t_new);
                    emit(IR_CVT_I2F, right, make_operand_none(), cast_res);
                    right = cast_res;
                }

                int t = new_temp();
                IROperand result = make_operand_temp(t);
                IROp op = map_binary_op(node->u.binop.op);
                emit(op, left, right, result);
                return result;
            }
        }

        // --- 4. Assignment ---
        case AST_ASSIGN: {
            ASTNode *lhs = node->u.assign.lhs;
            IROperand rhs_val = codegen(node->u.assign.rhs);
            
            Type *t_lhs = lhs->type;
            Type *t_rhs = node->u.assign.rhs->type;

            // Εφαρμογή Οδηγίας (β): Αριθμητική συμβατότητα
            // 1. int σε float (μετατροπή σε πραγματικό)
            if (t_lhs == type_float && t_rhs == type_int) {
                int t_new = new_temp();
                IROperand cast_res = make_operand_temp(t_new);
                emit(IR_CVT_I2F, rhs_val, make_operand_none(), cast_res);
                rhs_val = cast_res;
            }
            // 2. float σε int (αποκοπή κλασματικού μέρους)
            else if (t_lhs == type_int && t_rhs == type_float) {
                int t_new = new_temp();
                IROperand cast_res = make_operand_temp(t_new);
                emit(IR_CVT_F2I, rhs_val, make_operand_none(), cast_res);
                rhs_val = cast_res;
            }

            if (lhs->kind == AST_FIELD) {
                ASTNode *base_node = lhs->u.field.base;
                IROperand base_addr;

                // ΕΛΕΓΧΟΣ: Αν η βάση είναι το 'this', είναι ήδη διεύθυνση
                if (base_node->kind == AST_VAR && strcmp(base_node->u.var.name, "this") == 0) {
                    base_addr = codegen(base_node);
                } else {
                    IROperand base_val = codegen(base_node);
                    int t_addr = new_temp();
                    base_addr = make_operand_temp(t_addr);
                    emit(IR_LOAD_ADDR, base_val, make_operand_none(), base_addr);
                }

                int offset = lhs->u.field.member->offset;
                emit(IR_SET_FIELD, base_addr, make_operand_int(offset), rhs_val);
                return rhs_val;
            }

            if (lhs->kind == AST_VAR) {
                IROperand lhs_op = make_operand_var(lhs->u.var.sym);
                emit(IR_ASSIGN, rhs_val, make_operand_none(), lhs_op);
                return lhs_op;
            } 
            else if (lhs->kind == AST_INDEX) {
                // Λογική Πολλαπλών Διαστάσεων (Linearization)
                // A[i][j] = RHS
                
                ASTNode *curr = lhs;
                IROperand total_offset = make_operand_int(0);
                ASTNode *base_array = NULL;

                // Διασχίζουμε τα nested indices: A[i][j] -> INDEX( INDEX(A, i), j )
                while (curr->kind == AST_INDEX) {
                    ASTNode *idx_expr = curr->u.index.index;
                    IROperand idx_op = codegen(idx_expr);

                    // Offset += index * sizeof(current_element_type)
                    long step_size = sem_sizeof_bytes(curr->type, 0);
                    
                    int t_mul = new_temp();
                    emit(IR_MUL, idx_op, make_operand_int((int)step_size), make_operand_temp(t_mul));

                    int t_add = new_temp();
                    emit(IR_ADD, total_offset, make_operand_temp(t_mul), make_operand_temp(t_add));
                    total_offset = make_operand_temp(t_add);

                    curr = curr->u.index.array;
                }
                
                // Τώρα το curr είναι η βάση (π.χ. μεταβλητή A)
                base_array = curr;
                IROperand base_op = codegen(base_array);

                // Emit: base_op[total_offset] = rhs_res
                emit(IR_SET_INDEX, total_offset, rhs_val, base_op);
                return rhs_val;
            }
            return make_operand_none();
        }

        // --- 5. IF Statement ---
        case AST_IF: {
            int L_false = new_label();
            int L_end = new_label();

            // 1. Συνθήκη
            IROperand cond = codegen(node->u.if_stmt.cond);
            // ifFalse cond GOTO L_false
            emit(IR_IF_FALSE, cond, make_operand_label(L_false), make_operand_none());

            // 2. Then block
            codegen(node->u.if_stmt.then_part);
            emit(IR_GOTO, make_operand_label(L_end), make_operand_none(), make_operand_none());

            // 3. Else block
            emit_label(L_false);
            if (node->u.if_stmt.else_part) {
                codegen(node->u.if_stmt.else_part);
            }

            // 4. End
            emit_label(L_end);
            return make_operand_none();
        }

        // --- 6. WHILE Loop ---
        case AST_WHILE: {
            int L_start = new_label(); // Εδώ πάει το continue
            int L_end = new_label();   // Εδώ πάει το break

            emit_label(L_start);

            // Συνθήκη
            IROperand cond = codegen(node->u.while_stmt.cond);
            emit(IR_IF_FALSE, cond, make_operand_label(L_end), make_operand_none());

            // PUSH Labels
            push_loop(L_start, L_end);

            // Σώμα
            codegen(node->u.while_stmt.body);

            // POP Labels
            pop_loop();

            emit(IR_GOTO, make_operand_label(L_start), make_operand_none(), make_operand_none());
            emit_label(L_end);
            return make_operand_none();
        }

        // --- Break Statement ---
        case AST_BREAK: {
            int lbl = get_current_break_label();
            if (lbl == -1) {
                // Αυτό κανονικά το πιάνει το semantics.c, αλλά για ασφάλεια:
                fprintf(stderr, "Error: 'break' outside of loop\n");
            } else {
                emit(IR_GOTO, make_operand_label(lbl), make_operand_none(), make_operand_none());
            }
            return make_operand_none();
        }

        // --- Continue Statement ---
        case AST_CONTINUE: {
            int lbl = get_current_continue_label();
            if (lbl == -1) {
                fprintf(stderr, "Error: 'continue' outside of loop\n");
            } else {
                emit(IR_GOTO, make_operand_label(lbl), make_operand_none(), make_operand_none());
            }
            return make_operand_none();
        }

        // --- 7. FOR Loop ---
        case AST_FOR: {
            int L_cond = new_label();
            int L_step = new_label(); // Νέο label για το step!
            int L_end  = new_label();
            
            // 1. Init
            if (node->u.for_stmt.init) codegen(node->u.for_stmt.init);

            emit_label(L_cond);

            // 2. Condition
            if (node->u.for_stmt.cond) {
                IROperand cond = codegen(node->u.for_stmt.cond);
                emit(IR_IF_FALSE, cond, make_operand_label(L_end), make_operand_none());
            }

            // PUSH Labels: continue -> step, break -> end
            push_loop(L_step, L_end);

            // 3. Body
            codegen(node->u.for_stmt.body);

            // POP Labels
            pop_loop();

            // 4. Step Label & Code
            emit_label(L_step);
            if (node->u.for_stmt.step) codegen(node->u.for_stmt.step);

            emit(IR_GOTO, make_operand_label(L_cond), make_operand_none(), make_operand_none());
            emit_label(L_end);
            return make_operand_none();
        }

        // --- 8. Block (Λίστα εντολών) ---
        // Στο AST σου μπορεί να είναι AST_BLOCK ή AST_LIST
        // Εδώ υποθέτω ότι το Program έχει lists από stmts
        case AST_BLOCK: {
            // Συνήθως έχεις μια λίστα "stmts"
            // Αν το AST_BLOCK έχει απλά pointers σε lists:
            ASTNode *curr = node->u.block.stmts; 
            // Προσοχή: Εδώ εξαρτάται πώς έχεις υλοποιήσει τη λίστα στο AST.
            // Αν είναι συνδεδεμένη λίστα κόμβων (όπως φαίνεται στο ast.h με AST_LIST):
            codegen(curr); // Αναδρομή στη λίστα
            return make_operand_none();
        }
        
        case AST_LIST: {
            // Διασχίζουμε τη λίστα
            if (node->u.list.head) codegen(node->u.list.head);
            if (node->u.list.tail) codegen(node->u.list.tail);
            return make_operand_none();
        }

        // --- 9. Function Declaration ---
        // --- 9. Function Declaration ---
        case AST_FUNC_DECL: {
<<<<<<< HEAD
            // ΔΙΟΡΘΩΣΗ: Αντί για emit_label_ext, φτιάχνουμε το Quad χειροκίνητα
            // για να περάσουμε το Symbol* (που περιέχει το offset του stack frame)
            
            Symbol *func_sym = symtab_lookup(node->u.func_decl.name);
            
            Quad *q = malloc(sizeof(Quad));
            q->op = IR_LABEL;
            q->label_id = new_label();
            
            if (func_sym) {
                // Σωστή περίπτωση: Περνάμε το σύμβολο
                q->arg1.type = OT_VAR;
                q->arg1.val.sym = func_sym;
            } else {
                // Fallback (ασφάλεια): Περνάμε το όνομα ως string
                q->arg1.type = OT_CONST_STR;
                q->arg1.val.sval = strdup(node->u.func_decl.name);
            }
            
            q->arg2 = make_operand_none();
            q->result = make_operand_none();
            q->next = NULL;

            // Προσθήκη στη λίστα
            if (!quad_head) { quad_head = q; quad_tail = q; }
            else { quad_tail->next = q; quad_tail = q; }
            
            is_reachable = 1;

            // Παραγωγή κώδικα για το σώμα
            codegen(node->u.func_decl.body);
=======
            // Αναζήτηση του συμβόλου της συνάρτησης
            Symbol *s = symtab_lookup(node->u.func_decl.name);
>>>>>>> 7f6908f63419d87559c437b00ed6ec3bee11373f
            
            // Πέρασμα του συμβόλου αντί για το όνομα
            emit_label_ext(-1, s);

            codegen(node->u.func_decl.body);
            emit(IR_RETURN, make_operand_none(), make_operand_none(), make_operand_none());
            
            return make_operand_none();
        }

        // --- 10. Return ---
        case AST_RETURN: {
            IROperand res = make_operand_none();
            if (node->u.ret_stmt.expr) {
                res = codegen(node->u.ret_stmt.expr);
            }
            emit(IR_RETURN, res, make_operand_none(), make_operand_none());
            return make_operand_none();
        }
        
        // --- 11. Function / Method Call ---
        case AST_CALL: {
            ASTNode *func_node = node->u.call.func;
            ASTNode *args_node = node->u.call.args;
            int arg_count = 0;
            char *func_name = NULL;
            Symbol *target_func_sym = NULL;

            // ΕΛΕΓΧΟΣ: Είναι μέθοδος (obj.method(...)) ή απλή συνάρτηση;
            if (func_node->kind == AST_FIELD) {
                // 1. Παραγωγή κώδικα για το αντικείμενο (το "this")
                ASTNode *base_obj = func_node->u.field.base;
                IROperand this_addr;

                if (base_obj->kind == AST_VAR && strcmp(base_obj->u.var.name, "this") == 0) {
                    this_addr = codegen(base_obj);
                } else {
                    IROperand base_val = codegen(base_obj);
                    int t_this = new_temp();
                    this_addr = make_operand_temp(t_this);
                    emit(IR_LOAD_ADDR, base_val, make_operand_none(), this_addr);
                }

                emit(IR_PARAM, this_addr, make_operand_none(), make_operand_none());
                arg_count++; 

                Symbol *method_sym = func_node->u.field.member;
                target_func_sym = method_sym; // Κρατάμε το σύμβολο για έλεγχο παραμέτρων
                
                // Name Mangling
                Type *cls_type = base_obj->type; 
                char buffer[128];
                if (cls_type && cls_type->enum_name) {
                    sprintf(buffer, "%s_%s", cls_type->enum_name, method_sym->name);
                } else {
                    sprintf(buffer, "_%s", method_sym->name);
                }
                func_name = strdup(buffer);
            }
            else {
                // Απλή συνάρτηση
                if (func_node->kind == AST_VAR) {
                    target_func_sym = func_node->u.var.sym;
                    func_name = target_func_sym->name;
                } else {
                    func_name = "unknown_func";
                }
            }

            // 4. Παραγωγή ορισμάτων με έλεγχο Reference
            int arg_idx_counter = 0;
            // Αν είναι μέθοδος, το 1ο όρισμα είναι το 'this', άρα οι παράμετροι ξεκινάνε από 1 (αν τις μετράς μαζί)
            // Στο symbol table όμως οι παράμετροι είναι stored χωρίς το this συνήθως.
            // Εδώ υποθέτουμε ότι το arg_idx_counter ξεκινάει από 0 και αντιστοιχεί στα ορίσματα του AST.
            
            arg_count += gen_args(args_node, target_func_sym, &arg_idx_counter);

            // 5. Ετοιμασία αποτελέσματος
            int t = new_temp();
            IROperand result = make_operand_temp(t);

            // 6. Emit CALL
            IROperand func_op;
            func_op.type = OT_VAR;
            Symbol *sym = malloc(sizeof(Symbol));
            sym->name = func_name;
            func_op.val.sym = sym;

            emit(IR_CALL, func_op, make_operand_int(arg_count), result);

            return result;
        }

        // --- Array Access ---
        case AST_INDEX: {
            ASTNode *curr = node;
            IROperand total_offset = make_operand_int(0);
            ASTNode *base_array = NULL;

            // 1. Διασχίζουμε προς τα κάτω
            while (curr->kind == AST_INDEX) {
                ASTNode *idx_expr = curr->u.index.index;
                IROperand idx_op = codegen(idx_expr);
                
                long step_size = sem_sizeof_bytes(curr->type, 0); 
                
                int t_mul = new_temp();
                emit(IR_MUL, idx_op, make_operand_int((int)step_size), make_operand_temp(t_mul));
                
                int t_add = new_temp();
                emit(IR_ADD, total_offset, make_operand_temp(t_mul), make_operand_temp(t_add));
                total_offset = make_operand_temp(t_add);

                // Απλά προχωράμε στο επόμενο
                curr = curr->u.index.array;
            }
            
            // 2. Όταν βγούμε από το loop, το curr είναι πλέον η βάση (AST_VAR)
            base_array = curr; 
            IROperand base_op = codegen(base_array);
            
            // 3. Υπολογισμός αποτελέσματος
            int t_res = new_temp();
            IROperand result = make_operand_temp(t_res);
            emit(IR_INDEX, base_op, total_offset, result);
            
            return result;
        }

        // --- Unary Operators (-, !) ---
        case AST_UNOP: {
            IROperand arg = codegen(node->u.unop.expr);
            int t = new_temp();
            IROperand result = make_operand_temp(t);
            
            if (node->u.unop.op == OP_SUB) {
                // Unary Minus: t = -arg
                emit(IR_NEG, arg, make_operand_none(), result);
            } else if (node->u.unop.op == OP_NOT) {
                // Logical Not: t = !arg
                emit(IR_NOT, arg, make_operand_none(), result);
            }
            // Πρόσθεσε εδώ άλλα unary (π.χ. OP_PRE_INC) αν χρειάζεται
            return result;
        }

        // --- COUT (cout << expr1 << expr2 ...) ---
        case AST_COUT: {
            ASTNode *curr = node->u.io_stmt.io_list;
            // Η λίστα στο AST είναι συνήθως nested ή linked. 
            // Αν είναι AST_LIST, την διασχίζουμε:
            while (curr && curr->kind == AST_LIST) {
                // Υποθέτουμε ότι το head είναι το expression
                IROperand res = codegen(curr->u.list.head);
                emit(IR_PRINT, res, make_operand_none(), make_operand_none());
                curr = curr->u.list.tail;
            }
            // Αν έμεινε ένα τελευταίο στοιχείο (edge case της λίστας)
            if (curr && curr->kind != AST_LIST) {
                IROperand res = codegen(curr);
                emit(IR_PRINT, res, make_operand_none(), make_operand_none());
            }
            return make_operand_none();
        }

        // --- CIN (cin >> var1 >> var2 ...) ---
        case AST_CIN: {
            ASTNode *curr = node->u.io_stmt.io_list;
            while (curr && curr->kind == AST_LIST) {
                IROperand var = codegen(curr->u.list.head);
                // Προσοχή: Εδώ το var είναι το αποτέλεσμα, άρα μπαίνει στο result του Quad
                emit(IR_READ, make_operand_none(), make_operand_none(), var);
                curr = curr->u.list.tail;
            }

            if (curr && curr->kind != AST_LIST) {
                IROperand var = codegen(curr);
                emit(IR_READ, make_operand_none(), make_operand_none(), var);
            }
            return make_operand_none();
        }
        
        case AST_ENUM_DECL: {
            // Οι δηλώσεις enum δεν παράγουν κώδικα μηχανής.
            // Οι σταθερές έχουν ήδη μπει στο Symbol Table.
            return make_operand_none();
        }

        case AST_PROGRAM: {
            // 1. Καθολικές δηλώσεις (συναρτήσεις όπως η inc)
            if (node->u.program.globals) {
                codegen(node->u.program.globals);
            }
            // 2. Η κύρια συνάρτηση
            if (node->u.program.main_func) {
                codegen(node->u.program.main_func);
            }
            return make_operand_none();
        }

        case AST_FIELD: {
            ASTNode *base_node = node->u.field.base;
            IROperand base_addr;

            // ΕΛΕΓΧΟΣ: Αν η βάση είναι το 'this', χρησιμοποιούμε την τιμή του απευθείας
            if (base_node->kind == AST_VAR && strcmp(base_node->u.var.name, "this") == 0) {
                base_addr = codegen(base_node); 
            } else {
                // Για κανονικά αντικείμενα, παίρνουμε τη διεύθυνσή τους
                IROperand base_val = codegen(base_node);
                int t_addr = new_temp();
                base_addr = make_operand_temp(t_addr);
                emit(IR_LOAD_ADDR, base_val, make_operand_none(), base_addr);
            }

            int offset = node->u.field.member->offset;
            int t_res = new_temp();
            IROperand result = make_operand_temp(t_res);
            
            emit(IR_GET_FIELD, base_addr, make_operand_int(offset), result);
            return result;
        }

        default:
            break;
    }

    return make_operand_none();
}