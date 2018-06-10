#include <stdio.h>

int main() {
__asm__ ( AX,01 ; iniciación de AX
MOV BX,01 ; BX y
MOV DX,01 ; DX a 01
MOV CX,10 ; iniciar
A20: ; número de iteraciones
LOOP A20 ; decrementar CX
; iterar si es diferente de 0
MOV AX, 4C00H ; salida a DOS
INT 21H)

  return 0;
}
