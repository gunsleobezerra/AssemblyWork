    SECTION .data
	
    i: DB 0
    j: DB 0
    k: DB 0 
	

 
    SECTION .text

	%macro getmat 3

		push edx
		;push i and j 
		mov eax,%2
		push eax
		mov eax,%3
		push eax
		;
		mov eax,[ebp+24]; L size
		call index
		pop edx
		
		mov eax,[%1+eax];acesses position

		;retorna o valor da posição em eax	
	%endmacro

	%macro setmat 4

		push edx
		;push i and j 
		mov eax,%2
		push eax
		mov eax,%3
		push eax
		;
		mov eax,[ebp+24]; L size
		call index
		
		mov edx,%4
		mov [%1+eax],edx;acesses position
		pop edx

	%endmacro

	global exibir

exibir:
	
	enter 0,0
    
       
    mov edi,[ebp+8]  ;matA 
    mov esi,[ebp+20] ;mat res
    mov ecx,[ebp+16] ;matC
	push ebx
	;mult A x C

	forI:
	mov edx,[ebp+24]
	cmp [i],edx
	jnl  sum

	

		forJ:
		xor ebx,ebx
		cmp [j],edx
		jnl addI 
		
		
	
			forK:
			
			cmp [k],edx
			jnl  attres

			push edx
			getmat edi,[i],[k]
			mov edx,eax
			getmat ecx,[k],[j]
			mul dl
			add ebx,eax
			pop edx

						
			 
    
			inc byte [k]
			jmp forK 

	
	addI:
	inc byte [i]
	mov [j],byte 0
	jmp forI

	addJ:
	
	inc byte [j]
	mov [k],byte 0
	jmp forJ
	;;;

	attres:
	setmat esi,[i],[j],ebx
	
	jmp addJ

	
	
	sum:
	
	xor ebx,ebx
	xor ecx,ecx
	mov ecx,[ebp+12] ; Mat B [0][0]
	mov edx,[ebp+24] ; Size
	mov eax,edx
	mul dl           ; Size ^ 2 Numero de elementos
	mov edx,4
	mul dl           ; NM * 4 = Numero de bytes
	xor edx,edx

	sumloop:
	cmp ebx,eax
	jnl end
	mov edx,[ecx+ebx] ; Mat B [i][j]
	add [esi+ebx],edx ; Mat res [i][j] +  mat B [i][j]
	add ebx , 4 ; size of int
	jmp sumloop


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;calcula indice da matriz
index:
	;eax tamanho máximo da matriz
	enter 8,0
	xor edx,edx
	
	mov edx,[ebp+12]
	mul dl
	add eax,[ebp+8] ;(i*l + j)*4
	mov dl,4
	mul dl
	
	leave
	ret 8

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
end:
	;setmat esi,0,0,[soma]
	;setmat esi,0,1,[j]
	;setmat esi,1,0,[k]
	;Diagonal
	xor ebx,ebx
	xor edx,edx
	
	diagonal:
	cmp ebx,[ebp+24]
	jl diagonalsum         ;Soma diagonal principal
	mov eax,edx

	pop ebx
	leave
	ret 

diagonalsum:
	
	getmat esi,ebx,ebx
	add edx,eax
	inc ebx
	jmp diagonal

