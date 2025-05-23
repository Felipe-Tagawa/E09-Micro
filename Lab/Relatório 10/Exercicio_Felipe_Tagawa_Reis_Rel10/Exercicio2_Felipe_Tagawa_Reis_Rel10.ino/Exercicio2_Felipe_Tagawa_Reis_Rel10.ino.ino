#define pwm_out PD6 // Timer0
#define PINO_ADC PC2 // Potenciômetro

// -- A modificação feita foi mudar PC0 para PC2 e depois alterar (ADMUX & 0b11100000) para...  --
// -- ...(ADMUX & 0b11110010) representativo do ADC2.                                           --
// -- Mas ele muda de acordo com o potenciômetro assim como o outro.                            --

unsigned long int leituraAD = 0;

int main(){
  DDRD |= (1 << pwm_out); // PWM como saída.
  TCCR0A |= (1 << WGM01) | (1 << WGM00); // FAST PWM
  TCCR0A |= (1 << COM0A1); // Comportamento de nível lógico alto no tempo de comparação.
  // Prescaler
  TCCR0B |= (1 << CS01); // 2MHz e 500ms
  OCR0A = 0; // Comparações (led 0%).
  
  // Configuração do ADC
  ADCSRA |= (1 << ADEN); // Liga o ADC.
  // Prescaler:
  ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // 1 1 1 -- Prescaler 128(16Mhz/128) --> 125kHz
  ADMUX = (1 << REFS0); // Configuração do Canal e Amplitude de Referência(Usando VCC como referência).
  
  while(1){

    ADMUX = (ADMUX & 0b11110010) | PINO_ADC; // Seleciona canal ADC2
    
    // Inicia uma conversão
    ADCSRA |= (1 << ADSC);
    
    // Espera a conversão ser concluída (bit ADSC fica em 1 até voltar para 0)
    while((ADCSRA & (1 << ADSC)) == (1 << ADSC));
    
    // Armazenando a conversão:
    leituraAD = ADCL;
    leituraAD |= (ADCH << 8);
    OCR0A = leituraAD * 255 / 1023; // Conversãol (8 bits do Timer0)
  }
}
