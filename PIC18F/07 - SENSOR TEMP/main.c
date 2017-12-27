/*
               Microgenios Soluções Eletrônicas Ltda.

********************************************************************************
 PROGRAMA EXEMPLO: Leitura do canal A/D AN2 para ler temperatura através do lm35
                   e usar o CUSTOM CHAR para mostrar o simbolo de graus.
         OBJETIVO: Aprender a ler temperatura e usar o CUSTOM CHAR.
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
 |GLCD\LCD ( 1) = ON   |DIS1     ( 1) = OFF   |
 |RX       ( 2) = OFF  |DIS2     ( 2) = OFF   |
 |TX       ( 3) = OFF  |DIS3     ( 3) = OFF   |
 |REL1     ( 4) = OFF  |DIS4     ( 4) = OFF   |
 |REL2     ( 5) = OFF  |INFR     ( 5) = OFF   |
 |SCK      ( 6) = OFF  |RESIS    ( 6) = ON    |
 |SDA      ( 7) = OFF  |TEMP     ( 7) = ON    |
 |RTC      ( 8) = OFF  |VENT     ( 8) = OFF   |
 |LED1     ( 9) = OFF  |AN0      ( 9) = OFF   |
 |LED2     (10) = OFF  |AN1      (10) = OFF   |
  --------------------- ----------------------
********************************************************************************
OBS:
- HABILITAR BIBLIOTECA LCD.
- HABILITAR BIBLIOTECA A/D.
- HABILITAR BIBLIOTECA CONVERTIONS.

- JUMPER LIGADO DO BUZZER.
********************************************************************************
*/

// VARIAVEIS GLOBAIS
unsigned char ucTexto[10];   // Matriz para armazenamento de texto.
unsigned int iLeituraAD = 0; // Define variável para armazenamento da leitura AD.
// PROTOTIPOS DE FUNÇÃO
void GRAUS();

// CONFIGURAÇÃO DOS PINOS DO LCD.
sbit LCD_RS at RE2_bit;
sbit LCD_EN at RE1_bit;
sbit LCD_D7 at RD7_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D4 at RD4_bit;

// DIREÇÃO DOS PINOS.
sbit LCD_RS_Direction at TRISE2_bit;
sbit LCD_EN_Direction at TRISE1_bit;
sbit LCD_D7_Direction at TRISD7_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D4_Direction at TRISD4_bit;

void main(){
   TRISB = 0;                        // Define PORTB como saida.
   TRISD = 0;                        // Define PORTD como saida.
   TRISC.RC5 = 0;                    // Define PORTC.RC5 como saida.
   TRISC.RC1 = 0;                    // Define PORTC.RC1 como saida.
   TRISE = 0;                        // Define PORTE como saida.
   PORTB = 0;                        // Limpa PORTB.


   ADCON0 = 0b00000001;              // Configura conversor A/D Canal 0, conversão desligada, A/D ligado.
   ADCON1 = 0b00001100;              // Configura todos canais como Digital menos AN0,AN1 E AN2 e REF Interna.
   ADCON2 = 0b10111110;              // Configura conversor A/D para resultado justificado a direita, clock de 20 TAD, clock de Fosc/64.

   // Config. LCD no modo 4 bits
   Lcd_Init();                               // Inicializa LCD.

   Lcd_Cmd(_LCD_CLEAR);                      // Apaga display.
   Lcd_Cmd(_LCD_CURSOR_OFF);                 // Desliga cursor.
   Lcd_Out(1, 1, "TEMP: ");                  // Escreve mensagem no LCD.
   PORTC.RC5 = 1;                            // Liga resistencia de aquecimento.
   GRAUS();                                  // Armazena simbolo de graus.
   while(1){   // Aqui Definimos Uma Condição Sempre Verdadeira Como Parametro, Portanto Todo O Bloco Será Repetido Indefinidamente.
      iLeituraAD= ADC_Read(2);          // Lê Canal AD 2
      iLeituraAD/=2;                    // Converte valor do sensor LM35
      WordToStr(iLeituraAD, ucTexto);   // Converte o valor lido no A/D em string
      Lcd_Out(1,8,ucTexto);             // Imprime no LCD o valor do Duty Cycle.
      Lcd_Chr_CP(0);                    // Imprime simbolo de graus.
      Lcd_Chr_CP('C');                  // Unidade.
      Delay_ms(100);                    // Delay de 0,1 segundo.
      PORTC.RC1 = ~PORTC.RC1;           // Alterna som do buzzer.
   }
}

void GRAUS() {
  char i;
  const char character[] = {7,5,7,0,0,0,0,0};   // ARMAZENA SIMBOLO DE GRAUS.
    Lcd_Cmd(64);
    for (i = 0; i<=7; i++) Lcd_Chr_CP(character[i]);
}
