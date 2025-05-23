//#define sensor120 PD2
//#define sensor100 PD3
#define forno PB0

ISR(INT0_vect){
  PORTB = 0;
}

ISR(INT1_vect){
  PORTB |= (1 << forno);
}

int main(){

  DDRD = 0; // Todas entradas.
  DDRB |= (1 << forno); // forno como saída.

  PORTB = 0;

  EICRA = (1 << ISC01); // Borda de descida para INT0.
  EIMSK = (1 << INT0); // Habilita INT0.

  EICRA = (1 << ISC11); // Borda de descida para INT1.
  EIMSK = (1 << INT1); // Habilita INT1.
  sei();


  while(1){
    
  }
}
