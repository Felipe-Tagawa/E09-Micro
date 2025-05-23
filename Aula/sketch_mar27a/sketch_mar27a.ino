#define CHAVE1 PD1
#define EMERGENCIA PD2
#define Led1 PC5
#define Led2 PC0

unsigned char j;
ISR(INT0_vect){
  PORTC &= ~(1 << Led1); // Desliga o led 1.
  for(j = 0; j < 20; j++){
    PORTC  ^= (1 << Led2); // Alterna o led de alerta.
    _delay_ms(200);
  }
}

int main(){

  DDRD = 0; // Todas entradas.
  DDRC |= (1 << Led1) | (1 << Led2); // Saídas.
  PORTC = 0; // Leds desligados.

  EICRA = (1 << ISC00); // INT. na mudança de nível lógico.
  EIMSK = (1 << INT0); // Habilita o INT0.
  sei(); // Liga o serviço geral de INT.
  
  while(1){

    if(PIND & (1 << CHAVE1)){
      PORTC |= (1 << Led1); // Ativa o Led 1
      _delay_ms(5000); // 5 segundos.
      PORTC &= ~(1 << Led1); // Apaga este led.
    }
    
  }
}
