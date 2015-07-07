global _ft_isspace

_ft_isspace:
	cmp rdi, 9
	je yes
	cmp rdi, 10
	je yes
	cmp rdi, 11
	je yes
	cmp rdi, 12
	je yes
	cmp rdi, 13
	je yes
	cmp rdi, 32
	je yes
	mov rax, 0
	ret

yes:
	mov rax, 1
	ret
