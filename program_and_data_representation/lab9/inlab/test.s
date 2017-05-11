	.file	"test.cpp"
	.intel_syntax noprefix
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.text._ZN1AC2Ev,"axG",@progbits,_ZN1AC5Ev,comdat
	.align 2
	.weak	_ZN1AC2Ev
	.type	_ZN1AC2Ev, @function
_ZN1AC2Ev:
.LFB976:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	mov	eax, DWORD PTR [ebp+8]
	mov	DWORD PTR [eax], OFFSET FLAT:_ZTV1A+8
	pop	ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE976:
	.size	_ZN1AC2Ev, .-_ZN1AC2Ev
	.weak	_ZN1AC1Ev
	.set	_ZN1AC1Ev,_ZN1AC2Ev
	.section	.rodata
.LC0:
	.string	"A"
	.section	.text._ZN1A3fooEv,"axG",@progbits,_ZN1A3fooEv,comdat
	.align 2
	.weak	_ZN1A3fooEv
	.type	_ZN1A3fooEv, @function
_ZN1A3fooEv:
.LFB981:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 24
	mov	DWORD PTR [esp+4], OFFSET FLAT:.LC0
	mov	DWORD PTR [esp], OFFSET FLAT:_ZSt4cout
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	DWORD PTR [esp+4], OFFSET FLAT:_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	DWORD PTR [esp], eax
	call	_ZNSolsEPFRSoS_E
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE981:
	.size	_ZN1A3fooEv, .-_ZN1A3fooEv
	.section	.text._ZN1A3addEv,"axG",@progbits,_ZN1A3addEv,comdat
	.align 2
	.weak	_ZN1A3addEv
	.type	_ZN1A3addEv, @function
_ZN1A3addEv:
.LFB982:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	pop	ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE982:
	.size	_ZN1A3addEv, .-_ZN1A3addEv
	.section	.text._ZN1BC2Ev,"axG",@progbits,_ZN1BC5Ev,comdat
	.align 2
	.weak	_ZN1BC2Ev
	.type	_ZN1BC2Ev, @function
_ZN1BC2Ev:
.LFB984:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 24
	mov	eax, DWORD PTR [ebp+8]
	mov	DWORD PTR [esp], eax
	call	_ZN1AC2Ev
	mov	eax, DWORD PTR [ebp+8]
	mov	DWORD PTR [eax], OFFSET FLAT:_ZTV1B+8
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE984:
	.size	_ZN1BC2Ev, .-_ZN1BC2Ev
	.weak	_ZN1BC1Ev
	.set	_ZN1BC1Ev,_ZN1BC2Ev
	.section	.rodata
.LC1:
	.string	"B"
	.section	.text._ZN1B3fooEv,"axG",@progbits,_ZN1B3fooEv,comdat
	.align 2
	.weak	_ZN1B3fooEv
	.type	_ZN1B3fooEv, @function
_ZN1B3fooEv:
.LFB989:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 24
	mov	DWORD PTR [esp+4], OFFSET FLAT:.LC1
	mov	DWORD PTR [esp], OFFSET FLAT:_ZSt4cout
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	DWORD PTR [esp+4], OFFSET FLAT:_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	DWORD PTR [esp], eax
	call	_ZNSolsEPFRSoS_E
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE989:
	.size	_ZN1B3fooEv, .-_ZN1B3fooEv
	.section	.text._ZN1B3addEv,"axG",@progbits,_ZN1B3addEv,comdat
	.align 2
	.weak	_ZN1B3addEv
	.type	_ZN1B3addEv, @function
_ZN1B3addEv:
.LFB990:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	pop	ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE990:
	.size	_ZN1B3addEv, .-_ZN1B3addEv
	.text
	.globl	main
	.type	main, @function
main:
.LFB991:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	push	ebx
	and	esp, -16
	sub	esp, 32
	.cfi_offset 3, -12
	call	rand
	cdq
	shr	edx, 31
	add	eax, edx
	and	eax, 1
	sub	eax, edx
	mov	DWORD PTR [esp+28], eax
	cmp	DWORD PTR [esp+28], 0
	je	.L8
	mov	DWORD PTR [esp], 4
	call	_Znwj
	mov	ebx, eax
	mov	DWORD PTR [esp], ebx
	call	_ZN1AC1Ev
	mov	DWORD PTR [esp+24], ebx
	jmp	.L9
.L8:
	mov	DWORD PTR [esp], 4
	call	_Znwj
	mov	ebx, eax
	mov	DWORD PTR [esp], ebx
	call	_ZN1BC1Ev
	mov	DWORD PTR [esp+24], ebx
.L9:
	mov	eax, DWORD PTR [esp+24]
	mov	eax, DWORD PTR [eax]
	mov	eax, DWORD PTR [eax]
	mov	edx, DWORD PTR [esp+24]
	mov	DWORD PTR [esp], edx
	call	eax
	mov	eax, DWORD PTR [esp+24]
	mov	eax, DWORD PTR [eax]
	add	eax, 4
	mov	eax, DWORD PTR [eax]
	mov	edx, DWORD PTR [esp+24]
	mov	DWORD PTR [esp], edx
	call	eax
	mov	eax, 0
	mov	ebx, DWORD PTR [ebp-4]
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE991:
	.size	main, .-main
	.weak	_ZTV1B
	.section	.rodata._ZTV1B,"aG",@progbits,_ZTV1B,comdat
	.align 8
	.type	_ZTV1B, @object
	.size	_ZTV1B, 16
_ZTV1B:
	.long	0
	.long	_ZTI1B
	.long	_ZN1B3fooEv
	.long	_ZN1B3addEv
	.weak	_ZTV1A
	.section	.rodata._ZTV1A,"aG",@progbits,_ZTV1A,comdat
	.align 8
	.type	_ZTV1A, @object
	.size	_ZTV1A, 16
_ZTV1A:
	.long	0
	.long	_ZTI1A
	.long	_ZN1A3fooEv
	.long	_ZN1A3addEv
	.weak	_ZTS1B
	.section	.rodata._ZTS1B,"aG",@progbits,_ZTS1B,comdat
	.type	_ZTS1B, @object
	.size	_ZTS1B, 3
_ZTS1B:
	.string	"1B"
	.weak	_ZTI1B
	.section	.rodata._ZTI1B,"aG",@progbits,_ZTI1B,comdat
	.align 4
	.type	_ZTI1B, @object
	.size	_ZTI1B, 12
_ZTI1B:
	.long	_ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	_ZTS1B
	.long	_ZTI1A
	.weak	_ZTS1A
	.section	.rodata._ZTS1A,"aG",@progbits,_ZTS1A,comdat
	.type	_ZTS1A, @object
	.size	_ZTS1A, 3
_ZTS1A:
	.string	"1A"
	.weak	_ZTI1A
	.section	.rodata._ZTI1A,"aG",@progbits,_ZTI1A,comdat
	.align 4
	.type	_ZTI1A, @object
	.size	_ZTI1A, 8
_ZTI1A:
	.long	_ZTVN10__cxxabiv117__class_type_infoE+8
	.long	_ZTS1A
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1000:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 24
	cmp	DWORD PTR [ebp+8], 1
	jne	.L11
	cmp	DWORD PTR [ebp+12], 65535
	jne	.L11
	mov	DWORD PTR [esp], OFFSET FLAT:_ZStL8__ioinit
	call	_ZNSt8ios_base4InitC1Ev
	mov	DWORD PTR [esp+8], OFFSET FLAT:__dso_handle
	mov	DWORD PTR [esp+4], OFFSET FLAT:_ZStL8__ioinit
	mov	DWORD PTR [esp], OFFSET FLAT:_ZNSt8ios_base4InitD1Ev
	call	__cxa_atexit
.L11:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1000:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB1001:
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
.LFE1001:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 4
	.long	_GLOBAL__sub_I_main
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
