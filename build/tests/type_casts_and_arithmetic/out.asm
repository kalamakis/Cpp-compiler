.data
newline: .asciiz "\n"
_str_1: .asciiz "--- Test 2 Results ---\n"
_str_2: .asciiz "Float after addition (Expected 13.14): "
_str_3: .asciiz "\n"
_str_4: .asciiz "Int after truncation (Expected 13): "
_str_5: .asciiz "Compute result (Expected 8.5): "
_str_6: .asciiz "Success: 'A' is less than 'Z'\n"
_str_7: .asciiz "Success: RED is not GREEN\n"
_str_8: .asciiz "Success: Logical AND passed\n"
_str_9: .asciiz "Success: Logical OR passed (j is 13)\n"
_str_10: .asciiz "Success: Logical NOT passed\n"

# --- Global Variables ---
_compute: .space 4
_main: .space 4

.text
.globl main
L1:

# --- Prologue for compute ---
compute:
	addiu $sp, $sp, -68
	sw $ra, 64($sp)
	sw $fp, 60($sp)
	addiu $fp, $sp, 60
	lw $t0, 8($fp)
	mtc1 $t0, $f0
	cvt.s.w $f0, $f0
	mov.s $f4, $f0
	mov.s $f0, $f4
	l.s $f1, 12($fp)
	mul.s $f2, $f0, $f1
	mov.s $f4, $f2
	mov.s $f0, $f4
	li.s $f1, 2.500000
	add.s $f2, $f0, $f1
	mov.s $f4, $f2
	mov.s $f0, $f4
	s.s $f0, -4($fp)
	l.s $f0, -4($fp)

# --- Epilogue ---
	lw $ra, 64($sp)
	lw $fp, 60($sp)
	addiu $sp, $sp, 68
	jr $ra
L2:

# --- Prologue for main ---
main:
	addiu $sp, $sp, -96
	sw $ra, 92($sp)
	sw $fp, 88($sp)
	addiu $fp, $sp, 88
	li $v0, 4
	la $a0, _str_1
	syscall
	li $t0, 10
	sw $t0, -4($fp)
	li.s $f0, 3.140000
	s.s $f0, -12($fp)
	lw $t0, -4($fp)
	mtc1 $t0, $f0
	cvt.s.w $f0, $f0
	mov.s $f4, $f0
	l.s $f0, -12($fp)
	mov.s $f1, $f4
	add.s $f2, $f0, $f1
	mov.s $f4, $f2
	mov.s $f0, $f4
	s.s $f0, -12($fp)
	l.s $f0, -12($fp)
	cvt.w.s $f0, $f0
	mfc1 $t0, $f0
	move $t3, $t0
	move $t0, $t3
	sw $t0, -8($fp)
	li $v0, 4
	la $a0, _str_2
	syscall
	li $v0, 2
	l.s $f12, -12($fp)
	syscall
	li $v0, 4
	la $a0, _str_3
	syscall
	li $v0, 4
	la $a0, _str_4
	syscall
	li $v0, 1
	lw $a0, -8($fp)
	syscall
	li $v0, 4
	la $a0, _str_3
	syscall
	li $t0, 5
	sw $t0, -0($sp)
	sw $t0, -4($sp)
	jal compute
	sw $v0, -68($fp)
	l.s $f0, -68($fp)
	s.s $f0, -16($fp)
	li $v0, 4
	la $a0, _str_5
	syscall
	li $v0, 2
	l.s $f12, -16($fp)
	syscall
	li $v0, 4
	la $a0, _str_3
	syscall
	li $t0, 39
	sw $t0, -20($fp)
	li $t0, 39
	sw $t0, -24($fp)
	li $t0, 1
	sw $t0, -28($fp)
	li $t0, 2
	sw $t0, -32($fp)
	lw $t0, -20($fp)
	lw $t1, -24($fp)
	slt $t2, $t0, $t1
	move $t3, $t2
	move $t0, $t3
	beqz $t0, L3
	li $v0, 4
	la $a0, _str_6
	syscall
	j L4
L3:
L4:
	lw $t0, -28($fp)
	lw $t1, -32($fp)
	sne $t2, $t0, $t1
	move $t3, $t2
	move $t0, $t3
	beqz $t0, L5
	li $v0, 4
	la $a0, _str_7
	syscall
	j L6
L5:
L6:
	li $t0, 0
	move $t3, $t0
	lw $t0, -8($fp)
	li $t1, 10
	sgt $t2, $t0, $t1
	move $t4, $t2
	move $t0, $t4
	beqz $t0, L9
	l.s $f0, -12($fp)
	li.s $f1, 5.000000
	c.le.s $f0, $f1
	li $t2, 0
	bc1t 1f
	li $t2, 1
1:
	move $t4, $t2
	move $t0, $t4
	beqz $t0, L9
	li $t0, 1
	move $t3, $t0
L9:
	move $t0, $t3
	beqz $t0, L7
	li $v0, 4
	la $a0, _str_8
	syscall
	j L8
L7:
L8:
	li $t0, 0
	move $t3, $t0
	lw $t0, -4($fp)
	li $t1, 0
	seq $t2, $t0, $t1
	move $t4, $t2
	move $t0, $t4
	beqz $t0, L14
	j L12
L14:
	lw $t0, -8($fp)
	li $t1, 13
	seq $t2, $t0, $t1
	move $t4, $t2
	move $t0, $t4
	beqz $t0, L13
L12:
	li $t0, 1
	move $t3, $t0
L13:
	move $t0, $t3
	beqz $t0, L10
	li $v0, 4
	la $a0, _str_9
	syscall
	j L11
L10:
L11:
	lw $t0, -4($fp)
	li $t1, 0
	seq $t2, $t0, $t1
	move $t3, $t2
	move $t0, $t3
	xori $t2, $t0, 1
	sw $t2, -108($fp)
	lw $t0, -108($fp)
	beqz $t0, L15
	li $v0, 4
	la $a0, _str_10
	syscall
	j L16
L15:
L16:
	li $v0, 0

# --- Epilogue ---
	lw $ra, 92($sp)
	lw $fp, 88($sp)
	addiu $sp, $sp, 96
	jr $ra

# Exit program
	li $v0, 10
	syscall
