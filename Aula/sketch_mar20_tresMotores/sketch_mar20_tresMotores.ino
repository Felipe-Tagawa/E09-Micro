int main(){

  #define Chave1 PD5
  #define M1 PD0 // 30HP
  #define Chave2 PB0
  #define M2 PD1 // 50HP
  #define Chave3 PD4
  #define M3 PD3 // 70HP

  DDRD = 0;
  DDRB = 0;
  DDRD |= (1 << M1) | (1 << M2) | (1 << M3); // Saídas.

  while(1){

    PORTD = 0;
    // Primeiro caso é olhar a chave 3, em relação do Motor.
    if(PIND & (1 << Chave3){
      
    }

    
    
  }
}
