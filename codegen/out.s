.data
newline: .asciiz "\n"

.text
.globl main

# --- Prologue for Shape::set_id ---
Shape::set_id:
	addiu $sp, $sp, -82
	sw $ra, 78($sp)
	sw $fp, 74($sp)
	addiu $fp, $sp, 74
	lw $t0, 8($fp)
	lw $t1, 12($fp)
	sw $t1, 0($t0)

# --- Epilogue ---
	lw $ra, 78($sp)
	lw $fp, 74($sp)
	addiu $sp, $sp, 82
	jr $ra

# --- Prologue for Rectangle::init_rect ---
Rectangle::init_rect:
	addiu $sp, $sp, -81
	sw $ra, 77($sp)
	sw $fp, 73($sp)
	addiu $fp, $sp, 73
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
	lw $ra, 77($sp)
	lw $fp, 73($sp)
	addiu $sp, $sp, 81
	jr $ra

# --- Prologue for Rectangle::area ---
Rectangle::area:
	addiu $sp, $sp, -573125474
	sw $ra, 573125470($sp)
	sw $fp, 573125466($sp)
	addiu $fp, $sp, 573125466
	lw $t0, 8($fp)
	lw $t1, 4($t0)
	sw $t1, -573125438($fp)
	lw $t0, 8($fp)
	lw $t1, 8($t0)
	sw $t1, -573125442($fp)
	lw $t0, -573125438($fp)
	lw $t1, -573125442($fp)
	mul $t2, $t0, $t1
	sw $t2, -573125446($fp)
	lw $v0, -573125446($fp)

# --- Epilogue ---
	lw $ra, 573125470($sp)
	lw $fp, 573125466($sp)
	addiu $sp, $sp, 573125474
	jr $ra

# --- Prologue for main ---
main:
	addiu $sp, $sp, -1868788560
	sw $ra, 1868788556($sp)
	sw $fp, 1868788552($sp)
	addiu $fp, $sp, 1868788552
	addiu $t0, $fp, -12
	sw $t0, -1868788536($fp)
	lw $t0, -1868788536($fp)
	sw $t0, -0($sp)
	li $t0, 100
	sw $t0, -4($sp)
	li $t0, 10
	sw $t0, -8($sp)
	li $t0, 5
	sw $t0, -12($sp)
	jal Rectangle::init_rect
	sw $v0, -1868788540($fp)
	addiu $t0, $fp, -12
	sw $t0, -1868788544($fp)
	lw $t0, -1868788544($fp)
	sw $t0, -0($sp)
	jal Rectangle::area
	sw $v0, -1868788548($fp)
	lw $t0, -1868788548($fp)
	sw $t0, -16($fp)
	lw $v0, -16($fp)

# --- Epilogue ---
	lw $ra, 1868788556($sp)
	lw $fp, 1868788552($sp)
	addiu $sp, $sp, 1868788560
	jr $ra

# Exit program
	li $v0, 10
	syscall
