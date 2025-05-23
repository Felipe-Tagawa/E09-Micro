#define led PC0

unsigned char contador = 0;

ISR(TIMER0_COMPA_vect){
  contador++;

// 16,38ms é o período(T) de um clock com prescaler 1024.
  if(contador > (1/0.01638)){
    PORTC ^= (1 << led);
    contador = 0;
  }
}

int main(){

  DDRC = 255;
  PORTC = 0;
  // Configuração do Timer.
  TCCR0A |= (1 << WGM01); // Timer em modo de comparação.
  TCCR0B |= (1 << CS02)|(1 << CS00);
  TIMSK0 |= (1 << OCIE0A); // Habilita interrupção por comparação.
  sei(); // Liga o serviço de interrupção.

  OCR0A = 200; // Valor de topo do comparador

  while(1){
  }
}
