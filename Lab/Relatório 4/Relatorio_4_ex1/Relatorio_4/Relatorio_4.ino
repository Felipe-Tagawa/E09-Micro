int main(void)
{
  DDRD = DDRD | 0b11000000; // Pino PD7 definido como saída
  PORTD = PORTD | 0b00110000; // Habilitar PULL-UP no PD5
  PORTD = PORTD & ~(0b11000000); // Desliga a saída PD7
  
  for ( ;; ){ // Super Loop
    int botao = PIND & 0b00100000; // Lê o estado do PD5
    int botao2 = PIND & 0b00010000; // Lendo o estado do PD4
    
    if (botao == 0){ // Botão está pressionado ?
      PORTD = PORTD | 0b10000000; // PD7 -> HIGH
      _delay_ms(100); // Espera 5s
      PORTD = PORTD & ~(0b10000000); // PD7 -> LOW
      PORTD = PORTD |0b01000000; // PD6 - HIGH
      _delay_ms(100); // Delay de 1 segundo
      PORTD = PORTD & ~(0b01000000); // PD6 - LOW
    }

    if(botao2 == 0){
      PORTD = PORTD | 0b10000000; // PD7 -> HIGH
      _delay_ms(1000); // Espera 5s
      PORTD = PORTD & ~(0b10000000); // PD7 -> LOW
      PORTD = PORTD |0b01000000; // PD6 - HIGH
      _delay_ms(1000); // Delay de 1 segundo
      PORTD = PORTD & ~(0b01000000); // PD6 - LOW
    }
  }
}
