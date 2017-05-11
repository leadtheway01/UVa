	.file	"timer.cpp"
	.intel_syntax noprefix
	.section	.text.unlikely,"ax",@progbits
	.type	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc.part.6, @function
_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc.part.6:
.LFB1202:
	.cfi_startproc
	sub	esp, 28
	.cfi_def_cfa_offset 32
	mov	edx, DWORD PTR [eax]
	add	eax, DWORD PTR [edx-12]
	mov	edx, DWORD PTR [eax+20]
	mov	DWORD PTR [esp], eax
	or	edx, 1
	mov	DWORD PTR [esp+4], edx
	call	_ZNSt9basic_iosIcSt11char_traitsIcEE5clearESt12_Ios_Iostate
	add	esp, 28
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE1202:
	.size	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc.part.6, .-_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc.part.6
	.section	.text._ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEED2Ev,"axG",@progbits,_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEED5Ev,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEED2Ev
	.type	_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEED2Ev, @function
_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEED2Ev:
.LFB1103:
	.cfi_startproc
	push	esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	push	ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	sub	esp, 36
	.cfi_def_cfa_offset 48
	mov	ebx, DWORD PTR [esp+48]
	mov	eax, DWORD PTR [ebx+36]
	mov	DWORD PTR [ebx], OFFSET FLAT:_ZTVSt15basic_stringbufIcSt11char_traitsIcESaIcEE+8
	lea	edx, [eax-12]
	cmp	edx, OFFSET FLAT:_ZNSs4_Rep20_S_empty_rep_storageE
	jne	.L11
.L5:
	mov	DWORD PTR [ebx], OFFSET FLAT:_ZTVSt15basic_streambufIcSt11char_traitsIcEE+8
	add	ebx, 28
	mov	DWORD PTR [esp], ebx
	call	_ZNSt6localeD1Ev
	add	esp, 36
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	pop	ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	pop	esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
.L11:
	.cfi_restore_state
	mov	esi, OFFSET FLAT:_ZL28__gthrw___pthread_key_createPjPFvPvE
	test	esi, esi
	lea	ecx, [eax-4]
	je	.L6
	or	eax, -1
	lock xadd	DWORD PTR [ecx], eax
.L7:
	test	eax, eax
	jg	.L5
	lea	eax, [esp+31]
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], edx
	call	_ZNSs4_Rep10_M_destroyERKSaIcE
	jmp	.L5
.L6:
	mov	ecx, DWORD PTR [eax-4]
	lea	esi, [ecx-1]
	mov	DWORD PTR [eax-4], esi
	mov	eax, ecx
	jmp	.L7
	.cfi_endproc
.LFE1103:
	.size	_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEED2Ev, .-_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEED2Ev
	.weak	_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEED1Ev
	.set	_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEED1Ev,_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEED2Ev
	.section	.text._ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEED0Ev,"axG",@progbits,_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEED0Ev,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEED0Ev
	.type	_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEED0Ev, @function
_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEED0Ev:
.LFB1105:
	.cfi_startproc
	push	esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	push	ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	sub	esp, 36
	.cfi_def_cfa_offset 48
	mov	ebx, DWORD PTR [esp+48]
	mov	eax, DWORD PTR [ebx+36]
	mov	DWORD PTR [ebx], OFFSET FLAT:_ZTVSt15basic_stringbufIcSt11char_traitsIcESaIcEE+8
	lea	edx, [eax-12]
	cmp	edx, OFFSET FLAT:_ZNSs4_Rep20_S_empty_rep_storageE
	jne	.L19
.L14:
	lea	eax, [ebx+28]
	mov	DWORD PTR [ebx], OFFSET FLAT:_ZTVSt15basic_streambufIcSt11char_traitsIcEE+8
	mov	DWORD PTR [esp], eax
	call	_ZNSt6localeD1Ev
	mov	DWORD PTR [esp], ebx
	call	_ZdlPv
	add	esp, 36
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	pop	ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	pop	esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
.L19:
	.cfi_restore_state
	mov	esi, OFFSET FLAT:_ZL28__gthrw___pthread_key_createPjPFvPvE
	test	esi, esi
	lea	ecx, [eax-4]
	je	.L15
	or	eax, -1
	lock xadd	DWORD PTR [ecx], eax
.L16:
	test	eax, eax
	jg	.L14
	lea	eax, [esp+31]
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], edx
	call	_ZNSs4_Rep10_M_destroyERKSaIcE
	jmp	.L14
.L15:
	mov	ecx, DWORD PTR [eax-4]
	lea	esi, [ecx-1]
	mov	DWORD PTR [eax-4], esi
	mov	eax, ecx
	jmp	.L16
	.cfi_endproc
.LFE1105:
	.size	_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEED0Ev, .-_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEED0Ev
	.text
	.align 2
	.p2align 4,,15
	.globl	_ZN5timerC2ERS_
	.type	_ZN5timerC2ERS_, @function
_ZN5timerC2ERS_:
.LFB1086:
	.cfi_startproc
	mov	edx, DWORD PTR [esp+8]
	mov	eax, DWORD PTR [esp+4]
	movzx	ecx, BYTE PTR [edx+16]
	mov	BYTE PTR [eax+16], cl
	mov	ecx, DWORD PTR [edx]
	mov	DWORD PTR [eax], ecx
	mov	ecx, DWORD PTR [edx+4]
	mov	DWORD PTR [eax+4], ecx
	mov	ecx, DWORD PTR [edx+8]
	mov	DWORD PTR [eax+8], ecx
	mov	edx, DWORD PTR [edx+12]
	mov	DWORD PTR [eax+12], edx
	ret
	.cfi_endproc
.LFE1086:
	.size	_ZN5timerC2ERS_, .-_ZN5timerC2ERS_
	.globl	_ZN5timerC1ERS_
	.set	_ZN5timerC1ERS_,_ZN5timerC2ERS_
	.align 2
	.p2align 4,,15
	.globl	_ZN5timer5startEv
	.type	_ZN5timer5startEv, @function
_ZN5timer5startEv:
.LFB1088:
	.cfi_startproc
	sub	esp, 28
	.cfi_def_cfa_offset 32
	mov	eax, 1
	mov	edx, DWORD PTR [esp+32]
	cmp	BYTE PTR [edx+16], 0
	jne	.L22
	mov	BYTE PTR [edx+16], 1
	mov	DWORD PTR [esp+4], 0
	mov	DWORD PTR [esp], edx
	call	gettimeofday
	xor	eax, eax
.L22:
	add	esp, 28
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE1088:
	.size	_ZN5timer5startEv, .-_ZN5timer5startEv
	.align 2
	.p2align 4,,15
	.globl	_ZN5timer4stopEv
	.type	_ZN5timer4stopEv, @function
_ZN5timer4stopEv:
.LFB1089:
	.cfi_startproc
	sub	esp, 28
	.cfi_def_cfa_offset 32
	mov	eax, 1
	mov	edx, DWORD PTR [esp+32]
	cmp	BYTE PTR [edx+16], 0
	je	.L26
	mov	BYTE PTR [edx+16], 0
	add	edx, 8
	mov	DWORD PTR [esp+4], 0
	mov	DWORD PTR [esp], edx
	call	gettimeofday
	xor	eax, eax
.L26:
	add	esp, 28
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE1089:
	.size	_ZN5timer4stopEv, .-_ZN5timer4stopEv
	.align 2
	.p2align 4,,15
	.globl	_ZN5timer7getTimeEv
	.type	_ZN5timer7getTimeEv, @function
_ZN5timer7getTimeEv:
.LFB1091:
	.cfi_startproc
	sub	esp, 8
	.cfi_def_cfa_offset 12
	mov	eax, DWORD PTR [esp+12]
	mov	edx, DWORD PTR [eax+8]
	sub	edx, DWORD PTR [eax]
	mov	DWORD PTR [esp], edx
	mov	edx, DWORD PTR [eax+12]
	sub	edx, DWORD PTR [eax+4]
	fild	DWORD PTR [esp]
	mov	DWORD PTR [esp], edx
	fild	DWORD PTR [esp]
	fdiv	DWORD PTR .LC0
	add	esp, 8
	.cfi_def_cfa_offset 4
	faddp	st(1), st
	ret
	.cfi_endproc
.LFE1091:
	.size	_ZN5timer7getTimeEv, .-_ZN5timer7getTimeEv
	.section	.rodata.str1.4,"aMS",@progbits,1
	.align 4
.LC2:
	.string	"basic_string::_S_construct null not valid"
	.section	.text._ZNSs12_S_constructIPcEES0_T_S1_RKSaIcESt20forward_iterator_tag,"axG",@progbits,_ZNSs12_S_constructIPcEES0_T_S1_RKSaIcESt20forward_iterator_tag,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSs12_S_constructIPcEES0_T_S1_RKSaIcESt20forward_iterator_tag
	.type	_ZNSs12_S_constructIPcEES0_T_S1_RKSaIcESt20forward_iterator_tag, @function
_ZNSs12_S_constructIPcEES0_T_S1_RKSaIcESt20forward_iterator_tag:
.LFB1184:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	push	edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	push	esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	push	ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	sub	esp, 28
	.cfi_def_cfa_offset 48
	mov	ebx, DWORD PTR [esp+48]
	mov	eax, DWORD PTR [esp+52]
	cmp	ebx, eax
	je	.L50
	test	ebx, ebx
	je	.L51
	sub	eax, ebx
	mov	ebp, eax
	mov	eax, DWORD PTR [esp+56]
	mov	DWORD PTR [esp+4], 0
	mov	DWORD PTR [esp], ebp
	mov	DWORD PTR [esp+8], eax
	call	_ZNSs4_Rep9_S_createEjjRKSaIcE
	cmp	ebp, 1
	mov	edi, eax
	lea	esi, [eax+12]
	jne	.L40
	movzx	eax, BYTE PTR [ebx]
	mov	BYTE PTR [edi+12], al
.L36:
	cmp	edi, OFFSET FLAT:_ZNSs4_Rep20_S_empty_rep_storageE
	jne	.L52
.L43:
	add	esp, 28
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	mov	eax, esi
	pop	ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	pop	esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	pop	edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	pop	ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
.L53:
	.cfi_restore_state
	mov	eax, DWORD PTR [esp+56]
	xor	ebp, ebp
	mov	DWORD PTR [esp+4], 0
	mov	DWORD PTR [esp], 0
	mov	DWORD PTR [esp+8], eax
	call	_ZNSs4_Rep9_S_createEjjRKSaIcE
	mov	edi, eax
	lea	esi, [eax+12]
	.p2align 4,,7
	.p2align 3
.L40:
	mov	DWORD PTR [esp+8], ebp
	mov	DWORD PTR [esp+4], ebx
	mov	DWORD PTR [esp], esi
	call	memcpy
	jmp	.L36
	.p2align 4,,7
	.p2align 3
.L50:
	add	esp, 28
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	mov	esi, OFFSET FLAT:_ZNSs4_Rep20_S_empty_rep_storageE+12
	pop	ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	mov	eax, esi
	pop	esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	pop	edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	pop	ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,7
	.p2align 3
.L51:
	.cfi_restore_state
	test	eax, eax
	je	.L53
	mov	DWORD PTR [esp], OFFSET FLAT:.LC2
	call	_ZSt19__throw_logic_errorPKc
.L52:
	mov	DWORD PTR [edi+8], 0
	mov	DWORD PTR [edi], ebp
	mov	BYTE PTR [esi+ebp], 0
	jmp	.L43
	.cfi_endproc
.LFE1184:
	.size	_ZNSs12_S_constructIPcEES0_T_S1_RKSaIcESt20forward_iterator_tag, .-_ZNSs12_S_constructIPcEES0_T_S1_RKSaIcESt20forward_iterator_tag
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC3:
	.string	""
.LC4:
	.string	"0"
.LC5:
	.string	"Timer still running\n"
.LC6:
	.string	"."
	.text
	.align 2
	.p2align 4,,15
	.globl	_ZN5timer8toStringEv
	.type	_ZN5timer8toStringEv, @function
_ZN5timer8toStringEv:
.LFB1092:
	.cfi_startproc
	.cfi_personality 0,__gxx_personality_v0
	.cfi_lsda 0,.LLSDA1092
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	push	edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	push	esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	push	ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	sub	esp, 252
	.cfi_def_cfa_offset 272
	lea	edi, [esp+104]
	mov	ebx, DWORD PTR [esp+276]
	mov	DWORD PTR [esp], edi
	call	_ZNSt8ios_baseC2Ev
	mov	ebp, DWORD PTR _ZTTSt19basic_ostringstreamIcSt11char_traitsIcESaIcEE+4
	lea	eax, [esp+60]
	mov	ecx, DWORD PTR _ZTTSt19basic_ostringstreamIcSt11char_traitsIcESaIcEE+8
	mov	BYTE PTR [esp+220], 0
	mov	DWORD PTR [esp+104], OFFSET FLAT:_ZTVSt9basic_iosIcSt11char_traitsIcEE+8
	add	eax, DWORD PTR [ebp-12]
	mov	DWORD PTR [esp+216], 0
	mov	BYTE PTR [esp+221], 0
	mov	DWORD PTR [esp+224], 0
	mov	DWORD PTR [esp+228], 0
	mov	DWORD PTR [esp+232], 0
	mov	DWORD PTR [esp+236], 0
	mov	DWORD PTR [esp+60], ebp
	mov	DWORD PTR [eax], ecx
	mov	DWORD PTR [esp+4], 0
	mov	DWORD PTR [esp], eax
.LEHB0:
	call	_ZNSt9basic_iosIcSt11char_traitsIcEE4initEPSt15basic_streambufIcS1_E
.LEHE0:
	lea	eax, [esp+92]
	mov	DWORD PTR [esp], eax
	lea	esi, [esp+64]
	mov	DWORD PTR [esp+60], OFFSET FLAT:_ZTVSt19basic_ostringstreamIcSt11char_traitsIcESaIcEE+12
	mov	DWORD PTR [esp+104], OFFSET FLAT:_ZTVSt19basic_ostringstreamIcSt11char_traitsIcESaIcEE+32
	mov	DWORD PTR [esp+64], OFFSET FLAT:_ZTVSt15basic_streambufIcSt11char_traitsIcEE+8
	mov	DWORD PTR [esp+68], 0
	mov	DWORD PTR [esp+72], 0
	mov	DWORD PTR [esp+76], 0
	mov	DWORD PTR [esp+80], 0
	mov	DWORD PTR [esp+84], 0
	mov	DWORD PTR [esp+88], 0
	call	_ZNSt6localeC1Ev
	mov	DWORD PTR [esp+4], esi
	mov	DWORD PTR [esp], edi
	mov	DWORD PTR [esp+64], OFFSET FLAT:_ZTVSt15basic_stringbufIcSt11char_traitsIcESaIcEE+8
	mov	DWORD PTR [esp+96], 16
	mov	DWORD PTR [esp+100], OFFSET FLAT:_ZNSs4_Rep20_S_empty_rep_storageE+12
.LEHB1:
	call	_ZNSt9basic_iosIcSt11char_traitsIcEE4initEPSt15basic_streambufIcS1_E
.LEHE1:
	cmp	BYTE PTR [ebx+16], 0
	jne	.L112
	mov	eax, DWORD PTR [ebx+8]
	mov	esi, DWORD PTR [ebx+12]
	sub	eax, DWORD PTR [ebx]
	sub	esi, DWORD PTR [ebx+4]
	js	.L113
.L61:
	cmp	esi, 9
	jle	.L89
	cmp	esi, 99
	jle	.L90
	cmp	esi, 999
	jle	.L91
	cmp	esi, 9999
	jle	.L92
	cmp	esi, 99999
	mov	DWORD PTR [esp+40], OFFSET FLAT:.LC3
	mov	DWORD PTR [esp+36], OFFSET FLAT:.LC3
	mov	DWORD PTR [esp+32], OFFSET FLAT:.LC3
	mov	DWORD PTR [esp+28], OFFSET FLAT:.LC3
	jle	.L88
	mov	DWORD PTR [esp+44], OFFSET FLAT:.LC3
.L65:
	mov	DWORD PTR [esp+4], eax
	lea	eax, [esp+60]
	mov	DWORD PTR [esp], eax
.LEHB2:
	call	_ZNSo9_M_insertIlEERSoT_
	mov	DWORD PTR [esp+8], 1
	mov	ebx, eax
	mov	DWORD PTR [esp+4], OFFSET FLAT:.LC6
	mov	DWORD PTR [esp], eax
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	mov	eax, DWORD PTR [esp+44]
	mov	DWORD PTR [esp], eax
	call	strlen
	mov	DWORD PTR [esp], ebx
	mov	DWORD PTR [esp+8], eax
	mov	eax, DWORD PTR [esp+44]
	mov	DWORD PTR [esp+4], eax
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	mov	eax, DWORD PTR [esp+40]
	mov	DWORD PTR [esp], eax
	call	strlen
	mov	DWORD PTR [esp], ebx
	mov	DWORD PTR [esp+8], eax
	mov	eax, DWORD PTR [esp+40]
	mov	DWORD PTR [esp+4], eax
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	mov	eax, DWORD PTR [esp+36]
	mov	DWORD PTR [esp], eax
	call	strlen
	mov	DWORD PTR [esp], ebx
	mov	DWORD PTR [esp+8], eax
	mov	eax, DWORD PTR [esp+36]
	mov	DWORD PTR [esp+4], eax
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	mov	eax, DWORD PTR [esp+32]
	mov	DWORD PTR [esp], eax
	call	strlen
	mov	DWORD PTR [esp], ebx
	mov	DWORD PTR [esp+8], eax
	mov	eax, DWORD PTR [esp+32]
	mov	DWORD PTR [esp+4], eax
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	mov	eax, DWORD PTR [esp+28]
	mov	DWORD PTR [esp], eax
	call	strlen
	mov	DWORD PTR [esp], ebx
	mov	DWORD PTR [esp+8], eax
	mov	eax, DWORD PTR [esp+28]
	mov	DWORD PTR [esp+4], eax
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	mov	DWORD PTR [esp+4], esi
	mov	DWORD PTR [esp], ebx
	call	_ZNSo9_M_insertIlEERSoT_
.LEHE2:
.L66:
	mov	eax, DWORD PTR [esp+272]
	mov	DWORD PTR [eax], OFFSET FLAT:_ZNSs4_Rep20_S_empty_rep_storageE+12
	mov	eax, DWORD PTR [esp+84]
	test	eax, eax
	je	.L114
	mov	edx, DWORD PTR [esp+76]
	mov	BYTE PTR [esp+12], 0
	cmp	eax, edx
	jbe	.L67
	mov	DWORD PTR [esp+4], eax
	mov	eax, DWORD PTR [esp+80]
	lea	edx, [esp+55]
	mov	DWORD PTR [esp+8], edx
	mov	DWORD PTR [esp], eax
.LEHB3:
	call	_ZNSs12_S_constructIPcEES0_T_S1_RKSaIcESt20forward_iterator_tag
.LEHE3:
	mov	DWORD PTR [esp+56], eax
	mov	eax, DWORD PTR [esp+272]
	lea	ebx, [esp+56]
	mov	DWORD PTR [esp+4], ebx
	mov	DWORD PTR [esp], eax
.LEHB4:
	call	_ZNSs6assignERKSs
.LEHE4:
.L111:
	mov	eax, DWORD PTR [esp+56]
	lea	edx, [eax-12]
	cmp	edx, OFFSET FLAT:_ZNSs4_Rep20_S_empty_rep_storageE
	jne	.L115
.L73:
	mov	eax, DWORD PTR [esp+100]
	mov	DWORD PTR [esp+60], OFFSET FLAT:_ZTVSt19basic_ostringstreamIcSt11char_traitsIcESaIcEE+12
	mov	DWORD PTR [esp+104], OFFSET FLAT:_ZTVSt19basic_ostringstreamIcSt11char_traitsIcESaIcEE+32
	mov	DWORD PTR [esp+64], OFFSET FLAT:_ZTVSt15basic_stringbufIcSt11char_traitsIcESaIcEE+8
	lea	edx, [eax-12]
	cmp	edx, OFFSET FLAT:_ZNSs4_Rep20_S_empty_rep_storageE
	jne	.L116
.L84:
	lea	eax, [esp+92]
	mov	DWORD PTR [esp], eax
	mov	DWORD PTR [esp+64], OFFSET FLAT:_ZTVSt15basic_streambufIcSt11char_traitsIcEE+8
	call	_ZNSt6localeD1Ev
	mov	eax, DWORD PTR [ebp-12]
	mov	ecx, DWORD PTR _ZTTSt19basic_ostringstreamIcSt11char_traitsIcESaIcEE+8
	mov	DWORD PTR [esp+60], ebp
	mov	DWORD PTR [esp+60+eax], ecx
	mov	DWORD PTR [esp], edi
	mov	DWORD PTR [esp+104], OFFSET FLAT:_ZTVSt9basic_iosIcSt11char_traitsIcEE+8
.LEHB5:
	call	_ZNSt8ios_baseD2Ev
.LEHE5:
	mov	eax, DWORD PTR [esp+272]
	add	esp, 252
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	pop	ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	pop	esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	pop	edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	pop	ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret	4
	.p2align 4,,7
	.p2align 3
.L89:
	.cfi_restore_state
	mov	DWORD PTR [esp+28], OFFSET FLAT:.LC4
.L62:
	mov	DWORD PTR [esp+32], OFFSET FLAT:.LC4
.L63:
	mov	DWORD PTR [esp+36], OFFSET FLAT:.LC4
.L64:
	mov	DWORD PTR [esp+40], OFFSET FLAT:.LC4
.L88:
	mov	DWORD PTR [esp+44], OFFSET FLAT:.LC4
	jmp	.L65
	.p2align 4,,7
	.p2align 3
.L67:
	lea	eax, [esp+55]
	mov	DWORD PTR [esp+8], eax
	mov	eax, DWORD PTR [esp+80]
	mov	DWORD PTR [esp+4], edx
	mov	DWORD PTR [esp], eax
.LEHB6:
	call	_ZNSs12_S_constructIPcEES0_T_S1_RKSaIcESt20forward_iterator_tag
.LEHE6:
	mov	DWORD PTR [esp+56], eax
	mov	eax, DWORD PTR [esp+272]
	lea	ebx, [esp+56]
	mov	DWORD PTR [esp+4], ebx
	mov	DWORD PTR [esp], eax
.LEHB7:
	call	_ZNSs6assignERKSs
.LEHE7:
	jmp	.L111
	.p2align 4,,7
	.p2align 3
.L112:
	lea	eax, [esp+60]
	mov	DWORD PTR [esp+8], 20
	mov	DWORD PTR [esp+4], OFFSET FLAT:.LC5
	mov	DWORD PTR [esp], eax
.LEHB8:
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
.LEHE8:
	jmp	.L66
	.p2align 4,,7
	.p2align 3
.L113:
	sub	eax, 1
	add	esi, 1000000
	jmp	.L61
	.p2align 4,,7
	.p2align 3
.L114:
	lea	eax, [esp+100]
	mov	DWORD PTR [esp+4], eax
	mov	eax, DWORD PTR [esp+272]
	mov	DWORD PTR [esp], eax
.LEHB9:
	call	_ZNSs6assignERKSs
.LEHE9:
	jmp	.L73
.L116:
	mov	ebx, OFFSET FLAT:_ZL28__gthrw___pthread_key_createPjPFvPvE
	test	ebx, ebx
	lea	ecx, [eax-4]
	je	.L85
	or	eax, -1
	lock xadd	DWORD PTR [ecx], eax
	mov	ecx, eax
.L86:
	test	ecx, ecx
	jg	.L84
	lea	eax, [esp+56]
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], edx
	call	_ZNSs4_Rep10_M_destroyERKSaIcE
	jmp	.L84
.L115:
	mov	ebx, OFFSET FLAT:_ZL28__gthrw___pthread_key_createPjPFvPvE
	test	ebx, ebx
	lea	ecx, [eax-4]
	je	.L76
	or	eax, -1
	lock xadd	DWORD PTR [ecx], eax
	mov	ecx, eax
.L77:
	test	ecx, ecx
	jg	.L73
	lea	eax, [esp+54]
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], edx
	call	_ZNSs4_Rep10_M_destroyERKSaIcE
	jmp	.L73
.L96:
	mov	DWORD PTR [esp], esi
	mov	ebx, eax
	call	_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEED1Ev
	mov	eax, DWORD PTR [ebp-12]
	mov	ecx, DWORD PTR _ZTTSt19basic_ostringstreamIcSt11char_traitsIcESaIcEE+8
	mov	DWORD PTR [esp+60], ebp
	mov	DWORD PTR [esp+60+eax], ecx
.L57:
	mov	DWORD PTR [esp], edi
	mov	DWORD PTR [esp+104], OFFSET FLAT:_ZTVSt9basic_iosIcSt11char_traitsIcEE+8
	call	_ZNSt8ios_baseD2Ev
	mov	DWORD PTR [esp], ebx
.LEHB10:
	call	_Unwind_Resume
.LEHE10:
.L95:
	mov	ebx, eax
	jmp	.L57
.L76:
	mov	ecx, DWORD PTR [eax-4]
	lea	ebx, [ecx-1]
	mov	DWORD PTR [eax-4], ebx
	jmp	.L77
.L90:
	mov	DWORD PTR [esp+28], OFFSET FLAT:.LC3
	jmp	.L62
.L91:
	mov	DWORD PTR [esp+32], OFFSET FLAT:.LC3
	mov	DWORD PTR [esp+28], OFFSET FLAT:.LC3
	jmp	.L63
.L98:
.L104:
	mov	esi, eax
	lea	eax, [esp+54]
	mov	DWORD PTR [esp+4], eax
	mov	eax, DWORD PTR [esp+56]
	sub	eax, 12
	mov	DWORD PTR [esp], eax
	call	_ZNSs4_Rep10_M_disposeERKSaIcE
.L80:
	mov	eax, DWORD PTR [esp+272]
	mov	DWORD PTR [esp+4], ebx
	mov	eax, DWORD PTR [eax]
	sub	eax, 12
	mov	DWORD PTR [esp], eax
	call	_ZNSs4_Rep10_M_disposeERKSaIcE
.L82:
	lea	eax, [esp+60]
	mov	DWORD PTR [esp], eax
	call	_ZNSt19basic_ostringstreamIcSt11char_traitsIcESaIcEED1Ev
	mov	DWORD PTR [esp], esi
.LEHB11:
	call	_Unwind_Resume
.LEHE11:
.L97:
	mov	esi, eax
	lea	ebx, [esp+56]
	jmp	.L80
.L92:
	mov	DWORD PTR [esp+36], OFFSET FLAT:.LC3
	mov	DWORD PTR [esp+32], OFFSET FLAT:.LC3
	mov	DWORD PTR [esp+28], OFFSET FLAT:.LC3
	jmp	.L64
.L94:
	mov	esi, eax
	jmp	.L82
.L99:
	jmp	.L104
.L85:
	mov	ecx, DWORD PTR [eax-4]
	lea	ebx, [ecx-1]
	mov	DWORD PTR [eax-4], ebx
	jmp	.L86
	.cfi_endproc
.LFE1092:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA1092:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1092-.LLSDACSB1092
.LLSDACSB1092:
	.uleb128 .LEHB0-.LFB1092
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L95-.LFB1092
	.uleb128 0
	.uleb128 .LEHB1-.LFB1092
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L96-.LFB1092
	.uleb128 0
	.uleb128 .LEHB2-.LFB1092
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L94-.LFB1092
	.uleb128 0
	.uleb128 .LEHB3-.LFB1092
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L97-.LFB1092
	.uleb128 0
	.uleb128 .LEHB4-.LFB1092
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L99-.LFB1092
	.uleb128 0
	.uleb128 .LEHB5-.LFB1092
	.uleb128 .LEHE5-.LEHB5
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB6-.LFB1092
	.uleb128 .LEHE6-.LEHB6
	.uleb128 .L97-.LFB1092
	.uleb128 0
	.uleb128 .LEHB7-.LFB1092
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L98-.LFB1092
	.uleb128 0
	.uleb128 .LEHB8-.LFB1092
	.uleb128 .LEHE8-.LEHB8
	.uleb128 .L94-.LFB1092
	.uleb128 0
	.uleb128 .LEHB9-.LFB1092
	.uleb128 .LEHE9-.LEHB9
	.uleb128 .L97-.LFB1092
	.uleb128 0
	.uleb128 .LEHB10-.LFB1092
	.uleb128 .LEHE10-.LEHB10
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB11-.LFB1092
	.uleb128 .LEHE11-.LEHB11
	.uleb128 0
	.uleb128 0
.LLSDACSE1092:
	.text
	.size	_ZN5timer8toStringEv, .-_ZN5timer8toStringEv
	.align 2
	.p2align 4,,15
	.globl	_ZN5timer5printERSo
	.type	_ZN5timer5printERSo, @function
_ZN5timer5printERSo:
.LFB1090:
	.cfi_startproc
	.cfi_personality 0,__gxx_personality_v0
	.cfi_lsda 0,.LLSDA1090
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	push	esi
	push	ebx
	sub	esp, 32
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	mov	edx, DWORD PTR [ebp+8]
	lea	eax, [ebp-12]
	mov	DWORD PTR [esp], eax
	mov	DWORD PTR [esp+4], edx
.LEHB12:
	call	_ZN5timer8toStringEv
.LEHE12:
	mov	eax, DWORD PTR [ebp-12]
	mov	edx, DWORD PTR [eax-12]
	sub	esp, 4
	mov	DWORD PTR [esp+4], eax
	mov	eax, DWORD PTR [ebp+12]
	mov	DWORD PTR [esp+8], edx
	mov	DWORD PTR [esp], eax
.LEHB13:
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
.LEHE13:
	mov	edx, DWORD PTR [ebp-12]
	lea	ecx, [edx-12]
	cmp	ecx, OFFSET FLAT:_ZNSs4_Rep20_S_empty_rep_storageE
	jne	.L127
.L125:
	lea	esp, [ebp-8]
	pop	ebx
	.cfi_remember_state
	.cfi_restore 3
	pop	esi
	.cfi_restore 6
	pop	ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
.L127:
	.cfi_restore_state
	mov	esi, OFFSET FLAT:_ZL28__gthrw___pthread_key_createPjPFvPvE
	test	esi, esi
	lea	ebx, [edx-4]
	je	.L120
	or	edx, -1
	lock xadd	DWORD PTR [ebx], edx
.L121:
	test	edx, edx
	jg	.L125
	lea	edx, [ebp-13]
	mov	DWORD PTR [esp+4], edx
	mov	DWORD PTR [esp], ecx
	mov	DWORD PTR [ebp-28], eax
	call	_ZNSs4_Rep10_M_destroyERKSaIcE
	mov	eax, DWORD PTR [ebp-28]
	jmp	.L125
.L124:
	mov	ebx, eax
	lea	eax, [ebp-13]
	mov	DWORD PTR [esp+4], eax
	mov	eax, DWORD PTR [ebp-12]
	sub	eax, 12
	mov	DWORD PTR [esp], eax
	call	_ZNSs4_Rep10_M_disposeERKSaIcE
	mov	DWORD PTR [esp], ebx
.LEHB14:
	call	_Unwind_Resume
.LEHE14:
.L120:
	mov	ebx, DWORD PTR [edx-4]
	lea	esi, [ebx-1]
	mov	DWORD PTR [edx-4], esi
	mov	edx, ebx
	jmp	.L121
	.cfi_endproc
.LFE1090:
	.section	.gcc_except_table
.LLSDA1090:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1090-.LLSDACSB1090
.LLSDACSB1090:
	.uleb128 .LEHB12-.LFB1090
	.uleb128 .LEHE12-.LEHB12
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB13-.LFB1090
	.uleb128 .LEHE13-.LEHB13
	.uleb128 .L124-.LFB1090
	.uleb128 0
	.uleb128 .LEHB14-.LFB1090
	.uleb128 .LEHE14-.LEHB14
	.uleb128 0
	.uleb128 0
.LLSDACSE1090:
	.text
	.size	_ZN5timer5printERSo, .-_ZN5timer5printERSo
	.p2align 4,,15
	.globl	_ZlsRSoR5timer
	.type	_ZlsRSoR5timer, @function
_ZlsRSoR5timer:
.LFB1093:
	.cfi_startproc
	mov	eax, DWORD PTR [esp+8]
	mov	edx, DWORD PTR [esp+4]
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp+8], edx
	jmp	_ZN5timer5printERSo
	.cfi_endproc
.LFE1093:
	.size	_ZlsRSoR5timer, .-_ZlsRSoR5timer
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.type	_GLOBAL__sub_I__ZN5timerC2ERS_, @function
_GLOBAL__sub_I__ZN5timerC2ERS_:
.LFB1195:
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
.LFE1195:
	.size	_GLOBAL__sub_I__ZN5timerC2ERS_, .-_GLOBAL__sub_I__ZN5timerC2ERS_
	.section	.init_array,"aw"
	.align 4
	.long	_GLOBAL__sub_I__ZN5timerC2ERS_
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.weakref	_ZL28__gthrw___pthread_key_createPjPFvPvE,__pthread_key_create
	.section	.rodata.cst4,"aM",@progbits,4
	.align 4
.LC0:
	.long	1232348160
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
