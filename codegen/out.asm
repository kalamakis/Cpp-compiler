.data
.align 2
newline: .asciiz "\n"
.text
.globl main

# --- Prologue for main ---
main:
	addiu $sp, $sp, -52
	sw $ra, 48($sp)
	sw $fp, 44($sp)
	addiu $fp, $sp, 44
	# --- CONS (New List Node) ---
	li $v0, 9
	li $a0, 8
	syscall
	move $t2, $v0
	li $t0, 20
	sw $t0, 0($t2)
	li $t1, 0
	sw $t1, 4($t2)
	sw $t2, -24($fp)
	# --- CONS (New List Node) ---
	li $v0, 9
	li $a0, 8
	syscall
	move $t2, $v0
	li $t0, 10
	sw $t0, 0($t2)
	lw $t1, -24($fp)
	sw $t1, 4($t2)
	sw $t2, -28($fp)
	lw $t0, -28($fp)
	sw $t0, -4($fp)
	# --- CAR ---
	lw $t0, -4($fp)
	lw $t1, 0($t0)
	sw $t1, -32($fp)
	lw $t0, -32($fp)
	sw $t0, -8($fp)
	lw $a0, -8($fp)
	li $v0, 1
	syscall
	# --- CDR ---
	lw $t0, -4($fp)
	lw $t1, 4($t0)
	sw $t1, -36($fp)
	lw $t0, -36($fp)
	sw $t0, -12($fp)
	# --- CAR ---
	lw $t0, -12($fp)
	lw $t1, 0($t0)
	sw $t1, -40($fp)
	lw $t0, -40($fp)
	sw $t0, -8($fp)
	lw $a0, -8($fp)
	li $v0, 1
	syscall
	li $v0, 0

# --- Epilogue ---
	lw $ra, 48($sp)
	lw $fp, 44($sp)
	addiu $sp, $sp, 52
	jr $ra

# Exit program
	li $v0, 10
	syscall
