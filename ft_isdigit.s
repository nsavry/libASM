global _ft_isdigit

_ft_isdigit:
	cmp rdi, 48
	jl nop
	cmp rdi, 57
	jg nop
	mov rax, 1
	ret

nop:
	mov rax, 0
	ret
