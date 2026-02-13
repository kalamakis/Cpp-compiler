.data
newline: .asciiz "\n"
_str_1: .asciiz "Hello "
_str_2: .asciiz "Global counter is: "
_str_3: .asciiz "\n"
_str_4: .asciiz "Pre-inc (++a) : a="
_str_5: .asciiz ", b="
_str_6: .asciiz " (Expected: 6, 6)\n"
_str_7: .asciiz "Post-inc (a++) : a="
_str_8: .asciiz " (Expected: 6, 5)\n"
_str_9: .asciiz "Pre-dec (--a) : a="
_str_10: .asciiz " (Expected: 4, 4)\n"
_str_11: .asciiz "Post-dec (a--) : a="
_str_12: .asciiz " (Expected: 4, 5)\n"
_str_13: .asciiz "World"
_str_14: .asciiz "Concat result  : "
_str_15: .asciiz "Apple"
_str_16: .asciiz "Banana"
_str_17: .asciiz "Success: Apple == Apple\n"
_str_18: .asciiz "FAIL: String == operator\n"
_str_19: .asciiz "Success: Apple != Banana\n"
_str_20: .asciiz "FAIL: String != operator\n"
_str_21: .asciiz "Success: Apple < Banana (A comes before B)\n"
_str_22: .asciiz "FAIL: String < operator\n"
_str_23: .asciiz "Success: Banana > Apple\n"
_str_24: .asciiz "FAIL: String > operator\n"

# --- Global Variables ---
_main: .space 4
_global_counter: .space 4
_global_prefix: .space 256

.text
.globl main
L1:

# --- Prologue for main ---
main:
	addiu $sp, $sp, -1096
	sw $ra, 1092($sp)
	sw $fp, 1088($sp)
	addiu $fp, $sp, 1088
	li $t0, 100
	sw $t0, _global_counter
	la $t0, _str_1
	la $t1, _global_prefix
	li $t4, 256
copy_loop_1:
	blez $t4, copy_end_1
	lbu $t5, 0($t0)
	sb $t5, 0($t1)
	addiu $t0, $t0, 1
	addiu $t1, $t1, 1
	addiu $t4, $t4, -1
	j copy_loop_1
copy_end_1:
	li $v0, 4
	la $a0, _str_2
	syscall
	li $v0, 1
	lw $a0, _global_counter
	syscall
	li $v0, 4
	la $a0, _str_3
	syscall
	li $t0, 5
	sw $t0, -4($fp)
	lw $t0, -4($fp)
	li $t1, 1
	add $t2, $t0, $t1
	sw $t2, -1044($fp)
	lw $t0, -1044($fp)
	sw $t0, -4($fp)
	lw $t0, -4($fp)
	sw $t0, -8($fp)
	li $v0, 4
	la $a0, _str_4
	syscall
	li $v0, 1
	lw $a0, -4($fp)
	syscall
	li $v0, 4
	la $a0, _str_5
	syscall
	li $v0, 1
	lw $a0, -8($fp)
	syscall
	li $v0, 4
	la $a0, _str_6
	syscall
	li $t0, 5
	sw $t0, -4($fp)
	lw $t0, -4($fp)
	sw $t0, -1048($fp)
	lw $t0, -4($fp)
	li $t1, 1
	add $t2, $t0, $t1
	sw $t2, -1052($fp)
	lw $t0, -1052($fp)
	sw $t0, -4($fp)
	lw $t0, -1048($fp)
	sw $t0, -8($fp)
	li $v0, 4
	la $a0, _str_7
	syscall
	li $v0, 1
	lw $a0, -4($fp)
	syscall
	li $v0, 4
	la $a0, _str_5
	syscall
	li $v0, 1
	lw $a0, -8($fp)
	syscall
	li $v0, 4
	la $a0, _str_8
	syscall
	li $t0, 5
	sw $t0, -4($fp)
	lw $t0, -4($fp)
	li $t1, 1
	sub $t2, $t0, $t1
	sw $t2, -1056($fp)
	lw $t0, -1056($fp)
	sw $t0, -4($fp)
	lw $t0, -4($fp)
	sw $t0, -8($fp)
	li $v0, 4
	la $a0, _str_9
	syscall
	li $v0, 1
	lw $a0, -4($fp)
	syscall
	li $v0, 4
	la $a0, _str_5
	syscall
	li $v0, 1
	lw $a0, -8($fp)
	syscall
	li $v0, 4
	la $a0, _str_10
	syscall
	li $t0, 5
	sw $t0, -4($fp)
	lw $t0, -4($fp)
	sw $t0, -1060($fp)
	lw $t0, -4($fp)
	li $t1, 1
	sub $t2, $t0, $t1
	sw $t2, -1064($fp)
	lw $t0, -1064($fp)
	sw $t0, -4($fp)
	lw $t0, -1060($fp)
	sw $t0, -8($fp)
	li $v0, 4
	la $a0, _str_11
	syscall
	li $v0, 1
	lw $a0, -4($fp)
	syscall
	li $v0, 4
	la $a0, _str_5
	syscall
	li $v0, 1
	lw $a0, -8($fp)
	syscall
	li $v0, 4
	la $a0, _str_12
	syscall
	la $t0, _str_13
	addiu $t1, $fp, -264
	li $t4, 256
copy_loop_2:
	blez $t4, copy_end_2
	lbu $t5, 0($t0)
	sb $t5, 0($t1)
	addiu $t0, $t0, 1
	addiu $t1, $t1, 1
	addiu $t4, $t4, -1
	j copy_loop_2
copy_end_2:
	li $v0, 9
	li $a0, 256
	syscall
	sw $v0, -1068($fp)
	move $a0, $v0
	la $a1, _global_prefix
	addiu $a2, $fp, -264
	jal _strcat
	lw $t0, -1068($fp)
	addiu $t1, $fp, -520
	li $t4, 256
copy_loop_3:
	blez $t4, copy_end_3
	lbu $t5, 0($t0)
	sb $t5, 0($t1)
	addiu $t0, $t0, 1
	addiu $t1, $t1, 1
	addiu $t4, $t4, -1
	j copy_loop_3
copy_end_3:
	li $v0, 4
	la $a0, _str_14
	syscall
	li $v0, 4
	addiu $a0, $fp, -520
	syscall
	li $v0, 4
	la $a0, _str_3
	syscall
	la $t0, _str_15
	addiu $t1, $fp, -264
	li $t4, 256
copy_loop_4:
	blez $t4, copy_end_4
	lbu $t5, 0($t0)
	sb $t5, 0($t1)
	addiu $t0, $t0, 1
	addiu $t1, $t1, 1
	addiu $t4, $t4, -1
	j copy_loop_4
copy_end_4:
	la $t0, _str_16
	addiu $t1, $fp, -520
	li $t4, 256
copy_loop_5:
	blez $t4, copy_end_5
	lbu $t5, 0($t0)
	sb $t5, 0($t1)
	addiu $t0, $t0, 1
	addiu $t1, $t1, 1
	addiu $t4, $t4, -1
	j copy_loop_5
copy_end_5:
	la $t0, _str_15
	addiu $t1, $fp, -776
	li $t4, 256
copy_loop_6:
	blez $t4, copy_end_6
	lbu $t5, 0($t0)
	sb $t5, 0($t1)
	addiu $t0, $t0, 1
	addiu $t1, $t1, 1
	addiu $t4, $t4, -1
	j copy_loop_6
copy_end_6:
	addiu $a0, $fp, -264
	addiu $a1, $fp, -776
	jal _strcmp
	seq $t2, $v0, 0
	sw $t2, -1072($fp)
	lw $t0, -1072($fp)
	beqz $t0, L2
	li $v0, 4
	la $a0, _str_17
	syscall
	j L3
L2:
	li $v0, 4
	la $a0, _str_18
	syscall
L3:
	addiu $a0, $fp, -264
	addiu $a1, $fp, -520
	jal _strcmp
	sne $t2, $v0, $zero
	sw $t2, -1076($fp)
	lw $t0, -1076($fp)
	beqz $t0, L4
	li $v0, 4
	la $a0, _str_19
	syscall
	j L5
L4:
	li $v0, 4
	la $a0, _str_20
	syscall
L5:
	addiu $a0, $fp, -264
	addiu $a1, $fp, -520
	jal _strcmp
	slt $t2, $v0, $zero
	sw $t2, -1080($fp)
	lw $t0, -1080($fp)
	beqz $t0, L6
	li $v0, 4
	la $a0, _str_21
	syscall
	j L7
L6:
	li $v0, 4
	la $a0, _str_22
	syscall
L7:
	addiu $a0, $fp, -520
	addiu $a1, $fp, -264
	jal _strcmp
	sgt $t2, $v0, $zero
	sw $t2, -1084($fp)
	lw $t0, -1084($fp)
	beqz $t0, L8
	li $v0, 4
	la $a0, _str_23
	syscall
	j L9
L8:
	li $v0, 4
	la $a0, _str_24
	syscall
L9:
	li $v0, 0

# --- Epilogue ---
	lw $ra, 1092($sp)
	lw $fp, 1088($sp)
	addiu $sp, $sp, 1096
	jr $ra

# Exit program
	li $v0, 10
	syscall

# Built-in strcmp (a0=str1, a1=str2, v0=result)
_strcmp:
1:	lbu $t0, 0($a0)
	lbu $t1, 0($a1)
	bne $t0, $t1, 2f
	beq $t0, $zero, 3f
	addiu $a0, $a0, 1
	addiu $a1, $a1, 1
	j 1b
2:	sub $v0, $t0, $t1
	jr $ra
3:	li $v0, 0
	jr $ra

# Built-in strcat (a0=dest, a1=src1, a2=src2)
_strcat:
	move $t0, $a0
1:	lbu $t1, 0($a1)
	beq $t1, $zero, 2f
	sb $t1, 0($t0)
	addiu $a1, $a1, 1
	addiu $t0, $t0, 1
	j 1b
2:	lbu $t1, 0($a2)
	sb $t1, 0($t0)
	beq $t1, $zero, 3f
	addiu $a2, $a2, 1
	addiu $t0, $t0, 1
	j 2b
3:	jr $ra
