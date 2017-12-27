/*
               Microgenios Soluções Eletrônicas Ltda.

********************************************************************************
 PROGRAMA EXEMPLO: Utilizar a interrupção do timer0 para incrementar contador
                   de 0 a 255 a cada 1 segundo e mostrar no PORTD.
         OBJETIVO: Aprender a utilizar a interrupção do timer.
            AUTOR: Fabio Mulero.[fabio@microgenios.com.br]
********************************************************************************
************************ Configurações do KIT Picgenios ************************
 CRISTAL: 8Mhz.

 CHAVES DE FUNÇÃO:
  --------------------- ----------------------
 |GLCD\LCD ( 1) = OFF  |DIS1     ( 1) = OFF   |
 |RX       ( 2) = OFF  |DIS2     ( 2) = OFF   |
 |TX       ( 3) = OFF  |DIS3     ( 3) = OFF   |
 |REL1     ( 4) = OFF  |DIS4     ( 4) = OFF   |
 |REL2     ( 5) = OFF  |INFR     ( 5) = OFF   |
 |SCK      ( 6) = OFF  |RESIS    ( 6) = OFF   |
 |SDA      ( 7) = OFF  |TEMP     ( 7) = OFF   |
 |RTC      ( 8) = OFF  |VENT     ( 8) = OFF   |
 |LED1     ( 9) = ON   |AN0      ( 9) = OFF   |
 |LED2     (10) = OFF  |AN1      (10) = OFF   |
  --------------------- ----------------------
********************************************************************************
*/

// Variaveis Globais
unsigned char ucContador;       // Variavel de armazenamento do contador.

void interrupt(){               // Palavra "interrupt" sempre em minuscula.
    // Incrementa Contador.
    if(INTCON.TMR0IF==1){       // Incrementa somente quando existir o overflow do timer 0.
       // Recarrega o timer0.
       TMR0H = 0xE1 ;           // Carrega o valor alto do número 57723.
       TMR0L = 0x7B;            // Carrega o valor baixo do numero 57723.

       INTCON.TMR0IF = 0;       // Limpa o flag de estouro do timer0 para uma nova contagem de tempo.
       ucContador++;            // Esse operador aritmetico(++) realiza o mesmo que variavel = variavel + 1.
       PORTD=ucContador;        // Coloca o valor do Contador no PORTD.
    }
}


void main(){

   ADCON1 = 0x0F;           // Configura todos os pinos A/D como I/O

   TRISD = 0;               // Define todos os pinos Do PORTD como saida.

   ucContador=0;            // Inicializa a variavel com o valor 0.

   // Configuração do Timer0.
                            // Cristal de 8Mhz, ciclo de máquina: 8MHz / 4 = 2Mhz --> 1/2Mhz = 0,5us.
   T0CON.T0CS = 0;          // Timer0 operando como temporizador.
   T0CON.PSA = 0;           // Prescaler ativado.
   T0CON.T0PS2 = 1;         // Define prescaler 1:256.
   T0CON.T0PS1 = 1;         // Define prescaler 1:256.
   T0CON.T0PS0 = 1;         // Define prescaler 1:256.
   T0CON.T08BIT = 0;        // Define contagem no modo 16 bits.
   // Valor para 1 segundo.
   TMR0H = 0xE1;            // Carrega o valor alto do número 57723.
   TMR0L = 0x7B;            // Carrega o valor baixo do numero 57723.
   INTCON.TMR0IE = 1;       // Habilita interrupção do timer0.
   INTCON.TMR0IF = 0;       // Apaga flag de estouro do timer0, pois é fundamental para a sinalização do estouro.
   T0CON.TMR0ON = 1;        // Liga timer0.
   INTCON.GIE = 1;          // Habilita as interrupções não-mascaradas.
   INTCON.PEIE = 1;         // Habilita as interrupções dos perifericos.

   while(1);
}