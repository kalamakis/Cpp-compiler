.data
newline: .asciiz "\n"
_str_1: .asciiz "CAR (10): "
_str_2: .asciiz " | CADR (20): "
_str_3: .asciiz " | CAR(CDR) (20): "
_str_4: .asciiz " | CAR(CDDR) (30): "

# --- Global Variables ---
_main: .space 4

.text
.globl main
L1:

# --- Prologue for main ---
main:
	addiu $sp, $sp, -88
	sw $ra, 84($sp)
	sw $fp, 80($sp)
	addiu $fp, $sp, 80
	sw $t0, -4($fp)
	# --- CAR ---
	lw $t0, -4($fp)
	lw $t1, 0($t0)
	sw $t1, -36($fp)
	lw $t0, -36($fp)
	sw $t0, -16($fp)
	li $v0, 4
	la $a0, _str_1
	syscall
	li $v0, 1
	lw $a0, -16($fp)
	syscall
	# --- CDR ---
	lw $t0, -4($fp)
	lw $t1, 4($t0)
	sw $t1, -40($fp)
	# --- CAR ---
	lw $t0, -40($fp)
	lw $t1, 0($t0)
	sw $t1, -44($fp)
	lw $t0, -44($fp)
	sw $t0, -20($fp)
	li $v0, 4
	la $a0, _str_2
	syscall
	li $v0, 1
	lw $a0, -20($fp)
	syscall
	# --- CDR ---
	lw $t0, -4($fp)
	lw $t1, 4($t0)
	sw $t1, -48($fp)
	lw $t0, -48($fp)
	sw $t0, -8($fp)
	# --- CAR ---
	lw $t0, -8($fp)
	lw $t1, 0($t0)
	sw $t1, -52($fp)
	lw $t0, -52($fp)
	sw $t0, -20($fp)
	li $v0, 4
	la $a0, _str_3
	syscall
	li $v0, 1
	lw $a0, -20($fp)
	syscall
	# --- CDR ---
	lw $t0, -4($fp)
	lw $t1, 4($t0)
	sw $t1, -56($fp)
	# --- CDR ---
	lw $t0, -56($fp)
	lw $t1, 4($t0)
	sw $t1, -60($fp)
	lw $t0, -60($fp)
	sw $t0, -12($fp)
	# --- CAR ---
	lw $t0, -12($fp)
	lw $t1, 0($t0)
	sw $t1, -64($fp)
	lw $t0, -64($fp)
	sw $t0, -24($fp)
	li $v0, 4
	la $a0, _str_4
	syscall
	li $v0, 1
	lw $a0, -24($fp)
	syscall
	li $v0, 0

# --- Epilogue ---
	lw $ra, 84($sp)
	lw $fp, 80($sp)
	addiu $sp, $sp, 88
	jr $ra

# Exit program
	li $v0, 10
	syscall
