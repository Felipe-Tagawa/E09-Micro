#define VERMELHO_ON (1<<PC5)
#define AMARELO_ON (1<<PC1)
#define VERDE_ON (1<<PB5)

int main(){

  // Configurações:
  DDRD = 0; // Todos os pinos de D serão de entrada.
  // DDRB = 0b00100010; // PB1 e PB5 são saídas.
  // DDRC = 0b00100010; // PC1 e PC5 são saídas.

  DDRC = VERMELHO_ON | AMARELO_ON;
  DDRB = VERDE_ON;
  
  
  while(1){

    // Liga somente o vermelho e espera 2s.
    PORTC = VERMELHO_ON; // Liga o pino PC5.
     PORTB = 0;
    _delay_ms (2000);
    // Liga somente o amarelo e espera 1s.
    PORTC = AMARELO_ON;
    PORTB = 0; 
    _delay_ms (1000);
    // Liga somente o verde e espera 2s.
    PORTB = VERDE_ON;
    PORTC = 0;
    _delay_ms (2000);
    
  }
}
