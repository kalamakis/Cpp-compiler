.data
newline: .asciiz "\n"

.text
.globl main

# --- Prologue for main ---
main:
	addiu $sp, $sp, -51
	sw $ra, 47($sp)
	sw $fp, 43($sp)
	addiu $fp, $sp, 43
	sw $t0, -4($fp)
	lw $v0, -4($fp)

# --- Epilogue ---
	lw $ra, 47($sp)
	lw $fp, 43($sp)
	addiu $sp, $sp, 51
	jr $ra

# Exit program
	li $v0, 10
	syscall
