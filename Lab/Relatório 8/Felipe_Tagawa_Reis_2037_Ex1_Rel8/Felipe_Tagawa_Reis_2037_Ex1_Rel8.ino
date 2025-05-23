#define led PD0

unsigned int valor_contagem = 0;

ISR(TIMER0_COMPA_vect){
  valor_contagem++;

  if(valor_contagem >= 2000){ // 2000 * 75us = 150ms
    PORTD ^= (1 << led);
    valor_contagem = 0;
  }
}

int main(){

  DDRD = 255;
  PORTD |= (1 << led);

  PORTD = 0;

  TCCR0A |= (1 << WGM01); // TCT - comparação.
  TCCR0B |= (1 << CS01); // Prescaler 8(0 1 0).

  OCR0A = 149; // ticks 150 (0 a 149) - 500ns * 150 = 75us.

  TIMSK0 |= (1 << OCIE0A); // Habilita a interrupção no OCR0A

  sei();


  while(1){
  }
}
