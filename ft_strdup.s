global _ft_strdup
extern _ft_strlen
extern _malloc

_ft_strdup:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	push rbx
	mov rbx, rdi
	call _ft_strlen
	inc rax
	mov rcx, rax
	mov rdi, rax
	push rcx
	call _malloc
	pop rcx
	test rax, rax
	jz end
	mov rsi, rbx
	mov rdi, rax
	repne movsb
	leave
	ret

end:
	leave
	ret
