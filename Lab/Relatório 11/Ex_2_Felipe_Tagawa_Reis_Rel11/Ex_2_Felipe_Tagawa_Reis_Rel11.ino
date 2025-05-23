#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>

#define ledVermelho PD5 // Se recepção '9': ligar, se '8': desliga
#define ledVerde PD6 // se recepção '9': desligar, se '8': liga

#define F_CPU 16000000UL
#define BAUD 9600
#define MYUBRR (F_CPU/16/BAUD-1)

char rx_char;

// Inicialização do UART:
void UART_init(unsigned int ubrr) {
    UBRR0H = (unsigned char)(ubrr >> 8);
    UBRR0L = (unsigned char)ubrr;
    
    // Habilita recepção, transmissão, and interrupção
    UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);
    
    // 8bits, 1 stop bit
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void UART_TX(char data) {
    while (!(UCSR0A & (1 << UDRE0)));
    
    UDR0 = data;
}

ISR(USART_RX_vect){ 
  rx_char = UDR0; // Atribui o valor digitado
  
  if(rx_char == '9'){
    PORTD |= (1 << ledVermelho); // Liga o vermelho
    PORTD &= ~(1 << ledVerde); // Apaga o verde
  }
  else if(rx_char == '8'){
    PORTD &= ~(1 << ledVermelho); // Apaga o vermelho
    PORTD |= (1 << ledVerde); // Liga o verde
  }
}

// Função de transmissão de strings por UART:
void UART_Transmit(char *dados) {
    while (*dados != 0) {
        while (!(UCSR0A & (1 << UDRE0)));
        UDR0 = *dados;                   
        dados++;
    }
}

int main(){

  DDRD |= (1 << ledVermelho) | (1 << ledVerde); // Colocar 255 pode influenciar em Pinos de UART padrão
  PORTD = 0;

  // Inicializa UART
  UART_init(MYUBRR);

  sei();
  while(1){
    
  }
}
