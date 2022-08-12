assume cs:codemg,ss:stack,ds:datamg

stack segment
	dw 0,0,0,0,0,0,0,0
stack ends

datamg segment
	db '1. display      '
	db '2. brows        '
	db '3. replace      '
	db '4. modify       '
datamg ends

codemg segment
start:
	mov ax,stack
	mov ss,ax
	mov sp,16
	mov ax,datamg
	mov ds,ax

	mov bx,0
	mov cx,4
s:	
	push cx
	mov cx,4
	mov si,0
s0:
	mov al,[bx+si+3]
	and al,11011111b
	mov [bx+si+3],al
	inc si
	loop s0

	add bx,16
	pop cx
	loop s
	
	mov ax,4c00h
	int 21h
codemg ends
end start
