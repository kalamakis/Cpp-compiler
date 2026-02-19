.data
newline: .asciiz "\n"
_str_1: .asciiz "Number x should be 42: "
_str_2: .asciiz " | Float y should be 3.14: "
_str_3: .asciiz " | List Head should be 10: "

# --- Global Variables ---
_main: .space 4

.text
.globl main
L1:

# --- Prologue for main ---
main:
	addiu $sp, $sp, -80
	sw $ra, 76($sp)
	sw $fp, 72($sp)
	addiu $fp, $sp, 72
	li $t0, 42
	sw $t0, -4($fp)
	li.s $f0, 3.140000
	s.s $f0, -8($fp)
	sw $t0, -12($fp)
	# --- CAR ---
	lw $t0, -12($fp)
	lw $t1, 0($t0)
	sw $t1, -28($fp)
	lw $t0, -28($fp)
	sw $t0, -16($fp)
	li $v0, 4
	la $a0, _str_1
	syscall
	li $v0, 1
	lw $a0, -4($fp)
	syscall
	li $v0, 4
	la $a0, _str_2
	syscall
	li $v0, 2
	l.s $f12, -8($fp)
	syscall
	li $v0, 4
	la $a0, _str_3
	syscall
	li $v0, 1
	lw $a0, -16($fp)
	syscall
	li $v0, 0

# --- Epilogue ---
	lw $ra, 76($sp)
	lw $fp, 72($sp)
	addiu $sp, $sp, 80
	jr $ra

# Exit program
	li $v0, 10
	syscall
