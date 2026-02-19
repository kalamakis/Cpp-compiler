#ifndef MIPS_CODEGEN_H
#define MIPS_CODEGEN_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "ir.h"      // for IROperand, Quad, etc.
#include "symbol.h"  // for Symbol, types, etc.
#include "semantics.h"

/*
 * Public output stream used by the backend.
 * Defined in the .c file.
 */
extern FILE *f_asm;

/* ---- Register allocation / temp mapping ---- */
const char* allocate_reg(int temp_id, int is_float);
void free_temp_reg(int temp_id);

/* ---- Phase 0: init / sections / finish ---- */
void mips_init(const char *filename);
void mips_data_section(void);
void mips_finish(void);

/* ---- Phase 1: temps / memory model ---- */
int  get_mips_offset(IROperand op);
int  is_global(IROperand op);

/* ---- Prologue / epilogue ---- */
void mips_prologue(const char *func_name, int local_size);
void mips_epilogue(int local_size);

/* ---- Load / store helpers ---- */
void load_to_reg(IROperand op, const char *reg);
void load_to_freg(IROperand op, const char *reg);
void load_addr_to_reg(IROperand op, const char *reg);

void store_result(IROperand res, const char *reg, int is_float);

/* ---- Struct/array/string block copy helper ---- */
void emit_memcpy(const char *dest_reg, const char *src_reg, int size);

/* ---- Main codegen ---- */
void generate_mips(void);

#ifdef __cplusplus
}
#endif

#endif /* MIPS_CODEGEN_H */
