    SECTION .data
    i: DW 0
    j: DW 0
    k: DW 0 
    soma: DB 0 

 
    SECTION .text

	global exibir

exibir:
	enter 0,0
    ;xor eax, eax
    ;mov ebx,0
    ;mov ecx,0   ;contador
    ;mov edx,0   ;contador
    ;mov edi,0 ;mat
    ;mov esi,0 ;mat 
    ;mov [soma],byte 0
    push ebx

    mov edi,[ebp+8]  ;matA 
    mov esi,[ebp+16] ;matC

forI:
    forJ:
    mov [soma],BYTE 0
        forK:
            mov eax,[ebp+24] ; (L*i+k)*4 
	        mov ebx,[i]
	        mul bl
	        add eax,[k]
	        mov bl,4
	        mul bl
	        mov edx,eax ;cont matA
            mov eax,[edi+edx]

            mov eax,[ebp+24] ; (L*k+j)*4
	        mov ebx,[k]
	        mul bl
	        add eax,[j]
	        mov bl,4
	        mul bl
	        mov ecx,eax ;cont matC

            mov eax,[edi+edx] ; matA[i][k]
            mov ebx,[esi+ecx] ; matC[k][j]
            mul bl
            add [soma],eax 
			push eax
            inc k
			mov eax,[ebp+24]
            cmp k,eax
            jl forK

    mov eax,[ebp+24] ; (L*i+j)*4
    mov ebx,[i]
    mul bl
    add eax,[j]
    mov bl,4
    mul bl
    mov ecx,eax ;cont matRes

    ;colocando valores             
    mov ebx,[ebp+20] ;matRes
    mov [ebx+ecx],soma

    inc j
    cmp j,[ebp+24]
    jl forJ

inc i
cmp i,[ebp+24]
jl forI

       
    pop ebx    
	leave
	ret
