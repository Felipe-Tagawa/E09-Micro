int main(){
  
  DDRD = 255;
  TCCR0A |= (1 << COM0A1); // Modo não-invertido
  TCCR0A |= (1 << WGM01) | (1 << WGM00); // Fast-PWM
  TCCR0B |= (1 << WGM02); // Fast-PWM
  TCCR0B |= (1 << CS01); // Prescaler = 8

  OCR0A = 60; // Duty-Cycle (tensão de saída no pino)
  
  while(1){
    
  }
}
