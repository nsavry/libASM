global _ft_toupper

_ft_toupper:
	cmp rdi, 122
	jg nop
	cmp rdi, 97
	jl nop
	jmp yes

yes:
	mov rax, rdi
	sub rax, 32
	ret

nop:
	mov rax, rdi
	ret
