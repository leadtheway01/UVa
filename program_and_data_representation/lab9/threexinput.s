	.file	"threexinput.cpp"
	.intel_syntax noprefix
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"enter integer: "
	.section	.rodata.str1.4,"aMS",@progbits,1
	.align 4
.LC2:
	.string	"enter number of times to call subroutines: "
	.section	.rodata.str1.1
.LC3:
	.string	"\n"
.LC4:
	.string	"Total number of steps: "
	.section	.rodata.str1.4
	.align 4
.LC5:
	.string	"Average time for each subroutines: "
	.section	.rodata.str1.1
.LC6:
	.string	" seconds"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB1030:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	push	esi
	push	ebx
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	xor	ebx, ebx
	and	esp, -16
	sub	esp, 48
	fldz
	fst	QWORD PTR [esp+40]
	mov	DWORD PTR [esp], 20
	fstp	DWORD PTR [esp+16]
	call	_Znwj
	mov	BYTE PTR [eax+16], 0
	mov	esi, eax
	mov	DWORD PTR [esp+4], OFFSET FLAT:.LC1
	mov	DWORD PTR [esp], OFFSET FLAT:_ZSt4cout
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	lea	eax, [esp+36]
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], OFFSET FLAT:_ZSt3cin
	call	_ZNSirsERi
	mov	DWORD PTR [esp+4], OFFSET FLAT:.LC2
	mov	DWORD PTR [esp], OFFSET FLAT:_ZSt4cout
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	lea	eax, [esp+40]
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], OFFSET FLAT:_ZSt3cin
	call	_ZNSi10_M_extractIdEERSiRT_
	mov	DWORD PTR [esp+4], OFFSET FLAT:.LC3
	mov	DWORD PTR [esp], OFFSET FLAT:_ZSt4cout
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	DWORD PTR [esp], esi
	call	_ZN5timer5startEv
	fld	DWORD PTR [esp+16]
	fld	QWORD PTR [esp+40]
	fucomip	st, st(1)
	fstp	st(0)
	jbe	.L3
	.p2align 4,,7
	.p2align 3
.L7:
	mov	edx, DWORD PTR [esp+36]
	add	ebx, 1
	mov	DWORD PTR [esp], edx
	call	threexplusone
	mov	DWORD PTR [esp+28], ebx
	fild	DWORD PTR [esp+28]
	fld	QWORD PTR [esp+40]
	fucomip	st, st(1)
	fstp	st(0)
	ja	.L7
.L3:
	mov	DWORD PTR [esp], esi
	call	_ZN5timer4stopEv
	mov	DWORD PTR [esp], esi
	call	_ZN5timer7getTimeEv
	mov	eax, DWORD PTR [esp+36]
	mov	DWORD PTR [esp], eax
	fdiv	QWORD PTR [esp+40]
	fstp	QWORD PTR [esp+16]
	call	threexplusone
	mov	DWORD PTR [esp+4], OFFSET FLAT:.LC4
	mov	DWORD PTR [esp], OFFSET FLAT:_ZSt4cout
	mov	ebx, eax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	DWORD PTR [esp+4], ebx
	mov	DWORD PTR [esp], eax
	call	_ZNSolsEi
	mov	DWORD PTR [esp+4], OFFSET FLAT:.LC3
	mov	DWORD PTR [esp], eax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	DWORD PTR [esp+4], OFFSET FLAT:.LC5
	mov	DWORD PTR [esp], OFFSET FLAT:_ZSt4cout
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	fld	QWORD PTR [esp+16]
	fstp	QWORD PTR [esp+4]
	mov	DWORD PTR [esp], eax
	call	_ZNSo9_M_insertIdEERSoT_
	mov	DWORD PTR [esp+4], OFFSET FLAT:.LC6
	mov	DWORD PTR [esp], eax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	DWORD PTR [esp], eax
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	lea	esp, [ebp-8]
	xor	eax, eax
	pop	ebx
	.cfi_restore 3
	pop	esi
	.cfi_restore 6
	pop	ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1030:
	.size	main, .-main
	.p2align 4,,15
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB1042:
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
.LFE1042:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 4
	.long	_GLOBAL__sub_I_main
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
