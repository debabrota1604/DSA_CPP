	.text
	.file	"aes256ni_driver.cpp"
	.section	.rodata.cst32,"aM",@progbits,32
	.p2align	5, 0x0                          # -- Begin function main
.LCPI0_0:
	.short	20224                           # 0x4f00
	.short	20224                           # 0x4f00
	.short	20224                           # 0x4f00
	.short	20224                           # 0x4f00
	.short	20224                           # 0x4f00
	.short	20224                           # 0x4f00
	.short	20224                           # 0x4f00
	.short	20224                           # 0x4f00
	.short	20224                           # 0x4f00
	.short	20224                           # 0x4f00
	.short	20224                           # 0x4f00
	.short	20224                           # 0x4f00
	.short	20224                           # 0x4f00
	.short	20224                           # 0x4f00
	.short	20224                           # 0x4f00
	.short	20224                           # 0x4f00
.LCPI0_1:
	.zero	32,31
.LCPI0_2:
	.zero	32,16
.LCPI0_3:
	.zero	32,1
.LCPI0_4:
	.short	26                              # 0x1a
	.short	26                              # 0x1a
	.short	26                              # 0x1a
	.short	26                              # 0x1a
	.short	26                              # 0x1a
	.short	26                              # 0x1a
	.short	26                              # 0x1a
	.short	26                              # 0x1a
	.short	26                              # 0x1a
	.short	26                              # 0x1a
	.short	26                              # 0x1a
	.short	26                              # 0x1a
	.short	26                              # 0x1a
	.short	26                              # 0x1a
	.short	26                              # 0x1a
	.short	26                              # 0x1a
.LCPI0_5:
	.short	255                             # 0xff
	.short	255                             # 0xff
	.short	255                             # 0xff
	.short	255                             # 0xff
	.short	255                             # 0xff
	.short	255                             # 0xff
	.short	255                             # 0xff
	.short	255                             # 0xff
	.short	255                             # 0xff
	.short	255                             # 0xff
	.short	255                             # 0xff
	.short	255                             # 0xff
	.short	255                             # 0xff
	.short	255                             # 0xff
	.short	255                             # 0xff
	.short	255                             # 0xff
.LCPI0_6:
	.zero	32,97
	.section	.rodata,"a",@progbits
	.p2align	1, 0x0
.LCPI0_7:
	.short	20224                           # 0x4f00
.LCPI0_8:
	.byte	16                              # 0x10
	.zero	1
.LCPI0_9:
	.short	26                              # 0x1a
.LCPI0_10:
	.short	255                             # 0xff
	.text
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # 
.Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 155, DW.ref.__gxx_personality_v0
	.cfi_lsda 27, .Lexception0
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%r15
	.cfi_def_cfa_offset 24
	pushq	%r14
	.cfi_def_cfa_offset 32
	pushq	%r13
	.cfi_def_cfa_offset 40
	pushq	%r12
	.cfi_def_cfa_offset 48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	subq	$344, %rsp                      # imm = 0x158
	.cfi_def_cfa_offset 400
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	.cfi_offset %rbp, -16
	movq	%fs:40, %rax
	movq	%rax, 336(%rsp)
	vstmxcsr	(%rsp)
	orl	$32832, (%rsp)                  # imm = 0x8040
	vldmxcsr	(%rsp)
	movq	_ZSt4cout@GOTPCREL(%rip), %rdi
	leaq	.L.str(%rip), %rsi
	movl	$10, %edx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	%rsp, %rdi
	callq	time@PLT
	movl	%eax, %edi
	callq	srand@PLT
	movq	_ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj(%rip), %r14
	testq	%r14, %r14
	jne	.LBB0_3
# %bb.1:
	movl	$64, %edi
	callq	_Znwm@PLT
	movq	%rax, %r14
	movl	$-1, (%rax)
	leaq	8(%rax), %rbx
	addq	$56, %rax
	movq	%rax, 8(%r14)
	movq	$1, 16(%r14)
	vpxor	%xmm0, %xmm0, %xmm0
	vmovdqu	%xmm0, 24(%r14)
	movl	$1065353216, 40(%r14)           # imm = 0x3F800000
	vmovdqu	%xmm0, 48(%r14)
.Ltmp0:
	movq	_ZSt4cout@GOTPCREL(%rip), %rdi
	leaq	.L.str.6(%rip), %rsi
	movl	$32, %edx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp1:
# %bb.2:
	movq	%r14, _ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj(%rip)
.LBB0_3:
	leaq	320(%rsp), %rbx
	movq	%rbx, 304(%rsp)
	movabsq	$6085612663396855365, %rax      # imm = 0x5474707972636E45
	movq	%rax, 320(%rsp)
	movl	$1701669204, 327(%rsp)          # imm = 0x656D6954
	movq	$11, 312(%rsp)
	movb	$0, 331(%rsp)
.Ltmp3:
	leaq	304(%rsp), %rsi
	movq	%r14, %rdi
	callq	_ZN11CpuProfiler6addTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
.Ltmp4:
# %bb.4:
	movq	304(%rsp), %rdi
	cmpq	%rbx, %rdi
	je	.LBB0_6
# %bb.5:
	callq	_ZdlPv@PLT
.LBB0_6:
	movq	_ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj(%rip), %r14
	testq	%r14, %r14
	jne	.LBB0_9
# %bb.7:
	movl	$64, %edi
	callq	_Znwm@PLT
	movq	%rax, %r14
	movl	$-1, (%rax)
	leaq	8(%rax), %rbx
	addq	$56, %rax
	movq	%rax, 8(%r14)
	movq	$1, 16(%r14)
	vpxor	%xmm0, %xmm0, %xmm0
	vmovdqu	%xmm0, 24(%r14)
	movl	$1065353216, 40(%r14)           # imm = 0x3F800000
	vmovdqu	%xmm0, 48(%r14)
.Ltmp6:
	movq	_ZSt4cout@GOTPCREL(%rip), %rdi
	leaq	.L.str.6(%rip), %rsi
	movl	$32, %edx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp7:
# %bb.8:
	movq	%r14, _ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj(%rip)
.LBB0_9:
	leaq	288(%rsp), %rbx
	movq	%rbx, 272(%rsp)
	movabsq	$6085612663396853060, %rax      # imm = 0x5474707972636544
	movq	%rax, 288(%rsp)
	movl	$1701669204, 295(%rsp)          # imm = 0x656D6954
	movq	$11, 280(%rsp)
	movb	$0, 299(%rsp)
.Ltmp9:
	leaq	272(%rsp), %rsi
	movq	%r14, %rdi
	callq	_ZN11CpuProfiler6addTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
.Ltmp10:
# %bb.10:
	movq	272(%rsp), %rdi
	cmpq	%rbx, %rdi
	je	.LBB0_12
# %bb.11:
	callq	_ZdlPv@PLT
.LBB0_12:
	movl	$32, %edi
	callq	_Znam@PLT
	movq	%rax, %rbx
	callq	rand@PLT
	movl	%eax, 112(%rsp)                 # 4-byte Spill
	callq	rand@PLT
	movl	%eax, 108(%rsp)                 # 4-byte Spill
	callq	rand@PLT
	movl	%eax, 104(%rsp)                 # 4-byte Spill
	callq	rand@PLT
	movl	%eax, 100(%rsp)                 # 4-byte Spill
	callq	rand@PLT
	movl	%eax, 96(%rsp)                  # 4-byte Spill
	callq	rand@PLT
	movl	%eax, 92(%rsp)                  # 4-byte Spill
	callq	rand@PLT
	movl	%eax, 88(%rsp)                  # 4-byte Spill
	callq	rand@PLT
	movl	%eax, 84(%rsp)                  # 4-byte Spill
	callq	rand@PLT
	movl	%eax, 80(%rsp)                  # 4-byte Spill
	callq	rand@PLT
	movl	%eax, 76(%rsp)                  # 4-byte Spill
	callq	rand@PLT
	movl	%eax, 72(%rsp)                  # 4-byte Spill
	callq	rand@PLT
	movl	%eax, 68(%rsp)                  # 4-byte Spill
	callq	rand@PLT
	movl	%eax, 64(%rsp)                  # 4-byte Spill
	callq	rand@PLT
	movl	%eax, 60(%rsp)                  # 4-byte Spill
	callq	rand@PLT
	movl	%eax, 56(%rsp)                  # 4-byte Spill
	callq	rand@PLT
	movl	%eax, 52(%rsp)                  # 4-byte Spill
	callq	rand@PLT
	movl	%eax, 48(%rsp)                  # 4-byte Spill
	callq	rand@PLT
	movl	%eax, 44(%rsp)                  # 4-byte Spill
	callq	rand@PLT
	movl	%eax, 40(%rsp)                  # 4-byte Spill
	callq	rand@PLT
	movl	%eax, 36(%rsp)                  # 4-byte Spill
	callq	rand@PLT
	movl	%eax, 32(%rsp)                  # 4-byte Spill
	callq	rand@PLT
	movl	%eax, 28(%rsp)                  # 4-byte Spill
	callq	rand@PLT
	movl	%eax, 24(%rsp)                  # 4-byte Spill
	callq	rand@PLT
	movl	%eax, 20(%rsp)                  # 4-byte Spill
	callq	rand@PLT
	movl	%eax, 16(%rsp)                  # 4-byte Spill
	callq	rand@PLT
	movl	%eax, 12(%rsp)                  # 4-byte Spill
	callq	rand@PLT
	movl	%eax, %r14d
	callq	rand@PLT
	movl	%eax, %r15d
	callq	rand@PLT
	movl	%eax, %r12d
	callq	rand@PLT
	movl	%eax, %r13d
	callq	rand@PLT
	movl	%eax, %ebp
	callq	rand@PLT
	vmovd	112(%rsp), %xmm0                # 4-byte Folded Reload
                                        # xmm0 = mem[0],zero,zero,zero
	vpinsrb	$1, 108(%rsp), %xmm0, %xmm0     # 4-byte Folded Reload
	vpinsrb	$2, 104(%rsp), %xmm0, %xmm0     # 4-byte Folded Reload
	vpinsrb	$3, 100(%rsp), %xmm0, %xmm0     # 4-byte Folded Reload
	vpinsrb	$4, 96(%rsp), %xmm0, %xmm0      # 4-byte Folded Reload
	vpinsrb	$5, 92(%rsp), %xmm0, %xmm0      # 4-byte Folded Reload
	vpinsrb	$6, 88(%rsp), %xmm0, %xmm0      # 4-byte Folded Reload
	vpinsrb	$7, 84(%rsp), %xmm0, %xmm0      # 4-byte Folded Reload
	vpinsrb	$8, 80(%rsp), %xmm0, %xmm0      # 4-byte Folded Reload
	vpinsrb	$9, 76(%rsp), %xmm0, %xmm0      # 4-byte Folded Reload
	vpinsrb	$10, 72(%rsp), %xmm0, %xmm0     # 4-byte Folded Reload
	vpinsrb	$11, 68(%rsp), %xmm0, %xmm0     # 4-byte Folded Reload
	vpinsrb	$12, 64(%rsp), %xmm0, %xmm0     # 4-byte Folded Reload
	vpinsrb	$13, 60(%rsp), %xmm0, %xmm0     # 4-byte Folded Reload
	vpinsrb	$14, 56(%rsp), %xmm0, %xmm0     # 4-byte Folded Reload
	vpinsrb	$15, 52(%rsp), %xmm0, %xmm0     # 4-byte Folded Reload
	vmovd	48(%rsp), %xmm1                 # 4-byte Folded Reload
                                        # xmm1 = mem[0],zero,zero,zero
	vpinsrb	$1, 44(%rsp), %xmm1, %xmm1      # 4-byte Folded Reload
	vpinsrb	$2, 40(%rsp), %xmm1, %xmm1      # 4-byte Folded Reload
	vpinsrb	$3, 36(%rsp), %xmm1, %xmm1      # 4-byte Folded Reload
	vpinsrb	$4, 32(%rsp), %xmm1, %xmm1      # 4-byte Folded Reload
	vpinsrb	$5, 28(%rsp), %xmm1, %xmm1      # 4-byte Folded Reload
	vpinsrb	$6, 24(%rsp), %xmm1, %xmm1      # 4-byte Folded Reload
	vpinsrb	$7, 20(%rsp), %xmm1, %xmm1      # 4-byte Folded Reload
	vpinsrb	$8, 16(%rsp), %xmm1, %xmm1      # 4-byte Folded Reload
	vpinsrb	$9, 12(%rsp), %xmm1, %xmm1      # 4-byte Folded Reload
	vpinsrb	$10, %r14d, %xmm1, %xmm1
	vpinsrb	$11, %r15d, %xmm1, %xmm1
	vpinsrb	$12, %r12d, %xmm1, %xmm1
	vpinsrb	$13, %r13d, %xmm1, %xmm1
	vpinsrb	$14, %ebp, %xmm1, %xmm1
	vpinsrb	$15, %eax, %xmm1, %xmm1
	vinserti128	$1, %xmm1, %ymm0, %ymm0
	vpxor	%xmm1, %xmm1, %xmm1
	vpunpckhbw	%ymm0, %ymm1, %ymm2     # ymm2 = ymm1[8],ymm0[8],ymm1[9],ymm0[9],ymm1[10],ymm0[10],ymm1[11],ymm0[11],ymm1[12],ymm0[12],ymm1[13],ymm0[13],ymm1[14],ymm0[14],ymm1[15],ymm0[15],ymm1[24],ymm0[24],ymm1[25],ymm0[25],ymm1[26],ymm0[26],ymm1[27],ymm0[27],ymm1[28],ymm0[28],ymm1[29],ymm0[29],ymm1[30],ymm0[30],ymm1[31],ymm0[31]
	vpbroadcastw	.LCPI0_7(%rip), %ymm3   # ymm3 = [20224,20224,20224,20224,20224,20224,20224,20224,20224,20224,20224,20224,20224,20224,20224,20224]
	vpmulhw	%ymm3, %ymm2, %ymm2
	vpsrlw	$8, %ymm2, %ymm2
	vpunpcklbw	%ymm0, %ymm1, %ymm1     # ymm1 = ymm1[0],ymm0[0],ymm1[1],ymm0[1],ymm1[2],ymm0[2],ymm1[3],ymm0[3],ymm1[4],ymm0[4],ymm1[5],ymm0[5],ymm1[6],ymm0[6],ymm1[7],ymm0[7],ymm1[16],ymm0[16],ymm1[17],ymm0[17],ymm1[18],ymm0[18],ymm1[19],ymm0[19],ymm1[20],ymm0[20],ymm1[21],ymm0[21],ymm1[22],ymm0[22],ymm1[23],ymm0[23]
	vpmulhw	%ymm3, %ymm1, %ymm1
	vpsrlw	$8, %ymm1, %ymm1
	vpackuswb	%ymm2, %ymm1, %ymm1
	vpsrlw	$3, %ymm1, %ymm2
	vpand	.LCPI0_1(%rip), %ymm2, %ymm2
	vpbroadcastb	.LCPI0_8(%rip), %ymm3   # ymm3 = [16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16]
	vpsrlw	$7, %ymm1, %ymm1
	vpand	.LCPI0_3(%rip), %ymm1, %ymm1
	vpxor	%ymm3, %ymm2, %ymm2
	vpaddb	%ymm1, %ymm2, %ymm1
	vpsubb	%ymm3, %ymm1, %ymm1
	vpunpckhbw	%ymm1, %ymm1, %ymm2     # ymm2 = ymm1[8,8,9,9,10,10,11,11,12,12,13,13,14,14,15,15,24,24,25,25,26,26,27,27,28,28,29,29,30,30,31,31]
	vpbroadcastw	.LCPI0_9(%rip), %ymm3   # ymm3 = [26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26]
	vpmullw	%ymm3, %ymm2, %ymm2
	vpbroadcastw	.LCPI0_10(%rip), %ymm4  # ymm4 = [255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255]
	vpand	%ymm4, %ymm2, %ymm2
	vpunpcklbw	%ymm1, %ymm1, %ymm1     # ymm1 = ymm1[0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,16,16,17,17,18,18,19,19,20,20,21,21,22,22,23,23]
	vpmullw	%ymm3, %ymm1, %ymm1
	vpand	%ymm4, %ymm1, %ymm1
	vpackuswb	%ymm2, %ymm1, %ymm1
	vpsubb	%ymm1, %ymm0, %ymm0
	vpaddb	.LCPI0_6(%rip), %ymm0, %ymm0
	vmovdqu	%ymm0, 112(%rsp)                # 32-byte Spill
	vmovdqu	%ymm0, (%rbx)
	movq	_ZSt4cout@GOTPCREL(%rip), %r14
	leaq	.L.str.3(%rip), %rsi
	movl	$20, %edx
	movq	%r14, %rdi
	vzeroupper
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movzbl	(%rbx), %esi
	leaq	.L.str.12(%rip), %r15
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	1(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	2(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	3(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	4(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	5(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	6(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	7(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	8(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	9(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	10(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	11(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	12(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	13(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	14(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	15(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	16(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	17(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	18(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	19(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	20(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	21(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	22(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	23(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	24(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	25(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	26(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	27(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	28(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movzbl	29(%rbx), %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	vmovdqu	112(%rsp), %ymm0                # 32-byte Reload
	vextracti128	$1, %ymm0, %xmm0
	vmovdqu	%xmm0, 112(%rsp)                # 16-byte Spill
                                        # AlignMOV convert to UnAlignMOV 
	vpextrb	$14, %xmm0, %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	vzeroupper
	callq	printf@PLT
	vmovdqu	112(%rsp), %xmm0                # 16-byte Reload
                                        # AlignMOV convert to UnAlignMOV 
	vpextrb	$15, %xmm0, %esi
	movq	%r15, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movl	$10, %edi
	callq	putchar@PLT
	leaq	.L.str.4(%rip), %rsi
	movl	$35, %edx
	movq	%r14, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	%r14, %rdi
	movl	$10000, %esi                    # imm = 0x2710
	callq	_ZNSolsEi@PLT
	movq	%rax, %rbx
	leaq	.L.str.5(%rip), %rsi
	movl	$9, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	(%rbx), %rax
	movq	-24(%rax), %rax
	movq	240(%rbx,%rax), %r14
	testq	%r14, %r14
	je	.LBB0_66
# %bb.13:
	cmpb	$0, 56(%r14)
	je	.LBB0_15
# %bb.14:
	movzbl	67(%r14), %eax
	jmp	.LBB0_16
.LBB0_15:
	movq	%r14, %rdi
	callq	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%r14), %rax
	movq	%r14, %rdi
	movl	$10, %esi
	callq	*48(%rax)
.LBB0_16:
	movsbl	%al, %esi
	movq	%rbx, %rdi
	callq	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	callq	_ZNSo5flushEv@PLT
	leaq	224(%rsp), %r12
	leaq	192(%rsp), %r15
	movl	$10000, %ebp                    # imm = 0x2710
	leaq	160(%rsp), %r14
	jmp	.LBB0_18
	.p2align	4, 0x90
.LBB0_17:                               #   in Loop: Header=BB0_18 Depth=1
	decl	%ebp
	je	.LBB0_52
.LBB0_18:                               # =>This Inner Loop Header: Depth=1
	callq	rand@PLT
	callq	rand@PLT
	callq	rand@PLT
	callq	rand@PLT
	callq	rand@PLT
	callq	rand@PLT
	callq	rand@PLT
	callq	rand@PLT
	callq	rand@PLT
	callq	rand@PLT
	callq	rand@PLT
	callq	rand@PLT
	callq	rand@PLT
	callq	rand@PLT
	callq	rand@PLT
	callq	rand@PLT
	movq	_ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj(%rip), %rbx
	testq	%rbx, %rbx
	jne	.LBB0_21
# %bb.19:                               #   in Loop: Header=BB0_18 Depth=1
	movl	$64, %edi
	callq	_Znwm@PLT
	movq	%rax, %rbx
	movl	$-1, (%rax)
	leaq	8(%rax), %r13
	addq	$56, %rax
	movq	%rax, 8(%rbx)
	movq	$1, 16(%rbx)
	vpxor	%xmm0, %xmm0, %xmm0
	vmovdqu	%xmm0, 24(%rbx)
	movl	$1065353216, 40(%rbx)           # imm = 0x3F800000
	vmovdqu	%xmm0, 48(%rbx)
.Ltmp12:
	movl	$32, %edx
	movq	_ZSt4cout@GOTPCREL(%rip), %rdi
	leaq	.L.str.6(%rip), %rsi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp13:
# %bb.20:                               #   in Loop: Header=BB0_18 Depth=1
	movq	%rbx, _ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj(%rip)
.LBB0_21:                               #   in Loop: Header=BB0_18 Depth=1
	leaq	256(%rsp), %rcx
	movq	%rcx, 240(%rsp)
	movabsq	$6085612663396855365, %rax      # imm = 0x5474707972636E45
	movq	%rax, (%rcx)
	movl	$1701669204, 7(%rcx)            # imm = 0x656D6954
	movq	$11, 248(%rsp)
	movb	$0, 267(%rsp)
	addq	$8, %rbx
.Ltmp15:
	movq	%rbx, %rdi
	leaq	240(%rsp), %rsi
	callq	_ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEE2atERSD_
.Ltmp16:
# %bb.22:                               #   in Loop: Header=BB0_18 Depth=1
	movq	(%rax), %rsi
	testq	%rsi, %rsi
	je	.LBB0_24
# %bb.23:                               #   in Loop: Header=BB0_18 Depth=1
	#APP
	rdtscp
	#NO_APP
                                        # kill: def $edx killed $edx def $rdx
	shlq	$32, %rdx
	movl	%eax, %eax
	orq	%rdx, %rax
	movq	%rax, 32(%rsi)
	jmp	.LBB0_27
	.p2align	4, 0x90
.LBB0_24:                               #   in Loop: Header=BB0_18 Depth=1
.Ltmp17:
	movl	$4, %edx
	movq	_ZSt4cout@GOTPCREL(%rip), %rdi
	leaq	.L.str.14(%rip), %rsi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp18:
# %bb.25:                               #   in Loop: Header=BB0_18 Depth=1
	movq	240(%rsp), %rsi
	movq	248(%rsp), %rdx
.Ltmp19:
	movq	_ZSt4cout@GOTPCREL(%rip), %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp20:
# %bb.26:                               #   in Loop: Header=BB0_18 Depth=1
.Ltmp21:
	movl	$14, %edx
	movq	%rax, %rdi
	leaq	.L.str.15(%rip), %rsi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp22:
.LBB0_27:                               #   in Loop: Header=BB0_18 Depth=1
	movq	240(%rsp), %rdi
	leaq	256(%rsp), %rax
	cmpq	%rax, %rdi
	je	.LBB0_29
# %bb.28:                               #   in Loop: Header=BB0_18 Depth=1
	callq	_ZdlPv@PLT
.LBB0_29:                               #   in Loop: Header=BB0_18 Depth=1
	movq	_ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj(%rip), %rbx
	testq	%rbx, %rbx
	jne	.LBB0_32
# %bb.30:                               #   in Loop: Header=BB0_18 Depth=1
	movl	$64, %edi
	callq	_Znwm@PLT
	movq	%rax, %rbx
	movl	$-1, (%rax)
	leaq	8(%rax), %r13
	addq	$56, %rax
	movq	%rax, 8(%rbx)
	movq	$1, 16(%rbx)
	vpxor	%xmm0, %xmm0, %xmm0
	vmovdqu	%xmm0, 24(%rbx)
	movl	$1065353216, 40(%rbx)           # imm = 0x3F800000
	vmovdqu	%xmm0, 48(%rbx)
.Ltmp24:
	movl	$32, %edx
	movq	_ZSt4cout@GOTPCREL(%rip), %rdi
	leaq	.L.str.6(%rip), %rsi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp25:
# %bb.31:                               #   in Loop: Header=BB0_18 Depth=1
	movq	%rbx, _ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj(%rip)
.LBB0_32:                               #   in Loop: Header=BB0_18 Depth=1
	movq	%r12, 208(%rsp)
	movabsq	$6085612663396855365, %rax      # imm = 0x5474707972636E45
	movq	%rax, (%r12)
	movl	$1701669204, 7(%r12)            # imm = 0x656D6954
	movq	$11, 216(%rsp)
	movb	$0, 235(%rsp)
.Ltmp27:
	movq	%rbx, %rdi
	leaq	208(%rsp), %rsi
	callq	_ZN11CpuProfiler7stopTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
.Ltmp28:
# %bb.33:                               #   in Loop: Header=BB0_18 Depth=1
	movq	208(%rsp), %rdi
	cmpq	%r12, %rdi
	je	.LBB0_35
# %bb.34:                               #   in Loop: Header=BB0_18 Depth=1
	callq	_ZdlPv@PLT
.LBB0_35:                               #   in Loop: Header=BB0_18 Depth=1
	movq	_ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj(%rip), %rbx
	testq	%rbx, %rbx
	jne	.LBB0_38
# %bb.36:                               #   in Loop: Header=BB0_18 Depth=1
	movl	$64, %edi
	callq	_Znwm@PLT
	movq	%rax, %rbx
	movl	$-1, (%rax)
	leaq	8(%rax), %r13
	addq	$56, %rax
	movq	%rax, 8(%rbx)
	movq	$1, 16(%rbx)
	vpxor	%xmm0, %xmm0, %xmm0
	vmovdqu	%xmm0, 24(%rbx)
	movl	$1065353216, 40(%rbx)           # imm = 0x3F800000
	vmovdqu	%xmm0, 48(%rbx)
.Ltmp30:
	movl	$32, %edx
	movq	_ZSt4cout@GOTPCREL(%rip), %rdi
	leaq	.L.str.6(%rip), %rsi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp31:
# %bb.37:                               #   in Loop: Header=BB0_18 Depth=1
	movq	%rbx, _ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj(%rip)
.LBB0_38:                               #   in Loop: Header=BB0_18 Depth=1
	movq	%r15, 176(%rsp)
	movabsq	$6085612663396853060, %rax      # imm = 0x5474707972636544
	movq	%rax, (%r15)
	movl	$1701669204, 7(%r15)            # imm = 0x656D6954
	movq	$11, 184(%rsp)
	movb	$0, 203(%rsp)
	addq	$8, %rbx
.Ltmp33:
	movq	%rbx, %rdi
	leaq	176(%rsp), %rsi
	callq	_ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEE2atERSD_
.Ltmp34:
# %bb.39:                               #   in Loop: Header=BB0_18 Depth=1
	movq	(%rax), %rsi
	testq	%rsi, %rsi
	je	.LBB0_41
# %bb.40:                               #   in Loop: Header=BB0_18 Depth=1
	#APP
	rdtscp
	#NO_APP
                                        # kill: def $edx killed $edx def $rdx
	shlq	$32, %rdx
	movl	%eax, %eax
	orq	%rdx, %rax
	movq	%rax, 32(%rsi)
	jmp	.LBB0_44
	.p2align	4, 0x90
.LBB0_41:                               #   in Loop: Header=BB0_18 Depth=1
.Ltmp35:
	movl	$4, %edx
	movq	_ZSt4cout@GOTPCREL(%rip), %rdi
	leaq	.L.str.14(%rip), %rsi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp36:
# %bb.42:                               #   in Loop: Header=BB0_18 Depth=1
	movq	176(%rsp), %rsi
	movq	184(%rsp), %rdx
.Ltmp37:
	movq	_ZSt4cout@GOTPCREL(%rip), %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp38:
# %bb.43:                               #   in Loop: Header=BB0_18 Depth=1
.Ltmp39:
	movl	$14, %edx
	movq	%rax, %rdi
	leaq	.L.str.15(%rip), %rsi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp40:
.LBB0_44:                               #   in Loop: Header=BB0_18 Depth=1
	movq	176(%rsp), %rdi
	cmpq	%r15, %rdi
	je	.LBB0_46
# %bb.45:                               #   in Loop: Header=BB0_18 Depth=1
	callq	_ZdlPv@PLT
.LBB0_46:                               #   in Loop: Header=BB0_18 Depth=1
	movq	_ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj(%rip), %rbx
	testq	%rbx, %rbx
	jne	.LBB0_49
# %bb.47:                               #   in Loop: Header=BB0_18 Depth=1
	movl	$64, %edi
	callq	_Znwm@PLT
	movq	%rax, %rbx
	movl	$-1, (%rax)
	leaq	8(%rax), %r13
	addq	$56, %rax
	movq	%rax, 8(%rbx)
	movq	$1, 16(%rbx)
	vpxor	%xmm0, %xmm0, %xmm0
	vmovdqu	%xmm0, 24(%rbx)
	movl	$1065353216, 40(%rbx)           # imm = 0x3F800000
	vmovdqu	%xmm0, 48(%rbx)
.Ltmp42:
	movl	$32, %edx
	movq	_ZSt4cout@GOTPCREL(%rip), %rdi
	leaq	.L.str.6(%rip), %rsi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp43:
# %bb.48:                               #   in Loop: Header=BB0_18 Depth=1
	movq	%rbx, _ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj(%rip)
.LBB0_49:                               #   in Loop: Header=BB0_18 Depth=1
	movq	%r14, 144(%rsp)
	movabsq	$6085612663396853060, %rax      # imm = 0x5474707972636544
	movq	%rax, (%r14)
	movl	$1701669204, 7(%r14)            # imm = 0x656D6954
	movq	$11, 152(%rsp)
	movb	$0, 171(%rsp)
.Ltmp45:
	movq	%rbx, %rdi
	leaq	144(%rsp), %rsi
	callq	_ZN11CpuProfiler7stopTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
.Ltmp46:
# %bb.50:                               #   in Loop: Header=BB0_18 Depth=1
	movq	144(%rsp), %rdi
	cmpq	%r14, %rdi
	je	.LBB0_17
# %bb.51:                               #   in Loop: Header=BB0_18 Depth=1
	callq	_ZdlPv@PLT
	jmp	.LBB0_17
.LBB0_52:
	movq	_ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj(%rip), %rbx
	testq	%rbx, %rbx
	jne	.LBB0_55
# %bb.53:
	movl	$64, %edi
	callq	_Znwm@PLT
	movq	%rax, %rbx
	movl	$-1, (%rax)
	leaq	8(%rax), %r14
	addq	$56, %rax
	movq	%rax, 8(%rbx)
	movq	$1, 16(%rbx)
	vpxor	%xmm0, %xmm0, %xmm0
	vmovdqu	%xmm0, 24(%rbx)
	movl	$1065353216, 40(%rbx)           # imm = 0x3F800000
	vmovdqu	%xmm0, 48(%rbx)
.Ltmp48:
	movq	_ZSt4cout@GOTPCREL(%rip), %rdi
	leaq	.L.str.6(%rip), %rsi
	movl	$32, %edx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp49:
# %bb.54:
	movq	%rbx, _ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj(%rip)
.LBB0_55:
	movq	24(%rbx), %rbx
	testq	%rbx, %rbx
	je	.LBB0_64
.LBB0_56:                               # =>This Inner Loop Header: Depth=1
	movq	40(%rbx), %rdi
	callq	_ZN6TagObj26prepareReportAndDumpToFileEv
	movq	(%rbx), %rbx
	testq	%rbx, %rbx
	je	.LBB0_64
# %bb.57:                               #   in Loop: Header=BB0_56 Depth=1
	movq	40(%rbx), %rdi
	callq	_ZN6TagObj26prepareReportAndDumpToFileEv
	movq	(%rbx), %rbx
	testq	%rbx, %rbx
	je	.LBB0_64
# %bb.58:                               #   in Loop: Header=BB0_56 Depth=1
	movq	40(%rbx), %rdi
	callq	_ZN6TagObj26prepareReportAndDumpToFileEv
	movq	(%rbx), %rbx
	testq	%rbx, %rbx
	je	.LBB0_64
# %bb.59:                               #   in Loop: Header=BB0_56 Depth=1
	movq	40(%rbx), %rdi
	callq	_ZN6TagObj26prepareReportAndDumpToFileEv
	movq	(%rbx), %rbx
	testq	%rbx, %rbx
	je	.LBB0_64
# %bb.60:                               #   in Loop: Header=BB0_56 Depth=1
	movq	40(%rbx), %rdi
	callq	_ZN6TagObj26prepareReportAndDumpToFileEv
	movq	(%rbx), %rbx
	testq	%rbx, %rbx
	je	.LBB0_64
# %bb.61:                               #   in Loop: Header=BB0_56 Depth=1
	movq	40(%rbx), %rdi
	callq	_ZN6TagObj26prepareReportAndDumpToFileEv
	movq	(%rbx), %rbx
	testq	%rbx, %rbx
	je	.LBB0_64
# %bb.62:                               #   in Loop: Header=BB0_56 Depth=1
	movq	40(%rbx), %rdi
	callq	_ZN6TagObj26prepareReportAndDumpToFileEv
	movq	(%rbx), %rbx
	testq	%rbx, %rbx
	je	.LBB0_64
# %bb.63:                               #   in Loop: Header=BB0_56 Depth=1
	movq	40(%rbx), %rdi
	callq	_ZN6TagObj26prepareReportAndDumpToFileEv
	movq	(%rbx), %rbx
	testq	%rbx, %rbx
	jne	.LBB0_56
.LBB0_64:
	movq	%fs:40, %rax
	cmpq	336(%rsp), %rax
	jne	.LBB0_88
# %bb.65:
	xorl	%eax, %eax
	addq	$344, %rsp                      # imm = 0x158
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%r12
	.cfi_def_cfa_offset 40
	popq	%r13
	.cfi_def_cfa_offset 32
	popq	%r14
	.cfi_def_cfa_offset 24
	popq	%r15
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	retq
.LBB0_66:
	.cfi_def_cfa_offset 400
	movq	%fs:40, %rax
	cmpq	336(%rsp), %rax
	jne	.LBB0_88
# %bb.67:
	callq	_ZSt16__throw_bad_castv@PLT
.LBB0_68:
.Ltmp50:
	movq	%rax, %rbp
	movq	%r14, %rdi
	jmp	.LBB0_80
.LBB0_69:
.Ltmp8:
	jmp	.LBB0_71
.LBB0_70:
.Ltmp2:
.LBB0_71:
	movq	%rax, %rbp
	movq	%rbx, %rdi
	callq	_ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEED2Ev
	movq	%r14, %rdi
	jmp	.LBB0_85
.LBB0_72:
.Ltmp11:
	movq	%rax, %rbp
	movq	272(%rsp), %rdi
	jmp	.LBB0_74
.LBB0_73:
.Ltmp5:
	movq	%rax, %rbp
	movq	304(%rsp), %rdi
.LBB0_74:
	cmpq	%rbx, %rdi
	jne	.LBB0_85
	jmp	.LBB0_86
.LBB0_75:
.Ltmp32:
	jmp	.LBB0_79
.LBB0_76:
.Ltmp26:
	jmp	.LBB0_79
.LBB0_77:
.Ltmp14:
	jmp	.LBB0_79
.LBB0_78:
.Ltmp44:
.LBB0_79:
	movq	%rax, %rbp
	movq	%r13, %rdi
.LBB0_80:
	callq	_ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEED2Ev
	movq	%rbx, %rdi
	jmp	.LBB0_85
.LBB0_81:
.Ltmp47:
	movq	%rax, %rbp
	movq	144(%rsp), %rdi
	cmpq	%r14, %rdi
	jne	.LBB0_85
	jmp	.LBB0_86
.LBB0_82:
.Ltmp29:
	movq	%rax, %rbp
	movq	208(%rsp), %rdi
	cmpq	%r12, %rdi
	jne	.LBB0_85
	jmp	.LBB0_86
.LBB0_83:
.Ltmp41:
	movq	%rax, %rbp
	movq	176(%rsp), %rdi
	cmpq	%r15, %rdi
	jne	.LBB0_85
	jmp	.LBB0_86
.LBB0_84:
.Ltmp23:
	movq	%rax, %rbp
	movq	240(%rsp), %rdi
	leaq	256(%rsp), %rax
	cmpq	%rax, %rdi
	je	.LBB0_86
.LBB0_85:
	callq	_ZdlPv@PLT
.LBB0_86:
	movq	%fs:40, %rax
	cmpq	336(%rsp), %rax
	jne	.LBB0_88
# %bb.87:
	movq	%rbp, %rdi
	callq	_Unwind_Resume@PLT
.LBB0_88:
	callq	__stack_chk_fail@PLT
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
	.section	.gcc_except_table,"a",@progbits
	.p2align	2, 0x0
GCC_except_table0:
.Lexception0:
	.byte	255                             # @LPStart Encoding = omit
	.byte	255                             # @TType Encoding = omit
	.byte	1                               # Call site Encoding = uleb128
	.uleb128 .Lcst_end0-.Lcst_begin0
.Lcst_begin0:
	.uleb128 .Lfunc_begin0-.Lfunc_begin0    # >> Call Site 1 <<
	.uleb128 .Ltmp0-.Lfunc_begin0           #   Call between .Lfunc_begin0 and .Ltmp0
	.byte	0                               #     has no landing pad
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp0-.Lfunc_begin0           # >> Call Site 2 <<
	.uleb128 .Ltmp1-.Ltmp0                  #   Call between .Ltmp0 and .Ltmp1
	.uleb128 .Ltmp2-.Lfunc_begin0           #     jumps to .Ltmp2
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp3-.Lfunc_begin0           # >> Call Site 3 <<
	.uleb128 .Ltmp4-.Ltmp3                  #   Call between .Ltmp3 and .Ltmp4
	.uleb128 .Ltmp5-.Lfunc_begin0           #     jumps to .Ltmp5
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp4-.Lfunc_begin0           # >> Call Site 4 <<
	.uleb128 .Ltmp6-.Ltmp4                  #   Call between .Ltmp4 and .Ltmp6
	.byte	0                               #     has no landing pad
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp6-.Lfunc_begin0           # >> Call Site 5 <<
	.uleb128 .Ltmp7-.Ltmp6                  #   Call between .Ltmp6 and .Ltmp7
	.uleb128 .Ltmp8-.Lfunc_begin0           #     jumps to .Ltmp8
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp9-.Lfunc_begin0           # >> Call Site 6 <<
	.uleb128 .Ltmp10-.Ltmp9                 #   Call between .Ltmp9 and .Ltmp10
	.uleb128 .Ltmp11-.Lfunc_begin0          #     jumps to .Ltmp11
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp10-.Lfunc_begin0          # >> Call Site 7 <<
	.uleb128 .Ltmp12-.Ltmp10                #   Call between .Ltmp10 and .Ltmp12
	.byte	0                               #     has no landing pad
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp12-.Lfunc_begin0          # >> Call Site 8 <<
	.uleb128 .Ltmp13-.Ltmp12                #   Call between .Ltmp12 and .Ltmp13
	.uleb128 .Ltmp14-.Lfunc_begin0          #     jumps to .Ltmp14
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp15-.Lfunc_begin0          # >> Call Site 9 <<
	.uleb128 .Ltmp22-.Ltmp15                #   Call between .Ltmp15 and .Ltmp22
	.uleb128 .Ltmp23-.Lfunc_begin0          #     jumps to .Ltmp23
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp22-.Lfunc_begin0          # >> Call Site 10 <<
	.uleb128 .Ltmp24-.Ltmp22                #   Call between .Ltmp22 and .Ltmp24
	.byte	0                               #     has no landing pad
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp24-.Lfunc_begin0          # >> Call Site 11 <<
	.uleb128 .Ltmp25-.Ltmp24                #   Call between .Ltmp24 and .Ltmp25
	.uleb128 .Ltmp26-.Lfunc_begin0          #     jumps to .Ltmp26
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp27-.Lfunc_begin0          # >> Call Site 12 <<
	.uleb128 .Ltmp28-.Ltmp27                #   Call between .Ltmp27 and .Ltmp28
	.uleb128 .Ltmp29-.Lfunc_begin0          #     jumps to .Ltmp29
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp28-.Lfunc_begin0          # >> Call Site 13 <<
	.uleb128 .Ltmp30-.Ltmp28                #   Call between .Ltmp28 and .Ltmp30
	.byte	0                               #     has no landing pad
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp30-.Lfunc_begin0          # >> Call Site 14 <<
	.uleb128 .Ltmp31-.Ltmp30                #   Call between .Ltmp30 and .Ltmp31
	.uleb128 .Ltmp32-.Lfunc_begin0          #     jumps to .Ltmp32
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp33-.Lfunc_begin0          # >> Call Site 15 <<
	.uleb128 .Ltmp40-.Ltmp33                #   Call between .Ltmp33 and .Ltmp40
	.uleb128 .Ltmp41-.Lfunc_begin0          #     jumps to .Ltmp41
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp40-.Lfunc_begin0          # >> Call Site 16 <<
	.uleb128 .Ltmp42-.Ltmp40                #   Call between .Ltmp40 and .Ltmp42
	.byte	0                               #     has no landing pad
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp42-.Lfunc_begin0          # >> Call Site 17 <<
	.uleb128 .Ltmp43-.Ltmp42                #   Call between .Ltmp42 and .Ltmp43
	.uleb128 .Ltmp44-.Lfunc_begin0          #     jumps to .Ltmp44
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp45-.Lfunc_begin0          # >> Call Site 18 <<
	.uleb128 .Ltmp46-.Ltmp45                #   Call between .Ltmp45 and .Ltmp46
	.uleb128 .Ltmp47-.Lfunc_begin0          #     jumps to .Ltmp47
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp46-.Lfunc_begin0          # >> Call Site 19 <<
	.uleb128 .Ltmp48-.Ltmp46                #   Call between .Ltmp46 and .Ltmp48
	.byte	0                               #     has no landing pad
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp48-.Lfunc_begin0          # >> Call Site 20 <<
	.uleb128 .Ltmp49-.Ltmp48                #   Call between .Ltmp48 and .Ltmp49
	.uleb128 .Ltmp50-.Lfunc_begin0          #     jumps to .Ltmp50
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp49-.Lfunc_begin0          # >> Call Site 21 <<
	.uleb128 .Lfunc_end0-.Ltmp49            #   Call between .Ltmp49 and .Lfunc_end0
	.byte	0                               #     has no landing pad
	.byte	0                               #   On action: cleanup
.Lcst_end0:
	.p2align	2, 0x0
                                        # -- End function
	.section	.text._ZN11CpuProfiler6addTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,"axG",@progbits,_ZN11CpuProfiler6addTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,comdat
	.weak	_ZN11CpuProfiler6addTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE # -- Begin function _ZN11CpuProfiler6addTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.p2align	4, 0x90
	.type	_ZN11CpuProfiler6addTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,@function
_ZN11CpuProfiler6addTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE: # 
.Lfunc_begin1:
	.cfi_startproc
	.cfi_personality 155, DW.ref.__gxx_personality_v0
	.cfi_lsda 27, .Lexception1
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%r15
	.cfi_def_cfa_offset 24
	pushq	%r14
	.cfi_def_cfa_offset 32
	pushq	%r13
	.cfi_def_cfa_offset 40
	pushq	%r12
	.cfi_def_cfa_offset 48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	subq	$56, %rsp
	.cfi_def_cfa_offset 112
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	.cfi_offset %rbp, -16
	movq	%rsi, %r14
	movq	%rdi, %r15
	movq	%fs:40, %rax
	movq	%rax, 48(%rsp)
	movl	$80, %edi
	callq	_Znwm@PLT
	movq	%rax, %rbx
	leaq	32(%rsp), %rbp
	movq	%rbp, 16(%rsp)
	movq	(%r14), %r12
	movq	8(%r14), %r13
	movq	%r13, 8(%rsp)
	movq	%rbp, %rax
	cmpq	$16, %r13
	jb	.LBB1_3
# %bb.1:
.Ltmp51:
	leaq	16(%rsp), %rdi
	leaq	8(%rsp), %rsi
	xorl	%edx, %edx
	callq	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm@PLT
.Ltmp52:
# %bb.2:
	movq	%rax, 16(%rsp)
	movq	8(%rsp), %rcx
	movq	%rcx, 32(%rsp)
.LBB1_3:
	testq	%r13, %r13
	je	.LBB1_7
# %bb.4:
	cmpq	$1, %r13
	jne	.LBB1_6
# %bb.5:
	movzbl	(%r12), %ecx
	movb	%cl, (%rax)
	jmp	.LBB1_7
.LBB1_6:
	movq	%rax, %rdi
	movq	%r12, %rsi
	movq	%r13, %rdx
	callq	_intel_fast_memcpy@PLT
.LBB1_7:
	movq	8(%rsp), %rax
	movq	%rax, 24(%rsp)
	movq	16(%rsp), %rcx
	movb	$0, (%rcx,%rax)
	movl	(%r15), %edx
.Ltmp54:
	leaq	16(%rsp), %rsi
	movq	%rbx, %rdi
	callq	_ZN6TagObjC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEj
.Ltmp55:
# %bb.8:
	movq	16(%rsp), %rdi
	cmpq	%rbp, %rdi
	je	.LBB1_10
# %bb.9:
	callq	_ZdlPv@PLT
.LBB1_10:
	addq	$8, %r15
	movq	%r15, %rdi
	movq	%r14, %rsi
	callq	_ZNSt8__detail9_Map_baseINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS6_P6TagObjESaISB_ENS_10_Select1stESt8equal_toIS6_ESt4hashIS6_ENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixERS8_
	movq	%rbx, (%rax)
	movq	%fs:40, %rax
	cmpq	48(%rsp), %rax
	jne	.LBB1_17
# %bb.11:
	addq	$56, %rsp
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%r12
	.cfi_def_cfa_offset 40
	popq	%r13
	.cfi_def_cfa_offset 32
	popq	%r14
	.cfi_def_cfa_offset 24
	popq	%r15
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	retq
.LBB1_12:
	.cfi_def_cfa_offset 112
.Ltmp53:
	movq	%rax, %r14
	jmp	.LBB1_15
.LBB1_13:
.Ltmp56:
	movq	%rax, %r14
	movq	16(%rsp), %rdi
	cmpq	%rbp, %rdi
	je	.LBB1_15
# %bb.14:
	callq	_ZdlPv@PLT
.LBB1_15:
	movq	%rbx, %rdi
	callq	_ZdlPv@PLT
	movq	%fs:40, %rax
	cmpq	48(%rsp), %rax
	jne	.LBB1_17
# %bb.16:
	movq	%r14, %rdi
	callq	_Unwind_Resume@PLT
.LBB1_17:
	callq	__stack_chk_fail@PLT
.Lfunc_end1:
	.size	_ZN11CpuProfiler6addTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, .Lfunc_end1-_ZN11CpuProfiler6addTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.cfi_endproc
	.section	.gcc_except_table._ZN11CpuProfiler6addTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,"aG",@progbits,_ZN11CpuProfiler6addTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,comdat
	.p2align	2, 0x0
GCC_except_table1:
.Lexception1:
	.byte	255                             # @LPStart Encoding = omit
	.byte	255                             # @TType Encoding = omit
	.byte	1                               # Call site Encoding = uleb128
	.uleb128 .Lcst_end1-.Lcst_begin1
.Lcst_begin1:
	.uleb128 .Lfunc_begin1-.Lfunc_begin1    # >> Call Site 1 <<
	.uleb128 .Ltmp51-.Lfunc_begin1          #   Call between .Lfunc_begin1 and .Ltmp51
	.byte	0                               #     has no landing pad
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp51-.Lfunc_begin1          # >> Call Site 2 <<
	.uleb128 .Ltmp52-.Ltmp51                #   Call between .Ltmp51 and .Ltmp52
	.uleb128 .Ltmp53-.Lfunc_begin1          #     jumps to .Ltmp53
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp52-.Lfunc_begin1          # >> Call Site 3 <<
	.uleb128 .Ltmp54-.Ltmp52                #   Call between .Ltmp52 and .Ltmp54
	.byte	0                               #     has no landing pad
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp54-.Lfunc_begin1          # >> Call Site 4 <<
	.uleb128 .Ltmp55-.Ltmp54                #   Call between .Ltmp54 and .Ltmp55
	.uleb128 .Ltmp56-.Lfunc_begin1          #     jumps to .Ltmp56
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp55-.Lfunc_begin1          # >> Call Site 5 <<
	.uleb128 .Lfunc_end1-.Ltmp55            #   Call between .Ltmp55 and .Lfunc_end1
	.byte	0                               #     has no landing pad
	.byte	0                               #   On action: cleanup
.Lcst_end1:
	.p2align	2, 0x0
                                        # -- End function
	.section	.text._ZN11CpuProfiler7stopTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,"axG",@progbits,_ZN11CpuProfiler7stopTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,comdat
	.weak	_ZN11CpuProfiler7stopTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE # -- Begin function _ZN11CpuProfiler7stopTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.p2align	4, 0x90
	.type	_ZN11CpuProfiler7stopTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,@function
_ZN11CpuProfiler7stopTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE: # 
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%r15
	.cfi_def_cfa_offset 24
	pushq	%r14
	.cfi_def_cfa_offset 32
	pushq	%r13
	.cfi_def_cfa_offset 40
	pushq	%r12
	.cfi_def_cfa_offset 48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	.cfi_offset %rbp, -16
	movq	%rsi, %rbx
	addq	$8, %rdi
	callq	_ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEE2atERSD_
	movq	(%rax), %r12
	testq	%r12, %r12
	je	.LBB2_15
# %bb.1:
	#APP
	rdtscp
	#NO_APP
                                        # kill: def $edx killed $edx def $rdx
	shlq	$32, %rdx
	movl	%eax, %r13d
	orq	%rdx, %r13
	movq	%r13, 40(%r12)
	movq	32(%r12), %rax
	testq	%rax, %rax
	jne	.LBB2_3
# %bb.2:
	movq	_ZSt4cout@GOTPCREL(%rip), %rbx
	leaq	.L.str.17(%rip), %rsi
	movl	$23, %edx
	movq	%rbx, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	(%r12), %rsi
	movq	8(%r12), %rdx
	movq	%rbx, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	leaq	.L.str.18(%rip), %rsi
	movl	$13, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	32(%r12), %rax
	movq	40(%r12), %r13
.LBB2_3:
	incl	72(%r12)
	subq	%rax, %r13
	movq	56(%r12), %r14
	cmpq	64(%r12), %r14
	je	.LBB2_5
# %bb.4:
	movq	%r13, (%r14)
	addq	$8, %r14
	movq	%r14, 56(%r12)
	jmp	.LBB2_14
.LBB2_15:
	movq	_ZSt4cout@GOTPCREL(%rip), %r14
	leaq	.L.str.14(%rip), %rsi
	movl	$4, %edx
	movq	%r14, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	(%rbx), %rsi
	movq	8(%rbx), %rdx
	movq	%r14, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	leaq	.L.str.15(%rip), %rsi
	movl	$14, %edx
	movq	%rax, %rdi
	addq	$24, %rsp
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%r12
	.cfi_def_cfa_offset 40
	popq	%r13
	.cfi_def_cfa_offset 32
	popq	%r14
	.cfi_def_cfa_offset 24
	popq	%r15
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	jmp	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT # TAILCALL
.LBB2_5:
	.cfi_def_cfa_offset 80
	movq	48(%r12), %rax
	movq	%rax, 16(%rsp)                  # 8-byte Spill
	subq	%rax, %r14
	movabsq	$9223372036854775800, %rax      # imm = 0x7FFFFFFFFFFFFFF8
	cmpq	%rax, %r14
	je	.LBB2_16
# %bb.6:
	movq	%r14, %rbx
	sarq	$3, %rbx
	cmpq	$1, %rbx
	movq	%rbx, %rax
	adcq	$0, %rax
	leaq	(%rax,%rbx), %rbp
	movq	%rbp, %rcx
	shrq	$60, %rcx
	movabsq	$1152921504606846975, %rcx      # imm = 0xFFFFFFFFFFFFFFF
	cmovneq	%rcx, %rbp
	addq	%rbx, %rax
	cmovbq	%rcx, %rbp
	testq	%rbp, %rbp
	je	.LBB2_7
# %bb.8:
	leaq	(,%rbp,8), %rdi
	callq	_Znwm@PLT
	movq	%rax, %r15
	jmp	.LBB2_9
.LBB2_7:
	xorl	%r15d, %r15d
.LBB2_9:
	leaq	(%r15,%rbx,8), %rax
	movq	%rax, 8(%rsp)                   # 8-byte Spill
	movq	%r13, (%r15,%rbx,8)
	testq	%r14, %r14
	movq	16(%rsp), %rbx                  # 8-byte Reload
	jle	.LBB2_11
# %bb.10:
	movq	%r15, %rdi
	movq	%rbx, %rsi
	movq	%r14, %rdx
	callq	_intel_fast_memcpy@PLT
.LBB2_11:
	movq	8(%rsp), %r14                   # 8-byte Reload
	addq	$8, %r14
	testq	%rbx, %rbx
	je	.LBB2_13
# %bb.12:
	movq	%rbx, %rdi
	callq	_ZdlPv@PLT
.LBB2_13:
	movq	%r15, 48(%r12)
	movq	%r14, 56(%r12)
	leaq	(%r15,%rbp,8), %rax
	movq	%rax, 64(%r12)
.LBB2_14:
	addq	$24, %rsp
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%r12
	.cfi_def_cfa_offset 40
	popq	%r13
	.cfi_def_cfa_offset 32
	popq	%r14
	.cfi_def_cfa_offset 24
	popq	%r15
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	retq
.LBB2_16:
	.cfi_def_cfa_offset 80
	leaq	.L.str.19(%rip), %rdi
	callq	_ZSt20__throw_length_errorPKc@PLT
.Lfunc_end2:
	.size	_ZN11CpuProfiler7stopTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, .Lfunc_end2-_ZN11CpuProfiler7stopTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.cfi_endproc
                                        # -- End function
	.section	.text._ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEED2Ev,"axG",@progbits,_ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEED2Ev,comdat
	.weak	_ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEED2Ev # -- Begin function _ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEED2Ev
	.p2align	4, 0x90
	.type	_ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEED2Ev,@function
_ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEED2Ev: # 
	.cfi_startproc
# %bb.0:
	pushq	%r15
	.cfi_def_cfa_offset 16
	pushq	%r14
	.cfi_def_cfa_offset 24
	pushq	%r12
	.cfi_def_cfa_offset 32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	pushq	%rax
	.cfi_def_cfa_offset 48
	.cfi_offset %rbx, -40
	.cfi_offset %r12, -32
	.cfi_offset %r14, -24
	.cfi_offset %r15, -16
	movq	%rdi, %rbx
	leaq	16(%rdi), %r12
	movq	16(%rdi), %r14
	testq	%r14, %r14
	je	.LBB3_2
.LBB3_4:                                # =>This Inner Loop Header: Depth=1
	movq	(%r14), %r15
	movq	8(%r14), %rdi
	leaq	24(%r14), %rax
	cmpq	%rax, %rdi
	je	.LBB3_6
# %bb.5:                                #   in Loop: Header=BB3_4 Depth=1
	callq	_ZdlPv@PLT
.LBB3_6:                                #   in Loop: Header=BB3_4 Depth=1
	movq	%r14, %rdi
	callq	_ZdlPv@PLT
	testq	%r15, %r15
	je	.LBB3_2
# %bb.7:                                #   in Loop: Header=BB3_4 Depth=1
	movq	(%r15), %r14
	movq	8(%r15), %rdi
	leaq	24(%r15), %rax
	cmpq	%rax, %rdi
	je	.LBB3_9
# %bb.8:                                #   in Loop: Header=BB3_4 Depth=1
	callq	_ZdlPv@PLT
.LBB3_9:                                #   in Loop: Header=BB3_4 Depth=1
	movq	%r15, %rdi
	callq	_ZdlPv@PLT
	testq	%r14, %r14
	je	.LBB3_2
# %bb.10:                               #   in Loop: Header=BB3_4 Depth=1
	movq	(%r14), %r15
	movq	8(%r14), %rdi
	leaq	24(%r14), %rax
	cmpq	%rax, %rdi
	je	.LBB3_12
# %bb.11:                               #   in Loop: Header=BB3_4 Depth=1
	callq	_ZdlPv@PLT
.LBB3_12:                               #   in Loop: Header=BB3_4 Depth=1
	movq	%r14, %rdi
	callq	_ZdlPv@PLT
	testq	%r15, %r15
	je	.LBB3_2
# %bb.13:                               #   in Loop: Header=BB3_4 Depth=1
	movq	(%r15), %r14
	movq	8(%r15), %rdi
	leaq	24(%r15), %rax
	cmpq	%rax, %rdi
	je	.LBB3_15
# %bb.14:                               #   in Loop: Header=BB3_4 Depth=1
	callq	_ZdlPv@PLT
.LBB3_15:                               #   in Loop: Header=BB3_4 Depth=1
	movq	%r15, %rdi
	callq	_ZdlPv@PLT
	testq	%r14, %r14
	je	.LBB3_2
# %bb.16:                               #   in Loop: Header=BB3_4 Depth=1
	movq	(%r14), %r15
	movq	8(%r14), %rdi
	leaq	24(%r14), %rax
	cmpq	%rax, %rdi
	je	.LBB3_18
# %bb.17:                               #   in Loop: Header=BB3_4 Depth=1
	callq	_ZdlPv@PLT
.LBB3_18:                               #   in Loop: Header=BB3_4 Depth=1
	movq	%r14, %rdi
	callq	_ZdlPv@PLT
	testq	%r15, %r15
	je	.LBB3_2
# %bb.19:                               #   in Loop: Header=BB3_4 Depth=1
	movq	(%r15), %r14
	movq	8(%r15), %rdi
	leaq	24(%r15), %rax
	cmpq	%rax, %rdi
	je	.LBB3_21
# %bb.20:                               #   in Loop: Header=BB3_4 Depth=1
	callq	_ZdlPv@PLT
.LBB3_21:                               #   in Loop: Header=BB3_4 Depth=1
	movq	%r15, %rdi
	callq	_ZdlPv@PLT
	testq	%r14, %r14
	je	.LBB3_2
# %bb.22:                               #   in Loop: Header=BB3_4 Depth=1
	movq	(%r14), %r15
	movq	8(%r14), %rdi
	leaq	24(%r14), %rax
	cmpq	%rax, %rdi
	je	.LBB3_24
# %bb.23:                               #   in Loop: Header=BB3_4 Depth=1
	callq	_ZdlPv@PLT
.LBB3_24:                               #   in Loop: Header=BB3_4 Depth=1
	movq	%r14, %rdi
	callq	_ZdlPv@PLT
	testq	%r15, %r15
	je	.LBB3_2
# %bb.25:                               #   in Loop: Header=BB3_4 Depth=1
	movq	(%r15), %r14
	movq	8(%r15), %rdi
	leaq	24(%r15), %rax
	cmpq	%rax, %rdi
	je	.LBB3_27
# %bb.26:                               #   in Loop: Header=BB3_4 Depth=1
	callq	_ZdlPv@PLT
.LBB3_27:                               #   in Loop: Header=BB3_4 Depth=1
	movq	%r15, %rdi
	callq	_ZdlPv@PLT
	testq	%r14, %r14
	jne	.LBB3_4
.LBB3_2:
	movq	(%rbx), %rdi
	movq	8(%rbx), %rdx
	shlq	$3, %rdx
	xorl	%esi, %esi
	callq	_intel_fast_memset@PLT
	vxorps	%xmm0, %xmm0, %xmm0
	vmovups	%xmm0, (%r12)
	movq	(%rbx), %rdi
	addq	$48, %rbx
	addq	$8, %rsp
	cmpq	%rdi, %rbx
	je	.LBB3_3
# %bb.28:
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	jmp	_ZdlPv@PLT                      # TAILCALL
.LBB3_3:
	.cfi_def_cfa_offset 48
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end3:
	.size	_ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEED2Ev, .Lfunc_end3-_ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEED2Ev
	.cfi_endproc
                                        # -- End function
	.section	.text.__clang_call_terminate,"axG",@progbits,__clang_call_terminate,comdat
	.hidden	__clang_call_terminate          # -- Begin function __clang_call_terminate
	.weak	__clang_call_terminate
	.p2align	4, 0x90
	.type	__clang_call_terminate,@function
__clang_call_terminate:                 # 
	.cfi_startproc
# %bb.0:
	pushq	%rax
	.cfi_def_cfa_offset 16
	callq	__cxa_begin_catch@PLT
	callq	_ZSt9terminatev@PLT
.Lfunc_end4:
	.size	__clang_call_terminate, .Lfunc_end4-__clang_call_terminate
	.cfi_endproc
                                        # -- End function
	.section	.text._ZN6TagObjC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEj,"axG",@progbits,_ZN6TagObjC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEj,comdat
	.weak	_ZN6TagObjC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEj # -- Begin function _ZN6TagObjC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEj
	.p2align	4, 0x90
	.type	_ZN6TagObjC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEj,@function
_ZN6TagObjC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEj: # 
.Lfunc_begin2:
	.cfi_startproc
	.cfi_personality 155, DW.ref.__gxx_personality_v0
	.cfi_lsda 27, .Lexception2
# %bb.0:
	pushq	%r15
	.cfi_def_cfa_offset 16
	pushq	%r14
	.cfi_def_cfa_offset 24
	pushq	%r13
	.cfi_def_cfa_offset 32
	pushq	%r12
	.cfi_def_cfa_offset 40
	pushq	%rbx
	.cfi_def_cfa_offset 48
	subq	$592, %rsp                      # imm = 0x250
	.cfi_def_cfa_offset 640
	.cfi_offset %rbx, -48
	.cfi_offset %r12, -40
	.cfi_offset %r13, -32
	.cfi_offset %r14, -24
	.cfi_offset %r15, -16
	movq	%rdi, %rbx
	movq	%fs:40, %rax
	movq	%rax, 584(%rsp)
	leaq	16(%rdi), %r12
	movq	%r12, (%rdi)
	movq	(%rsi), %r14
	movq	8(%rsi), %r15
	movq	%r15, 8(%rsp)
	movq	%r12, %rax
	cmpq	$16, %r15
	jb	.LBB5_2
# %bb.1:
	leaq	8(%rsp), %rsi
	movq	%rbx, %rdi
	xorl	%edx, %edx
	callq	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm@PLT
	movq	%rax, (%rbx)
	movq	8(%rsp), %rcx
	movq	%rcx, 16(%rbx)
.LBB5_2:
	testq	%r15, %r15
	je	.LBB5_6
# %bb.3:
	cmpq	$1, %r15
	jne	.LBB5_5
# %bb.4:
	movzbl	(%r14), %ecx
	movb	%cl, (%rax)
	jmp	.LBB5_6
.LBB5_5:
	movq	%rax, %rdi
	movq	%r14, %rsi
	movq	%r15, %rdx
	callq	_intel_fast_memcpy@PLT
.LBB5_6:
	movq	8(%rsp), %rax
	movq	%rax, 8(%rbx)
	movq	(%rbx), %rcx
	movb	$0, (%rcx,%rax)
	vxorps	%xmm0, %xmm0, %xmm0
	vmovups	%xmm0, 48(%rbx)
	movq	$0, 64(%rbx)
	movl	$4294967295, %eax               # imm = 0xFFFFFFFF
	movq	%rax, 72(%rbx)
.Ltmp57:
	leaq	8(%rsp), %r14
	movq	%r14, %rdi
	callq	_ZNSt14basic_ofstreamIcSt11char_traitsIcEEC1Ev@PLT
.Ltmp58:
# %bb.7:
.Ltmp60:
	movq	_ZSt4cout@GOTPCREL(%rip), %rdi
	leaq	.L.str.8(%rip), %rsi
	movl	$27, %edx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp61:
# %bb.8:
.Ltmp62:
	leaq	.L.str.9(%rip), %rsi
	leaq	520(%rsp), %rdi
	movq	%rbx, %rdx
	callq	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_RKS8_
.Ltmp63:
# %bb.9:
	movq	528(%rsp), %rax
	shrq	$2, %rax
	movabsq	$1152921504606846975, %rcx      # imm = 0xFFFFFFFFFFFFFFF
	cmpq	%rcx, %rax
	je	.LBB5_27
# %bb.10:
.Ltmp65:
	leaq	.L.str.10(%rip), %rsi
	leaq	520(%rsp), %rdi
	movl	$4, %edx
	callq	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_appendEPKcm@PLT
.Ltmp66:
# %bb.11:
	leaq	568(%rsp), %r13
	movq	%r13, 552(%rsp)
	movq	(%rax), %rsi
	movq	%rax, %rcx
	addq	$16, %rcx
	cmpq	%rcx, %rsi
	je	.LBB5_13
# %bb.12:
	movq	%rsi, 552(%rsp)
	movq	(%rcx), %rdx
	movq	%rdx, 568(%rsp)
	jmp	.LBB5_14
.LBB5_13:
	vmovups	(%rsi), %xmm0
	vmovups	%xmm0, (%r13)
	movq	%r13, %rsi
.LBB5_14:
	movq	8(%rax), %rdx
	movq	%rdx, 560(%rsp)
	movq	%rcx, (%rax)
	movq	$0, 8(%rax)
	movb	$0, (%rcx)
	leaq	16(%rsp), %r15
.Ltmp67:
	movq	%r15, %rdi
	movl	$48, %edx
	callq	_ZNSt13basic_filebufIcSt11char_traitsIcEE4openEPKcSt13_Ios_Openmode@PLT
.Ltmp68:
# %bb.15:
	movq	8(%rsp), %rcx
	addq	-24(%rcx), %r14
	xorl	%esi, %esi
	testq	%rax, %rax
	jne	.LBB5_17
# %bb.16:
	movl	32(%r14), %esi
	orl	$4, %esi
.LBB5_17:
.Ltmp69:
	movq	%r14, %rdi
	callq	_ZNSt9basic_iosIcSt11char_traitsIcEE5clearESt12_Ios_Iostate@PLT
.Ltmp70:
# %bb.18:
	movq	552(%rsp), %rdi
	cmpq	%r13, %rdi
	je	.LBB5_20
# %bb.19:
	callq	_ZdlPv@PLT
.LBB5_20:
	movq	520(%rsp), %rdi
	leaq	536(%rsp), %rax
	cmpq	%rax, %rdi
	je	.LBB5_22
# %bb.21:
	callq	_ZdlPv@PLT
.LBB5_22:
.Ltmp72:
	movq	%r15, %rdi
	callq	_ZNSt13basic_filebufIcSt11char_traitsIcEE5closeEv@PLT
.Ltmp73:
# %bb.23:
	testq	%rax, %rax
	jne	.LBB5_25
# %bb.24:
	movq	8(%rsp), %rax
	movq	-24(%rax), %rax
	leaq	(%rsp,%rax), %rdi
	addq	$8, %rdi
	movl	40(%rsp,%rax), %esi
	orl	$4, %esi
.Ltmp74:
	callq	_ZNSt9basic_iosIcSt11char_traitsIcEE5clearESt12_Ios_Iostate@PLT
.Ltmp75:
.LBB5_25:
	leaq	8(%rsp), %rdi
	callq	_ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev@PLT
	movq	%fs:40, %rax
	cmpq	584(%rsp), %rax
	jne	.LBB5_46
# %bb.26:
	addq	$592, %rsp                      # imm = 0x250
	.cfi_def_cfa_offset 48
	popq	%rbx
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	retq
.LBB5_27:
	.cfi_def_cfa_offset 640
	movq	%fs:40, %rax
	cmpq	584(%rsp), %rax
	jne	.LBB5_46
# %bb.28:
.Ltmp77:
	leaq	.L.str.11(%rip), %rdi
	callq	_ZSt20__throw_length_errorPKc@PLT
.Ltmp78:
# %bb.29:
.LBB5_30:
.Ltmp64:
	jmp	.LBB5_38
.LBB5_31:
.Ltmp59:
	movq	%rax, %r14
	jmp	.LBB5_40
.LBB5_32:
.Ltmp71:
	movq	%rax, %r14
	movq	552(%rsp), %rdi
	cmpq	%r13, %rdi
	je	.LBB5_35
# %bb.33:
	callq	_ZdlPv@PLT
	jmp	.LBB5_35
.LBB5_34:
.Ltmp79:
	movq	%rax, %r14
.LBB5_35:
	movq	520(%rsp), %rdi
	leaq	536(%rsp), %rax
	cmpq	%rax, %rdi
	je	.LBB5_39
# %bb.36:
	callq	_ZdlPv@PLT
	jmp	.LBB5_39
.LBB5_37:
.Ltmp76:
.LBB5_38:
	movq	%rax, %r14
.LBB5_39:
	leaq	8(%rsp), %rdi
	callq	_ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev@PLT
.LBB5_40:
	leaq	48(%rbx), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	jne	.LBB5_44
# %bb.41:
	movq	(%rbx), %rdi
	cmpq	%r12, %rdi
	jne	.LBB5_45
.LBB5_42:
	movq	%fs:40, %rax
	cmpq	584(%rsp), %rax
	jne	.LBB5_46
.LBB5_43:
	movq	%r14, %rdi
	callq	_Unwind_Resume@PLT
.LBB5_44:
	callq	_ZdlPv@PLT
	movq	(%rbx), %rdi
	cmpq	%r12, %rdi
	je	.LBB5_42
.LBB5_45:
	callq	_ZdlPv@PLT
	movq	%fs:40, %rax
	cmpq	584(%rsp), %rax
	je	.LBB5_43
.LBB5_46:
	callq	__stack_chk_fail@PLT
.Lfunc_end5:
	.size	_ZN6TagObjC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEj, .Lfunc_end5-_ZN6TagObjC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEj
	.cfi_endproc
	.section	.gcc_except_table._ZN6TagObjC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEj,"aG",@progbits,_ZN6TagObjC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEj,comdat
	.p2align	2, 0x0
GCC_except_table5:
.Lexception2:
	.byte	255                             # @LPStart Encoding = omit
	.byte	255                             # @TType Encoding = omit
	.byte	1                               # Call site Encoding = uleb128
	.uleb128 .Lcst_end2-.Lcst_begin2
.Lcst_begin2:
	.uleb128 .Lfunc_begin2-.Lfunc_begin2    # >> Call Site 1 <<
	.uleb128 .Ltmp57-.Lfunc_begin2          #   Call between .Lfunc_begin2 and .Ltmp57
	.byte	0                               #     has no landing pad
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp57-.Lfunc_begin2          # >> Call Site 2 <<
	.uleb128 .Ltmp58-.Ltmp57                #   Call between .Ltmp57 and .Ltmp58
	.uleb128 .Ltmp59-.Lfunc_begin2          #     jumps to .Ltmp59
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp60-.Lfunc_begin2          # >> Call Site 3 <<
	.uleb128 .Ltmp61-.Ltmp60                #   Call between .Ltmp60 and .Ltmp61
	.uleb128 .Ltmp76-.Lfunc_begin2          #     jumps to .Ltmp76
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp62-.Lfunc_begin2          # >> Call Site 4 <<
	.uleb128 .Ltmp63-.Ltmp62                #   Call between .Ltmp62 and .Ltmp63
	.uleb128 .Ltmp64-.Lfunc_begin2          #     jumps to .Ltmp64
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp65-.Lfunc_begin2          # >> Call Site 5 <<
	.uleb128 .Ltmp66-.Ltmp65                #   Call between .Ltmp65 and .Ltmp66
	.uleb128 .Ltmp79-.Lfunc_begin2          #     jumps to .Ltmp79
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp67-.Lfunc_begin2          # >> Call Site 6 <<
	.uleb128 .Ltmp70-.Ltmp67                #   Call between .Ltmp67 and .Ltmp70
	.uleb128 .Ltmp71-.Lfunc_begin2          #     jumps to .Ltmp71
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp72-.Lfunc_begin2          # >> Call Site 7 <<
	.uleb128 .Ltmp75-.Ltmp72                #   Call between .Ltmp72 and .Ltmp75
	.uleb128 .Ltmp76-.Lfunc_begin2          #     jumps to .Ltmp76
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp77-.Lfunc_begin2          # >> Call Site 8 <<
	.uleb128 .Ltmp78-.Ltmp77                #   Call between .Ltmp77 and .Ltmp78
	.uleb128 .Ltmp79-.Lfunc_begin2          #     jumps to .Ltmp79
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp78-.Lfunc_begin2          # >> Call Site 9 <<
	.uleb128 .Lfunc_end5-.Ltmp78            #   Call between .Ltmp78 and .Lfunc_end5
	.byte	0                               #     has no landing pad
	.byte	0                               #   On action: cleanup
.Lcst_end2:
	.p2align	2, 0x0
                                        # -- End function
	.section	.text._ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_RKS8_,"axG",@progbits,_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_RKS8_,comdat
	.weak	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_RKS8_ # -- Begin function _ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_RKS8_
	.p2align	4, 0x90
	.type	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_RKS8_,@function
_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_RKS8_: # 
.Lfunc_begin3:
	.cfi_startproc
	.cfi_personality 155, DW.ref.__gxx_personality_v0
	.cfi_lsda 27, .Lexception3
# %bb.0:
	pushq	%r15
	.cfi_def_cfa_offset 16
	pushq	%r14
	.cfi_def_cfa_offset 24
	pushq	%r13
	.cfi_def_cfa_offset 32
	pushq	%r12
	.cfi_def_cfa_offset 40
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset %rbx, -48
	.cfi_offset %r12, -40
	.cfi_offset %r13, -32
	.cfi_offset %r14, -24
	.cfi_offset %r15, -16
	movq	%rdx, %r14
	movq	%rsi, %r15
	movq	%rdi, %rbx
	movq	%rsi, %rdi
	callq	strlen@PLT
	movq	%rax, %r12
	leaq	16(%rbx), %r13
	movq	%r13, (%rbx)
	movq	$0, 8(%rbx)
	movb	$0, 16(%rbx)
	movq	8(%r14), %rsi
	addq	%rax, %rsi
.Ltmp80:
	movq	%rbx, %rdi
	callq	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7reserveEm@PLT
.Ltmp81:
# %bb.1:
	movabsq	$4611686018427387903, %rax      # imm = 0x3FFFFFFFFFFFFFFF
	subq	8(%rbx), %rax
	cmpq	%r12, %rax
	jb	.LBB6_2
# %bb.4:
.Ltmp82:
	movq	%rbx, %rdi
	movq	%r15, %rsi
	movq	%r12, %rdx
	callq	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_appendEPKcm@PLT
.Ltmp83:
# %bb.5:
	movq	(%r14), %rsi
	movq	8(%r14), %rdx
.Ltmp84:
	movq	%rbx, %rdi
	callq	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_appendEPKcm@PLT
.Ltmp85:
# %bb.6:
	movq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	retq
.LBB6_2:
	.cfi_def_cfa_offset 48
.Ltmp86:
	leaq	.L.str.11(%rip), %rdi
	callq	_ZSt20__throw_length_errorPKc@PLT
.Ltmp87:
# %bb.3:
.LBB6_7:
.Ltmp88:
	movq	%rax, %r14
	movq	(%rbx), %rdi
	cmpq	%r13, %rdi
	je	.LBB6_9
# %bb.8:
	callq	_ZdlPv@PLT
.LBB6_9:
	movq	%r14, %rdi
	callq	_Unwind_Resume@PLT
.Lfunc_end6:
	.size	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_RKS8_, .Lfunc_end6-_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_RKS8_
	.cfi_endproc
	.section	.gcc_except_table._ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_RKS8_,"aG",@progbits,_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_RKS8_,comdat
	.p2align	2, 0x0
GCC_except_table6:
.Lexception3:
	.byte	255                             # @LPStart Encoding = omit
	.byte	255                             # @TType Encoding = omit
	.byte	1                               # Call site Encoding = uleb128
	.uleb128 .Lcst_end3-.Lcst_begin3
.Lcst_begin3:
	.uleb128 .Ltmp80-.Lfunc_begin3          # >> Call Site 1 <<
	.uleb128 .Ltmp87-.Ltmp80                #   Call between .Ltmp80 and .Ltmp87
	.uleb128 .Ltmp88-.Lfunc_begin3          #     jumps to .Ltmp88
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp87-.Lfunc_begin3          # >> Call Site 2 <<
	.uleb128 .Lfunc_end6-.Ltmp87            #   Call between .Ltmp87 and .Lfunc_end6
	.byte	0                               #     has no landing pad
	.byte	0                               #   On action: cleanup
.Lcst_end3:
	.p2align	2, 0x0
                                        # -- End function
	.section	.text._ZNSt8__detail9_Map_baseINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS6_P6TagObjESaISB_ENS_10_Select1stESt8equal_toIS6_ESt4hashIS6_ENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixERS8_,"axG",@progbits,_ZNSt8__detail9_Map_baseINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS6_P6TagObjESaISB_ENS_10_Select1stESt8equal_toIS6_ESt4hashIS6_ENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixERS8_,comdat
	.weak	_ZNSt8__detail9_Map_baseINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS6_P6TagObjESaISB_ENS_10_Select1stESt8equal_toIS6_ESt4hashIS6_ENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixERS8_ # -- Begin function _ZNSt8__detail9_Map_baseINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS6_P6TagObjESaISB_ENS_10_Select1stESt8equal_toIS6_ESt4hashIS6_ENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixERS8_
	.p2align	4, 0x90
	.type	_ZNSt8__detail9_Map_baseINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS6_P6TagObjESaISB_ENS_10_Select1stESt8equal_toIS6_ESt4hashIS6_ENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixERS8_,@function
_ZNSt8__detail9_Map_baseINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS6_P6TagObjESaISB_ENS_10_Select1stESt8equal_toIS6_ESt4hashIS6_ENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixERS8_: # 
.Lfunc_begin4:
	.cfi_startproc
	.cfi_personality 155, DW.ref.__gxx_personality_v0
	.cfi_lsda 27, .Lexception4
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%r15
	.cfi_def_cfa_offset 24
	pushq	%r14
	.cfi_def_cfa_offset 32
	pushq	%r13
	.cfi_def_cfa_offset 40
	pushq	%r12
	.cfi_def_cfa_offset 48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	subq	$56, %rsp
	.cfi_def_cfa_offset 112
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	.cfi_offset %rbp, -16
	movq	%rsi, %r15
	movq	%rdi, %rbx
	movq	(%rsi), %rdi
	movq	8(%rsi), %rsi
.Ltmp89:
	movl	$3339675911, %edx               # imm = 0xC70F6907
	callq	_ZSt11_Hash_bytesPKvmm@PLT
.Ltmp90:
# %bb.1:
	movq	%rax, %r14
	movq	%rbx, 16(%rsp)                  # 8-byte Spill
	movq	8(%rbx), %rbx
	orq	%rbx, %rax
	shrq	$32, %rax
	movq	%r15, 32(%rsp)                  # 8-byte Spill
	je	.LBB7_3
# %bb.2:
	movq	%r14, %rax
	xorl	%edx, %edx
	divq	%rbx
	movq	%rdx, %r15
	jmp	.LBB7_4
.LBB7_3:
	movl	%r14d, %eax
	xorl	%edx, %edx
	divl	%ebx
	movl	%edx, %r15d
.LBB7_4:
	movq	16(%rsp), %rax                  # 8-byte Reload
	movq	(%rax), %rax
	movq	(%rax,%r15,8), %r13
	testq	%r13, %r13
	je	.LBB7_35
# %bb.5:
	movq	(%r13), %rbp
	movq	32(%rsp), %rax                  # 8-byte Reload
	movq	8(%rax), %r12
	movq	48(%rbp), %rcx
	testq	%r12, %r12
	je	.LBB7_22
# %bb.6:
	movq	(%rax), %rax
	movq	%rax, 8(%rsp)                   # 8-byte Spill
	jmp	.LBB7_8
	.p2align	4, 0x90
.LBB7_20:                               #   in Loop: Header=BB7_8 Depth=1
	movl	%ecx, %eax
	xorl	%edx, %edx
	divl	%ebx
                                        # kill: def $edx killed $edx def $rdx
	cmpq	%r15, %rdx
	jne	.LBB7_35
.LBB7_8:                                # =>This Inner Loop Header: Depth=1
	cmpq	%r14, %rcx
	jne	.LBB7_11
# %bb.9:                                #   in Loop: Header=BB7_8 Depth=1
	cmpq	16(%rbp), %r12
	jne	.LBB7_11
# %bb.10:                               #   in Loop: Header=BB7_8 Depth=1
	movq	8(%rbp), %rsi
	movq	8(%rsp), %rdi                   # 8-byte Reload
	movq	%r12, %rdx
	callq	bcmp@PLT
	movq	%r13, %rcx
	testl	%eax, %eax
	je	.LBB7_33
.LBB7_11:                               #   in Loop: Header=BB7_8 Depth=1
	movq	(%rbp), %r13
	testq	%r13, %r13
	je	.LBB7_35
# %bb.12:                               #   in Loop: Header=BB7_8 Depth=1
	movq	48(%r13), %rcx
	movq	%rcx, %rax
	orq	%rbx, %rax
	shrq	$32, %rax
	je	.LBB7_14
# %bb.13:                               #   in Loop: Header=BB7_8 Depth=1
	movq	%rcx, %rax
	xorl	%edx, %edx
	divq	%rbx
	cmpq	%r15, %rdx
	je	.LBB7_15
	jmp	.LBB7_35
	.p2align	4, 0x90
.LBB7_14:                               #   in Loop: Header=BB7_8 Depth=1
	movl	%ecx, %eax
	xorl	%edx, %edx
	divl	%ebx
                                        # kill: def $edx killed $edx def $rdx
	cmpq	%r15, %rdx
	jne	.LBB7_35
.LBB7_15:                               #   in Loop: Header=BB7_8 Depth=1
	cmpq	%r14, %rcx
	jne	.LBB7_18
# %bb.16:                               #   in Loop: Header=BB7_8 Depth=1
	cmpq	16(%r13), %r12
	jne	.LBB7_18
# %bb.17:                               #   in Loop: Header=BB7_8 Depth=1
	movq	8(%r13), %rsi
	movq	8(%rsp), %rdi                   # 8-byte Reload
	movq	%r12, %rdx
	callq	bcmp@PLT
	movq	%rbp, %rcx
	testl	%eax, %eax
	je	.LBB7_33
.LBB7_18:                               #   in Loop: Header=BB7_8 Depth=1
	movq	(%r13), %rbp
	testq	%rbp, %rbp
	je	.LBB7_35
# %bb.19:                               #   in Loop: Header=BB7_8 Depth=1
	movq	48(%rbp), %rcx
	movq	%rcx, %rax
	orq	%rbx, %rax
	shrq	$32, %rax
	je	.LBB7_20
# %bb.7:                                #   in Loop: Header=BB7_8 Depth=1
	movq	%rcx, %rax
	xorl	%edx, %edx
	divq	%rbx
	cmpq	%r15, %rdx
	je	.LBB7_8
	jmp	.LBB7_35
	.p2align	4, 0x90
.LBB7_32:                               #   in Loop: Header=BB7_22 Depth=1
	movl	%ecx, %eax
	xorl	%edx, %edx
	divl	%ebx
                                        # kill: def $edx killed $edx def $rdx
	cmpq	%r15, %rdx
	jne	.LBB7_35
.LBB7_22:                               # =>This Inner Loop Header: Depth=1
	cmpq	%r14, %rcx
	jne	.LBB7_24
# %bb.23:                               #   in Loop: Header=BB7_22 Depth=1
	cmpq	$0, 16(%rbp)
	movq	%r13, %rcx
	je	.LBB7_33
.LBB7_24:                               #   in Loop: Header=BB7_22 Depth=1
	movq	(%rbp), %r13
	testq	%r13, %r13
	je	.LBB7_35
# %bb.25:                               #   in Loop: Header=BB7_22 Depth=1
	movq	48(%r13), %rcx
	movq	%rcx, %rax
	orq	%rbx, %rax
	shrq	$32, %rax
	je	.LBB7_27
# %bb.26:                               #   in Loop: Header=BB7_22 Depth=1
	movq	%rcx, %rax
	xorl	%edx, %edx
	divq	%rbx
	cmpq	%r15, %rdx
	je	.LBB7_28
	jmp	.LBB7_35
	.p2align	4, 0x90
.LBB7_27:                               #   in Loop: Header=BB7_22 Depth=1
	movl	%ecx, %eax
	xorl	%edx, %edx
	divl	%ebx
                                        # kill: def $edx killed $edx def $rdx
	cmpq	%r15, %rdx
	jne	.LBB7_35
.LBB7_28:                               #   in Loop: Header=BB7_22 Depth=1
	cmpq	%r14, %rcx
	jne	.LBB7_30
# %bb.29:                               #   in Loop: Header=BB7_22 Depth=1
	cmpq	$0, 16(%r13)
	movq	%rbp, %rcx
	je	.LBB7_33
.LBB7_30:                               #   in Loop: Header=BB7_22 Depth=1
	movq	(%r13), %rbp
	testq	%rbp, %rbp
	je	.LBB7_35
# %bb.31:                               #   in Loop: Header=BB7_22 Depth=1
	movq	48(%rbp), %rcx
	movq	%rcx, %rax
	orq	%rbx, %rax
	shrq	$32, %rax
	je	.LBB7_32
# %bb.21:                               #   in Loop: Header=BB7_22 Depth=1
	movq	%rcx, %rax
	xorl	%edx, %edx
	divq	%rbx
	cmpq	%r15, %rdx
	je	.LBB7_22
	jmp	.LBB7_35
.LBB7_33:
	movq	(%rcx), %rcx
	testq	%rcx, %rcx
	je	.LBB7_35
# %bb.34:
	addq	$40, %rcx
	jmp	.LBB7_73
.LBB7_35:
	movq	16(%rsp), %rax                  # 8-byte Reload
	movq	%rax, 40(%rsp)
	movl	$56, %edi
	callq	_Znwm@PLT
	movq	%rax, %r12
	movq	$0, (%rax)
	leaq	24(%rax), %rbp
	movq	%rbp, 8(%rax)
	movq	32(%rsp), %rax                  # 8-byte Reload
	movq	(%rax), %rcx
	movq	%rcx, 8(%rsp)                   # 8-byte Spill
	movq	8(%rax), %rbx
	movq	%rbx, 24(%rsp)
	cmpq	$16, %rbx
	jb	.LBB7_38
# %bb.36:
.Ltmp92:
	leaq	8(%r12), %r13
	leaq	24(%rsp), %rsi
	movq	%r13, %rdi
	xorl	%edx, %edx
	callq	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm@PLT
.Ltmp93:
# %bb.37:
	movq	%rax, (%r13)
	movq	24(%rsp), %rcx
	movq	%rcx, (%rbp)
	movq	%rax, %rbp
.LBB7_38:
	testq	%rbx, %rbx
	je	.LBB7_42
# %bb.39:
	cmpq	$1, %rbx
	jne	.LBB7_41
# %bb.40:
	movq	8(%rsp), %rax                   # 8-byte Reload
	movzbl	(%rax), %eax
	movb	%al, (%rbp)
	jmp	.LBB7_42
.LBB7_41:
	movq	%rbp, %rdi
	movq	8(%rsp), %rsi                   # 8-byte Reload
	movq	%rbx, %rdx
	callq	_intel_fast_memcpy@PLT
.LBB7_42:
	movq	24(%rsp), %rax
	movq	%rax, 16(%r12)
	movq	8(%r12), %rcx
	movb	$0, (%rcx,%rax)
	movq	$0, 40(%r12)
	movq	%r12, 48(%rsp)
	movq	16(%rsp), %rbx                  # 8-byte Reload
	leaq	32(%rbx), %rdi
	movq	40(%rbx), %r13
	movq	8(%rbx), %rsi
	movq	24(%rbx), %rdx
.Ltmp101:
	movl	$1, %ecx
	callq	_ZNKSt8__detail20_Prime_rehash_policy14_M_need_rehashEmmm@PLT
.Ltmp102:
# %bb.43:
	testb	$1, %al
	jne	.LBB7_45
# %bb.44:
	movq	(%rbx), %r13
	jmp	.LBB7_64
.LBB7_45:
	movq	%rdx, %rbp
	cmpq	$1, %rdx
	je	.LBB7_58
# %bb.46:
	movq	%r13, %r15
	movq	%rbp, %rax
	shrq	$60, %rax
	jne	.LBB7_74
# %bb.47:
	leaq	(,%rbp,8), %rbx
.Ltmp104:
	movq	%rbx, %rdi
	callq	_Znwm@PLT
.Ltmp105:
# %bb.48:
	movq	%rax, %r13
	movq	%rax, %rdi
	xorl	%esi, %esi
	movq	%rbx, %rdx
	callq	_intel_fast_memset@PLT
	movq	16(%rsp), %rbx                  # 8-byte Reload
	movq	16(%rbx), %rsi
	movq	$0, 16(%rbx)
	testq	%rsi, %rsi
	je	.LBB7_59
.LBB7_49:
	leaq	16(%rbx), %rcx
	xorl	%r8d, %r8d
	jmp	.LBB7_53
	.p2align	4, 0x90
.LBB7_55:                               #   in Loop: Header=BB7_53 Depth=1
                                        # kill: def $eax killed $eax killed $rax
	xorl	%edx, %edx
	divl	%ebp
                                        # kill: def $edx killed $edx def $rdx
	movq	(%r13,%rdx,8), %rax
	testq	%rax, %rax
	je	.LBB7_56
.LBB7_50:                               #   in Loop: Header=BB7_53 Depth=1
	movq	(%rax), %rax
	movq	%rax, (%rsi)
	movq	(%r13,%rdx,8), %rax
	movq	%r8, %rdx
.LBB7_51:                               #   in Loop: Header=BB7_53 Depth=1
	movq	%rsi, (%rax)
.LBB7_52:                               #   in Loop: Header=BB7_53 Depth=1
	movq	%rdi, %rsi
	movq	%rdx, %r8
	testq	%rdi, %rdi
	je	.LBB7_59
.LBB7_53:                               # =>This Inner Loop Header: Depth=1
	movq	(%rsi), %rdi
	movq	48(%rsi), %rax
	movq	%rax, %rdx
	orq	%rbp, %rdx
	shrq	$32, %rdx
	je	.LBB7_55
# %bb.54:                               #   in Loop: Header=BB7_53 Depth=1
	xorl	%edx, %edx
	divq	%rbp
	movq	(%r13,%rdx,8), %rax
	testq	%rax, %rax
	jne	.LBB7_50
.LBB7_56:                               #   in Loop: Header=BB7_53 Depth=1
	movq	(%rcx), %rax
	movq	%rax, (%rsi)
	movq	%rsi, (%rcx)
	movq	%rcx, (%r13,%rdx,8)
	cmpq	$0, (%rsi)
	je	.LBB7_52
# %bb.57:                               #   in Loop: Header=BB7_53 Depth=1
	leaq	(,%r8,8), %rax
	addq	%r13, %rax
	jmp	.LBB7_51
.LBB7_58:
	leaq	48(%rbx), %r13
	movq	$0, 48(%rbx)
	movq	16(%rbx), %rsi
	movq	$0, 16(%rbx)
	testq	%rsi, %rsi
	jne	.LBB7_49
.LBB7_59:
	movq	(%rbx), %rdi
	leaq	48(%rbx), %rax
	cmpq	%rdi, %rax
	je	.LBB7_61
# %bb.60:
	callq	_ZdlPv@PLT
.LBB7_61:
	movq	%rbp, 8(%rbx)
	movq	%r13, (%rbx)
	movq	%r14, %rax
	orq	%rbp, %rax
	shrq	$32, %rax
	je	.LBB7_63
# %bb.62:
	movq	%r14, %rax
	xorl	%edx, %edx
	divq	%rbp
	movq	%rdx, %r15
	jmp	.LBB7_64
.LBB7_63:
	movl	%r14d, %eax
	xorl	%edx, %edx
	divl	%ebp
	movl	%edx, %r15d
.LBB7_64:
	movq	%r12, %rcx
	addq	$40, %rcx
	movq	%r14, 48(%r12)
	movq	(%r13,%r15,8), %rax
	testq	%rax, %rax
	je	.LBB7_66
# %bb.65:
	movq	(%rax), %rax
	movq	%rax, (%r12)
	movq	(%r13,%r15,8), %rax
	movq	%r12, (%rax)
	jmp	.LBB7_72
.LBB7_66:
	leaq	16(%rbx), %rsi
	movq	16(%rbx), %rax
	movq	%rax, (%r12)
	movq	%r12, 16(%rbx)
	testq	%rax, %rax
	je	.LBB7_71
# %bb.67:
	movq	8(%rbx), %rdi
	movq	48(%rax), %rax
	movq	%rax, %rdx
	orq	%rdi, %rdx
	shrq	$32, %rdx
	je	.LBB7_69
# %bb.68:
	xorl	%edx, %edx
	divq	%rdi
	jmp	.LBB7_70
.LBB7_69:
                                        # kill: def $eax killed $eax killed $rax
	xorl	%edx, %edx
	divl	%edi
                                        # kill: def $edx killed $edx def $rdx
.LBB7_70:
	movq	%r12, (%r13,%rdx,8)
.LBB7_71:
	movq	%rsi, (%r13,%r15,8)
.LBB7_72:
	incq	24(%rbx)
.LBB7_73:
	movq	%rcx, %rax
	addq	$56, %rsp
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%r12
	.cfi_def_cfa_offset 40
	popq	%r13
	.cfi_def_cfa_offset 32
	popq	%r14
	.cfi_def_cfa_offset 24
	popq	%r15
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	retq
.LBB7_74:
	.cfi_def_cfa_offset 112
	shrq	$61, %rbp
	je	.LBB7_77
# %bb.75:
.Ltmp108:
	callq	_ZSt28__throw_bad_array_new_lengthv@PLT
.Ltmp109:
# %bb.76:
.LBB7_77:
.Ltmp106:
	callq	_ZSt17__throw_bad_allocv@PLT
.Ltmp107:
# %bb.78:
.LBB7_79:
.Ltmp94:
	movq	%rax, %rdi
	callq	__cxa_begin_catch@PLT
	movq	%r12, %rdi
	callq	_ZdlPv@PLT
.Ltmp95:
	callq	__cxa_rethrow@PLT
.Ltmp96:
# %bb.80:
.LBB7_81:
.Ltmp97:
	movq	%rax, %rbx
.Ltmp98:
	callq	__cxa_end_catch@PLT
.Ltmp99:
# %bb.82:
	movq	%rbx, %rdi
	callq	_Unwind_Resume@PLT
.LBB7_83:
.Ltmp100:
	movq	%rax, %rdi
	callq	__clang_call_terminate
.LBB7_84:
.Ltmp103:
	movq	%rax, %rbx
	leaq	40(%rsp), %rdi
	callq	_ZNSt10_HashtableINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS5_P6TagObjESaISA_ENSt8__detail10_Select1stESt8equal_toIS5_ESt4hashIS5_ENSC_18_Mod_range_hashingENSC_20_Default_ranged_hashENSC_20_Prime_rehash_policyENSC_17_Hashtable_traitsILb1ELb0ELb1EEEE12_Scoped_nodeD2Ev
	movq	%rbx, %rdi
	callq	_Unwind_Resume@PLT
.LBB7_85:
.Ltmp91:
	movq	%rax, %rdi
	callq	__clang_call_terminate
.LBB7_86:
.Ltmp110:
	movq	%rax, %rdi
	callq	__cxa_begin_catch@PLT
	movq	16(%rsp), %rax                  # 8-byte Reload
	movq	%r15, 40(%rax)
.Ltmp111:
	callq	__cxa_rethrow@PLT
.Ltmp112:
# %bb.87:
.LBB7_88:
.Ltmp113:
	movq	%rax, %rbx
.Ltmp114:
	callq	__cxa_end_catch@PLT
.Ltmp115:
# %bb.89:
	leaq	40(%rsp), %rdi
	callq	_ZNSt10_HashtableINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS5_P6TagObjESaISA_ENSt8__detail10_Select1stESt8equal_toIS5_ESt4hashIS5_ENSC_18_Mod_range_hashingENSC_20_Default_ranged_hashENSC_20_Prime_rehash_policyENSC_17_Hashtable_traitsILb1ELb0ELb1EEEE12_Scoped_nodeD2Ev
	movq	%rbx, %rdi
	callq	_Unwind_Resume@PLT
.LBB7_90:
.Ltmp116:
	movq	%rax, %rdi
	callq	__clang_call_terminate
.Lfunc_end7:
	.size	_ZNSt8__detail9_Map_baseINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS6_P6TagObjESaISB_ENS_10_Select1stESt8equal_toIS6_ESt4hashIS6_ENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixERS8_, .Lfunc_end7-_ZNSt8__detail9_Map_baseINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS6_P6TagObjESaISB_ENS_10_Select1stESt8equal_toIS6_ESt4hashIS6_ENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixERS8_
	.cfi_endproc
	.section	.gcc_except_table._ZNSt8__detail9_Map_baseINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS6_P6TagObjESaISB_ENS_10_Select1stESt8equal_toIS6_ESt4hashIS6_ENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixERS8_,"aG",@progbits,_ZNSt8__detail9_Map_baseINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS6_P6TagObjESaISB_ENS_10_Select1stESt8equal_toIS6_ESt4hashIS6_ENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixERS8_,comdat
	.p2align	2, 0x0
GCC_except_table7:
.Lexception4:
	.byte	255                             # @LPStart Encoding = omit
	.byte	155                             # @TType Encoding = indirect pcrel sdata4
	.uleb128 .Lttbase0-.Lttbaseref0
.Lttbaseref0:
	.byte	1                               # Call site Encoding = uleb128
	.uleb128 .Lcst_end4-.Lcst_begin4
.Lcst_begin4:
	.uleb128 .Ltmp89-.Lfunc_begin4          # >> Call Site 1 <<
	.uleb128 .Ltmp90-.Ltmp89                #   Call between .Ltmp89 and .Ltmp90
	.uleb128 .Ltmp91-.Lfunc_begin4          #     jumps to .Ltmp91
	.byte	1                               #   On action: 1
	.uleb128 .Ltmp90-.Lfunc_begin4          # >> Call Site 2 <<
	.uleb128 .Ltmp92-.Ltmp90                #   Call between .Ltmp90 and .Ltmp92
	.byte	0                               #     has no landing pad
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp92-.Lfunc_begin4          # >> Call Site 3 <<
	.uleb128 .Ltmp93-.Ltmp92                #   Call between .Ltmp92 and .Ltmp93
	.uleb128 .Ltmp94-.Lfunc_begin4          #     jumps to .Ltmp94
	.byte	1                               #   On action: 1
	.uleb128 .Ltmp93-.Lfunc_begin4          # >> Call Site 4 <<
	.uleb128 .Ltmp101-.Ltmp93               #   Call between .Ltmp93 and .Ltmp101
	.byte	0                               #     has no landing pad
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp101-.Lfunc_begin4         # >> Call Site 5 <<
	.uleb128 .Ltmp102-.Ltmp101              #   Call between .Ltmp101 and .Ltmp102
	.uleb128 .Ltmp103-.Lfunc_begin4         #     jumps to .Ltmp103
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp104-.Lfunc_begin4         # >> Call Site 6 <<
	.uleb128 .Ltmp105-.Ltmp104              #   Call between .Ltmp104 and .Ltmp105
	.uleb128 .Ltmp110-.Lfunc_begin4         #     jumps to .Ltmp110
	.byte	1                               #   On action: 1
	.uleb128 .Ltmp105-.Lfunc_begin4         # >> Call Site 7 <<
	.uleb128 .Ltmp108-.Ltmp105              #   Call between .Ltmp105 and .Ltmp108
	.byte	0                               #     has no landing pad
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp108-.Lfunc_begin4         # >> Call Site 8 <<
	.uleb128 .Ltmp107-.Ltmp108              #   Call between .Ltmp108 and .Ltmp107
	.uleb128 .Ltmp110-.Lfunc_begin4         #     jumps to .Ltmp110
	.byte	1                               #   On action: 1
	.uleb128 .Ltmp107-.Lfunc_begin4         # >> Call Site 9 <<
	.uleb128 .Ltmp95-.Ltmp107               #   Call between .Ltmp107 and .Ltmp95
	.byte	0                               #     has no landing pad
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp95-.Lfunc_begin4          # >> Call Site 10 <<
	.uleb128 .Ltmp96-.Ltmp95                #   Call between .Ltmp95 and .Ltmp96
	.uleb128 .Ltmp97-.Lfunc_begin4          #     jumps to .Ltmp97
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp98-.Lfunc_begin4          # >> Call Site 11 <<
	.uleb128 .Ltmp99-.Ltmp98                #   Call between .Ltmp98 and .Ltmp99
	.uleb128 .Ltmp100-.Lfunc_begin4         #     jumps to .Ltmp100
	.byte	1                               #   On action: 1
	.uleb128 .Ltmp99-.Lfunc_begin4          # >> Call Site 12 <<
	.uleb128 .Ltmp111-.Ltmp99               #   Call between .Ltmp99 and .Ltmp111
	.byte	0                               #     has no landing pad
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp111-.Lfunc_begin4         # >> Call Site 13 <<
	.uleb128 .Ltmp112-.Ltmp111              #   Call between .Ltmp111 and .Ltmp112
	.uleb128 .Ltmp113-.Lfunc_begin4         #     jumps to .Ltmp113
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp114-.Lfunc_begin4         # >> Call Site 14 <<
	.uleb128 .Ltmp115-.Ltmp114              #   Call between .Ltmp114 and .Ltmp115
	.uleb128 .Ltmp116-.Lfunc_begin4         #     jumps to .Ltmp116
	.byte	1                               #   On action: 1
	.uleb128 .Ltmp115-.Lfunc_begin4         # >> Call Site 15 <<
	.uleb128 .Lfunc_end7-.Ltmp115           #   Call between .Ltmp115 and .Lfunc_end7
	.byte	0                               #     has no landing pad
	.byte	0                               #   On action: cleanup
.Lcst_end4:
	.byte	1                               # >> Action Record 1 <<
                                        #   Catch TypeInfo 1
	.byte	0                               #   No further actions
	.p2align	2, 0x0
                                        # >> Catch TypeInfos <<
	.long	0                               # TypeInfo 1
.Lttbase0:
	.p2align	2, 0x0
                                        # -- End function
	.section	.text._ZNSt10_HashtableINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS5_P6TagObjESaISA_ENSt8__detail10_Select1stESt8equal_toIS5_ESt4hashIS5_ENSC_18_Mod_range_hashingENSC_20_Default_ranged_hashENSC_20_Prime_rehash_policyENSC_17_Hashtable_traitsILb1ELb0ELb1EEEE12_Scoped_nodeD2Ev,"axG",@progbits,_ZNSt10_HashtableINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS5_P6TagObjESaISA_ENSt8__detail10_Select1stESt8equal_toIS5_ESt4hashIS5_ENSC_18_Mod_range_hashingENSC_20_Default_ranged_hashENSC_20_Prime_rehash_policyENSC_17_Hashtable_traitsILb1ELb0ELb1EEEE12_Scoped_nodeD2Ev,comdat
	.weak	_ZNSt10_HashtableINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS5_P6TagObjESaISA_ENSt8__detail10_Select1stESt8equal_toIS5_ESt4hashIS5_ENSC_18_Mod_range_hashingENSC_20_Default_ranged_hashENSC_20_Prime_rehash_policyENSC_17_Hashtable_traitsILb1ELb0ELb1EEEE12_Scoped_nodeD2Ev # -- Begin function _ZNSt10_HashtableINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS5_P6TagObjESaISA_ENSt8__detail10_Select1stESt8equal_toIS5_ESt4hashIS5_ENSC_18_Mod_range_hashingENSC_20_Default_ranged_hashENSC_20_Prime_rehash_policyENSC_17_Hashtable_traitsILb1ELb0ELb1EEEE12_Scoped_nodeD2Ev
	.p2align	4, 0x90
	.type	_ZNSt10_HashtableINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS5_P6TagObjESaISA_ENSt8__detail10_Select1stESt8equal_toIS5_ESt4hashIS5_ENSC_18_Mod_range_hashingENSC_20_Default_ranged_hashENSC_20_Prime_rehash_policyENSC_17_Hashtable_traitsILb1ELb0ELb1EEEE12_Scoped_nodeD2Ev,@function
_ZNSt10_HashtableINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS5_P6TagObjESaISA_ENSt8__detail10_Select1stESt8equal_toIS5_ESt4hashIS5_ENSC_18_Mod_range_hashingENSC_20_Default_ranged_hashENSC_20_Prime_rehash_policyENSC_17_Hashtable_traitsILb1ELb0ELb1EEEE12_Scoped_nodeD2Ev: # 
	.cfi_startproc
# %bb.0:
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset %rbx, -16
	movq	8(%rdi), %rbx
	testq	%rbx, %rbx
	je	.LBB8_4
# %bb.1:
	movq	8(%rbx), %rdi
	leaq	24(%rbx), %rax
	cmpq	%rax, %rdi
	je	.LBB8_3
# %bb.2:
	callq	_ZdlPv@PLT
.LBB8_3:
	movq	%rbx, %rdi
	popq	%rbx
	.cfi_def_cfa_offset 8
	jmp	_ZdlPv@PLT                      # TAILCALL
.LBB8_4:
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end8:
	.size	_ZNSt10_HashtableINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS5_P6TagObjESaISA_ENSt8__detail10_Select1stESt8equal_toIS5_ESt4hashIS5_ENSC_18_Mod_range_hashingENSC_20_Default_ranged_hashENSC_20_Prime_rehash_policyENSC_17_Hashtable_traitsILb1ELb0ELb1EEEE12_Scoped_nodeD2Ev, .Lfunc_end8-_ZNSt10_HashtableINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS5_P6TagObjESaISA_ENSt8__detail10_Select1stESt8equal_toIS5_ESt4hashIS5_ENSC_18_Mod_range_hashingENSC_20_Default_ranged_hashENSC_20_Prime_rehash_policyENSC_17_Hashtable_traitsILb1ELb0ELb1EEEE12_Scoped_nodeD2Ev
	.cfi_endproc
                                        # -- End function
	.section	.text._ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEE2atERSD_,"axG",@progbits,_ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEE2atERSD_,comdat
	.weak	_ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEE2atERSD_ # -- Begin function _ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEE2atERSD_
	.p2align	4, 0x90
	.type	_ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEE2atERSD_,@function
_ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEE2atERSD_: # 
.Lfunc_begin5:
	.cfi_startproc
	.cfi_personality 155, DW.ref.__gxx_personality_v0
	.cfi_lsda 27, .Lexception5
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%r15
	.cfi_def_cfa_offset 24
	pushq	%r14
	.cfi_def_cfa_offset 32
	pushq	%r13
	.cfi_def_cfa_offset 40
	pushq	%r12
	.cfi_def_cfa_offset 48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	pushq	%rax
	.cfi_def_cfa_offset 64
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	.cfi_offset %rbp, -16
	movq	%rdi, %r15
	movq	(%rsi), %rdi
	movq	%rsi, (%rsp)                    # 8-byte Spill
	movq	8(%rsi), %rsi
.Ltmp117:
	movl	$3339675911, %edx               # imm = 0xC70F6907
	callq	_ZSt11_Hash_bytesPKvmm@PLT
.Ltmp118:
# %bb.1:
	movq	%rax, %rbx
	movq	8(%r15), %r13
	orq	%r13, %rax
	shrq	$32, %rax
	je	.LBB9_2
# %bb.3:
	movq	%rbx, %rax
	xorl	%edx, %edx
	divq	%r13
	movq	%rdx, %r14
	movq	(%r15), %rax
	movq	(%rax,%r14,8), %rbp
	testq	%rbp, %rbp
	jne	.LBB9_5
	jmp	.LBB9_39
.LBB9_2:
	movl	%ebx, %eax
	xorl	%edx, %edx
	divl	%r13d
	movl	%edx, %r14d
	movq	(%r15), %rax
	movq	(%rax,%r14,8), %rbp
	testq	%rbp, %rbp
	je	.LBB9_39
.LBB9_5:
	movq	(%rbp), %r12
	movq	(%rsp), %rax                    # 8-byte Reload
	movq	8(%rax), %r15
	movq	48(%r12), %rcx
	testq	%r15, %r15
	je	.LBB9_25
# %bb.6:
	movq	(%rax), %rax
	movq	%rax, (%rsp)                    # 8-byte Spill
	jmp	.LBB9_7
	.p2align	4, 0x90
.LBB9_23:                               #   in Loop: Header=BB9_7 Depth=1
	movq	%rcx, %rax
	xorl	%edx, %edx
	divq	%r13
	cmpq	%r14, %rdx
	jne	.LBB9_39
.LBB9_7:                                # =>This Inner Loop Header: Depth=1
	cmpq	%rbx, %rcx
	jne	.LBB9_12
# %bb.8:                                #   in Loop: Header=BB9_7 Depth=1
	cmpq	16(%r12), %r15
	jne	.LBB9_12
# %bb.9:                                #   in Loop: Header=BB9_7 Depth=1
	movq	8(%r12), %rsi
	movq	(%rsp), %rdi                    # 8-byte Reload
	movq	%r15, %rdx
	callq	bcmp@PLT
	movq	%rbp, %rcx
	testl	%eax, %eax
	je	.LBB9_10
.LBB9_12:                               #   in Loop: Header=BB9_7 Depth=1
	movq	(%r12), %rbp
	testq	%rbp, %rbp
	je	.LBB9_39
# %bb.13:                               #   in Loop: Header=BB9_7 Depth=1
	movq	48(%rbp), %rcx
	movq	%rcx, %rax
	orq	%r13, %rax
	shrq	$32, %rax
	je	.LBB9_14
# %bb.15:                               #   in Loop: Header=BB9_7 Depth=1
	movq	%rcx, %rax
	xorl	%edx, %edx
	divq	%r13
	cmpq	%r14, %rdx
	je	.LBB9_17
	jmp	.LBB9_39
	.p2align	4, 0x90
.LBB9_14:                               #   in Loop: Header=BB9_7 Depth=1
	movl	%ecx, %eax
	xorl	%edx, %edx
	divl	%r13d
                                        # kill: def $edx killed $edx def $rdx
	cmpq	%r14, %rdx
	jne	.LBB9_39
.LBB9_17:                               #   in Loop: Header=BB9_7 Depth=1
	cmpq	%rbx, %rcx
	jne	.LBB9_20
# %bb.18:                               #   in Loop: Header=BB9_7 Depth=1
	cmpq	16(%rbp), %r15
	jne	.LBB9_20
# %bb.19:                               #   in Loop: Header=BB9_7 Depth=1
	movq	8(%rbp), %rsi
	movq	(%rsp), %rdi                    # 8-byte Reload
	movq	%r15, %rdx
	callq	bcmp@PLT
	movq	%r12, %rcx
	testl	%eax, %eax
	je	.LBB9_10
.LBB9_20:                               #   in Loop: Header=BB9_7 Depth=1
	movq	(%rbp), %r12
	testq	%r12, %r12
	je	.LBB9_39
# %bb.21:                               #   in Loop: Header=BB9_7 Depth=1
	movq	48(%r12), %rcx
	movq	%rcx, %rax
	orq	%r13, %rax
	shrq	$32, %rax
	jne	.LBB9_23
# %bb.22:                               #   in Loop: Header=BB9_7 Depth=1
	movl	%ecx, %eax
	xorl	%edx, %edx
	divl	%r13d
                                        # kill: def $edx killed $edx def $rdx
	cmpq	%r14, %rdx
	je	.LBB9_7
	jmp	.LBB9_39
	.p2align	4, 0x90
.LBB9_37:                               #   in Loop: Header=BB9_25 Depth=1
	movq	%rcx, %rax
	xorl	%edx, %edx
	divq	%r13
	cmpq	%r14, %rdx
	jne	.LBB9_39
.LBB9_25:                               # =>This Inner Loop Header: Depth=1
	cmpq	%rbx, %rcx
	jne	.LBB9_27
# %bb.26:                               #   in Loop: Header=BB9_25 Depth=1
	cmpq	$0, 16(%r12)
	movq	%rbp, %rcx
	je	.LBB9_10
.LBB9_27:                               #   in Loop: Header=BB9_25 Depth=1
	movq	(%r12), %rbp
	testq	%rbp, %rbp
	je	.LBB9_39
# %bb.28:                               #   in Loop: Header=BB9_25 Depth=1
	movq	48(%rbp), %rcx
	movq	%rcx, %rax
	orq	%r13, %rax
	shrq	$32, %rax
	je	.LBB9_29
# %bb.30:                               #   in Loop: Header=BB9_25 Depth=1
	movq	%rcx, %rax
	xorl	%edx, %edx
	divq	%r13
	cmpq	%r14, %rdx
	je	.LBB9_32
	jmp	.LBB9_39
	.p2align	4, 0x90
.LBB9_29:                               #   in Loop: Header=BB9_25 Depth=1
	movl	%ecx, %eax
	xorl	%edx, %edx
	divl	%r13d
                                        # kill: def $edx killed $edx def $rdx
	cmpq	%r14, %rdx
	jne	.LBB9_39
.LBB9_32:                               #   in Loop: Header=BB9_25 Depth=1
	cmpq	%rbx, %rcx
	jne	.LBB9_34
# %bb.33:                               #   in Loop: Header=BB9_25 Depth=1
	cmpq	$0, 16(%rbp)
	movq	%r12, %rcx
	je	.LBB9_10
.LBB9_34:                               #   in Loop: Header=BB9_25 Depth=1
	movq	(%rbp), %r12
	testq	%r12, %r12
	je	.LBB9_39
# %bb.35:                               #   in Loop: Header=BB9_25 Depth=1
	movq	48(%r12), %rcx
	movq	%rcx, %rax
	orq	%r13, %rax
	shrq	$32, %rax
	jne	.LBB9_37
# %bb.36:                               #   in Loop: Header=BB9_25 Depth=1
	movl	%ecx, %eax
	xorl	%edx, %edx
	divl	%r13d
                                        # kill: def $edx killed $edx def $rdx
	cmpq	%r14, %rdx
	je	.LBB9_25
.LBB9_39:
	leaq	.L.str.16(%rip), %rdi
	callq	_ZSt20__throw_out_of_rangePKc@PLT
.LBB9_10:
	movq	(%rcx), %rax
	testq	%rax, %rax
	je	.LBB9_39
# %bb.11:
	addq	$40, %rax
	addq	$8, %rsp
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%r12
	.cfi_def_cfa_offset 40
	popq	%r13
	.cfi_def_cfa_offset 32
	popq	%r14
	.cfi_def_cfa_offset 24
	popq	%r15
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	retq
.LBB9_40:
	.cfi_def_cfa_offset 64
.Ltmp119:
	movq	%rax, %rdi
	callq	__clang_call_terminate
.Lfunc_end9:
	.size	_ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEE2atERSD_, .Lfunc_end9-_ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEE2atERSD_
	.cfi_endproc
	.section	.gcc_except_table._ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEE2atERSD_,"aG",@progbits,_ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEE2atERSD_,comdat
	.p2align	2, 0x0
GCC_except_table9:
.Lexception5:
	.byte	255                             # @LPStart Encoding = omit
	.byte	155                             # @TType Encoding = indirect pcrel sdata4
	.uleb128 .Lttbase1-.Lttbaseref1
.Lttbaseref1:
	.byte	1                               # Call site Encoding = uleb128
	.uleb128 .Lcst_end5-.Lcst_begin5
.Lcst_begin5:
	.uleb128 .Ltmp117-.Lfunc_begin5         # >> Call Site 1 <<
	.uleb128 .Ltmp118-.Ltmp117              #   Call between .Ltmp117 and .Ltmp118
	.uleb128 .Ltmp119-.Lfunc_begin5         #     jumps to .Ltmp119
	.byte	1                               #   On action: 1
	.uleb128 .Ltmp118-.Lfunc_begin5         # >> Call Site 2 <<
	.uleb128 .Lfunc_end9-.Ltmp118           #   Call between .Ltmp118 and .Lfunc_end9
	.byte	0                               #     has no landing pad
	.byte	0                               #   On action: cleanup
.Lcst_end5:
	.byte	1                               # >> Action Record 1 <<
                                        #   Catch TypeInfo 1
	.byte	0                               #   No further actions
	.p2align	2, 0x0
                                        # >> Catch TypeInfos <<
	.long	0                               # TypeInfo 1
.Lttbase1:
	.p2align	2, 0x0
                                        # -- End function
	.section	.rodata.cst16,"aM",@progbits,16
	.p2align	4, 0x0                          # -- Begin function _ZN6TagObj26prepareReportAndDumpToFileEv
.LCPI10_0:
	.long	1127219200                      # 0x43300000
	.long	1160773632                      # 0x45300000
	.long	0                               # 0x0
	.long	0                               # 0x0
.LCPI10_1:
	.quad	0x4330000000000000              #  4503599627370496
	.quad	0x4530000000000000              #  1.9342813113834067E+25
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3, 0x0
.LCPI10_2:
	.quad	0x3ff0000000000000              #  1
.LCPI10_3:
	.quad	4841369599423283200             # 0x4330000000000000
.LCPI10_4:
	.quad	4985484787499139072             # 0x4530000000000000
.LCPI10_5:
	.quad	0x4530000000100000              #  1.9342813118337666E+25
	.section	.text._ZN6TagObj26prepareReportAndDumpToFileEv,"axG",@progbits,_ZN6TagObj26prepareReportAndDumpToFileEv,comdat
	.weak	_ZN6TagObj26prepareReportAndDumpToFileEv
	.p2align	4, 0x90
	.type	_ZN6TagObj26prepareReportAndDumpToFileEv,@function
_ZN6TagObj26prepareReportAndDumpToFileEv: # 
.Lfunc_begin6:
	.cfi_startproc
	.cfi_personality 155, DW.ref.__gxx_personality_v0
	.cfi_lsda 27, .Lexception6
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%r15
	.cfi_def_cfa_offset 24
	pushq	%r14
	.cfi_def_cfa_offset 32
	pushq	%r13
	.cfi_def_cfa_offset 40
	pushq	%r12
	.cfi_def_cfa_offset 48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	subq	$632, %rsp                      # imm = 0x278
	.cfi_def_cfa_offset 688
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	.cfi_offset %rbp, -16
	movq	%rdi, %r14
	movq	%fs:40, %rax
	movq	%rax, 624(%rsp)
	movq	_ZSt4cout@GOTPCREL(%rip), %rdi
	movq	(%rdi), %rax
	movq	-24(%rax), %rax
	movq	$10, 16(%rdi,%rax)
	movq	(%r14), %rsi
	movq	8(%r14), %rdx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	leaq	.L.str.20(%rip), %rsi
	movl	$3, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	leaq	48(%rsp), %rbx
	movq	%rbx, %rdi
	callq	_ZNSt14basic_ofstreamIcSt11char_traitsIcEEC1Ev@PLT
.Ltmp120:
	leaq	.L.str.9(%rip), %rsi
	leaq	560(%rsp), %rdi
	movq	%r14, (%rsp)                    # 8-byte Spill
	movq	%r14, %rdx
	callq	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_RKS8_
.Ltmp121:
# %bb.1:
	movq	568(%rsp), %rax
	shrq	$2, %rax
	movabsq	$1152921504606846975, %rcx      # imm = 0xFFFFFFFFFFFFFFF
	cmpq	%rcx, %rax
	je	.LBB10_2
# %bb.5:
.Ltmp123:
	leaq	.L.str.10(%rip), %rsi
	leaq	560(%rsp), %rdi
	movl	$4, %edx
	callq	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_appendEPKcm@PLT
.Ltmp124:
# %bb.6:
	leaq	608(%rsp), %r15
	movq	%r15, 592(%rsp)
	movq	(%rax), %rdx
	movq	%rax, %rcx
	addq	$16, %rcx
	cmpq	%rcx, %rdx
	je	.LBB10_7
# %bb.8:
	movq	%rdx, 592(%rsp)
	movq	(%rcx), %rdx
	movq	%rdx, 608(%rsp)
	jmp	.LBB10_9
.LBB10_7:
	vmovupd	(%rdx), %xmm0
	vmovupd	%xmm0, (%r15)
.LBB10_9:
	movq	8(%rax), %rdx
	movq	%rdx, 600(%rsp)
	movq	%rcx, (%rax)
	movq	$0, 8(%rax)
	movb	$0, (%rcx)
	leaq	56(%rsp), %rdi
	movq	592(%rsp), %rsi
.Ltmp125:
	movl	$17, %edx
	callq	_ZNSt13basic_filebufIcSt11char_traitsIcEE4openEPKcSt13_Ios_Openmode@PLT
.Ltmp126:
# %bb.10:
	movq	48(%rsp), %rcx
	addq	-24(%rcx), %rbx
	xorl	%esi, %esi
	testq	%rax, %rax
	jne	.LBB10_12
# %bb.11:
	movl	32(%rbx), %esi
	orl	$4, %esi
.LBB10_12:
.Ltmp127:
	movq	%rbx, %rdi
	callq	_ZNSt9basic_iosIcSt11char_traitsIcEE5clearESt12_Ios_Iostate@PLT
.Ltmp128:
# %bb.13:
	movq	592(%rsp), %rdi
	cmpq	%r15, %rdi
	je	.LBB10_15
# %bb.14:
	callq	_ZdlPv@PLT
.LBB10_15:
	movq	560(%rsp), %rdi
	leaq	576(%rsp), %rax
	cmpq	%rax, %rdi
	je	.LBB10_17
# %bb.16:
	callq	_ZdlPv@PLT
.LBB10_17:
	movq	(%rsp), %rax                    # 8-byte Reload
	movq	48(%rax), %rbx
	cmpq	%rbx, 56(%rax)
	je	.LBB10_58
# %bb.18:
	xorl	%ebp, %ebp
	leaq	48(%rsp), %r12
	leaq	.L.str.13(%rip), %r13
	.p2align	4, 0x90
.LBB10_19:                              # =>This Inner Loop Header: Depth=1
	movq	(%rbx,%rbp,8), %rsi
.Ltmp130:
	movq	%r12, %rdi
	callq	_ZNSo9_M_insertImEERSoT_@PLT
.Ltmp131:
# %bb.20:                               #   in Loop: Header=BB10_19 Depth=1
.Ltmp132:
	movl	$1, %edx
	movq	%rax, %rdi
	movq	%r13, %rsi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp133:
# %bb.21:                               #   in Loop: Header=BB10_19 Depth=1
	incq	%rbp
	movq	(%rsp), %rax                    # 8-byte Reload
	movq	48(%rax), %rbx
	movq	56(%rax), %r14
	movq	%r14, %r15
	subq	%rbx, %r15
	movq	%r15, %rax
	sarq	$3, %rax
	cmpq	%rax, %rbp
	jb	.LBB10_19
# %bb.22:
	cmpq	%r14, %rbx
	je	.LBB10_58
# %bb.23:
	bsrq	%rax, %rdx
	xorq	$63, %rdx
	addq	%rdx, %rdx
	xorq	$126, %rdx
.Ltmp135:
	movq	%rbx, %rdi
	movq	%r14, %rsi
	callq	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPmSt6vectorImSaImEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_
.Ltmp136:
# %bb.24:
	cmpq	$129, %r15
	jl	.LBB10_45
# %bb.25:
	leaq	8(%rbx), %r15
	movl	$1, %r13d
	movq	%rbx, %rbp
	jmp	.LBB10_26
	.p2align	4, 0x90
.LBB10_27:                              #   in Loop: Header=BB10_26 Depth=1
	leaq	(,%r13,8), %rdx
	movq	%r15, %rdi
	movq	%rbx, %rsi
	callq	memmove@PLT
	movq	%rbx, %rdx
.LBB10_35:                              #   in Loop: Header=BB10_26 Depth=1
	movq	%r12, (%rdx)
	incq	%r13
	cmpq	$16, %r13
	je	.LBB10_36
.LBB10_26:                              # =>This Loop Header: Depth=1
                                        #     Child Loop BB10_29 Depth 2
	movq	%rbp, %rax
	addq	$8, %rbp
	movq	8(%rax), %r12
	cmpq	(%rbx), %r12
	jb	.LBB10_27
# %bb.28:                               #   in Loop: Header=BB10_26 Depth=1
	movq	(%rax), %rcx
	movq	%rbp, %rdx
	cmpq	%rcx, %r12
	jae	.LBB10_35
	.p2align	4, 0x90
.LBB10_29:                              #   Parent Loop BB10_26 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movq	%rcx, 8(%rax)
	movq	-8(%rax), %rcx
	cmpq	%rcx, %r12
	jae	.LBB10_34
# %bb.30:                               #   in Loop: Header=BB10_29 Depth=2
	movq	%rcx, (%rax)
	movq	-16(%rax), %rcx
	cmpq	%rcx, %r12
	jae	.LBB10_31
# %bb.117:                              #   in Loop: Header=BB10_29 Depth=2
	movq	%rcx, -8(%rax)
	movq	-24(%rax), %rcx
	cmpq	%rcx, %r12
	jae	.LBB10_32
# %bb.118:                              #   in Loop: Header=BB10_29 Depth=2
	movq	%rcx, -16(%rax)
	movq	-32(%rax), %rcx
	addq	$-32, %rax
	cmpq	%rcx, %r12
	jb	.LBB10_29
# %bb.33:                               #   in Loop: Header=BB10_26 Depth=1
	addq	$8, %rax
	jmp	.LBB10_34
.LBB10_31:                              #   in Loop: Header=BB10_26 Depth=1
	addq	$-8, %rax
	jmp	.LBB10_34
.LBB10_32:                              #   in Loop: Header=BB10_26 Depth=1
	addq	$-16, %rax
.LBB10_34:                              #   in Loop: Header=BB10_26 Depth=1
	movq	%rax, %rdx
	jmp	.LBB10_35
.LBB10_45:
	leaq	8(%rbx), %r12
	cmpq	%r14, %r12
	je	.LBB10_58
# %bb.46:
	movq	%rbx, %r13
	jmp	.LBB10_47
.LBB10_54:                              #   in Loop: Header=BB10_47 Depth=1
	addq	$-8, %rax
	.p2align	4, 0x90
.LBB10_57:                              #   in Loop: Header=BB10_47 Depth=1
	movq	%rbp, (%rax)
	addq	$8, %r12
	addq	$8, %r13
	cmpq	%r14, %r12
	je	.LBB10_58
.LBB10_47:                              # =>This Loop Header: Depth=1
                                        #     Child Loop BB10_52 Depth 2
	movq	(%r12), %rbp
	cmpq	(%rbx), %rbp
	jae	.LBB10_50
# %bb.48:                               #   in Loop: Header=BB10_47 Depth=1
	movq	%r12, %rdx
	movq	%rbx, %rax
	subq	%rbx, %rdx
	je	.LBB10_57
# %bb.49:                               #   in Loop: Header=BB10_47 Depth=1
	movq	%r13, %rdi
	subq	%rdx, %rdi
	addq	$16, %rdi
	movq	%rbx, %rsi
	callq	memmove@PLT
	movq	%rbx, %rax
	jmp	.LBB10_57
	.p2align	4, 0x90
.LBB10_50:                              #   in Loop: Header=BB10_47 Depth=1
	movq	(%r13), %rcx
	movq	%r12, %rax
	cmpq	%rcx, %rbp
	jae	.LBB10_57
# %bb.51:                               #   in Loop: Header=BB10_47 Depth=1
	movq	%r13, %rax
	.p2align	4, 0x90
.LBB10_52:                              #   Parent Loop BB10_47 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movq	%rcx, 8(%rax)
	movq	-8(%rax), %rcx
	cmpq	%rcx, %rbp
	jae	.LBB10_57
# %bb.53:                               #   in Loop: Header=BB10_52 Depth=2
	movq	%rcx, (%rax)
	movq	-16(%rax), %rcx
	cmpq	%rcx, %rbp
	jae	.LBB10_54
# %bb.115:                              #   in Loop: Header=BB10_52 Depth=2
	movq	%rcx, -8(%rax)
	movq	-24(%rax), %rcx
	cmpq	%rcx, %rbp
	jae	.LBB10_55
# %bb.116:                              #   in Loop: Header=BB10_52 Depth=2
	movq	%rcx, -16(%rax)
	movq	-32(%rax), %rcx
	addq	$-32, %rax
	cmpq	%rcx, %rbp
	jb	.LBB10_52
# %bb.56:                               #   in Loop: Header=BB10_47 Depth=1
	addq	$8, %rax
	jmp	.LBB10_57
.LBB10_55:                              #   in Loop: Header=BB10_47 Depth=1
	addq	$-16, %rax
	jmp	.LBB10_57
.LBB10_36:
	leaq	128(%rbx), %rax
	jmp	.LBB10_37
.LBB10_41:                              #   in Loop: Header=BB10_37 Depth=1
	addq	$120, %rdx
	.p2align	4, 0x90
.LBB10_44:                              #   in Loop: Header=BB10_37 Depth=1
	movq	%rcx, (%rdx)
	addq	$8, %rax
	addq	$8, %rbx
.LBB10_37:                              # =>This Loop Header: Depth=1
                                        #     Child Loop BB10_40 Depth 2
	cmpq	%r14, %rax
	je	.LBB10_58
# %bb.38:                               #   in Loop: Header=BB10_37 Depth=1
	movq	-8(%rax), %rsi
	movq	(%rax), %rcx
	movq	%rax, %rdx
	cmpq	%rsi, %rcx
	jae	.LBB10_44
# %bb.39:                               #   in Loop: Header=BB10_37 Depth=1
	movq	%rbx, %rdx
	.p2align	4, 0x90
.LBB10_40:                              #   Parent Loop BB10_37 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movq	%rsi, 128(%rdx)
	movq	112(%rdx), %rsi
	cmpq	%rsi, %rcx
	jae	.LBB10_41
# %bb.119:                              #   in Loop: Header=BB10_40 Depth=2
	movq	%rsi, 120(%rdx)
	movq	104(%rdx), %rsi
	cmpq	%rsi, %rcx
	jae	.LBB10_42
# %bb.120:                              #   in Loop: Header=BB10_40 Depth=2
	movq	%rsi, 112(%rdx)
	movq	96(%rdx), %rsi
	cmpq	%rsi, %rcx
	jae	.LBB10_43
# %bb.121:                              #   in Loop: Header=BB10_40 Depth=2
	movq	%rsi, 104(%rdx)
	movq	88(%rdx), %rsi
	addq	$-32, %rdx
	cmpq	%rsi, %rcx
	jb	.LBB10_40
# %bb.122:                              #   in Loop: Header=BB10_37 Depth=1
	subq	$-128, %rdx
	jmp	.LBB10_44
.LBB10_42:                              #   in Loop: Header=BB10_37 Depth=1
	addq	$112, %rdx
	jmp	.LBB10_44
.LBB10_43:                              #   in Loop: Header=BB10_37 Depth=1
	addq	$104, %rdx
	jmp	.LBB10_44
.LBB10_58:
	movq	(%rsp), %rax                    # 8-byte Reload
	movq	48(%rax), %r8
	movq	56(%rax), %r9
	movq	%r9, %r15
	subq	%r8, %r15
	sarq	$3, %r15
	movq	%r15, %r10
	andq	$-2, %r10
	imulq	$90, %r15, %rax
	shrq	$2, %rax
	movabsq	$2951479051793528259, %rdi      # imm = 0x28F5C28F5C28F5C3
	mulq	%rdi
	movq	%rdx, %rcx
	andq	$-4, %rcx
	imulq	$95, %r15, %rax
	shrq	$2, %rax
	mulq	%rdi
	movq	%rdx, %rsi
	imulq	$99, %r15, %rax
	shrq	$2, %rax
	mulq	%rdi
	movq	%rdx, %rdi
	andq	$-4, %rsi
	imulq	$999, %r15, %rax                # imm = 0x3E7
	shrq	$3, %rax
	movabsq	$2361183241434822607, %rdx      # imm = 0x20C49BA5E353F7CF
	mulq	%rdx
	andq	$-4, %rdi
	shrq	$4, %rdx
	cmpq	%r8, %r9
	je	.LBB10_59
# %bb.67:
	vmovq	%r15, %xmm0
	vpunpckldq	.LCPI10_0(%rip), %xmm0, %xmm0 # xmm0 = xmm0[0],mem[0],xmm0[1],mem[1]
	vsubpd	.LCPI10_1(%rip), %xmm0, %xmm0
	vshufpd	$1, %xmm0, %xmm0, %xmm1         # xmm1 = xmm0[1,0]
	vaddsd	%xmm0, %xmm1, %xmm0
	cmpq	$1, %r15
	movq	%r15, %rax
	adcq	$0, %rax
	movq	%rax, %r11
	andq	$-4, %r11
	je	.LBB10_68
# %bb.123:
	leaq	-1(%r11), %rbx
	vmovsd	.LCPI10_2(%rip), %xmm1          # xmm1 = mem[0],zero
	vdivsd	%xmm0, %xmm1, %xmm1
	vbroadcastsd	%xmm1, %ymm1
	vpxor	%xmm2, %xmm2, %xmm2
	xorl	%r14d, %r14d
	vpbroadcastq	.LCPI10_3(%rip), %ymm4  # ymm4 = [4841369599423283200,4841369599423283200,4841369599423283200,4841369599423283200]
	vpbroadcastq	.LCPI10_4(%rip), %ymm5  # ymm5 = [4985484787499139072,4985484787499139072,4985484787499139072,4985484787499139072]
	vbroadcastsd	.LCPI10_5(%rip), %ymm6  # ymm6 = [1.9342813118337666E+25,1.9342813118337666E+25,1.9342813118337666E+25,1.9342813118337666E+25]
	vxorpd	%xmm3, %xmm3, %xmm3
	.p2align	4, 0x90
.LBB10_124:                             # =>This Inner Loop Header: Depth=1
	vmovdqu	(%r8,%r14,8), %ymm7
	vpblendd	$170, %ymm2, %ymm7, %ymm8       # ymm8 = ymm7[0],ymm2[1],ymm7[2],ymm2[3],ymm7[4],ymm2[5],ymm7[6],ymm2[7]
	vpor	%ymm4, %ymm8, %ymm8
	vpsrlq	$32, %ymm7, %ymm7
	vpor	%ymm5, %ymm7, %ymm7
	vsubpd	%ymm6, %ymm7, %ymm7
	vaddpd	%ymm7, %ymm8, %ymm7
	vmulpd	%ymm1, %ymm7, %ymm7
	vaddpd	%ymm3, %ymm7, %ymm3
	addq	$4, %r14
	cmpq	%rbx, %r14
	jbe	.LBB10_124
# %bb.125:
	vextractf128	$1, %ymm3, %xmm1
	vaddpd	%xmm1, %xmm3, %xmm1
	vshufpd	$1, %xmm1, %xmm1, %xmm2         # xmm2 = xmm1[1,0]
	vaddsd	%xmm2, %xmm1, %xmm5
	cmpq	%r11, %rax
	jne	.LBB10_69
	jmp	.LBB10_126
.LBB10_59:
	vxorpd	%xmm5, %xmm5, %xmm5
	jmp	.LBB10_126
.LBB10_68:
	xorl	%r11d, %r11d
	vxorpd	%xmm5, %xmm5, %xmm5
.LBB10_69:
	vmovsd	.LCPI10_2(%rip), %xmm1          # xmm1 = mem[0],zero
	vdivsd	%xmm0, %xmm1, %xmm0
	vmovupd	.LCPI10_0(%rip), %xmm1          # xmm1 = [1127219200,1160773632,0,0]
                                        # AlignMOV convert to UnAlignMOV 
	vmovupd	.LCPI10_1(%rip), %xmm2          # xmm2 = [4.503599627370496E+15,1.9342813113834067E+25]
                                        # AlignMOV convert to UnAlignMOV 
	.p2align	4, 0x90
.LBB10_70:                              # =>This Inner Loop Header: Depth=1
	vmovsd	(%r8,%r11,8), %xmm3             # xmm3 = mem[0],zero
	vunpcklps	%xmm1, %xmm3, %xmm3     # xmm3 = xmm3[0],xmm1[0],xmm3[1],xmm1[1]
	vsubpd	%xmm2, %xmm3, %xmm3
	vshufpd	$1, %xmm3, %xmm3, %xmm4         # xmm4 = xmm3[1,0]
	vaddsd	%xmm3, %xmm4, %xmm3
	vmulsd	%xmm0, %xmm3, %xmm3
	vaddsd	%xmm5, %xmm3, %xmm5
	incq	%r11
	cmpq	%r11, %rax
	jne	.LBB10_70
.LBB10_126:
.Ltmp138:
	vmovsd	%xmm5, 40(%rsp)                 # 8-byte Spill
	movq	(%r8), %rax
	movq	%rax, 8(%rsp)                   # 8-byte Spill
	movq	-8(%r9), %r14
	movq	(%r8,%r10,4), %rbp
	movq	(%r8,%rcx,2), %r13
	movq	(%r8,%rsi,2), %rax
	movq	%rax, 32(%rsp)                  # 8-byte Spill
	movq	(%r8,%rdi,2), %rax
	movq	%rax, 24(%rsp)                  # 8-byte Spill
	movq	(%r8,%rdx,8), %rax
	movq	%rax, 16(%rsp)                  # 8-byte Spill
	movq	_ZSt4cout@GOTPCREL(%rip), %rbx
	leaq	.L.str.21(%rip), %rsi
	movl	$7, %edx
	movq	%rbx, %rdi
	vzeroupper
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp139:
# %bb.127:
	movq	(%rbx), %rax
	movq	-24(%rax), %rax
	movq	$8, 16(%rbx,%rax)
.Ltmp140:
	movq	%rbx, %rdi
	vmovsd	40(%rsp), %xmm0                 # 8-byte Reload
                                        # xmm0 = mem[0],zero
	callq	_ZNSo9_M_insertIdEERSoT_@PLT
.Ltmp141:
# %bb.128:
.Ltmp142:
	movq	%rax, %rbx
	leaq	.L.str.22(%rip), %rsi
	movl	$9, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp143:
# %bb.129:
	movq	(%rbx), %rax
	movq	-24(%rax), %rax
	movq	$8, 16(%rbx,%rax)
.Ltmp144:
	movq	%rbx, %rdi
	movq	%rbp, %rsi
	callq	_ZNSo9_M_insertImEERSoT_@PLT
.Ltmp145:
# %bb.130:
.Ltmp146:
	movq	%rax, %rbx
	leaq	.L.str.23(%rip), %rsi
	movl	$7, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp147:
# %bb.131:
	movq	(%rbx), %rax
	movq	-24(%rax), %rax
	movq	$8, 16(%rbx,%rax)
.Ltmp148:
	movq	%rbx, %rdi
	movq	%r13, %rsi
	callq	_ZNSo9_M_insertImEERSoT_@PLT
.Ltmp149:
# %bb.132:
.Ltmp150:
	movq	%rax, %rbx
	leaq	.L.str.24(%rip), %rsi
	movl	$7, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp151:
# %bb.133:
	movq	(%rbx), %rax
	movq	-24(%rax), %rax
	movq	$8, 16(%rbx,%rax)
.Ltmp152:
	movq	%rbx, %rdi
	movq	32(%rsp), %rsi                  # 8-byte Reload
	callq	_ZNSo9_M_insertImEERSoT_@PLT
.Ltmp153:
# %bb.134:
.Ltmp154:
	movq	%rax, %rbx
	leaq	.L.str.25(%rip), %rsi
	movl	$7, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp155:
# %bb.135:
	movq	(%rbx), %rax
	movq	-24(%rax), %rax
	movq	$8, 16(%rbx,%rax)
.Ltmp156:
	movq	%rbx, %rdi
	movq	24(%rsp), %rsi                  # 8-byte Reload
	callq	_ZNSo9_M_insertImEERSoT_@PLT
.Ltmp157:
# %bb.136:
.Ltmp158:
	movq	%rax, %rbx
	leaq	.L.str.26(%rip), %rsi
	movl	$9, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp159:
# %bb.137:
	movq	(%rbx), %rax
	movq	-24(%rax), %rax
	movq	$8, 16(%rbx,%rax)
.Ltmp160:
	movq	%rbx, %rdi
	movq	16(%rsp), %rsi                  # 8-byte Reload
	callq	_ZNSo9_M_insertImEERSoT_@PLT
.Ltmp161:
# %bb.138:
.Ltmp162:
	movq	%rax, %rbx
	leaq	.L.str.27(%rip), %rsi
	movl	$6, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp163:
# %bb.139:
	movq	(%rbx), %rax
	movq	-24(%rax), %rax
	movq	$8, 16(%rbx,%rax)
.Ltmp164:
	movq	%rbx, %rdi
	movq	8(%rsp), %rsi                   # 8-byte Reload
	callq	_ZNSo9_M_insertImEERSoT_@PLT
.Ltmp165:
# %bb.140:
.Ltmp166:
	movq	%rax, %rbx
	leaq	.L.str.28(%rip), %rsi
	movl	$6, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp167:
# %bb.141:
	movq	(%rbx), %rax
	movq	-24(%rax), %rax
	movq	$8, 16(%rbx,%rax)
.Ltmp168:
	movq	%rbx, %rdi
	movq	%r14, %rsi
	callq	_ZNSo9_M_insertImEERSoT_@PLT
.Ltmp169:
# %bb.142:
.Ltmp170:
	movq	%rax, %rbx
	leaq	.L.str.29(%rip), %rsi
	movl	$8, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp171:
# %bb.143:
.Ltmp172:
	movq	%rbx, %rdi
	movq	%r15, %rsi
	callq	_ZNSo9_M_insertImEERSoT_@PLT
.Ltmp173:
# %bb.144:
	movq	%rax, %rbx
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%rbx,%rax), %r12
	testq	%r12, %r12
	je	.LBB10_97
# %bb.145:
	cmpb	$0, 56(%r12)
	je	.LBB10_72
# %bb.146:
	movzbl	67(%r12), %eax
	jmp	.LBB10_74
.LBB10_72:
.Ltmp174:
	movq	%r12, %rdi
	callq	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
.Ltmp175:
# %bb.73:
	movq	(%r12), %rax
.Ltmp176:
	movq	%r12, %rdi
	movl	$10, %esi
	callq	*48(%rax)
.Ltmp177:
.LBB10_74:
.Ltmp178:
	movsbl	%al, %esi
	movq	%rbx, %rdi
	callq	_ZNSo3putEc@PLT
.Ltmp179:
# %bb.75:
.Ltmp180:
	movq	%rax, %rdi
	callq	_ZNSo5flushEv@PLT
.Ltmp181:
# %bb.76:
	movq	(%rsp), %rax                    # 8-byte Reload
	movq	(%rax), %rsi
	movq	8(%rax), %rdx
.Ltmp182:
	leaq	48(%rsp), %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp183:
# %bb.77:
.Ltmp184:
	movq	%rax, %rbx
	leaq	.L.str.20(%rip), %rsi
	movl	$3, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp185:
# %bb.78:
.Ltmp186:
	leaq	.L.str.21(%rip), %rsi
	movl	$7, %edx
	movq	%rbx, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp187:
# %bb.79:
	vcvttsd2si	40(%rsp), %esi          # 8-byte Folded Reload
.Ltmp188:
	movq	%rbx, %rdi
	callq	_ZNSolsEi@PLT
.Ltmp189:
# %bb.80:
.Ltmp190:
	movq	%rax, %rbx
	leaq	.L.str.22(%rip), %rsi
	movl	$9, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp191:
# %bb.81:
.Ltmp192:
	movq	%rbx, %rdi
	movq	%rbp, %rsi
	callq	_ZNSo9_M_insertImEERSoT_@PLT
.Ltmp193:
# %bb.82:
.Ltmp194:
	movq	%rax, %rbx
	leaq	.L.str.23(%rip), %rsi
	movl	$7, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp195:
# %bb.83:
.Ltmp196:
	movq	%rbx, %rdi
	movq	%r13, %rsi
	callq	_ZNSo9_M_insertImEERSoT_@PLT
.Ltmp197:
# %bb.84:
.Ltmp198:
	movq	%rax, %rbx
	leaq	.L.str.24(%rip), %rsi
	movl	$7, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp199:
# %bb.85:
.Ltmp200:
	movq	%rbx, %rdi
	movq	32(%rsp), %rsi                  # 8-byte Reload
	callq	_ZNSo9_M_insertImEERSoT_@PLT
.Ltmp201:
# %bb.86:
.Ltmp202:
	movq	%rax, %rbx
	leaq	.L.str.25(%rip), %rsi
	movl	$7, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp203:
# %bb.87:
.Ltmp204:
	movq	%rbx, %rdi
	movq	24(%rsp), %rsi                  # 8-byte Reload
	callq	_ZNSo9_M_insertImEERSoT_@PLT
.Ltmp205:
# %bb.88:
.Ltmp206:
	movq	%rax, %rbx
	leaq	.L.str.26(%rip), %rsi
	movl	$9, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp207:
# %bb.89:
.Ltmp208:
	movq	%rbx, %rdi
	movq	16(%rsp), %rsi                  # 8-byte Reload
	callq	_ZNSo9_M_insertImEERSoT_@PLT
.Ltmp209:
# %bb.90:
.Ltmp210:
	movq	%rax, %rbx
	leaq	.L.str.27(%rip), %rsi
	movl	$6, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp211:
# %bb.91:
.Ltmp212:
	movq	%rbx, %rdi
	movq	8(%rsp), %rsi                   # 8-byte Reload
	callq	_ZNSo9_M_insertImEERSoT_@PLT
.Ltmp213:
# %bb.92:
.Ltmp214:
	movq	%rax, %rbx
	leaq	.L.str.28(%rip), %rsi
	movl	$6, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp215:
# %bb.93:
.Ltmp216:
	movq	%rbx, %rdi
	movq	%r14, %rsi
	callq	_ZNSo9_M_insertImEERSoT_@PLT
.Ltmp217:
# %bb.94:
.Ltmp218:
	movq	%rax, %rbx
	leaq	.L.str.29(%rip), %rsi
	movl	$8, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp219:
# %bb.95:
.Ltmp220:
	movq	%rbx, %rdi
	movq	%r15, %rsi
	callq	_ZNSo9_M_insertImEERSoT_@PLT
.Ltmp221:
# %bb.96:
	movq	%rax, %rbx
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%rbx,%rax), %r14
	testq	%r14, %r14
	je	.LBB10_97
# %bb.100:
	cmpb	$0, 56(%r14)
	je	.LBB10_102
# %bb.101:
	movzbl	67(%r14), %eax
	jmp	.LBB10_104
.LBB10_102:
.Ltmp222:
	movq	%r14, %rdi
	callq	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
.Ltmp223:
# %bb.103:
	movq	(%r14), %rax
.Ltmp224:
	movq	%r14, %rdi
	movl	$10, %esi
	callq	*48(%rax)
.Ltmp225:
.LBB10_104:
.Ltmp226:
	movsbl	%al, %esi
	movq	%rbx, %rdi
	callq	_ZNSo3putEc@PLT
.Ltmp227:
# %bb.105:
.Ltmp228:
	movq	%rax, %rdi
	callq	_ZNSo5flushEv@PLT
.Ltmp229:
# %bb.106:
.Ltmp230:
	leaq	56(%rsp), %rdi
	callq	_ZNSt13basic_filebufIcSt11char_traitsIcEE5closeEv@PLT
.Ltmp231:
# %bb.107:
	testq	%rax, %rax
	jne	.LBB10_109
# %bb.108:
	movq	48(%rsp), %rax
	movq	-24(%rax), %rax
	leaq	(%rsp,%rax), %rdi
	addq	$48, %rdi
	movl	80(%rsp,%rax), %esi
	orl	$4, %esi
.Ltmp232:
	callq	_ZNSt9basic_iosIcSt11char_traitsIcEE5clearESt12_Ios_Iostate@PLT
.Ltmp233:
.LBB10_109:
	leaq	48(%rsp), %rdi
	callq	_ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev@PLT
	movq	%fs:40, %rax
	cmpq	624(%rsp), %rax
	jne	.LBB10_147
# %bb.110:
	addq	$632, %rsp                      # imm = 0x278
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%r12
	.cfi_def_cfa_offset 40
	popq	%r13
	.cfi_def_cfa_offset 32
	popq	%r14
	.cfi_def_cfa_offset 24
	popq	%r15
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	retq
.LBB10_97:
	.cfi_def_cfa_offset 688
	movq	%fs:40, %rax
	cmpq	624(%rsp), %rax
	jne	.LBB10_147
# %bb.98:
.Ltmp234:
	callq	_ZSt16__throw_bad_castv@PLT
.Ltmp235:
# %bb.99:
.LBB10_2:
	movq	%fs:40, %rax
	cmpq	624(%rsp), %rax
	jne	.LBB10_147
# %bb.3:
.Ltmp237:
	leaq	.L.str.11(%rip), %rdi
	callq	_ZSt20__throw_length_errorPKc@PLT
.Ltmp238:
# %bb.4:
.LBB10_71:
.Ltmp137:
	jmp	.LBB10_112
.LBB10_60:
.Ltmp122:
	jmp	.LBB10_112
.LBB10_62:
.Ltmp129:
	movq	%rax, %rbx
	movq	592(%rsp), %rdi
	cmpq	%r15, %rdi
	je	.LBB10_64
# %bb.63:
	callq	_ZdlPv@PLT
	jmp	.LBB10_64
.LBB10_61:
.Ltmp239:
	movq	%rax, %rbx
.LBB10_64:
	movq	560(%rsp), %rdi
	leaq	576(%rsp), %rax
	cmpq	%rax, %rdi
	je	.LBB10_113
# %bb.65:
	callq	_ZdlPv@PLT
	jmp	.LBB10_113
.LBB10_66:
.Ltmp134:
	jmp	.LBB10_112
.LBB10_111:
.Ltmp236:
.LBB10_112:
	movq	%rax, %rbx
.LBB10_113:
	leaq	48(%rsp), %rdi
	callq	_ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev@PLT
	movq	%fs:40, %rax
	cmpq	624(%rsp), %rax
	jne	.LBB10_147
# %bb.114:
	movq	%rbx, %rdi
	callq	_Unwind_Resume@PLT
.LBB10_147:
	callq	__stack_chk_fail@PLT
.Lfunc_end10:
	.size	_ZN6TagObj26prepareReportAndDumpToFileEv, .Lfunc_end10-_ZN6TagObj26prepareReportAndDumpToFileEv
	.cfi_endproc
	.section	.gcc_except_table._ZN6TagObj26prepareReportAndDumpToFileEv,"aG",@progbits,_ZN6TagObj26prepareReportAndDumpToFileEv,comdat
	.p2align	2, 0x0
GCC_except_table10:
.Lexception6:
	.byte	255                             # @LPStart Encoding = omit
	.byte	255                             # @TType Encoding = omit
	.byte	1                               # Call site Encoding = uleb128
	.uleb128 .Lcst_end6-.Lcst_begin6
.Lcst_begin6:
	.uleb128 .Lfunc_begin6-.Lfunc_begin6    # >> Call Site 1 <<
	.uleb128 .Ltmp120-.Lfunc_begin6         #   Call between .Lfunc_begin6 and .Ltmp120
	.byte	0                               #     has no landing pad
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp120-.Lfunc_begin6         # >> Call Site 2 <<
	.uleb128 .Ltmp121-.Ltmp120              #   Call between .Ltmp120 and .Ltmp121
	.uleb128 .Ltmp122-.Lfunc_begin6         #     jumps to .Ltmp122
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp123-.Lfunc_begin6         # >> Call Site 3 <<
	.uleb128 .Ltmp124-.Ltmp123              #   Call between .Ltmp123 and .Ltmp124
	.uleb128 .Ltmp239-.Lfunc_begin6         #     jumps to .Ltmp239
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp125-.Lfunc_begin6         # >> Call Site 4 <<
	.uleb128 .Ltmp128-.Ltmp125              #   Call between .Ltmp125 and .Ltmp128
	.uleb128 .Ltmp129-.Lfunc_begin6         #     jumps to .Ltmp129
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp130-.Lfunc_begin6         # >> Call Site 5 <<
	.uleb128 .Ltmp133-.Ltmp130              #   Call between .Ltmp130 and .Ltmp133
	.uleb128 .Ltmp134-.Lfunc_begin6         #     jumps to .Ltmp134
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp135-.Lfunc_begin6         # >> Call Site 6 <<
	.uleb128 .Ltmp136-.Ltmp135              #   Call between .Ltmp135 and .Ltmp136
	.uleb128 .Ltmp137-.Lfunc_begin6         #     jumps to .Ltmp137
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp136-.Lfunc_begin6         # >> Call Site 7 <<
	.uleb128 .Ltmp138-.Ltmp136              #   Call between .Ltmp136 and .Ltmp138
	.byte	0                               #     has no landing pad
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp138-.Lfunc_begin6         # >> Call Site 8 <<
	.uleb128 .Ltmp235-.Ltmp138              #   Call between .Ltmp138 and .Ltmp235
	.uleb128 .Ltmp236-.Lfunc_begin6         #     jumps to .Ltmp236
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp237-.Lfunc_begin6         # >> Call Site 9 <<
	.uleb128 .Ltmp238-.Ltmp237              #   Call between .Ltmp237 and .Ltmp238
	.uleb128 .Ltmp239-.Lfunc_begin6         #     jumps to .Ltmp239
	.byte	0                               #   On action: cleanup
	.uleb128 .Ltmp238-.Lfunc_begin6         # >> Call Site 10 <<
	.uleb128 .Lfunc_end10-.Ltmp238          #   Call between .Ltmp238 and .Lfunc_end10
	.byte	0                               #     has no landing pad
	.byte	0                               #   On action: cleanup
.Lcst_end6:
	.p2align	2, 0x0
                                        # -- End function
	.section	.text._ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPmSt6vectorImSaImEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_,"axG",@progbits,_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPmSt6vectorImSaImEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_,comdat
	.weak	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPmSt6vectorImSaImEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_ # -- Begin function _ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPmSt6vectorImSaImEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_
	.p2align	4, 0x90
	.type	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPmSt6vectorImSaImEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_,@function
_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPmSt6vectorImSaImEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_: # 
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%r15
	.cfi_def_cfa_offset 24
	pushq	%r14
	.cfi_def_cfa_offset 32
	pushq	%r13
	.cfi_def_cfa_offset 40
	pushq	%r12
	.cfi_def_cfa_offset 48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	pushq	%rax
	.cfi_def_cfa_offset 64
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	.cfi_offset %rbp, -16
	movq	%rsi, %r14
	subq	%rdi, %r14
	cmpq	$129, %r14
	jl	.LBB11_25
# %bb.1:
	movq	%rdx, %r15
	movq	%rsi, %r13
	movq	%rdi, %rbx
	leaq	8(%rdi), %r8
	movq	$-8, %rbp
	subq	%rdi, %rbp
	jmp	.LBB11_2
	.p2align	4, 0x90
.LBB11_24:                              #   in Loop: Header=BB11_2 Depth=1
	movq	%r12, %rdi
	movq	%r13, %rsi
	movq	%r15, %rdx
	movq	%r8, %r13
	callq	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPmSt6vectorImSaImEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_
	movq	%r13, %r8
	movq	%r12, %r13
	cmpq	$128, %r14
	jle	.LBB11_25
.LBB11_2:                               # =>This Loop Header: Depth=1
                                        #     Child Loop BB11_18 Depth 2
                                        #       Child Loop BB11_19 Depth 3
                                        #       Child Loop BB11_21 Depth 3
	subq	$1, %r15
	jb	.LBB11_3
# %bb.14:                               #   in Loop: Header=BB11_2 Depth=1
	sarq	%r14
	andq	$-8, %r14
	leaq	(%rbx,%r14), %rdx
	leaq	-8(%r13), %rcx
	movq	8(%rbx), %rax
	movq	(%rbx,%r14), %rsi
	movq	-8(%r13), %rdi
	cmpq	%rsi, %rax
	jae	.LBB11_16
# %bb.15:                               #   in Loop: Header=BB11_2 Depth=1
	cmpq	%rdi, %rax
	cmovbeq	%rdi, %rax
	cmovaeq	%r8, %rcx
	cmpq	%rdi, %rsi
	cmovbq	%rsi, %rax
	cmovbq	%rdx, %rcx
	jmp	.LBB11_17
	.p2align	4, 0x90
.LBB11_16:                              #   in Loop: Header=BB11_2 Depth=1
	cmpq	%rdi, %rsi
	cmovbeq	%rdi, %rsi
	cmovbq	%rcx, %rdx
	cmpq	%rdi, %rax
	cmovaeq	%rsi, %rax
	cmovbq	%r8, %rdx
	movq	%rdx, %rcx
.LBB11_17:                              #   in Loop: Header=BB11_2 Depth=1
	movq	(%rbx), %rdx
	movq	%rax, (%rbx)
	movq	%rdx, (%rcx)
	movq	%r8, %rax
	movq	%r13, %rcx
	.p2align	4, 0x90
.LBB11_18:                              #   Parent Loop BB11_2 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB11_19 Depth 3
                                        #       Child Loop BB11_21 Depth 3
	movq	(%rbx), %rdx
	leaq	(%rax,%rbp), %r14
	.p2align	4, 0x90
.LBB11_19:                              #   Parent Loop BB11_2 Depth=1
                                        #     Parent Loop BB11_18 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	movq	(%rax), %rsi
	addq	$8, %rax
	addq	$8, %r14
	cmpq	%rdx, %rsi
	jb	.LBB11_19
# %bb.20:                               #   in Loop: Header=BB11_18 Depth=2
	leaq	-8(%rax), %r12
	.p2align	4, 0x90
.LBB11_21:                              #   Parent Loop BB11_2 Depth=1
                                        #     Parent Loop BB11_18 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	movq	-8(%rcx), %rdi
	addq	$-8, %rcx
	cmpq	%rdi, %rdx
	jb	.LBB11_21
# %bb.22:                               #   in Loop: Header=BB11_18 Depth=2
	cmpq	%rcx, %r12
	jae	.LBB11_24
# %bb.23:                               #   in Loop: Header=BB11_18 Depth=2
	movq	%rdi, (%r12)
	movq	%rsi, (%rcx)
	jmp	.LBB11_18
.LBB11_3:
	movq	%rbx, %rdi
	movq	%r13, %rsi
	movq	%r13, %rdx
	callq	_ZSt13__heap_selectIN9__gnu_cxx17__normal_iteratorIPmSt6vectorImSaImEEEENS0_5__ops15_Iter_less_iterEEvT_S9_S9_T0_
	jmp	.LBB11_4
	.p2align	4, 0x90
.LBB11_13:                              #   in Loop: Header=BB11_4 Depth=1
	movq	%rax, (%rbx,%rdx,8)
	cmpq	$8, %rcx
	jle	.LBB11_25
.LBB11_4:                               # =>This Loop Header: Depth=1
                                        #     Child Loop BB11_27 Depth 2
                                        #     Child Loop BB11_10 Depth 2
	movq	-8(%r13), %rax
	movq	(%rbx), %rcx
	movq	%rcx, -8(%r13)
	addq	$-8, %r13
	movq	%r13, %rcx
	subq	%rbx, %rcx
	movq	%rcx, %rsi
	sarq	$3, %rsi
	cmpq	$17, %rcx
	jl	.LBB11_5
# %bb.26:                               #   in Loop: Header=BB11_4 Depth=1
	leaq	-1(%rsi), %rdx
	shrq	$63, %rdx
	leaq	(%rsi,%rdx), %rdi
	decq	%rdi
	sarq	%rdi
	xorl	%edx, %edx
	jmp	.LBB11_27
	.p2align	4, 0x90
.LBB11_43:                              #   in Loop: Header=BB11_27 Depth=2
	leaq	2(,%r8,2), %rdx
.LBB11_44:                              #   in Loop: Header=BB11_27 Depth=2
	movq	(%rbx,%rdx,8), %r9
	movq	%r9, (%rbx,%r8,8)
	cmpq	%rdi, %rdx
	jge	.LBB11_6
.LBB11_27:                              #   Parent Loop BB11_4 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	leaq	(%rdx,%rdx), %r8
	movq	16(%rbx,%r8,8), %r9
	cmpq	8(%rbx,%r8,8), %r9
	jb	.LBB11_28
# %bb.29:                               #   in Loop: Header=BB11_27 Depth=2
	leaq	2(,%rdx,2), %r8
	movq	(%rbx,%r8,8), %r9
	movq	%r9, (%rbx,%rdx,8)
	cmpq	%rdi, %r8
	jl	.LBB11_32
	jmp	.LBB11_31
	.p2align	4, 0x90
.LBB11_28:                              #   in Loop: Header=BB11_27 Depth=2
	leaq	1(,%rdx,2), %r8
	movq	(%rbx,%r8,8), %r9
	movq	%r9, (%rbx,%rdx,8)
	cmpq	%rdi, %r8
	jge	.LBB11_31
.LBB11_32:                              #   in Loop: Header=BB11_27 Depth=2
	leaq	(%r8,%r8), %rdx
	movq	16(%rbx,%rdx,8), %r9
	cmpq	8(%rbx,%rdx,8), %r9
	jb	.LBB11_33
# %bb.34:                               #   in Loop: Header=BB11_27 Depth=2
	leaq	2(,%r8,2), %rdx
	movq	(%rbx,%rdx,8), %r9
	movq	%r9, (%rbx,%r8,8)
	cmpq	%rdi, %rdx
	jl	.LBB11_36
	jmp	.LBB11_6
	.p2align	4, 0x90
.LBB11_33:                              #   in Loop: Header=BB11_27 Depth=2
	leaq	1(,%r8,2), %rdx
	movq	(%rbx,%rdx,8), %r9
	movq	%r9, (%rbx,%r8,8)
	cmpq	%rdi, %rdx
	jge	.LBB11_6
.LBB11_36:                              #   in Loop: Header=BB11_27 Depth=2
	leaq	(%rdx,%rdx), %r8
	movq	16(%rbx,%r8,8), %r9
	cmpq	8(%rbx,%r8,8), %r9
	jb	.LBB11_37
# %bb.38:                               #   in Loop: Header=BB11_27 Depth=2
	leaq	2(,%rdx,2), %r8
	movq	(%rbx,%r8,8), %r9
	movq	%r9, (%rbx,%rdx,8)
	cmpq	%rdi, %r8
	jl	.LBB11_41
	jmp	.LBB11_40
	.p2align	4, 0x90
.LBB11_37:                              #   in Loop: Header=BB11_27 Depth=2
	leaq	1(,%rdx,2), %r8
	movq	(%rbx,%r8,8), %r9
	movq	%r9, (%rbx,%rdx,8)
	cmpq	%rdi, %r8
	jge	.LBB11_40
.LBB11_41:                              #   in Loop: Header=BB11_27 Depth=2
	leaq	(%r8,%r8), %rdx
	movq	16(%rbx,%rdx,8), %r9
	cmpq	8(%rbx,%rdx,8), %r9
	jae	.LBB11_43
# %bb.42:                               #   in Loop: Header=BB11_27 Depth=2
	leaq	1(,%r8,2), %rdx
	jmp	.LBB11_44
	.p2align	4, 0x90
.LBB11_5:                               #   in Loop: Header=BB11_4 Depth=1
	xorl	%edx, %edx
	testb	$8, %cl
	je	.LBB11_7
	jmp	.LBB11_9
.LBB11_31:                              #   in Loop: Header=BB11_4 Depth=1
	movq	%r8, %rdx
	.p2align	4, 0x90
.LBB11_6:                               #   in Loop: Header=BB11_4 Depth=1
	testb	$8, %cl
	jne	.LBB11_9
.LBB11_7:                               #   in Loop: Header=BB11_4 Depth=1
	leaq	-2(%rsi), %rdi
	shrq	$63, %rdi
	addq	%rdi, %rsi
	addq	$-2, %rsi
	sarq	%rsi
	cmpq	%rsi, %rdx
	jne	.LBB11_9
# %bb.8:                                #   in Loop: Header=BB11_4 Depth=1
	leaq	(%rdx,%rdx), %rsi
	movq	8(%rbx,%rsi,8), %rsi
	movq	%rsi, (%rbx,%rdx,8)
	leaq	1(,%rdx,2), %rdx
.LBB11_9:                               #   in Loop: Header=BB11_4 Depth=1
	testq	%rdx, %rdx
	jle	.LBB11_13
	.p2align	4, 0x90
.LBB11_10:                              #   Parent Loop BB11_4 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	leaq	-1(%rdx), %rsi
	movq	%rsi, %rdi
	shrq	%rdi
	movq	(%rbx,%rdi,8), %r8
	cmpq	%rax, %r8
	jae	.LBB11_13
# %bb.11:                               #   in Loop: Header=BB11_10 Depth=2
	movq	%r8, (%rbx,%rdx,8)
	movq	%rdi, %rdx
	cmpq	$1, %rsi
	ja	.LBB11_10
# %bb.12:                               #   in Loop: Header=BB11_4 Depth=1
	xorl	%edx, %edx
	jmp	.LBB11_13
.LBB11_40:                              #   in Loop: Header=BB11_4 Depth=1
	movq	%r8, %rdx
	testb	$8, %cl
	je	.LBB11_7
	jmp	.LBB11_9
.LBB11_25:
	addq	$8, %rsp
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%r12
	.cfi_def_cfa_offset 40
	popq	%r13
	.cfi_def_cfa_offset 32
	popq	%r14
	.cfi_def_cfa_offset 24
	popq	%r15
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end11:
	.size	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPmSt6vectorImSaImEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_, .Lfunc_end11-_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPmSt6vectorImSaImEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_
	.cfi_endproc
                                        # -- End function
	.section	.text._ZSt13__heap_selectIN9__gnu_cxx17__normal_iteratorIPmSt6vectorImSaImEEEENS0_5__ops15_Iter_less_iterEEvT_S9_S9_T0_,"axG",@progbits,_ZSt13__heap_selectIN9__gnu_cxx17__normal_iteratorIPmSt6vectorImSaImEEEENS0_5__ops15_Iter_less_iterEEvT_S9_S9_T0_,comdat
	.weak	_ZSt13__heap_selectIN9__gnu_cxx17__normal_iteratorIPmSt6vectorImSaImEEEENS0_5__ops15_Iter_less_iterEEvT_S9_S9_T0_ # -- Begin function _ZSt13__heap_selectIN9__gnu_cxx17__normal_iteratorIPmSt6vectorImSaImEEEENS0_5__ops15_Iter_less_iterEEvT_S9_S9_T0_
	.p2align	4, 0x90
	.type	_ZSt13__heap_selectIN9__gnu_cxx17__normal_iteratorIPmSt6vectorImSaImEEEENS0_5__ops15_Iter_less_iterEEvT_S9_S9_T0_,@function
_ZSt13__heap_selectIN9__gnu_cxx17__normal_iteratorIPmSt6vectorImSaImEEEENS0_5__ops15_Iter_less_iterEEvT_S9_S9_T0_: # 
	.cfi_startproc
# %bb.0:
	pushq	%r15
	.cfi_def_cfa_offset 16
	pushq	%r14
	.cfi_def_cfa_offset 24
	pushq	%r12
	.cfi_def_cfa_offset 32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset %rbx, -40
	.cfi_offset %r12, -32
	.cfi_offset %r14, -24
	.cfi_offset %r15, -16
	movq	%rsi, %rax
	subq	%rdi, %rax
	movq	%rax, %rcx
	sarq	$3, %rcx
	cmpq	$16, %rax
	jge	.LBB12_29
.LBB12_1:
	cmpq	%rdx, %rsi
	jae	.LBB12_149
# %bb.2:
	leaq	-1(%rcx), %r9
	andl	$8, %eax
	leaq	-2(%rcx), %r8
	shrq	$63, %r8
	addq	%rcx, %r8
	addq	$-2, %r8
	sarq	%r8
	cmpq	$2, %r9
	jl	.LBB12_81
# %bb.3:
	shrq	$63, %r9
	addq	%r9, %rcx
	decq	%rcx
	sarq	%rcx
	leaq	(%r8,%r8), %r9
	leaq	1(,%r8,2), %r10
	jmp	.LBB12_6
	.p2align	4, 0x90
.LBB12_4:                               #   in Loop: Header=BB12_6 Depth=1
	movq	%r11, (%rdi,%rbx,8)
.LBB12_5:                               #   in Loop: Header=BB12_6 Depth=1
	addq	$8, %rsi
	cmpq	%rdx, %rsi
	jae	.LBB12_149
.LBB12_6:                               # =>This Loop Header: Depth=1
                                        #     Child Loop BB12_10 Depth 2
                                        #     Child Loop BB12_26 Depth 2
	movq	(%rsi), %r11
	movq	(%rdi), %rbx
	cmpq	%rbx, %r11
	jae	.LBB12_5
# %bb.7:                                #   in Loop: Header=BB12_6 Depth=1
	movq	%rbx, (%rsi)
	xorl	%ebx, %ebx
	jmp	.LBB12_10
	.p2align	4, 0x90
.LBB12_8:                               #   in Loop: Header=BB12_10 Depth=2
	leaq	2(,%r14,2), %rbx
	movq	(%rdi,%rbx,8), %r15
	movq	%r15, (%rdi,%r14,8)
	cmpq	%rcx, %rbx
	jge	.LBB12_22
.LBB12_10:                              #   Parent Loop BB12_6 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	leaq	(%rbx,%rbx), %r14
	movq	16(%rdi,%r14,8), %r15
	cmpq	8(%rdi,%r14,8), %r15
	jb	.LBB12_12
# %bb.11:                               #   in Loop: Header=BB12_10 Depth=2
	leaq	2(,%rbx,2), %r14
	movq	(%rdi,%r14,8), %r15
	movq	%r15, (%rdi,%rbx,8)
	cmpq	%rcx, %r14
	jl	.LBB12_13
	jmp	.LBB12_21
	.p2align	4, 0x90
.LBB12_12:                              #   in Loop: Header=BB12_10 Depth=2
	leaq	1(,%rbx,2), %r14
	movq	(%rdi,%r14,8), %r15
	movq	%r15, (%rdi,%rbx,8)
	cmpq	%rcx, %r14
	jge	.LBB12_21
.LBB12_13:                              #   in Loop: Header=BB12_10 Depth=2
	leaq	(%r14,%r14), %rbx
	movq	16(%rdi,%rbx,8), %r15
	cmpq	8(%rdi,%rbx,8), %r15
	jb	.LBB12_15
# %bb.14:                               #   in Loop: Header=BB12_10 Depth=2
	leaq	2(,%r14,2), %rbx
	movq	(%rdi,%rbx,8), %r15
	movq	%r15, (%rdi,%r14,8)
	cmpq	%rcx, %rbx
	jl	.LBB12_16
	jmp	.LBB12_22
	.p2align	4, 0x90
.LBB12_15:                              #   in Loop: Header=BB12_10 Depth=2
	leaq	1(,%r14,2), %rbx
	movq	(%rdi,%rbx,8), %r15
	movq	%r15, (%rdi,%r14,8)
	cmpq	%rcx, %rbx
	jge	.LBB12_22
.LBB12_16:                              #   in Loop: Header=BB12_10 Depth=2
	leaq	(%rbx,%rbx), %r14
	movq	16(%rdi,%r14,8), %r15
	cmpq	8(%rdi,%r14,8), %r15
	jb	.LBB12_18
# %bb.17:                               #   in Loop: Header=BB12_10 Depth=2
	leaq	2(,%rbx,2), %r14
	movq	(%rdi,%r14,8), %r15
	movq	%r15, (%rdi,%rbx,8)
	cmpq	%rcx, %r14
	jl	.LBB12_19
	jmp	.LBB12_21
	.p2align	4, 0x90
.LBB12_18:                              #   in Loop: Header=BB12_10 Depth=2
	leaq	1(,%rbx,2), %r14
	movq	(%rdi,%r14,8), %r15
	movq	%r15, (%rdi,%rbx,8)
	cmpq	%rcx, %r14
	jge	.LBB12_21
.LBB12_19:                              #   in Loop: Header=BB12_10 Depth=2
	leaq	(%r14,%r14), %rbx
	movq	16(%rdi,%rbx,8), %r15
	cmpq	8(%rdi,%rbx,8), %r15
	jae	.LBB12_8
# %bb.20:                               #   in Loop: Header=BB12_10 Depth=2
	leaq	1(,%r14,2), %rbx
	movq	(%rdi,%rbx,8), %r15
	movq	%r15, (%rdi,%r14,8)
	cmpq	%rcx, %rbx
	jl	.LBB12_10
	jmp	.LBB12_22
	.p2align	4, 0x90
.LBB12_21:                              #   in Loop: Header=BB12_6 Depth=1
	movq	%r14, %rbx
.LBB12_22:                              #   in Loop: Header=BB12_6 Depth=1
	testq	%rax, %rax
	jne	.LBB12_25
# %bb.23:                               #   in Loop: Header=BB12_6 Depth=1
	cmpq	%r8, %rbx
	jne	.LBB12_25
# %bb.24:                               #   in Loop: Header=BB12_6 Depth=1
	movq	8(%rdi,%r9,8), %rbx
	movq	%rbx, (%rdi,%r8,8)
	movq	%r10, %rbx
.LBB12_25:                              #   in Loop: Header=BB12_6 Depth=1
	testq	%rbx, %rbx
	jle	.LBB12_4
	.p2align	4, 0x90
.LBB12_26:                              #   Parent Loop BB12_6 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	leaq	-1(%rbx), %r14
	movq	%r14, %r15
	shrq	%r15
	movq	(%rdi,%r15,8), %r12
	cmpq	%r11, %r12
	jae	.LBB12_4
# %bb.27:                               #   in Loop: Header=BB12_26 Depth=2
	movq	%r12, (%rdi,%rbx,8)
	movq	%r15, %rbx
	cmpq	$1, %r14
	ja	.LBB12_26
# %bb.28:                               #   in Loop: Header=BB12_6 Depth=1
	xorl	%ebx, %ebx
	jmp	.LBB12_4
.LBB12_29:
	leaq	-2(%rcx), %r10
	movq	%r10, %r8
	shrq	%r8
	leaq	-1(%rcx), %r9
	shrq	%r9
	testb	$8, %al
	jne	.LBB12_33
# %bb.30:
	orq	$1, %r10
	movq	%r8, %r11
	jmp	.LBB12_56
	.p2align	4, 0x90
.LBB12_31:                              #   in Loop: Header=BB12_33 Depth=1
	movq	%rbx, %r11
.LBB12_32:                              #   in Loop: Header=BB12_33 Depth=1
	movq	%r10, (%rdi,%r11,8)
	subq	$1, %r8
	jb	.LBB12_1
.LBB12_33:                              # =>This Loop Header: Depth=1
                                        #     Child Loop BB12_36 Depth 2
                                        #     Child Loop BB12_49 Depth 2
	movq	(%rdi,%r8,8), %r10
	movq	%r8, %r11
	cmpq	%r8, %r9
	jle	.LBB12_32
# %bb.34:                               #   in Loop: Header=BB12_33 Depth=1
	movq	%r8, %r11
	jmp	.LBB12_36
	.p2align	4, 0x90
.LBB12_35:                              #   in Loop: Header=BB12_36 Depth=2
	leaq	2(,%rbx,2), %r11
	movq	(%rdi,%r11,8), %r14
	movq	%r14, (%rdi,%rbx,8)
	cmpq	%r9, %r11
	jge	.LBB12_49
.LBB12_36:                              #   Parent Loop BB12_33 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	leaq	(%r11,%r11), %rbx
	movq	16(%rdi,%rbx,8), %r14
	cmpq	8(%rdi,%rbx,8), %r14
	jb	.LBB12_38
# %bb.37:                               #   in Loop: Header=BB12_36 Depth=2
	leaq	2(,%r11,2), %rbx
	movq	(%rdi,%rbx,8), %r14
	movq	%r14, (%rdi,%r11,8)
	cmpq	%r9, %rbx
	jl	.LBB12_39
	jmp	.LBB12_47
	.p2align	4, 0x90
.LBB12_38:                              #   in Loop: Header=BB12_36 Depth=2
	leaq	1(,%r11,2), %rbx
	movq	(%rdi,%rbx,8), %r14
	movq	%r14, (%rdi,%r11,8)
	cmpq	%r9, %rbx
	jge	.LBB12_47
.LBB12_39:                              #   in Loop: Header=BB12_36 Depth=2
	leaq	(%rbx,%rbx), %r11
	movq	16(%rdi,%r11,8), %r14
	cmpq	8(%rdi,%r11,8), %r14
	jb	.LBB12_41
# %bb.40:                               #   in Loop: Header=BB12_36 Depth=2
	leaq	2(,%rbx,2), %r11
	movq	(%rdi,%r11,8), %r14
	movq	%r14, (%rdi,%rbx,8)
	cmpq	%r9, %r11
	jl	.LBB12_42
	jmp	.LBB12_49
	.p2align	4, 0x90
.LBB12_41:                              #   in Loop: Header=BB12_36 Depth=2
	leaq	1(,%rbx,2), %r11
	movq	(%rdi,%r11,8), %r14
	movq	%r14, (%rdi,%rbx,8)
	cmpq	%r9, %r11
	jge	.LBB12_49
.LBB12_42:                              #   in Loop: Header=BB12_36 Depth=2
	leaq	(%r11,%r11), %rbx
	movq	16(%rdi,%rbx,8), %r14
	cmpq	8(%rdi,%rbx,8), %r14
	jb	.LBB12_44
# %bb.43:                               #   in Loop: Header=BB12_36 Depth=2
	leaq	2(,%r11,2), %rbx
	movq	(%rdi,%rbx,8), %r14
	movq	%r14, (%rdi,%r11,8)
	cmpq	%r9, %rbx
	jl	.LBB12_45
	jmp	.LBB12_48
	.p2align	4, 0x90
.LBB12_44:                              #   in Loop: Header=BB12_36 Depth=2
	leaq	1(,%r11,2), %rbx
	movq	(%rdi,%rbx,8), %r14
	movq	%r14, (%rdi,%r11,8)
	cmpq	%r9, %rbx
	jge	.LBB12_48
.LBB12_45:                              #   in Loop: Header=BB12_36 Depth=2
	leaq	(%rbx,%rbx), %r11
	movq	16(%rdi,%r11,8), %r14
	cmpq	8(%rdi,%r11,8), %r14
	jae	.LBB12_35
# %bb.46:                               #   in Loop: Header=BB12_36 Depth=2
	leaq	1(,%rbx,2), %r11
	movq	(%rdi,%r11,8), %r14
	movq	%r14, (%rdi,%rbx,8)
	cmpq	%r9, %r11
	jl	.LBB12_36
	jmp	.LBB12_49
.LBB12_47:                              #   in Loop: Header=BB12_33 Depth=1
	movq	%rbx, %r11
	jmp	.LBB12_49
.LBB12_48:                              #   in Loop: Header=BB12_33 Depth=1
	movq	%rbx, %r11
	.p2align	4, 0x90
.LBB12_49:                              #   Parent Loop BB12_33 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	leaq	-1(%r11), %rbx
	shrq	$63, %rbx
	addq	%r11, %rbx
	decq	%rbx
	sarq	%rbx
	movq	(%rdi,%rbx,8), %r14
	cmpq	%r10, %r14
	jae	.LBB12_32
# %bb.50:                               #   in Loop: Header=BB12_49 Depth=2
	movq	%r14, (%rdi,%r11,8)
	cmpq	%r8, %rbx
	jle	.LBB12_31
# %bb.51:                               #   in Loop: Header=BB12_49 Depth=2
	leaq	-1(%rbx), %r11
	shrq	$63, %r11
	addq	%rbx, %r11
	decq	%r11
	sarq	%r11
	movq	(%rdi,%r11,8), %r14
	cmpq	%r10, %r14
	jae	.LBB12_31
# %bb.52:                               #   in Loop: Header=BB12_49 Depth=2
	movq	%r14, (%rdi,%rbx,8)
	cmpq	%r8, %r11
	jg	.LBB12_49
	jmp	.LBB12_32
	.p2align	4, 0x90
.LBB12_54:                              #   in Loop: Header=BB12_56 Depth=1
	movq	%r15, %r14
.LBB12_55:                              #   in Loop: Header=BB12_56 Depth=1
	movq	%rbx, (%rdi,%r14,8)
	subq	$1, %r11
	jb	.LBB12_1
.LBB12_56:                              # =>This Loop Header: Depth=1
                                        #     Child Loop BB12_60 Depth 2
                                        #     Child Loop BB12_74 Depth 2
	movq	(%rdi,%r11,8), %rbx
	movq	%r11, %r14
	cmpq	%r11, %r9
	jle	.LBB12_72
# %bb.57:                               #   in Loop: Header=BB12_56 Depth=1
	movq	%r11, %r14
	jmp	.LBB12_60
	.p2align	4, 0x90
.LBB12_58:                              #   in Loop: Header=BB12_60 Depth=2
	leaq	2(,%r15,2), %r14
	movq	(%rdi,%r14,8), %r12
	movq	%r12, (%rdi,%r15,8)
	cmpq	%r9, %r14
	jge	.LBB12_72
.LBB12_60:                              #   Parent Loop BB12_56 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	leaq	(%r14,%r14), %r15
	movq	16(%rdi,%r15,8), %r12
	cmpq	8(%rdi,%r15,8), %r12
	jb	.LBB12_62
# %bb.61:                               #   in Loop: Header=BB12_60 Depth=2
	leaq	2(,%r14,2), %r15
	movq	(%rdi,%r15,8), %r12
	movq	%r12, (%rdi,%r14,8)
	cmpq	%r9, %r15
	jl	.LBB12_63
	jmp	.LBB12_71
	.p2align	4, 0x90
.LBB12_62:                              #   in Loop: Header=BB12_60 Depth=2
	leaq	1(,%r14,2), %r15
	movq	(%rdi,%r15,8), %r12
	movq	%r12, (%rdi,%r14,8)
	cmpq	%r9, %r15
	jge	.LBB12_71
.LBB12_63:                              #   in Loop: Header=BB12_60 Depth=2
	leaq	(%r15,%r15), %r14
	movq	16(%rdi,%r14,8), %r12
	cmpq	8(%rdi,%r14,8), %r12
	jb	.LBB12_65
# %bb.64:                               #   in Loop: Header=BB12_60 Depth=2
	leaq	2(,%r15,2), %r14
	movq	(%rdi,%r14,8), %r12
	movq	%r12, (%rdi,%r15,8)
	cmpq	%r9, %r14
	jl	.LBB12_66
	jmp	.LBB12_72
	.p2align	4, 0x90
.LBB12_65:                              #   in Loop: Header=BB12_60 Depth=2
	leaq	1(,%r15,2), %r14
	movq	(%rdi,%r14,8), %r12
	movq	%r12, (%rdi,%r15,8)
	cmpq	%r9, %r14
	jge	.LBB12_72
.LBB12_66:                              #   in Loop: Header=BB12_60 Depth=2
	leaq	(%r14,%r14), %r15
	movq	16(%rdi,%r15,8), %r12
	cmpq	8(%rdi,%r15,8), %r12
	jb	.LBB12_68
# %bb.67:                               #   in Loop: Header=BB12_60 Depth=2
	leaq	2(,%r14,2), %r15
	movq	(%rdi,%r15,8), %r12
	movq	%r12, (%rdi,%r14,8)
	cmpq	%r9, %r15
	jl	.LBB12_69
	jmp	.LBB12_79
	.p2align	4, 0x90
.LBB12_68:                              #   in Loop: Header=BB12_60 Depth=2
	leaq	1(,%r14,2), %r15
	movq	(%rdi,%r15,8), %r12
	movq	%r12, (%rdi,%r14,8)
	cmpq	%r9, %r15
	jge	.LBB12_79
.LBB12_69:                              #   in Loop: Header=BB12_60 Depth=2
	leaq	(%r15,%r15), %r14
	movq	16(%rdi,%r14,8), %r12
	cmpq	8(%rdi,%r14,8), %r12
	jae	.LBB12_58
# %bb.70:                               #   in Loop: Header=BB12_60 Depth=2
	leaq	1(,%r15,2), %r14
	movq	(%rdi,%r14,8), %r12
	movq	%r12, (%rdi,%r15,8)
	cmpq	%r9, %r14
	jl	.LBB12_60
	jmp	.LBB12_72
.LBB12_71:                              #   in Loop: Header=BB12_56 Depth=1
	movq	%r15, %r14
	.p2align	4, 0x90
.LBB12_72:                              #   in Loop: Header=BB12_56 Depth=1
	cmpq	%r8, %r14
	jne	.LBB12_74
.LBB12_73:                              #   in Loop: Header=BB12_56 Depth=1
	movq	(%rdi,%r10,8), %r14
	movq	%r14, (%rdi,%r8,8)
	movq	%r10, %r14
	.p2align	4, 0x90
.LBB12_74:                              #   Parent Loop BB12_56 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	cmpq	%r11, %r14
	jle	.LBB12_55
# %bb.75:                               #   in Loop: Header=BB12_74 Depth=2
	leaq	-1(%r14), %r15
	shrq	$63, %r15
	addq	%r14, %r15
	decq	%r15
	sarq	%r15
	movq	(%rdi,%r15,8), %r12
	cmpq	%rbx, %r12
	jae	.LBB12_55
# %bb.76:                               #   in Loop: Header=BB12_74 Depth=2
	movq	%r12, (%rdi,%r14,8)
	cmpq	%r11, %r15
	jle	.LBB12_54
# %bb.77:                               #   in Loop: Header=BB12_74 Depth=2
	leaq	-1(%r15), %r14
	shrq	$63, %r14
	addq	%r15, %r14
	decq	%r14
	sarq	%r14
	movq	(%rdi,%r14,8), %r12
	cmpq	%rbx, %r12
	jae	.LBB12_54
# %bb.78:                               #   in Loop: Header=BB12_74 Depth=2
	movq	%r12, (%rdi,%r15,8)
	jmp	.LBB12_74
.LBB12_79:                              #   in Loop: Header=BB12_56 Depth=1
	movq	%r15, %r14
	cmpq	%r8, %r14
	jne	.LBB12_74
	jmp	.LBB12_73
.LBB12_81:
	testq	%rax, %rax
	je	.LBB12_88
# %bb.82:
	leaq	8(%rsi), %r8
	cmpq	%r8, %rdx
	cmovaq	%rdx, %r8
	movq	(%rdi), %rdx
	subq	%rsi, %r8
	leaq	-1(%r8), %rcx
	movq	%rcx, %rax
	shrq	$3, %rax
	andq	$-8, %rcx
	addq	%rsi, %rcx
	cmpq	%rdi, %rcx
	jb	.LBB12_95
# %bb.83:
	cmpq	%rsi, %rdi
	jb	.LBB12_95
# %bb.84:
	incq	%rax
	xorl	%ecx, %ecx
	jmp	.LBB12_86
	.p2align	4, 0x90
.LBB12_85:                              #   in Loop: Header=BB12_86 Depth=1
	incq	%rcx
	cmpq	%rcx, %rax
	je	.LBB12_149
.LBB12_86:                              # =>This Inner Loop Header: Depth=1
	movq	(%rsi,%rcx,8), %r8
	cmpq	%rdx, %r8
	jae	.LBB12_85
# %bb.87:                               #   in Loop: Header=BB12_86 Depth=1
	movq	%rdx, (%rsi,%rcx,8)
	movq	%r8, (%rdi)
	movq	%r8, %rdx
	jmp	.LBB12_85
.LBB12_88:
	testq	%r8, %r8
	je	.LBB12_119
# %bb.89:
	leaq	8(%rsi), %r8
	cmpq	%r8, %rdx
	cmovaq	%rdx, %r8
	movq	(%rdi), %rdx
	subq	%rsi, %r8
	leaq	-1(%r8), %rcx
	movq	%rcx, %rax
	shrq	$3, %rax
	andq	$-8, %rcx
	addq	%rsi, %rcx
	cmpq	%rdi, %rcx
	jb	.LBB12_125
# %bb.90:
	cmpq	%rsi, %rdi
	jb	.LBB12_125
# %bb.91:
	incq	%rax
	xorl	%ecx, %ecx
	jmp	.LBB12_93
	.p2align	4, 0x90
.LBB12_92:                              #   in Loop: Header=BB12_93 Depth=1
	incq	%rcx
	cmpq	%rcx, %rax
	je	.LBB12_149
.LBB12_93:                              # =>This Inner Loop Header: Depth=1
	movq	(%rsi,%rcx,8), %r8
	cmpq	%rdx, %r8
	jae	.LBB12_92
# %bb.94:                               #   in Loop: Header=BB12_93 Depth=1
	movq	%rdx, (%rsi,%rcx,8)
	movq	%r8, (%rdi)
	movq	%r8, %rdx
	jmp	.LBB12_92
.LBB12_95:
	addq	$7, %r8
	movq	%r8, %rcx
	shrq	$6, %rcx
	cmpq	$64, %r8
	jb	.LBB12_114
# %bb.96:
	leaq	56(%rsi), %r9
	movq	%rcx, %r10
	jmp	.LBB12_98
	.p2align	4, 0x90
.LBB12_97:                              #   in Loop: Header=BB12_98 Depth=1
	movq	%r11, (%r9)
	movq	%rdx, (%rdi)
	addq	$64, %r9
	decq	%r10
	je	.LBB12_114
.LBB12_98:                              # =>This Inner Loop Header: Depth=1
	movq	-56(%r9), %r11
	cmpq	%rdx, %r11
	jae	.LBB12_106
# %bb.99:                               #   in Loop: Header=BB12_98 Depth=1
	movq	%rdx, -56(%r9)
	movq	%r11, (%rdi)
	movq	-48(%r9), %rdx
	cmpq	%r11, %rdx
	jb	.LBB12_107
.LBB12_100:                             #   in Loop: Header=BB12_98 Depth=1
	movq	%r11, %rdx
	movq	-40(%r9), %r11
	cmpq	%rdx, %r11
	jb	.LBB12_108
.LBB12_101:                             #   in Loop: Header=BB12_98 Depth=1
	movq	%rdx, %r11
	movq	-32(%r9), %rdx
	cmpq	%r11, %rdx
	jb	.LBB12_109
.LBB12_102:                             #   in Loop: Header=BB12_98 Depth=1
	movq	%r11, %rdx
	movq	-24(%r9), %r11
	cmpq	%rdx, %r11
	jb	.LBB12_110
.LBB12_103:                             #   in Loop: Header=BB12_98 Depth=1
	movq	%rdx, %r11
	movq	-16(%r9), %rdx
	cmpq	%r11, %rdx
	jb	.LBB12_111
.LBB12_104:                             #   in Loop: Header=BB12_98 Depth=1
	movq	%r11, %rdx
	movq	-8(%r9), %r11
	cmpq	%rdx, %r11
	jb	.LBB12_112
.LBB12_105:                             #   in Loop: Header=BB12_98 Depth=1
	movq	%rdx, %r11
	movq	(%r9), %rdx
	cmpq	%r11, %rdx
	jb	.LBB12_97
	jmp	.LBB12_113
	.p2align	4, 0x90
.LBB12_106:                             #   in Loop: Header=BB12_98 Depth=1
	movq	%rdx, %r11
	movq	-48(%r9), %rdx
	cmpq	%r11, %rdx
	jae	.LBB12_100
.LBB12_107:                             #   in Loop: Header=BB12_98 Depth=1
	movq	%r11, -48(%r9)
	movq	%rdx, (%rdi)
	movq	-40(%r9), %r11
	cmpq	%rdx, %r11
	jae	.LBB12_101
.LBB12_108:                             #   in Loop: Header=BB12_98 Depth=1
	movq	%rdx, -40(%r9)
	movq	%r11, (%rdi)
	movq	-32(%r9), %rdx
	cmpq	%r11, %rdx
	jae	.LBB12_102
.LBB12_109:                             #   in Loop: Header=BB12_98 Depth=1
	movq	%r11, -32(%r9)
	movq	%rdx, (%rdi)
	movq	-24(%r9), %r11
	cmpq	%rdx, %r11
	jae	.LBB12_103
.LBB12_110:                             #   in Loop: Header=BB12_98 Depth=1
	movq	%rdx, -24(%r9)
	movq	%r11, (%rdi)
	movq	-16(%r9), %rdx
	cmpq	%r11, %rdx
	jae	.LBB12_104
.LBB12_111:                             #   in Loop: Header=BB12_98 Depth=1
	movq	%r11, -16(%r9)
	movq	%rdx, (%rdi)
	movq	-8(%r9), %r11
	cmpq	%rdx, %r11
	jae	.LBB12_105
.LBB12_112:                             #   in Loop: Header=BB12_98 Depth=1
	movq	%rdx, -8(%r9)
	movq	%r11, (%rdi)
	movq	(%r9), %rdx
	cmpq	%r11, %rdx
	jb	.LBB12_97
.LBB12_113:                             #   in Loop: Header=BB12_98 Depth=1
	movq	%r11, %rdx
	addq	$64, %r9
	decq	%r10
	jne	.LBB12_98
.LBB12_114:
	shlq	$3, %rcx
	shrq	$3, %r8
	cmpq	%r8, %rcx
	jae	.LBB12_149
# %bb.115:
	incq	%rax
	jmp	.LBB12_117
	.p2align	4, 0x90
.LBB12_116:                             #   in Loop: Header=BB12_117 Depth=1
	incq	%rcx
	cmpq	%rcx, %rax
	je	.LBB12_149
.LBB12_117:                             # =>This Inner Loop Header: Depth=1
	movq	(%rsi,%rcx,8), %r8
	cmpq	%rdx, %r8
	jae	.LBB12_116
# %bb.118:                              #   in Loop: Header=BB12_117 Depth=1
	movq	%rdx, (%rsi,%rcx,8)
	movq	%r8, (%rdi)
	movq	%r8, %rdx
	jmp	.LBB12_116
.LBB12_119:
	leaq	8(%rsi), %rax
	cmpq	%rax, %rdx
	cmovaq	%rdx, %rax
	subq	%rsi, %rax
	leaq	7(%rax), %rdx
	movq	%rdx, %rcx
	shrq	$5, %rcx
	cmpq	$32, %rdx
	jae	.LBB12_150
.LBB12_120:
	shlq	$2, %rcx
	shrq	$3, %rdx
	cmpq	%rdx, %rcx
	jae	.LBB12_149
# %bb.121:
	decq	%rax
	shrq	$3, %rax
	incq	%rax
	jmp	.LBB12_123
	.p2align	4, 0x90
.LBB12_122:                             #   in Loop: Header=BB12_123 Depth=1
	incq	%rcx
	cmpq	%rcx, %rax
	je	.LBB12_149
.LBB12_123:                             # =>This Inner Loop Header: Depth=1
	movq	(%rsi,%rcx,8), %rdx
	movq	(%rdi), %r8
	cmpq	%r8, %rdx
	jae	.LBB12_122
# %bb.124:                              #   in Loop: Header=BB12_123 Depth=1
	movq	%r8, (%rsi,%rcx,8)
	movq	8(%rdi), %r8
	movq	%r8, (%rdi)
	xorl	%r9d, %r9d
	cmpq	%rdx, %r8
	setae	%r9b
	movq	%rdx, (%rdi,%r9,8)
	jmp	.LBB12_122
.LBB12_125:
	addq	$7, %r8
	movq	%r8, %rcx
	shrq	$6, %rcx
	cmpq	$64, %r8
	jb	.LBB12_144
# %bb.126:
	leaq	56(%rsi), %r9
	movq	%rcx, %r10
	jmp	.LBB12_128
	.p2align	4, 0x90
.LBB12_127:                             #   in Loop: Header=BB12_128 Depth=1
	movq	%r11, (%r9)
	movq	%rdx, (%rdi)
	addq	$64, %r9
	decq	%r10
	je	.LBB12_144
.LBB12_128:                             # =>This Inner Loop Header: Depth=1
	movq	-56(%r9), %r11
	cmpq	%rdx, %r11
	jae	.LBB12_136
# %bb.129:                              #   in Loop: Header=BB12_128 Depth=1
	movq	%rdx, -56(%r9)
	movq	%r11, (%rdi)
	movq	-48(%r9), %rdx
	cmpq	%r11, %rdx
	jb	.LBB12_137
.LBB12_130:                             #   in Loop: Header=BB12_128 Depth=1
	movq	%r11, %rdx
	movq	-40(%r9), %r11
	cmpq	%rdx, %r11
	jb	.LBB12_138
.LBB12_131:                             #   in Loop: Header=BB12_128 Depth=1
	movq	%rdx, %r11
	movq	-32(%r9), %rdx
	cmpq	%r11, %rdx
	jb	.LBB12_139
.LBB12_132:                             #   in Loop: Header=BB12_128 Depth=1
	movq	%r11, %rdx
	movq	-24(%r9), %r11
	cmpq	%rdx, %r11
	jb	.LBB12_140
.LBB12_133:                             #   in Loop: Header=BB12_128 Depth=1
	movq	%rdx, %r11
	movq	-16(%r9), %rdx
	cmpq	%r11, %rdx
	jb	.LBB12_141
.LBB12_134:                             #   in Loop: Header=BB12_128 Depth=1
	movq	%r11, %rdx
	movq	-8(%r9), %r11
	cmpq	%rdx, %r11
	jb	.LBB12_142
.LBB12_135:                             #   in Loop: Header=BB12_128 Depth=1
	movq	%rdx, %r11
	movq	(%r9), %rdx
	cmpq	%r11, %rdx
	jb	.LBB12_127
	jmp	.LBB12_143
	.p2align	4, 0x90
.LBB12_136:                             #   in Loop: Header=BB12_128 Depth=1
	movq	%rdx, %r11
	movq	-48(%r9), %rdx
	cmpq	%r11, %rdx
	jae	.LBB12_130
.LBB12_137:                             #   in Loop: Header=BB12_128 Depth=1
	movq	%r11, -48(%r9)
	movq	%rdx, (%rdi)
	movq	-40(%r9), %r11
	cmpq	%rdx, %r11
	jae	.LBB12_131
.LBB12_138:                             #   in Loop: Header=BB12_128 Depth=1
	movq	%rdx, -40(%r9)
	movq	%r11, (%rdi)
	movq	-32(%r9), %rdx
	cmpq	%r11, %rdx
	jae	.LBB12_132
.LBB12_139:                             #   in Loop: Header=BB12_128 Depth=1
	movq	%r11, -32(%r9)
	movq	%rdx, (%rdi)
	movq	-24(%r9), %r11
	cmpq	%rdx, %r11
	jae	.LBB12_133
.LBB12_140:                             #   in Loop: Header=BB12_128 Depth=1
	movq	%rdx, -24(%r9)
	movq	%r11, (%rdi)
	movq	-16(%r9), %rdx
	cmpq	%r11, %rdx
	jae	.LBB12_134
.LBB12_141:                             #   in Loop: Header=BB12_128 Depth=1
	movq	%r11, -16(%r9)
	movq	%rdx, (%rdi)
	movq	-8(%r9), %r11
	cmpq	%rdx, %r11
	jae	.LBB12_135
.LBB12_142:                             #   in Loop: Header=BB12_128 Depth=1
	movq	%rdx, -8(%r9)
	movq	%r11, (%rdi)
	movq	(%r9), %rdx
	cmpq	%r11, %rdx
	jb	.LBB12_127
.LBB12_143:                             #   in Loop: Header=BB12_128 Depth=1
	movq	%r11, %rdx
	addq	$64, %r9
	decq	%r10
	jne	.LBB12_128
.LBB12_144:
	shlq	$3, %rcx
	shrq	$3, %r8
	cmpq	%r8, %rcx
	jae	.LBB12_149
# %bb.145:
	incq	%rax
	jmp	.LBB12_147
	.p2align	4, 0x90
.LBB12_146:                             #   in Loop: Header=BB12_147 Depth=1
	incq	%rcx
	cmpq	%rcx, %rax
	je	.LBB12_149
.LBB12_147:                             # =>This Inner Loop Header: Depth=1
	movq	(%rsi,%rcx,8), %r8
	cmpq	%rdx, %r8
	jae	.LBB12_146
# %bb.148:                              #   in Loop: Header=BB12_147 Depth=1
	movq	%rdx, (%rsi,%rcx,8)
	movq	%r8, (%rdi)
	movq	%r8, %rdx
	jmp	.LBB12_146
.LBB12_149:
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	retq
.LBB12_150:
	.cfi_def_cfa_offset 40
	leaq	24(%rsi), %r8
	movq	%rcx, %r9
	jmp	.LBB12_152
	.p2align	4, 0x90
.LBB12_151:                             #   in Loop: Header=BB12_152 Depth=1
	addq	$32, %r8
	decq	%r9
	je	.LBB12_120
.LBB12_152:                             # =>This Inner Loop Header: Depth=1
	movq	-24(%r8), %r11
	movq	(%rdi), %r10
	cmpq	%r10, %r11
	jae	.LBB12_153
# %bb.156:                              #   in Loop: Header=BB12_152 Depth=1
	movq	%r10, -24(%r8)
	movq	8(%rdi), %r10
	movq	%r10, (%rdi)
	xorl	%ebx, %ebx
	cmpq	%r11, %r10
	setae	%bl
	movq	%r11, (%rdi,%rbx,8)
	movq	(%rdi), %r10
	movq	-16(%r8), %r11
	cmpq	%r10, %r11
	jb	.LBB12_157
.LBB12_154:                             #   in Loop: Header=BB12_152 Depth=1
	movq	-8(%r8), %r11
	cmpq	%r10, %r11
	jae	.LBB12_155
.LBB12_158:                             #   in Loop: Header=BB12_152 Depth=1
	movq	%r10, -8(%r8)
	movq	8(%rdi), %r10
	movq	%r10, (%rdi)
	xorl	%ebx, %ebx
	cmpq	%r11, %r10
	setae	%bl
	movq	%r11, (%rdi,%rbx,8)
	movq	(%rdi), %r10
	movq	(%r8), %r11
	cmpq	%r10, %r11
	jae	.LBB12_151
	jmp	.LBB12_159
	.p2align	4, 0x90
.LBB12_153:                             #   in Loop: Header=BB12_152 Depth=1
	movq	-16(%r8), %r11
	cmpq	%r10, %r11
	jae	.LBB12_154
.LBB12_157:                             #   in Loop: Header=BB12_152 Depth=1
	movq	%r10, -16(%r8)
	movq	8(%rdi), %r10
	movq	%r10, (%rdi)
	xorl	%ebx, %ebx
	cmpq	%r11, %r10
	setae	%bl
	movq	%r11, (%rdi,%rbx,8)
	movq	(%rdi), %r10
	movq	-8(%r8), %r11
	cmpq	%r10, %r11
	jb	.LBB12_158
.LBB12_155:                             #   in Loop: Header=BB12_152 Depth=1
	movq	(%r8), %r11
	cmpq	%r10, %r11
	jae	.LBB12_151
.LBB12_159:                             #   in Loop: Header=BB12_152 Depth=1
	movq	%r10, (%r8)
	movq	8(%rdi), %r10
	movq	%r10, (%rdi)
	xorl	%ebx, %ebx
	cmpq	%r11, %r10
	setae	%bl
	movq	%r11, (%rdi,%rbx,8)
	jmp	.LBB12_151
.Lfunc_end12:
	.size	_ZSt13__heap_selectIN9__gnu_cxx17__normal_iteratorIPmSt6vectorImSaImEEEENS0_5__ops15_Iter_less_iterEEvT_S9_S9_T0_, .Lfunc_end12-_ZSt13__heap_selectIN9__gnu_cxx17__normal_iteratorIPmSt6vectorImSaImEEEENS0_5__ops15_Iter_less_iterEEvT_S9_S9_T0_
	.cfi_endproc
                                        # -- End function
	.section	.text.startup,"ax",@progbits
	.p2align	4, 0x90                         # -- Begin function _GLOBAL__sub_I_aes256ni_driver.cpp
	.type	_GLOBAL__sub_I_aes256ni_driver.cpp,@function
_GLOBAL__sub_I_aes256ni_driver.cpp:     # 
	.cfi_startproc
# %bb.0:
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset %rbx, -16
	leaq	_ZStL8__ioinit(%rip), %rbx
	movq	%rbx, %rdi
	callq	_ZNSt8ios_base4InitC1Ev@PLT
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rdi
	leaq	__dso_handle(%rip), %rdx
	movq	%rbx, %rsi
	popq	%rbx
	.cfi_def_cfa_offset 8
	jmp	__cxa_atexit@PLT                # TAILCALL
.Lfunc_end13:
	.size	_GLOBAL__sub_I_aes256ni_driver.cpp, .Lfunc_end13-_GLOBAL__sub_I_aes256ni_driver.cpp
	.cfi_endproc
                                        # -- End function
	.type	_ZStL8__ioinit,@object          # 
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.type	.L.str,@object                  # 
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"CheckText\n"
	.size	.L.str, 11

	.type	.L.str.1,@object                # 
.L.str.1:
	.asciz	"EncryptTime"
	.size	.L.str.1, 12

	.type	.L.str.2,@object                # 
.L.str.2:
	.asciz	"DecryptTime"
	.size	.L.str.2, 12

	.type	.L.str.3,@object                # 
.L.str.3:
	.asciz	"Random 32-byte Key: "
	.size	.L.str.3, 21

	.type	.L.str.4,@object                # 
.L.str.4:
	.asciz	"Starting Excryption/Decryption for "
	.size	.L.str.4, 36

	.type	.L.str.5,@object                # 
.L.str.5:
	.asciz	" times..."
	.size	.L.str.5, 10

	.type	_ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj,@object # 
	.section	.bss._ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj,"aGw",@nobits,_ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj,comdat
	.weak	_ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj
	.p2align	3, 0x0
_ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj:
	.quad	0
	.size	_ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj, 8

	.type	.L.str.6,@object                # 
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str.6:
	.asciz	"CpuProfiler Constructor Called.\n"
	.size	.L.str.6, 33

	.type	.L.str.8,@object                # 
.L.str.8:
	.asciz	"Deleting old data files...\n"
	.size	.L.str.8, 28

	.type	.L.str.9,@object                # 
.L.str.9:
	.asciz	"cpuProfilerOutput_"
	.size	.L.str.9, 19

	.type	.L.str.10,@object               # 
.L.str.10:
	.asciz	".txt"
	.size	.L.str.10, 5

	.type	.L.str.11,@object               # 
.L.str.11:
	.asciz	"basic_string::append"
	.size	.L.str.11, 21

	.type	.L.str.12,@object               # 
.L.str.12:
	.asciz	"%d "
	.size	.L.str.12, 4

	.type	.L.str.13,@object               # 
.L.str.13:
	.asciz	"\n"
	.size	.L.str.13, 2

	.type	.L.str.14,@object               # 
.L.str.14:
	.asciz	"Tag "
	.size	.L.str.14, 5

	.type	.L.str.15,@object               # 
.L.str.15:
	.asciz	" not found...\n"
	.size	.L.str.15, 15

	.type	.L.str.16,@object               # 
.L.str.16:
	.asciz	"_Map_base::at"
	.size	.L.str.16, 14

	.type	.L.str.17,@object               # 
.L.str.17:
	.asciz	"ERROR: counter for tag "
	.size	.L.str.17, 24

	.type	.L.str.18,@object               # 
.L.str.18:
	.asciz	" not started\n"
	.size	.L.str.18, 14

	.type	.L.str.19,@object               # 
.L.str.19:
	.asciz	"vector::_M_realloc_insert"
	.size	.L.str.19, 26

	.type	.L.str.20,@object               # 
.L.str.20:
	.asciz	":: "
	.size	.L.str.20, 4

	.type	.L.str.21,@object               # 
.L.str.21:
	.asciz	" Mean: "
	.size	.L.str.21, 8

	.type	.L.str.22,@object               # 
.L.str.22:
	.asciz	" Median: "
	.size	.L.str.22, 10

	.type	.L.str.23,@object               # 
.L.str.23:
	.asciz	" 90th: "
	.size	.L.str.23, 8

	.type	.L.str.24,@object               # 
.L.str.24:
	.asciz	" 95th: "
	.size	.L.str.24, 8

	.type	.L.str.25,@object               # 
.L.str.25:
	.asciz	" 99th: "
	.size	.L.str.25, 8

	.type	.L.str.26,@object               # 
.L.str.26:
	.asciz	" 99.9th: "
	.size	.L.str.26, 10

	.type	.L.str.27,@object               # 
.L.str.27:
	.asciz	" Min: "
	.size	.L.str.27, 7

	.type	.L.str.28,@object               # 
.L.str.28:
	.asciz	" Max: "
	.size	.L.str.28, 7

	.type	.L.str.29,@object               # 
.L.str.29:
	.asciz	" Count: "
	.size	.L.str.29, 9

	.section	.init_array,"aw",@init_array
	.p2align	3, 0x90
	.quad	_GLOBAL__sub_I_aes256ni_driver.cpp
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.DW.ref.__gxx_personality_v0,"aGw",@progbits,DW.ref.__gxx_personality_v0,comdat
	.p2align	3, 0x0
	.type	DW.ref.__gxx_personality_v0,@object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.ident	"Intel(R) oneAPI DPC++/C++ Compiler 2024.0.0 (2024.0.0.20231017)"
	.section	".note.GNU-stack","",@progbits
