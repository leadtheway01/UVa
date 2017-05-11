
.global VolumeAndDensity

#declare global variable
#arrary size 2
.global var
.comm var, 8, 4

#param mass   @ ebp+20
#param height @ ebp+16
#param widht  @ ebp+12
#param lenght @ ebp+8
#ret address  @ ebp+4

VolumeAndDensity:
	# prologue
	push %ebp
	movl %esp, %ebp
	push %ecx

	movl 8(%ebp), %eax	# length
	imul 12(%ebp), %eax	# length * width
	imul 16(%ebp), %eax	# length * width * height 
	movl %eax, %ecx		# save volume @var[0]

	xorl %edx, %edx		# set edx to 0
	movl 20(%ebp), %eax	# eax has value of mass
	idiv %ecx		# density stored @ eax

	movl %eax, var+4 	# save density @var[1]
	movl %ecx, var		# store density @var[1]	
	leal var, %eax
	
	#epilogue
	pop %ecx
	movl %ebp, %esp
	pop %ebp
	ret
