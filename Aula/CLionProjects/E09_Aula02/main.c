#include <stdio.h>
#include <avrt.h>

int main(void) {
    printf("Hello, World!\n");
    unsigned char contador; // Ou unsigned short int contador;
    signed short int entrada; // Ou signed char entrada ou char entrada.
    unsigned int tempo;
    signed int temperatura; // Ou simplesmente int temperatura.
    const int IN = 0x16d;
    // const LIGADO = 1;

    // Operadores duplos são usados em comparações de variáveis e valores.
    // Operadores simples(lógicos) são usados para comparar bits um a um.
    // Operadores lógicos: &(and), |(or), ^(xor), >>(deslocamento pra direita), <<(deslocamento pra esquerda).
    // Deslocamentos são usados para fazer multiplicações. Para multiplicar um binário por 4, devemos
    // deslocar para a esquerda duas vezes (2^2). Se quisermos dividir, devemos deslocar para a direita.

    return 0;
}