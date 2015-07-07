section .data
buffer times 5000 db 0
lenght_buf equ $ - buffer

section .text
global _ft_cat

_ft_cat:
	cmp rdi, -1
	jle exit
	jmp cat

cat:
	lea rsi, [rel buffer]
	mov rax, 0x2000003
	mov rdx, lenght_buf
	syscall
	cmp rax, 0
	jle exit
	mov rdx, rax
	mov rax, 0x2000004
	push rdi
	mov rdi, 1
	syscall
	pop rdi
	cmp rax, -1
	je exit
	cmp rdi, 0
	je cat
	cmp rax, 5000
	je cat

exit:
	ret
