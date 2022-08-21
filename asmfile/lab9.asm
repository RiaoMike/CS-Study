assume cs:code,ds:data,ss:stack

data segment
	db 'Welcome to masm!'
	db 02h,24h,71h,0c3h
data ends

stack segment
	db 16 dup(0)
stack ends


code segment

start:
	mov ax,0b800h
	mov ds,ax
	mov bx,3c0h
	mov ax,data
	mov es,ax
	mov ax,stack
	mov ss,ax
	mov sp,10h
	mov cx,4
	mov di,0

s:
	mov ah,es:[di+10h]
	push cx
	mov cx,16
	mov bp,0
	mov si,0
s0:
	mov al,es:[bp]
	mov ds:[bx+si+40h],ax
	inc bp
	add si,2
	loop s0

	inc di
	add bx,320h
	pop cx
	loop s

	mov ax,4c00h
	int 21h


code ends

end start
