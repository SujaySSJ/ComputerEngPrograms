.model small
.stack 100
org 100
.data
  n1 dw 1234H
  n2 dw 0f234H
  sum dw ?

.code
.startup
    mov ax,n1
    mov bx,n2
    mov cx,0h
    add ax,bx
    jnc down
    inc cx
down: mov sum,ax
      mov sum+2,cx
      mov ah,4ch
      int 21H
end      
