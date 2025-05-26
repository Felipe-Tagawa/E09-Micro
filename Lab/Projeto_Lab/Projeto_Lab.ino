#define botao PD1
#define led PD6 // Timer0 e pwm
#define potenciometro PC0 // A0

unsigned char contadorPontos = 0;

ISR(PCINT2_vect){
  if(!PIND & (1 << botao) && (OCR0A > 0)){ // Botão pressionado e led ligado.
    contadorPontos++;
    OCR0A = 0;
  }
  
}
// ------------------------------------------ //
ISR(TIMER1_COMPA_vect){
  
}
// ------------------------------------------ //
int main(){

  DDRD &= ~(1 << botao); // botão como entrada
  DDRD |= (1 << led); // PWM como saída

  PORTD |= (1 << botao); // Pull-up no botão
  PORTD = 0;
 
  //----------------- Configuração do Fast-PWM -----------------

  TCCR0A |= (1 << WGM01) | (1 << WGM00); // Fast-PWM
  TCCR0A |= (1 << COM0A1); // Nível lógico de súbida

  //----------------- Configurando Prescaler -----------------

  TCCR0B |= (1 << CS02) | (1 << CS00); // 1024

  //----------------- Timer -----------------

  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12) | (1 << CS11); // borda de descida
  OCR1A = 200; // Valor limite do contador
  TIMSK1 |= (1 << OCIE1A); // ligando a interrupcao por comparacao

  //----------------- Interrupção externa: -----------------

  PCICR |= (1 << PCIE2); // PD
  PCMSK2 |= (1 << PCINT17); // Interrupção em PD1

  //----------------- Configuração do conversor ADC: -----------------

  ADCSRA |= (1 << ADEN); // Liga o ADC
  // PRESCALER:

  ADCSRA |= (1 << ADPS2) |(1 << ADPS1) |(1 << ADPS0); // Prescaler = 128(125kHz)
  ADMUX |= (1 << REFS0); // Usando AVCC como referência

  sei();

  OCR0A = 0;

  while(1){

    
    
  }
}
