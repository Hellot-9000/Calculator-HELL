.586
.MODEL FLAT, C
.STACK
.DATA
.CODE

PUBLIC add_asm

add_asm PROC, arg1:DWORD, arg2:DWORD
    mov eax, arg1
    add eax, arg2
    ret
add_asm ENDP

PUBLIC sub_asm

sub_asm PROC, arg1:DWORD, arg2:DWORD
    mov eax, arg1
    sub eax, arg2
    ret
sub_asm ENDP

PUBLIC mul_asm

mul_asm PROC, arg1:DWORD, arg2:DWORD
    mov eax, arg1
    imul eax, arg2
    ret
mul_asm ENDP

PUBLIC div_asm

div_asm PROC, arg1:DWORD, arg2:DWORD
    mov eax, arg1
    cdq
    idiv arg2
    ret
div_asm ENDP

END
