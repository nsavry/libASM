global _ft_isascii

_ft_isascii:
	cmp rdi, 0
	jl nop
	cmp rdi, 127
	jg nop
	mov rax, 1
	ret

nop:
	mov rax, 0
	ret
