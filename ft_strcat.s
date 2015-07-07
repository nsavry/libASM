global _ft_strcat

_ft_strcat:
	push rbx
	mov rax, rdi
	jmp len_rdi

len_rdi:
	cmp byte[rdi], 0 
	je next
	inc rdi
	jmp len_rdi

next:
	mov bl, byte[rsi]	
	mov byte[rdi], bl	
	cmp byte[rsi], 0
	je end
	inc rdi
	inc rsi
	jmp next

end:
	pop rbx
	ret
