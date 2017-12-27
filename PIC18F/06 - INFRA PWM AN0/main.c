/*
               Microgenios Solu��es Eletr�nicas Ltda.

********************************************************************************
 PROGRAMA EXEMPLO: Leitura do canal A/D AN0, mostrar a representa��o no PWM
                   da ventoinha E utilizar infravermelho para verificar RPM.
         OBJETIVO: Aprender a utilizar o canal PWM E TIMER1 como contador.
            AUTOR: Fabio Mulero.[fabio@microgenios.com.br]
********************************************************************************
 MICROCONTROLADOR: PIC18F4520.
 http://ww1.microchip.com/downloads/en/DeviceDoc/39631E.pdf

 PLACA DE DESENVOLVIMENTO: KIT PICgenios - PIC18F
 http://www.microgenios.com.br/news/index.php?option=com_content&task=view&id=88&Itemid=134

 SOFTWARE: MikroC PRO for PIC
 http://www.mikroe.com/en/compilers/mikroc/pro/pic/

************************ Configura��es do KIT Picgenios ************************
 CRISTAL: 8Mhz.

 CHAVES DE FUN��O:
  --------------------- ----------------------
 |GLCD\LCD ( 1) = ON   |DIS1     ( 1) = OFF   |
 |RX       ( 2) = OFF  |DIS2     ( 2) = OFF   |
 |TX       ( 3) = OFF  |DIS3     ( 3) = OFF   |
 |REL1     ( 4) = OFF  |DIS4     ( 4) = OFF   |
 |REL2     ( 5) = OFF  |INFR     ( 5) = ON    |
 |SCK      ( 6) = OFF  |RESIS    ( 6) = OFF   |
 |SDA      ( 7) = OFF  |TEMP     ( 7) = OFF   |
 |RTC      ( 8) = OFF  |VENT     ( 8) = ON    |
 |LED1     ( 9) = OFF  |AN0      ( 9) = ON    |
 |LED2     (10) = ON   |AN1      (10) = OFF   |
  --------------------- ----------------------
********************************************************************************
OBS:
- HABILITAR BIBLIOTECA LCD.
- HABILITAR BIBLIOTECA PWM.
- HABILITAR BIBLIOTECA A/D.
- HABILITAR BIBLIOTECA CONVERTIONS.
********************************************************************************
*/


// vARIAVEIS GLOBAIS
unsigned char ucTexto[10];   // Matriz para armazenamento de texto.
unsigned char ucPorcentagem; // Armazena a porcentagem do PWM.
unsigned int iLeituraAD = 0; // Define vari�vel para armazenamento da leitura AD.
unsigned int iReg_timer1;    // Armazena o RPM.

// CONFIGURA��O DOS PINOS DO LCD.
sbit LCD_RS at RE2_bit;
sbit LCD_EN at RE1_bit;
sbit LCD_D7 at RD7_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D4 at RD4_bit;

// DIRE��O DOS PINOS.
sbit LCD_RS_Direction at TRISE2_bit;
sbit LCD_EN_Direction at TRISE1_bit;
sbit LCD_D7_Direction at TRISD7_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D4_Direction at TRISD4_bit;

void interrupt(){
   if (INTCON.TMR0IF == 1){    // Se o flag de estouro do TIMER0 for igual a 1, ent�o
      PORTB.RB0 = ~PORTB.RB0;  // Inverte o estado do PORTB.RB0.
      TMR0L = 0X7B;                  // Carrega valores de contagem
      TMR0H = 0XE1;                  // Carrega valores de contagem
      INTCON.TMR0IF = 0;             // Seta T0IE, apaga flag de entouro do TIMER0
      iReg_timer1 = TMR1L*(60/7);    // Pega valor lido do timer1 e multiplica por 60 para saber rota��o por minuto.
                                     // e divide por 7 pois a ventoinha para dar uma volta completa realiza 7 pulsos.
      TMR1L = 0;                     // Limpa contador.
   }
}

void main(){
   TRISB = 0;                        // Define PORTB como saida.
   TRISD = 0;                        // Define PORTD como saida.
   TRISC.RC0 = 1;                    // Define PORTC.RC0 como entrada.
   TRISC.RC2 = 0;                    // Define PORTC.RC2 como saida.
   TRISE = 0;                        // Define PORTE como saida.
   PORTB = 0;                        // Limpa PORTB.

   // Configura��o das interrup��es
   INTCON.GIEH = 1;   // Habilita as interrup��es e a interrup��o de alta prioridade.
   INTCON.GIEL = 1;   // Habilita as interrup��es e a interrup��o de baixa prioridade
   RCON.IPEN = 1;     // Configura 2 niveis de interrup��o.

   // Timer 0
   INTCON.TMR0IF = 0;
   INTCON2.TMR0IP = 1;
   INTCON.TMR0IE = 1;

   T0CON = 0B10000100; // Configura timer modo 16 bits, com prescaler
   TMR0L = 0X7B;       // Carrega valores de contagem
   TMR0H = 0XE1;       // Carrega valores de contagem
   INTCON.TMR0IF = 0;  // Apaga flag de estouro do TIMER0

   // Timer 1
   T1CON = 0B10000011; // Liga TIMER1 como Contador em RC0, prescaler 1:1, modo 16bits.
   TMR1L = 0;          // Carrega valor de contagem baixa do TIMER1
   TMR1H = 0;          // Carrega valor de contagem alta do TIMER1
   PIR1.TMR1IF = 0;    // Apaga flag de estouro do TIMER1
   
   ADCON0 = 0b00000001;              // Configura conversor A/D Canal 0, convers�o desligada, A/D ligado.
   ADCON1 = 0b00001110;              // Configura todos canais como Digital menos AN0 e REF Interna.
   ADCON2 = 0b10111110;              // Configura conversor A/D para resultado justificado a direita, clock de 20 TAD, clock de Fosc/64.

   // Config. LCD no modo 4 bits
   Lcd_Init();                               // Inicializa LCD.

   Lcd_Cmd(_LCD_CLEAR);                      // Apaga display.
   Lcd_Cmd(_LCD_CURSOR_OFF);                 // Desliga cursor.
   Lcd_Out(1, 1, "Duty Cycle: ");            // Escreve mensagem no LCD.
   
   PWM1_Init(5000);                  // Inicializa m�dulo PWM com 5Khz
   PWM1_Set_Duty(255);               // Seta o Duty-cycle do PWM em 100%.
   PWM1_Start();                     // Inicia PWM.

   while(1){   // Aqui Definimos Uma Condi��o Sempre Verdadeira Como Parametro, Portanto Todo O Bloco Ser� Repetido Indefinidamente.
      iLeituraAD= ADC_Read(0);          // L� Canal AD 0
      iLeituraAD=(iLeituraAD*0.24);     // Converte valor para o duty cycle [255/(1023 pontos do A/D)]
      PWM1_Set_Duty(iLeituraAD);        // Envia o valor lido de "iLeituraAD" para o m�dulo CCP1 PWM
      iLeituraAD=(iLeituraAD*0.41);     // Converte valor para o duty cycle em %
      WordToStr(iLeituraAD, ucTexto);   // Converte o valor lido no A/D em string
      Lcd_Out(1,11,ucTexto);            // Imprime no LCD o valor do Duty Cycle.

      
      WordToStr(iReg_timer1, ucTexto);  // Converte o valor lido no iReg_timer1 em string
      Lcd_Out(2,1,ucTexto);             // Imprime no LCD o valor da RPM.
      Lcd_Out_CP(" RPM");               // Unidade "RPM".
      Delay_10us;
   }
}
