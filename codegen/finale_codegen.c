#include <stdio.h>
#include <stdlib.h>
#include "ir.h"
#include "symbol.h"

FILE *f_asm;

// --- phase 0: Initialization ---

void mips_init(const char *filename) {
    f_asm = fopen(filename, "w");
    if (!f_asm) {
        perror("Cannot create assembly file");
        exit(1);
    }
}

void mips_data_section() {
    fprintf(f_asm, ".data\n");
    fprintf(f_asm, "newline: .asciiz \"\\n\"\n");
    
    extern StringLiteral *string_head; 
    StringLiteral *curr = string_head;
    while (curr) {
        fprintf(f_asm, "_str_%d: .asciiz \"%s\"\n", curr->id, curr->value);
        curr = curr->next;
    }
    fprintf(f_asm, "\n");
}

void mips_finish() {
    if (f_asm) {
        // Exit syscall για να μην "τρέξει" ο κώδικας έξω από τη main
        fprintf(f_asm, "\n# Exit program\n");
        fprintf(f_asm, "\tli $v0, 10\n\tsyscall\n");
        fclose(f_asm);
    }
}

// --- phase 1: Διαχείριση Μνήμης & Temps ---

static int current_local_size = 0;

int get_mips_offset(IROperand op) {
    if (op.type == OT_VAR) {
        return op.val.sym->offset; 
    }
    if (op.type == OT_TEMP) {
        return -(current_local_size + 8 + (op.val.ival * 4)); 
    }
    return 0;
}

int is_global(IROperand op) {
    if (op.type == OT_VAR && op.val.sym->scope == 0) return 1;
    return 0;
}

// --- Prologue/Epilogue ---

void mips_prologue(const char *func_name, int local_size) {
    fprintf(f_asm, "\n# --- Prologue for %s ---\n", func_name);
    fprintf(f_asm, "%s:\n", func_name);
    int total_stack = local_size + 64; // Αυξημένος χώρος για ασφάλεια (floats κλπ)
    fprintf(f_asm, "\taddiu $sp, $sp, -%d\n", total_stack);
    fprintf(f_asm, "\tsw $ra, %d($sp)\n", total_stack - 4);
    fprintf(f_asm, "\tsw $fp, %d($sp)\n", total_stack - 8);
    fprintf(f_asm, "\taddiu $fp, $sp, %d\n", total_stack - 8);
}

void mips_epilogue(int local_size) {
    int total_stack = local_size + 64;
    fprintf(f_asm, "\n# --- Epilogue ---\n");
    fprintf(f_asm, "\tlw $ra, %d($sp)\n", total_stack - 4);
    fprintf(f_asm, "\tlw $fp, %d($sp)\n", total_stack - 8);
    fprintf(f_asm, "\taddiu $sp, $sp, %d\n", total_stack);
    fprintf(f_asm, "\tjr $ra\n");
}

// --- Load/Store Helpers ---

// Φόρτωση σε Integer Register ($t0-$t9)
void load_to_reg(IROperand op, const char *reg) {
    if (op.type == OT_CONST_INT) {
        fprintf(f_asm, "\tli %s, %d\n", reg, op.val.ival);
    } else if (op.type == OT_CONST_CHAR) {
        fprintf(f_asm, "\tli %s, %d\n", reg, (int)op.val.cval);
    } else if (op.type == OT_CONST_STR) {
        fprintf(f_asm, "\tla %s, %s\n", reg, op.val.sval);
    } else if (op.type == OT_VAR || op.type == OT_TEMP) {
        if (is_global(op)) {
            // Global: Access by label name
            fprintf(f_asm, "\tlw %s, _%s\n", reg, op.val.sym->name);
        } else {
            // Local: Access by $fp offset
            fprintf(f_asm, "\tlw %s, %d($fp)\n", reg, get_mips_offset(op));
        }
    }
}

// Φόρτωση σε Float Register ($f0-$f12)
void load_to_freg(IROperand op, const char *reg) {
    if (op.type == OT_CONST_FLOAT) {
        fprintf(f_asm, "\tli.s %s, %.6f\n", reg, op.val.fval);
    } else if (op.type == OT_VAR || op.type == OT_TEMP) {
        if (is_global(op)) {
            fprintf(f_asm, "\tl.s %s, _%s\n", reg, op.val.sym->name);
        } else {
            fprintf(f_asm, "\tl.s %s, %d($fp)\n", reg, get_mips_offset(op));
        }
    } else if (op.type == OT_CONST_INT) {
         // Αν κατά λάθος ζητηθεί int σε float reg, κάνε convert
         fprintf(f_asm, "\tli $t9, %d\n", op.val.ival);
         fprintf(f_asm, "\tmtc1 $t9, %s\n", reg);
         fprintf(f_asm, "\tcvt.s.w %s, %s\n", reg, reg);
    }
}

// Αποθήκευση αποτελέσματος (Int ή Float)
void store_result(IROperand res, const char *reg, int is_float) {
    if (res.type == OT_NONE) return;
    
    int offset = get_mips_offset(res);
    char *store_instr = is_float ? "s.s" : "sw";
    
    if (is_global(res)) {
        fprintf(f_asm, "\t%s %s, _%s\n", store_instr, reg, res.val.sym->name);
    } else {
        fprintf(f_asm, "\t%s %s, %d($fp)\n", store_instr, reg, offset);
    }
}

static int param_count = 0; // Μετρητής παραμέτρων για το IR_PARAM

void generate_mips() {
    fprintf(f_asm, ".text\n.globl main\n");
    Quad *curr = quad_head;
    int current_frame_size = 0;
    int is_float = (curr->arg1.type == OT_CONST_FLOAT || curr->arg2.type == OT_CONST_FLOAT);

    while (curr) {
        switch(curr->op) {
            case IR_LABEL:{
                if (curr->arg1.type != OT_NONE) {
                    // --- Λειτουργία Συνάρτησης (Prologue) ---
                    char *func_name;
                    int stack_size = 0;

                    if (curr->arg1.type == OT_VAR) {
                        Symbol *func_sym = curr->arg1.val.sym;
                        func_name = func_sym->name;
                        stack_size = func_sym->offset;
                    } else {
                        func_name = curr->arg1.val.sval;
                        stack_size = 32;
                    }

                    current_local_size = stack_size;
                    
                    // Παράγουμε και το Label L<id> για debugging ή jumps, αλλά και το όνομα
                    // Στον MIPS entry point είναι το όνομα.
                    // Αν θέλεις να κρατήσεις τη συμβατότητα με το IR label id:
                    fprintf(f_asm, "L%d:\n", curr->label_id); 
                    
                    mips_prologue(func_name, current_local_size);
                } else {
                    // --- Απλό Label (Jump target) ---
                    fprintf(f_asm, "L%d:\n", curr->label_id);
                }
                break;
            }
            // --- 1. Αριθμητικές/Λογικες Πράξεις ---
            case IR_ADD:{
                if (is_float) {
                    load_to_freg(curr->arg1, "$f0");
                    load_to_freg(curr->arg2, "$f1");
                    fprintf(f_asm, "\tadd.s $f2, $f0, $f1\n");
                    store_result(curr->result, "$f2", 1);
                } else {
                    load_to_reg(curr->arg1, "$t0");
                    load_to_reg(curr->arg2, "$t1");
                    fprintf(f_asm, "\tadd $t2, $t0, $t1\n");
                    store_result(curr->result, "$t2", 0);
                }
                break;
            }
            case IR_SUB:{
                if (is_float) {
                    load_to_freg(curr->arg1, "$f0");
                    load_to_freg(curr->arg2, "$f1");
                    fprintf(f_asm, "\tsub.s $f2, $f0, $f1\n");
                    store_result(curr->result, "$f2", 1);
                } else {
                    load_to_reg(curr->arg1, "$t0");
                    load_to_reg(curr->arg2, "$t1");
                    fprintf(f_asm, "\tsub $t2, $t0, $t1\n");
                    store_result(curr->result, "$t2", 0);
                }
                break;
            }
            case IR_MUL:{
                if (is_float) {
                    load_to_freg(curr->arg1, "$f0");
                    load_to_freg(curr->arg2, "$f1");
                    fprintf(f_asm, "\tmul.s $f2, $f0, $f1\n");
                    store_result(curr->result, "$f2", 1);
                } else {
                    load_to_reg(curr->arg1, "$t0");
                    load_to_reg(curr->arg2, "$t1");
                    fprintf(f_asm, "\tmul $t2, $t0, $t1\n");
                    store_result(curr->result, "$t2", 0);
                }
                break;
            }
            case IR_DIV:{
                if (is_float) {
                    load_to_freg(curr->arg1, "$f0");
                    load_to_freg(curr->arg2, "$f1");
                    fprintf(f_asm, "\tdiv.s $f2, $f0, $f1\n");
                    store_result(curr->result, "$f2", 1);
                } else {
                    load_to_reg(curr->arg1, "$t0");
                    load_to_reg(curr->arg2, "$t1");
                    fprintf(f_asm, "\tdiv $t0, $t1\n");
                    fprintf(f_asm, "\tmflo $t2\n"); 
                    store_result(curr->result, "$t2", 0);
                }
                break;
            }
            case IR_MOD:{
                load_to_reg(curr->arg1, "$t0");
                load_to_reg(curr->arg2, "$t1");
                fprintf(f_asm, "\tdiv $t0, $t1\n");
                fprintf(f_asm, "\tmfhi $t2\n"); // Το υπόλοιπο μπαίνει στο $t2
                fprintf(f_asm, "\tsw $t2, %d($fp)\n", get_mips_offset(curr->result));
                break;
            }
            case IR_AND:{
                load_to_reg(curr->arg1, "$t0");
                load_to_reg(curr->arg2, "$t1");
                fprintf(f_asm, "\tand $t2, $t0, $t1\n");
                fprintf(f_asm, "\tsw $t2, %d($fp)\n", get_mips_offset(curr->result));
                break;
            }
            case IR_OR:{
                load_to_reg(curr->arg1, "$t0");
                load_to_reg(curr->arg2, "$t1");
                fprintf(f_asm, "\tor $t2, $t0, $t1\n");
                fprintf(f_asm, "\tsw $t2, %d($fp)\n", get_mips_offset(curr->result));
                break;
            }
            // --- 2. Σγκρίσεις (Relational) ---
            case IR_EQ:{
                load_to_reg(curr->arg1, "$t0");
                load_to_reg(curr->arg2, "$t1");
                fprintf(f_asm, "\tseq $t2, $t0, $t1\n"); // 1 αν t0 == t1, αλλιώς 0
                fprintf(f_asm, "\tsw $t2, %d($fp)\n", get_mips_offset(curr->result));
                break;
            }
            case IR_LT:{
                load_to_reg(curr->arg1, "$t0");
                load_to_reg(curr->arg2, "$t1");
                fprintf(f_asm, "\tslt $t2, $t0, $t1\n");
                fprintf(f_asm, "\tsw $t2, %d($fp)\n", get_mips_offset(curr->result));
                break;
            }
            case IR_GT:{
                load_to_reg(curr->arg1, "$t0");
                load_to_reg(curr->arg2, "$t1");
                fprintf(f_asm, "\tsgt $t2, $t0, $t1\n");
                fprintf(f_asm, "\tsw $t2, %d($fp)\n", get_mips_offset(curr->result));
                break;
            }
            case IR_NE:{
                load_to_reg(curr->arg1, "$t0");
                load_to_reg(curr->arg2, "$t1");
                fprintf(f_asm, "\tsne $t2, $t0, $t1\n"); // Set if Not Equal
                fprintf(f_asm, "\tsw $t2, %d($fp)\n", get_mips_offset(curr->result));
                break;
            }
            case IR_GE:{
                load_to_reg(curr->arg1, "$t0");
                load_to_reg(curr->arg2, "$t1");
                fprintf(f_asm, "\tsge $t2, $t0, $t1\n"); // Set if Greater or Equal
                fprintf(f_asm, "\tsw $t2, %d($fp)\n", get_mips_offset(curr->result));
                break;
            }
            case IR_LE:{
                load_to_reg(curr->arg1, "$t0");
                load_to_reg(curr->arg2, "$t1");
                fprintf(f_asm, "\tsle $t2, $t0, $t1\n"); // Set if Less or Equal
                fprintf(f_asm, "\tsw $t2, %d($fp)\n", get_mips_offset(curr->result));
                break;
            }
            // --- 3. Unary Πράξεις ---
            case IR_NEG:{
                load_to_reg(curr->arg1, "$t0");
                fprintf(f_asm, "\tnegu $t2, $t0\n");
                fprintf(f_asm, "\tsw $t2, %d($fp)\n", get_mips_offset(curr->result));
                break;
            }
            case IR_NOT:{
                load_to_reg(curr->arg1, "$t0");
                fprintf(f_asm, "\txori $t2, $t0, 1\n"); // Αντιστροφή 0 <-> 1
                fprintf(f_asm, "\tsw $t2, %d($fp)\n", get_mips_offset(curr->result));
                break;
            }
            // --- 4. Ροή Ελέγχου (Jumps & Branches) ---
            case IR_GOTO:{
                // arg1 είναι ο τύπος OT_LABEL
                fprintf(f_asm, "\tj L%d\n", curr->arg1.val.ival);
                break;
            }
            case IR_IF_FALSE:{
                // Φορτώνουμε τη συνθήκη (arg1)
                load_to_reg(curr->arg1, "$t0");
                // Αν είναι 0 (false), πήδα στο label (arg2)
                fprintf(f_asm, "\tbeqz $t0, L%d\n", curr->arg2.val.ival);
                break;
            }
            // --- 5. Συναρτήσεις ---
            case IR_PARAM:{
                // 1. Φόρτωσε την παράμετρο σε έναν register
                load_to_reg(curr->arg1, "$t0");
                
                // 2. Τοποθέτησέ την στη στοίβα για τη συνάρτηση που θα κληθεί.
                // Οι παράμετροι τοποθετούνται συνήθως σε αρνητικά offsets από το $sp.
                // Ο 1ος θα πάει στο 0($sp), ο 2ος στο -4($sp), κ.ο.κ.
                fprintf(f_asm, "\tsw $t0, -%d($sp)\n", param_count * 4);
                param_count++;
                break;
            }
            case IR_CALL:{
                // 1. Εκτέλεση της κλήσης. Το arg1 περιέχει το όνομα (μέσω του Symbol).
                fprintf(f_asm, "\tjal %s\n", curr->arg1.val.sym->name);
                
                // 2. Μετά την επιστροφή, αποθήκευσε το αποτέλεσμα ($v0) στο result του Quad.
                if (curr->result.type != OT_NONE) {
                    fprintf(f_asm, "\tsw $v0, %d($fp)\n", get_mips_offset(curr->result));
                }
                
                // 3. Μηδενισμός του μετρητή για την επόμενη κλήση
                param_count = 0;
                break;
            }
            // --- 6. Arrays & Pointers ---
            case IR_INDEX: {
                // Εντολή: result = arg1[arg2] 
                // arg1: Base Array, arg2: Byte Offset
                {
                    // 1. Βρες τη διεύθυνση βάσης (Base Address)
                    Symbol *sym = curr->arg1.val.sym;
                    int base_offset = get_mips_offset(curr->arg1);
                    
                    // ΕΛΕΓΧΟΣ: Είναι τοπικός πίνακας ή δείκτης/παράμετρος;
                    if (curr->arg1.type == OT_VAR && sym->type && sym->type->kind == TYPE_ARRAY) {
                        // Περίπτωση 1: Τοπικός Πίνακας -> Η διεύθυνση είναι $fp + offset
                        fprintf(f_asm, "\taddiu $t0, $fp, %d\n", base_offset);
                    } else {
                        // Περίπτωση 2: Δείκτης ή Temp -> Η διεύθυνση είναι η τιμή που περιέχει
                        load_to_reg(curr->arg1, "$t0");
                    }

                    // 2. Φόρτωσε το Offset (που υπολόγισες στο IR)
                    load_to_reg(curr->arg2, "$t1");

                    // 3. Υπολόγισε την τελική διεύθυνση: $t2 = Base + Offset
                    fprintf(f_asm, "\tadd $t2, $t0, $t1\n");

                    // 4. Φόρτωσε την τιμή από τη μνήμη: result = *($t2)
                    fprintf(f_asm, "\tlw $t3, 0($t2)\n");
                    fprintf(f_asm, "\tsw $t3, %d($fp)\n", get_mips_offset(curr->result));
                }
                break;
            }
            case IR_SET_INDEX:{
                // Εντολή: result[arg1] = arg2
                // result: Base Array, arg1: Byte Offset, arg2: Value to store
                {
                    // 1. Βρες τη διεύθυνση βάσης (Base Address)
                    Symbol *sym = curr->result.val.sym;
                    int base_offset = get_mips_offset(curr->result);

                    if (curr->result.type == OT_VAR && sym->type && sym->type->kind == TYPE_ARRAY) {
                        fprintf(f_asm, "\taddiu $t0, $fp, %d\n", base_offset);
                    } else {
                        load_to_reg(curr->result, "$t0");
                    }

                    // 2. Φόρτωσε το Offset
                    load_to_reg(curr->arg1, "$t1");

                    // 3. Υπολόγισε την τελική διεύθυνση: $t2 = Base + Offset
                    fprintf(f_asm, "\tadd $t2, $t0, $t1\n");

                    // 4. Φόρτωσε την τιμή που θέλουμε να αποθηκεύσουμε (RHS)
                    load_to_reg(curr->arg2, "$t3");

                    // 5. Αποθήκευσε στη μνήμη: *($t2) = value
                    fprintf(f_asm, "\tsw $t3, 0($t2)\n");
                }
                break;
            }
            // --- Helper: Load Address (&variable) ---
            case IR_LOAD_ADDR:{
                if (is_global(curr->arg1)) {
                    fprintf(f_asm, "\tla $t0, _%s\n", curr->arg1.val.sym->name);
                } else {
                    int offset = get_mips_offset(curr->arg1);
                    fprintf(f_asm, "\taddiu $t0, $fp, %d\n", offset);
                }
                store_result(curr->result, "$t0", 0);
                break;
            }
            // --- 7. Classes: Fields Access ---
            case IR_GET_FIELD:{
                // Εντολή: result = base_addr.(+offset)
                // arg1: Διεύθυνση βάσης (δείκτης), arg2: Σταθερό offset
                {
                    // 1. Φόρτωσε τη διεύθυνση βάσης στον $t0
                    load_to_reg(curr->arg1, "$t0");

                    // 2. Το offset είναι ακέραιος στο arg2
                    int offset = curr->arg2.val.ival;

                    // 3. Φόρτωσε την τιμή από τη μνήμη: $t1 = *(base + offset)
                    fprintf(f_asm, "\tlw $t1, %d($t0)\n", offset);

                    // 4. Αποθήκευσε το αποτέλεσμα στη στοίβα του caller
                    fprintf(f_asm, "\tsw $t1, %d($fp)\n", get_mips_offset(curr->result));
                }
                break;
            }
            case IR_SET_FIELD:{
                // Εντολή: base_addr.(+offset) = value
                // arg1: Διεύθυνση βάσης, arg2: Offset, result: Η τιμή προς αποθήκευση
                {
                    // 1. Φόρτωσε τη διεύθυνση βάσης στον $t0
                    load_to_reg(curr->arg1, "$t0");

                    // 2. Φόρτωσε την τιμή που θέλουμε να γράψουμε στον $t1
                    load_to_reg(curr->result, "$t1");

                    // 3. Το offset είναι ακέραιος στο arg2
                    int offset = curr->arg2.val.ival;

                    // 4. Αποθήκευσε στη μνήμη: *(base + offset) = value
                    fprintf(f_asm, "\tsw $t1, %d($t0)\n", offset);
                }
                break;
            }
            //-- typecasting --
            case IR_CVT_I2F:{ // Int to Float
                load_to_reg(curr->arg1, "$t0");
                fprintf(f_asm, "\tmtc1 $t0, $f0\n");    // Μεταφορά στον coprocessor 1
                fprintf(f_asm, "\tcvt.s.w $f0, $f0\n"); // Μετατροπή Word σε Single precision
                store_result(curr->result, "$f0", 1);
                break;
            }
            case IR_CVT_F2I:{ // Float to Int
                load_to_freg(curr->arg1, "$f0");
                fprintf(f_asm, "\tcvt.w.s $f0, $f0\n"); // Μετατροπή Single σε Word
                fprintf(f_asm, "\tmfc1 $t0, $f0\n");    // Μεταφορά πίσω σε CPU register
                store_result(curr->result, "$t0", 0);
                break;
            }
            //-- βασικές εντολές --
            case IR_ASSIGN:{
                if (curr->arg1.type == OT_CONST_FLOAT) {
                    load_to_freg(curr->arg1, "$f0");
                    store_result(curr->result, "$f0", 1);
                } else {
                    load_to_reg(curr->arg1, "$t0");
                    store_result(curr->result, "$t0", 0);
                }
                break;
            }
            case IR_PRINT:{
                if (curr->arg1.type == OT_CONST_STR) {
                    fprintf(f_asm, "\tli $v0, 4\n");
                    fprintf(f_asm, "\tla $a0, %s\n", curr->arg1.val.sval);
                    fprintf(f_asm, "\tsyscall\n");
                } else if (curr->arg1.type == OT_CONST_FLOAT) {
                     fprintf(f_asm, "\tli $v0, 2\n"); // Syscall print_float
                     load_to_freg(curr->arg1, "$f12"); // Ο MIPS θέλει το float argument στον $f12
                     fprintf(f_asm, "\tsyscall\n");
                } else {
                    // Default int
                    fprintf(f_asm, "\tli $v0, 1\n");
                    load_to_reg(curr->arg1, "$a0");
                    fprintf(f_asm, "\tsyscall\n");
                }
                // Εκτύπωση newline
                fprintf(f_asm, "\tli $v0, 4\n\tla $a0, newline\n\tsyscall\n");
                break;
            }
            case IR_READ:{
                fprintf(f_asm, "\tli $v0, 5\n"); // Read integer syscall
                fprintf(f_asm, "\tsyscall\n");
                fprintf(f_asm, "\tsw $v0, %d($fp)\n", get_mips_offset(curr->result));
                break;
            }
            case IR_RETURN:{
                if (curr->arg1.type != OT_NONE) {
                    load_to_reg(curr->arg1, "$v0"); // Το αποτέλεσμα επιστρέφει πάντα στον $v0
                }
                mips_epilogue(current_local_size);
                break;
            }
        }
        curr = curr->next;
    }
}