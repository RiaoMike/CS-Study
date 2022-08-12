assume cs:codemg,ds:datamg

datamg segment
	db 'ibm             '
	db 'dec             '
	db 'dos             '
	db 'vax             '
datamg ends

codemg segment
start:
	mov ax,datamg
	mov ds,ax
	mov bx,0
	mov cx,4

s:	mov dx,cx	
	mov cx,3
	mov si,0

s0:	mov al,[bx+si]
	and al,11011111b
	mov [bx+si],al
	inc si
	loop s0

	add bx,16
	mov cx,dx
	loop s

	mov ax,4c00h
	int 21h
codemg ends
end start

