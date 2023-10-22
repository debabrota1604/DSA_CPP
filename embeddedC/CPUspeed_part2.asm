section .bss
    tsc resb 8

section .text
global read_tsc
read_tsc:
    rdtsc
    mov [tsc], rax
    ret