/*
               Microgenios Soluções Eletrônicas Ltda.

********************************************************************************
 PROGRAMA EXEMPLO: Mostrar contador de 0 a 9999 nos displays de LCD em 8 bits.
         OBJETIVO: Aprender a utilizar LCD alfanumerico em configuração de 8 bits.
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
 |SCK      ( 6) = OFF  |RESIS    ( 6) = OFF   |
 |SDA      ( 7) = OFF  |TEMP     ( 7) = OFF   |
 |RTC      ( 8) = OFF  |VENT     ( 8) = OFF   |
 |LED1     ( 9) = OFF  |AN0      ( 9) = OFF   |
 |LED2     (10) = OFF  |AN1      (10) = OFF   |
*  --------------------- ----------------------
********************************************************************************
*/

sbit LCD_RS at RE2_bit;
sbit LCD_EN at RE1_bit;
sbit LCD_D7 at RD7_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D4 at RD4_bit;
sbit LCD_D3 at RD3_bit;
sbit LCD_D2 at RD2_bit;
sbit LCD_D1 at RD1_bit;
sbit LCD_D0 at RD0_bit;

sbit LCD_RS_Direction at TRISE2_bit;
sbit LCD_EN_Direction at TRISE1_bit;
sbit LCD_D7_Direction at TRISD7_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D4_Direction at TRISD4_bit;
sbit LCD_D3_Direction at TRISD3_bit;
sbit LCD_D2_Direction at TRISD2_bit;
sbit LCD_D1_Direction at TRISD1_bit;
sbit LCD_D0_Direction at TRISD0_bit;

int cont = 0;
char impressao[10];

void main(){
     adcon1 = 0x0f;
     TRISB.RB3=1;                  // Define o pino RB3 do PORTB como entrada.
     TRISB.RB4=1;                  // Define o pino RB4 do PORTB como entrada.
     Lcd_Init();
     Lcd_Cmd(_LCD_CLEAR);               // Clear display
     Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
     Lcd_Out(1,1,"Contador");
     while(1){
           if(Button(&PORTB, 3, 100, 0) && cont < 9999){       // Enquanto o pino PORTB.RB0 estiver pressionado (igual a 0) , será executado o laço do while.
               cont++;
           }
           if(Button(&PORTB, 4, 100, 0) && cont>0){       // Enquanto o pino PORTB.RB0 estiver pressionado (igual a 0) , será executado o laço do while.
               cont--;
           }
           IntToStrWithZeros(cont,impressao);
           Lcd_Out(2,-1,impressao);
     }
}