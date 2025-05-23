#include <avr/io.h>
#include <avr/interrupt.h>

#define ledVerde PD6  // PWM

#define F_CPU 16000000UL
#define BAUD 9600
#define MYUBRR (F_CPU/16/BAUD-1)

void UART_init(unsigned int ubrr) {
    UBRR0H = (unsigned char)(ubrr >> 8);
    UBRR0L = (unsigned char)ubrr;
    UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

ISR(USART_RX_vect) {
    char valor = UDR0;

    if (valor >= '0' && valor <= '9') {
        // Converte '0'..'9' para 0..255
        unsigned int nivel = (valor - '0') * 28;  // 9 * 28 = 252 (aproxima 255)
        OCR0A = nivel;
    }
}

int main(void) {
    DDRD |= (1 << ledVerde);  // Saída para o LED

    // Configura Timer0 em Fast PWM (PD6)
    TCCR0A |= (1 << WGM01) | (1 << WGM00);
    TCCR0A |= (1 << COM0A1); 
    TCCR0B |= (1 << CS01);    // Prescaler 8

    UART_init(MYUBRR);
    sei();

    while (1) {
    }
}
