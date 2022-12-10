        global torusVertexGenerator

        section .text

torusVertexGenerator: 
        vmovss [rdi], xmm1;
        ret;

        section .data
one: db 2.137
