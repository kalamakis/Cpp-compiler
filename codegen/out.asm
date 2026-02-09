.data
.align 2
newline: .asciiz "\n"
.text
.globl main

# --- Prologue for main ---
main:
	addiu $sp, $sp, -40
	sw $ra, 36($sp)
	sw $fp, 32($sp)
	addiu $fp, $sp, 32
	li $v0, 0

# --- Epilogue ---
	lw $ra, 36($sp)
	lw $fp, 32($sp)
	addiu $sp, $sp, 40
	jr $ra

# Exit program
	li $v0, 10
	syscall
