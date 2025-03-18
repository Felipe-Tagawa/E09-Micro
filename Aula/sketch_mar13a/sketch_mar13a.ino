int main(){

  DDRD = 0;
  DDRB = 0;
  DDRC = 255; // Todas os pinos de C setados como saída.
  DDRD |= (1 << PD0) | (1 << PD1);
  PORTC = 0; // Inicialmente todos os Leds desligados.


  for(;;){
    // Todos os Leds acendem e apagam em intervalos de 300ms com "A" pressionado.
    if(!(PIND & (1 << PD0))){ // Porta A.

      PORTC = 0; // Desligando os leds.
      _delay_ms(1000);
      PORTC = 255; // Ligando os leds após o tempo de 300ms.
      _delay_ms(1000);
    }
    // Os leds acendem em pares, alternadamente, em intervalos de 800ms com "B" pressionado.
    if(!(PIND & (1 << PD1))){ // Porta B.

      PORTC = 0; // Inicia tudo desligado.
      PORTC |= (1 << PC0) | (1 << PC2);
      _delay_ms(800);
      PORTC = 0;
      PORTC |= (1 << PC1) | (1 << PC3);
      _delay_ms(800);

    }
    // Os leds acendem sequencialmente em intervalos de 300ms e em seguida todos apagam e se repete tudo com "C" pressionada.
    if(!(PIND & (1 << PB0))){ // Porta C.

      PORTC = 0;
      _delay_ms(300);
      PORTC |= (1<< PC0);
      _delay_ms(1000);
      PORTC |= (1<< PC1);
      _delay_ms(1000);
      PORTC |= (1<< PC2);
      _delay_ms(1000);
      PORTC |= (1<< PC3);
      _delay_ms(1000);
    }

    // Os leds todos iniciam acesos e vão se apagando do último para o primeiro em intervalos de 300ms e se repete com "D" pressionada.
    if(!(PINB & (1 << PB1))){
      
      PORTC |= (1 << PC0) | (1 << PC1) | (1 << PC2) | (1 << PC3); // Ligando os leds.
      _delay_ms(1000);
      PORTC &= ~(1 << PC3);
      _delay_ms(1000);
      PORTC &= ~(1 << PC2);
      _delay_ms(1000);
      PORTC &= ~(1 << PC1);
      _delay_ms(1000);
      PORTC &= ~(1 << PC0);
      _delay_ms(1000);
    }
  }
}
