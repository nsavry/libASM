global _ft_isinteger
extern _ft_isdigit

_ft_isinteger:
	cmp byte[rdi], 43
	je nb
	cmp byte[rdi], 45
	je nb
	cmp byte[rdi], 48
	jl err
	cmp byte[rdi], 57
	jg err

nb:
	inc rdi
	cmp byte[rdi], 0
	je yes
	cmp byte[rdi], 48
	jl err
	cmp byte[rdi], 57
	jg err 
	jmp nb

err:
	mov rax, 0
	ret

yes:
	mov rax, 1
	ret
