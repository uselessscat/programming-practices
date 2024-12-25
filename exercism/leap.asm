section .data
    output db "Valor de rax: %ld", 0

section .text
global leap_year
leap_year:
    push rbp
    mov  rbp, rsp

    mov rax, rdi
    mov qword [rbp - 8], rax
    mov qword [rbp - 16], 100
    mov qword [rbp - 24], 400

; is divisible by 4
    mov rax, qword [rbp - 8]
    and rax, 3
    test rax, rax
    jne ret_false

; should not be divisible by 100
    mov rax, qword [rbp - 8]
    cqo
    idiv qword [rbp - 16]
    test rdx, rdx
    jne ret_true

; is divisible by 400
    mov rax, qword [rbp - 8]
    cqo
    idiv qword [rbp - 24]
    test rdx, rdx
    jne ret_false

ret_true:
    mov rax, 1
    jmp ret

ret_false:
    mov rax, 0

ret:
    pop rbp
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
