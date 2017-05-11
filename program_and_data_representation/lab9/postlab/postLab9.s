	.file	"postLab9.cpp"
	.intel_syntax noprefix
	.text
	.p2align 4,,15
	.globl	_Z3addii
	.type	_Z3addii, @function
_Z3addii:
.LFB998:
	.cfi_startproc
	mov	eax, DWORD PTR [esp+8]
	add	eax, DWORD PTR [esp+4]
	ret
	.cfi_endproc
.LFE998:
	.size	_Z3addii, .-_Z3addii
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB999:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	and	esp, -16
	sub	esp, 16
	mov	DWORD PTR [esp+4], 6
	mov	DWORD PTR [esp], OFFSET FLAT:_ZSt4cout
	call	_ZNSolsEi
	xor	eax, eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE999:
	.size	main, .-main
	.p2align 4,,15
	.type	_GLOBAL__sub_I__Z3addii, @function
_GLOBAL__sub_I__Z3addii:
.LFB1001:
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
.LFE1001:
	.size	_GLOBAL__sub_I__Z3addii, .-_GLOBAL__sub_I__Z3addii
	.section	.init_array,"aw"
	.align 4
	.long	_GLOBAL__sub_I__Z3addii
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
