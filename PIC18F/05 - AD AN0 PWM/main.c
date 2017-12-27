/*
               Microgenios Soluções Eletrônicas Ltda.

********************************************************************************
 PROGRAMA EXEMPLO: Leitura do canal A/D AN0 e mostrar a representação no PWM
                   da ventoinha.
         OBJETIVO: Aprender a utilizar o canal PWM.
            AUTOR: Fabio Mulero.[fabio@microgenios.com.br]
********************************************************************************
 MICROCONTROLADOR: PIC18F4520.
 http://ww1.microchip.com/downloads/en/DeviceDoc/39631E.pdf

 PLACA DE DESENVOLVIMENTO: KIT PICgenios - PIC18F
 http://www.microgenios.com.br/news/index.php?option=com_content&task=view&id=88&Itemid=134

 SOFTWARE: MikroC PRO for PIC
 http://www.mikroe.com/en/compilers/mikroc/pro/pic/

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
 |RTC      ( 8) = OFF  |VENT     ( 8) = ON    |
 |LED1     ( 9) = OFF  |AN0      ( 9) = ON    |
 |LED2     (10) = OFF  |AN1      (10) = OFF   |
  --------------------- ----------------------
********************************************************************************
*/

void main(){
   unsigned int  uiValorAD;     // Variavel que armazena o valor do A/D.

   PORTA = 255;
   TRISA = 255;                 // Configura PORTA pins como entrada

   ADCON0 = 0b00000001;  // Configura conversor A/D Canal 0, conversão desligada, A/D ligado.
   ADCON1 = 0b11001110;  // Configura todos canais como Digital menos AN0 e REF Interna.
   ADCON2 = 0b10111110;  // Configura conversor A/D para resultado justificado a direita, clock de 20 TAD, clock de Fosc/64.

   PWM1_Init(5000);      // Inicializa módulo PWM com 5Khz
   PWM1_Start();         // Start PWM
   while(1){   // Aqui Definimos Uma Condição Sempre Verdadeira Como Parametro, Portanto Todo O Bloco Será Repetido Indefinidamente.

      uiValorAD= ADC_Read(0);     // Lê Canal AD 0
      uiValorAD*=0.24;            // Converte valor para o duty cycle
      PWM1_Set_Duty(uiValorAD);   // Envia o valor lido de "uiValorAD" para o módulo CCP1 pwm
      Delay_10us;
   }
}
