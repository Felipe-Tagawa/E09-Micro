int main(){

  #define STemperatura PD2
  #define SPressao PD4
  #define SNivel PD5
  #define SPeso PB0
  #define led PD0
  
  DDRD |= (1 << led); // PD0 como saída.
  DDRD &= ~(1 << SNivel) | (1 << SPressao) | (1 << STemperatura); // Entradas.
  // Sem necessidade de pull-up(chaves já em zero ou já em um).

  PORTD = 0; // Todos os pinos inicialmente desligados.
  DDRB &= ~(1 << SPeso); // Apenas PB0 como entrada.
  


  while(1){

    PORTD = 0; // Desliga ao reiniciar.
    // 1. Nível alto e temperatura alta e pressão alta.
    while((PIND & (1 << STemperatura)) && (PIND & (1 << SNivel)) && (PIND & (1 << SPressao))){
      PORTD |= (1 << led); // Liga o Led.
    }

    // 2. Nível baixo com temperatura alta e peso alto.
    while((PIND & (1 << STemperatura)) && (PINB & (1 << SPeso)) && !(PIND & (1 << SNivel))){
      PORTD |= (1 << led); // Liga o Led.
    }

    // 3. Nível baixo, temperatura baixa e pressão alta.
    while(!(PIND & (1 << STemperatura)) && (PIND & (1 << SPressao)) && !(PIND & (1 << SNivel))){
      PORTD |= (1 << led); // Liga o Led.
    }

    // 4. Nível baixo, peso baixo e temperatura alta.
    while((PIND & (1 << STemperatura)) && !(PINB & (1 << SPeso)) && !(PIND & (1 << SNivel))){
      PORTD |= (1 << led); // Liga o Led.
    }
   
  }
  
}
