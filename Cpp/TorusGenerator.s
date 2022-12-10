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
	subq	$648, %rsp
	movq	%rdi, -616(%rbp)
	movl	%esi, -620(%rbp)
	vmovss	%xmm0, -624(%rbp)
	vmovss	%xmm1, -628(%rbp)
	vmovss	%xmm2, -632(%rbp)
	vmovss	%xmm3, -636(%rbp)
	movl	%edx, -640(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	vxorps	%xmm0, %xmm0, %xmm0
	vmovss	%xmm0, -600(%rbp)
	movl	-640(%rbp), %eax
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
	vmovss	%xmm0, -588(%rbp)
	vxorps	%xmm0, %xmm0, %xmm0
	vmovss	%xmm0, -96(%rbp)
	vmovss	.LC2(%rip), %xmm0
	vmovss	%xmm0, -92(%rbp)
	vxorps	%xmm0, %xmm0, %xmm0
	vmovss	%xmm0, -88(%rbp)
	vxorps	%xmm0, %xmm0, %xmm0
	vmovss	%xmm0, -84(%rbp)
	vxorps	%xmm0, %xmm0, %xmm0
	vmovss	%xmm0, -80(%rbp)
	vmovss	.LC2(%rip), %xmm0
	vmovss	%xmm0, -76(%rbp)
	vxorps	%xmm0, %xmm0, %xmm0
	vmovss	%xmm0, -72(%rbp)
	vxorps	%xmm0, %xmm0, %xmm0
	vmovss	%xmm0, -68(%rbp)
	vpxor	%xmm0, %xmm0, %xmm0
	vmovdqa	%xmm0, -64(%rbp)
	vmovdqa	%xmm0, -48(%rbp)
	vxorps	%xmm0, %xmm0, %xmm0
	vmovss	%xmm0, -552(%rbp)
	vxorps	%xmm0, %xmm0, %xmm0
	vmovss	%xmm0, -548(%rbp)
	vxorps	%xmm0, %xmm0, %xmm0
	vmovss	%xmm0, -544(%rbp)
	vxorps	%xmm0, %xmm0, %xmm0
	vmovss	%xmm0, -540(%rbp)
	vmovss	-632(%rbp), %xmm0
	vmovss	%xmm0, -536(%rbp)
	vmovss	-632(%rbp), %xmm0
	vmovss	%xmm0, -532(%rbp)
	vxorps	%xmm0, %xmm0, %xmm0
	vmovss	%xmm0, -528(%rbp)
	vmovss	-632(%rbp), %xmm0
	vmovss	%xmm0, -524(%rbp)
	vmovss	-552(%rbp), %xmm1
	vmovss	-548(%rbp), %xmm0
	vunpcklps	%xmm1, %xmm0, %xmm1
	vmovss	-544(%rbp), %xmm2
	vmovss	-540(%rbp), %xmm0
	vunpcklps	%xmm2, %xmm0, %xmm0
	vmovlhps	%xmm1, %xmm0, %xmm1
	vmovss	-536(%rbp), %xmm2
	vmovss	-532(%rbp), %xmm0
	vunpcklps	%xmm2, %xmm0, %xmm2
	vmovss	-528(%rbp), %xmm3
	vmovss	-524(%rbp), %xmm0
	vunpcklps	%xmm3, %xmm0, %xmm0
	vmovlhps	%xmm2, %xmm0, %xmm0
	vinsertf128	$0x1, %xmm1, %ymm0, %ymm0
	vmovaps	%ymm0, -496(%rbp)
	vmovss	.LC2(%rip), %xmm0
	vmovss	%xmm0, -584(%rbp)
	vmovss	.LC2(%rip), %xmm0
	vmovss	%xmm0, -580(%rbp)
	vmovss	.LC2(%rip), %xmm0
	vmovss	%xmm0, -576(%rbp)
	vmovss	.LC2(%rip), %xmm0
	vmovss	%xmm0, -572(%rbp)
	vmovss	-636(%rbp), %xmm0
	vmovss	%xmm0, -568(%rbp)
	vmovss	-636(%rbp), %xmm0
	vmovss	%xmm0, -564(%rbp)
	vmovss	-636(%rbp), %xmm0
	vmovss	%xmm0, -560(%rbp)
	vmovss	-636(%rbp), %xmm0
	vmovss	%xmm0, -556(%rbp)
	vmovss	-584(%rbp), %xmm1
	vmovss	-580(%rbp), %xmm0
	vunpcklps	%xmm1, %xmm0, %xmm1
	vmovss	-576(%rbp), %xmm2
	vmovss	-572(%rbp), %xmm0
	vunpcklps	%xmm2, %xmm0, %xmm0
	vmovlhps	%xmm1, %xmm0, %xmm1
	vmovss	-568(%rbp), %xmm2
	vmovss	-564(%rbp), %xmm0
	vunpcklps	%xmm2, %xmm0, %xmm2
	vmovss	-560(%rbp), %xmm3
	vmovss	-556(%rbp), %xmm0
	vunpcklps	%xmm3, %xmm0, %xmm0
	vmovlhps	%xmm2, %xmm0, %xmm0
	vinsertf128	$0x1, %xmm1, %ymm0, %ymm0
	vmovaps	%ymm0, -464(%rbp)
	movl	$0, -596(%rbp)
	jmp	.L10
.L18:
	movl	-624(%rbp), %eax
	vmovd	%eax, %xmm0
	call	_ZSt3cosf
	vmovd	%xmm0, %eax
	movl	%eax, -80(%rbp)
	vmovss	-80(%rbp), %xmm0
	vmovss	%xmm0, -96(%rbp)
	movl	-624(%rbp), %eax
	vmovd	%eax, %xmm0
	call	_ZSt3sinf
	vmovd	%xmm0, %eax
	movl	%eax, -72(%rbp)
	vmovss	-72(%rbp), %xmm0
	vmovss	%xmm0, -88(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, -520(%rbp)
	movq	-520(%rbp), %rax
	vmovups	(%rax), %ymm0
	vmovaps	%ymm0, -432(%rbp)
	movl	$0, -592(%rbp)
	jmp	.L12
.L17:
	movl	-600(%rbp), %eax
	vmovd	%eax, %xmm0
	call	_ZSt3cosf
	vmovd	%xmm0, %eax
	movl	%eax, -40(%rbp)
	vmovss	-40(%rbp), %xmm0
	vmovss	%xmm0, -48(%rbp)
	vmovss	-48(%rbp), %xmm0
	vmovss	%xmm0, -56(%rbp)
	vmovss	-56(%rbp), %xmm0
	vmovss	%xmm0, -64(%rbp)
	movl	-600(%rbp), %eax
	vmovd	%eax, %xmm0
	call	_ZSt3sinf
	vmovd	%xmm0, %eax
	movl	%eax, -44(%rbp)
	vmovss	-44(%rbp), %xmm0
	vmovss	%xmm0, -60(%rbp)
	leaq	-64(%rbp), %rax
	movq	%rax, -504(%rbp)
	movq	-504(%rbp), %rax
	vmovups	(%rax), %ymm0
	vmovaps	%ymm0, -400(%rbp)
	vmovaps	-400(%rbp), %ymm0
	vmovaps	%ymm0, -176(%rbp)
	vmovaps	-464(%rbp), %ymm0
	vmovaps	%ymm0, -144(%rbp)
	vmovaps	-176(%rbp), %ymm0
	vmulps	-144(%rbp), %ymm0, %ymm0
	vmovaps	%ymm0, -368(%rbp)
	vmovaps	-368(%rbp), %ymm0
	vmovaps	%ymm0, -240(%rbp)
	vmovaps	-496(%rbp), %ymm0
	vmovaps	%ymm0, -208(%rbp)
	vmovaps	-240(%rbp), %ymm0
	vaddps	-208(%rbp), %ymm0, %ymm0
	vmovaps	%ymm0, -368(%rbp)
	vmovaps	-368(%rbp), %ymm0
	vmovaps	%ymm0, -304(%rbp)
	vmovaps	-432(%rbp), %ymm0
	vmovaps	%ymm0, -272(%rbp)
	vmovaps	-304(%rbp), %ymm0
	vmulps	-272(%rbp), %ymm0, %ymm0
	vmovaps	%ymm0, -368(%rbp)
	movq	-616(%rbp), %rax
	movq	%rax, -512(%rbp)
	vmovaps	-368(%rbp), %ymm0
	vmovaps	%ymm0, -336(%rbp)
	vmovaps	-336(%rbp), %ymm0
	movq	-512(%rbp), %rax
	vmovups	%xmm0, (%rax)
	vextractf128	$0x1, %ymm0, 16(%rax)
	nop
	addq	$32, -616(%rbp)
	vmovss	-600(%rbp), %xmm0
	vaddss	-588(%rbp), %xmm0, %xmm0
	vmovss	%xmm0, -600(%rbp)
	incl	-592(%rbp)
.L12:
	movl	-592(%rbp), %eax
	cmpl	-640(%rbp), %eax
	jb	.L17
	vmovss	-624(%rbp), %xmm0
	vaddss	-628(%rbp), %xmm0, %xmm0
	vmovss	%xmm0, -624(%rbp)
	incl	-596(%rbp)
.L10:
	movl	-596(%rbp), %eax
	cmpl	-620(%rbp), %eax
	jb	.L18
	nop
	movq	-24(%rbp), %rax
	subq	%fs:40, %rax
	je	.L19
	call	__stack_chk_fail@PLT
.L19:
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
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	%edx, -32(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L21
.L24:
	movl	$0, -4(%rbp)
	jmp	.L22
.L23:
	movl	-8(%rbp), %eax
	imull	-32(%rbp), %eax
	movl	-4(%rbp), %edx
	leal	(%rax,%rdx), %ecx
	movq	-24(%rbp), %rax
	leaq	4(%rax), %rdx
	movq	%rdx, -24(%rbp)
	movl	%ecx, (%rax)
	movl	-8(%rbp), %eax
	incl	%eax
	imull	-32(%rbp), %eax
	movl	-4(%rbp), %edx
	leal	(%rax,%rdx), %ecx
	movq	-24(%rbp), %rax
	leaq	4(%rax), %rdx
	movq	%rdx, -24(%rbp)
	movl	%ecx, (%rax)
	movl	-8(%rbp), %eax
	incl	%eax
	imull	-32(%rbp), %eax
	movl	-4(%rbp), %edx
	addl	%edx, %eax
	leal	1(%rax), %ecx
	movq	-24(%rbp), %rax
	leaq	4(%rax), %rdx
	movq	%rdx, -24(%rbp)
	movl	%ecx, (%rax)
	movl	-8(%rbp), %eax
	imull	-32(%rbp), %eax
	movl	-4(%rbp), %edx
	leal	(%rax,%rdx), %ecx
	movq	-24(%rbp), %rax
	leaq	4(%rax), %rdx
	movq	%rdx, -24(%rbp)
	movl	%ecx, (%rax)
	movl	-8(%rbp), %eax
	imull	-32(%rbp), %eax
	movl	-4(%rbp), %edx
	addl	%edx, %eax
	leal	1(%rax), %ecx
	movq	-24(%rbp), %rax
	leaq	4(%rax), %rdx
	movq	%rdx, -24(%rbp)
	movl	%ecx, (%rax)
	movl	-8(%rbp), %eax
	incl	%eax
	imull	-32(%rbp), %eax
	movl	-4(%rbp), %edx
	addl	%edx, %eax
	leal	1(%rax), %ecx
	movq	-24(%rbp), %rax
	leaq	4(%rax), %rdx
	movq	%rdx, -24(%rbp)
	movl	%ecx, (%rax)
	incl	-4(%rbp)
.L22:
	movl	-32(%rbp), %eax
	decl	%eax
	movl	-4(%rbp), %edx
	cmpl	%eax, %edx
	jb	.L23
	incl	-8(%rbp)
.L21:
	movl	-28(%rbp), %eax
	decl	%eax
	movl	-8(%rbp), %edx
	cmpl	%eax, %edx
	jb	.L24
	nop
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5807:
	.size	torusIndexGenerator, .-torusIndexGenerator
	.section	.rodata
	.align 8
.LC1:
	.long	1413754136
	.long	1075388923
	.align 4
.LC2:
	.long	1065353216
	.ident	"GCC: (GNU) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
