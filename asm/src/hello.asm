section .data
    buffer db '0000', 0, 10    ; buffer to store the stirng representation of addition

section .text
global _start

_start:
    mov eax, 10     ; move 10 to eax register     
    add eax, 20     ; add 20 to the value in eax  

    ; Convert number to string
    mov ecx, buffer ; initialize buffer pointer
    add ecx, 3      ; load the number back into eax
    mov byte [ecx], 10 ; Add new line character
    dec ecx         ; Move to the last character position

convert_loop:
    mov ebx, 10      ; Divisor
    xor edx, edx     ; Clear EDX for division
    div ebx          ; Divide EAX by 10, quotient in EAX, remainder in EDX
    add dl, '0'      ; Convert remainder to ASCII
    mov [ecx], dl    ; Store ASCII character in buffer
    dec ecx          ; Move to the next position
    test eax, eax    ; Check if quotient is zero
    jnz convert_loop ; Repeat if quotient is not zero

    ; Print the string
    mov eax, 4      ; sys_write system call number
    mov ebx, 1      ; file descriptor 1 (stdout)
    lea ecx, [ecx+1] ; pointer to the buffer
    mov edx, 4      ; number of bytes to write
    int 0x80        ; call kernel to execute sys call

    ; Exit system call
    mov eax, 1      ; sys_exit system call number
    xor ebx, ebx    ; exit code 0
    int 0x80        ; call kernel to execute sys call

