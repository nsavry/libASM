global _ft_isalnum

_ft_isalnum:
	cmp rdi, 122
	jg nop
	cmp rdi, 96
	jg yes
	cmp rdi, 90
	jg nop
	cmp rdi, 64
	jg yes
	cmp rdi, 57
	jg nop
	cmp rdi, 47
	jg yes
	jmp nop

yes:
	mov rax, 1
	ret

nop:
	mov rax, 0
	ret
