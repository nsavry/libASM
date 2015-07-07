global _ft_strlen

_ft_strlen:
	mov rax, 0
	cmp rdi, 0
	je nul
	push rcx
	push rdi
	mov rcx, -1 
	cld
	repne scasb
	mov rax, rcx
	inc rax
	not rax
	pop rdi
	pop rcx
	ret

nul:
	ret
