int main(){
  DDRD = (1<<PD6); // Liga o PD6 como saída.
  PORTD = 255; // Liga o Pull-up em todos os pinos de entrada.

  while(1){

    PORTD &= ~(1<<PD6); // Essa configuração faz com que não mudemos outras portas de entrada e saída, apenas a necessária.
    _delay_ms(1000);
    PORTD |= (1<<PD6);
    _delay_ms(1000);
    
  }
}
