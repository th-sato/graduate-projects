/*
               Microgenios Soluções Eletrônicas Ltda.

********************************************************************************
 PROGRAMA EXEMPLO: Leitura do teclado matricial e mostrar a representação nos
                   displays de 7 segmentos.
         OBJETIVO: Aprender a utilizar varredura de port´s do pic para leitura
                   de teclado matricial e escrita nos displays de 7 segmentos.
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
 |GLCD\LCD ( 1) = OFF  |DIS1     ( 1) = ON    |
 |RX       ( 2) = OFF  |DIS2     ( 2) = ON    |
 |TX       ( 3) = OFF  |DIS3     ( 3) = ON    |
 |REL1     ( 4) = OFF  |DIS4     ( 4) = ON    |
 |REL2     ( 5) = OFF  |INFR     ( 5) = OFF   |
 |SCK      ( 6) = OFF  |RESIS    ( 6) = OFF   |
 |SDA      ( 7) = OFF  |TEMP     ( 7) = OFF   |
 |RTC      ( 8) = OFF  |VENT     ( 8) = OFF   |
 |LED1     ( 9) = OFF  |AN0      ( 9) = OFF   |
 |LED2     (10) = OFF  |AN1      (10) = OFF   |
  --------------------- ----------------------
********************************************************************************
*/

void main(){
                          //  "0"  "1"  "2"  "3"  "4"  "5"  "6"  "7"  "8"  "9"  "<"  ">"  "-"
   unsigned char ucMask[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x21,0x03,0x40};
   /* Variavel Do Tipo Matriz Que Armazena Os Valores Correspondentes Ao Numero
   Para Ser Mostrado No Display De 7 Segmentos */

   unsigned char ucConverter[] = {12,10,7,4,1,0,8,5,2,11,9,6,3};
   /* Variavel para conversão do que foi lido pelo teclado para formatação do
   teclado */

   unsigned char ucTecla;       // Armazena Tecla Lida De Cada Coluna.
   unsigned int  uiTeclas;      // Armazena Todas As Teclas Lidas.
   unsigned int  uiValor;       // Variavel Auxiliar Para Mostrar No Display.
   unsigned char ucContador;    // Variavel Auxiliar Para Contador.

   ADCON1 = 0x0f;      // Configura Todos Os Pinos A/D Como I/O

   TRISB.RB0=0;        // Define o pino RB0 do PORTB como saida(Coluna1).
   TRISB.RB1=0;        // Define o pino RB1 do PORTB como saida(Coluna2).
   TRISB.RB2=0;        // Define o pino RB2 do PORTB como saida(Coluna3).

   TRISA.RA2=0;        // Define O Pino RA2 Do PORTA Como Saida(Seleção Display 1).
   TRISA.RA3=0;        // Define O Pino RA3 Do PORTA Como Saida(Seleção Display 2).
   TRISA.RA4=0;        // Define O Pino RA4 Do PORTA Como Saida(Seleção Display 3).
   TRISA.RA5=0;        // Define O Pino RA5 Do PORTA Como Saida(Seleção Display 4).

   TRISD = 0;          // Define Todos Os Pinos Do PORTD Como Saida.

   while(1){   // Aqui Definimos Uma Condição Sempre Verdadeira Como Parametro, Portanto Todo O Bloco Será Repetido Indefinidamente.
      TRISD=0x0F;      // Define Todos Os Pinos De 0 A 3 Do PORTD Como Entrada E Pinos De 4 A 7 Do PORTD Como Saida.
      PORTB.RB0=0;     // Liga Coluna 1
      Delay_ms(1);     // Aguarda 1ms Para Fazer A Leitura Das Teclas.
      ucTecla = (((~PORTD)&0x0F)); // Com O Operador Lógico Bit A Bit "&", Podemos Ler Somente Os Pinos Que Nos Interessam, No Caso Os Pinos De RD0 A RD3
      PORTB.RB0=1;     // Desliga Coluna 1
      uiTeclas = (unsigned int)(ucTecla&0x0F);

      PORTB.RB1=0;
      Delay_ms(1);
      ucTecla = (((~PORTD)&0x0F));
      PORTB.RB1=1;
      uiTeclas |= (unsigned int)((ucTecla&0x0F)<<4);

      PORTB.RB2=0;
      Delay_ms(1);
      ucTecla = (((~PORTD)&0x0F));
      PORTB.RB2=1;
      uiTeclas |= (unsigned int)((ucTecla&0x0F)<<8);
      uiValor=0;
      // Procurar Qual Tecla Foi Pressionada.
      for (ucContador=0;ucContador<=12;ucContador++)
      {
          if ((unsigned int)(1<<ucContador)==uiTeclas)      // (1<<Variavel) Igual A 2 Elevado A Um Expoente
          {
             uiValor = (unsigned int) ucContador + 1 ;      // Coloca O Conteudo Da Variavel Do Contador Na Varaivel Auxiliar.
          }
      }

      TRISD=0;                                   // Define Todos Os Pinos Do PORTD Como Saida.

      // Mostra Valor Da Unidade
      PORTD = ucMask[ucConverter[uiValor]];      // Mostra caractere correspondente
      PORTA.RA5 = 1;                             // Liga O Transistor Associado Ao Display 1.
      Delay_ms(2);                               // Delay Para Escrita No Display.
      PORTA.RA5 = 0;                             // Desliga O Transistor Associado Ao Display 1.
   }
}
