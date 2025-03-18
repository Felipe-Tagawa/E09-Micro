#include <stdio.h>
#include <stdlib.h>

void main() {

    unsigned char A = 0x55;  // 0b01010101
    unsigned char B = 0xF0;  // 0b11110000

    unsigned char C = A & B;   // AND bit a bit
    unsigned char D = A | B;   // OR bit a bit
    unsigned char E = A && B;  // Operação lógica (1 ou 0)
    unsigned char F = A || B;  // Operação lógica (1 ou 0)
    unsigned char G = B >> 4;  // Deslocamento de bits à direita
    unsigned char H = A << 1;  // Deslocamento de bits à esquerda

    printf("A & B  = %X\n", C);
    printf("A | B  = %X\n", D);
    printf("A && B = %d\n", E); // Se tiver qualquer bit 1, o resultado é 1.
    printf("A || B = %d\n", F); // Se tiver qualquer bit 1, o resultado é 1.
    printf("B >> 4 = %X\n", G);
    printf("A << 1 = %X\n", H);

}
