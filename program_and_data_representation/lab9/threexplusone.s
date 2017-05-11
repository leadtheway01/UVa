;Wright Kim
;wdk7bj
;threexplusone

;Optimization
; 1) used bit shift instead of dividing by 2 (.L2) and multiplying by 2 (.L3)
; 2) first pushed all callee registers to stack(ebx, edi, esi). 
;	Since edi register was not being used, removed it from the code
; 3) offset parameter from esp instead of ebp
; 4) removed allocated local variable (sub esp, 4) since not used

	global threexplusone

	section .text

threexplusone:
	;prolouge
	push ebx			; paramter
	push esi			; to check if even or odd
	xor eax, eax		; initialize return value eax to 0
	mov ebx, [esp+12]	; copy parameter to ebx
	cmp ebx, 1 			; compare the parameter with 1
	je .L4				; if parameter is equal to 1, exit subroutine
	mov esi, ebx
	and esi, 01H		; and operation on the LSB of ebx
	jz .L2				; if parameter is even, jump to L2
	jmp .L3				; if odd, jump to L3
.L2:
	shr ebx, 1 			; divide ebx by 2
	push ebx			; push parameter to stack 
	call threexplusone
	pop ebx
	add eax, 1 			; increment counter by 1
	pop esi
	pop ebx
	ret
.L3:
	shl ebx, 1 			; multiply x by 2
	add ebx, [esp+12]	; add x to 2x
	inc ebx
	push ebx			; push parameter to stack
	call threexplusone
	pop ebx
	add eax, 1
	pop esi
	pop ebx
	ret
.L4:
	xor eax, eax		; return value of eax is 0
	pop esi
	pop ebx
	ret




