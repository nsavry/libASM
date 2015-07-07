global _ft_tolower

_ft_tolower:
	cmp rdi, 90
	jg nop
	cmp rdi, 65
	jl nop
	jmp yes

yes:
	mov rax, rdi
	add rax, 32
	ret

nop:
	mov rax, rdi
	ret
