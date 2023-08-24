section .data
    hello db "Hello, Holberton", 10 ; The 10 represents a new line character

section .text
    global _start

_start:
    ; Write "Hello, Holberton" to stdout (file descriptor 1)
    mov rax, 1             ; syscall number for sys_write
    mov rdi, 1             ; file descriptor 1 (stdout)
    mov rsi, hello         ; pointer to the string
    mov rdx, 16            ; string length
    syscall

    ; Exit the program
    mov rax, 60            ; syscall number for sys_exit
    xor rdi, rdi           ; exit status 0
    syscall

