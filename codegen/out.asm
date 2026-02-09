.data
.align 2
newline: .asciiz "\n"
_str_1: .asciiz "varoufakis: "
varoufakis: .word 42
.text
.globl main

# --- Prologue for Shape::set_id ---
Shape::set_id:
	addiu $sp, $sp, -40
	sw $ra, 36($sp)
	sw $fp, 32($sp)
	addiu $fp, $sp, 32
	lw $t0, 8($fp)
	lw $t1, 12($fp)
	sw $t1, 0($t0)

# --- Epilogue ---
	lw $ra, 36($sp)
	lw $fp, 32($sp)
	addiu $sp, $sp, 40
	jr $ra

# --- Prologue for Rectangle::init_rect ---
Rectangle::init_rect:
	addiu $sp, $sp, -40
	sw $ra, 36($sp)
	sw $fp, 32($sp)
	addiu $fp, $sp, 32
	lw $t0, 8($fp)
	lw $t1, 12($fp)
	sw $t1, 0($t0)
	lw $t0, 8($fp)
	lw $t1, 16($fp)
	sw $t1, 4($t0)
	lw $t0, 8($fp)
	lw $t1, 20($fp)
	sw $t1, 8($t0)

# --- Epilogue ---
	lw $ra, 36($sp)
	lw $fp, 32($sp)
	addiu $sp, $sp, 40
	jr $ra

# --- Prologue for Rectangle::area ---
Rectangle::area:
	addiu $sp, $sp, -40
	sw $ra, 36($sp)
	sw $fp, 32($sp)
	addiu $fp, $sp, 32
	lw $t0, 8($fp)
	lw $t1, 4($t0)
	sw $t1, -12($fp)
	lw $t0, 8($fp)
	lw $t1, 8($t0)
	sw $t1, -16($fp)
	lw $t0, -12($fp)
	lw $t1, -16($fp)
	mul $t2, $t0, $t1
	sw $t2, -20($fp)
	lw $v0, -20($fp)

# --- Epilogue ---
	lw $ra, 36($sp)
	lw $fp, 32($sp)
	addiu $sp, $sp, 40
	jr $ra

# --- Prologue for main ---
main:
	addiu $sp, $sp, -56
	sw $ra, 52($sp)
	sw $fp, 48($sp)
	addiu $fp, $sp, 48
	addiu $t0, $fp, -12
	sw $t0, -40($fp)
	lw $t0, -40($fp)
	sw $t0, -0($sp)
	li $t0, 100
	sw $t0, -4($sp)
	li $t0, 10
	sw $t0, -8($sp)
	li $t0, 5
	sw $t0, -12($sp)
	jal Rectangle::init_rect
	sw $v0, -44($fp)
	addiu $t0, $fp, -12
	sw $t0, -48($fp)
	lw $t0, -48($fp)
	sw $t0, -0($sp)
	jal Rectangle::area
	sw $v0, -52($fp)
	lw $t0, -52($fp)
	sw $t0, -16($fp)
	li $v0, 4
	la $a0, _str_1
	syscall
	lw $a0, varoufakis
	li $v0, 1
	syscall
	lw $v0, -16($fp)

# --- Epilogue ---
	lw $ra, 52($sp)
	lw $fp, 48($sp)
	addiu $sp, $sp, 56
	jr $ra

# Exit program
	li $v0, 10
	syscall
