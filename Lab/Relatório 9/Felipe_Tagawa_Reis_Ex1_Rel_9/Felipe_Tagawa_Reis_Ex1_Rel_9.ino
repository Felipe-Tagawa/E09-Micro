#define pwm_out PD6 // Timer 0 e OCR0A.
//#define led PD7
#define botao PD1
// unsigned int Ton = 0; // Vai ficar somando 10 no while na contagem de nível lógico, quantidade de ticks em '1'.

ISR(PCINT2_vect){
  // Apertando o botão:
    if(!(PIND & (1 << botao))){
      OCR0A = 128; // 255 * 0.5 // Ele quer 50% de intensidade.
    }
    else
      OCR0A = 0;
}

int main(){

  DDRD |= (1 << pwm_out); // PWM como saída.
  PORTD &= ~(1 << pwm_out); // PWM inicia desligado.
  PORTD |= (1 << botao); // Habilitando pull-up.

  
  TCCR0A |= (1 << WGM01) | (1 << WGM00); // FAST PWN
  TCCR0A |= (1 << COM0A1); // Comportamento de nível lógico alto no tempo de comparação.

  // Prescaler
  TCCR0B |= (1 << CS01); // 2MHz e 500ms

  OCR0A = 0; // Comparações (led 0%).

  // Interrupção Externa:

  PCICR |= (1 << PCIE2);
  PCMSK2 |= (1 << PCINT17); // PD1

  sei();

  while(1){

  }
}
