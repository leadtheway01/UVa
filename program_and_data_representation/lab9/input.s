	.file	"input.cpp"
	.intel_syntax noprefix
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"enter integer"
.LC1:
	.string	"\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB998:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	and	esp, -16
	sub	esp, 32
	mov	DWORD PTR [esp+4], OFFSET FLAT:.LC0
	mov	DWORD PTR [esp], OFFSET FLAT:_ZSt4cout
	mov	DWORD PTR [esp+28], 0
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	DWORD PTR [esp+4], OFFSET FLAT:.LC1
	mov	DWORD PTR [esp], eax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	lea	eax, [esp+28]
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], OFFSET FLAT:_ZSt3cin
	call	_ZNSirsERi
	mov	eax, DWORD PTR [esp+28]
	cmp	eax, 1
	je	.L6
	mov	edx, 1
	jmp	.L3
	.p2align 4,,7
	.p2align 3
.L12:
	lea	eax, [eax+1+eax*2]
	mov	ecx, edx
	add	edx, 1
	cmp	eax, 1
	je	.L2
.L3:
	test	al, 1
	jne	.L12
	mov	ecx, eax
	shr	ecx, 31
	add	eax, ecx
	mov	ecx, edx
	sar	eax
	add	edx, 1
	cmp	eax, 1
	jne	.L3
.L2:
	mov	DWORD PTR [esp+4], ecx
	mov	DWORD PTR [esp], OFFSET FLAT:_ZSt4cout
	call	_ZNSolsEi
	mov	DWORD PTR [esp], eax
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	xor	eax, eax
	leave
	.cfi_remember_state
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
.L6:
	.cfi_restore_state
	xor	ecx, ecx
	jmp	.L2
	.cfi_endproc
.LFE998:
	.size	main, .-main
	.text
	.p2align 4,,15
	.globl	_Z5counti
	.type	_Z5counti, @function
_Z5counti:
.LFB999:
	.cfi_startproc
	mov	edx, DWORD PTR [esp+4]
	cmp	edx, 1
	je	.L18
	mov	ecx, 1
	jmp	.L15
	.p2align 4,,7
	.p2align 3
.L22:
	lea	edx, [edx+1+edx*2]
	mov	eax, ecx
	add	ecx, 1
	cmp	edx, 1
	je	.L14
.L15:
	test	dl, 1
	jne	.L22
	mov	eax, edx
	shr	eax, 31
	add	edx, eax
	mov	eax, ecx
	sar	edx
	add	ecx, 1
	cmp	edx, 1
	jne	.L15
.L14:
	rep ret
.L18:
	xor	eax, eax
	ret
	.cfi_endproc
.LFE999:
	.size	_Z5counti, .-_Z5counti
	.section	.text.startup
	.p2align 4,,15
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB1009:
	.cfi_startproc
	sub	esp, 28
	.cfi_def_cfa_offset 32
	mov	DWORD PTR [esp], OFFSET FLAT:_ZStL8__ioinit
	call	_ZNSt8ios_base4InitC1Ev
	mov	DWORD PTR [esp+8], OFFSET FLAT:__dso_handle
	mov	DWORD PTR [esp+4], OFFSET FLAT:_ZStL8__ioinit
	mov	DWORD PTR [esp], OFFSET FLAT:_ZNSt8ios_base4InitD1Ev
	call	__cxa_atexit
	add	esp, 28
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE1009:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 4
	.long	_GLOBAL__sub_I_main
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
