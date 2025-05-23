#define Led1 PC5
#define Led2 PB5
#define Sensor1 PD1
#define Sensor2 PB7

unsigned char n = 10;
unsigned char i;

// Interrupção no port B -- PCINT7
ISR(PCINT0_vect){
  PORTC &= ~(1 << Led1);
  _delay_ms(600);

  for(i = 0; i < n; i++){
    PORTB ^= (1 << Led2);
    _delay_ms(600);
  }
  
}

// Interrupção no port D -- PCINT17
ISR(PCINT2_vect){
  PORTC &= ~(1 << Led1);
  _delay_ms(300);

  for(i = 0; i < n; i++){
    PORTB ^= (1 << Led2);
    _delay_ms(300);
  }
}

int main(){

  DDRC = 255;
  DDRD = 0;
  DDRB |= (1 << Led2);
  DDRB &= ~(1 << Sensor2);

  PORTB = 0;
  PORTC = 0;

  // Interrupção:

  PCICR |= (1 << PCIE0) | (1 << PCIE2);
  PCMSK0 |= (1 << PCINT7);
  PCMSK2 |= (1 << PCINT17);

  sei();

  while(1){

    PORTC ^= (1 << Led1);
    _delay_ms(5000);
    
  }
}
