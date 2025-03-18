int main(void){

  DDRD = DDRD | 0b10000000; // Pino PD7 definido como saída
  PORTD = PORTD | 0b00100000; // Habilitar PULL-UP no PD5
  PORTD = PORTD & ~(0b10000000); // Desliga a saída PD7

  for ( ;; ){ // Super Loop
  
    int botao = PIND & 0b00100000; // Lê o estado do PD5
    
    if (botao == 0) // Botão está pressionado ?
    
    {
    
    PORTD = PORTD | 0b10000000;
    _delay_ms(1000);
    PORTD = PORTD & ~(0b10000000);
    
    // PD7 -> HIGH
    
    // Espera 5s
    
    // PD7 -> LOW
  
    }
  }
}
