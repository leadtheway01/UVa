
.section .text
.globl main
main:
	movl $12, %edx
	movl $0xbffffe60, %ecx
	movl $1, %ebx
	movl $4, %eax
	int  $0x80
	ret 
