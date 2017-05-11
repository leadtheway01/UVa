	.file	"mathlibtest.cpp"
	.section	.debug_info,"",@progbits
.Lsection_info:
	.section	.debug_abbrev,"",@progbits
.Lsection_abbrev:
	.section	.debug_aranges,"",@progbits
	.section	.debug_macinfo,"",@progbits
	.section	.debug_line,"",@progbits
.Lsection_line:
	.section	.debug_loc,"",@progbits
	.section	.debug_pubnames,"",@progbits
	.section	.debug_pubtypes,"",@progbits
	.section	.debug_str,"MS",@progbits,1
.Linfo_string:
	.section	.debug_ranges,"",@progbits
.Ldebug_range:
	.section	.debug_loc,"",@progbits
.Lsection_debug_loc:
	.text
.Ltext_begin:
	.data
	.file	1 "mathlibtest.cpp"
	.file	2 "/usr/bin/../lib/gcc/x86_64-linux-gnu/4.8/../../../../include/x86_64-linux-gnu/c++/4.8/32/bits/c++config.h"
	.file	3 "/usr/bin/../lib/gcc/x86_64-linux-gnu/4.8/../../../../include/c++/4.8/bits/ios_base.h"
	.file	4 "/usr/bin/../lib/gcc/x86_64-linux-gnu/4.8/../../../../include/c++/4.8/iostream"
	.file	5 "/usr/bin/../lib/gcc/x86_64-linux-gnu/4.8/../../../../include/c++/4.8/debug/debug.h"
	.section	.text.startup,"ax",@progbits
	.align	16, 0x90
	.type	__cxx_global_var_init,@function
__cxx_global_var_init:                  # @__cxx_global_var_init
	.cfi_startproc
.Lfunc_begin0:
	.loc	4 74 0                  # /usr/bin/../lib/gcc/x86_64-linux-gnu/4.8/../../../../include/c++/4.8/iostream:74:0
# BB#0:
	pushl	%ebp
.Ltmp2:
	.cfi_def_cfa_offset 8
.Ltmp3:
	.cfi_offset %ebp, -8
	movl	%esp, %ebp
.Ltmp4:
	.cfi_def_cfa_register %ebp
	subl	$24, %esp
	leal	_ZStL8__ioinit, %eax
	.loc	4 74 0 prologue_end     # /usr/bin/../lib/gcc/x86_64-linux-gnu/4.8/../../../../include/c++/4.8/iostream:74:0
.Ltmp5:
	movl	%eax, (%esp)
	calll	_ZNSt8ios_base4InitC1Ev
	leal	_ZNSt8ios_base4InitD1Ev, %eax
	leal	_ZStL8__ioinit, %ecx
	leal	__dso_handle, %edx
	movl	%eax, (%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, 8(%esp)
	calll	__cxa_atexit
	movl	%eax, -4(%ebp)          # 4-byte Spill
	addl	$24, %esp
	popl	%ebp
	ret
.Ltmp6:
.Ltmp7:
	.size	__cxx_global_var_init, .Ltmp7-__cxx_global_var_init
.Lfunc_end0:
	.cfi_endproc

	.text
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
.Lfunc_begin1:
	.loc	1 9 0                   # mathlibtest.cpp:9:0
# BB#0:
	pushl	%ebp
.Ltmp10:
	.cfi_def_cfa_offset 8
.Ltmp11:
	.cfi_offset %ebp, -8
	movl	%esp, %ebp
.Ltmp12:
	.cfi_def_cfa_register %ebp
	subl	$40, %esp
	leal	_ZSt4cout, %eax
	leal	.L.str, %ecx
	.loc	1 10 0 prologue_end     # mathlibtest.cpp:10:0
.Ltmp13:
	movl	$0, -4(%ebp)
	.loc	1 11 0                  # mathlibtest.cpp:11:0
	movl	$0, -8(%ebp)
	.loc	1 12 0                  # mathlibtest.cpp:12:0
	movl	%eax, (%esp)
	movl	%ecx, 4(%esp)
	calll	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	.L.str1, %ecx
	movl	%eax, (%esp)
	movl	%ecx, 4(%esp)
	calll	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	_ZSt3cin, %ecx
	leal	-4(%ebp), %edx
	.loc	1 13 0                  # mathlibtest.cpp:13:0
	movl	%ecx, (%esp)
	movl	%edx, 4(%esp)
	movl	%eax, -12(%ebp)         # 4-byte Spill
	calll	_ZNSirsERi
	leal	_ZSt3cin, %ecx
	leal	-8(%ebp), %edx
	.loc	1 14 0                  # mathlibtest.cpp:14:0
	movl	%ecx, (%esp)
	movl	%edx, 4(%esp)
	movl	%eax, -16(%ebp)         # 4-byte Spill
	calll	_ZNSirsERi
	.loc	1 16 0                  # mathlibtest.cpp:16:0
	movl	-4(%ebp), %ecx
	movl	-8(%ebp), %edx
	movl	%ecx, (%esp)
	movl	%edx, 4(%esp)
	movl	%eax, -20(%ebp)         # 4-byte Spill
	calll	_Z7productii
	leal	_ZSt4cout, %ecx
	movl	%ecx, (%esp)
	movl	%eax, 4(%esp)
	calll	_ZNSolsEi
	leal	.L.str1, %ecx
	movl	%eax, (%esp)
	movl	%ecx, 4(%esp)
	calll	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	.loc	1 17 0                  # mathlibtest.cpp:17:0
	movl	-4(%ebp), %ecx
	movl	-8(%ebp), %edx
	movl	%ecx, (%esp)
	movl	%edx, 4(%esp)
	movl	%eax, -24(%ebp)         # 4-byte Spill
	calll	_Z5powerii
	leal	_ZSt4cout, %ecx
	movl	%ecx, (%esp)
	movl	%eax, 4(%esp)
	calll	_ZNSolsEi
	leal	.L.str1, %ecx
	movl	%eax, (%esp)
	movl	%ecx, 4(%esp)
	calll	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$0, %ecx
	.loc	1 18 0                  # mathlibtest.cpp:18:0
	movl	%eax, -28(%ebp)         # 4-byte Spill
	movl	%ecx, %eax
	addl	$40, %esp
	popl	%ebp
	ret
.Ltmp14:
.Ltmp15:
	.size	main, .Ltmp15-main
.Lfunc_end1:
	.cfi_endproc

	.globl	_Z7productii
	.align	16, 0x90
	.type	_Z7productii,@function
_Z7productii:                           # @_Z7productii
	.cfi_startproc
.Lfunc_begin2:
	.loc	1 20 0                  # mathlibtest.cpp:20:0
# BB#0:
	pushl	%ebp
.Ltmp18:
	.cfi_def_cfa_offset 8
.Ltmp19:
	.cfi_offset %ebp, -8
	movl	%esp, %ebp
.Ltmp20:
	.cfi_def_cfa_register %ebp
	subl	$16, %esp
	movl	12(%ebp), %eax
	movl	8(%ebp), %ecx
	movl	%ecx, -4(%ebp)
	movl	%eax, -8(%ebp)
	.loc	1 21 0 prologue_end     # mathlibtest.cpp:21:0
.Ltmp21:
	movl	$0, -12(%ebp)
	.loc	1 22 0                  # mathlibtest.cpp:22:0
	movl	$0, -16(%ebp)
.LBB2_1:                                # =>This Inner Loop Header: Depth=1
	.loc	1 23 0                  # mathlibtest.cpp:23:0
	movl	-16(%ebp), %eax
	cmpl	-8(%ebp), %eax
	jge	.LBB2_3
# BB#2:                                 #   in Loop: Header=BB2_1 Depth=1
	.loc	1 24 0                  # mathlibtest.cpp:24:0
.Ltmp22:
	movl	-4(%ebp), %eax
	movl	-12(%ebp), %ecx
	addl	%eax, %ecx
	movl	%ecx, -12(%ebp)
	.loc	1 25 0                  # mathlibtest.cpp:25:0
	movl	-16(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -16(%ebp)
	.loc	1 26 0                  # mathlibtest.cpp:26:0
	jmp	.LBB2_1
.Ltmp23:
.LBB2_3:
	.loc	1 30 0                  # mathlibtest.cpp:30:0
	movl	-12(%ebp), %eax
	addl	$16, %esp
	popl	%ebp
	ret
.Ltmp24:
.Ltmp25:
	.size	_Z7productii, .Ltmp25-_Z7productii
.Lfunc_end2:
	.cfi_endproc

	.globl	_Z5powerii
	.align	16, 0x90
	.type	_Z5powerii,@function
_Z5powerii:                             # @_Z5powerii
	.cfi_startproc
.Lfunc_begin3:
	.loc	1 33 0                  # mathlibtest.cpp:33:0
# BB#0:
	pushl	%ebp
.Ltmp28:
	.cfi_def_cfa_offset 8
.Ltmp29:
	.cfi_offset %ebp, -8
	movl	%esp, %ebp
.Ltmp30:
	.cfi_def_cfa_register %ebp
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	8(%ebp), %ecx
	movl	%ecx, -4(%ebp)
	movl	%eax, -8(%ebp)
	.loc	1 35 0 prologue_end     # mathlibtest.cpp:35:0
.Ltmp31:
	cmpl	$0, -8(%ebp)
	jne	.LBB3_2
# BB#1:
	.loc	1 36 0                  # mathlibtest.cpp:36:0
.Ltmp32:
	movl	$1, -12(%ebp)
	.loc	1 37 0                  # mathlibtest.cpp:37:0
	jmp	.LBB3_3
.Ltmp33:
.LBB3_2:
	.loc	1 39 0                  # mathlibtest.cpp:39:0
	movl	-4(%ebp), %eax
	movl	-4(%ebp), %ecx
	movl	-8(%ebp), %edx
	subl	$1, %edx
	movl	%ecx, (%esp)
	movl	%edx, 4(%esp)
	movl	%eax, -16(%ebp)         # 4-byte Spill
	calll	_Z5powerii
	movl	-16(%ebp), %ecx         # 4-byte Reload
	imull	%eax, %ecx
	movl	%ecx, -12(%ebp)
.Ltmp34:
.LBB3_3:
	.loc	1 41 0                  # mathlibtest.cpp:41:0
	movl	-12(%ebp), %eax
	addl	$24, %esp
	popl	%ebp
	ret
.Ltmp35:
.Ltmp36:
	.size	_Z5powerii, .Ltmp36-_Z5powerii
.Lfunc_end3:
	.cfi_endproc

	.section	.text.startup,"ax",@progbits
	.align	16, 0x90
	.type	_GLOBAL__I_a,@function
_GLOBAL__I_a:                           # @_GLOBAL__I_a
	.cfi_startproc
.Lfunc_begin4:
	.loc	1 42 0                  # mathlibtest.cpp:42:0
# BB#0:
	pushl	%ebp
.Ltmp39:
	.cfi_def_cfa_offset 8
.Ltmp40:
	.cfi_offset %ebp, -8
	movl	%esp, %ebp
.Ltmp41:
	.cfi_def_cfa_register %ebp
	.loc	1 42 0 prologue_end     # mathlibtest.cpp:42:0
.Ltmp42:
	subl	$8, %esp
	calll	__cxx_global_var_init
	addl	$8, %esp
	popl	%ebp
	ret
.Ltmp43:
.Ltmp44:
	.size	_GLOBAL__I_a, .Ltmp44-_GLOBAL__I_a
.Lfunc_end4:
	.cfi_endproc

	.type	_ZStL8__ioinit,@object  # @_ZStL8__ioinit
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"enter two integer numbers: "
	.size	.L.str, 28

	.type	.L.str1,@object         # @.str1
.L.str1:
	.asciz	"\n"
	.size	.L.str1, 2

	.section	.init_array,"aw",@init_array
	.align	4
	.long	_GLOBAL__I_a
	.section	.text.startup,"ax",@progbits
.Ldebug_end1:
	.text
.Ldebug_end2:
	.section	.debug_str,"MS",@progbits,1
.Linfo_string0:
	.asciz	"Ubuntu clang version 3.4-1ubuntu3 (tags/RELEASE_34/final) (based on LLVM 3.4)"
.Linfo_string1:
	.asciz	"mathlibtest.cpp"
.Linfo_string2:
	.asciz	"/home/parallels/Documents/lab/lab8"
.Linfo_string3:
	.asciz	"std"
.Linfo_string4:
	.asciz	"__ioinit"
.Linfo_string5:
	.asciz	"ios_base"
.Linfo_string6:
	.asciz	"_S_refcount"
.Linfo_string7:
	.asciz	"int"
.Linfo_string8:
	.asciz	"_Atomic_word"
.Linfo_string9:
	.asciz	"_S_synced_with_stdio"
.Linfo_string10:
	.asciz	"bool"
.Linfo_string11:
	.asciz	"Init"
.Linfo_string12:
	.asciz	"~Init"
.Linfo_string13:
	.asciz	"_ZStL8__ioinit"
.Linfo_string14:
	.asciz	"__cxx_global_var_init"
.Linfo_string15:
	.asciz	"main"
.Linfo_string16:
	.asciz	"_Z7productii"
.Linfo_string17:
	.asciz	"product"
.Linfo_string18:
	.asciz	"_Z5powerii"
.Linfo_string19:
	.asciz	"power"
.Linfo_string20:
	.asciz	"_GLOBAL__I_a"
.Linfo_string21:
	.asciz	"__gnu_debug"
.Linfo_string22:
	.asciz	"__debug"
.Linfo_string23:
	.asciz	"x"
.Linfo_string24:
	.asciz	"y"
.Linfo_string25:
	.asciz	"retVal"
.Linfo_string26:
	.asciz	"i"
.Linfo_string27:
	.byte	0
	.section	.debug_info,"",@progbits
.L.debug_info_begin0:
	.long	430                     # Length of Unit
	.short	4                       # DWARF version number
	.long	.L.debug_abbrev_begin   # Offset Into Abbrev. Section
	.byte	4                       # Address Size (in bytes)
	.byte	1                       # Abbrev [1] 0xb:0x1a7 DW_TAG_compile_unit
	.long	.Linfo_string0          # DW_AT_producer
	.short	4                       # DW_AT_language
	.long	.Linfo_string1          # DW_AT_name
	.long	0                       # DW_AT_low_pc
	.long	.Lsection_line          # DW_AT_stmt_list
	.long	.Linfo_string2          # DW_AT_comp_dir
	.byte	2                       # Abbrev [2] 0x22:0x66 DW_TAG_namespace
	.long	.Linfo_string3          # DW_AT_name
	.byte	2                       # DW_AT_decl_file
	.byte	184                     # DW_AT_decl_line
	.byte	3                       # Abbrev [3] 0x29:0xf DW_TAG_variable
	.long	.Linfo_string4          # DW_AT_name
	.long	61                      # DW_AT_type
	.byte	4                       # DW_AT_decl_file
	.byte	74                      # DW_AT_decl_line
                                        # DW_AT_declaration
	.long	.Linfo_string13         # DW_AT_MIPS_linkage_name
	.byte	4                       # Abbrev [4] 0x38:0x48 DW_TAG_class_type
	.long	.Linfo_string5          # DW_AT_name
                                        # DW_AT_declaration
	.byte	5                       # Abbrev [5] 0x3d:0x42 DW_TAG_class_type
	.long	.Linfo_string11         # DW_AT_name
	.byte	1                       # DW_AT_byte_size
	.byte	3                       # DW_AT_decl_file
	.short	533                     # DW_AT_decl_line
	.byte	6                       # Abbrev [6] 0x46:0xd DW_TAG_member
	.long	.Linfo_string6          # DW_AT_name
	.long	136                     # DW_AT_type
	.byte	3                       # DW_AT_decl_file
	.short	541                     # DW_AT_decl_line
                                        # DW_AT_external
                                        # DW_AT_declaration
	.byte	3                       # DW_AT_accessibility
                                        # DW_ACCESS_private
	.byte	6                       # Abbrev [6] 0x53:0xd DW_TAG_member
	.long	.Linfo_string9          # DW_AT_name
	.long	154                     # DW_AT_type
	.byte	3                       # DW_AT_decl_file
	.short	542                     # DW_AT_decl_line
                                        # DW_AT_external
                                        # DW_AT_declaration
	.byte	3                       # DW_AT_accessibility
                                        # DW_ACCESS_private
	.byte	7                       # Abbrev [7] 0x60:0xf DW_TAG_subprogram
	.long	.Linfo_string11         # DW_AT_name
	.byte	3                       # DW_AT_decl_file
	.short	537                     # DW_AT_decl_line
                                        # DW_AT_declaration
                                        # DW_AT_external
	.byte	1                       # DW_AT_accessibility
                                        # DW_ACCESS_public
	.byte	8                       # Abbrev [8] 0x69:0x5 DW_TAG_formal_parameter
	.long	161                     # DW_AT_type
                                        # DW_AT_artificial
	.byte	0                       # End Of Children Mark
	.byte	7                       # Abbrev [7] 0x6f:0xf DW_TAG_subprogram
	.long	.Linfo_string12         # DW_AT_name
	.byte	3                       # DW_AT_decl_file
	.short	538                     # DW_AT_decl_line
                                        # DW_AT_declaration
                                        # DW_AT_external
	.byte	1                       # DW_AT_accessibility
                                        # DW_ACCESS_public
	.byte	8                       # Abbrev [8] 0x78:0x5 DW_TAG_formal_parameter
	.long	161                     # DW_AT_type
                                        # DW_AT_artificial
	.byte	0                       # End Of Children Mark
	.byte	0                       # End Of Children Mark
	.byte	0                       # End Of Children Mark
	.byte	9                       # Abbrev [9] 0x80:0x7 DW_TAG_namespace
	.long	.Linfo_string22         # DW_AT_name
	.byte	5                       # DW_AT_decl_file
	.byte	48                      # DW_AT_decl_line
	.byte	0                       # End Of Children Mark
	.byte	10                      # Abbrev [10] 0x88:0xb DW_TAG_typedef
	.long	147                     # DW_AT_type
	.long	.Linfo_string8          # DW_AT_name
	.byte	3                       # DW_AT_decl_file
	.byte	32                      # DW_AT_decl_line
	.byte	11                      # Abbrev [11] 0x93:0x7 DW_TAG_base_type
	.long	.Linfo_string7          # DW_AT_name
	.byte	5                       # DW_AT_encoding
	.byte	4                       # DW_AT_byte_size
	.byte	11                      # Abbrev [11] 0x9a:0x7 DW_TAG_base_type
	.long	.Linfo_string10         # DW_AT_name
	.byte	2                       # DW_AT_encoding
	.byte	1                       # DW_AT_byte_size
	.byte	12                      # Abbrev [12] 0xa1:0x5 DW_TAG_pointer_type
	.long	61                      # DW_AT_type
	.byte	13                      # Abbrev [13] 0xa6:0xb DW_TAG_variable
	.long	41                      # DW_AT_specification
	.byte	5                       # DW_AT_location
	.byte	3
	.long	_ZStL8__ioinit
	.byte	14                      # Abbrev [14] 0xb1:0x11 DW_TAG_subprogram
	.long	.Linfo_string14         # DW_AT_name
	.byte	4                       # DW_AT_decl_file
	.byte	74                      # DW_AT_decl_line
	.long	.Lfunc_begin0           # DW_AT_low_pc
	.long	.Lfunc_end0             # DW_AT_high_pc
	.byte	1                       # DW_AT_frame_base
	.byte	85
	.byte	15                      # Abbrev [15] 0xc2:0x32 DW_TAG_subprogram
	.long	.Linfo_string15         # DW_AT_name
	.byte	1                       # DW_AT_decl_file
	.byte	9                       # DW_AT_decl_line
	.long	147                     # DW_AT_type
                                        # DW_AT_external
	.long	.Lfunc_begin1           # DW_AT_low_pc
	.long	.Lfunc_end1             # DW_AT_high_pc
	.byte	1                       # DW_AT_frame_base
	.byte	85
	.byte	16                      # Abbrev [16] 0xd7:0xe DW_TAG_variable
	.long	.Linfo_string23         # DW_AT_name
	.byte	1                       # DW_AT_decl_file
	.byte	10                      # DW_AT_decl_line
	.long	147                     # DW_AT_type
	.byte	2                       # DW_AT_location
	.byte	145
	.byte	124
	.byte	16                      # Abbrev [16] 0xe5:0xe DW_TAG_variable
	.long	.Linfo_string24         # DW_AT_name
	.byte	1                       # DW_AT_decl_file
	.byte	11                      # DW_AT_decl_line
	.long	147                     # DW_AT_type
	.byte	2                       # DW_AT_location
	.byte	145
	.byte	120
	.byte	0                       # End Of Children Mark
	.byte	17                      # Abbrev [17] 0xf4:0x52 DW_TAG_subprogram
	.long	.Linfo_string16         # DW_AT_MIPS_linkage_name
	.long	.Linfo_string17         # DW_AT_name
	.byte	1                       # DW_AT_decl_file
	.byte	20                      # DW_AT_decl_line
	.long	147                     # DW_AT_type
                                        # DW_AT_external
	.long	.Lfunc_begin2           # DW_AT_low_pc
	.long	.Lfunc_end2             # DW_AT_high_pc
	.byte	1                       # DW_AT_frame_base
	.byte	85
	.byte	18                      # Abbrev [18] 0x10d:0xe DW_TAG_formal_parameter
	.long	.Linfo_string23         # DW_AT_name
	.byte	1                       # DW_AT_decl_file
	.byte	20                      # DW_AT_decl_line
	.long	147                     # DW_AT_type
	.byte	2                       # DW_AT_location
	.byte	145
	.byte	124
	.byte	18                      # Abbrev [18] 0x11b:0xe DW_TAG_formal_parameter
	.long	.Linfo_string24         # DW_AT_name
	.byte	1                       # DW_AT_decl_file
	.byte	20                      # DW_AT_decl_line
	.long	147                     # DW_AT_type
	.byte	2                       # DW_AT_location
	.byte	145
	.byte	120
	.byte	16                      # Abbrev [16] 0x129:0xe DW_TAG_variable
	.long	.Linfo_string25         # DW_AT_name
	.byte	1                       # DW_AT_decl_file
	.byte	21                      # DW_AT_decl_line
	.long	147                     # DW_AT_type
	.byte	2                       # DW_AT_location
	.byte	145
	.byte	116
	.byte	16                      # Abbrev [16] 0x137:0xe DW_TAG_variable
	.long	.Linfo_string26         # DW_AT_name
	.byte	1                       # DW_AT_decl_file
	.byte	22                      # DW_AT_decl_line
	.long	147                     # DW_AT_type
	.byte	2                       # DW_AT_location
	.byte	145
	.byte	112
	.byte	0                       # End Of Children Mark
	.byte	17                      # Abbrev [17] 0x146:0x44 DW_TAG_subprogram
	.long	.Linfo_string18         # DW_AT_MIPS_linkage_name
	.long	.Linfo_string19         # DW_AT_name
	.byte	1                       # DW_AT_decl_file
	.byte	33                      # DW_AT_decl_line
	.long	147                     # DW_AT_type
                                        # DW_AT_external
	.long	.Lfunc_begin3           # DW_AT_low_pc
	.long	.Lfunc_end3             # DW_AT_high_pc
	.byte	1                       # DW_AT_frame_base
	.byte	85
	.byte	18                      # Abbrev [18] 0x15f:0xe DW_TAG_formal_parameter
	.long	.Linfo_string23         # DW_AT_name
	.byte	1                       # DW_AT_decl_file
	.byte	33                      # DW_AT_decl_line
	.long	147                     # DW_AT_type
	.byte	2                       # DW_AT_location
	.byte	145
	.byte	124
	.byte	18                      # Abbrev [18] 0x16d:0xe DW_TAG_formal_parameter
	.long	.Linfo_string24         # DW_AT_name
	.byte	1                       # DW_AT_decl_file
	.byte	33                      # DW_AT_decl_line
	.long	147                     # DW_AT_type
	.byte	2                       # DW_AT_location
	.byte	145
	.byte	120
	.byte	16                      # Abbrev [16] 0x17b:0xe DW_TAG_variable
	.long	.Linfo_string25         # DW_AT_name
	.byte	1                       # DW_AT_decl_file
	.byte	34                      # DW_AT_decl_line
	.long	147                     # DW_AT_type
	.byte	2                       # DW_AT_location
	.byte	145
	.byte	116
	.byte	0                       # End Of Children Mark
	.byte	19                      # Abbrev [19] 0x18a:0x11 DW_TAG_subprogram
	.long	.Linfo_string20         # DW_AT_MIPS_linkage_name
	.byte	1                       # DW_AT_decl_file
	.byte	42                      # DW_AT_decl_line
                                        # DW_AT_artificial
	.long	.Lfunc_begin4           # DW_AT_low_pc
	.long	.Lfunc_end4             # DW_AT_high_pc
	.byte	1                       # DW_AT_frame_base
	.byte	85
	.byte	2                       # Abbrev [2] 0x19b:0xf DW_TAG_namespace
	.long	.Linfo_string21         # DW_AT_name
	.byte	5                       # DW_AT_decl_file
	.byte	54                      # DW_AT_decl_line
	.byte	20                      # Abbrev [20] 0x1a2:0x7 DW_TAG_imported_module
	.byte	5                       # DW_AT_decl_file
	.byte	56                      # DW_AT_decl_line
	.long	128                     # DW_AT_import
	.byte	0                       # End Of Children Mark
	.byte	20                      # Abbrev [20] 0x1aa:0x7 DW_TAG_imported_module
	.byte	1                       # DW_AT_decl_file
	.byte	4                       # DW_AT_decl_line
	.long	34                      # DW_AT_import
	.byte	0                       # End Of Children Mark
.L.debug_info_end0:
	.section	.debug_abbrev,"",@progbits
.L.debug_abbrev_begin:
	.byte	1                       # Abbreviation Code
	.byte	17                      # DW_TAG_compile_unit
	.byte	1                       # DW_CHILDREN_yes
	.byte	37                      # DW_AT_producer
	.byte	14                      # DW_FORM_strp
	.byte	19                      # DW_AT_language
	.byte	5                       # DW_FORM_data2
	.byte	3                       # DW_AT_name
	.byte	14                      # DW_FORM_strp
	.byte	17                      # DW_AT_low_pc
	.byte	1                       # DW_FORM_addr
	.byte	16                      # DW_AT_stmt_list
	.byte	23                      # DW_FORM_sec_offset
	.byte	27                      # DW_AT_comp_dir
	.byte	14                      # DW_FORM_strp
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	2                       # Abbreviation Code
	.byte	57                      # DW_TAG_namespace
	.byte	1                       # DW_CHILDREN_yes
	.byte	3                       # DW_AT_name
	.byte	14                      # DW_FORM_strp
	.byte	58                      # DW_AT_decl_file
	.byte	11                      # DW_FORM_data1
	.byte	59                      # DW_AT_decl_line
	.byte	11                      # DW_FORM_data1
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	3                       # Abbreviation Code
	.byte	52                      # DW_TAG_variable
	.byte	0                       # DW_CHILDREN_no
	.byte	3                       # DW_AT_name
	.byte	14                      # DW_FORM_strp
	.byte	73                      # DW_AT_type
	.byte	19                      # DW_FORM_ref4
	.byte	58                      # DW_AT_decl_file
	.byte	11                      # DW_FORM_data1
	.byte	59                      # DW_AT_decl_line
	.byte	11                      # DW_FORM_data1
	.byte	60                      # DW_AT_declaration
	.byte	25                      # DW_FORM_flag_present
	.ascii	"\207@"                 # DW_AT_MIPS_linkage_name
	.byte	14                      # DW_FORM_strp
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	4                       # Abbreviation Code
	.byte	2                       # DW_TAG_class_type
	.byte	1                       # DW_CHILDREN_yes
	.byte	3                       # DW_AT_name
	.byte	14                      # DW_FORM_strp
	.byte	60                      # DW_AT_declaration
	.byte	25                      # DW_FORM_flag_present
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	5                       # Abbreviation Code
	.byte	2                       # DW_TAG_class_type
	.byte	1                       # DW_CHILDREN_yes
	.byte	3                       # DW_AT_name
	.byte	14                      # DW_FORM_strp
	.byte	11                      # DW_AT_byte_size
	.byte	11                      # DW_FORM_data1
	.byte	58                      # DW_AT_decl_file
	.byte	11                      # DW_FORM_data1
	.byte	59                      # DW_AT_decl_line
	.byte	5                       # DW_FORM_data2
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	6                       # Abbreviation Code
	.byte	13                      # DW_TAG_member
	.byte	0                       # DW_CHILDREN_no
	.byte	3                       # DW_AT_name
	.byte	14                      # DW_FORM_strp
	.byte	73                      # DW_AT_type
	.byte	19                      # DW_FORM_ref4
	.byte	58                      # DW_AT_decl_file
	.byte	11                      # DW_FORM_data1
	.byte	59                      # DW_AT_decl_line
	.byte	5                       # DW_FORM_data2
	.byte	63                      # DW_AT_external
	.byte	25                      # DW_FORM_flag_present
	.byte	60                      # DW_AT_declaration
	.byte	25                      # DW_FORM_flag_present
	.byte	50                      # DW_AT_accessibility
	.byte	11                      # DW_FORM_data1
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	7                       # Abbreviation Code
	.byte	46                      # DW_TAG_subprogram
	.byte	1                       # DW_CHILDREN_yes
	.byte	3                       # DW_AT_name
	.byte	14                      # DW_FORM_strp
	.byte	58                      # DW_AT_decl_file
	.byte	11                      # DW_FORM_data1
	.byte	59                      # DW_AT_decl_line
	.byte	5                       # DW_FORM_data2
	.byte	60                      # DW_AT_declaration
	.byte	25                      # DW_FORM_flag_present
	.byte	63                      # DW_AT_external
	.byte	25                      # DW_FORM_flag_present
	.byte	50                      # DW_AT_accessibility
	.byte	11                      # DW_FORM_data1
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	8                       # Abbreviation Code
	.byte	5                       # DW_TAG_formal_parameter
	.byte	0                       # DW_CHILDREN_no
	.byte	73                      # DW_AT_type
	.byte	19                      # DW_FORM_ref4
	.byte	52                      # DW_AT_artificial
	.byte	25                      # DW_FORM_flag_present
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	9                       # Abbreviation Code
	.byte	57                      # DW_TAG_namespace
	.byte	0                       # DW_CHILDREN_no
	.byte	3                       # DW_AT_name
	.byte	14                      # DW_FORM_strp
	.byte	58                      # DW_AT_decl_file
	.byte	11                      # DW_FORM_data1
	.byte	59                      # DW_AT_decl_line
	.byte	11                      # DW_FORM_data1
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	10                      # Abbreviation Code
	.byte	22                      # DW_TAG_typedef
	.byte	0                       # DW_CHILDREN_no
	.byte	73                      # DW_AT_type
	.byte	19                      # DW_FORM_ref4
	.byte	3                       # DW_AT_name
	.byte	14                      # DW_FORM_strp
	.byte	58                      # DW_AT_decl_file
	.byte	11                      # DW_FORM_data1
	.byte	59                      # DW_AT_decl_line
	.byte	11                      # DW_FORM_data1
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	11                      # Abbreviation Code
	.byte	36                      # DW_TAG_base_type
	.byte	0                       # DW_CHILDREN_no
	.byte	3                       # DW_AT_name
	.byte	14                      # DW_FORM_strp
	.byte	62                      # DW_AT_encoding
	.byte	11                      # DW_FORM_data1
	.byte	11                      # DW_AT_byte_size
	.byte	11                      # DW_FORM_data1
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	12                      # Abbreviation Code
	.byte	15                      # DW_TAG_pointer_type
	.byte	0                       # DW_CHILDREN_no
	.byte	73                      # DW_AT_type
	.byte	19                      # DW_FORM_ref4
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	13                      # Abbreviation Code
	.byte	52                      # DW_TAG_variable
	.byte	0                       # DW_CHILDREN_no
	.byte	71                      # DW_AT_specification
	.byte	19                      # DW_FORM_ref4
	.byte	2                       # DW_AT_location
	.byte	10                      # DW_FORM_block1
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	14                      # Abbreviation Code
	.byte	46                      # DW_TAG_subprogram
	.byte	0                       # DW_CHILDREN_no
	.byte	3                       # DW_AT_name
	.byte	14                      # DW_FORM_strp
	.byte	58                      # DW_AT_decl_file
	.byte	11                      # DW_FORM_data1
	.byte	59                      # DW_AT_decl_line
	.byte	11                      # DW_FORM_data1
	.byte	17                      # DW_AT_low_pc
	.byte	1                       # DW_FORM_addr
	.byte	18                      # DW_AT_high_pc
	.byte	1                       # DW_FORM_addr
	.byte	64                      # DW_AT_frame_base
	.byte	10                      # DW_FORM_block1
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	15                      # Abbreviation Code
	.byte	46                      # DW_TAG_subprogram
	.byte	1                       # DW_CHILDREN_yes
	.byte	3                       # DW_AT_name
	.byte	14                      # DW_FORM_strp
	.byte	58                      # DW_AT_decl_file
	.byte	11                      # DW_FORM_data1
	.byte	59                      # DW_AT_decl_line
	.byte	11                      # DW_FORM_data1
	.byte	73                      # DW_AT_type
	.byte	19                      # DW_FORM_ref4
	.byte	63                      # DW_AT_external
	.byte	25                      # DW_FORM_flag_present
	.byte	17                      # DW_AT_low_pc
	.byte	1                       # DW_FORM_addr
	.byte	18                      # DW_AT_high_pc
	.byte	1                       # DW_FORM_addr
	.byte	64                      # DW_AT_frame_base
	.byte	10                      # DW_FORM_block1
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	16                      # Abbreviation Code
	.byte	52                      # DW_TAG_variable
	.byte	0                       # DW_CHILDREN_no
	.byte	3                       # DW_AT_name
	.byte	14                      # DW_FORM_strp
	.byte	58                      # DW_AT_decl_file
	.byte	11                      # DW_FORM_data1
	.byte	59                      # DW_AT_decl_line
	.byte	11                      # DW_FORM_data1
	.byte	73                      # DW_AT_type
	.byte	19                      # DW_FORM_ref4
	.byte	2                       # DW_AT_location
	.byte	10                      # DW_FORM_block1
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	17                      # Abbreviation Code
	.byte	46                      # DW_TAG_subprogram
	.byte	1                       # DW_CHILDREN_yes
	.ascii	"\207@"                 # DW_AT_MIPS_linkage_name
	.byte	14                      # DW_FORM_strp
	.byte	3                       # DW_AT_name
	.byte	14                      # DW_FORM_strp
	.byte	58                      # DW_AT_decl_file
	.byte	11                      # DW_FORM_data1
	.byte	59                      # DW_AT_decl_line
	.byte	11                      # DW_FORM_data1
	.byte	73                      # DW_AT_type
	.byte	19                      # DW_FORM_ref4
	.byte	63                      # DW_AT_external
	.byte	25                      # DW_FORM_flag_present
	.byte	17                      # DW_AT_low_pc
	.byte	1                       # DW_FORM_addr
	.byte	18                      # DW_AT_high_pc
	.byte	1                       # DW_FORM_addr
	.byte	64                      # DW_AT_frame_base
	.byte	10                      # DW_FORM_block1
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	18                      # Abbreviation Code
	.byte	5                       # DW_TAG_formal_parameter
	.byte	0                       # DW_CHILDREN_no
	.byte	3                       # DW_AT_name
	.byte	14                      # DW_FORM_strp
	.byte	58                      # DW_AT_decl_file
	.byte	11                      # DW_FORM_data1
	.byte	59                      # DW_AT_decl_line
	.byte	11                      # DW_FORM_data1
	.byte	73                      # DW_AT_type
	.byte	19                      # DW_FORM_ref4
	.byte	2                       # DW_AT_location
	.byte	10                      # DW_FORM_block1
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	19                      # Abbreviation Code
	.byte	46                      # DW_TAG_subprogram
	.byte	0                       # DW_CHILDREN_no
	.ascii	"\207@"                 # DW_AT_MIPS_linkage_name
	.byte	14                      # DW_FORM_strp
	.byte	58                      # DW_AT_decl_file
	.byte	11                      # DW_FORM_data1
	.byte	59                      # DW_AT_decl_line
	.byte	11                      # DW_FORM_data1
	.byte	52                      # DW_AT_artificial
	.byte	25                      # DW_FORM_flag_present
	.byte	17                      # DW_AT_low_pc
	.byte	1                       # DW_FORM_addr
	.byte	18                      # DW_AT_high_pc
	.byte	1                       # DW_FORM_addr
	.byte	64                      # DW_AT_frame_base
	.byte	10                      # DW_FORM_block1
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	20                      # Abbreviation Code
	.byte	58                      # DW_TAG_imported_module
	.byte	0                       # DW_CHILDREN_no
	.byte	58                      # DW_AT_decl_file
	.byte	11                      # DW_FORM_data1
	.byte	59                      # DW_AT_decl_line
	.byte	11                      # DW_FORM_data1
	.byte	24                      # DW_AT_import
	.byte	19                      # DW_FORM_ref4
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	0                       # EOM(3)
.L.debug_abbrev_end:
	.section	.debug_aranges,"",@progbits
	.long	44                      # Length of ARange Set
	.short	2                       # DWARF Arange version number
	.long	.L.debug_info_begin0    # Offset Into Debug Info Section
	.byte	4                       # Address Size (in bytes)
	.byte	0                       # Segment Size (in bytes)
	.byte	255
	.byte	255
	.byte	255
	.byte	255
	.long	_ZStL8__ioinit
	.long	1
	.long	.Lfunc_begin0
.Lset0 = .Ldebug_end1-.Lfunc_begin0
	.long	.Lset0
	.long	.Lfunc_begin1
.Lset1 = .Ldebug_end2-.Lfunc_begin1
	.long	.Lset1
	.long	0                       # ARange terminator
	.long	0
	.section	.debug_ranges,"",@progbits
	.section	.debug_macinfo,"",@progbits
	.section	.debug_pubnames,"",@progbits
.Lset2 = .Lpubnames_end0-.Lpubnames_begin0 # Length of Public Names Info
	.long	.Lset2
.Lpubnames_begin0:
	.short	2                       # DWARF Version
	.long	.L.debug_info_begin0    # Offset of Compilation Unit Info
.Lset3 = .L.debug_info_end0-.L.debug_info_begin0 # Compilation Unit Length
	.long	.Lset3
	.long	394                     # DIE offset
	.byte	0                       # External Name
	.long	244                     # DIE offset
	.asciz	"product"               # External Name
	.long	128                     # DIE offset
	.asciz	"std::__debug"          # External Name
	.long	194                     # DIE offset
	.asciz	"main"                  # External Name
	.long	34                      # DIE offset
	.asciz	"std"                   # External Name
	.long	177                     # DIE offset
	.asciz	"__cxx_global_var_init" # External Name
	.long	326                     # DIE offset
	.asciz	"power"                 # External Name
	.long	411                     # DIE offset
	.asciz	"__gnu_debug"           # External Name
	.long	0                       # End Mark
.Lpubnames_end0:
	.section	.debug_pubtypes,"",@progbits
.Lset4 = .Lpubtypes_end0-.Lpubtypes_begin0 # Length of Public Types Info
	.long	.Lset4
.Lpubtypes_begin0:
	.short	2                       # DWARF Version
	.long	.L.debug_info_begin0    # Offset of Compilation Unit Info
.Lset5 = .L.debug_info_end0-.L.debug_info_begin0 # Compilation Unit Length
	.long	.Lset5
	.long	136                     # DIE offset
	.asciz	"_Atomic_word"          # External Name
	.long	147                     # DIE offset
	.asciz	"int"                   # External Name
	.long	154                     # DIE offset
	.asciz	"bool"                  # External Name
	.long	0                       # End Mark
.Lpubtypes_end0:

	.ident	"Ubuntu clang version 3.4-1ubuntu3 (tags/RELEASE_34/final) (based on LLVM 3.4)"
	.section	".note.GNU-stack","",@progbits
