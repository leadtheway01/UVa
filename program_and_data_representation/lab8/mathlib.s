; Wright Kim
; wdk7bj
; mathlib.s

; mathlib
; Parameter 1 - the starting address. integer value of x
; Parameter 2 - integer value of y in sequence to parameter 1
; Return value - the product of the intergers in sequence 
;				 or the power of base x to the exponent of y


	global product
	global power

	section .text

; product(x, y)
product:
	; Standard prologue
	push	ebp				; Save the old base pointer
	mov		ebp, esp		; Set new value of the base pointer
	sub	  	esp, 4 			; save room for the first local variable, retVal
	sub	  	esp, 4			; save room for the second local variable, i

	push	ebx				; save callee-save register
	push 	esi				; save callee-save register

	xor 	eax, eax		; place 0 in eax to initialize 	retVal
	xor 	esi, esi		; place 0 in esi to initialize	i

	mov 	ebx, [ebp+12] 	;put y value to ebx

product_loop:
	add 	eax, [ebp+8]	; add x value to eax
	dec 	ebx				; dec y by 1
	cmp 	ebx, esi		; compare i and y
	je 		product_done	; jump to product_done when y == i == 0
	jg 		product_loop	; jump to prodict_loop when y > i

product_done:
	pop 	esi
	pop 	ebx
	mov 	esp, ebp
	pop 	ebp
	ret

; power(x, y)
power:
	; Standard prologue
	push	ebp				; Save the old base pointer
	mov		ebp, esp		; Set new value of the base pointer
	sub	  	esp, 4 			; save room for the first local variable, retVal
	sub	  	esp, 4			; save room for the second local variable, i

	push	ebx				; save callee-save register
	push 	esi				; save callee-save register
	push 	edi				; save callee-save register

	xor 	eax, eax		; place 0 in eax to initialize 	retVal
	inc 	eax				; inc eax to 1


	mov 	ebx, [ebp+12] 	;put y value to ebx
	mov 	esi, [ebp+8]  	; x at esi	
power_loop:
	imul 	eax, esi		; eax = eax*esi 
	dec 	ebx				; dec y by 1
	cmp 	ebx, edi
	je 		power_done		; if ebx == edi, jmp to power_done
	jg 		power_loop		; if ebx > edi, jmp to power_loop
	

power_done:
	pop 	edi
	pop 	esi
	pop 	ebx
	mov 	esp, ebp
	pop 	ebp
	ret