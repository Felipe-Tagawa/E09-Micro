#define led1 PD0
#define led2 PD1

unsigned long int valor_contagem = 0;

ISR(TIMER0_COMPA_vect){
  valor_contagem++;

  if(valor_contagem % 10000 == 0){ // Cada 1s.
    PORTD |= (1 << led1); // Acende o Led1
  }
  if(valor_contagem % 10000 == 1000){ // Todos os casos(10100,20100,30100,...).
    PORTD &= ~(1 << led1); // Apaga o Led1
  }
  if(valor_contagem == 600000){ // 1 min
      PORTD |= (1 << led2); // Acende o Led2
  }
  if(valor_contagem == 600100){ // timer de 100ms
    PORTD &= ~(1 << led2); // Apaga o Led2
    valor_contagem = 0; // Zera a contagem para reiniciar. 
  }
  
}

int main(){

  DDRD = 255; // Todos os leds definidos como saída.

  PORTD = 0; // Leds inicialmente desligados.


  TCCR0A |= (1 << WGM01); // TCT - comparação.
  TCCR0B |= (1 << CS01); // Prescaler 8(0 1 0).

  OCR0A = 199; // ticks 200 (0 a 199) - 500ns * 200 = 100us.

  TIMSK0 |= (1 << OCIE0A); // Habilita a interrupção no OCR0A

  sei();

  while(1){
  }
}
