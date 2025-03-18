void setup() {
  // put your setup code here, to run once:
  DDRD = 0b000001110;
  PORTD = 0b100001110;

}

void loop() {
  // put your main code here, to run repeatedly:

  // Fazer ele ficar repetindo (1->2->0).
    if(!(PIND & 0b10000000)){ // Máscara.
      PORTD = 0b00000001;
      _delay_ms(500);
    }
    if(!(PIND & 0b10000000)){ // Máscara.
      PORTD = 0b00000010;
      _delay_ms(500);
    }
    if(!(PIND & 0b10000000)){ // Máscara.
      PORTD = 0b00000000;
      _delay_ms(500);
    }
  
}
