.data
newline: .asciiz "\n"

# --- Global Variables ---
_A::go: .space 4
_C::mine: .space 4
_main: .space 4

.text
.globl main
L1:

# --- Prologue for A::go ---
A::go:
	addiu $sp, $sp, -64
	sw $ra, 60($sp)
	sw $fp, 56($sp)
	addiu $fp, $sp, 56
	lw $t0, 12($fp)
	sw $t0, 16($fp)
	lw $t0, 12($fp)
	move $t3, $t0
	lw $t0, 12($fp)
	li $t1, 1
	add $t2, $t0, $t1
	move $t4, $t2
	move $t0, $t4
	sw $t0, 12($fp)
	move $v0, $t3

# --- Epilogue ---
	lw $ra, 60($sp)
	lw $fp, 56($sp)
	addiu $sp, $sp, 64
	jr $ra
L2:

# --- Prologue for C::mine ---
C::mine:
	addiu $sp, $sp, -64
	sw $ra, 60($sp)
	sw $fp, 56($sp)
	addiu $fp, $sp, 56
	lw $t0, 12($fp)
	lw $t1, 16($fp)
	add $t2, $t0, $t1
	move $t3, $t2
	move $t0, $t3
	mtc1 $t0, $f0
	cvt.s.w $f0, $f0
	mov.s $f4, $f0
	mov.s $f0, $f4
	s.s $f0, 20($fp)
	lw $t0, 12($fp)
	move $t3, $t0
	lw $t0, 12($fp)
	li $t1, 1
	sub $t2, $t0, $t1
	move $t4, $t2
	move $t0, $t4
	sw $t0, 12($fp)
	move $t0, $t3
	sw $t0, 16($fp)
	l.s $f0, 20($fp)

# --- Epilogue ---
	lw $ra, 60($sp)
	lw $fp, 56($sp)
	addiu $sp, $sp, 64
	jr $ra
L3:

# --- Prologue for main ---
main:
	addiu $sp, $sp, -932
	sw $ra, 928($sp)
	sw $fp, 924($sp)
	addiu $fp, $sp, 924
	addiu $t0, $fp, -848
	move $t3, $t0
	move $t0, $t3
	sw $t0, -0($sp)
	lw $t0, -860($fp)
	sw $t0, -4($sp)
	addiu $t0, $fp, -864
	move $t3, $t0
	move $t0, $t3
	sw $t0, -8($sp)
	lw $t0, -868($fp)
	sw $t0, -12($sp)
	jal C::mine
	sw $v0, -912($fp)
	l.s $f0, -912($fp)
	s.s $f0, -868($fp)
	addiu $t0, $fp, -20
	move $t3, $t0
	move $t0, $t3
	sw $t0, -0($sp)
	lw $t0, -860($fp)
	sw $t0, -4($sp)
	addiu $t0, $fp, -864
	move $t3, $t0
	move $t0, $t3
	sw $t0, -8($sp)
	jal A::go
	sw $v0, -924($fp)
	lw $t0, -924($fp)
	sw $t0, -864($fp)
	li $v0, 0

# --- Epilogue ---
	lw $ra, 928($sp)
	lw $fp, 924($sp)
	addiu $sp, $sp, 932
	jr $ra

# Exit program
	li $v0, 10
	syscall
