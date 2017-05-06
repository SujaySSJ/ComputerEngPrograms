.model small
.stack 100
org 100
.data
	numbers db 20h,10h,40h,50h,30h
.code
.startup
		lea bx,numbers
		mov ch,04h
loop3:	mov cl,04h
		lea bx,numbers
loop2:	mov al,numbers[bx]
		cmp al,numbers[bx+1]
		jc loop1
		xchg al,numbers[bx+1]
		mov numbers[bx],al
loop1:	inc bx
		dec cl
		jnz loop2
	dec ch
	jnz loop3
mov ah,4ch
int 21h
end			
