	.file	"hw1.c"
	.section	.rodata
.LC0:
	.string	"Sum is %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x7c,0x6
	subl	$36, %esp
	movl	%gs:20, %eax
	movl	%eax, -12(%ebp)
	xorl	%eax, %eax
	subl	$4, %esp
	pushl	$1
	pushl	$12
	leal	-24(%ebp), %eax
	pushl	%eax
	call	foo
	addl	$16, %esp
	movl	%eax, -28(%ebp)
	movl	$0, -32(%ebp)
	movl	$0, -36(%ebp)
	jmp	.L2
.L3:
	leal	-24(%ebp), %edx
	movl	-36(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	addl	%eax, -32(%ebp)
	addl	$1, -36(%ebp)
.L2:
	cmpl	$11, -36(%ebp)
	jle	.L3
	subl	$8, %esp
	pushl	-32(%ebp)
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	movl	$0, %eax
	movl	-12(%ebp), %ecx
	xorl	%gs:20, %ecx
	je	.L5
	call	__stack_chk_fail
.L5:
	movl	-4(%ebp), %ecx
	.cfi_def_cfa 1, 0
	leave
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	foo
	.type	foo, @function
foo:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$0, -4(%ebp)
	jmp	.L7
.L8:
	movl	-4(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	16(%ebp), %edx
	movb	%dl, (%eax)
	addl	$1, -4(%ebp)
.L7:
	movl	-4(%ebp), %eax
	cmpl	12(%ebp), %eax
	jl	.L8
	movl	12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	foo, .-foo
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
