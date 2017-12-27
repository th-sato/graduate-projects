/*
               Microgenios Solu��es Eletr�nicas Ltda.

********************************************************************************
 PROGRAMA EXEMPLO: Utilizar a interrup��o do timer0 para incrementar contador
                   de 0 a 255 a cada 1 segundo e mostrar no PORTD.
         OBJETIVO: Aprender a utilizar a interrup��o do timer.
            AUTOR: Fabio Mulero.[fabio@microgenios.com.br]
********************************************************************************
************************ Configura��es do KIT Picgenios ************************
 CRISTAL: 8Mhz.

 CHAVES DE FUN��O:
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
       TMR0H = 0xE1 ;           // Carrega o valor alto do n�mero 57723.
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

   // Configura��o do Timer0.
                            // Cristal de 8Mhz, ciclo de m�quina: 8MHz / 4 = 2Mhz --> 1/2Mhz = 0,5us.
   T0CON.T0CS = 0;          // Timer0 operando como temporizador.
   T0CON.PSA = 0;           // Prescaler ativado.
   T0CON.T0PS2 = 1;         // Define prescaler 1:256.
   T0CON.T0PS1 = 1;         // Define prescaler 1:256.
   T0CON.T0PS0 = 1;         // Define prescaler 1:256.
   T0CON.T08BIT = 0;        // Define contagem no modo 16 bits.
   // Valor para 1 segundo.
   TMR0H = 0xE1;            // Carrega o valor alto do n�mero 57723.
   TMR0L = 0x7B;            // Carrega o valor baixo do numero 57723.
   INTCON.TMR0IE = 1;       // Habilita interrup��o do timer0.
   INTCON.TMR0IF = 0;       // Apaga flag de estouro do timer0, pois � fundamental para a sinaliza��o do estouro.
   T0CON.TMR0ON = 1;        // Liga timer0.
   INTCON.GIE = 1;          // Habilita as interrup��es n�o-mascaradas.
   INTCON.PEIE = 1;         // Habilita as interrup��es dos perifericos.

   while(1);
}