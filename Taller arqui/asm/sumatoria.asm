	.data
suma:	.space	4
cont: 	.space	4
n: 	.space	4
tira1:	.asciiz	"introduzca el valor limite:"
tira2: 	.asciiz	"El valor de la suma es"
	.text 
main:
	li 	$v0,4
	la	$a0,tira1
	syscall
	li	$v0,5
	syscall
	sw	$v0,n
	li	$s0,0
	sw	$s0,suma
	li	$s1,1
	sw	$s1,cont
while:	lw	$s2,n
	bgt	$s1,$s2,endwhile
	lw	$s0,suma
	lw	$s1,cont
	add	$s0,$s0,$s1
	sw	$s0,suma
	addi	$s1,$s1,1
	sw	$s1,cont
	j	while
endwhile:
	li	$v0,4
	la	$a0,tira2
	syscall
	li	$v0,1
	lw	$a0,suma
	syscall
	li 	$v0,17
	li	$a0,0
	syscall
	
