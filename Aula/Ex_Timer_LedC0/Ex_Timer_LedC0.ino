#define led PC0

unsigned char contador = 0;

ISR(TIMER0_OVF_vect){
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
  TCCR0A = 0; // Timer em modo normal.
  TCCR0B |= (1 << CS02)|(1 << CS00); // Prescaler (1024) e f = 15,625kHz.
  TIMSK0 |= (1 << TOIE0); // Habilita interrupção por overflow (modo normal).
  sei(); // Liga o serviço de interrupção.

  while(1){
  }
}
