#include <util/delay.h>
void setup() {
  // put your setup code here, to run once:
    DDRD = 0b00001110;
    PORTD = 0b10001110; // 1 na porta 7 transforma o pino em pull up.

}

void loop() {
  // put your main code here, to run repeatedly:

    // Fazer ele ficar repetindo de 0 a 3, voltando pra 0.
    if(!(PIND & 0b10000000)){ // Máscara.
      PORTD = 0b00000000;
      _delay_ms(500);
    }
    if(!(PIND & 0b10000000)){ // Máscara.
      PORTD = 0b00000001;
      _delay_ms(500);
    }
    if(!(PIND & 0b10000000)){ // Máscara.
      PORTD = 0b00000010;
      _delay_ms(500);
    }
    if(!(PIND & 0b10000000)){ // Máscara.
      PORTD = 0b00000011;
      _delay_ms(500);
    }

}
