global _ft_strchr

_ft_strchr:
	push rbx
	mov rbx, rsi

loop:
	cmp byte[rdi], 0
	je err
	cmp byte[rdi], bl
	je yes
	inc rdi
	jmp loop

err:
	mov rax, 0
	pop rbx
	ret

yes:
	mov rax, rdi
	pop rbx
	ret
