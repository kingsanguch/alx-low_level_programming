section .data
hello db 'Hello, Holberton',10   ; The 10 is for a newline character
hello_len equ $ - hello

section .text
global _start

_start:
; Write "Hello, Holberton" to stdout (file descriptor 1)
mov eax, 4           ; syscall number for sys_write
mov ebx, 1           ; file descriptor 1 (stdout)
mov ecx, hello       ; pointer to the string
mov edx, hello_len   ; string length
int 0x80             ; invoke syscall

; Exit the program
mov eax, 1           ; syscall number for sys_exit
xor ebx, ebx         ; exit status 0
int 0x80             ; invoke syscall
