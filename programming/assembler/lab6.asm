data segment 
prompt1 db '������ 1 ��ப�: ',13,10,'$' 
prompt2 db 13,10,'������ 2 ��ப�: ' 
crlf db 13,10,'$' 
txtno db 13,10,'���$' 
txtyes db '����ন��� $' 
buf1 db 255,? 
str1 db 255 dup (?) 
buf2 db 255,? 
str2 db 255 dup (?) 
data ends 

code segment 
assume cs:code,ds:data 
;======================================= 
;����ணࠬ�� ������� ���-�� �宦����� 
;�����ப� [si] � ��ப� [di]. 
;����� ��ப ������ ��室����� �� ���ᠬ
;[si-1] � [di-1]  
;���-�� �宦����� �����頥��� � al 
subroutine proc 
 xor al,al 
 mov cl,[di-1] 
 sub cl,[si-1] 
 jb Exit 
 inc cl 
 mov ch,al; ��� xor ch,ch 
m1: 
 push cx 
 push di 
 push si 
 mov cl,[si-1] 
 xor ch,ch 
compare_strings:
    mov dl, [si]          ; ���뢠�� ���� �� ��ப� source
    mov bl, [di]          ; ���뢠�� ���� �� ��ப� destination
    cmp dl, bl             ; �ࠢ������ �����
    jne m2
    ; �᫨ ����� ࠢ��:
    inc si                ; ���室�� � ᫥���饬� ����� ��ப� source
    inc di                ; ���室�� � ᫥���饬� ����� ��ப� destination
    loop compare_strings   ; �����蠥� CX � �����塞, �᫨ CX > 0 
    inc al 
m2: pop si 
 pop di 
 inc di 
 pop cx 
loop m1 

Exit: ret 
subroutine endp 
;======================================= 
start: mov ax,data 
 mov ds,ax 
 mov ah,9 
 lea dx,prompt1 
 int 21h 
 mov ah,10 
 lea dx,buf1 
 int 21h 
 mov ah,9 
 lea dx,prompt2 
 int 21h 
 mov ah,10 
 lea dx,buf2 
 int 21h 
 lea di,str1 
 lea si,str2 
 call subroutine; �맮� ����ணࠬ�� 
 or al,al; ��� cmp al,0 
 jne Yes 
No: lea dx,txtno 
 mov ah,9 
 int 21h 
 jmp quit 
Yes: push ax 
 lea dx,crlf 
 mov ah,9 
 int 21h 
 lea dx,txtyes 
 int 21h 
 pop ax 
 xor ah,ah 
 mov bx,300Ah 
 div bl 
 add bh,ah 
 xor ah,ah 
 div bl 
 mov dx,3030h 
 add dx,ax 
 mov ah,2 
 int 21h 
 mov dl,dh 
 int 21h 
 mov dl,bh 
 int 21h 
quit: xor ah,ah 
 int 16h 
 mov ah,4Ch 
 int 21h 
code ends 
 end start