data segment ; ��४⨢� ��砫� ᥣ���� ������
msg1    DB  "������ ��ப�: $"
msg2    DB  0Ah, 0Dh, "������ 蠡���: $"
msg3    DB  0Ah, 0Dh, "��!$"
msg4    DB  0Ah, 0Dh, "���$"
 
str1ml  DB  200
str1l   DB  '$'
str1    DB  200 dup('$')
 
str2ml  DB  200
str2l   DB  '$'
str2    DB  200 dup('$')
data ends 
code segment ; ��४⨢� ��砫� ᥣ���� �����
assume cs: code, ds: data ; ��⠭���� ᮮ⢥�ᢨ� ᥣ���⮢ � �� ���ᮢ
start:
    mov ax, data
    mov ds, ax
    mov es,ax
    xor ax,ax

    lea dx, msg1    ;�뢮� msg1
    call    strout
 
    lea dx, str1ml  ;���� ��ப� str1
    call    strin
 
    lea dx, msg2    ;�뢮� msg2
    call    strout
 
    lea dx, str2ml  ;���� ��ப� str2
    call    strin
 
    xor cx, cx
    mov cl, str1l   ;��⠭���������� ���-�� ����७��
    sub cl, str2l
    inc cl
    cld         ;������ 䫠� ���ࠢ�����
    lea di, str2    ;� di - ��ப�, ������ ���� ����
    lea si, str1    ;� si - ��ப�, � ���ன �饬
    xor ax, ax
 
beg:         ;��������� ��� str1 �� ���� ��ப� ����� ����� str2
    
    push    cx
    push    di
    push    si
    mov bx, si
    mov cl, str2l

compare_strings:
    mov al, [si]          ; ���뢠�� ���� �� ��ப� source
    mov bl, [di]          ; ���뢠�� ���� �� ��ப� destination
    cmp al, bl             ; �ࠢ������ �����
    jne _neq          ; �᫨ �� ࠢ��, ���室

    ; �᫨ ����� ࠢ��:
    inc si                ; ���室�� � ᫥���饬� ����� ��ப� source
    inc di                ; ���室�� � ᫥���饬� ����� ��ப� destination
    loop compare_strings   ; �����蠥� CX � �����塞, �᫨ CX > 0
    jmp _eq              ; �� ����� ࠢ��

_eq:
    lea dx, msg3    ;�뢮� msg1
    call    strout
    jmp _end
_neq:
    pop si
    pop di
    pop cx
 
    inc si
loop    beg
    
    lea dx, msg4
    call    strout
 
_end:
    mov     ah, 4ch    
    int 21h
 
 
;*****************��楤���***********************
 
;*************************************************
strin   proc
    mov ah, 0Ah
    int 21h
    ret
strin   endp
;*************************************************
strout  proc
    mov ah, 09h
    int 21h
    ret
strout  endp
;*************************************************
code ends
end start
