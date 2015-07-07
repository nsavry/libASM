global _ft_putchar

_ft_putchar:
	mov [rsp+8], rdi
	mov rdi, 1
	mov rsi, rsp
	add rsi, 8
	mov rdx, 1
	mov rax, 0x2000004
	syscall
	ret
