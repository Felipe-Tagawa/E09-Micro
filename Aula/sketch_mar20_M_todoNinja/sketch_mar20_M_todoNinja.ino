int main(){

  #define STemperatura PD2
  #define SPressao PD4
  #define SNivel PD5
  #define SPeso PD7
  #define led PD0
  #define liga_led PORTC!= (1 << led)

  while(1){

    PORTC = 0; // Desliga 0.

    switch(PIND){
      PORTC = 0;
      case 52: liga_led; // PIND = 0b00110100.
        break;
      case 132: liga_led; // PIND = 0b10000100.
        break;
      case 16: liga_led; // PIND = 0b00010000.
        break;
      case 4: liga_led; // PIND = Ob00000100.
        break;
      default:
        PORTC = 0;
        break;
    }
   
  }
  
}
