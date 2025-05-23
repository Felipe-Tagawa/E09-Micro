#include <avr/io.h> // Entrada e saída
#include <avr/interrupt.h> // Interrupções
#include <stdlib.h> // itoa()
#include <string.h> // strstr()

#define F_CPU 16000000UL
#define BAUD 9600
#define MYUBRR (F_CPU/16/BAUD-1)
#define botao PD4 // INT0

volatile unsigned int x = 0;
// Mensagem recebida:
char msg_rx[20];
// Mensagem transmitida:
char msg_tx[20];
volatile unsigned int rx_index = 0;

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

// Função de transmissão de strings por UART("print"):
void UART_Transmit(char *dados) {
    while (*dados != 0) {
        while (!(UCSR0A & (1 << UDRE0)));
        UDR0 = *dados;                   
        dados++;
    }
}

// UART Receive Interrupt Service Routine
ISR(USART_RX_vect) {
    char recebido = UDR0;

    // Armazenamento em um 'buffer' -- não perder os valores(isso poderia ser feito usando um vetor simples, mas os valores seriam perdidos).
    if (rx_index < sizeof(msg_rx) - 1) {
        msg_rx[rx_index++] = recebido;
        msg_rx[rx_index] = '\0'; // Evitar erros de caracteres.
    }
    
    // Checar "zerar"
    if (rx_index >= 5) {
        if (strstr(msg_rx, "zerar") != NULL) {
            x = 0;  // Reset do contador
            
            // Confirmação
            UART_Transmit("Contador zerado\r\n");
        }
    }
}

ISR(PCINT2_vect) {
    
    // verifica se o botão foi pressionado
    if (!(PIND & (1 << botao))) {
        x++;  // Incrementando
        
        UART_Transmit("Num vezes botao press: ");
        // integer to ASCII(itoa()):
        itoa(x, msg_tx, 10); // Conversão de x (inteiro), 10 representa a base decimal.
        UART_Transmit(msg_tx);
        UART_Transmit("\n");
        
        while (!(PIND & (1 << botao)));
    }
}

int main() {
    
    DDRD = 0;  
    PORTD |= (1 << botao);  // Habilita pull-up
    
    // Inicializa UART
    UART_init(MYUBRR);

    PCICR |= (1 << PCIE2);     // PORTD
    PCMSK2 |= (1 << PCINT20);  // PD4 (PCINT20)
    
    x = 0; // NumPress = 0 inicialmente.
    
    sei();
    
    UART_Transmit("Aperte o botao:\n");
    
    while(1) {
    }
}
