.data
newline: .asciiz "\n"

.text
.globl main

# --- Prologue for Shape::set_id ---
Shape::set_id:
	addiu $sp, $sp, -76
	sw $ra, 72($sp)
	sw $fp, 68($sp)
	addiu $fp, $sp, 68
	la $t0, Shape::set_id
	add $t2, $t0, $t1
	sw $t2, 0($fp)
	lw $t0, 8($fp)
	lw $t1, 12($fp)
	sw $t1, 0($t0)

# --- Epilogue ---
	lw $ra, 72($sp)
	lw $fp, 68($sp)
	addiu $sp, $sp, 76
	jr $ra

# --- Prologue for Rectangle::init_rect ---
Rectangle::init_rect:
	addiu $sp, $sp, -76
	sw $ra, 72($sp)
	sw $fp, 68($sp)
	addiu $fp, $sp, 68
	la $t0, Rectangle::init_rect
	add $t2, $t0, $t1
	sw $t2, 0($fp)
	lw $t0, 8($fp)
	lw $t1, 12($fp)
	sw $t1, 0($t0)
	lw $t0, 8($fp)
	lw $t1, 16($fp)
	sw $t1, 8($t0)
	lw $t0, 8($fp)
	lw $t1, 20($fp)
	sw $t1, 4($t0)

# --- Epilogue ---
	lw $ra, 72($sp)
	lw $fp, 68($sp)
	addiu $sp, $sp, 76
	jr $ra

# --- Prologue for Rectangle::area ---
Rectangle::area:
	addiu $sp, $sp, -72
	sw $ra, 68($sp)
	sw $fp, 64($sp)
	addiu $fp, $sp, 64
	la $t0, Rectangle::area
	add $t2, $t0, $t1
	sw $t2, 0($fp)
	lw $t0, 8($fp)
	lw $t1, 8($t0)
	sw $t1, -44($fp)
	lw $t0, 8($fp)
	lw $t1, 4($t0)
	sw $t1, -48($fp)
	lw $t0, -44($fp)
	lw $t1, -48($fp)
	mul $t2, $t0, $t1
	sw $t2, -52($fp)
	lw $v0, -52($fp)

# --- Epilogue ---
	lw $ra, 68($sp)
	lw $fp, 64($sp)
	addiu $sp, $sp, 72
	jr $ra

# --- Prologue for main ---
main:
	addiu $sp, $sp, -72
	sw $ra, 68($sp)
	sw $fp, 64($sp)
	addiu $fp, $sp, 64
	la $t0, main
	add $t2, $t0, $t1
	sw $t2, 0($fp)
	addiu $t0, $fp, -12
	sw $t0, -56($fp)
	lw $t0, -56($fp)
	sw $t0, -0($sp)
	li $t0, 100
	sw $t0, -4($sp)
	li $t0, 10
	sw $t0, -8($sp)
	li $t0, 5
	sw $t0, -12($sp)
	jal Rectangle::init_rect
	sw $v0, -60($fp)
	addiu $t0, $fp, -12
	sw $t0, -64($fp)
	lw $t0, -64($fp)
	sw $t0, -0($sp)
	jal Rectangle::area
	sw $v0, -68($fp)
	lw $t0, -68($fp)
	sw $t0, -16($fp)
	lw $v0, -16($fp)

# --- Epilogue ---
	lw $ra, 68($sp)
	lw $fp, 64($sp)
	addiu $sp, $sp, 72
	jr $ra

# Exit program
	li $v0, 10
	syscall
