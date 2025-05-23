int main(){
    // Definição dos motores:
    #define M1 PC0
    #define M2 PC1
    #define M3 PC2
    // Definição dos Botões:
    #define Botao_A PD7
    #define Botao_B PD6
    #define Botao_C PD5
    
    // Configurações iniciais de entrada e saída.
    DDRC |= (1 << M1) | (1 << M2) | (1 << M3);  // Motores definidos como saída
    DDRD &= ~((1 << Botao_A) | (1 << Botao_B) | (1 << Botao_C));  // Botões definidos como entrada
    PORTD |= (1 << Botao_A) | (1 << Botao_B) | (1 << Botao_C);  // Pull-up nos botões
    PORTC = 0;  // Todos motores desligados
    
    while(1){
        // Leitura dos botões:
        int BotaoA = (!(PIND & (1 << Botao_A)));
        int BotaoB = (!(PIND & (1 << Botao_B)));
        int BotaoC = (!(PIND & (1 << Botao_C)));
        
        // Desliga todos os motores no início de cada ciclo
        PORTC = 0;

        // Motor 3 tem prioridade (70HP -- deve ser verificado primeiro):
        if (BotaoC) {
            PORTC |= (1 << M3);
            _delay_ms(800);
        } 
        else {
            // Motor 3 não está ativo, podemos usar M1 e/ou M2.
            
            // Se ambos botões A e B estiverem pressionados (30HP + 50HP = 80HP < 90HP --> OK)
            if (BotaoA && BotaoB) {
                PORTC |= (1 << M1) | (1 << M2);  // Liga ambos os motores
                _delay_ms(300);  // Delay reduzido para 300ms
            }
            // Caso contrário, precisamos verificar cada um individualmente
            else if (BotaoB && !BotaoA) {
                PORTC |= (1 << M2);  // Liga apenas M2
                _delay_ms(800);
            }
            else if (BotaoA && !BotaoB) {
                PORTC |= (1 << M1);  // Liga apenas M1
                _delay_ms(800);
            }
        }
    }
}
