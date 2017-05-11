	.file	"off_by_one.c"
	.text
.Ltext0:
	.section	.rodata
.LC0:
	.string	"Hello, %s.\n"
	.text
	.globl	echo_name
	.type	echo_name, @function
echo_name:
.LFB0:
	pushl	%ebp
.LCFI0:
	movl	%esp, %ebp
.LCFI1:
	subl	$296, %esp
	movl	$0, -268(%ebp)
	movl	$0, -268(%ebp)
	jmp	.L2
.L6:
	call	getchar
	movl	%eax, -272(%ebp)
	cmpl	$-1, -272(%ebp)
	je	.L3
	cmpl	$10, -272(%ebp)
	jne	.L4
.L3:
	leal	-256(%ebp), %eax
	addl	-268(%ebp), %eax
	movb	$0, (%eax)
	jmp	.L5
.L4:
	movl	-272(%ebp), %eax
	movl	%eax, %edx
	leal	-256(%ebp), %eax
	addl	-268(%ebp), %eax
	movb	%dl, (%eax)
	addl	$1, -268(%ebp)
.L2:
	cmpl	$256, -268(%ebp)
	jle	.L6
.L5:
	movl	$.LC0, %eax
	leal	-256(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$0, %eax
	leave
.LCFI2:
	ret
.LFE0:
	.size	echo_name, .-echo_name
	.section	.rodata
.LC1:
	.string	"Please enter your name: "
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	pushl	%ebp
.LCFI3:
	movl	%esp, %ebp
.LCFI4:
	andl	$-16, %esp
	subl	$16, %esp
	movl	$.LC1, %eax
	movl	%eax, (%esp)
	call	printf
	call	echo_name
	movl	$0, %eax
	leave
.LCFI5:
	ret

	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
