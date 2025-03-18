int main(void)
{
  DDRD = DDRD | 0b11001000; // Pino PD7 definido como saída
  PORTD = PORTD | 0b00111000; // Habilitar PULL-UP no PD5
  PORTD = PORTD & ~(0b11001000); // Desliga a saída PD7
  
  for ( ;; ){ // Super Loop
    int botao = PIND & 0b00100000; // Lê o estado do PD5
    int botao2 = PIND & 0b00010000; // Lendo o estado do PD4
    
   if(botao == 0){
      // led vermelho
      PORTD = PORTD |0b00001000; // PD3 - HIGH
      _delay_ms(2000); // Delay de 2s
      PORTD = PORTD & ~(0b00001000); // PD3 - LOW
      
      // Led verde
      PORTD = PORTD | 0b10000000; // PD7 -> HIGH
      _delay_ms(2000); // Delay de 2s
      PORTD = PORTD & ~(0b10000000); // PD7 -> LOW

      // Led amarelo
      PORTD = PORTD |0b01000000; // PD6 - HIGH
      _delay_ms(2000); // Delay de 2s
      PORTD = PORTD & ~(0b01000000); // PD6 - LOW
   }
  }
}
