		.data
text1:		.asciiz "Ingrese un palindromo :"
text2:		.asciiz	"Su palabra es: "
palindromo:	.space 1024			#asigno a palindromo un tamaño de 1024 bytes
fin_palindromo:	.asciiz	"\n"
verificar:	.space 1			#reservo 1 byte para mi verificador
cont:		.space 4
		.text
main:		la	$a0,text1		#carga la direccion de text1
		li	$v0,4			#instruccion de imprimir string
		syscall				#imprime
		la	$a0,palindromo 		#carga la direcion de palindromo
		li	$v0,8			#instruccion de leer un string
		li	$a1,1024		#argumento de leer un string (guarda en a1 el string de tamaño 1024)
		syscall				#leo la frase
		li	$s0,0			#inicializo s0 como 0
		sb	$s0,verificar		#Guardo el byte de s0 en verificar
		jal 	print			#salto a la etiqueta print
		la 	$a0,palindromo		#carga la direccion de palindromo
		lb	$t0,palindromo		#carga 1 byte de memoria de palindromo 
		li	$t3,0			#auxiliar para encontrar ultimo registro
		lb 	$t4,fin_palindromo	#cargo 1 byte de memoria de fin_palindromo que seria \n
		jal 	fin			#salto a la etiqueta fin
		add	$s5,$zero,$t3		#Guardo en el registro s5 el valor del largo de la palabra
		jal	ver_palindromo		#Salto a la funcion ver_palindromo
		lb	$a0,verificar		#cargo en a0 el byte dentro de verificar
		li	$v0,1			#Instruccion de imprimir un numero entero
		syscall				#llama a imprimir
		jal	contra
		li	$v0,10			#system call for exit
		syscall				#end of program
		### funciones
print:		la	$a0,text2		#carga la direccion de text2
		li	$v0,4			#instruccion de imprimir string
		syscall				#imprime
		la	$a0,palindromo		#carga la direccion de palindromo	
		li	$v0,4			#instruccion de imprimir string de palindromo
		syscall				#imprime string	
		jr 	$ra			#devuelve el registro de la siguiente instruccion antes del jal
fin:		lb	$t2,palindromo($t3)	#Cargo un byte, copio en t2 el contador que tengo en t3
		addi	$t3,$t3,1		#Avanzo el contador t3 en 1
		bne	$t2,$t4,fin		#salto condicional, salta a etiqueta si t2 es distinto a t4
		addi	$t3,$t3,-2		#Guardo la ultima letra antes del \n, ya que el contador me avanzara un byte mas que el espacio
		lb 	$t1,palindromo($t3)	#Guardo en t1 el byte de la ultima letra
		li	$t2,0			#Dejo el t2 en 0
		jr	$ra			#devuelvo el registro de la siguiente instruccion cuando se llamo el jal
ver_palindromo:	lb	$t0,palindromo($t2)	#Guardo en t0 la primera letra por la izq
		lb	$t1,palindromo($t3)	#Guardo en t1 la primera letra por la derecha
		bge 	$t2,$t3,ver		#Si t2 es mayor o igual a t3 llama a la etiqueta ver
		beq	$t0,32,espacio_i	#Salta uno a la derecha si encuentra un espacio (31 codigo ascii del espacio)		
		beq	$t1,32,espacio_d	#Salta uno a la izquierda si hay un espacio
		addi	$t2,$t2,1		#Avanza en 1 el t2
		addi	$t3,$t3,-1		#Avanza en -1 el t3 
		beq	$t0,$t1,ver_palindromo	#Compara t0 con t1 y si son iguales llama a la etiqueta ver_palindromo
		jr	$ra			#Manda a la direccion de memoria guardada en $ra
espacio_i:	addi	$t2,$t2,1		#Avanza en 1 el t2
		b	ver_palindromo		#hace un back a la etiqueta ver_palindromo
espacio_d:	addi	$t3,$t3,-1		#Avanza en -1 el t3
		b	ver_palindromo		#Hace un back a la etiqueta ver_palindromo
ver:		li	$s0,1			#guarda en s0 el valor 
		sb	$s0,verificar		#Guarda 1 byte de s0 dentro de verificar
		li	$s0,0			#deja el s0 con el valor 0
		jr 	$ra			#llama de vuelta a la siguiente instruccion guardada en ra, en la linea 24,despues del jal a ver palindromo
		#s1 contador, s5 es el tamaño
contra:		
		jr 	$ra

