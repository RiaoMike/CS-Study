assume cs:codesg,ss:stacksg

data segment
	db '1975','1976','1977','1978','1979','1980','1981','1982','1983'
	db '1984','1985','1986','1987','1988','1989','1990','1991','1992'
	db '1993','1994','1995'
	
	dd 16,22,382,1356,2390,8000,16000,24486,50065,97479,140417,197514
	dd 345980,590827,803530,1183000,1843000,2759000,3753000,4649000,5937000

	dw 3,7,9,13,28,38,130,220,476,778,1001,1442,2258,2793,4037,5635,8226
	dw 11542,14430,15257,17800
data ends

table segment
	db 21 dup ('year summ ne ?? ')
table ends

stacksg segment
	db 16 dup (0)
stacksg ends

codesg segment
start:
	mov ax,data
	mov ds,ax
	mov ax,table
	mov es,ax
	mov ax,stacksg
	mov ss,ax
	mov sp,10h

	mov di,0
	
	mov cx,21
	mov bx,0
s0:
	push cx
	mov cx,4
	mov si,0
s1:
	mov al,ds:[di]
	mov es:[bx+si],al
	inc si
	inc di
	loop s1

	add bx,10h
	pop cx
	loop s0
	
	mov cx,21
	mov bx,0
l0:
	push cx
	mov cx,4
	mov si,0
l1:
	mov al,ds:[di]
	mov es:[bx+si+5],al
	inc si
	inc di
	loop l1

	add bx,10h
	pop cx
	loop l0

	mov cx,21
	mov bx,0
t0:
	mov ax,ds:[di]
	mov es:[bx+0ah],ax
	add di,2
	add bx,10h
	loop t0

	mov cx,21
	mov bx,0
q0:
	mov ax,es:[bx+5]
	mov dx,es:[bx+7]
	div word ptr es:[bx+0ah]
	mov es:[bx+0dh],ax
	add bx,10h
	loop q0

	mov ax,4c00h
	int 21h

codesg ends

end start
