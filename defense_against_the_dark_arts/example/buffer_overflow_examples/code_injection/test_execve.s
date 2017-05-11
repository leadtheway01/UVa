.section .data
s:
	.string "/bin/cat"
p:	
	.string "/etc/passwd"

.section .text
.globl main

main:
	pushl %ebp
	movl  %esp, %ebp

	xorl  %eax, %eax
	pushl %eax

	movl  $s, %ebx
	
	pushl %eax
	movl  %esp, %edx
	
	push  $p
	push  $s
	mov   %esp, %ecx
	
	movb  $11, %al
	int   $0x80
	leave
	ret

