	.file	"testClass.cpp"
	.intel_syntax noprefix
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata
.LC2:
	.string	"\n"
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
	sub	esp, 48
	fld	QWORD PTR .LC0
	fstp	QWORD PTR [esp+32]
	fld	QWORD PTR .LC1
	fstp	QWORD PTR [esp+40]
	mov	eax, DWORD PTR [esp+32]
	mov	DWORD PTR [esp], eax
	mov	eax, DWORD PTR [esp+36]
	mov	DWORD PTR [esp+4], eax
	mov	eax, DWORD PTR [esp+40]
	mov	DWORD PTR [esp+8], eax
	mov	eax, DWORD PTR [esp+44]
	mov	DWORD PTR [esp+12], eax
	call	_Z10returnYour8testCase
	fld	QWORD PTR [esp+40]
	fstp	QWORD PTR [esp+24]
	fld	QWORD PTR [esp+32]
	fstp	QWORD PTR [esp+4]
	mov	DWORD PTR [esp], OFFSET FLAT:_ZSt4cout
	call	_ZNSolsEd
	mov	DWORD PTR [esp+4], OFFSET FLAT:.LC2
	mov	DWORD PTR [esp], eax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	fld	QWORD PTR [esp+24]
	fstp	QWORD PTR [esp+4]
	mov	DWORD PTR [esp], eax
	call	_ZNSolsEd
	mov	DWORD PTR [esp+4], OFFSET FLAT:_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	DWORD PTR [esp], eax
	call	_ZNSolsEPFRSoS_E
	lea	eax, [esp+32]
	mov	DWORD PTR [esp], eax
	call	_Z13returnYourRefR8testCase
	fld	QWORD PTR [esp+40]
	fstp	QWORD PTR [esp+24]
	fld	QWORD PTR [esp+32]
	fstp	QWORD PTR [esp+4]
	mov	DWORD PTR [esp], OFFSET FLAT:_ZSt4cout
	call	_ZNSolsEd
	mov	DWORD PTR [esp+4], OFFSET FLAT:.LC2
	mov	DWORD PTR [esp], eax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	fld	QWORD PTR [esp+24]
	fstp	QWORD PTR [esp+4]
	mov	DWORD PTR [esp], eax
	call	_ZNSolsEd
	mov	DWORD PTR [esp+4], OFFSET FLAT:_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	DWORD PTR [esp], eax
	call	_ZNSolsEPFRSoS_E
	mov	eax, 0
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE971:
	.size	main, .-main
	.globl	_Z13returnYourRefR8testCase
	.type	_Z13returnYourRefR8testCase, @function
_Z13returnYourRefR8testCase:
.LFB972:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 40
	mov	eax, DWORD PTR [ebp+8]
	fld	QWORD PTR .LC4
	fstp	QWORD PTR [eax]
	mov	eax, DWORD PTR [ebp+8]
	fld	QWORD PTR .LC5
	fstp	QWORD PTR [eax+8]
	mov	eax, DWORD PTR [ebp+8]
	fld	QWORD PTR [eax+8]
	fstp	QWORD PTR [ebp-16]
	mov	eax, DWORD PTR [ebp+8]
	fld	QWORD PTR [eax]
	fstp	QWORD PTR [esp+4]
	mov	DWORD PTR [esp], OFFSET FLAT:_ZSt4cout
	call	_ZNSolsEd
	mov	DWORD PTR [esp+4], OFFSET FLAT:.LC2
	mov	DWORD PTR [esp], eax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	fld	QWORD PTR [ebp-16]
	fstp	QWORD PTR [esp+4]
	mov	DWORD PTR [esp], eax
	call	_ZNSolsEd
	mov	DWORD PTR [esp+4], OFFSET FLAT:_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	DWORD PTR [esp], eax
	call	_ZNSolsEPFRSoS_E
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE972:
	.size	_Z13returnYourRefR8testCase, .-_Z13returnYourRefR8testCase
	.globl	_Z10returnYour8testCase
	.type	_Z10returnYour8testCase, @function
_Z10returnYour8testCase:
.LFB973:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 40
	fld	QWORD PTR .LC6
	fstp	QWORD PTR [ebp+8]
	fld	QWORD PTR .LC7
	fstp	QWORD PTR [ebp+16]
	fld	QWORD PTR [ebp+16]
	fstp	QWORD PTR [ebp-16]
	fld	QWORD PTR [ebp+8]
	fstp	QWORD PTR [esp+4]
	mov	DWORD PTR [esp], OFFSET FLAT:_ZSt4cout
	call	_ZNSolsEd
	mov	DWORD PTR [esp+4], OFFSET FLAT:.LC2
	mov	DWORD PTR [esp], eax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	fld	QWORD PTR [ebp-16]
	fstp	QWORD PTR [esp+4]
	mov	DWORD PTR [esp], eax
	call	_ZNSolsEd
	mov	DWORD PTR [esp+4], OFFSET FLAT:_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	DWORD PTR [esp], eax
	call	_ZNSolsEPFRSoS_E
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE973:
	.size	_Z10returnYour8testCase, .-_Z10returnYour8testCase
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB983:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 24
	cmp	DWORD PTR [ebp+8], 1
	jne	.L5
	cmp	DWORD PTR [ebp+12], 65535
	jne	.L5
	mov	DWORD PTR [esp], OFFSET FLAT:_ZStL8__ioinit
	call	_ZNSt8ios_base4InitC1Ev
	mov	DWORD PTR [esp+8], OFFSET FLAT:__dso_handle
	mov	DWORD PTR [esp+4], OFFSET FLAT:_ZStL8__ioinit
	mov	DWORD PTR [esp], OFFSET FLAT:_ZNSt8ios_base4InitD1Ev
	call	__cxa_atexit
.L5:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE983:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB984:
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
.LFE984:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 4
	.long	_GLOBAL__sub_I_main
	.section	.rodata
	.align 8
.LC0:
	.long	0
	.long	1075314688
	.align 8
.LC1:
	.long	0
	.long	1080381440
	.align 8
.LC4:
	.long	858993459
	.long	1075131187
	.align 8
.LC5:
	.long	0
	.long	1080627200
	.align 8
.LC6:
	.long	0
	.long	1075052544
	.align 8
.LC7:
	.long	0
	.long	1080623104
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
