.text
.global gadget1

gadget1:
	popl %eax
        ret

.global gadget2

gadget2:
	popl %ebx
        ret

.global gadget3

gadget3:
	leal 12(%esp), %ecx
        ret

.global gadget4

gadget4:
	popl %edx
        ret


.global gadget5

gadget5:
	int $0x80	
        ret

