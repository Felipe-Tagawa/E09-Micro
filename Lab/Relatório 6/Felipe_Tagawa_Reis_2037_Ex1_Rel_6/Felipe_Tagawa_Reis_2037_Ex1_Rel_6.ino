#define BT1 PD2 // INT0
// #define BT2 PD3 // INT1
#define Led1 PD5
#define Led2 PD4

ISR(INT0_vect){
  PORTD ^= (1 << Led2);
  _delay_ms(1000);
  PORTD = 0;
}


int main(){

// PD2 e PD3 são padrões para INT0 e INT1, respectivamente.
//EICRA |= (1 << ISC11) | (1 << ISC10); // INT1
//EICRA |= (1 << ISC01) | (1 << ISC00); // INT0

  DDRD |= (1 << Led1) | (1 << Led2); // Definindo os Leds como saída.
  PORTD |= (1 << BT1); // Habilitando pull-up no primeiro botão.

  EICRA = 0b00000011; // Configura a interrupção externa para transição de subida.
  EIMSK = 0b00000001; // Ativa a interrupção externa em 0.

  sei(); // Habilita interrupções globais.


  while(1){

    PORTD ^= (1 << Led1);
    _delay_ms(500);
  }
}
