	.text
	.file	"aes_ni.c"
	.globl	_Z15aes128_load_keyPh           # -- Begin function _Z15aes128_load_keyPh
	.p2align	4, 0x90
	.type	_Z15aes128_load_keyPh,@function
_Z15aes128_load_keyPh:                  # 
	.cfi_startproc
# %bb.0:
	movdqu	(%rdi), %xmm0
	movdqa	%xmm0, _ZL12key_schedule(%rip)
	aeskeygenassist	$1, %xmm0, %xmm1
	pshufd	$255, %xmm1, %xmm1              # xmm1 = xmm1[3,3,3,3]
	movdqa	%xmm0, %xmm2
	pslldq	$4, %xmm2                       # xmm2 = zero,zero,zero,zero,xmm2[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm0, %xmm2
	movdqa	%xmm2, %xmm3
	pslldq	$4, %xmm3                       # xmm3 = zero,zero,zero,zero,xmm3[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm2, %xmm3
	movdqa	%xmm3, %xmm0
	pslldq	$4, %xmm0                       # xmm0 = zero,zero,zero,zero,xmm0[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm3, %xmm0
	pxor	%xmm1, %xmm0
	movdqa	%xmm0, _ZL12key_schedule+16(%rip)
	aeskeygenassist	$2, %xmm0, %xmm1
	pshufd	$255, %xmm1, %xmm2              # xmm2 = xmm1[3,3,3,3]
	movdqa	%xmm0, %xmm1
	pslldq	$4, %xmm1                       # xmm1 = zero,zero,zero,zero,xmm1[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm0, %xmm1
	movdqa	%xmm1, %xmm3
	pslldq	$4, %xmm3                       # xmm3 = zero,zero,zero,zero,xmm3[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm1, %xmm3
	movdqa	%xmm3, %xmm1
	pslldq	$4, %xmm1                       # xmm1 = zero,zero,zero,zero,xmm1[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm3, %xmm1
	pxor	%xmm2, %xmm1
	movdqa	%xmm1, _ZL12key_schedule+32(%rip)
	aeskeygenassist	$4, %xmm1, %xmm2
	pshufd	$255, %xmm2, %xmm3              # xmm3 = xmm2[3,3,3,3]
	movdqa	%xmm1, %xmm2
	pslldq	$4, %xmm2                       # xmm2 = zero,zero,zero,zero,xmm2[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm1, %xmm2
	movdqa	%xmm2, %xmm4
	pslldq	$4, %xmm4                       # xmm4 = zero,zero,zero,zero,xmm4[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm2, %xmm4
	movdqa	%xmm4, %xmm2
	pslldq	$4, %xmm2                       # xmm2 = zero,zero,zero,zero,xmm2[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm4, %xmm2
	pxor	%xmm3, %xmm2
	movdqa	%xmm2, _ZL12key_schedule+48(%rip)
	aeskeygenassist	$8, %xmm2, %xmm3
	pshufd	$255, %xmm3, %xmm4              # xmm4 = xmm3[3,3,3,3]
	movdqa	%xmm2, %xmm3
	pslldq	$4, %xmm3                       # xmm3 = zero,zero,zero,zero,xmm3[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm2, %xmm3
	movdqa	%xmm3, %xmm5
	pslldq	$4, %xmm5                       # xmm5 = zero,zero,zero,zero,xmm5[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm3, %xmm5
	movdqa	%xmm5, %xmm3
	pslldq	$4, %xmm3                       # xmm3 = zero,zero,zero,zero,xmm3[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm5, %xmm3
	pxor	%xmm4, %xmm3
	movdqa	%xmm3, _ZL12key_schedule+64(%rip)
	aeskeygenassist	$16, %xmm3, %xmm4
	pshufd	$255, %xmm4, %xmm5              # xmm5 = xmm4[3,3,3,3]
	movdqa	%xmm3, %xmm4
	pslldq	$4, %xmm4                       # xmm4 = zero,zero,zero,zero,xmm4[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm3, %xmm4
	movdqa	%xmm4, %xmm6
	pslldq	$4, %xmm6                       # xmm6 = zero,zero,zero,zero,xmm6[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm4, %xmm6
	movdqa	%xmm6, %xmm4
	pslldq	$4, %xmm4                       # xmm4 = zero,zero,zero,zero,xmm4[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm6, %xmm4
	pxor	%xmm5, %xmm4
	movdqa	%xmm4, _ZL12key_schedule+80(%rip)
	aeskeygenassist	$32, %xmm4, %xmm5
	pshufd	$255, %xmm5, %xmm6              # xmm6 = xmm5[3,3,3,3]
	movdqa	%xmm4, %xmm5
	pslldq	$4, %xmm5                       # xmm5 = zero,zero,zero,zero,xmm5[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm4, %xmm5
	movdqa	%xmm5, %xmm7
	pslldq	$4, %xmm7                       # xmm7 = zero,zero,zero,zero,xmm7[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm5, %xmm7
	movdqa	%xmm7, %xmm5
	pslldq	$4, %xmm5                       # xmm5 = zero,zero,zero,zero,xmm5[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm7, %xmm5
	pxor	%xmm6, %xmm5
	movdqa	%xmm5, _ZL12key_schedule+96(%rip)
	aeskeygenassist	$64, %xmm5, %xmm6
	pshufd	$255, %xmm6, %xmm7              # xmm7 = xmm6[3,3,3,3]
	movdqa	%xmm5, %xmm6
	pslldq	$4, %xmm6                       # xmm6 = zero,zero,zero,zero,xmm6[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm5, %xmm6
	movdqa	%xmm6, %xmm8
	pslldq	$4, %xmm8                       # xmm8 = zero,zero,zero,zero,xmm8[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm6, %xmm8
	movdqa	%xmm8, %xmm6
	pslldq	$4, %xmm6                       # xmm6 = zero,zero,zero,zero,xmm6[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm8, %xmm6
	pxor	%xmm7, %xmm6
	movdqa	%xmm6, _ZL12key_schedule+112(%rip)
	aeskeygenassist	$128, %xmm6, %xmm7
	pshufd	$255, %xmm7, %xmm8              # xmm8 = xmm7[3,3,3,3]
	movdqa	%xmm6, %xmm7
	pslldq	$4, %xmm7                       # xmm7 = zero,zero,zero,zero,xmm7[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm6, %xmm7
	movdqa	%xmm7, %xmm9
	pslldq	$4, %xmm9                       # xmm9 = zero,zero,zero,zero,xmm9[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm7, %xmm9
	movdqa	%xmm9, %xmm7
	pslldq	$4, %xmm7                       # xmm7 = zero,zero,zero,zero,xmm7[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm9, %xmm7
	pxor	%xmm8, %xmm7
	movdqa	%xmm7, _ZL12key_schedule+128(%rip)
	aeskeygenassist	$27, %xmm7, %xmm8
	pshufd	$255, %xmm8, %xmm8              # xmm8 = xmm8[3,3,3,3]
	movdqa	%xmm7, %xmm9
	pslldq	$4, %xmm9                       # xmm9 = zero,zero,zero,zero,xmm9[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm7, %xmm9
	movdqa	%xmm9, %xmm10
	pslldq	$4, %xmm10                      # xmm10 = zero,zero,zero,zero,xmm10[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm9, %xmm10
	movdqa	%xmm10, %xmm9
	pslldq	$4, %xmm9                       # xmm9 = zero,zero,zero,zero,xmm9[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm10, %xmm9
	pxor	%xmm8, %xmm9
	movdqa	%xmm9, _ZL12key_schedule+144(%rip)
	aeskeygenassist	$54, %xmm9, %xmm8
	pshufd	$255, %xmm8, %xmm8              # xmm8 = xmm8[3,3,3,3]
	movdqa	%xmm9, %xmm10
	pslldq	$4, %xmm10                      # xmm10 = zero,zero,zero,zero,xmm10[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm9, %xmm10
	movdqa	%xmm10, %xmm11
	pslldq	$4, %xmm11                      # xmm11 = zero,zero,zero,zero,xmm11[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm10, %xmm11
	movdqa	%xmm11, %xmm10
	pslldq	$4, %xmm10                      # xmm10 = zero,zero,zero,zero,xmm10[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm11, %xmm10
	pxor	%xmm8, %xmm10
	movdqa	%xmm10, _ZL12key_schedule+160(%rip)
	aesimc	%xmm9, %xmm8
	movdqa	%xmm8, _ZL12key_schedule+176(%rip)
	aesimc	%xmm7, %xmm7
	aesimc	%xmm6, %xmm6
	movdqa	%xmm7, _ZL12key_schedule+192(%rip)
	movdqa	%xmm6, _ZL12key_schedule+208(%rip)
	aesimc	%xmm5, %xmm5
	movdqa	%xmm5, _ZL12key_schedule+224(%rip)
	aesimc	%xmm4, %xmm4
	movdqa	%xmm4, _ZL12key_schedule+240(%rip)
	aesimc	%xmm3, %xmm3
	aesimc	%xmm2, %xmm2
	movdqa	%xmm3, _ZL12key_schedule+256(%rip)
	movdqa	%xmm2, _ZL12key_schedule+272(%rip)
	aesimc	%xmm1, %xmm1
	movdqa	%xmm1, _ZL12key_schedule+288(%rip)
	aesimc	%xmm0, %xmm0
	movdqa	%xmm0, _ZL12key_schedule+304(%rip)
	retq
.Lfunc_end0:
	.size	_Z15aes128_load_keyPh, .Lfunc_end0-_Z15aes128_load_keyPh
	.cfi_endproc
                                        # -- End function
	.globl	_Z10aes128_encPhS_              # -- Begin function _Z10aes128_encPhS_
	.p2align	4, 0x90
	.type	_Z10aes128_encPhS_,@function
_Z10aes128_encPhS_:                     # 
	.cfi_startproc
# %bb.0:
	movdqu	(%rdi), %xmm0
	pxor	_ZL12key_schedule(%rip), %xmm0
	aesenc	_ZL12key_schedule+16(%rip), %xmm0
	aesenc	_ZL12key_schedule+32(%rip), %xmm0
	aesenc	_ZL12key_schedule+48(%rip), %xmm0
	aesenc	_ZL12key_schedule+64(%rip), %xmm0
	aesenc	_ZL12key_schedule+80(%rip), %xmm0
	aesenc	_ZL12key_schedule+96(%rip), %xmm0
	aesenc	_ZL12key_schedule+112(%rip), %xmm0
	aesenc	_ZL12key_schedule+128(%rip), %xmm0
	aesenc	_ZL12key_schedule+144(%rip), %xmm0
	aesenclast	_ZL12key_schedule+160(%rip), %xmm0
	movdqu	%xmm0, (%rsi)
	retq
.Lfunc_end1:
	.size	_Z10aes128_encPhS_, .Lfunc_end1-_Z10aes128_encPhS_
	.cfi_endproc
                                        # -- End function
	.globl	_Z10aes128_decPhS_              # -- Begin function _Z10aes128_decPhS_
	.p2align	4, 0x90
	.type	_Z10aes128_decPhS_,@function
_Z10aes128_decPhS_:                     # 
	.cfi_startproc
# %bb.0:
	movdqu	(%rdi), %xmm0
	pxor	_ZL12key_schedule+160(%rip), %xmm0
	aesdec	_ZL12key_schedule+176(%rip), %xmm0
	aesdec	_ZL12key_schedule+192(%rip), %xmm0
	aesdec	_ZL12key_schedule+208(%rip), %xmm0
	aesdec	_ZL12key_schedule+224(%rip), %xmm0
	aesdec	_ZL12key_schedule+240(%rip), %xmm0
	aesdec	_ZL12key_schedule+256(%rip), %xmm0
	aesdec	_ZL12key_schedule+272(%rip), %xmm0
	aesdec	_ZL12key_schedule+288(%rip), %xmm0
	aesdec	_ZL12key_schedule+304(%rip), %xmm0
	aesdeclast	_ZL12key_schedule(%rip), %xmm0
	movdqu	%xmm0, (%rsi)
	retq
.Lfunc_end2:
	.size	_Z10aes128_decPhS_, .Lfunc_end2-_Z10aes128_decPhS_
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst16,"aM",@progbits,16
	.p2align	4, 0x0                          # -- Begin function main
.LCPI3_0:
	.quad	-6425882231111844309            # 0xa6d2ae2816157e2b
	.quad	4345919805280614315             # 0x3c4fcf098815f7ab
.LCPI3_1:
	.quad	-5708365290994827733            # 0xb0c7d00316157e2b
	.quad	332677726635960232              # 0x49de8a138d227a8
.LCPI3_2:
	.quad	-8273012972482837710            # 0x8d305a88a8f64332
	.quad	3749026652749312305             # 0x340737e0a2983131
.LCPI3_3:
	.quad	-357512793755998919             # 0xfb09dc021d842539
	.quad	3606092584789021148             # 0x320b6a19978511dc
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
	subq	$240, %rsp
	.cfi_def_cfa_offset 288
	.cfi_offset %rbx, -48
	.cfi_offset %r12, -40
	.cfi_offset %r13, -32
	.cfi_offset %r14, -24
	.cfi_offset %r15, -16
	movq	%fs:40, %rax
	movq	%rax, 232(%rsp)
	stmxcsr	144(%rsp)
	orl	$32832, 144(%rsp)               # imm = 0x8040
	ldmxcsr	144(%rsp)
	movq	_ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj(%rip), %r14
	testq	%r14, %r14
	jne	.LBB3_3
# %bb.1:
	movl	$64, %edi
	callq	_Znwm@PLT
	movq	%rax, %r14
	movl	$-1, (%rax)
	leaq	8(%rax), %r15
	addq	$56, %rax
	movq	%rax, 8(%r14)
	movq	$1, 16(%r14)
	pxor	%xmm0, %xmm0
	movdqu	%xmm0, 24(%r14)
	movl	$1065353216, 40(%r14)           # imm = 0x3F800000
	movdqu	%xmm0, 48(%r14)
.Ltmp0:
	movq	_ZSt4cout@GOTPCREL(%rip), %rdi
	leaq	.L.str.3(%rip), %rsi
	movl	$32, %edx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp1:
# %bb.2:
	movq	%r14, _ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj(%rip)
.LBB3_3:
	leaq	216(%rsp), %r15
	movq	%r15, 200(%rsp)
	movabsq	$6085612663396855365, %r13      # imm = 0x5474707972636E45
	movq	%r13, 216(%rsp)
	movl	$1701669204, 223(%rsp)          # imm = 0x656D6954
	movq	$11, 208(%rsp)
	movb	$0, 227(%rsp)
.Ltmp3:
	leaq	200(%rsp), %rsi
	movq	%r14, %rdi
	callq	_ZN11CpuProfiler6addTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
.Ltmp4:
# %bb.4:
	movq	200(%rsp), %rdi
	cmpq	%r15, %rdi
	je	.LBB3_6
# %bb.5:
	callq	_ZdlPv@PLT
.LBB3_6:
	movq	_ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj(%rip), %r14
	testq	%r14, %r14
	jne	.LBB3_9
# %bb.7:
	movl	$64, %edi
	callq	_Znwm@PLT
	movq	%rax, %r14
	movl	$-1, (%rax)
	leaq	8(%rax), %r15
	addq	$56, %rax
	movq	%rax, 8(%r14)
	movq	$1, 16(%r14)
	pxor	%xmm0, %xmm0
	movdqu	%xmm0, 24(%r14)
	movl	$1065353216, 40(%r14)           # imm = 0x3F800000
	movdqu	%xmm0, 48(%r14)
.Ltmp6:
	movq	_ZSt4cout@GOTPCREL(%rip), %rdi
	leaq	.L.str.3(%rip), %rsi
	movl	$32, %edx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp7:
# %bb.8:
	movq	%r14, _ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj(%rip)
.LBB3_9:
	leaq	184(%rsp), %r15
	movq	%r15, 168(%rsp)
	movabsq	$6085612663396853060, %r12      # imm = 0x5474707972636544
	movq	%r12, 184(%rsp)
	movl	$1701669204, 191(%rsp)          # imm = 0x656D6954
	movq	$11, 176(%rsp)
	movb	$0, 195(%rsp)
.Ltmp9:
	leaq	168(%rsp), %rsi
	movq	%r14, %rdi
	callq	_ZN11CpuProfiler6addTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
.Ltmp10:
# %bb.10:
	movq	168(%rsp), %rdi
	cmpq	%r15, %rdi
	je	.LBB3_12
# %bb.11:
	callq	_ZdlPv@PLT
.LBB3_12:
	movdqa	.LCPI3_0(%rip), %xmm1           # xmm1 = [12020861842597707307,4345919805280614315]
	aeskeygenassist	$1, %xmm1, %xmm0
	pshufd	$255, %xmm0, %xmm0              # xmm0 = xmm0[3,3,3,3]
	pxor	.LCPI3_1(%rip), %xmm0
	movdqa	%xmm1, _ZL12key_schedule(%rip)
	movdqa	%xmm0, _ZL12key_schedule+16(%rip)
	aeskeygenassist	$2, %xmm0, %xmm1
	pshufd	$255, %xmm1, %xmm2              # xmm2 = xmm1[3,3,3,3]
	movdqa	%xmm0, %xmm1
	pslldq	$4, %xmm1                       # xmm1 = zero,zero,zero,zero,xmm1[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm0, %xmm1
	movdqa	%xmm1, %xmm3
	pslldq	$4, %xmm3                       # xmm3 = zero,zero,zero,zero,xmm3[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm1, %xmm3
	movdqa	%xmm3, %xmm1
	pslldq	$4, %xmm1                       # xmm1 = zero,zero,zero,zero,xmm1[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm3, %xmm1
	pxor	%xmm2, %xmm1
	movdqa	%xmm1, _ZL12key_schedule+32(%rip)
	aeskeygenassist	$4, %xmm1, %xmm2
	pshufd	$255, %xmm2, %xmm3              # xmm3 = xmm2[3,3,3,3]
	movdqa	%xmm1, %xmm2
	pslldq	$4, %xmm2                       # xmm2 = zero,zero,zero,zero,xmm2[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm1, %xmm2
	movdqa	%xmm2, %xmm4
	pslldq	$4, %xmm4                       # xmm4 = zero,zero,zero,zero,xmm4[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm2, %xmm4
	movdqa	%xmm4, %xmm2
	pslldq	$4, %xmm2                       # xmm2 = zero,zero,zero,zero,xmm2[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm4, %xmm2
	pxor	%xmm3, %xmm2
	movdqa	%xmm2, _ZL12key_schedule+48(%rip)
	aeskeygenassist	$8, %xmm2, %xmm3
	pshufd	$255, %xmm3, %xmm4              # xmm4 = xmm3[3,3,3,3]
	movdqa	%xmm2, %xmm3
	pslldq	$4, %xmm3                       # xmm3 = zero,zero,zero,zero,xmm3[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm2, %xmm3
	movdqa	%xmm3, %xmm5
	pslldq	$4, %xmm5                       # xmm5 = zero,zero,zero,zero,xmm5[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm3, %xmm5
	movdqa	%xmm5, %xmm3
	pslldq	$4, %xmm3                       # xmm3 = zero,zero,zero,zero,xmm3[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm5, %xmm3
	pxor	%xmm4, %xmm3
	movdqa	%xmm3, _ZL12key_schedule+64(%rip)
	aeskeygenassist	$16, %xmm3, %xmm4
	pshufd	$255, %xmm4, %xmm5              # xmm5 = xmm4[3,3,3,3]
	movdqa	%xmm3, %xmm4
	pslldq	$4, %xmm4                       # xmm4 = zero,zero,zero,zero,xmm4[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm3, %xmm4
	movdqa	%xmm4, %xmm6
	pslldq	$4, %xmm6                       # xmm6 = zero,zero,zero,zero,xmm6[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm4, %xmm6
	movdqa	%xmm6, %xmm4
	pslldq	$4, %xmm4                       # xmm4 = zero,zero,zero,zero,xmm4[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm6, %xmm4
	pxor	%xmm5, %xmm4
	movdqa	%xmm4, _ZL12key_schedule+80(%rip)
	aeskeygenassist	$32, %xmm4, %xmm5
	pshufd	$255, %xmm5, %xmm6              # xmm6 = xmm5[3,3,3,3]
	movdqa	%xmm4, %xmm5
	pslldq	$4, %xmm5                       # xmm5 = zero,zero,zero,zero,xmm5[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm4, %xmm5
	movdqa	%xmm5, %xmm7
	pslldq	$4, %xmm7                       # xmm7 = zero,zero,zero,zero,xmm7[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm5, %xmm7
	movdqa	%xmm7, %xmm5
	pslldq	$4, %xmm5                       # xmm5 = zero,zero,zero,zero,xmm5[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm7, %xmm5
	pxor	%xmm6, %xmm5
	movdqa	%xmm5, _ZL12key_schedule+96(%rip)
	aeskeygenassist	$64, %xmm5, %xmm6
	pshufd	$255, %xmm6, %xmm7              # xmm7 = xmm6[3,3,3,3]
	movdqa	%xmm5, %xmm6
	pslldq	$4, %xmm6                       # xmm6 = zero,zero,zero,zero,xmm6[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm5, %xmm6
	movdqa	%xmm6, %xmm8
	pslldq	$4, %xmm8                       # xmm8 = zero,zero,zero,zero,xmm8[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm6, %xmm8
	movdqa	%xmm8, %xmm6
	pslldq	$4, %xmm6                       # xmm6 = zero,zero,zero,zero,xmm6[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm8, %xmm6
	pxor	%xmm7, %xmm6
	movdqa	%xmm6, _ZL12key_schedule+112(%rip)
	aeskeygenassist	$128, %xmm6, %xmm7
	pshufd	$255, %xmm7, %xmm8              # xmm8 = xmm7[3,3,3,3]
	movdqa	%xmm6, %xmm7
	pslldq	$4, %xmm7                       # xmm7 = zero,zero,zero,zero,xmm7[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm6, %xmm7
	movdqa	%xmm7, %xmm9
	pslldq	$4, %xmm9                       # xmm9 = zero,zero,zero,zero,xmm9[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm7, %xmm9
	movdqa	%xmm9, %xmm7
	pslldq	$4, %xmm7                       # xmm7 = zero,zero,zero,zero,xmm7[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm9, %xmm7
	pxor	%xmm8, %xmm7
	movdqa	%xmm7, _ZL12key_schedule+128(%rip)
	aeskeygenassist	$27, %xmm7, %xmm8
	pshufd	$255, %xmm8, %xmm8              # xmm8 = xmm8[3,3,3,3]
	movdqa	%xmm7, %xmm9
	pslldq	$4, %xmm9                       # xmm9 = zero,zero,zero,zero,xmm9[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm7, %xmm9
	movdqa	%xmm9, %xmm10
	pslldq	$4, %xmm10                      # xmm10 = zero,zero,zero,zero,xmm10[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm9, %xmm10
	movdqa	%xmm10, %xmm9
	pslldq	$4, %xmm9                       # xmm9 = zero,zero,zero,zero,xmm9[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm10, %xmm9
	pxor	%xmm8, %xmm9
	movdqa	%xmm9, _ZL12key_schedule+144(%rip)
	aeskeygenassist	$54, %xmm9, %xmm8
	pshufd	$255, %xmm8, %xmm8              # xmm8 = xmm8[3,3,3,3]
	movdqa	%xmm9, %xmm10
	pslldq	$4, %xmm10                      # xmm10 = zero,zero,zero,zero,xmm10[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm9, %xmm10
	movdqa	%xmm10, %xmm11
	pslldq	$4, %xmm11                      # xmm11 = zero,zero,zero,zero,xmm11[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm10, %xmm11
	movdqa	%xmm11, %xmm10
	pslldq	$4, %xmm10                      # xmm10 = zero,zero,zero,zero,xmm10[0,1,2,3,4,5,6,7,8,9,10,11]
	pxor	%xmm11, %xmm10
	pxor	%xmm8, %xmm10
	aesimc	%xmm9, %xmm8
	movdqa	%xmm10, _ZL12key_schedule+160(%rip)
	movdqa	%xmm8, _ZL12key_schedule+176(%rip)
	aesimc	%xmm7, %xmm7
	movdqa	%xmm7, _ZL12key_schedule+192(%rip)
	aesimc	%xmm6, %xmm6
	movdqa	%xmm6, _ZL12key_schedule+208(%rip)
	aesimc	%xmm5, %xmm5
	aesimc	%xmm4, %xmm4
	movdqa	%xmm5, _ZL12key_schedule+224(%rip)
	movdqa	%xmm4, _ZL12key_schedule+240(%rip)
	aesimc	%xmm3, %xmm3
	movdqa	%xmm3, _ZL12key_schedule+256(%rip)
	aesimc	%xmm2, %xmm2
	movdqa	%xmm2, _ZL12key_schedule+272(%rip)
	aesimc	%xmm1, %xmm1
	aesimc	%xmm0, %xmm0
	movdqa	%xmm1, _ZL12key_schedule+288(%rip)
	movdqa	%xmm0, _ZL12key_schedule+304(%rip)
	movq	_ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj(%rip), %r14
	testq	%r14, %r14
	jne	.LBB3_15
# %bb.13:
	movl	$64, %edi
	callq	_Znwm@PLT
	movq	%rax, %r14
	movl	$-1, (%rax)
	leaq	8(%rax), %r15
	addq	$56, %rax
	movq	%rax, 8(%r14)
	movq	$1, 16(%r14)
	pxor	%xmm0, %xmm0
	movdqu	%xmm0, 24(%r14)
	movl	$1065353216, 40(%r14)           # imm = 0x3F800000
	movdqu	%xmm0, 48(%r14)
.Ltmp12:
	movq	_ZSt4cout@GOTPCREL(%rip), %rdi
	leaq	.L.str.3(%rip), %rsi
	movl	$32, %edx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp13:
# %bb.14:
	movq	%r14, _ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj(%rip)
.LBB3_15:
	leaq	112(%rsp), %r15
	movq	%r15, 96(%rsp)
	movq	%r13, 112(%rsp)
	movl	$1701669204, 119(%rsp)          # imm = 0x656D6954
	movq	$11, 104(%rsp)
	movb	$0, 123(%rsp)
	addq	$8, %r14
.Ltmp15:
	leaq	96(%rsp), %rsi
	movq	%r14, %rdi
	callq	_ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEE2atERSD_
.Ltmp16:
# %bb.16:
	movq	(%rax), %rsi
	testq	%rsi, %rsi
	je	.LBB3_18
# %bb.17:
	#APP
	rdtscp
	#NO_APP
                                        # kill: def $edx killed $edx def $rdx
	shlq	$32, %rdx
	movl	%eax, %eax
	orq	%rdx, %rax
	movq	%rax, 32(%rsi)
	jmp	.LBB3_21
.LBB3_18:
.Ltmp17:
	movq	_ZSt4cout@GOTPCREL(%rip), %rdi
	leaq	.L.str.9(%rip), %rsi
	movl	$4, %edx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp18:
# %bb.19:
	movq	96(%rsp), %rsi
	movq	104(%rsp), %rdx
.Ltmp19:
	movq	_ZSt4cout@GOTPCREL(%rip), %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp20:
# %bb.20:
.Ltmp21:
	leaq	.L.str.10(%rip), %rsi
	movl	$14, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp22:
.LBB3_21:
	movq	96(%rsp), %rdi
	cmpq	%r15, %rdi
	je	.LBB3_23
# %bb.22:
	callq	_ZdlPv@PLT
.LBB3_23:
	movdqa	_ZL12key_schedule(%rip), %xmm0
	pxor	.LCPI3_2(%rip), %xmm0
	aesenc	_ZL12key_schedule+16(%rip), %xmm0
	aesenc	_ZL12key_schedule+32(%rip), %xmm0
	aesenc	_ZL12key_schedule+48(%rip), %xmm0
	aesenc	_ZL12key_schedule+64(%rip), %xmm0
	aesenc	_ZL12key_schedule+80(%rip), %xmm0
	aesenc	_ZL12key_schedule+96(%rip), %xmm0
	aesenc	_ZL12key_schedule+112(%rip), %xmm0
	aesenc	_ZL12key_schedule+128(%rip), %xmm0
	aesenc	_ZL12key_schedule+144(%rip), %xmm0
	aesenclast	_ZL12key_schedule+160(%rip), %xmm0
	movdqa	%xmm0, 144(%rsp)
	movq	_ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj(%rip), %r14
	testq	%r14, %r14
	jne	.LBB3_26
# %bb.24:
	movl	$64, %edi
	callq	_Znwm@PLT
	movq	%rax, %r14
	movl	$-1, (%rax)
	leaq	8(%rax), %r15
	addq	$56, %rax
	movq	%rax, 8(%r14)
	movq	$1, 16(%r14)
	pxor	%xmm0, %xmm0
	movdqu	%xmm0, 24(%r14)
	movl	$1065353216, 40(%r14)           # imm = 0x3F800000
	movdqu	%xmm0, 48(%r14)
.Ltmp24:
	movq	_ZSt4cout@GOTPCREL(%rip), %rdi
	leaq	.L.str.3(%rip), %rsi
	movl	$32, %edx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp25:
# %bb.25:
	movq	%r14, _ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj(%rip)
.LBB3_26:
	leaq	80(%rsp), %r15
	movq	%r15, 64(%rsp)
	movq	%r13, 80(%rsp)
	movl	$1701669204, 87(%rsp)           # imm = 0x656D6954
	movq	$11, 72(%rsp)
	movb	$0, 91(%rsp)
.Ltmp27:
	leaq	64(%rsp), %rsi
	movq	%r14, %rdi
	callq	_ZN11CpuProfiler7stopTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
.Ltmp28:
# %bb.27:
	movq	64(%rsp), %rdi
	cmpq	%r15, %rdi
	je	.LBB3_29
# %bb.28:
	callq	_ZdlPv@PLT
.LBB3_29:
	movq	_ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj(%rip), %r14
	testq	%r14, %r14
	jne	.LBB3_32
# %bb.30:
	movl	$64, %edi
	callq	_Znwm@PLT
	movq	%rax, %r14
	movl	$-1, (%rax)
	leaq	8(%rax), %r15
	addq	$56, %rax
	movq	%rax, 8(%r14)
	movq	$1, 16(%r14)
	pxor	%xmm0, %xmm0
	movdqu	%xmm0, 24(%r14)
	movl	$1065353216, 40(%r14)           # imm = 0x3F800000
	movdqu	%xmm0, 48(%r14)
.Ltmp30:
	movq	_ZSt4cout@GOTPCREL(%rip), %rdi
	leaq	.L.str.3(%rip), %rsi
	movl	$32, %edx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp31:
# %bb.31:
	movq	%r14, _ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj(%rip)
.LBB3_32:
	leaq	48(%rsp), %r15
	movq	%r15, 32(%rsp)
	movq	%r12, 48(%rsp)
	movl	$1701669204, 55(%rsp)           # imm = 0x656D6954
	movq	$11, 40(%rsp)
	movb	$0, 59(%rsp)
	addq	$8, %r14
.Ltmp33:
	leaq	32(%rsp), %rsi
	movq	%r14, %rdi
	callq	_ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEE2atERSD_
.Ltmp34:
# %bb.33:
	movq	(%rax), %rsi
	testq	%rsi, %rsi
	je	.LBB3_35
# %bb.34:
	#APP
	rdtscp
	#NO_APP
                                        # kill: def $edx killed $edx def $rdx
	shlq	$32, %rdx
	movl	%eax, %eax
	orq	%rdx, %rax
	movq	%rax, 32(%rsi)
	jmp	.LBB3_38
.LBB3_35:
.Ltmp35:
	movq	_ZSt4cout@GOTPCREL(%rip), %rdi
	leaq	.L.str.9(%rip), %rsi
	movl	$4, %edx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp36:
# %bb.36:
	movq	32(%rsp), %rsi
	movq	40(%rsp), %rdx
.Ltmp37:
	movq	_ZSt4cout@GOTPCREL(%rip), %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp38:
# %bb.37:
.Ltmp39:
	leaq	.L.str.10(%rip), %rsi
	movl	$14, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp40:
.LBB3_38:
	movq	32(%rsp), %rdi
	cmpq	%r15, %rdi
	je	.LBB3_40
# %bb.39:
	callq	_ZdlPv@PLT
.LBB3_40:
	movdqa	_ZL12key_schedule+160(%rip), %xmm0
	pxor	.LCPI3_3(%rip), %xmm0
	aesdec	_ZL12key_schedule+176(%rip), %xmm0
	aesdec	_ZL12key_schedule+192(%rip), %xmm0
	aesdec	_ZL12key_schedule+208(%rip), %xmm0
	aesdec	_ZL12key_schedule+224(%rip), %xmm0
	aesdec	_ZL12key_schedule+240(%rip), %xmm0
	aesdec	_ZL12key_schedule+256(%rip), %xmm0
	aesdec	_ZL12key_schedule+272(%rip), %xmm0
	aesdec	_ZL12key_schedule+288(%rip), %xmm0
	aesdec	_ZL12key_schedule+304(%rip), %xmm0
	aesdeclast	_ZL12key_schedule(%rip), %xmm0
	movdqa	%xmm0, 128(%rsp)
	movq	_ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj(%rip), %r14
	testq	%r14, %r14
	jne	.LBB3_43
# %bb.41:
	movl	$64, %edi
	callq	_Znwm@PLT
	movq	%rax, %r14
	movl	$-1, (%rax)
	leaq	8(%rax), %r15
	addq	$56, %rax
	movq	%rax, 8(%r14)
	movq	$1, 16(%r14)
	pxor	%xmm0, %xmm0
	movdqu	%xmm0, 24(%r14)
	movl	$1065353216, 40(%r14)           # imm = 0x3F800000
	movdqu	%xmm0, 48(%r14)
.Ltmp42:
	movq	_ZSt4cout@GOTPCREL(%rip), %rdi
	leaq	.L.str.3(%rip), %rsi
	movl	$32, %edx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp43:
# %bb.42:
	movq	%r14, _ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj(%rip)
.LBB3_43:
	leaq	16(%rsp), %r15
	movq	%r15, (%rsp)
	movq	%r12, 16(%rsp)
	movl	$1701669204, 23(%rsp)           # imm = 0x656D6954
	movq	$11, 8(%rsp)
	movb	$0, 27(%rsp)
.Ltmp45:
	movq	%rsp, %rsi
	movq	%r14, %rdi
	callq	_ZN11CpuProfiler7stopTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
.Ltmp46:
# %bb.44:
	movq	(%rsp), %rdi
	cmpq	%r15, %rdi
	je	.LBB3_46
# %bb.45:
	callq	_ZdlPv@PLT
.LBB3_46:
	movdqa	144(%rsp), %xmm0
	pcmpeqb	.LCPI3_3(%rip), %xmm0
	pmovmskb	%xmm0, %eax
	xorl	%ecx, %ecx
	cmpl	$65535, %eax                    # imm = 0xFFFF
	setne	%cl
	movdqa	128(%rsp), %xmm0
	pcmpeqb	.LCPI3_2(%rip), %xmm0
	pmovmskb	%xmm0, %eax
	leal	2(%rcx), %ebx
	cmpl	$65535, %eax                    # imm = 0xFFFF
	cmovel	%ecx, %ebx
	leaq	.L.str.2(%rip), %rdi
	movl	%ebx, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movq	_ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj(%rip), %r14
	testq	%r14, %r14
	jne	.LBB3_49
# %bb.47:
	movl	$64, %edi
	callq	_Znwm@PLT
	movq	%rax, %r14
	movl	$-1, (%rax)
	leaq	8(%rax), %r15
	addq	$56, %rax
	movq	%rax, 8(%r14)
	movq	$1, 16(%r14)
	pxor	%xmm0, %xmm0
	movdqu	%xmm0, 24(%r14)
	movl	$1065353216, 40(%r14)           # imm = 0x3F800000
	movdqu	%xmm0, 48(%r14)
.Ltmp48:
	movq	_ZSt4cout@GOTPCREL(%rip), %rdi
	leaq	.L.str.3(%rip), %rsi
	movl	$32, %edx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp49:
# %bb.48:
	movq	%r14, _ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj(%rip)
.LBB3_49:
	movq	24(%r14), %r14
	testq	%r14, %r14
	je	.LBB3_51
	.p2align	4, 0x90
.LBB3_50:                               # =>This Inner Loop Header: Depth=1
	movq	40(%r14), %rdi
	callq	_ZN6TagObj26prepareReportAndDumpToFileEv
	movq	(%r14), %r14
	testq	%r14, %r14
	jne	.LBB3_50
.LBB3_51:
	movq	%fs:40, %rax
	cmpq	232(%rsp), %rax
	jne	.LBB3_73
# %bb.52:
	movl	%ebx, %eax
	addq	$240, %rsp
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
.LBB3_53:
	.cfi_def_cfa_offset 288
.Ltmp50:
	jmp	.LBB3_60
.LBB3_54:
.Ltmp44:
	jmp	.LBB3_60
.LBB3_55:
.Ltmp32:
	jmp	.LBB3_60
.LBB3_56:
.Ltmp26:
	jmp	.LBB3_60
.LBB3_57:
.Ltmp14:
	jmp	.LBB3_60
.LBB3_58:
.Ltmp8:
	jmp	.LBB3_60
.LBB3_59:
.Ltmp2:
.LBB3_60:
	movq	%rax, %rbx
	movq	%r15, %rdi
	callq	_ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEED2Ev
	movq	%r14, %rdi
	jmp	.LBB3_70
.LBB3_61:
.Ltmp47:
	movq	%rax, %rbx
	movq	(%rsp), %rdi
	jmp	.LBB3_69
.LBB3_62:
.Ltmp29:
	movq	%rax, %rbx
	movq	64(%rsp), %rdi
	jmp	.LBB3_69
.LBB3_63:
.Ltmp11:
	movq	%rax, %rbx
	movq	168(%rsp), %rdi
	cmpq	%r15, %rdi
	jne	.LBB3_70
	jmp	.LBB3_71
.LBB3_65:
.Ltmp5:
	movq	%rax, %rbx
	movq	200(%rsp), %rdi
	cmpq	%r15, %rdi
	jne	.LBB3_70
	jmp	.LBB3_71
.LBB3_67:
.Ltmp41:
	movq	%rax, %rbx
	movq	32(%rsp), %rdi
	jmp	.LBB3_69
.LBB3_68:
.Ltmp23:
	movq	%rax, %rbx
	movq	96(%rsp), %rdi
.LBB3_69:
	cmpq	%r15, %rdi
	je	.LBB3_71
.LBB3_70:
	callq	_ZdlPv@PLT
.LBB3_71:
	movq	%fs:40, %rax
	cmpq	232(%rsp), %rax
	jne	.LBB3_73
# %bb.72:
	movq	%rbx, %rdi
	callq	_Unwind_Resume@PLT
.LBB3_73:
	callq	__stack_chk_fail@PLT
.Lfunc_end3:
	.size	main, .Lfunc_end3-main
	.cfi_endproc
	.section	.gcc_except_table,"a",@progbits
	.p2align	2, 0x0
GCC_except_table3:
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
	.uleb128 .Lfunc_end3-.Ltmp49            #   Call between .Ltmp49 and .Lfunc_end3
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
	jb	.LBB4_3
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
.LBB4_3:
	testq	%r13, %r13
	je	.LBB4_7
# %bb.4:
	cmpq	$1, %r13
	jne	.LBB4_6
# %bb.5:
	movzbl	(%r12), %ecx
	movb	%cl, (%rax)
	jmp	.LBB4_7
.LBB4_6:
	movq	%rax, %rdi
	movq	%r12, %rsi
	movq	%r13, %rdx
	callq	_intel_fast_memcpy@PLT
.LBB4_7:
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
	je	.LBB4_10
# %bb.9:
	callq	_ZdlPv@PLT
.LBB4_10:
	addq	$8, %r15
	movq	%r15, %rdi
	movq	%r14, %rsi
	callq	_ZNSt8__detail9_Map_baseINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS6_P6TagObjESaISB_ENS_10_Select1stESt8equal_toIS6_ESt4hashIS6_ENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixERS8_
	movq	%rbx, (%rax)
	movq	%fs:40, %rax
	cmpq	48(%rsp), %rax
	jne	.LBB4_17
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
.LBB4_12:
	.cfi_def_cfa_offset 112
.Ltmp53:
	movq	%rax, %r14
	jmp	.LBB4_15
.LBB4_13:
.Ltmp56:
	movq	%rax, %r14
	movq	16(%rsp), %rdi
	cmpq	%rbp, %rdi
	je	.LBB4_15
# %bb.14:
	callq	_ZdlPv@PLT
.LBB4_15:
	movq	%rbx, %rdi
	callq	_ZdlPv@PLT
	movq	%fs:40, %rax
	cmpq	48(%rsp), %rax
	jne	.LBB4_17
# %bb.16:
	movq	%r14, %rdi
	callq	_Unwind_Resume@PLT
.LBB4_17:
	callq	__stack_chk_fail@PLT
.Lfunc_end4:
	.size	_ZN11CpuProfiler6addTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, .Lfunc_end4-_ZN11CpuProfiler6addTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.cfi_endproc
	.section	.gcc_except_table._ZN11CpuProfiler6addTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,"aG",@progbits,_ZN11CpuProfiler6addTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,comdat
	.p2align	2, 0x0
GCC_except_table4:
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
	.uleb128 .Lfunc_end4-.Ltmp55            #   Call between .Ltmp55 and .Lfunc_end4
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
	je	.LBB5_15
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
	jne	.LBB5_3
# %bb.2:
	movq	_ZSt4cout@GOTPCREL(%rip), %rbx
	leaq	.L.str.12(%rip), %rsi
	movl	$23, %edx
	movq	%rbx, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	(%r12), %rsi
	movq	8(%r12), %rdx
	movq	%rbx, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	leaq	.L.str.13(%rip), %rsi
	movl	$13, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	32(%r12), %rax
	movq	40(%r12), %r13
.LBB5_3:
	incl	72(%r12)
	subq	%rax, %r13
	movq	56(%r12), %r14
	cmpq	64(%r12), %r14
	je	.LBB5_5
# %bb.4:
	movq	%r13, (%r14)
	addq	$8, %r14
	movq	%r14, 56(%r12)
	jmp	.LBB5_14
.LBB5_15:
	movq	_ZSt4cout@GOTPCREL(%rip), %r14
	leaq	.L.str.9(%rip), %rsi
	movl	$4, %edx
	movq	%r14, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	(%rbx), %rsi
	movq	8(%rbx), %rdx
	movq	%r14, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	leaq	.L.str.10(%rip), %rsi
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
.LBB5_5:
	.cfi_def_cfa_offset 80
	movq	48(%r12), %rax
	movq	%rax, 16(%rsp)                  # 8-byte Spill
	subq	%rax, %r14
	movabsq	$9223372036854775800, %rax      # imm = 0x7FFFFFFFFFFFFFF8
	cmpq	%rax, %r14
	je	.LBB5_16
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
	je	.LBB5_7
# %bb.8:
	leaq	(,%rbp,8), %rdi
	callq	_Znwm@PLT
	movq	%rax, %r15
	jmp	.LBB5_9
.LBB5_7:
	xorl	%r15d, %r15d
.LBB5_9:
	leaq	(%r15,%rbx,8), %rax
	movq	%rax, 8(%rsp)                   # 8-byte Spill
	movq	%r13, (%r15,%rbx,8)
	testq	%r14, %r14
	movq	16(%rsp), %rbx                  # 8-byte Reload
	jle	.LBB5_11
# %bb.10:
	movq	%r15, %rdi
	movq	%rbx, %rsi
	movq	%r14, %rdx
	callq	_intel_fast_memcpy@PLT
.LBB5_11:
	movq	8(%rsp), %r14                   # 8-byte Reload
	addq	$8, %r14
	testq	%rbx, %rbx
	je	.LBB5_13
# %bb.12:
	movq	%rbx, %rdi
	callq	_ZdlPv@PLT
.LBB5_13:
	movq	%r15, 48(%r12)
	movq	%r14, 56(%r12)
	leaq	(%r15,%rbp,8), %rax
	movq	%rax, 64(%r12)
.LBB5_14:
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
.LBB5_16:
	.cfi_def_cfa_offset 80
	leaq	.L.str.14(%rip), %rdi
	callq	_ZSt20__throw_length_errorPKc@PLT
.Lfunc_end5:
	.size	_ZN11CpuProfiler7stopTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, .Lfunc_end5-_ZN11CpuProfiler7stopTagENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
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
	leaq	16(%rdi), %r15
	movq	16(%rdi), %r14
	testq	%r14, %r14
	jne	.LBB6_1
.LBB6_4:
	movq	(%rbx), %rdi
	movq	8(%rbx), %rdx
	shlq	$3, %rdx
	xorl	%esi, %esi
	callq	_intel_fast_memset@PLT
	xorps	%xmm0, %xmm0
	movups	%xmm0, (%r15)
	movq	(%rbx), %rdi
	addq	$48, %rbx
	addq	$8, %rsp
	cmpq	%rdi, %rbx
	je	.LBB6_5
# %bb.6:
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
	.p2align	4, 0x90
.LBB6_3:                                #   in Loop: Header=BB6_1 Depth=1
	.cfi_def_cfa_offset 48
	movq	%r14, %rdi
	callq	_ZdlPv@PLT
	movq	%r12, %r14
	testq	%r12, %r12
	je	.LBB6_4
.LBB6_1:                                # =>This Inner Loop Header: Depth=1
	movq	(%r14), %r12
	movq	8(%r14), %rdi
	leaq	24(%r14), %rax
	cmpq	%rax, %rdi
	je	.LBB6_3
# %bb.2:                                #   in Loop: Header=BB6_1 Depth=1
	callq	_ZdlPv@PLT
	jmp	.LBB6_3
.LBB6_5:
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
.Lfunc_end6:
	.size	_ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEED2Ev, .Lfunc_end6-_ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEED2Ev
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
.Lfunc_end7:
	.size	__clang_call_terminate, .Lfunc_end7-__clang_call_terminate
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
	jb	.LBB8_2
# %bb.1:
	leaq	8(%rsp), %rsi
	movq	%rbx, %rdi
	xorl	%edx, %edx
	callq	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm@PLT
	movq	%rax, (%rbx)
	movq	8(%rsp), %rcx
	movq	%rcx, 16(%rbx)
.LBB8_2:
	testq	%r15, %r15
	je	.LBB8_6
# %bb.3:
	cmpq	$1, %r15
	jne	.LBB8_5
# %bb.4:
	movzbl	(%r14), %ecx
	movb	%cl, (%rax)
	jmp	.LBB8_6
.LBB8_5:
	movq	%rax, %rdi
	movq	%r14, %rsi
	movq	%r15, %rdx
	callq	_intel_fast_memcpy@PLT
.LBB8_6:
	movq	8(%rsp), %rax
	movq	%rax, 8(%rbx)
	movq	(%rbx), %rcx
	movb	$0, (%rcx,%rax)
	xorps	%xmm0, %xmm0
	movups	%xmm0, 48(%rbx)
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
	leaq	.L.str.5(%rip), %rsi
	movl	$27, %edx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp61:
# %bb.8:
.Ltmp62:
	leaq	.L.str.6(%rip), %rsi
	leaq	520(%rsp), %rdi
	movq	%rbx, %rdx
	callq	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_RKS8_
.Ltmp63:
# %bb.9:
	movq	528(%rsp), %rax
	shrq	$2, %rax
	movabsq	$1152921504606846975, %rcx      # imm = 0xFFFFFFFFFFFFFFF
	cmpq	%rcx, %rax
	je	.LBB8_27
# %bb.10:
.Ltmp65:
	leaq	.L.str.7(%rip), %rsi
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
	je	.LBB8_13
# %bb.12:
	movq	%rsi, 552(%rsp)
	movq	(%rcx), %rdx
	movq	%rdx, 568(%rsp)
	jmp	.LBB8_14
.LBB8_13:
	movups	(%rsi), %xmm0
	movups	%xmm0, (%r13)
	movq	%r13, %rsi
.LBB8_14:
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
	jne	.LBB8_17
# %bb.16:
	movl	32(%r14), %esi
	orl	$4, %esi
.LBB8_17:
.Ltmp69:
	movq	%r14, %rdi
	callq	_ZNSt9basic_iosIcSt11char_traitsIcEE5clearESt12_Ios_Iostate@PLT
.Ltmp70:
# %bb.18:
	movq	552(%rsp), %rdi
	cmpq	%r13, %rdi
	je	.LBB8_20
# %bb.19:
	callq	_ZdlPv@PLT
.LBB8_20:
	movq	520(%rsp), %rdi
	leaq	536(%rsp), %rax
	cmpq	%rax, %rdi
	je	.LBB8_22
# %bb.21:
	callq	_ZdlPv@PLT
.LBB8_22:
.Ltmp72:
	movq	%r15, %rdi
	callq	_ZNSt13basic_filebufIcSt11char_traitsIcEE5closeEv@PLT
.Ltmp73:
# %bb.23:
	testq	%rax, %rax
	jne	.LBB8_25
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
.LBB8_25:
	leaq	8(%rsp), %rdi
	callq	_ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev@PLT
	movq	%fs:40, %rax
	cmpq	584(%rsp), %rax
	jne	.LBB8_46
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
.LBB8_27:
	.cfi_def_cfa_offset 640
	movq	%fs:40, %rax
	cmpq	584(%rsp), %rax
	jne	.LBB8_46
# %bb.28:
.Ltmp77:
	leaq	.L.str.8(%rip), %rdi
	callq	_ZSt20__throw_length_errorPKc@PLT
.Ltmp78:
# %bb.29:
.LBB8_30:
.Ltmp64:
	jmp	.LBB8_38
.LBB8_31:
.Ltmp59:
	movq	%rax, %r14
	jmp	.LBB8_40
.LBB8_32:
.Ltmp71:
	movq	%rax, %r14
	movq	552(%rsp), %rdi
	cmpq	%r13, %rdi
	je	.LBB8_35
# %bb.33:
	callq	_ZdlPv@PLT
	jmp	.LBB8_35
.LBB8_34:
.Ltmp79:
	movq	%rax, %r14
.LBB8_35:
	movq	520(%rsp), %rdi
	leaq	536(%rsp), %rax
	cmpq	%rax, %rdi
	je	.LBB8_39
# %bb.36:
	callq	_ZdlPv@PLT
	jmp	.LBB8_39
.LBB8_37:
.Ltmp76:
.LBB8_38:
	movq	%rax, %r14
.LBB8_39:
	leaq	8(%rsp), %rdi
	callq	_ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev@PLT
.LBB8_40:
	leaq	48(%rbx), %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	je	.LBB8_42
# %bb.41:
	callq	_ZdlPv@PLT
.LBB8_42:
	movq	(%rbx), %rdi
	cmpq	%r12, %rdi
	je	.LBB8_44
# %bb.43:
	callq	_ZdlPv@PLT
.LBB8_44:
	movq	%fs:40, %rax
	cmpq	584(%rsp), %rax
	jne	.LBB8_46
# %bb.45:
	movq	%r14, %rdi
	callq	_Unwind_Resume@PLT
.LBB8_46:
	callq	__stack_chk_fail@PLT
.Lfunc_end8:
	.size	_ZN6TagObjC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEj, .Lfunc_end8-_ZN6TagObjC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEj
	.cfi_endproc
	.section	.gcc_except_table._ZN6TagObjC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEj,"aG",@progbits,_ZN6TagObjC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEj,comdat
	.p2align	2, 0x0
GCC_except_table8:
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
	.uleb128 .Lfunc_end8-.Ltmp78            #   Call between .Ltmp78 and .Lfunc_end8
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
	jb	.LBB9_2
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
.LBB9_2:
	.cfi_def_cfa_offset 48
.Ltmp86:
	leaq	.L.str.8(%rip), %rdi
	callq	_ZSt20__throw_length_errorPKc@PLT
.Ltmp87:
# %bb.3:
.LBB9_7:
.Ltmp88:
	movq	%rax, %r14
	movq	(%rbx), %rdi
	cmpq	%r13, %rdi
	je	.LBB9_9
# %bb.8:
	callq	_ZdlPv@PLT
.LBB9_9:
	movq	%r14, %rdi
	callq	_Unwind_Resume@PLT
.Lfunc_end9:
	.size	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_RKS8_, .Lfunc_end9-_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_RKS8_
	.cfi_endproc
	.section	.gcc_except_table._ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_RKS8_,"aG",@progbits,_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_RKS8_,comdat
	.p2align	2, 0x0
GCC_except_table9:
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
	.uleb128 .Lfunc_end9-.Ltmp87            #   Call between .Ltmp87 and .Lfunc_end9
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
	movq	%rsi, %r13
	movq	%rdi, %r14
	movq	(%rsi), %rdi
	movq	8(%rsi), %rsi
.Ltmp89:
	movl	$3339675911, %edx               # imm = 0xC70F6907
	callq	_ZSt11_Hash_bytesPKvmm@PLT
.Ltmp90:
# %bb.1:
	movq	%rax, %rdi
	movq	8(%r14), %rbx
	orq	%rbx, %rax
	shrq	$32, %rax
	je	.LBB10_3
# %bb.2:
	movq	%rdi, %rax
	xorl	%edx, %edx
	divq	%rbx
	movq	%rdx, %r12
	jmp	.LBB10_4
.LBB10_3:
	movl	%edi, %eax
	xorl	%edx, %edx
	divl	%ebx
	movl	%edx, %r12d
.LBB10_4:
	movq	%r14, 32(%rsp)                  # 8-byte Spill
	movq	(%r14), %rax
	movq	(%rax,%r12,8), %r14
	testq	%r14, %r14
	movq	%rdi, 16(%rsp)                  # 8-byte Spill
	je	.LBB10_17
# %bb.5:
	movq	(%r14), %r15
	movq	(%r13), %rax
	movq	%rax, 8(%rsp)                   # 8-byte Spill
	movq	8(%r13), %rbp
	movq	48(%r15), %rcx
	jmp	.LBB10_8
	.p2align	4, 0x90
.LBB10_6:                               #   in Loop: Header=BB10_8 Depth=1
	movl	%ecx, %eax
	xorl	%edx, %edx
	divl	%ebx
                                        # kill: def $edx killed $edx def $rdx
.LBB10_7:                               #   in Loop: Header=BB10_8 Depth=1
	movq	%r15, %r14
	movq	%rsi, %r15
	cmpq	%r12, %rdx
	jne	.LBB10_17
.LBB10_8:                               # =>This Inner Loop Header: Depth=1
	cmpq	%rdi, %rcx
	jne	.LBB10_12
# %bb.9:                                #   in Loop: Header=BB10_8 Depth=1
	cmpq	16(%r15), %rbp
	jne	.LBB10_12
# %bb.10:                               #   in Loop: Header=BB10_8 Depth=1
	testq	%rbp, %rbp
	je	.LBB10_15
# %bb.11:                               #   in Loop: Header=BB10_8 Depth=1
	movq	8(%r15), %rsi
	movq	8(%rsp), %rdi                   # 8-byte Reload
	movq	%rbp, %rdx
	callq	bcmp@PLT
	movq	16(%rsp), %rdi                  # 8-byte Reload
	testl	%eax, %eax
	je	.LBB10_15
.LBB10_12:                              #   in Loop: Header=BB10_8 Depth=1
	movq	(%r15), %rsi
	testq	%rsi, %rsi
	je	.LBB10_17
# %bb.13:                               #   in Loop: Header=BB10_8 Depth=1
	movq	48(%rsi), %rcx
	movq	%rcx, %rax
	orq	%rbx, %rax
	shrq	$32, %rax
	je	.LBB10_6
# %bb.14:                               #   in Loop: Header=BB10_8 Depth=1
	movq	%rcx, %rax
	xorl	%edx, %edx
	divq	%rbx
	jmp	.LBB10_7
.LBB10_15:
	movq	(%r14), %rcx
	testq	%rcx, %rcx
	je	.LBB10_17
# %bb.16:
	addq	$40, %rcx
	jmp	.LBB10_56
.LBB10_17:
	movq	32(%rsp), %r14                  # 8-byte Reload
	movq	%r14, 40(%rsp)
	movl	$56, %edi
	callq	_Znwm@PLT
	movq	%rax, %r15
	movq	$0, (%rax)
	leaq	24(%rax), %rbp
	movq	%rbp, 8(%rax)
	movq	(%r13), %rax
	movq	%rax, 8(%rsp)                   # 8-byte Spill
	movq	8(%r13), %r13
	movq	%r13, 24(%rsp)
	cmpq	$16, %r13
	jb	.LBB10_20
# %bb.18:
.Ltmp92:
	leaq	8(%r15), %rbx
	leaq	24(%rsp), %rsi
	movq	%rbx, %rdi
	xorl	%edx, %edx
	callq	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm@PLT
.Ltmp93:
# %bb.19:
	movq	%rax, (%rbx)
	movq	24(%rsp), %rcx
	movq	%rcx, (%rbp)
	movq	%rax, %rbp
.LBB10_20:
	testq	%r13, %r13
	je	.LBB10_24
# %bb.21:
	cmpq	$1, %r13
	jne	.LBB10_23
# %bb.22:
	movq	8(%rsp), %rax                   # 8-byte Reload
	movzbl	(%rax), %eax
	movb	%al, (%rbp)
	jmp	.LBB10_24
.LBB10_23:
	movq	%rbp, %rdi
	movq	8(%rsp), %rsi                   # 8-byte Reload
	movq	%r13, %rdx
	callq	_intel_fast_memcpy@PLT
.LBB10_24:
	movq	24(%rsp), %rax
	movq	%rax, 16(%r15)
	movq	8(%r15), %rcx
	movb	$0, (%rcx,%rax)
	movq	$0, 40(%r15)
	movq	%r15, 48(%rsp)
	leaq	32(%r14), %rdi
	movq	40(%r14), %rbx
	movq	8(%r14), %rsi
	movq	24(%r14), %rdx
.Ltmp101:
	movl	$1, %ecx
	callq	_ZNKSt8__detail20_Prime_rehash_policy14_M_need_rehashEmmm@PLT
.Ltmp102:
# %bb.25:
	testb	$1, %al
	movq	16(%rsp), %rsi                  # 8-byte Reload
	jne	.LBB10_27
# %bb.26:
	movq	(%r14), %r13
	jmp	.LBB10_47
.LBB10_27:
	movq	%rdx, %rbp
	cmpq	$1, %rdx
	je	.LBB10_57
# %bb.28:
	movq	%rbx, %r12
	movq	%rbp, %rax
	shrq	$60, %rax
	jne	.LBB10_58
# %bb.29:
	leaq	(,%rbp,8), %rbx
.Ltmp104:
	movq	%rbx, %rdi
	callq	_Znwm@PLT
.Ltmp105:
# %bb.30:
	movq	%rax, %r13
	movq	%rax, %rdi
	xorl	%esi, %esi
	movq	%rbx, %rdx
	callq	_intel_fast_memset@PLT
.LBB10_31:
	movq	16(%r14), %rsi
	movq	$0, 16(%r14)
	testq	%rsi, %rsi
	je	.LBB10_42
# %bb.32:
	leaq	16(%r14), %rcx
	xorl	%r8d, %r8d
	jmp	.LBB10_36
	.p2align	4, 0x90
.LBB10_33:                              #   in Loop: Header=BB10_36 Depth=1
	movq	(%rax), %rax
	movq	%rax, (%rsi)
	movq	(%r13,%rdx,8), %rax
	movq	%r8, %rdx
.LBB10_34:                              #   in Loop: Header=BB10_36 Depth=1
	movq	%rsi, (%rax)
.LBB10_35:                              #   in Loop: Header=BB10_36 Depth=1
	movq	%rdi, %rsi
	movq	%rdx, %r8
	testq	%rdi, %rdi
	je	.LBB10_42
.LBB10_36:                              # =>This Inner Loop Header: Depth=1
	movq	(%rsi), %rdi
	movq	48(%rsi), %rax
	movq	%rax, %rdx
	orq	%rbp, %rdx
	shrq	$32, %rdx
	je	.LBB10_38
# %bb.37:                               #   in Loop: Header=BB10_36 Depth=1
	xorl	%edx, %edx
	divq	%rbp
	jmp	.LBB10_39
	.p2align	4, 0x90
.LBB10_38:                              #   in Loop: Header=BB10_36 Depth=1
                                        # kill: def $eax killed $eax killed $rax
	xorl	%edx, %edx
	divl	%ebp
                                        # kill: def $edx killed $edx def $rdx
.LBB10_39:                              #   in Loop: Header=BB10_36 Depth=1
	movq	(%r13,%rdx,8), %rax
	testq	%rax, %rax
	jne	.LBB10_33
# %bb.40:                               #   in Loop: Header=BB10_36 Depth=1
	movq	(%rcx), %rax
	movq	%rax, (%rsi)
	movq	%rsi, (%rcx)
	movq	%rcx, (%r13,%rdx,8)
	cmpq	$0, (%rsi)
	je	.LBB10_35
# %bb.41:                               #   in Loop: Header=BB10_36 Depth=1
	leaq	(,%r8,8), %rax
	addq	%r13, %rax
	jmp	.LBB10_34
.LBB10_42:
	movq	(%r14), %rdi
	leaq	48(%r14), %rax
	cmpq	%rdi, %rax
	je	.LBB10_44
# %bb.43:
	callq	_ZdlPv@PLT
.LBB10_44:
	movq	%rbp, 8(%r14)
	movq	%r13, (%r14)
	movq	16(%rsp), %rsi                  # 8-byte Reload
	movq	%rsi, %rax
	orq	%rbp, %rax
	shrq	$32, %rax
	je	.LBB10_46
# %bb.45:
	movq	%rsi, %rax
	xorl	%edx, %edx
	divq	%rbp
	movq	%rdx, %r12
	jmp	.LBB10_47
.LBB10_46:
	movl	%esi, %eax
	xorl	%edx, %edx
	divl	%ebp
	movl	%edx, %r12d
.LBB10_47:
	movq	%r15, %rcx
	addq	$40, %rcx
	movq	%rsi, 48(%r15)
	movq	(%r13,%r12,8), %rax
	testq	%rax, %rax
	je	.LBB10_49
# %bb.48:
	movq	(%rax), %rax
	movq	%rax, (%r15)
	movq	(%r13,%r12,8), %rax
	movq	%r15, (%rax)
	jmp	.LBB10_55
.LBB10_49:
	leaq	16(%r14), %rsi
	movq	16(%r14), %rax
	movq	%rax, (%r15)
	movq	%r15, 16(%r14)
	testq	%rax, %rax
	je	.LBB10_54
# %bb.50:
	movq	8(%r14), %rdi
	movq	48(%rax), %rax
	movq	%rax, %rdx
	orq	%rdi, %rdx
	shrq	$32, %rdx
	je	.LBB10_52
# %bb.51:
	xorl	%edx, %edx
	divq	%rdi
	jmp	.LBB10_53
.LBB10_52:
                                        # kill: def $eax killed $eax killed $rax
	xorl	%edx, %edx
	divl	%edi
                                        # kill: def $edx killed $edx def $rdx
.LBB10_53:
	movq	%r15, (%r13,%rdx,8)
.LBB10_54:
	movq	%rsi, (%r13,%r12,8)
.LBB10_55:
	incq	24(%r14)
.LBB10_56:
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
.LBB10_57:
	.cfi_def_cfa_offset 112
	leaq	48(%r14), %r13
	movq	$0, 48(%r14)
	jmp	.LBB10_31
.LBB10_58:
	shrq	$61, %rbp
	je	.LBB10_61
# %bb.59:
.Ltmp108:
	callq	_ZSt28__throw_bad_array_new_lengthv@PLT
.Ltmp109:
# %bb.60:
.LBB10_61:
.Ltmp106:
	callq	_ZSt17__throw_bad_allocv@PLT
.Ltmp107:
# %bb.62:
.LBB10_63:
.Ltmp94:
	movq	%rax, %rdi
	callq	__cxa_begin_catch@PLT
	movq	%r15, %rdi
	callq	_ZdlPv@PLT
.Ltmp95:
	callq	__cxa_rethrow@PLT
.Ltmp96:
# %bb.64:
.LBB10_65:
.Ltmp97:
	movq	%rax, %rbx
.Ltmp98:
	callq	__cxa_end_catch@PLT
.Ltmp99:
# %bb.66:
	movq	%rbx, %rdi
	callq	_Unwind_Resume@PLT
.LBB10_67:
.Ltmp100:
	movq	%rax, %rdi
	callq	__clang_call_terminate
.LBB10_68:
.Ltmp103:
	movq	%rax, %rbx
	jmp	.LBB10_73
.LBB10_69:
.Ltmp91:
	movq	%rax, %rdi
	callq	__clang_call_terminate
.LBB10_70:
.Ltmp110:
	movq	%rax, %rdi
	callq	__cxa_begin_catch@PLT
	movq	%r12, 40(%r14)
.Ltmp111:
	callq	__cxa_rethrow@PLT
.Ltmp112:
# %bb.71:
.LBB10_72:
.Ltmp113:
	movq	%rax, %rbx
.Ltmp114:
	callq	__cxa_end_catch@PLT
.Ltmp115:
.LBB10_73:
	leaq	40(%rsp), %rdi
	callq	_ZNSt10_HashtableINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS5_P6TagObjESaISA_ENSt8__detail10_Select1stESt8equal_toIS5_ESt4hashIS5_ENSC_18_Mod_range_hashingENSC_20_Default_ranged_hashENSC_20_Prime_rehash_policyENSC_17_Hashtable_traitsILb1ELb0ELb1EEEE12_Scoped_nodeD2Ev
	movq	%rbx, %rdi
	callq	_Unwind_Resume@PLT
.LBB10_74:
.Ltmp116:
	movq	%rax, %rdi
	callq	__clang_call_terminate
.Lfunc_end10:
	.size	_ZNSt8__detail9_Map_baseINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS6_P6TagObjESaISB_ENS_10_Select1stESt8equal_toIS6_ESt4hashIS6_ENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixERS8_, .Lfunc_end10-_ZNSt8__detail9_Map_baseINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS6_P6TagObjESaISB_ENS_10_Select1stESt8equal_toIS6_ESt4hashIS6_ENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixERS8_
	.cfi_endproc
	.section	.gcc_except_table._ZNSt8__detail9_Map_baseINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS6_P6TagObjESaISB_ENS_10_Select1stESt8equal_toIS6_ESt4hashIS6_ENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixERS8_,"aG",@progbits,_ZNSt8__detail9_Map_baseINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS6_P6TagObjESaISB_ENS_10_Select1stESt8equal_toIS6_ESt4hashIS6_ENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixERS8_,comdat
	.p2align	2, 0x0
GCC_except_table10:
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
	.uleb128 .Lfunc_end10-.Ltmp115          #   Call between .Ltmp115 and .Lfunc_end10
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
	je	.LBB11_4
# %bb.1:
	movq	8(%rbx), %rdi
	leaq	24(%rbx), %rax
	cmpq	%rax, %rdi
	je	.LBB11_3
# %bb.2:
	callq	_ZdlPv@PLT
.LBB11_3:
	movq	%rbx, %rdi
	popq	%rbx
	.cfi_def_cfa_offset 8
	jmp	_ZdlPv@PLT                      # TAILCALL
.LBB11_4:
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end11:
	.size	_ZNSt10_HashtableINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS5_P6TagObjESaISA_ENSt8__detail10_Select1stESt8equal_toIS5_ESt4hashIS5_ENSC_18_Mod_range_hashingENSC_20_Default_ranged_hashENSC_20_Prime_rehash_policyENSC_17_Hashtable_traitsILb1ELb0ELb1EEEE12_Scoped_nodeD2Ev, .Lfunc_end11-_ZNSt10_HashtableINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt4pairIKS5_P6TagObjESaISA_ENSt8__detail10_Select1stESt8equal_toIS5_ESt4hashIS5_ENSC_18_Mod_range_hashingENSC_20_Default_ranged_hashENSC_20_Prime_rehash_policyENSC_17_Hashtable_traitsILb1ELb0ELb1EEEE12_Scoped_nodeD2Ev
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
	movq	%rsi, %r12
	movq	%rdi, %r15
	movq	(%rsi), %rdi
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
	je	.LBB12_2
# %bb.3:
	movq	%rbx, %rax
	xorl	%edx, %edx
	divq	%r13
	movq	%rdx, %r14
	jmp	.LBB12_4
.LBB12_2:
	movl	%ebx, %eax
	xorl	%edx, %edx
	divl	%r13d
	movl	%edx, %r14d
.LBB12_4:
	movq	(%r15), %rax
	movq	(%rax,%r14,8), %r15
	testq	%r15, %r15
	je	.LBB12_15
# %bb.5:
	movq	(%r15), %rbp
	movq	(%r12), %rax
	movq	%rax, (%rsp)                    # 8-byte Spill
	movq	8(%r12), %r12
	movq	48(%rbp), %rcx
	jmp	.LBB12_6
	.p2align	4, 0x90
.LBB12_13:                              #   in Loop: Header=BB12_6 Depth=1
	movq	%rcx, %rax
	xorl	%edx, %edx
	divq	%r13
.LBB12_14:                              #   in Loop: Header=BB12_6 Depth=1
	movq	%rbp, %r15
	movq	%rsi, %rbp
	cmpq	%r14, %rdx
	jne	.LBB12_15
.LBB12_6:                               # =>This Inner Loop Header: Depth=1
	cmpq	%rbx, %rcx
	jne	.LBB12_10
# %bb.7:                                #   in Loop: Header=BB12_6 Depth=1
	cmpq	16(%rbp), %r12
	jne	.LBB12_10
# %bb.8:                                #   in Loop: Header=BB12_6 Depth=1
	testq	%r12, %r12
	je	.LBB12_16
# %bb.9:                                #   in Loop: Header=BB12_6 Depth=1
	movq	8(%rbp), %rsi
	movq	(%rsp), %rdi                    # 8-byte Reload
	movq	%r12, %rdx
	callq	bcmp@PLT
	testl	%eax, %eax
	je	.LBB12_16
.LBB12_10:                              #   in Loop: Header=BB12_6 Depth=1
	movq	(%rbp), %rsi
	testq	%rsi, %rsi
	je	.LBB12_15
# %bb.11:                               #   in Loop: Header=BB12_6 Depth=1
	movq	48(%rsi), %rcx
	movq	%rcx, %rax
	orq	%r13, %rax
	shrq	$32, %rax
	jne	.LBB12_13
# %bb.12:                               #   in Loop: Header=BB12_6 Depth=1
	movl	%ecx, %eax
	xorl	%edx, %edx
	divl	%r13d
                                        # kill: def $edx killed $edx def $rdx
	jmp	.LBB12_14
.LBB12_16:
	movq	(%r15), %rax
	testq	%rax, %rax
	je	.LBB12_15
# %bb.17:
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
.LBB12_15:
	.cfi_def_cfa_offset 64
	leaq	.L.str.11(%rip), %rdi
	callq	_ZSt20__throw_out_of_rangePKc@PLT
.LBB12_18:
.Ltmp119:
	movq	%rax, %rdi
	callq	__clang_call_terminate
.Lfunc_end12:
	.size	_ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEE2atERSD_, .Lfunc_end12-_ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEE2atERSD_
	.cfi_endproc
	.section	.gcc_except_table._ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEE2atERSD_,"aG",@progbits,_ZNSt13unordered_mapINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEP6TagObjSt4hashIS5_ESt8equal_toIS5_ESaISt4pairIKS5_S7_EEE2atERSD_,comdat
	.p2align	2, 0x0
GCC_except_table12:
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
	.uleb128 .Lfunc_end12-.Ltmp118          #   Call between .Ltmp118 and .Lfunc_end12
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
.LCPI13_0:
	.long	1127219200                      # 0x43300000
	.long	1160773632                      # 0x45300000
	.long	0                               # 0x0
	.long	0                               # 0x0
.LCPI13_1:
	.quad	0x4330000000000000              #  4503599627370496
	.quad	0x4530000000000000              #  1.9342813113834067E+25
.LCPI13_3:
	.quad	4294967295                      # 0xffffffff
	.quad	4294967295                      # 0xffffffff
.LCPI13_4:
	.quad	4841369599423283200             # 0x4330000000000000
	.quad	4841369599423283200             # 0x4330000000000000
.LCPI13_5:
	.quad	4985484787499139072             # 0x4530000000000000
	.quad	4985484787499139072             # 0x4530000000000000
.LCPI13_6:
	.quad	0x4530000000100000              #  1.9342813118337666E+25
	.quad	0x4530000000100000              #  1.9342813118337666E+25
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3, 0x0
.LCPI13_2:
	.quad	0x3ff0000000000000              #  1
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
	subq	$648, %rsp                      # imm = 0x288
	.cfi_def_cfa_offset 704
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	.cfi_offset %rbp, -16
	movq	%rdi, %r14
	movq	%fs:40, %rax
	movq	%rax, 640(%rsp)
	movq	_ZSt4cout@GOTPCREL(%rip), %rdi
	movq	(%rdi), %rax
	movq	-24(%rax), %rax
	movq	$10, 16(%rdi,%rax)
	movq	(%r14), %rsi
	movq	8(%r14), %rdx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	leaq	.L.str.15(%rip), %rsi
	movl	$3, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	leaq	64(%rsp), %rbx
	movq	%rbx, %rdi
	callq	_ZNSt14basic_ofstreamIcSt11char_traitsIcEEC1Ev@PLT
.Ltmp120:
	leaq	.L.str.6(%rip), %rsi
	leaq	576(%rsp), %rdi
	movq	%r14, 8(%rsp)                   # 8-byte Spill
	movq	%r14, %rdx
	callq	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_RKS8_
.Ltmp121:
# %bb.1:
	movq	584(%rsp), %rax
	shrq	$2, %rax
	movabsq	$1152921504606846975, %rcx      # imm = 0xFFFFFFFFFFFFFFF
	cmpq	%rcx, %rax
	je	.LBB13_2
# %bb.5:
.Ltmp123:
	leaq	.L.str.7(%rip), %rsi
	leaq	576(%rsp), %rdi
	movl	$4, %edx
	callq	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_appendEPKcm@PLT
.Ltmp124:
# %bb.6:
	leaq	624(%rsp), %r15
	movq	%r15, 608(%rsp)
	movq	(%rax), %rdx
	movq	%rax, %rcx
	addq	$16, %rcx
	cmpq	%rcx, %rdx
	je	.LBB13_7
# %bb.8:
	movq	%rdx, 608(%rsp)
	movq	(%rcx), %rdx
	movq	%rdx, 624(%rsp)
	jmp	.LBB13_9
.LBB13_7:
	movupd	(%rdx), %xmm0
	movupd	%xmm0, (%r15)
.LBB13_9:
	movq	8(%rax), %rdx
	movq	%rdx, 616(%rsp)
	movq	%rcx, (%rax)
	movq	$0, 8(%rax)
	movb	$0, (%rcx)
	leaq	72(%rsp), %rdi
	movq	608(%rsp), %rsi
.Ltmp125:
	movl	$17, %edx
	callq	_ZNSt13basic_filebufIcSt11char_traitsIcEE4openEPKcSt13_Ios_Openmode@PLT
.Ltmp126:
# %bb.10:
	movq	64(%rsp), %rcx
	addq	-24(%rcx), %rbx
	xorl	%esi, %esi
	testq	%rax, %rax
	jne	.LBB13_12
# %bb.11:
	movl	32(%rbx), %esi
	orl	$4, %esi
.LBB13_12:
.Ltmp127:
	movq	%rbx, %rdi
	callq	_ZNSt9basic_iosIcSt11char_traitsIcEE5clearESt12_Ios_Iostate@PLT
.Ltmp128:
# %bb.13:
	movq	608(%rsp), %rdi
	cmpq	%r15, %rdi
	je	.LBB13_15
# %bb.14:
	callq	_ZdlPv@PLT
.LBB13_15:
	movq	576(%rsp), %rdi
	leaq	592(%rsp), %rax
	cmpq	%rax, %rdi
	je	.LBB13_17
# %bb.16:
	callq	_ZdlPv@PLT
.LBB13_17:
	movq	8(%rsp), %rax                   # 8-byte Reload
	movq	48(%rax), %rbx
	cmpq	%rbx, 56(%rax)
	je	.LBB13_58
# %bb.18:
	xorl	%ebp, %ebp
	leaq	64(%rsp), %r12
	leaq	.L.str.16(%rip), %r13
	.p2align	4, 0x90
.LBB13_19:                              # =>This Inner Loop Header: Depth=1
	movq	(%rbx,%rbp,8), %rsi
.Ltmp130:
	movq	%r12, %rdi
	callq	_ZNSo9_M_insertImEERSoT_@PLT
.Ltmp131:
# %bb.20:                               #   in Loop: Header=BB13_19 Depth=1
.Ltmp132:
	movl	$1, %edx
	movq	%rax, %rdi
	movq	%r13, %rsi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp133:
# %bb.21:                               #   in Loop: Header=BB13_19 Depth=1
	incq	%rbp
	movq	8(%rsp), %rax                   # 8-byte Reload
	movq	48(%rax), %rbx
	movq	56(%rax), %r14
	movq	%r14, %r15
	subq	%rbx, %r15
	movq	%r15, %rax
	sarq	$3, %rax
	cmpq	%rax, %rbp
	jb	.LBB13_19
# %bb.22:
	cmpq	%r14, %rbx
	je	.LBB13_58
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
	jl	.LBB13_45
# %bb.25:
	leaq	8(%rbx), %r15
	movl	$1, %r13d
	movq	%rbx, %rbp
	jmp	.LBB13_26
	.p2align	4, 0x90
.LBB13_27:                              #   in Loop: Header=BB13_26 Depth=1
	leaq	(,%r13,8), %rdx
	movq	%r15, %rdi
	movq	%rbx, %rsi
	callq	memmove@PLT
	movq	%rbx, %rdx
.LBB13_35:                              #   in Loop: Header=BB13_26 Depth=1
	movq	%r12, (%rdx)
	incq	%r13
	cmpq	$16, %r13
	je	.LBB13_36
.LBB13_26:                              # =>This Loop Header: Depth=1
                                        #     Child Loop BB13_29 Depth 2
	movq	%rbp, %rax
	addq	$8, %rbp
	movq	8(%rax), %r12
	cmpq	(%rbx), %r12
	jb	.LBB13_27
# %bb.28:                               #   in Loop: Header=BB13_26 Depth=1
	movq	(%rax), %rcx
	movq	%rbp, %rdx
	cmpq	%rcx, %r12
	jae	.LBB13_35
	.p2align	4, 0x90
.LBB13_29:                              #   Parent Loop BB13_26 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movq	%rcx, 8(%rax)
	movq	-8(%rax), %rcx
	cmpq	%rcx, %r12
	jae	.LBB13_34
# %bb.30:                               #   in Loop: Header=BB13_29 Depth=2
	movq	%rcx, (%rax)
	movq	-16(%rax), %rcx
	cmpq	%rcx, %r12
	jae	.LBB13_31
# %bb.117:                              #   in Loop: Header=BB13_29 Depth=2
	movq	%rcx, -8(%rax)
	movq	-24(%rax), %rcx
	cmpq	%rcx, %r12
	jae	.LBB13_32
# %bb.118:                              #   in Loop: Header=BB13_29 Depth=2
	movq	%rcx, -16(%rax)
	movq	-32(%rax), %rcx
	addq	$-32, %rax
	cmpq	%rcx, %r12
	jb	.LBB13_29
# %bb.33:                               #   in Loop: Header=BB13_26 Depth=1
	addq	$8, %rax
	jmp	.LBB13_34
.LBB13_31:                              #   in Loop: Header=BB13_26 Depth=1
	addq	$-8, %rax
	jmp	.LBB13_34
.LBB13_32:                              #   in Loop: Header=BB13_26 Depth=1
	addq	$-16, %rax
.LBB13_34:                              #   in Loop: Header=BB13_26 Depth=1
	movq	%rax, %rdx
	jmp	.LBB13_35
.LBB13_45:
	leaq	8(%rbx), %r12
	cmpq	%r14, %r12
	je	.LBB13_58
# %bb.46:
	movq	%rbx, %r13
	jmp	.LBB13_47
.LBB13_54:                              #   in Loop: Header=BB13_47 Depth=1
	addq	$-8, %rax
	.p2align	4, 0x90
.LBB13_57:                              #   in Loop: Header=BB13_47 Depth=1
	movq	%rbp, (%rax)
	addq	$8, %r12
	addq	$8, %r13
	cmpq	%r14, %r12
	je	.LBB13_58
.LBB13_47:                              # =>This Loop Header: Depth=1
                                        #     Child Loop BB13_52 Depth 2
	movq	(%r12), %rbp
	cmpq	(%rbx), %rbp
	jae	.LBB13_50
# %bb.48:                               #   in Loop: Header=BB13_47 Depth=1
	movq	%r12, %rdx
	movq	%rbx, %rax
	subq	%rbx, %rdx
	je	.LBB13_57
# %bb.49:                               #   in Loop: Header=BB13_47 Depth=1
	movq	%r13, %rdi
	subq	%rdx, %rdi
	addq	$16, %rdi
	movq	%rbx, %rsi
	callq	memmove@PLT
	movq	%rbx, %rax
	jmp	.LBB13_57
	.p2align	4, 0x90
.LBB13_50:                              #   in Loop: Header=BB13_47 Depth=1
	movq	(%r13), %rcx
	movq	%r12, %rax
	cmpq	%rcx, %rbp
	jae	.LBB13_57
# %bb.51:                               #   in Loop: Header=BB13_47 Depth=1
	movq	%r13, %rax
	.p2align	4, 0x90
.LBB13_52:                              #   Parent Loop BB13_47 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movq	%rcx, 8(%rax)
	movq	-8(%rax), %rcx
	cmpq	%rcx, %rbp
	jae	.LBB13_57
# %bb.53:                               #   in Loop: Header=BB13_52 Depth=2
	movq	%rcx, (%rax)
	movq	-16(%rax), %rcx
	cmpq	%rcx, %rbp
	jae	.LBB13_54
# %bb.115:                              #   in Loop: Header=BB13_52 Depth=2
	movq	%rcx, -8(%rax)
	movq	-24(%rax), %rcx
	cmpq	%rcx, %rbp
	jae	.LBB13_55
# %bb.116:                              #   in Loop: Header=BB13_52 Depth=2
	movq	%rcx, -16(%rax)
	movq	-32(%rax), %rcx
	addq	$-32, %rax
	cmpq	%rcx, %rbp
	jb	.LBB13_52
# %bb.56:                               #   in Loop: Header=BB13_47 Depth=1
	addq	$8, %rax
	jmp	.LBB13_57
.LBB13_55:                              #   in Loop: Header=BB13_47 Depth=1
	addq	$-16, %rax
	jmp	.LBB13_57
.LBB13_36:
	leaq	128(%rbx), %rax
	jmp	.LBB13_37
.LBB13_41:                              #   in Loop: Header=BB13_37 Depth=1
	addq	$120, %rdx
	.p2align	4, 0x90
.LBB13_44:                              #   in Loop: Header=BB13_37 Depth=1
	movq	%rcx, (%rdx)
	addq	$8, %rax
	addq	$8, %rbx
.LBB13_37:                              # =>This Loop Header: Depth=1
                                        #     Child Loop BB13_40 Depth 2
	cmpq	%r14, %rax
	je	.LBB13_58
# %bb.38:                               #   in Loop: Header=BB13_37 Depth=1
	movq	-8(%rax), %rsi
	movq	(%rax), %rcx
	movq	%rax, %rdx
	cmpq	%rsi, %rcx
	jae	.LBB13_44
# %bb.39:                               #   in Loop: Header=BB13_37 Depth=1
	movq	%rbx, %rdx
	.p2align	4, 0x90
.LBB13_40:                              #   Parent Loop BB13_37 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movq	%rsi, 128(%rdx)
	movq	112(%rdx), %rsi
	cmpq	%rsi, %rcx
	jae	.LBB13_41
# %bb.119:                              #   in Loop: Header=BB13_40 Depth=2
	movq	%rsi, 120(%rdx)
	movq	104(%rdx), %rsi
	cmpq	%rsi, %rcx
	jae	.LBB13_42
# %bb.120:                              #   in Loop: Header=BB13_40 Depth=2
	movq	%rsi, 112(%rdx)
	movq	96(%rdx), %rsi
	cmpq	%rsi, %rcx
	jae	.LBB13_43
# %bb.121:                              #   in Loop: Header=BB13_40 Depth=2
	movq	%rsi, 104(%rdx)
	movq	88(%rdx), %rsi
	addq	$-32, %rdx
	cmpq	%rsi, %rcx
	jb	.LBB13_40
# %bb.122:                              #   in Loop: Header=BB13_37 Depth=1
	subq	$-128, %rdx
	jmp	.LBB13_44
.LBB13_42:                              #   in Loop: Header=BB13_37 Depth=1
	addq	$112, %rdx
	jmp	.LBB13_44
.LBB13_43:                              #   in Loop: Header=BB13_37 Depth=1
	addq	$104, %rdx
	jmp	.LBB13_44
.LBB13_58:
	movq	8(%rsp), %rax                   # 8-byte Reload
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
	je	.LBB13_59
# %bb.67:
	movq	%r15, %xmm1
	punpckldq	.LCPI13_0(%rip), %xmm1  # xmm1 = xmm1[0],mem[0],xmm1[1],mem[1]
	subpd	.LCPI13_1(%rip), %xmm1
	movapd	%xmm1, %xmm0
	unpckhpd	%xmm1, %xmm0                    # xmm0 = xmm0[1],xmm1[1]
	addsd	%xmm1, %xmm0
	cmpq	$1, %r15
	movq	%r15, %rax
	adcq	$0, %rax
	movq	%rax, %r11
	andq	$-2, %r11
	je	.LBB13_68
# %bb.123:
	leaq	-1(%r11), %rbx
	movsd	.LCPI13_2(%rip), %xmm1          # xmm1 = mem[0],zero
	divsd	%xmm0, %xmm1
	unpcklpd	%xmm1, %xmm1                    # xmm1 = xmm1[0,0]
	xorpd	%xmm2, %xmm2
	xorl	%r12d, %r12d
	movdqa	.LCPI13_3(%rip), %xmm3          # xmm3 = [4294967295,4294967295]
	movdqa	.LCPI13_4(%rip), %xmm4          # xmm4 = [4841369599423283200,4841369599423283200]
	movdqa	.LCPI13_5(%rip), %xmm5          # xmm5 = [4985484787499139072,4985484787499139072]
	movapd	.LCPI13_6(%rip), %xmm6          # xmm6 = [1.9342813118337666E+25,1.9342813118337666E+25]
	.p2align	4, 0x90
.LBB13_124:                             # =>This Inner Loop Header: Depth=1
	movdqu	(%r8,%r12,8), %xmm7
	movdqa	%xmm7, %xmm8
	pand	%xmm3, %xmm8
	por	%xmm4, %xmm8
	psrlq	$32, %xmm7
	por	%xmm5, %xmm7
	subpd	%xmm6, %xmm7
	addpd	%xmm8, %xmm7
	mulpd	%xmm1, %xmm7
	addpd	%xmm7, %xmm2
	addq	$2, %r12
	cmpq	%rbx, %r12
	jbe	.LBB13_124
# %bb.125:
	movapd	%xmm2, %xmm5
	unpckhpd	%xmm2, %xmm5                    # xmm5 = xmm5[1],xmm2[1]
	addsd	%xmm2, %xmm5
	cmpq	%r11, %rax
	jne	.LBB13_69
	jmp	.LBB13_126
.LBB13_59:
	xorpd	%xmm5, %xmm5
	jmp	.LBB13_126
.LBB13_68:
	xorl	%r11d, %r11d
	xorpd	%xmm5, %xmm5
.LBB13_69:
	movsd	.LCPI13_2(%rip), %xmm1          # xmm1 = mem[0],zero
	divsd	%xmm0, %xmm1
	movapd	.LCPI13_0(%rip), %xmm0          # xmm0 = [1127219200,1160773632,0,0]
	movapd	.LCPI13_1(%rip), %xmm2          # xmm2 = [4.503599627370496E+15,1.9342813113834067E+25]
	.p2align	4, 0x90
.LBB13_70:                              # =>This Inner Loop Header: Depth=1
	movsd	(%r8,%r11,8), %xmm3             # xmm3 = mem[0],zero
	unpcklps	%xmm0, %xmm3                    # xmm3 = xmm3[0],xmm0[0],xmm3[1],xmm0[1]
	subpd	%xmm2, %xmm3
	movapd	%xmm3, %xmm4
	unpckhpd	%xmm3, %xmm4                    # xmm4 = xmm4[1],xmm3[1]
	addsd	%xmm3, %xmm4
	mulsd	%xmm1, %xmm4
	addsd	%xmm4, %xmm5
	incq	%r11
	cmpq	%r11, %rax
	jne	.LBB13_70
.LBB13_126:
.Ltmp138:
	movapd	%xmm5, 48(%rsp)                 # 16-byte Spill
	movq	(%r8), %rax
	movq	%rax, 16(%rsp)                  # 8-byte Spill
	movq	-8(%r9), %r14
	movq	(%r8,%r10,4), %rbp
	movq	(%r8,%rcx,2), %r13
	movq	(%r8,%rsi,2), %rax
	movq	%rax, 40(%rsp)                  # 8-byte Spill
	movq	(%r8,%rdi,2), %rax
	movq	%rax, 32(%rsp)                  # 8-byte Spill
	movq	(%r8,%rdx,8), %rax
	movq	%rax, 24(%rsp)                  # 8-byte Spill
	movq	_ZSt4cout@GOTPCREL(%rip), %rbx
	leaq	.L.str.17(%rip), %rsi
	movl	$7, %edx
	movq	%rbx, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp139:
# %bb.127:
	movq	(%rbx), %rax
	movq	-24(%rax), %rax
	movq	$8, 16(%rbx,%rax)
.Ltmp140:
	movq	%rbx, %rdi
	movapd	48(%rsp), %xmm0                 # 16-byte Reload
	callq	_ZNSo9_M_insertIdEERSoT_@PLT
.Ltmp141:
# %bb.128:
.Ltmp142:
	movq	%rax, %rbx
	leaq	.L.str.18(%rip), %rsi
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
	leaq	.L.str.19(%rip), %rsi
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
	leaq	.L.str.20(%rip), %rsi
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
	movq	40(%rsp), %rsi                  # 8-byte Reload
	callq	_ZNSo9_M_insertImEERSoT_@PLT
.Ltmp153:
# %bb.134:
.Ltmp154:
	movq	%rax, %rbx
	leaq	.L.str.21(%rip), %rsi
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
	movq	32(%rsp), %rsi                  # 8-byte Reload
	callq	_ZNSo9_M_insertImEERSoT_@PLT
.Ltmp157:
# %bb.136:
.Ltmp158:
	movq	%rax, %rbx
	leaq	.L.str.22(%rip), %rsi
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
	movq	24(%rsp), %rsi                  # 8-byte Reload
	callq	_ZNSo9_M_insertImEERSoT_@PLT
.Ltmp161:
# %bb.138:
.Ltmp162:
	movq	%rax, %rbx
	leaq	.L.str.23(%rip), %rsi
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
	movq	16(%rsp), %rsi                  # 8-byte Reload
	callq	_ZNSo9_M_insertImEERSoT_@PLT
.Ltmp165:
# %bb.140:
.Ltmp166:
	movq	%rax, %rbx
	leaq	.L.str.24(%rip), %rsi
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
	leaq	.L.str.25(%rip), %rsi
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
	je	.LBB13_97
# %bb.145:
	cmpb	$0, 56(%r12)
	je	.LBB13_72
# %bb.146:
	movzbl	67(%r12), %eax
	jmp	.LBB13_74
.LBB13_72:
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
.LBB13_74:
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
	movq	8(%rsp), %rax                   # 8-byte Reload
	movq	(%rax), %rsi
	movq	8(%rax), %rdx
.Ltmp182:
	leaq	64(%rsp), %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp183:
# %bb.77:
.Ltmp184:
	movq	%rax, %rbx
	leaq	.L.str.15(%rip), %rsi
	movl	$3, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp185:
# %bb.78:
.Ltmp186:
	leaq	.L.str.17(%rip), %rsi
	movl	$7, %edx
	movq	%rbx, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp187:
# %bb.79:
	cvttsd2si	48(%rsp), %esi          # 16-byte Folded Reload
.Ltmp188:
	movq	%rbx, %rdi
	callq	_ZNSolsEi@PLT
.Ltmp189:
# %bb.80:
.Ltmp190:
	movq	%rax, %rbx
	leaq	.L.str.18(%rip), %rsi
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
	leaq	.L.str.19(%rip), %rsi
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
	leaq	.L.str.20(%rip), %rsi
	movl	$7, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp199:
# %bb.85:
.Ltmp200:
	movq	%rbx, %rdi
	movq	40(%rsp), %rsi                  # 8-byte Reload
	callq	_ZNSo9_M_insertImEERSoT_@PLT
.Ltmp201:
# %bb.86:
.Ltmp202:
	movq	%rax, %rbx
	leaq	.L.str.21(%rip), %rsi
	movl	$7, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp203:
# %bb.87:
.Ltmp204:
	movq	%rbx, %rdi
	movq	32(%rsp), %rsi                  # 8-byte Reload
	callq	_ZNSo9_M_insertImEERSoT_@PLT
.Ltmp205:
# %bb.88:
.Ltmp206:
	movq	%rax, %rbx
	leaq	.L.str.22(%rip), %rsi
	movl	$9, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp207:
# %bb.89:
.Ltmp208:
	movq	%rbx, %rdi
	movq	24(%rsp), %rsi                  # 8-byte Reload
	callq	_ZNSo9_M_insertImEERSoT_@PLT
.Ltmp209:
# %bb.90:
.Ltmp210:
	movq	%rax, %rbx
	leaq	.L.str.23(%rip), %rsi
	movl	$6, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.Ltmp211:
# %bb.91:
.Ltmp212:
	movq	%rbx, %rdi
	movq	16(%rsp), %rsi                  # 8-byte Reload
	callq	_ZNSo9_M_insertImEERSoT_@PLT
.Ltmp213:
# %bb.92:
.Ltmp214:
	movq	%rax, %rbx
	leaq	.L.str.24(%rip), %rsi
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
	leaq	.L.str.25(%rip), %rsi
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
	je	.LBB13_97
# %bb.100:
	cmpb	$0, 56(%r14)
	je	.LBB13_102
# %bb.101:
	movzbl	67(%r14), %eax
	jmp	.LBB13_104
.LBB13_102:
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
.LBB13_104:
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
	leaq	72(%rsp), %rdi
	callq	_ZNSt13basic_filebufIcSt11char_traitsIcEE5closeEv@PLT
.Ltmp231:
# %bb.107:
	testq	%rax, %rax
	jne	.LBB13_109
# %bb.108:
	movq	64(%rsp), %rax
	movq	-24(%rax), %rax
	leaq	(%rsp,%rax), %rdi
	addq	$64, %rdi
	movl	96(%rsp,%rax), %esi
	orl	$4, %esi
.Ltmp232:
	callq	_ZNSt9basic_iosIcSt11char_traitsIcEE5clearESt12_Ios_Iostate@PLT
.Ltmp233:
.LBB13_109:
	leaq	64(%rsp), %rdi
	callq	_ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev@PLT
	movq	%fs:40, %rax
	cmpq	640(%rsp), %rax
	jne	.LBB13_147
# %bb.110:
	addq	$648, %rsp                      # imm = 0x288
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
.LBB13_97:
	.cfi_def_cfa_offset 704
	movq	%fs:40, %rax
	cmpq	640(%rsp), %rax
	jne	.LBB13_147
# %bb.98:
.Ltmp234:
	callq	_ZSt16__throw_bad_castv@PLT
.Ltmp235:
# %bb.99:
.LBB13_2:
	movq	%fs:40, %rax
	cmpq	640(%rsp), %rax
	jne	.LBB13_147
# %bb.3:
.Ltmp237:
	leaq	.L.str.8(%rip), %rdi
	callq	_ZSt20__throw_length_errorPKc@PLT
.Ltmp238:
# %bb.4:
.LBB13_71:
.Ltmp137:
	jmp	.LBB13_112
.LBB13_60:
.Ltmp122:
	jmp	.LBB13_112
.LBB13_62:
.Ltmp129:
	movq	%rax, %rbx
	movq	608(%rsp), %rdi
	cmpq	%r15, %rdi
	je	.LBB13_64
# %bb.63:
	callq	_ZdlPv@PLT
	jmp	.LBB13_64
.LBB13_61:
.Ltmp239:
	movq	%rax, %rbx
.LBB13_64:
	movq	576(%rsp), %rdi
	leaq	592(%rsp), %rax
	cmpq	%rax, %rdi
	je	.LBB13_113
# %bb.65:
	callq	_ZdlPv@PLT
	jmp	.LBB13_113
.LBB13_66:
.Ltmp134:
	jmp	.LBB13_112
.LBB13_111:
.Ltmp236:
.LBB13_112:
	movq	%rax, %rbx
.LBB13_113:
	leaq	64(%rsp), %rdi
	callq	_ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev@PLT
	movq	%fs:40, %rax
	cmpq	640(%rsp), %rax
	jne	.LBB13_147
# %bb.114:
	movq	%rbx, %rdi
	callq	_Unwind_Resume@PLT
.LBB13_147:
	callq	__stack_chk_fail@PLT
.Lfunc_end13:
	.size	_ZN6TagObj26prepareReportAndDumpToFileEv, .Lfunc_end13-_ZN6TagObj26prepareReportAndDumpToFileEv
	.cfi_endproc
	.section	.gcc_except_table._ZN6TagObj26prepareReportAndDumpToFileEv,"aG",@progbits,_ZN6TagObj26prepareReportAndDumpToFileEv,comdat
	.p2align	2, 0x0
GCC_except_table13:
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
	.uleb128 .Lfunc_end13-.Ltmp238          #   Call between .Ltmp238 and .Lfunc_end13
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
	movq	%rsi, %r12
	subq	%rdi, %r12
	cmpq	$129, %r12
	jl	.LBB14_83
# %bb.1:
	movq	%rdx, %r14
	movq	%rdi, %rbx
	movq	%r12, %rax
	sarq	$3, %rax
	testq	%rdx, %rdx
	je	.LBB14_24
# %bb.2:
	leaq	8(%rbx), %rcx
	movq	%rcx, (%rsp)                    # 8-byte Spill
	movq	$-8, %rbp
	subq	%rbx, %rbp
	.p2align	4, 0x90
.LBB14_3:                               # =>This Loop Header: Depth=1
                                        #     Child Loop BB14_15 Depth 2
                                        #       Child Loop BB14_16 Depth 3
                                        #       Child Loop BB14_18 Depth 3
	shrq	%rax
	movq	8(%rbx), %rdx
	movq	(%rbx,%rax,8), %rdi
	movq	-8(%rsi), %rcx
	cmpq	%rdi, %rdx
	jae	.LBB14_6
# %bb.4:                                #   in Loop: Header=BB14_3 Depth=1
	cmpq	%rcx, %rdi
	jae	.LBB14_8
# %bb.5:                                #   in Loop: Header=BB14_3 Depth=1
	movq	(%rbx), %rcx
	movq	%rdi, (%rbx)
	movq	%rcx, (%rbx,%rax,8)
	jmp	.LBB14_14
	.p2align	4, 0x90
.LBB14_6:                               #   in Loop: Header=BB14_3 Depth=1
	cmpq	%rcx, %rdx
	jae	.LBB14_11
# %bb.7:                                #   in Loop: Header=BB14_3 Depth=1
	movq	(%rbx), %rax
	jmp	.LBB14_10
	.p2align	4, 0x90
.LBB14_8:                               #   in Loop: Header=BB14_3 Depth=1
	movq	(%rbx), %rax
	cmpq	%rcx, %rdx
	jae	.LBB14_10
# %bb.9:                                #   in Loop: Header=BB14_3 Depth=1
	movq	%rcx, (%rbx)
	movq	%rax, -8(%rsi)
	jmp	.LBB14_14
	.p2align	4, 0x90
.LBB14_10:                              #   in Loop: Header=BB14_3 Depth=1
	movq	%rdx, (%rbx)
	movq	%rax, 8(%rbx)
	jmp	.LBB14_14
	.p2align	4, 0x90
.LBB14_11:                              #   in Loop: Header=BB14_3 Depth=1
	movq	(%rbx), %rdx
	cmpq	%rcx, %rdi
	jae	.LBB14_13
# %bb.12:                               #   in Loop: Header=BB14_3 Depth=1
	movq	%rcx, (%rbx)
	movq	%rdx, -8(%rsi)
	jmp	.LBB14_14
.LBB14_13:                              #   in Loop: Header=BB14_3 Depth=1
	movq	%rdi, (%rbx)
	movq	%rdx, (%rbx,%rax,8)
	.p2align	4, 0x90
.LBB14_14:                              #   in Loop: Header=BB14_3 Depth=1
	decq	%r14
	movq	(%rsp), %r13                    # 8-byte Reload
	movq	%rsi, %rax
	.p2align	4, 0x90
.LBB14_15:                              #   Parent Loop BB14_3 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB14_16 Depth 3
                                        #       Child Loop BB14_18 Depth 3
	movq	(%rbx), %rcx
	movq	%rbp, %r12
	addq	%r13, %r12
	.p2align	4, 0x90
.LBB14_16:                              #   Parent Loop BB14_3 Depth=1
                                        #     Parent Loop BB14_15 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	movq	(%r13), %rdx
	addq	$8, %r13
	addq	$8, %r12
	cmpq	%rcx, %rdx
	jb	.LBB14_16
# %bb.17:                               #   in Loop: Header=BB14_15 Depth=2
	leaq	-8(%r13), %r15
	.p2align	4, 0x90
.LBB14_18:                              #   Parent Loop BB14_3 Depth=1
                                        #     Parent Loop BB14_15 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	movq	-8(%rax), %rdi
	addq	$-8, %rax
	cmpq	%rdi, %rcx
	jb	.LBB14_18
# %bb.19:                               #   in Loop: Header=BB14_15 Depth=2
	cmpq	%rax, %r15
	jae	.LBB14_21
# %bb.20:                               #   in Loop: Header=BB14_15 Depth=2
	movq	%rdi, (%r15)
	movq	%rdx, (%rax)
	jmp	.LBB14_15
	.p2align	4, 0x90
.LBB14_21:                              #   in Loop: Header=BB14_3 Depth=1
	movq	%r15, %rdi
	movq	%r14, %rdx
	callq	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPmSt6vectorImSaImEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_
	cmpq	$128, %r12
	jle	.LBB14_83
# %bb.22:                               #   in Loop: Header=BB14_3 Depth=1
	movq	%r12, %rax
	sarq	$3, %rax
	movq	%r15, %rsi
	testq	%r14, %r14
	jne	.LBB14_3
# %bb.23:
	addq	$-8, %r13
	movq	%r13, %rsi
.LBB14_24:
	leaq	-2(%rax), %rcx
	movq	%rcx, %rdx
	shrq	%rdx
	decq	%rax
	shrq	%rax
	orq	$1, %rcx
	movq	%rdx, %rdi
	jmp	.LBB14_27
	.p2align	4, 0x90
.LBB14_25:                              #   in Loop: Header=BB14_27 Depth=1
	movq	%r9, %r10
.LBB14_26:                              #   in Loop: Header=BB14_27 Depth=1
	movq	%r8, (%rbx,%r10,8)
	subq	$1, %rdi
	jb	.LBB14_55
.LBB14_27:                              # =>This Loop Header: Depth=1
                                        #     Child Loop BB14_31 Depth 2
                                        #     Child Loop BB14_50 Depth 2
	movq	(%rbx,%rdi,8), %r8
	movq	%rdi, %r9
	cmpq	%rdi, %rax
	jle	.LBB14_46
# %bb.28:                               #   in Loop: Header=BB14_27 Depth=1
	movq	%rdi, %r9
	jmp	.LBB14_31
	.p2align	4, 0x90
.LBB14_29:                              #   in Loop: Header=BB14_31 Depth=2
	leaq	2(,%r10,2), %r9
.LBB14_30:                              #   in Loop: Header=BB14_31 Depth=2
	movq	(%rbx,%r9,8), %r11
	movq	%r11, (%rbx,%r10,8)
	cmpq	%rax, %r9
	jge	.LBB14_46
.LBB14_31:                              #   Parent Loop BB14_27 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	leaq	(%r9,%r9), %r10
	movq	16(%rbx,%r10,8), %r11
	cmpq	8(%rbx,%r10,8), %r11
	jb	.LBB14_33
# %bb.32:                               #   in Loop: Header=BB14_31 Depth=2
	leaq	2(,%r9,2), %r10
	jmp	.LBB14_34
	.p2align	4, 0x90
.LBB14_33:                              #   in Loop: Header=BB14_31 Depth=2
	leaq	1(,%r9,2), %r10
.LBB14_34:                              #   in Loop: Header=BB14_31 Depth=2
	movq	(%rbx,%r10,8), %r11
	movq	%r11, (%rbx,%r9,8)
	cmpq	%rax, %r10
	jge	.LBB14_45
# %bb.35:                               #   in Loop: Header=BB14_31 Depth=2
	leaq	(%r10,%r10), %r9
	movq	16(%rbx,%r9,8), %r11
	cmpq	8(%rbx,%r9,8), %r11
	jb	.LBB14_37
# %bb.36:                               #   in Loop: Header=BB14_31 Depth=2
	leaq	2(,%r10,2), %r9
	jmp	.LBB14_38
	.p2align	4, 0x90
.LBB14_37:                              #   in Loop: Header=BB14_31 Depth=2
	leaq	1(,%r10,2), %r9
.LBB14_38:                              #   in Loop: Header=BB14_31 Depth=2
	movq	(%rbx,%r9,8), %r11
	movq	%r11, (%rbx,%r10,8)
	cmpq	%rax, %r9
	jge	.LBB14_46
# %bb.39:                               #   in Loop: Header=BB14_31 Depth=2
	leaq	(%r9,%r9), %r10
	movq	16(%rbx,%r10,8), %r11
	cmpq	8(%rbx,%r10,8), %r11
	jb	.LBB14_41
# %bb.40:                               #   in Loop: Header=BB14_31 Depth=2
	leaq	2(,%r9,2), %r10
	jmp	.LBB14_42
	.p2align	4, 0x90
.LBB14_41:                              #   in Loop: Header=BB14_31 Depth=2
	leaq	1(,%r9,2), %r10
.LBB14_42:                              #   in Loop: Header=BB14_31 Depth=2
	movq	(%rbx,%r10,8), %r11
	movq	%r11, (%rbx,%r9,8)
	cmpq	%rax, %r10
	jge	.LBB14_53
# %bb.43:                               #   in Loop: Header=BB14_31 Depth=2
	leaq	(%r10,%r10), %r9
	movq	16(%rbx,%r9,8), %r11
	cmpq	8(%rbx,%r9,8), %r11
	jae	.LBB14_29
# %bb.44:                               #   in Loop: Header=BB14_31 Depth=2
	leaq	1(,%r10,2), %r9
	jmp	.LBB14_30
.LBB14_45:                              #   in Loop: Header=BB14_27 Depth=1
	movq	%r10, %r9
	.p2align	4, 0x90
.LBB14_46:                              #   in Loop: Header=BB14_27 Depth=1
	testb	$8, %r12b
	jne	.LBB14_49
.LBB14_47:                              #   in Loop: Header=BB14_27 Depth=1
	cmpq	%rdx, %r9
	jne	.LBB14_49
# %bb.48:                               #   in Loop: Header=BB14_27 Depth=1
	movq	(%rbx,%rcx,8), %r9
	movq	%r9, (%rbx,%rdx,8)
	movq	%rcx, %r9
.LBB14_49:                              #   in Loop: Header=BB14_27 Depth=1
	cmpq	%rdi, %r9
	jle	.LBB14_25
	.p2align	4, 0x90
.LBB14_50:                              #   Parent Loop BB14_27 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	leaq	-1(%r9), %r10
	shrq	$63, %r10
	addq	%r9, %r10
	decq	%r10
	sarq	%r10
	movq	(%rbx,%r10,8), %r11
	cmpq	%r8, %r11
	jae	.LBB14_25
# %bb.51:                               #   in Loop: Header=BB14_50 Depth=2
	movq	%r11, (%rbx,%r9,8)
	movq	%r10, %r9
	cmpq	%rdi, %r10
	jg	.LBB14_50
	jmp	.LBB14_26
.LBB14_53:                              #   in Loop: Header=BB14_27 Depth=1
	movq	%r10, %r9
	testb	$8, %r12b
	je	.LBB14_47
	jmp	.LBB14_49
	.p2align	4, 0x90
.LBB14_54:                              #   in Loop: Header=BB14_55 Depth=1
	movq	%rax, (%rbx,%rdx,8)
	cmpq	$8, %rcx
	jle	.LBB14_83
.LBB14_55:                              # =>This Loop Header: Depth=1
                                        #     Child Loop BB14_59 Depth 2
                                        #     Child Loop BB14_79 Depth 2
	movq	-8(%rsi), %rax
	movq	(%rbx), %rcx
	movq	%rcx, -8(%rsi)
	addq	$-8, %rsi
	movq	%rsi, %rcx
	subq	%rbx, %rcx
	movq	%rcx, %rdi
	sarq	$3, %rdi
	cmpq	$17, %rcx
	jl	.LBB14_73
# %bb.56:                               #   in Loop: Header=BB14_55 Depth=1
	leaq	-1(%rdi), %rdx
	shrq	$63, %rdx
	leaq	(%rdi,%rdx), %r8
	decq	%r8
	sarq	%r8
	xorl	%edx, %edx
	jmp	.LBB14_59
	.p2align	4, 0x90
.LBB14_57:                              #   in Loop: Header=BB14_59 Depth=2
	leaq	2(,%r9,2), %rdx
.LBB14_58:                              #   in Loop: Header=BB14_59 Depth=2
	movq	(%rbx,%rdx,8), %r10
	movq	%r10, (%rbx,%r9,8)
	cmpq	%r8, %rdx
	jge	.LBB14_75
.LBB14_59:                              #   Parent Loop BB14_55 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	leaq	(%rdx,%rdx), %r9
	movq	16(%rbx,%r9,8), %r10
	cmpq	8(%rbx,%r9,8), %r10
	jb	.LBB14_61
# %bb.60:                               #   in Loop: Header=BB14_59 Depth=2
	leaq	2(,%rdx,2), %r9
	jmp	.LBB14_62
	.p2align	4, 0x90
.LBB14_61:                              #   in Loop: Header=BB14_59 Depth=2
	leaq	1(,%rdx,2), %r9
.LBB14_62:                              #   in Loop: Header=BB14_59 Depth=2
	movq	(%rbx,%r9,8), %r10
	movq	%r10, (%rbx,%rdx,8)
	cmpq	%r8, %r9
	jge	.LBB14_74
# %bb.63:                               #   in Loop: Header=BB14_59 Depth=2
	leaq	(%r9,%r9), %rdx
	movq	16(%rbx,%rdx,8), %r10
	cmpq	8(%rbx,%rdx,8), %r10
	jb	.LBB14_65
# %bb.64:                               #   in Loop: Header=BB14_59 Depth=2
	leaq	2(,%r9,2), %rdx
	jmp	.LBB14_66
	.p2align	4, 0x90
.LBB14_65:                              #   in Loop: Header=BB14_59 Depth=2
	leaq	1(,%r9,2), %rdx
.LBB14_66:                              #   in Loop: Header=BB14_59 Depth=2
	movq	(%rbx,%rdx,8), %r10
	movq	%r10, (%rbx,%r9,8)
	cmpq	%r8, %rdx
	jge	.LBB14_75
# %bb.67:                               #   in Loop: Header=BB14_59 Depth=2
	leaq	(%rdx,%rdx), %r9
	movq	16(%rbx,%r9,8), %r10
	cmpq	8(%rbx,%r9,8), %r10
	jb	.LBB14_69
# %bb.68:                               #   in Loop: Header=BB14_59 Depth=2
	leaq	2(,%rdx,2), %r9
	jmp	.LBB14_70
	.p2align	4, 0x90
.LBB14_69:                              #   in Loop: Header=BB14_59 Depth=2
	leaq	1(,%rdx,2), %r9
.LBB14_70:                              #   in Loop: Header=BB14_59 Depth=2
	movq	(%rbx,%r9,8), %r10
	movq	%r10, (%rbx,%rdx,8)
	cmpq	%r8, %r9
	jge	.LBB14_82
# %bb.71:                               #   in Loop: Header=BB14_59 Depth=2
	leaq	(%r9,%r9), %rdx
	movq	16(%rbx,%rdx,8), %r10
	cmpq	8(%rbx,%rdx,8), %r10
	jae	.LBB14_57
# %bb.72:                               #   in Loop: Header=BB14_59 Depth=2
	leaq	1(,%r9,2), %rdx
	jmp	.LBB14_58
	.p2align	4, 0x90
.LBB14_73:                              #   in Loop: Header=BB14_55 Depth=1
	xorl	%edx, %edx
	testb	$8, %cl
	je	.LBB14_76
	jmp	.LBB14_78
.LBB14_74:                              #   in Loop: Header=BB14_55 Depth=1
	movq	%r9, %rdx
	.p2align	4, 0x90
.LBB14_75:                              #   in Loop: Header=BB14_55 Depth=1
	testb	$8, %cl
	jne	.LBB14_78
.LBB14_76:                              #   in Loop: Header=BB14_55 Depth=1
	leaq	-2(%rdi), %r8
	shrq	$63, %r8
	addq	%r8, %rdi
	addq	$-2, %rdi
	sarq	%rdi
	cmpq	%rdi, %rdx
	jne	.LBB14_78
# %bb.77:                               #   in Loop: Header=BB14_55 Depth=1
	leaq	(%rdx,%rdx), %rdi
	movq	8(%rbx,%rdi,8), %rdi
	movq	%rdi, (%rbx,%rdx,8)
	leaq	1(,%rdx,2), %rdx
.LBB14_78:                              #   in Loop: Header=BB14_55 Depth=1
	testq	%rdx, %rdx
	jle	.LBB14_54
	.p2align	4, 0x90
.LBB14_79:                              #   Parent Loop BB14_55 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	leaq	-1(%rdx), %rdi
	movq	%rdi, %r8
	shrq	%r8
	movq	(%rbx,%r8,8), %r9
	cmpq	%rax, %r9
	jae	.LBB14_54
# %bb.80:                               #   in Loop: Header=BB14_79 Depth=2
	movq	%r9, (%rbx,%rdx,8)
	movq	%r8, %rdx
	cmpq	$1, %rdi
	ja	.LBB14_79
# %bb.81:                               #   in Loop: Header=BB14_55 Depth=1
	xorl	%edx, %edx
	jmp	.LBB14_54
.LBB14_82:                              #   in Loop: Header=BB14_55 Depth=1
	movq	%r9, %rdx
	testb	$8, %cl
	je	.LBB14_76
	jmp	.LBB14_78
.LBB14_83:
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
.Lfunc_end14:
	.size	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPmSt6vectorImSaImEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_, .Lfunc_end14-_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPmSt6vectorImSaImEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_
	.cfi_endproc
                                        # -- End function
	.section	.text.startup,"ax",@progbits
	.p2align	4, 0x90                         # -- Begin function _GLOBAL__sub_I_aes_ni.c
	.type	_GLOBAL__sub_I_aes_ni.c,@function
_GLOBAL__sub_I_aes_ni.c:                # 
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
.Lfunc_end15:
	.size	_GLOBAL__sub_I_aes_ni.c, .Lfunc_end15-_GLOBAL__sub_I_aes_ni.c
	.cfi_endproc
                                        # -- End function
	.type	_ZStL8__ioinit,@object          # 
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.type	_ZL12key_schedule,@object       # 
	.local	_ZL12key_schedule
	.comm	_ZL12key_schedule,320,16
	.type	.L.str,@object                  # 
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"EncryptTime"
	.size	.L.str, 12

	.type	.L.str.1,@object                # 
.L.str.1:
	.asciz	"DecryptTime"
	.size	.L.str.1, 12

	.type	.L__const.main.plain,@object    # 
	.section	.rodata.cst16,"aM",@progbits,16
	.p2align	4, 0x0
.L__const.main.plain:
	.ascii	"2C\366\250\210Z0\21511\230\242\3407\0074"
	.size	.L__const.main.plain, 16

	.type	.L__const.main.cipher,@object   # 
	.p2align	4, 0x0
.L__const.main.cipher:
	.ascii	"9%\204\035\002\334\t\373\334\021\205\227\031j\0132"
	.size	.L__const.main.cipher, 16

	.type	.L.str.2,@object                # 
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str.2:
	.asciz	"%d\n"
	.size	.L.str.2, 4

	.type	_ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj,@object # 
	.section	.bss._ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj,"aGw",@nobits,_ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj,comdat
	.weak	_ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj
	.p2align	3, 0x0
_ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj:
	.quad	0
	.size	_ZZN11CpuProfiler17getUniqueInstanceEjE11profilerObj, 8

	.type	.L.str.3,@object                # 
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str.3:
	.asciz	"CpuProfiler Constructor Called.\n"
	.size	.L.str.3, 33

	.type	.L.str.5,@object                # 
.L.str.5:
	.asciz	"Deleting old data files...\n"
	.size	.L.str.5, 28

	.type	.L.str.6,@object                # 
.L.str.6:
	.asciz	"cpuProfilerOutput_"
	.size	.L.str.6, 19

	.type	.L.str.7,@object                # 
.L.str.7:
	.asciz	".txt"
	.size	.L.str.7, 5

	.type	.L.str.8,@object                # 
.L.str.8:
	.asciz	"basic_string::append"
	.size	.L.str.8, 21

	.type	.L.str.9,@object                # 
.L.str.9:
	.asciz	"Tag "
	.size	.L.str.9, 5

	.type	.L.str.10,@object               # 
.L.str.10:
	.asciz	" not found...\n"
	.size	.L.str.10, 15

	.type	.L.str.11,@object               # 
.L.str.11:
	.asciz	"_Map_base::at"
	.size	.L.str.11, 14

	.type	.L.str.12,@object               # 
.L.str.12:
	.asciz	"ERROR: counter for tag "
	.size	.L.str.12, 24

	.type	.L.str.13,@object               # 
.L.str.13:
	.asciz	" not started\n"
	.size	.L.str.13, 14

	.type	.L.str.14,@object               # 
.L.str.14:
	.asciz	"vector::_M_realloc_insert"
	.size	.L.str.14, 26

	.type	.L.str.15,@object               # 
.L.str.15:
	.asciz	":: "
	.size	.L.str.15, 4

	.type	.L.str.16,@object               # 
.L.str.16:
	.asciz	"\n"
	.size	.L.str.16, 2

	.type	.L.str.17,@object               # 
.L.str.17:
	.asciz	" Mean: "
	.size	.L.str.17, 8

	.type	.L.str.18,@object               # 
.L.str.18:
	.asciz	" Median: "
	.size	.L.str.18, 10

	.type	.L.str.19,@object               # 
.L.str.19:
	.asciz	" 90th: "
	.size	.L.str.19, 8

	.type	.L.str.20,@object               # 
.L.str.20:
	.asciz	" 95th: "
	.size	.L.str.20, 8

	.type	.L.str.21,@object               # 
.L.str.21:
	.asciz	" 99th: "
	.size	.L.str.21, 8

	.type	.L.str.22,@object               # 
.L.str.22:
	.asciz	" 99.9th: "
	.size	.L.str.22, 10

	.type	.L.str.23,@object               # 
.L.str.23:
	.asciz	" Min: "
	.size	.L.str.23, 7

	.type	.L.str.24,@object               # 
.L.str.24:
	.asciz	" Max: "
	.size	.L.str.24, 7

	.type	.L.str.25,@object               # 
.L.str.25:
	.asciz	" Count: "
	.size	.L.str.25, 9

	.section	.init_array,"aw",@init_array
	.p2align	3, 0x90
	.quad	_GLOBAL__sub_I_aes_ni.c
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
