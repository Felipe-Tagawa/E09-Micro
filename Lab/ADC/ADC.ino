int main(){

  ADCSRA |= (1 << ADEN); // Liga o ADC.
  ADCSRA |= (1 << ADSC); // Inicia o processo de conversão.

  // Prescaler:

  ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // 1 1 1 -- Prescaler 128(16Mhz/128) --> 125kHz
  // 1 conversão a cada 13 ciclos.

  ADMUX &= ~(1 << REFS1) | (1 << REFS0); // Configuração do Canal e Amplitude de Referência(Usando AREF - tabela).
  ADMUX |= (1 << MUX0); // PC1 como entrada(tabela).

  while(){
    
  }
}
