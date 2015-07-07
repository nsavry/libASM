global _ft_isfloat
extern _ft_isdigit

_ft_isfloat:
	push rbx
	mov rbx, 0
	cmp byte[rdi], 43
	je nb
	cmp byte[rdi], 45
	je nb
	cmp byte[rdi], 46
	je dot
	cmp byte[rdi], 48
	jl err
	cmp byte[rdi], 57
	jg err

nb:
	inc rdi
	cmp byte[rdi], 0
	je yes
	cmp byte[rdi], 46
	je dot
	cmp byte[rdi], 48
	jl err
	cmp byte[rdi], 57
	jg err
	jmp nb

dot:
	cmp rbx, 1
	je err
	mov rbx, 1
	jmp nb

err:
	mov rax, 0
	pop rbx
	ret

yes:
	cmp rbx, 1
	jne err
	mov rax, 1
	pop rbx
	ret
