.data
newline: .asciiz "\n"

.text
.globl main
L1:

# --- Prologue for Shape::set_id ---
Shape::set_id:
	addiu $sp, $sp, -64
	sw $ra, 60($sp)
	sw $fp, 56($sp)
	addiu $fp, $sp, 56
	lw $t0, 8($fp)
	lw $t1, 12($fp)
	sw $t1, 0($t0)

# --- Epilogue ---
	lw $ra, 60($sp)
	lw $fp, 56($sp)
	addiu $sp, $sp, 64
	jr $ra
L2:

# --- Prologue for Rectangle::init_rect ---
Rectangle::init_rect:
	addiu $sp, $sp, -64
	sw $ra, 60($sp)
	sw $fp, 56($sp)
	addiu $fp, $sp, 56
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
	lw $ra, 60($sp)
	lw $fp, 56($sp)
	addiu $sp, $sp, 64
	jr $ra
L3:

# --- Prologue for Rectangle::area ---
Rectangle::area:
	addiu $sp, $sp, -64
	sw $ra, 60($sp)
	sw $fp, 56($sp)
	addiu $fp, $sp, 56
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
	lw $ra, 60($sp)
	lw $fp, 56($sp)
	addiu $sp, $sp, 64
	jr $ra
L4:

# --- Prologue for main ---
main:
	addiu $sp, $sp, -80
	sw $ra, 76($sp)
	sw $fp, 72($sp)
	addiu $fp, $sp, 72
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
	lw $v0, -16($fp)

# --- Epilogue ---
	lw $ra, 76($sp)
	lw $fp, 72($sp)
	addiu $sp, $sp, 80
	jr $ra

# Exit program
	li $v0, 10
	syscall
