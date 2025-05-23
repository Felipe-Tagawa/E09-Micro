// Saídas:
#define led1 PD5
#define led2 PD7
#define led3 PD6
#define led4 PB1

// Para os pinos B:
ISR(PCINT0_vect){
  if(!(PINB & (1 << PB0))){
    PORTD |= (1 << led2);
    _delay_ms(1000);
    PORTD &= ~(1 << led2);
  }
  if(!(PINB & (1 << PB2))){
    PORTD |= (1 << led3);
    _delay_ms(500);
    PORTD &= ~(1 << led3);
  }
}

// Para os pinos D:
ISR(PCINT2_vect){
  if(!(PIND & (1 << PD4))){
    PORTB |= (1 << led4);
    _delay_ms(2000);
    PORTB &= ~(1 << led4);
  }
}

int main(){

  // Definindo as saídas:
  DDRD |= (1 << led1) | (1 << led2) | (1 << led3);
  DDRB |= (1 << led4);

  // Pull-up nos botões:
  PORTB |= (1 << PB0) | (1 << PB2);
  PORTD |= (1 << PD4); 

  // Qual grupo de pinos vai ter intervenção -> 0: B, 1: C, 2: D
  PCICR = (1 << PCIE0) | (1 << PCIE1) | (1 << PCIE2);
  
  // Qual pino do grupo vai acionar a interrupção:
  // PCINT0 -- PB0
  // PCINT2 -- PB2
  // PCINT20 -- PD4
  
  PCMSK0 |= ((1 << PCINT0) | (1 << PCINT2));
  PCMSK2 |= (1 << PCINT20);

  sei();
  
    while(1){
      PORTD ^= (1 << led1);
      _delay_ms(250);
      
    }
  }
