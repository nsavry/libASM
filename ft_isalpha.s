global _ft_isalpha

_ft_isalpha:
	cmp rdi, 65
	jl nop
	cmp rdi, 122
	jg nop
	cmp rdi, 96
	jg yes
	cmp rdi, 91
	jl yes
	jmp nop

yes:
	mov rax, 1
	ret

nop:
	mov rax, 0
	ret
