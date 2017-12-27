/*
               Microgenios Soluções Eletrônicas Ltda.

********************************************************************************
 PROGRAMA EXEMPLO: Escrita e Leitura da EEPROM externa 24C04.
         OBJETIVO: Aprender a utilizar a EEPROM externa 24C04.
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
 |REL2     ( 5) = OFF  |INFR     ( 5) = ON    |
 |SCK      ( 6) = ON   |RESIS    ( 6) = OFF   |
 |SDA      ( 7) = ON   |TEMP     ( 7) = OFF   |
 |RTC      ( 8) = OFF  |VENT     ( 8) = OFF   |
 |LED1     ( 9) = OFF  |AN0      ( 9) = OFF   |
 |LED2     (10) = OFF  |AN1      (10) = OFF   |
  --------------------- ----------------------
********************************************************************************
OBS:
- HABILITAR BIBLIOTECA LCD.
- HABILITAR BIBLIOTECA I2C.
********************************************************************************
*/

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

unsigned char ucContador;    // Auxiliar para contagem.
unsigned char i;

// Prototipos de função
void Escrita_24C04(unsigned char ucEndereco,unsigned char ucValor);
unsigned char Leitura_24C04(unsigned char ucEndereco);

void interrupt(){               // Palavra "interrupt" sempre em minuscula.
    // Incrementa Contador.
    if(INTCON.TMR0IF==1){       // Incrementa somente quando existir o overflow do timer 0.
       // Recarrega o timer0.
       TMR0H = 0xDB;           // Carrega o valor alto do número 57723.
       TMR0L = 0x61;            // Carrega o valor baixo do numero 57723.
       INTCON.TMR0IF = 0;       // Limpa o flag de estouro do timer0 para uma nova contagem de tempo.
       ucContador++;
    }
}


void main(){
   TRISB = 0;                        // Define PORTB como saida.
   TRISD = 0;                        // Define PORTD como saida.
   TRISE = 0;                        // Define PORTE como saida.

   ADCON1 = 0x0F;                    // Configura todos canais como Digital.

   // Configuração do Timer0.
                            // Cristal de 8Mhz, ciclo de máquina: 8MHz / 4 = 2Mhz --> 1/2Mhz = 0,5us.
   T0CON.T0CS = 0;          // Timer0 operando como temporizador.
   T0CON.PSA = 0;           // Prescaler ativado.
   T0CON.T0PS2 = 1;         // Define prescaler 1:128.
   T0CON.T0PS1 = 1;         // Define prescaler 1:128.
   T0CON.T0PS0 = 0;         // Define prescaler 1:128.
   T0CON.T08BIT = 0;        // Define contagem no modo 16 bits.
   // Valor para 1 segundo.
   TMR0H = 0xDB;            // Carrega o valor alto do número 56161.
   TMR0L = 0x61;            // Carrega o valor baixo do numero 56161.
   INTCON.TMR0IE = 1;       // Habilita interrupção do timer0.
   INTCON.TMR0IF = 0;       // Apaga flag de estouro do timer0, pois é fundamental para a sinalização do estouro.
   T0CON.TMR0ON = 1;        // Liga timer0.
   INTCON.GIE = 1;          // Habilita as interrupções não-mascaradas.
   INTCON.PEIE = 1;         // Habilita as interrupções dos perifericos.

   // Config. LCD no modo 4 bits
   Lcd_Init();                               // Inicializa LCD.

   Lcd_Cmd(_LCD_CLEAR);                      // Apaga display.
   Lcd_Cmd(_LCD_CURSOR_OFF);                 // Desliga cursor.
   Lcd_Out(1,1,"Escr. na 24C04");      // Mostra o estado no LCD.
   ucContador = 0;
   while(1){
      if(INTCON.TMR0IF ==1 && ucContador < 16){
         Escrita_24C04(ucContador,0x30+ucContador);   // Grava na EEPROM valores de 0 a 10 em ASCII.
      }
      if(ucContador == 16){
         Lcd_Cmd(_LCD_CLEAR);                      // Apaga display.
         Lcd_Cmd(_LCD_CURSOR_OFF);                 // Desliga cursor.
         Lcd_Out(1,1,"Lido da 24C04 ");      // Mostra o estado no LCD.
         for(i=0;i<ucContador;i++){
             Lcd_Chr(2,i+1,Leitura_24C04(i));      // Le na EEPROM valores .
         }
      }
   };
}

// Função que escreve na memória 24C04
void Escrita_24C04(unsigned char ucEndereco,unsigned char ucValor)
{
  I2C1_Init(100000);             // Freqüência de clock
  I2C1_Start();                  // Start no barramento i2c
  I2C1_Wr(0xA0);                 // Endereço da memória no hardware do kit (w = 0): identificação do componente
  I2C1_Wr(ucEndereco);           // Endereço da eeprom onde será salvo o dado
  I2C1_Wr(ucValor);              // Escreve valor da variável 'ucValor' na 24c04
  I2C1_Stop();                   // Finaliza a comunicação I2C

}
// Função que faz a leitura da memória 24C04
unsigned char Leitura_24C04(unsigned char ucEndereco)
{
   unsigned char ucLeitura;      // Temporario para leitura da memória 24C04.

   I2C1_Start();                 // start no barramento i2c
   I2C1_Wr(0xA0);                // endereço da memória no hardware do kit (w = 0)
   I2C1_Wr(ucEndereco);          // endereço da eeprom onde será lido o byte
   I2C1_Repeated_Start();        // re-start no barramento
   I2C1_Wr(0xA1);                // endereço da memória no hardware do kit (w = 1)
   ucLeitura = I2C1_Rd(0u);      // Lê o byte
   I2C1_Stop();                  // finaliza a comunicação I2C
   return(ucLeitura);            // Retorna Valor da leitura.
}