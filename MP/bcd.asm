.model small 
.stack 100
org 100
.data
   N1 dw 01A9H
   bcd db ?
.code
start: mov ax,@data
       mov ds,ax   
   mov ax,N1
   mov cl,64H
   div cl
   mov bcd+1,al
   mov al,ah
   mov ah,00H
   mov cl,0ah
   div cl
   mov bl,al
   ror bl,4
   mov al,ah
   add al,bl
   mov bcd,al
   mov dl,bcd
   mov ah,4ch
   int 21h
   
end start
 end
   
   
