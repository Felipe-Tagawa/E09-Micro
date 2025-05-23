int main(){
// Primeiro precisamos definir as saídas(Motores):

DDRC |= (1 << PC0) | (1 << PC1) | (1 << PC2); // Definindo os Motores como saída.
DDRD &= ~((1 << PD7) | (1 << PD6) | (1 << PD5)); // Definindos os pinos de entrada(Botões).
PORTD |= (1 << PD7) | (1 << PD6) | (1 << PD5); // Habilitando pull-up nos 3 botões.

PORTC = 0; // Inicia tudo desligado.


  while(1){

    int BotaoA = (!(PIND & (1 << PD7)));
    int BotaoB = (!(PIND & (1 << PD6)));
    int BotaoC = (!(PIND & (1 << PD5)));

    if(BotaoA){
      // Aciona o motor 1(30Hz):
      PORTC |= (1 << PC0);
    }
    else if(BotaoB){
      // Aciona o motor 2(50Hz):
      PORTC |= (1 << PC1);
    }
    else if(BotaoC){
      // Aciona o motor 3(70Hz):
      PORTC |= (1 << PC2);
    }
    // Quando nenhum botão apertado, apaga tudo.
    else{
      PORTC = 0;
    }
    
  }
  
}
