int main() {
    DDRD |= (1 << PD7) | (1 << PD6); // Motor(PD7) e Alarme(PD6) definidos como saída.
    PORTD = 0; // Inicializa com tudo desligado.

    // Botões: PC6 (LIGA - NA, pull-down), PC5 (DESLIGA - NF, pull-up)
    DDRC &= ~((1 << PC6) | (1 << PC5)); // Definir como entrada os dois botões.
    PORTC |= (1 << PC5); // Habilitar pull-up apenas para o botão 2 (NF)

    // Configuração do sensor S1 (PD0 como entrada com pull-up)
    DDRD &= ~(1 << PD0);
    PORTD |= (1 << PD0); // Habilita pull-up no sensor S1

    while (1) {
        int botao_1 = (PINC & (1 << PC6)); // Botão NA com pull-down (HIGH quando pressionado)
        int botao_2 = !(PINC & (1 << PC5)); // Botão NF com pull-up (LOW quando pressionado)
        int S1 = (PIND & (1 << PD0)); // Lê o sensor de amontoamento

        if (botao_1) {
            PORTD |= (1 << PD7); // Liga o motor
            if (S1) {
                PORTD &= ~(1 << PD7); // Para o motor
                PORTD |= (1 << PD6);  // Liga o alarme
            } else {
                PORTD &= ~(1 << PD6); // Desliga o alarme
            }
        }

        if (botao_2) {
            PORTD &= ~(1 << PD7); // Desliga o motor
        }
    }
}
