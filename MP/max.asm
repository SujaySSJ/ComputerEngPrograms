.model small
.stack 100
org 100
.data
	n1 db 03h,02h,06h,08h
	min db ?
	max db ?
.code 
.startup
	lea bx,n1
	mov cl,04h
	mov al,n1[bx]
l1:	inc bx
	cmp al,n1[bx]
	ja next
	mov al,n1[bx]
next:	dec cl	
	jnz l1
	mov dl,al
	mov max,al
	
	lea bx,n1
	mov cl,04h
	mov al,n1[bx]
l2:	inc bx
	cmp al,n1[bx]
	jb next1
	mov al,n1[bx]
next1:	dec cl	
	jnz l2
	mov dh,al
	mov min,al
	
	mov ah,4ch
    	int 21h
end
	
	
	
	
	
	
	
end
