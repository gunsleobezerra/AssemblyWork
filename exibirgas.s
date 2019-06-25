 .data

    i: .byte 0
    j: .byte 0
    k: .byte 0
    



    .text

     .macro getmat a,b,c

                pushl %edx
                #push i and j 
                movl \b, %eax
                pushl %eax
                movl \c, %eax
                pushl %eax
                #
                movl 24(%ebp),%eax # L size
                call index
                popl %edx
               
                movl (%\a,%eax),%eax #acesses position

                #retorna o valor da posição em eax    
     .endm

     .macro setmat a,b,c,d

                pushl %edx
              
                movl \b, %eax
                pushl %eax
                movl \c, %eax
                pushl %eax
                
                movl 24(%ebp),%eax 
                call index

                movl \d, %edx
                
                movl %edx,(%\a,%eax) 
                popl %edx

     .endm

        .global exibirgas

exibirgas: 

        enter $0,$0


    movl 8(%ebp),%edi  
    movl 20(%ebp),%esi 
    movl 16(%ebp),%ecx 
        pushl %ebx
        #mult A x C

        forI: 
        movl 24(%ebp),%edx
        cmpl %edx,i
        jnl  sum



                forJ: 
                xorl %ebx,%ebx
                cmpl %edx,j
                jnl addI



                        forK: 

                        cmpl %edx,k
                        jnl  attres

                        pushl %edx
                        getmat edi,$i,$k
                        movl %eax,%edx
                        getmat ecx,$k,$j
                        mulb %dl
                        addl %eax,%ebx
                        popl %edx




                        incb k
                        jmp forK


        addI: 
        incb i
        movb $0,j
        jmp forI

        addJ: 

        incb j
        movb $0,k
        jmp forJ
        ###

        attres: 
        setmat esi,$i,$j,%ebx

        jmp addJ



        sum: 

        xorl %ebx,%ebx
        xorl %ecx,%ecx
        movl 12(%ebp),%ecx 
        movl 24(%ebp),%edx 
        movl %edx,%eax
        mulb %dl        
        movl $4,%edx
        mulb %dl         
        xorl %edx,%edx

        sumloop: 
        cmpl %eax,%ebx
        jnl end
        movl (%ecx,%ebx),%edx 
        addl %edx,(%esi,%ebx) 
        addl $4,%ebx 
        jmp sumloop



index: 
        
        enter $0,$8
        xorl %edx,%edx

        movl 12(%ebp),%edx
        mulb %dl
        addl 8(%ebp),%eax 
        movb $4,%dl
        mulb %dl

        leave
        ret $8

##################################################################################
end: 
        #setmat esi,0,0,[soma]
        #setmat esi,0,1,[j]
        #setmat esi,1,0,[k]
        #Diagonal
        xorl %ebx,%ebx
        xorl %edx,%edx

        diagonal: 
        cmpl 24(%ebp),%ebx
        jl diagonalsum         #Soma diagonal principal
        movl %edx,%eax

        popl %ebx
        leave
        ret

diagonalsum: 

        getmat esi,%ebx,%ebx
        addl %eax,%edx
        incl %ebx
        jmp diagonal

        