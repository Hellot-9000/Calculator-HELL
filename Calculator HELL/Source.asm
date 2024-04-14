.586  ;This directive tells the assembler to use instructions up to the 586 instruction set, which corresponds to the Pentium processor.

.MODEL FLAT, C  ; This directive sets the memory model to FLAT (meaning the program can access up to 4GB of memory), and sets the calling convention to C (meaning it uses the standard C calling convention).

.STACK  ; This directive reserves a stack segment for the program.

.DATA  ; This directive would normally be used to declare initialized data. In this case, it's empty.

.CODE  ; This directive is used to mark the beginning of the code section.

PUBLIC add_asm  ; The PUBLIC directive makes this procedure accessible from outside the file.

add_asm PROC, arg1:DWORD, arg2:DWORD  ; This is a procedure named add_asm that takes two DWORD (32-bit) arguments, arg1 and arg2.
    mov eax, arg1  ; It moves arg1 into the eax register,
    add eax, arg2  ; adds arg2 to eax,
    ret  ; and then returns.
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
    imul eax, arg2  ; The imul instruction is used for signed multiplication.
    ret
mul_asm ENDP

PUBLIC div_asm

div_asm PROC, arg1:DWORD, arg2:DWORD
    mov eax, arg1
    cdq  ; The cdq instruction is used to sign-extend the 32-bit eax register into the 64-bit edx:eax register pair, in preparation for division.
    idiv arg2  ; The idiv instruction is used for signed division.
    ret
div_asm ENDP

END  ; This directive marks the end of the source file.
