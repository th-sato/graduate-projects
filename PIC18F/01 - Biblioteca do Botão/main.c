/*
               Microgenios Soluções Eletrônicas Ltda.

********************************************************************************
 PROGRAMA EXEMPLO: Pisca-Pisca no PORTD.
         OBJETIVO: Aprender a utilizar o PORTD do PIC como saida e o pino RB0
                   do PORTB como entrada.
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
 |RTC      ( 8) = OFF  |VENT     ( 8) = OFF   |
 |LED1     ( 9) = ON   |AN0      ( 9) = OFF   |
 |LED2     (10) = OFF  |AN1      (10) = OFF   |
  --------------------- ----------------------
********************************************************************************
*/

void main(){
   TRISB.RB0=1;                  // Define o pino RB0 do PORTB como entrada.
   TRISD=0;                      // Define todos os pinos do PORTD como saída.
   while(1){                     // Aqui definimos uma condição sempre verdadeira como parametro, portanto todo o bloco será repetido indefinidamente.
      while(Button(&PORTB, 0, 100, 0)){       // Enquanto o pino PORTB.RB0 estiver pressionado (igual a 0) , será executado o laço do while.
         PORTD=0;                // Todos os pinos do PORTD em 0.
         Delay_ms(1000);         // Esta função é interna do compilador, portanto o tempo é de 1000ms ou 1 segundo.
         PORTD=255;              // Todos os pinos do PORTD em 1.
         Delay_ms(1000);         // Aguarda novamente 1 segundo.
      }
   }
}