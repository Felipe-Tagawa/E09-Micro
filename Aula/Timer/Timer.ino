#define led PC0
#define chave PD4 // PD4 tem entrada de clock externo(clock manual).

int main(){

  DDRC = 255; // Portal C como saída.
  DDRD = 0; // Portal D como entrada.

  TCCR0A = 0;
  TCCR0B |= (1 << CS02) | (1 << CS01) | (1 << CS00); // Clock externo com borda de subida(tabela).
  
  while(1){

  if(TCNT0 == 255){
    PORTC ^= 255; // Liga o led.
    TCNT0 = 0; // Reinicia o contador.
  }
    
  }
}
