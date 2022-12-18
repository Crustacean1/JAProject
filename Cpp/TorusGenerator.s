	.file	"TorusGenerator.cpp"
	.text
	.section	.text._ZSt3cosf,"axG",@progbits,_ZSt3cosf,comdat
	.weak	_ZSt3cosf
	.type	_ZSt3cosf, @function
_ZSt3cosf:
.LFB48:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	vmovss	%xmm0, -4(%rbp)
	movl	-4(%rbp), %eax
	vmovd	%eax, %xmm0
	call	cosf@PLT
	vmovd	%xmm0, %eax
	vmovd	%eax, %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE48:
	.size	_ZSt3cosf, .-_ZSt3cosf
	.section	.text._ZSt3sinf,"axG",@progbits,_ZSt3sinf,comdat
	.weak	_ZSt3sinf
	.type	_ZSt3sinf, @function
_ZSt3sinf:
.LFB83:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	vmovss	%xmm0, -4(%rbp)
	movl	-4(%rbp), %eax
	vmovd	%eax, %xmm0
	call	sinf@PLT
	vmovd	%xmm0, %eax
	vmovd	%eax, %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE83:
	.size	_ZSt3sinf, .-_ZSt3sinf
	.section	.rodata
	.align 4
	.type	_ZL11VERTEX_SIZE, @object
	.size	_ZL11VERTEX_SIZE, 4
_ZL11VERTEX_SIZE:
	.long	8
	.globl	ones
	.data
	.align 16
	.type	ones, @object
	.size	ones, 17
ones:
	.long	1065353216
	.long	1065353216
	.long	1065353216
	.long	1065353216
	.globl	zeros
	.bss
	.align 16
	.type	zeros, @object
	.size	zeros, 16
zeros:
	.zero	16
	.globl	oneVector
	.align 16
	.type	oneVector, @object
	.size	oneVector, 16
oneVector:
	.zero	16
	.globl	zeroVector
	.align 16
	.type	zeroVector, @object
	.size	zeroVector, 16
zeroVector:
	.zero	16
	.text
	.globl	torusVertexGenerator
	.type	torusVertexGenerator, @function
torusVertexGenerator:
.LFB5806:
	.cfi_startproc
	leaq	8(%rsp), %r10
	.cfi_def_cfa 10, 0
	andq	$-32, %rsp
	pushq	-8(%r10)
	pushq	%rbp
	movq	%rsp, %rbp
	.cfi_escape 0x10,0x6,0x2,0x76,0
	pushq	%r10
	.cfi_escape 0xf,0x3,0x76,0x78,0x6
	subq	$1000, %rsp
	movq	%rdi, -968(%rbp)
	movl	%esi, -972(%rbp)
	vmovss	%xmm0, -976(%rbp)
	vmovss	%xmm1, -980(%rbp)
	vmovss	%xmm2, -984(%rbp)
	vmovss	%xmm3, -988(%rbp)
	movl	%edx, -992(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	vxorps	%xmm0, %xmm0, %xmm0
	vmovss	%xmm0, -952(%rbp)
	movl	-992(%rbp), %eax
	testq	%rax, %rax
	js	.L6
	vcvtsi2sdq	%rax, %xmm0, %xmm0
	jmp	.L7
.L6:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	vcvtsi2sdq	%rdx, %xmm0, %xmm0
	vaddsd	%xmm0, %xmm0, %xmm0
.L7:
	vmovsd	.LC1(%rip), %xmm1
	vdivsd	%xmm0, %xmm1, %xmm0
	vcvtsd2ss	%xmm0, %xmm0, %xmm0
	vmovss	%xmm0, -940(%rbp)
	movl	-976(%rbp), %eax
	vmovd	%eax, %xmm0
	call	_ZSt3cosf
	vmovd	%xmm0, %eax
	movl	%eax, -96(%rbp)
	movl	-976(%rbp), %eax
	vmovd	%eax, %xmm0
	call	_ZSt3sinf
	vmovd	%xmm0, %eax
	movl	%eax, -92(%rbp)
	movl	-976(%rbp), %eax
	vmovd	%eax, %xmm0
	call	_ZSt3cosf
	vmovd	%xmm0, %eax
	movl	%eax, -88(%rbp)
	movl	-976(%rbp), %eax
	vmovd	%eax, %xmm0
	call	_ZSt3sinf
	vmovd	%xmm0, %eax
	movl	%eax, -84(%rbp)
	vmovss	.LC2(%rip), %xmm0
	vmovss	%xmm0, -80(%rbp)
	vxorps	%xmm0, %xmm0, %xmm0
	vmovss	%xmm0, -76(%rbp)
	vmovss	.LC2(%rip), %xmm0
	vmovss	%xmm0, -72(%rbp)
	vxorps	%xmm0, %xmm0, %xmm0
	vmovss	%xmm0, -68(%rbp)
	movl	-980(%rbp), %eax
	vmovd	%eax, %xmm0
	call	_ZSt3cosf
	vmovd	%xmm0, %eax
	movl	%eax, -64(%rbp)
	movl	-980(%rbp), %eax
	vmovd	%eax, %xmm0
	call	_ZSt3sinf
	vmovd	%xmm0, %eax
	vmovss	.LC3(%rip), %xmm0
	vmovd	%eax, %xmm4
	vxorps	%xmm0, %xmm4, %xmm0
	vmovss	%xmm0, -60(%rbp)
	movl	-980(%rbp), %eax
	vmovd	%eax, %xmm0
	call	_ZSt3sinf
	vmovd	%xmm0, %eax
	movl	%eax, -56(%rbp)
	movl	-980(%rbp), %eax
	vmovd	%eax, %xmm0
	call	_ZSt3cosf
	vmovd	%xmm0, %eax
	movl	%eax, -52(%rbp)
	movl	-940(%rbp), %eax
	vmovd	%eax, %xmm0
	call	_ZSt3cosf
	vmovd	%xmm0, %eax
	movl	%eax, -48(%rbp)
	movl	-940(%rbp), %eax
	vmovd	%eax, %xmm0
	call	_ZSt3sinf
	vmovd	%xmm0, %eax
	vmovss	.LC3(%rip), %xmm0
	vmovd	%eax, %xmm5
	vxorps	%xmm0, %xmm5, %xmm0
	vmovss	%xmm0, -44(%rbp)
	movl	-940(%rbp), %eax
	vmovd	%eax, %xmm0
	call	_ZSt3sinf
	vmovd	%xmm0, %eax
	movl	%eax, -40(%rbp)
	movl	-940(%rbp), %eax
	vmovd	%eax, %xmm0
	call	_ZSt3cosf
	vmovd	%xmm0, %eax
	movl	%eax, -36(%rbp)
	vxorps	%xmm0, %xmm0, %xmm0
	vmovss	%xmm0, -904(%rbp)
	vxorps	%xmm0, %xmm0, %xmm0
	vmovss	%xmm0, -900(%rbp)
	vxorps	%xmm0, %xmm0, %xmm0
	vmovss	%xmm0, -896(%rbp)
	vxorps	%xmm0, %xmm0, %xmm0
	vmovss	%xmm0, -892(%rbp)
	vxorps	%xmm0, %xmm0, %xmm0
	vmovss	%xmm0, -888(%rbp)
	vmovss	-984(%rbp), %xmm0
	vmovss	%xmm0, -884(%rbp)
	vxorps	%xmm0, %xmm0, %xmm0
	vmovss	%xmm0, -880(%rbp)
	vmovss	-984(%rbp), %xmm0
	vmovss	%xmm0, -876(%rbp)
	vmovss	-904(%rbp), %xmm1
	vmovss	-900(%rbp), %xmm0
	vunpcklps	%xmm1, %xmm0, %xmm1
	vmovss	-896(%rbp), %xmm2
	vmovss	-892(%rbp), %xmm0
	vunpcklps	%xmm2, %xmm0, %xmm0
	vmovlhps	%xmm1, %xmm0, %xmm1
	vmovss	-888(%rbp), %xmm2
	vmovss	-884(%rbp), %xmm0
	vunpcklps	%xmm2, %xmm0, %xmm2
	vmovss	-880(%rbp), %xmm3
	vmovss	-876(%rbp), %xmm0
	vunpcklps	%xmm3, %xmm0, %xmm0
	vmovlhps	%xmm2, %xmm0, %xmm0
	vinsertf128	$0x1, %xmm1, %ymm0, %ymm0
	vmovaps	%ymm0, -432(%rbp)
	vmovss	.LC2(%rip), %xmm0
	vmovss	%xmm0, -936(%rbp)
	vmovss	.LC2(%rip), %xmm0
	vmovss	%xmm0, -932(%rbp)
	vmovss	.LC2(%rip), %xmm0
	vmovss	%xmm0, -928(%rbp)
	vmovss	.LC2(%rip), %xmm0
	vmovss	%xmm0, -924(%rbp)
	vxorps	%xmm0, %xmm0, %xmm0
	vmovss	%xmm0, -920(%rbp)
	vmovss	-988(%rbp), %xmm0
	vmovss	%xmm0, -916(%rbp)
	vmovss	-988(%rbp), %xmm0
	vmovss	%xmm0, -912(%rbp)
	vmovss	-988(%rbp), %xmm0
	vmovss	%xmm0, -908(%rbp)
	vmovss	-936(%rbp), %xmm1
	vmovss	-932(%rbp), %xmm0
	vunpcklps	%xmm1, %xmm0, %xmm1
	vmovss	-928(%rbp), %xmm2
	vmovss	-924(%rbp), %xmm0
	vunpcklps	%xmm2, %xmm0, %xmm0
	vmovlhps	%xmm1, %xmm0, %xmm1
	vmovss	-920(%rbp), %xmm2
	vmovss	-916(%rbp), %xmm0
	vunpcklps	%xmm2, %xmm0, %xmm2
	vmovss	-912(%rbp), %xmm3
	vmovss	-908(%rbp), %xmm0
	vunpcklps	%xmm3, %xmm0, %xmm0
	vmovlhps	%xmm2, %xmm0, %xmm0
	vinsertf128	$0x1, %xmm1, %ymm0, %ymm0
	vmovaps	%ymm0, -400(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, -848(%rbp)
	movq	-848(%rbp), %rax
	vmovaps	(%rax), %xmm0
	vmovaps	%xmm0, -832(%rbp)
	leaq	-64(%rbp), %rax
	movq	%rax, -856(%rbp)
	movq	-856(%rbp), %rax
	vmovups	(%rax), %xmm0
	vmovaps	%xmm0, -800(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, -864(%rbp)
	movq	-864(%rbp), %rax
	vmovaps	(%rax), %xmm0
	vmovaps	%xmm0, -816(%rbp)
	leaq	-48(%rbp), %rax
	movq	%rax, -872(%rbp)
	movq	-872(%rbp), %rax
	vmovups	(%rax), %xmm0
	vmovaps	%xmm0, -784(%rbp)
	movl	$0, -948(%rbp)
	jmp	.L14
.L30:
	vmovaps	-832(%rbp), %xmm0
	vmovaps	%xmm0, -688(%rbp)
	vmovaps	-800(%rbp), %xmm0
	vmovaps	%xmm0, -672(%rbp)
	vmovaps	-688(%rbp), %xmm0
	vmulps	-672(%rbp), %xmm0, %xmm0
	vmovaps	%xmm0, -768(%rbp)
	vmovaps	-768(%rbp), %xmm0
	vmovaps	%xmm0, -720(%rbp)
	vmovaps	-768(%rbp), %xmm0
	vmovaps	%xmm0, -704(%rbp)
	vmovaps	-720(%rbp), %xmm0
	vhaddps	-704(%rbp), %xmm0, %xmm0
	nop
	vmovaps	%xmm0, -832(%rbp)
	vmovaps	-832(%rbp), %xmm0
	vpermilps	$212, %xmm0, %xmm0
	vmovaps	%xmm0, -752(%rbp)
	vmovaps	oneVector(%rip), %xmm1
	vmovaps	-752(%rbp), %xmm0
	vblendps	$10, %xmm1, %xmm0, %xmm0
	vmovaps	%xmm0, -752(%rbp)
	movl	$0, -944(%rbp)
	jmp	.L17
.L29:
	vmovaps	-816(%rbp), %xmm0
	vmovaps	%xmm0, -624(%rbp)
	vmovaps	-784(%rbp), %xmm0
	vmovaps	%xmm0, -608(%rbp)
	vmovaps	-624(%rbp), %xmm0
	vmulps	-608(%rbp), %xmm0, %xmm0
	vmovaps	%xmm0, -768(%rbp)
	vmovaps	-768(%rbp), %xmm0
	vmovaps	%xmm0, -656(%rbp)
	vmovaps	-768(%rbp), %xmm0
	vmovaps	%xmm0, -640(%rbp)
	vmovaps	-656(%rbp), %xmm0
	vhaddps	-640(%rbp), %xmm0, %xmm0
	nop
	vmovaps	%xmm0, -816(%rbp)
	vmovaps	-816(%rbp), %xmm0
	vpermilps	$68, %xmm0, %xmm0
	vmovaps	%xmm0, -736(%rbp)
	vmovaps	-736(%rbp), %xmm0
	vmovaps	%xmm0, -592(%rbp)
	vmovaps	-736(%rbp), %xmm0
	vmovaps	%xmm0, -576(%rbp)
	vmovaps	-576(%rbp), %xmm0
	vmovaps	%xmm0, -560(%rbp)
	vmovaps	-592(%rbp), %xmm0
	vmovaps	%xmm0, -544(%rbp)
	vmovaps	-544(%rbp), %xmm0
	vmovaps	%xmm0, -528(%rbp)
	vmovaps	-528(%rbp), %xmm0
	nop
	vinsertf128	$0x1, -560(%rbp), %ymm0, %ymm0
	nop
	vmovaps	%ymm0, -368(%rbp)
	vmovaps	-368(%rbp), %ymm0
	vmovaps	%ymm0, -272(%rbp)
	vmovaps	-400(%rbp), %ymm0
	vmovaps	%ymm0, -240(%rbp)
	vmovaps	-272(%rbp), %ymm0
	vmulps	-240(%rbp), %ymm0, %ymm0
	vmovaps	%ymm0, -368(%rbp)
	vmovaps	-368(%rbp), %ymm0
	vmovaps	%ymm0, -336(%rbp)
	vmovaps	-432(%rbp), %ymm0
	vmovaps	%ymm0, -304(%rbp)
	vmovaps	-336(%rbp), %ymm0
	vaddps	-304(%rbp), %ymm0, %ymm0
	vmovaps	%ymm0, -368(%rbp)
	vmovaps	-752(%rbp), %xmm0
	vmovaps	%xmm0, -512(%rbp)
	vmovaps	-752(%rbp), %xmm0
	vmovaps	%xmm0, -496(%rbp)
	vmovaps	-496(%rbp), %xmm0
	vmovaps	%xmm0, -480(%rbp)
	vmovaps	-512(%rbp), %xmm0
	vmovaps	%xmm0, -464(%rbp)
	vmovaps	-464(%rbp), %xmm0
	vmovaps	%xmm0, -448(%rbp)
	vmovaps	-448(%rbp), %xmm0
	nop
	vinsertf128	$0x1, -480(%rbp), %ymm0, %ymm0
	nop
	vmovaps	-368(%rbp), %ymm1
	vmovaps	%ymm1, -176(%rbp)
	vmovaps	%ymm0, -144(%rbp)
	vmovaps	-176(%rbp), %ymm0
	vmulps	-144(%rbp), %ymm0, %ymm0
	vmovaps	%ymm0, -368(%rbp)
	movq	-968(%rbp), %rax
	movq	%rax, -840(%rbp)
	vmovaps	-368(%rbp), %ymm0
	vmovaps	%ymm0, -208(%rbp)
	vmovaps	-208(%rbp), %ymm0
	movq	-840(%rbp), %rax
	vmovups	%xmm0, (%rax)
	vextractf128	$0x1, %ymm0, 16(%rax)
	nop
	addq	$32, -968(%rbp)
	vmovss	-952(%rbp), %xmm0
	vaddss	-940(%rbp), %xmm0, %xmm0
	vmovss	%xmm0, -952(%rbp)
	incl	-944(%rbp)
.L17:
	movl	-944(%rbp), %eax
	cmpl	-992(%rbp), %eax
	jb	.L29
	vmovss	-976(%rbp), %xmm0
	vaddss	-980(%rbp), %xmm0, %xmm0
	vmovss	%xmm0, -976(%rbp)
	incl	-948(%rbp)
.L14:
	movl	-948(%rbp), %eax
	cmpl	-972(%rbp), %eax
	jb	.L30
	nop
	movq	-24(%rbp), %rax
	subq	%fs:40, %rax
	je	.L31
	call	__stack_chk_fail@PLT
.L31:
	movq	-8(%rbp), %r10
	.cfi_def_cfa 10, 0
	leave
	leaq	-8(%r10), %rsp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5806:
	.size	torusVertexGenerator, .-torusVertexGenerator
	.globl	torusIndexGenerator
	.type	torusIndexGenerator, @function
torusIndexGenerator:
.LFB5807:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -40(%rbp)
	movl	%esi, -44(%rbp)
	movl	%edx, -48(%rbp)
	movl	$0, -24(%rbp)
	jmp	.L33
.L36:
	movl	$0, -20(%rbp)
	jmp	.L34
.L35:
	movl	-24(%rbp), %eax
	imull	-48(%rbp), %eax
	movl	-20(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -16(%rbp)
	movl	-24(%rbp), %eax
	incl	%eax
	movl	$0, %edx
	divl	-44(%rbp)
	movl	%edx, %eax
	imull	-48(%rbp), %eax
	movl	-20(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -12(%rbp)
	movl	-24(%rbp), %eax
	imull	-48(%rbp), %eax
	movl	%eax, %ecx
	movl	-20(%rbp), %eax
	incl	%eax
	movl	$0, %edx
	divl	-48(%rbp)
	movl	%edx, %eax
	addl	%ecx, %eax
	movl	%eax, -8(%rbp)
	movl	-24(%rbp), %eax
	incl	%eax
	movl	$0, %edx
	divl	-44(%rbp)
	movl	%edx, %eax
	imull	-48(%rbp), %eax
	movl	%eax, %ecx
	movl	-20(%rbp), %eax
	incl	%eax
	movl	$0, %edx
	divl	-48(%rbp)
	movl	%edx, %eax
	addl	%ecx, %eax
	movl	%eax, -4(%rbp)
	movl	-16(%rbp), %ecx
	movq	-40(%rbp), %rax
	leaq	4(%rax), %rdx
	movq	%rdx, -40(%rbp)
	movl	%ecx, (%rax)
	movl	-12(%rbp), %ecx
	movq	-40(%rbp), %rax
	leaq	4(%rax), %rdx
	movq	%rdx, -40(%rbp)
	movl	%ecx, (%rax)
	movl	-4(%rbp), %ecx
	movq	-40(%rbp), %rax
	leaq	4(%rax), %rdx
	movq	%rdx, -40(%rbp)
	movl	%ecx, (%rax)
	movl	-16(%rbp), %ecx
	movq	-40(%rbp), %rax
	leaq	4(%rax), %rdx
	movq	%rdx, -40(%rbp)
	movl	%ecx, (%rax)
	movl	-8(%rbp), %ecx
	movq	-40(%rbp), %rax
	leaq	4(%rax), %rdx
	movq	%rdx, -40(%rbp)
	movl	%ecx, (%rax)
	movl	-4(%rbp), %ecx
	movq	-40(%rbp), %rax
	leaq	4(%rax), %rdx
	movq	%rdx, -40(%rbp)
	movl	%ecx, (%rax)
	incl	-20(%rbp)
.L34:
	movl	-20(%rbp), %eax
	cmpl	-48(%rbp), %eax
	jb	.L35
	incl	-24(%rbp)
.L33:
	movl	-24(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jb	.L36
	nop
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5807:
	.size	torusIndexGenerator, .-torusIndexGenerator
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB5958:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	cmpl	$1, -20(%rbp)
	jne	.L41
	cmpl	$65535, -24(%rbp)
	jne	.L41
	leaq	ones(%rip), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	vmovups	(%rax), %xmm0
	vmovaps	%xmm0, oneVector(%rip)
	leaq	zeros(%rip), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	vmovups	(%rax), %xmm0
	vmovaps	%xmm0, zeroVector(%rip)
.L41:
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5958:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_ones, @function
_GLOBAL__sub_I_ones:
.LFB5959:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5959:
	.size	_GLOBAL__sub_I_ones, .-_GLOBAL__sub_I_ones
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_ones
	.section	.rodata
	.align 8
.LC1:
	.long	1413754136
	.long	1075388923
	.align 4
.LC2:
	.long	1065353216
	.align 16
.LC3:
	.long	-2147483648
	.long	0
	.long	0
	.long	0
	.ident	"GCC: (GNU) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
