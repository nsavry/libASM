global _ft_isprint

_ft_isprint:
	cmp rdi, 32
	jl nop
	cmp rdi, 126
	jg nop
	mov rax, 1
	ret

nop:
	mov rax, 0
	ret
