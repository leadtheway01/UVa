	.file	"dynamic.cpp"
	.intel_syntax noprefix
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.text._ZN6parentC2Ev,"axG",@progbits,_ZN6parentC5Ev,comdat
	.align 2
	.weak	_ZN6parentC2Ev
	.type	_ZN6parentC2Ev, @function
_ZN6parentC2Ev:
.LFB972:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	mov	eax, DWORD PTR [ebp+8]
	mov	DWORD PTR [eax], OFFSET FLAT:_ZTV6parent+8
	pop	ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE972:
	.size	_ZN6parentC2Ev, .-_ZN6parentC2Ev
	.weak	_ZN6parentC1Ev
	.set	_ZN6parentC1Ev,_ZN6parentC2Ev
	.section	.rodata
.LC0:
	.string	"parent"
	.section	.text._ZN6parent5printEv,"axG",@progbits,_ZN6parent5printEv,comdat
	.align 2
	.weak	_ZN6parent5printEv
	.type	_ZN6parent5printEv, @function
_ZN6parent5printEv:
.LFB977:
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
.LFE977:
	.size	_ZN6parent5printEv, .-_ZN6parent5printEv
	.section	.rodata
.LC1:
	.string	"parent add"
	.section	.text._ZN6parent3addEv,"axG",@progbits,_ZN6parent3addEv,comdat
	.align 2
	.weak	_ZN6parent3addEv
	.type	_ZN6parent3addEv, @function
_ZN6parent3addEv:
.LFB978:
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
.LFE978:
	.size	_ZN6parent3addEv, .-_ZN6parent3addEv
	.section	.text._ZN5childC2Ev,"axG",@progbits,_ZN5childC5Ev,comdat
	.align 2
	.weak	_ZN5childC2Ev
	.type	_ZN5childC2Ev, @function
_ZN5childC2Ev:
.LFB980:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 24
	mov	eax, DWORD PTR [ebp+8]
	mov	DWORD PTR [esp], eax
	call	_ZN6parentC2Ev
	mov	eax, DWORD PTR [ebp+8]
	mov	DWORD PTR [eax], OFFSET FLAT:_ZTV5child+8
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE980:
	.size	_ZN5childC2Ev, .-_ZN5childC2Ev
	.weak	_ZN5childC1Ev
	.set	_ZN5childC1Ev,_ZN5childC2Ev
	.section	.rodata
.LC2:
	.string	"child"
	.section	.text._ZN5child5printEv,"axG",@progbits,_ZN5child5printEv,comdat
	.align 2
	.weak	_ZN5child5printEv
	.type	_ZN5child5printEv, @function
_ZN5child5printEv:
.LFB985:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 24
	mov	DWORD PTR [esp+4], OFFSET FLAT:.LC2
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
.LFE985:
	.size	_ZN5child5printEv, .-_ZN5child5printEv
	.section	.rodata
.LC3:
	.string	"child add"
	.section	.text._ZN5child3addEv,"axG",@progbits,_ZN5child3addEv,comdat
	.align 2
	.weak	_ZN5child3addEv
	.type	_ZN5child3addEv, @function
_ZN5child3addEv:
.LFB986:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 24
	mov	DWORD PTR [esp+4], OFFSET FLAT:.LC3
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
.LFE986:
	.size	_ZN5child3addEv, .-_ZN5child3addEv
	.text
	.globl	main
	.type	main, @function
main:
.LFB987:
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
	mov	DWORD PTR [esp], 4
	call	_Znwj
	mov	ebx, eax
	mov	DWORD PTR [esp], ebx
	call	_ZN5childC1Ev
	mov	DWORD PTR [esp+28], ebx
	mov	eax, DWORD PTR [esp+28]
	mov	eax, DWORD PTR [eax]
	mov	eax, DWORD PTR [eax]
	mov	edx, DWORD PTR [esp+28]
	mov	DWORD PTR [esp], edx
	call	eax
	mov	eax, DWORD PTR [esp+28]
	mov	eax, DWORD PTR [eax]
	add	eax, 4
	mov	eax, DWORD PTR [eax]
	mov	edx, DWORD PTR [esp+28]
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
.LFE987:
	.size	main, .-main
	.weak	_ZTV5child
	.section	.rodata._ZTV5child,"aG",@progbits,_ZTV5child,comdat
	.align 8
	.type	_ZTV5child, @object
	.size	_ZTV5child, 16
_ZTV5child:
	.long	0
	.long	_ZTI5child
	.long	_ZN5child5printEv
	.long	_ZN5child3addEv
	.weak	_ZTV6parent
	.section	.rodata._ZTV6parent,"aG",@progbits,_ZTV6parent,comdat
	.align 8
	.type	_ZTV6parent, @object
	.size	_ZTV6parent, 16
_ZTV6parent:
	.long	0
	.long	_ZTI6parent
	.long	_ZN6parent5printEv
	.long	_ZN6parent3addEv
	.weak	_ZTS5child
	.section	.rodata._ZTS5child,"aG",@progbits,_ZTS5child,comdat
	.type	_ZTS5child, @object
	.size	_ZTS5child, 7
_ZTS5child:
	.string	"5child"
	.weak	_ZTI5child
	.section	.rodata._ZTI5child,"aG",@progbits,_ZTI5child,comdat
	.align 4
	.type	_ZTI5child, @object
	.size	_ZTI5child, 12
_ZTI5child:
	.long	_ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	_ZTS5child
	.long	_ZTI6parent
	.weak	_ZTS6parent
	.section	.rodata._ZTS6parent,"aG",@progbits,_ZTS6parent,comdat
	.type	_ZTS6parent, @object
	.size	_ZTS6parent, 8
_ZTS6parent:
	.string	"6parent"
	.weak	_ZTI6parent
	.section	.rodata._ZTI6parent,"aG",@progbits,_ZTI6parent,comdat
	.align 4
	.type	_ZTI6parent, @object
	.size	_ZTI6parent, 8
_ZTI6parent:
	.long	_ZTVN10__cxxabiv117__class_type_infoE+8
	.long	_ZTS6parent
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB996:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 24
	cmp	DWORD PTR [ebp+8], 1
	jne	.L9
	cmp	DWORD PTR [ebp+12], 65535
	jne	.L9
	mov	DWORD PTR [esp], OFFSET FLAT:_ZStL8__ioinit
	call	_ZNSt8ios_base4InitC1Ev
	mov	DWORD PTR [esp+8], OFFSET FLAT:__dso_handle
	mov	DWORD PTR [esp+4], OFFSET FLAT:_ZStL8__ioinit
	mov	DWORD PTR [esp], OFFSET FLAT:_ZNSt8ios_base4InitD1Ev
	call	__cxa_atexit
.L9:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE996:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB997:
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
.LFE997:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 4
	.long	_GLOBAL__sub_I_main
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
