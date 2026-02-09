.data
newline: .asciiz "\n"

.text
.globl main

# --- Prologue for main ---
main:
	addiu $sp, $sp, -1847599162
	sw $ra, 1847599158($sp)
	sw $fp, 1847599154($sp)
	addiu $fp, $sp, 1847599154
	li $v0, 0

# --- Epilogue ---
	lw $ra, 1847599158($sp)
	lw $fp, 1847599154($sp)
	addiu $sp, $sp, 1847599162
	jr $ra

# Exit program
	li $v0, 10
	syscall
