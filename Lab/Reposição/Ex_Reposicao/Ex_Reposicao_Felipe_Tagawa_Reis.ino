#define MOTOR PD1    
#define BOTAO_ON PB1   
#define BOTAO_OFF PB2  

volatile bool motor_running = false;
volatile bool start_counting = false;
unsigned long int Ton = 0; // Contador de tempo

// Interrupção dos botões
ISR(PCINT0_vect) {
    // Botão ON pressionado
    if (!(PINB & (1 << BOTAO_ON)) && !motor_running && !start_counting) {
        start_counting = true; // Começar a contar os 10s
        Ton = 0;  // Reset
    }
    
    // Botão OFF pressionado e motor ligado
    if (!(PINB & (1 << BOTAO_OFF)) && motor_running) {
        PORTD &= ~(1 << MOTOR);  // Desliga o motor completamente
        motor_running = false;
    }
}

// Timer0 Overflow(pico):
ISR(TIMER0_OVF_vect) {
    if (start_counting) {
        Ton++;
        
        // Verificar se já passaram aproximadamente 10s (10s / 16.34ms ~= 612)
        if (Ton >= 612) {
            // Ligar o motor apenas depois de contar os 10s
            if (!(PINB & (1 << BOTAO_ON))) { // Botão ainda pressionado após 10s -- mantido pressionado como no enunciado.
                PORTD |= (1 << MOTOR); // Liga o motor
                motor_running = true; // Motor ligado
            }
            start_counting = false;
            Ton = 0; // Reset
        }
    }
}

int main() {
    // Motor como saída
    DDRD = (1 << MOTOR);
    
    // Botões como entradas com pull-up
    DDRB &= ~((1 << BOTAO_ON) | (1 << BOTAO_OFF));
    PORTB |= (1 << BOTAO_ON) | (1 << BOTAO_OFF);
    
    // Garantir que o motor comece desligado
    PORTD &= ~(1 << MOTOR);
    
    // Configurar interrupção para botões
    PCICR |= (1 << PCIE0);
    PCMSK0 |= (1 << PCINT1) | (1 << PCINT2);
    
    // Configurar Timer0
    TCCR0A = 0; // Normal - aprendido em aula com professor.                            
    TCCR0B = (1 << CS02) | (1 << CS00); // Prescaler 1024
    TIMSK0 |= (1 << TOIE0); // Habilitar interrupção de overflow
    
    // Habilitar interrupções globais
    sei();
    
    while (1) {
    }
}
