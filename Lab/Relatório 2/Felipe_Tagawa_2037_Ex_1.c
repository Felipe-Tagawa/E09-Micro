#include <stdio.h>
#include <windows.h>
#include <time.h> // Quero mostrar os segundos passados de cada.

void main(){

    while(true){

        time_t begin, now;

        begin = time(NULL);

        now = time(NULL);
        char *estado_atual = "Verde";
        printf("%s\n", estado_atual);
        //_delay_ms(12000);
        printf("Segundos passados: %ld\n", now - begin);
        Sleep(12000);
        now = time(NULL);
        estado_atual = "Amarelo";
        printf("%s\n", estado_atual);
        //_delay_ms(3000);
        printf("Segundos passados: %ld\n", now - begin);
        Sleep(3000);
        now = time(NULL);
        estado_atual = "Vermelho";
        printf("%s\n", estado_atual);
        //_delay_ms(15000);
        printf("Segundos passados: %ld\n", now - begin);
        Sleep(15000);

    }

}