.section .data
s:
	.string "xxxHackedxxx\n"

.section .text
.globl main
main:
	movl $13, %edx
	movl $0x804a018, %ecx
	movl $1, %ebx
	movl $4, %eax
	int  $0x80
	ret 
	movl $0xbffffe60, %ecx
