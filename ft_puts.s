section .data
	lol:
		db `lol`
	null:
		db `(null)\n`

section .text
global _ft_puts

_ft_puts:
	cmp rdi, 0
	je nulx
	push rcx
	push rbx
	mov rcx, 0
	mov rbx, rdi
	jmp len

len:
	cmp byte[rbx], 0
	je aff
	inc rcx
	inc rbx
	jmp len
	
aff:
	mov rbx, rdi
	mov rdi, 1
	mov rsi, rbx
	mov rdx, rcx
	mov rax, 0x2000004
	syscall
	mov rdi, 1
	mov	rsi, rsp
	mov byte [rsi], 10 
	mov rdx, 1
	mov rax, 0x2000004
	syscall
	pop rbx
	pop rcx
	jmp end

nulx:
	mov rdi, 1
	mov rsi, null
	mov rdx, 7
	mov rax, 0x2000004
	syscall
	jmp end

end:
	mov rax, 10
	ret
