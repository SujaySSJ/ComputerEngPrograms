.model small
.stack 100
org 100
.data
	n1 db 0AH
	n2 db 32H
	gcd db ?
.code
.startup
	mov al,n1
	mov bl,n2
wh:	cmp al,bl
    jz ed
	ja i
	xchg al,bl
i:  sub al,bl
	jmp wh
ed:	mov cl,al
    mov ah,4ch
    int 21h
	end
   

