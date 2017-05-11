	.file	"testObject.cpp"
	.intel_syntax noprefix
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.text
	.globl	main
	.type	main, @function
main:
.LFB971:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	and	esp, -16
	sub	esp, 96
	mov	DWORD PTR [esp+16], 1
	mov	BYTE PTR [esp+20], 65
	mov	eax, DWORD PTR .LC0
	mov	DWORD PTR [esp+24], eax
	fld	QWORD PTR .LC1
	fstp	QWORD PTR [esp+28]
	fld	QWORD PTR .LC2
	fstp	QWORD PTR [esp+36]
	fld	QWORD PTR .LC3
	fstp	QWORD PTR [esp+44]
	mov	DWORD PTR [esp+4], 5
	lea	eax, [esp+16]
	mov	DWORD PTR [esp], eax
	call	_ZN6object3setEi
	mov	DWORD PTR [esp+4], 10
	lea	eax, [esp+56]
	mov	DWORD PTR [esp], eax
	call	_ZN6object3setEi
	lea	eax, [esp+16]
	mov	DWORD PTR [esp], eax
	call	_ZN6object3getEv
	mov	eax, 0
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE971:
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB972:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 24
	cmp	DWORD PTR [ebp+8], 1
	jne	.L3
	cmp	DWORD PTR [ebp+12], 65535
	jne	.L3
	mov	DWORD PTR [esp], OFFSET FLAT:_ZStL8__ioinit
	call	_ZNSt8ios_base4InitC1Ev
	mov	DWORD PTR [esp+8], OFFSET FLAT:__dso_handle
	mov	DWORD PTR [esp+4], OFFSET FLAT:_ZStL8__ioinit
	mov	DWORD PTR [esp], OFFSET FLAT:_ZNSt8ios_base4InitD1Ev
	call	__cxa_atexit
.L3:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE972:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB973:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 24
	mov	DWORD PTR [esp+4], 65535
	mov	DWORD PTR [esp], 1
	call	_Z41__static_initialization_and_destruction_0ii
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE973:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 4
	.long	_GLOBAL__sub_I_main
	.section	.rodata
	.align 4
.LC0:
	.long	1074161254
	.align 8
.LC1:
	.long	3435973837
	.long	1074318540
	.align 8
.LC2:
	.long	0
	.long	1075314688
	.align 8
.LC3:
	.long	0
	.long	1080459264
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
