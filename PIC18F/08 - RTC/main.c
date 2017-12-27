/*
               Microgenios Soluções Eletrônicas Ltda.

********************************************************************************
 PROGRAMA EXEMPLO: RTC.
         OBJETIVO: Aprender a utilizar o RTC para leitura de Datas e Hora.
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
 |SCK      ( 6) = ON   |RESIS    ( 6) = OFF   |
 |SDA      ( 7) = ON   |TEMP     ( 7) = OFF   |
 |RTC      ( 8) = ON   |VENT     ( 8) = OFF   |
 |LED1     ( 9) = OFF  |AN0      ( 9) = OFF   |
 |LED2     (10) = OFF  |AN1      (10) = OFF   |
  --------------------- ----------------------
********************************************************************************
OBS:
- HABILITAR BIBLIOTECA LCD.
- HABILITAR BIBLIOTECA I2C.
********************************************************************************
*/

//VARIAVEIS GLOBAIS
unsigned char ucHora;       // Armazena Hora.
unsigned char ucMinuto;     // Armazena Minuto.
unsigned char ucSegundo;    // Armazena Segundo.
unsigned char ucDia;        // Armazena Dia.
unsigned char ucMes;        // Armazena Mes.
unsigned char ucAno;        // Armazena Ano.
unsigned char ucDia_Semana; // Armazena Dia da Semana.

char *ucTexto;              // Ponteiro para leitura de strings.

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

// Prototipos de função.
void Display_LCD();
void Encontra_Dia_Semana();
void Grava_RTC();
void Leitura_RTC();
void Converte_BCD(unsigned char ucLinha, unsigned char ucColuna,unsigned char ucValor);

void main(){
   TRISA = 0;                                // Define PORTA como saida
   TRISB = 0;                                // Define PORTB como saida
   TRISC = 0;                                // Define PORTC como saida
   TRISD = 0;                                // Define PORTD como saida
   TRISE = 0;                                // Define PORTE como saida
   
   ADCON1= 0x0F;                             // Torna todos os pinos A/D como I/O de uso geral
   CMCON = 0X07;                             // Desliga os comparadores.

   // Config. LCD no modo 4 bits
   Lcd_Init();                               // Inicializa LCD.
   
   Lcd_Cmd(_LCD_CLEAR);                      // Apaga display
   Lcd_Cmd(_LCD_CURSOR_OFF);                 // Desliga cursor
   Grava_RTC();

   while(1){
     Display_LCD();  // Escreve no display lcd o valor
     Leitura_RTC();  // Efetua leitura de segundo, minuto e horas do DS1307
     Delay_ms(200);  // Delay de 200 milisegundos
   }
}

// Rotina de conversão de dados para BCD
void Converte_BCD(unsigned char ucLinha, unsigned char ucColuna,unsigned char ucValor) {
  unsigned char ucValor1, ucValor2;

  ucValor1 = (ucValor >> 4  ) + '0';    // Converte o primeiro nibble em BCD e após em string
  Lcd_Chr(ucLinha,ucColuna,ucValor1);   // Escreve caractere no LCD
  ucValor2 = (ucValor & 0x0F) + '0';    // Converte o segundo nibble em BCD e após isso, em string
  Lcd_Chr_CP(ucValor2);                 // Escreve caractere no LCD
}

void Leitura_RTC() {          // Rotina de leitura do DS1307
   I2C1_Start();              // Inicializa comunicação i2c
   I2C1_Wr(0xD0);             // End. fixo para DS1307: 1101000X, onde x = 0 é para gravação
   I2C1_Wr(0);                // End. onde começa a programação do relógio, end dos segundos.
   I2C1_Repeated_Start();     // Issue I2C signal repeated start
   I2C1_Wr(0xD1);             // End. fixo para DS1307: 1101000X, onde x=1 é para leitura
   ucSegundo = I2C1_Rd(1);    // Lê o primeiro byte(segundos),informa que continua lendo
   ucMinuto = I2C1_Rd(1);     // Lê o segundo byte(minutos)
   ucHora = I2C1_Rd(1);       // Lê o terceiro byte(horas)
   ucDia_Semana = I2C1_Rd(1);
   ucDia = I2C1_Rd(1);
   ucMes = I2C1_Rd(1);
   ucAno = I2C1_Rd(0);        // Lê o sétimo byte(ano),encerra as leituras de dados
   I2C1_Stop();               // Finaliza comunicação I2C
}

void Grava_RTC(){
   I2C1_Init(100000);     // Iniciliza I2C com frequencia de 100KHz
   I2C1_Start();          // Inicializa a comunicação I2c
   I2C1_Wr(0xD0);         // End. fixo para DS1307: 1101000X, onde x = 0 é para gravação
   I2C1_Wr(0);            // End. onde começa a programação do relógio, end. dos segundos.
   I2C1_Wr(0x00);         // Inicializa com 00 segundos.
   I2C1_Wr(0x34);         // Inicializa com 34 minutos.
   I2C1_Wr(0x16);         // Inicializa com 16:00hs (formato 24 horas).
   I2C1_Wr(0x03);         // Inicializa com terça
   I2C1_Wr(0x13);         // Inicializa com dia 13
   I2C1_Wr(0x06);         // Inicializa com mês 06
   I2C1_Wr(0x17);         // Inicializa com ano 17
   I2C1_Stop();           // Finaliza comunicação I2C
}

void Encontra_Dia_Semana() {
   switch (ucDia_Semana) {
      case 01: ucTexto = "DOMINGO"; break; // Caso dias_semana = 01 então..
      case 02: ucTexto = "SEGUNDA"; break; // Caso dias_semana = 02 então..
      case 03: ucTexto = "TERCA";   break; // Caso dias_semana = 03 então..
      case 04: ucTexto = "QUARTA";  break; // Caso dias_semana = 04 então..
      case 05: ucTexto = "QUINTA";  break; // Caso dias_semana = 05 então..
      case 06: ucTexto = "SEXTA";   break; // Caso dias_semana = 06 então..
      default: ucTexto = "SABADO";         // Se não for nenhum desses então...
   }
}

void Display_LCD() {
   Lcd_Out(1,1,"(Hora)");
   Converte_BCD(1,7,ucHora);     // Conversão da variável horas para BCD
   Lcd_Chr_CP(':');              // Escreve no display LCD
   Converte_BCD(1,10,ucMinuto);  // Conversão da variável minuto para BCD
   Lcd_Chr_CP(':');              // Escreve no display LCD
   Converte_BCD(1,13,ucSegundo); // Conversão da variável segundo para BCD
   Lcd_Out(2,1,"(Data)");
   Converte_BCD(2,7,ucDia);      // Conversão da variável dia para BCD
   Lcd_Chr_CP('/');              // Escreve no display LCD
   Converte_BCD(2,10,ucMes);     // Conversão da variável mes para BCD
   Lcd_Chr_CP('/');              // Escreve no display LCD
   Converte_BCD(2,13,ucAno);     // Conversão da variável ano para BCD
   Encontra_Dia_Semana();
   Lcd_Out(2,1,ucTexto);         // Mostra dia da semana
}