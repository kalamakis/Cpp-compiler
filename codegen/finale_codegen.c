#include <stdio.h>
#include <stdlib.h>
#include "ir.h"
#include "symbol.h"
#include "symbolTable.h"

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
    fprintf(f_asm, ".align 2\n");
    fprintf(f_asm, "newline: .asciiz \"\\n\"\n");
    
    // Strings
    extern StringLiteral *string_head; 
    StringLiteral *curr_str = string_head;
    while (curr_str) {
        fprintf(f_asm, "_str_%d: .asciiz \"%s\"\n", curr_str->id, curr_str->value);
        curr_str = curr_str->next;
    }

    // Global Variables
    extern HASHTBL *g_symtab;
    if (g_symtab) {
        for (hash_size i = 0; i < g_symtab->size; i++) {
            struct hashnode_s *node = g_symtab->nodes[i];
            while (node) {
                Symbol *s = (Symbol *)node->data;
                if (s->scope == 0 && s->kind == SYM_VAR) {
                    fprintf(f_asm, "%s: .word %ld\n", s->name, s->u.c.ival);
                }
                node = node->next;
            }
        }
    }
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

static int current_local_size = 0; // Παρακολουθεί το μέγεθος της τρέχουσας συνάρτησης

int get_mips_offset(IROperand op) {
    if (op.type == OT_VAR) {
        return op.val.sym->offset; // Offsets από το semantics.c
    }
    if (op.type == OT_TEMP) {
        /* Υπολογισμός: -(μέγεθος_τοπικών + 8 bytes για ra/fp + ID_του_temp * 4) */
        return -(current_local_size + 8 + (op.val.ival * 4)); 
    }
    return 0;
}

// --- phase 2: Prologue & Epilogue ---

void mips_prologue(const char *func_name, int local_size) {
    fprintf(f_asm, "\n# --- Prologue for %s ---\n", func_name);
    fprintf(f_asm, "%s:\n", func_name);

    // Εξασφάλιση alignment στα 4 bytes
    if (local_size % 4 != 0) {
        local_size += (4 - (local_size % 4));
    }

    // Τοπικές + 8 (ra, fp) + 32 (ασφάλεια/temps)
    int total_stack = local_size + 40; 
    
    fprintf(f_asm, "\taddiu $sp, $sp, -%d\n", total_stack);
    fprintf(f_asm, "\tsw $ra, %d($sp)\n", total_stack - 4);
    fprintf(f_asm, "\tsw $fp, %d($sp)\n", total_stack - 8);
    fprintf(f_asm, "\taddiu $fp, $sp, %d\n", total_stack - 8);
}

void mips_epilogue(int local_size) {
    // Ίδια ευθυγράμμιση με τον πρόλογο
    if (local_size % 4 != 0) local_size += (4 - (local_size % 4));
    int total_stack = local_size + 40; // Χρήση της ίδιας σταθεράς 40

    fprintf(f_asm, "\n# --- Epilogue ---\n");
    fprintf(f_asm, "\tlw $ra, %d($sp)\n", total_stack - 4);
    fprintf(f_asm, "\tlw $fp, %d($sp)\n", total_stack - 8);
    fprintf(f_asm, "\taddiu $sp, $sp, %d\n", total_stack);
    fprintf(f_asm, "\tjr $ra\n");
}

// --- phase 3: Μετάφραση Quads ---

void load_to_reg(IROperand op, const char *reg) {
    if (op.type == OT_CONST_INT) {
        fprintf(f_asm, "\tli %s, %d\n", reg, op.val.ival);
    } else if (op.type == OT_CONST_STR) {
        fprintf(f_asm, "\tla %s, %s\n", reg, op.val.sval);
    } else if (op.type == OT_VAR) {
        // ΕΛΕΓΧΟΣ: Είναι Global;
        if (op.val.sym->scope == 0) {
            fprintf(f_asm, "\tlw %s, %s\n", reg, op.val.sym->name);
        } else {
            fprintf(f_asm, "\tlw %s, %d($fp)\n", reg, get_mips_offset(op));
        }
    } else if (op.type == OT_TEMP) {
        fprintf(f_asm, "\tlw %s, %d($fp)\n", reg, get_mips_offset(op));
    }
}

void store_from_reg(const char *reg, IROperand result) {
    if (result.type == OT_VAR && result.val.sym->scope == 0) {
        fprintf(f_asm, "\tsw %s, %s\n", reg, result.val.sym->name);
    } else {
        fprintf(f_asm, "\tsw %s, %d($fp)\n", reg, get_mips_offset(result));
    }
}

static int param_count = 0; // Μετρητής παραμέτρων για το IR_PARAM

void generate_mips() {
    fprintf(f_asm, ".text\n.globl main\n");
    Quad *curr = quad_head;
    //int current_frame_size = 0;

    while (curr) {
        switch(curr->op) {
            case IR_LABEL: {
                if (curr->label_id == -1) {
                    Symbol *func_sym = curr->arg1.val.sym; // Πλέον είναι έγκυρο Symbol*
                    
                    // Το όνομα το παίρνουμε από το func_sym->name
                    const char* name = (func_sym) ? func_sym->name : "unknown";
                    
                    // Το offset είναι πλέον το πραγματικό από το Semantics
                    current_local_size = (func_sym) ? func_sym->offset : 32;
                    
                    mips_prologue(name, current_local_size);
                } else {
                    // ΠΡΟΣΘΗΚΗ: Τύπωσε τις απλές ετικέτες αλμάτων (π.χ. L1:)
                    fprintf(f_asm, "L%d:\n", curr->label_id);
                }
                break; 
            }
            // --- 1. Αριθμητικές/Λογικες Πράξεις ---
            case IR_ADD:{
                load_to_reg(curr->arg1, "$t0");
                load_to_reg(curr->arg2, "$t1");
                fprintf(f_asm, "\tadd $t2, $t0, $t1\n");
                fprintf(f_asm, "\tsw $t2, %d($fp)\n", get_mips_offset(curr->result));
                break;
            }
            case IR_SUB:{
                load_to_reg(curr->arg1, "$t0");
                load_to_reg(curr->arg2, "$t1");
                fprintf(f_asm, "\tsub $t2, $t0, $t1\n");
                fprintf(f_asm, "\tsw $t2, %d($fp)\n", get_mips_offset(curr->result));
                break;
            }
            case IR_MUL:{
                load_to_reg(curr->arg1, "$t0");
                load_to_reg(curr->arg2, "$t1");
                fprintf(f_asm, "\tmul $t2, $t0, $t1\n");
                fprintf(f_asm, "\tsw $t2, %d($fp)\n", get_mips_offset(curr->result));
                break;
            }
            case IR_DIV:{
                load_to_reg(curr->arg1, "$t0");
                load_to_reg(curr->arg2, "$t1");
                fprintf(f_asm, "\tdiv $t0, $t1\n");
                fprintf(f_asm, "\tmflo $t2\n"); // Το πηλίκο μπαίνει στο $t2
                fprintf(f_asm, "\tsw $t2, %d($fp)\n", get_mips_offset(curr->result));
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
            case IR_IF: {
                // Αν η συνθήκη (arg1) ΔΕΝ είναι 0 (True), πήδα στο label (arg2)
                load_to_reg(curr->arg1, "$t0");
                fprintf(f_asm, "\tbnez $t0, L%d\n", curr->arg2.val.ival);
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
            case IR_LOAD_ADDR: {
                if (curr->arg1.type == OT_VAR && curr->arg1.val.sym->scope == 0) {
                    fprintf(f_asm, "\tla $t0, %s\n", curr->arg1.val.sym->name);
                } else {
                    int offset = get_mips_offset(curr->arg1);
                    fprintf(f_asm, "\taddiu $t0, $fp, %d\n", offset);
                }
                store_from_reg("$t0", curr->result);
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
            case IR_CVT_I2F: {
                // Int -> Float
                load_to_reg(curr->arg1, "$t0");     // Φόρτωση Int στον $t0
                fprintf(f_asm, "\tmtc1 $t0, $f0\n"); // Μεταφορά στον float reg $f0
                fprintf(f_asm, "\tcvt.s.w $f0, $f0\n"); // Convert Integer Word to Single Precision
                fprintf(f_asm, "\tmfc1 $t1, $f0\n"); // Επιστροφή των bits του float στον $t1
                fprintf(f_asm, "\tsw $t1, %d($fp)\n", get_mips_offset(curr->result));
                break;
            }
            case IR_CVT_F2I: {
                // Float -> Int
                load_to_reg(curr->arg1, "$t0");     // Φόρτωση Float bits στον $t0
                fprintf(f_asm, "\tmtc1 $t0, $f0\n"); // Μεταφορά στον $f0
                fprintf(f_asm, "\tcvt.w.s $f0, $f0\n"); // Convert Single Precision to Integer Word
                fprintf(f_asm, "\tmfc1 $t1, $f0\n"); // Επιστροφή του int στον $t1
                fprintf(f_asm, "\tsw $t1, %d($fp)\n", get_mips_offset(curr->result));
                break;
            }
            //-- βασικές εντολές --
            case IR_ASSIGN:{
                load_to_reg(curr->arg1, "$t0");
                fprintf(f_asm, "\tsw $t0, %d($fp)\n", get_mips_offset(curr->result));
                break;
            }
            case IR_PRINT: {
                if (curr->arg1.type == OT_CONST_STR) {
                    // String Literal
                    fprintf(f_asm, "\tli $v0, 4\n");
                    fprintf(f_asm, "\tla $a0, %s\n", curr->arg1.val.sval);
                    fprintf(f_asm, "\tsyscall\n");
                } 
                else if (curr->arg1.type == OT_CONST_FLOAT || 
                        (curr->arg1.type == OT_VAR && curr->arg1.val.sym->type && curr->arg1.val.sym->type->kind == TYPE_FLOAT)) {
                    // Float Print (Syscall 2)
                    // Ο MIPS περιμένει το float στον $f12
                    load_to_reg(curr->arg1, "$t0");      // Φόρτωση bits στον $t0
                    fprintf(f_asm, "\tmtc1 $t0, $f12\n"); // Μεταφορά στον $f12
                    fprintf(f_asm, "\tli $v0, 2\n");
                    fprintf(f_asm, "\tsyscall\n");
                } 
                else {
                    // Int Print (Syscall 1) - Default
                    load_to_reg(curr->arg1, "$a0");
                    fprintf(f_asm, "\tli $v0, 1\n");
                    fprintf(f_asm, "\tsyscall\n");
                }
                
                // Newline
                // fprintf(f_asm, "\tli $v0, 4\n\tla $a0, newline\n\tsyscall\n");
                break;
            }
            case IR_READ: {
                // Ελέγχουμε αν το αποτέλεσμα προορίζεται για Float
                if (curr->result.type == OT_VAR && curr->result.val.sym->type && curr->result.val.sym->type->kind == TYPE_FLOAT) {
                    fprintf(f_asm, "\tli $v0, 6\n"); // Read Float
                    fprintf(f_asm, "\tsyscall\n");   // Το αποτέλεσμα μπαίνει στον $f0
                    fprintf(f_asm, "\tmfc1 $t0, $f0\n"); // Μεταφορά στον $t0
                    fprintf(f_asm, "\tsw $t0, %d($fp)\n", get_mips_offset(curr->result));
                } else {
                    fprintf(f_asm, "\tli $v0, 5\n"); // Read Integer
                    fprintf(f_asm, "\tsyscall\n");   // Το αποτέλεσμα μπαίνει στον $v0
                    fprintf(f_asm, "\tsw $v0, %d($fp)\n", get_mips_offset(curr->result));
                }
                break;
            }
            case IR_RETURN: {
                if (curr->arg1.type != OT_NONE) {
                    load_to_reg(curr->arg1, "$v0"); 
                }
                mips_epilogue(current_local_size); 
                break;
            }

            /*LIST OPERATIONS*/
            case IR_CONS: {  
                fprintf(f_asm, "\t# --- CONS (New List Node) ---\n");
                
                // 1. Δέσμευση 8 bytes (Heap Allocation)
                fprintf(f_asm, "\tli $v0, 9\n");     
                fprintf(f_asm, "\tli $a0, 8\n");     
                fprintf(f_asm, "\tsyscall\n");       
                
                // Μεταφορά της διεύθυνσης στον $t2
                fprintf(f_asm, "\tmove $t2, $v0\n");

                // 2. Αποθήκευση Head (arg1) στο offset 0
                load_to_reg(curr->arg1, "$t0");       
                fprintf(f_asm, "\tsw $t0, 0($t2)\n"); 

                // 3. Αποθήκευση Tail (arg2) στο offset 4
                load_to_reg(curr->arg2, "$t1");       
                fprintf(f_asm, "\tsw $t1, 4($t2)\n"); 

                // 4. Αποθήκευση του δείκτη (result) στη στοίβα (local var / temp)
                fprintf(f_asm, "\tsw $t2, %d($fp)\n", get_mips_offset(curr->result));
                break;
            }

            case IR_CAR: {
                // Εντολή: result = CAR(arg1)
                fprintf(f_asm, "\t# --- CAR ---\n");

                // 1. Φόρτωση της διεύθυνσης της λίστας
                load_to_reg(curr->arg1, "$t0");
                
                // 2. Φόρτωση του Head από το offset 0
                fprintf(f_asm, "\tlw $t1, 0($t0)\n");
                
                // 3. Αποθήκευση αποτελέσματος
                fprintf(f_asm, "\tsw $t1, %d($fp)\n", get_mips_offset(curr->result));
                break;
            }

            case IR_CDR: {
                // Εντολή: result = CDR(arg1)
                fprintf(f_asm, "\t# --- CDR ---\n");

                // 1. Φόρτωση της διεύθυνσης της λίστας
                load_to_reg(curr->arg1, "$t0");
                
                // 2. Φόρτωση του Tail από το offset 4
                fprintf(f_asm, "\tlw $t1, 4($t0)\n");
                
                // 3. Αποθήκευση αποτελέσματος
                fprintf(f_asm, "\tsw $t1, %d($fp)\n", get_mips_offset(curr->result));
                break;
            }
        }
        curr = curr->next;
    }
}