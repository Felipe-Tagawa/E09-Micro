// Felipe Silva Loschi(601) & Felipe Tagawa Reis(2037) & Pedro Henrique Ribeiro Dias(529)

// ------------------ UART ---------------------
#define F_CPU 16000000UL
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

// ------------- Entradas e saídas -------------
#define botao PD1
#define led PD6 // Timer0 e pwm
#define potenciometro PC0 // A0
unsigned char contadorPontos = 0; // Pontuação

// ----------- Inicialização UART ---------------
void UART_Init(unsigned int ubrr) {
    UBRR0H = (unsigned char)(ubrr >> 8);
    UBRR0L = (unsigned char)ubrr;
    UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

// ----------- Recepção UART --------------------
ISR(USART_RX_vect){
  char comando = UDR0;

  switch(comando){
    case 'r':
      contadorPontos = 0;
      UART_SendString("Pontuacao reiniciada.\r\n");
      break;
    case 's':
      UART_SendString("Pontuacao atual: ");
      UART_SendInt(contadorPontos);
      UART_SendString("\r\n");
      break;
     case 'd': // Debug do brilho
            UART_SendString("Brilho atual: ");
            UART_SendInt(OCR0A);
            UART_SendString("\r\n");
            break;
    default:
      UART_SendString("Comando invalido.\r\n");
  }
}

// ------------ Transmissão de dados -------------
void UART_Transmit(unsigned char data){
  // Espera o buffer estar vazio
  while (!(UCSR0A & (1 << UDRE0)));
  // Envia o dado
  UDR0 = data;
}

// --------- Envio de valores inteiros com UART ----------
void UART_SendInt(uint8_t valor){
  char buffer[10];
  itoa(valor, buffer, 10); // Conversão de inteiro para string
  UART_SendString(buffer);
}

// ---------- Envio de Strings com UART --------------------
void UART_SendString(const char* str){
  while (*str){
    UART_Transmit(*str++); // Transmissão de mensagens
  }
}

ISR(PCINT2_vect){
  if(!(PIND & (1 << botao)) && (OCR0A > 0)){ // Botão pressionado e led ligado
    contadorPontos++; // Incrementa a pontuação do jogador
    OCR0A = 0; // Desliga o Led
    UART_SendString("Pontuacao: ");
    UART_SendInt(contadorPontos);
    UART_SendString("\r\n");
  }
}

// ------------------- Rotina de TIMER 2 ----------------------- //
ISR(TIMER2_COMPA_vect){ // 8 bits (0 a 255)
}



// ------------------------  Função Principal  ------------------ //

int main(){

  UART_Init(MYUBRR); // Inicialização do UART

  DDRD &= ~(1 << botao); // botão como entrada
  DDRD |= (1 << led); // PWM como saída

  PORTD |= (1 << botao); // Pull-up no botão
 
  //----------------- Configuração do Fast-PWM -----------------

  TCCR0A |= (1 << WGM01) | (1 << WGM00); // Fast-PWM
  TCCR0A |= (1 << COM0A1); // Nível lógico de súbida

  //----------------- Configurando Prescaler -----------------

  TCCR0B |= (1 << CS02) | (1 << CS00); // 1024

  //----------------- Timer2 -----------------

  TCCR2A = (1 << WGM21); // Modo CTC (WGM21 = 1, WGM20 = 0)
  TCCR2B = (1 << WGM22) | (1 << CS22) | (1 << CS20); // WGM22 = 1, prescaler = 1024
  OCR2A = 199; // Valor de comparação com f = 16M /(1024 * 200) = 78,1Hz -> Tclk = 1/f = 12,8ms
  TIMSK2 |= (1 << OCIE2A); // Habilita a interrupção por comparação

  //----------------- Interrupção externa: -----------------

  PCICR |= (1 << PCIE2); // PD
  PCMSK2 |= (1 << PCINT17); // Interrupção em PD1

  //----------------- Configuração do conversor ADC: -----------------

  ADCSRA |= (1 << ADEN); // Liga o ADC
  // PRESCALER ADC:

  ADCSRA |= (1 << ADPS2) |(1 << ADPS1) |(1 << ADPS0); // Prescaler = 128(125kHz)
  ADMUX |= (1 << REFS0); // Usando AVCC como referência

  sei();

  OCR0A = 0;

  UART_SendString("=== Bem-vindo ao Tiro ao LED! ===\r\n");
  UART_SendString("Comandos: 'r' = reset, 's' = score, 'd' = debug\r\n");
  UART_SendString("Gire o potenciometro e pressione o botao quando o LED acender!\r\n\r\n");
   
  while(1){
  }
}
