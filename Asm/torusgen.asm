
segment .text
    global torusVertexGenerator
    extern cosf
    extern sinf
    default rel

%define torusStartCos   [rsp+248]
%define torusStartSin   [rsp+240]
%define ringCos         [rsp+232]
%define ringSin         [rsp+224]
%define ringAngleStep   [rsp+216]
%define outerLoopIndex  [rsp+208]
%define torusSin        [rsp+200]
%define torusCos        [rsp+192]
%define vertexPtr       [rsp+184]
%define steps           [rsp+176]
%define startAngle      [rsp+168]
%define torusAngleStep  [rsp+160]
%define torusSize       [rsp+152]
%define ringSize        [rsp+144]
%define ringResolution  [rsp+136]

%define vectorBuffer4    [rsp+128]
%define vectorBuffer3    [rsp+124]
%define vectorBuffer2    [rsp+120]
%define vectorBuffer1    [rsp+116]

%define unitVector4      [rsp+112]
%define unitVector3      [rsp+108]
%define unitVector2      [rsp+104]
%define unitVector1      [rsp+100]

%define ringDeltaMatrix4    [rsp+96]
%define ringDeltaMatrix3    [rsp+92]
%define ringDeltaMatrix2    [rsp+88]
%define ringDeltaMatrix1    [rsp+84]

%define torusDeltaMatrix4    [rsp+80]
%define torusDeltaMatrix3    [rsp+76]
%define torusDeltaMatrix2    [rsp+72]
%define torusDeltaMatrix1    [rsp+68]

%define torusPositionMatrix4    [rsp+64]
%define torusPositionMatrix3    [rsp+60]
%define torusPositionMatrix2    [rsp+56]
%define torusPositionMatrix1    [rsp+52]

%define ringPositionMatrix4    [rsp+48]
%define ringPositionMatrix3    [rsp+44]
%define ringPositionMatrix2    [rsp+40]
%define ringPositionMatrix1    [rsp+36]

%define torusSizeVector4    [rsp+32]
%define torusSizeVector3    [rsp+28]
%define torusSizeVector2    [rsp+24]
%define torusSizeVector1    [rsp+20]

%define ringSizeVector4     [rsp+16] 
%define ringSizeVector3     [rsp+12] 
%define ringSizeVector2     [rsp+8] 
%define ringSizeVector1     [rsp+4] 


torusVertexGenerator: 
    ; Trick with stack to align to 32 byte boundary - usefull for SIMD instructions
    mov r10, rsp
    and rsp, -32;
    push r10
    sub rsp, 256
    
    ;; Storing passed arguments on stack
    mov vertexPtr, rdi;
    mov steps, rsi;
    vmovd startAngle, xmm0;
    vmovd torusAngleStep, xmm1;
    vmovd torusSize, xmm2;
    vmovd ringSize, xmm3;
    mov ringResolution, rdx;

    ; Computing ringAngleStep
    vmovd xmm1, [tau]
    cvtsi2ss xmm0, ringResolution
    vdivss xmm0, xmm1, xmm0
    vmovd ringAngleStep, xmm0

    ; Computing trigonometric deltas for matrix
    vmovd xmm0, torusAngleStep
    call cosf WRT ..plt
    vmovd torusCos, xmm0

    vmovd xmm0, torusAngleStep
    call sinf WRT ..plt
    vmovd torusSin, xmm0

    vmovd xmm0, ringAngleStep
    call cosf WRT ..plt
    vmovd ringCos, xmm0

    vmovd xmm0, ringAngleStep
    call sinf WRT ..plt
    vmovd ringSin, xmm0

    vmovd xmm0, startAngle
    call cosf WRT ..plt
    vmovd torusStartCos, xmm0

    vmovd xmm0, startAngle
    call sinf WRT ..plt
    vmovd torusStartSin, xmm0

    ; preparing for iteration
    mov rcx, steps;

    ; Loading some useful constants
    vmovd xmm0, ringSize;
    vmovd xmm1, torusSize;
    vmovd xmm2, [zero];
    vmovd xmm3, [one];
    vmovd xmm4, torusStartCos
    vmovd xmm5, torusStartSin

    ; Setting up torus size vector
    vmovd torusSizeVector1, xmm1;
    vmovd torusSizeVector2, xmm2;
    vmovd torusSizeVector3, xmm1;
    vmovd torusSizeVector4, xmm2;

    ; Setting up ring size vector
    vmovd ringSizeVector1, xmm0;
    vmovd ringSizeVector2, xmm0;
    vmovd ringSizeVector3, xmm0;
    vmovd ringSizeVector4, xmm2;

    ; Setting up torus position matrix
    vmovd torusPositionMatrix1, xmm4
    vmovd torusPositionMatrix2, xmm5
    vmovd torusPositionMatrix3, xmm4
    vmovd torusPositionMatrix4, xmm5

    ; Setting up ring position matrix
    vmovd ringPositionMatrix1, xmm2
    vmovd ringPositionMatrix2, xmm3
    vmovd ringPositionMatrix3, xmm2
    vmovd ringPositionMatrix4, xmm3

    ; Setting up torus delta matrix
    vmovd xmm4, torusCos
    vmovd xmm5, torusSin
    vmovd xmm6, [zero]
    vsubss xmm6, xmm6, xmm5

    vmovd torusDeltaMatrix1, xmm4; cos(deltaTorus)
    vmovd torusDeltaMatrix2, xmm6; -sin(deltaTorus)
    vmovd torusDeltaMatrix3, xmm5; sin(deltaTorus)
    vmovd torusDeltaMatrix4, xmm4; cos(deltaTorus)

    ; Setting up ring delta matrix
    vmovd xmm4, ringCos
    vmovd xmm5, ringSin
    vmovd xmm6, [zero]
    vsubss xmm6, xmm6, xmm5

    vmovd ringDeltaMatrix1, xmm4; cos(deltaTorus)
    vmovd ringDeltaMatrix2, xmm6; -sin(deltaTorus)
    vmovd ringDeltaMatrix3, xmm5; sin(deltaTorus)
    vmovd ringDeltaMatrix4, xmm4; cos(deltaTorus)

    ;Setting up unit vector
    vmovd xmm0, [one]
    vmovd unitVector1, xmm0
    vmovd unitVector2, xmm0
    vmovd unitVector3, xmm0
    vmovd unitVector4, xmm0

    ; Setting up registers for the rest of the program
    vmovups xmm0, torusPositionMatrix1
    vmovups xmm1, torusDeltaMatrix1
    vmovups xmm2, torusSizeVector1

    vmovups xmm3, ringPositionMatrix1
    vmovups xmm4, ringDeltaMatrix1
    vmovups xmm5, ringSizeVector1

    vmovups xmm6, unitVector1

mainLoop:
    vsubss xmm7, xmm7, xmm7; xmm7=0

    vunpcklps xmm7, xmm0, xmm6; interleaving

    vinsertf128 ymm8, ymm8, xmm7, 0
    vinsertf128 ymm8, ymm8, xmm7, 1

    mov outerLoopIndex, rcx;
    mov rcx, ringResolution

    innerLoop:
        vmulps xmm7, xmm3, xmm5; multiply by ring size factor
        vaddps xmm7, xmm7, xmm2; add torus size vector

        vinsertf128 ymm9, ymm9, xmm7, 0
        vinsertf128 ymm9, ymm9, xmm3, 1

        vmulps ymm9, ymm8, ymm9

        vmovups [rdi], ymm9

        vmulps xmm7, xmm3, xmm4; apply ring transform
        vhaddps xmm3, xmm7, xmm7; compute new ring position matrix

        add rdi, 32
        add rax, 1
        sub rcx, 1;
        jnz innerLoop;

    vmulps xmm7, xmm0, xmm1; temp result to buffer
    vhaddps xmm0, xmm7, xmm7; compute new torus position matrix

    mov rcx, outerLoopIndex;
    sub rcx, 1;
    jnz mainLoop;

end:
    add rsp, 256
    pop rsp

    ret;

section .data
    one: dd 1.0
    zero: dd 0
    tau: dd 6.28318530718
    intOne: dd 1
    intZero: dd 0

