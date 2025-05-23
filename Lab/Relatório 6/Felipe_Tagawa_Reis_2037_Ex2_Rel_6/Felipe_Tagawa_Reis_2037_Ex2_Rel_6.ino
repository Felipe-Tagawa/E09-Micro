#define BT1 PD2 // INT0
#define BT2 PD3 // INT1
#define Led1 PD5 // Led1
#define Led2 PD4 // Led2

// Volatile ajuda em erros de compilação(não funciona sem)
volatile bool ativa_INT0 = true;

ISR(INT0_vect) {
    PORTD ^= (1 << Led2); // Alterna Led2
    _delay_ms(1000);
    PORTD ^= (1 << Led2); // Desliga Led2
}

ISR(INT1_vect) {
    if (ativa_INT0) {
        // Desativa INT0
        EIMSK &= ~(1 << INT0);
        ativa_INT0 = false;
        PORTD &= ~(1 << Led1); // Apaga Led1 ao desativar INT0
    } else {
        // Ativa INT0
        EIMSK |= (1 << INT0);
        ativa_INT0 = true;
    }
}

int main() {
    // PD2 e PD3 são padrões para INT0 e INT1, respectivamente.
    EICRA |= (1 << ISC01) | (1 << ISC00); // INT0 - Transição de subida
    EICRA |= (1 << ISC11); // INT1 - Transição de descida.

    DDRD |= (1 << Led1) | (1 << Led2); // Definindo os Leds como saída.
    PORTD |= (1 << BT1) | (1 << BT2); // Habilitando pull-up nos botões.

    EIMSK |= (1 << INT0) | (1 << INT1); // Ativa INT0 e INT1 no início

    sei(); // Habilita interrupções globais.

    while (1) {
        if (ativa_INT0) {
            PORTD ^= (1 << Led1); // Led1 pisca apenas se INT0 estiver ativado
            _delay_ms(500);
        }
    }
}
