.data
newline: .asciiz "\n"
_str_1: .asciiz "--- Test 1 Results ---\n"
_str_2: .asciiz "Total sum (Expected 30): "
_str_3: .asciiz "\n"
_str_4: .asciiz "Average (Expected 6.0): "
_str_5: .asciiz "Modified local_arr[0] (Expected 2): "
_str_6: .asciiz "Matrix[1][2] (Expected 3): "

# --- Global Variables ---
_process_data: .space 4
_main: .space 4
_matrix: .space 24

.text
.globl main
L1:

# --- Prologue for process_data ---
process_data:
	addiu $sp, $sp, -68
	sw $ra, 64($sp)
	sw $fp, 60($sp)
	addiu $fp, $sp, 60
	li $t0, 0
	sw $t0, 32($fp)
	li $t0, 0
	sw $t0, -4($fp)
L2:
	lw $t0, -4($fp)
	li $t1, 5
	slt $t2, $t0, $t1
	move $t3, $t2
	move $t0, $t3
	beqz $t0, L4
	lw $t0, -4($fp)
	li $t1, 4
	mul $t2, $t0, $t1
	move $t3, $t2
	li $t0, 0
	move $t1, $t3
	add $t2, $t0, $t1
	move $t3, $t2
	addiu $t0, $fp, 8
	move $t1, $t3
	add $t2, $t0, $t1
	lw $t3, 0($t2)
	sw $t3, -28($fp)
	lw $t0, -28($fp)
	lw $t1, 28($fp)
	mul $t2, $t0, $t1
	move $t3, $t2
	lw $t0, -4($fp)
	li $t1, 4
	mul $t2, $t0, $t1
	move $t4, $t2
	li $t0, 0
	move $t1, $t4
	add $t2, $t0, $t1
	move $t4, $t2
	addiu $t0, $fp, 8
	move $t1, $t4
	add $t2, $t0, $t1
	move $t3, $t3
	sw $t3, 0($t2)
	lw $t0, -4($fp)
	li $t1, 4
	mul $t2, $t0, $t1
	move $t3, $t2
	li $t0, 0
	move $t1, $t3
	add $t2, $t0, $t1
	move $t3, $t2
	addiu $t0, $fp, 8
	move $t1, $t3
	add $t2, $t0, $t1
	lw $t3, 0($t2)
	sw $t3, -52($fp)
	lw $t0, 32($fp)
	lw $t1, -52($fp)
	add $t2, $t0, $t1
	move $t3, $t2
	move $t0, $t3
	sw $t0, 32($fp)
L3:
	lw $t0, -4($fp)
	move $t3, $t0
	lw $t0, -4($fp)
	li $t1, 1
	add $t2, $t0, $t1
	move $t4, $t2
	move $t0, $t4
	sw $t0, -4($fp)
	j L2
L4:
	lw $t0, 32($fp)
	mtc1 $t0, $f0
	cvt.s.w $f0, $f0
	mov.s $f4, $f0
	mov.s $f0, $f4
	li.s $f1, 5.000000
	div.s $f2, $f0, $f1
	mov.s $f4, $f2
	mov.s $f0, $f4
	s.s $f0, 36($fp)
	li $v0, 0

# --- Epilogue ---
	lw $ra, 64($sp)
	lw $fp, 60($sp)
	addiu $sp, $sp, 68
	jr $ra
L5:

# --- Prologue for main ---
main:
	addiu $sp, $sp, -100
	sw $ra, 96($sp)
	sw $fp, 92($sp)
	addiu $fp, $sp, 92
	li $t0, 0
	sw $t0, -24($fp)
L6:
	lw $t0, -24($fp)
	li $t1, 5
	slt $t2, $t0, $t1
	move $t3, $t2
	move $t0, $t3
	beqz $t0, L8
	lw $t0, -24($fp)
	li $t1, 1
	add $t2, $t0, $t1
	move $t3, $t2
	lw $t0, -24($fp)
	li $t1, 4
	mul $t2, $t0, $t1
	move $t4, $t2
	li $t0, 0
	move $t1, $t4
	add $t2, $t0, $t1
	move $t4, $t2
	addiu $t0, $fp, -20
	move $t1, $t4
	add $t2, $t0, $t1
	move $t3, $t3
	sw $t3, 0($t2)
L7:
	lw $t0, -24($fp)
	move $t3, $t0
	lw $t0, -24($fp)
	li $t1, 1
	add $t2, $t0, $t1
	move $t4, $t2
	move $t0, $t4
	sw $t0, -24($fp)
	j L6
L8:
	li $t0, 0
	sw $t0, -24($fp)
L9:
	lw $t0, -24($fp)
	li $t1, 2
	slt $t2, $t0, $t1
	move $t4, $t2
	move $t0, $t4
	beqz $t0, L11
	li $t0, 0
	sw $t0, -28($fp)
L12:
	lw $t0, -28($fp)
	li $t1, 3
	slt $t2, $t0, $t1
	move $t4, $t2
	move $t0, $t4
	beqz $t0, L14
	lw $t0, -24($fp)
	lw $t1, -28($fp)
	add $t2, $t0, $t1
	move $t4, $t2
	lw $t0, -28($fp)
	li $t1, 4
	mul $t2, $t0, $t1
	move $t5, $t2
	li $t0, 0
	move $t1, $t5
	add $t2, $t0, $t1
	move $t5, $t2
	lw $t0, -24($fp)
	li $t1, 12
	mul $t2, $t0, $t1
	move $t6, $t2
	move $t0, $t5
	move $t1, $t6
	add $t2, $t0, $t1
	move $t5, $t2
	addiu $t0, $fp, 0
	move $t1, $t5
	add $t2, $t0, $t1
	move $t3, $t4
	sw $t3, 0($t2)
L13:
	lw $t0, -28($fp)
	move $t4, $t0
	lw $t0, -28($fp)
	li $t1, 1
	add $t2, $t0, $t1
	move $t5, $t2
	move $t0, $t5
	sw $t0, -28($fp)
	j L12
L14:
L10:
	lw $t0, -24($fp)
	move $t5, $t0
	lw $t0, -24($fp)
	li $t1, 1
	add $t2, $t0, $t1
	move $t6, $t2
	move $t0, $t6
	sw $t0, -24($fp)
	j L9
L11:
	li $t0, 0
	sw $t0, -32($fp)
	li.s $f0, 0.000000
	s.s $f0, -36($fp)
	addiu $t0, $fp, -20
	move $t6, $t0
	move $t0, $t6
	sw $t0, -0($sp)
	li $t0, 2
	sw $t0, -4($sp)
	addiu $t0, $fp, -32
	move $t6, $t0
	move $t0, $t6
	sw $t0, -8($sp)
	addiu $t0, $fp, -36
	move $t6, $t0
	move $t0, $t6
	sw $t0, -12($sp)
	jal process_data
	sw $v0, -188($fp)
	li $v0, 4
	la $a0, _str_1
	syscall
	li $v0, 4
	la $a0, _str_2
	syscall
	li $v0, 1
	lw $a0, -32($fp)
	syscall
	li $v0, 4
	la $a0, _str_3
	syscall
	li $v0, 4
	la $a0, _str_4
	syscall
	li $v0, 2
	l.s $f12, -36($fp)
	syscall
	li $v0, 4
	la $a0, _str_3
	syscall
	li $v0, 4
	la $a0, _str_5
	syscall
	li $t0, 0
	li $t1, 4
	mul $t2, $t0, $t1
	move $t6, $t2
	li $t0, 0
	move $t1, $t6
	add $t2, $t0, $t1
	move $t6, $t2
	addiu $t0, $fp, -20
	move $t1, $t6
	add $t2, $t0, $t1
	lw $t3, 0($t2)
	sw $t3, -200($fp)
	li $v0, 1
	lw $a0, -200($fp)
	syscall
	li $v0, 4
	la $a0, _str_3
	syscall
	li $v0, 4
	la $a0, _str_6
	syscall
	li $t0, 2
	li $t1, 4
	mul $t2, $t0, $t1
	move $t6, $t2
	li $t0, 0
	move $t1, $t6
	add $t2, $t0, $t1
	move $t6, $t2
	li $t0, 1
	li $t1, 12
	mul $t2, $t0, $t1
	move $t7, $t2
	move $t0, $t6
	move $t1, $t7
	add $t2, $t0, $t1
	move $t6, $t2
	addiu $t0, $fp, 0
	move $t1, $t6
	add $t2, $t0, $t1
	lw $t3, 0($t2)
	sw $t3, -220($fp)
	li $v0, 1
	lw $a0, -220($fp)
	syscall
	li $v0, 4
	la $a0, _str_3
	syscall
	li $v0, 0

# --- Epilogue ---
	lw $ra, 96($sp)
	lw $fp, 92($sp)
	addiu $sp, $sp, 100
	jr $ra

# Exit program
	li $v0, 10
	syscall
