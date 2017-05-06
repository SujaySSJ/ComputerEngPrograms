.model small
.stack 100
org 100
.data
	BCD db 31H
	BIN db ?
.code
.startup
	MOV AL, BCD
	MOV AH, BCD
	AND	AH, 0FH
	MOV BL, AH
	AND AL, 0F0H
	MOV CL, 04H
	ROR	AL, CL
	MOV BH, 0AH
	MUL BH
	ADD AL,BL
	MOV BIN, AL
	MOV AH, 4CH
	INT 21H
	end
