/*******************************************************************************
RESUMO:
Este projeto realiza o controle de temperatura; para isto, é necessário que o
usuário esteja logado.
Ao iniciar o PIC18F4520, o usuário deve inserir uma senha (de 4 dígitos) para
que possa alterar a temperatura posteriormente. A inserção da senha é realizada
somente com números, sendo que o primeiro dígito deve ser diferente de zero. Para
a definição da senha, utiliza-se 4 botões do PORTB: RB0 (decrementar o valor),
RB1 (incrementar o valor), RB3 (inserir o valor), RB4 (apagar/voltar o valor).
Após inserida a senha, a senha não poderá ser alterada, somente reiniciando o
PIC18F4520. Com a senha definida, será apresentado ao usuário um menu que
apresenta as seguintes opções:
* Logar
* Ler temperatura e rotação da ventoinha
* Temperaturas anteriores
Este menu (mostrado no display LCD) é controlado por um trimpot (AN0). O usuário
pode selecionar a opção do menu e confirmar com o botão RB2. Selecionado a opção
de logar, o usuário deve inserir a mesma senha que a definida no início do
programa.
Agora com o usuário logado, este possui as seguintes opções no menu:
* Deslogar
* Ler temperatura e rotação da ventoinha
* Temperaturas anteriores
* Alterar a temperatura
A opção de "ler temperatura e rotação da ventoinha" apresenta os valores lidos
no LCD, estes dados são obtidos, respectivamente, pelo sensor de temperatura
e pelo infravermelho.
A opção "temperaturas anteriores" apresenta os valores de temperaturas lidos
até o momento, estes valores são guardados na EEPROM a cada 12 segundos
(controlado pelo TIMER0). Caso seja pressionado o botão:
* PORTB.RB1: será incrementado a posição lida.
* PORTB.RB0: será decrementado a posição lida.
A opção "alterar temperatura" é utilizada para alterar a temperatura desejada
pelo usuário, este valor é apresentado no display de 7 segmentos e é controlado
por outro trimpot (AN1). Caso a temperatura definida seja menor que a
temperatura atual, o projeto irá desligar a resistência de aquecimento (se estiver
ligada) e ligará a ventoinha com o objetivo de diminuir a temperatura. Caso a
temperatura definida seja maior que a temperatura atual, será desligada a
ventoinha e resistência de aquecimento será ligada.

RECURSOS UTILIZADOS:
* DISPLAY LCD
* DISPLAY 7 SEGMENTOS
* EEPROM INTERNA
* TRIMPOTS
* MODULO TIMER0 (COM INTERRUPÇÃO)
* SENSOR DE TEMPERATURA + RESISTÊNCIA PARA AQUECIMENTO
* PWM + VENTOINHA + INFRAVERMELHO + TIMER1
************************* Configurações do KIT Picgenios ***********************
 CRISTAL: 8Mhz.
 CHAVES DE FUNÇÃO:
  --------------------- ----------------------
 |GLCD\LCD ( 1) = ON   |DIS1     ( 1) = OFF   |
 |RX       ( 2) = OFF  |DIS2     ( 2) = OFF   |
 |TX       ( 3) = OFF  |DIS3     ( 3) = ON    |
 |REL1     ( 4) = OFF  |DIS4     ( 4) = ON    |
 |REL2     ( 5) = OFF  |INFR     ( 5) = ON    |
 |SCK      ( 6) = OFF  |RESIS    ( 6) = ON    |
 |SDA      ( 7) = OFF  |TEMP     ( 7) = ON    |
 |RTC      ( 8) = OFF  |VENT     ( 8) = ON    |
 |LED1     ( 9) = OFF  |AN0      ( 9) = ON    |
 |LED2     (10) = OFF  |AN1      (10) = ON    |
  --------------------- ----------------------
********************************************************************************
OBS:
- HABILITAR AS SEGUINTES BIBLIOTECAS:
ADC, BUTTON, CONVERSIONS, C_STRING, EEPROM, LCD, PWM
********************************************************************************/

#define tamSenha 4                              //4 dígitos para a senha
sbit LCD_RS at RE2_bit;
sbit LCD_EN at RE1_bit;
sbit LCD_D7 at RD7_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D4 at RD4_bit;

sbit LCD_RS_Direction at TRISE2_bit;
sbit LCD_EN_Direction at TRISE1_bit;
sbit LCD_D7_Direction at TRISD7_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D4_Direction at TRISD4_bit;

// Variáveis Globais
int i;                                          // Controla a quantidade de dígitos já inseridos para senha/login
int cont;                                       // Guarda o valor que será guardado no vetor de senha/login
int gravarEEPROM;                               // Controla quando será escrito na EEPROM
int ultimaTemperatura;                          // Guarda a última temperatura lida
unsigned char posWriteEEPROM;                   // Guarda a posição para escrita na EEPROM
int senha[tamSenha];                            // Guarda a senha definida pelo usuário
int login[tamSenha];                            // Guarda os valores inseridos para login
int temperaturaDefinida;                        // Guarda a temperatura definida pelo usuário
int PWM;                                        // Guarda o valor para o PWM
unsigned int iReg_timer1;                       // Armazena o RPM.
unsigned char mensagem[10];                     // Vetor para armazenamento de texto: utilizado para mostrar a temperatura e a rotação
char impressao[12];                             // Vetor para armazenamento de texto: utilizado para mostrar a senha e a temperatura

// Rotinas Auxiliares
void inicializarVetor(int v[]){ //Inicializa o vetor com (-1) em todos as posições
     int j;
     for(j=0; j<tamSenha; j++){
         v[j] = -1;
     }
}

//A biblioteca de potência não é precisa.
int potencia(int a, int b){ //Realiza a operação de potência de dois números
    int c = 0, resultado = 1;
    while(c<b){
        resultado = resultado*a;
        c++;
    }
    return resultado;
}

void imprimirSenha(int vetor[]){ //Imprime a senha que está sendo inserida
     int aux = 0, j;
     for(j=0; j<i; j++){
         aux += vetor[j]*potencia(10, i-j);
        //De acordo com a posição no vetor de senha, multiplica-se pela potência referente a sua posição
        //e soma com o valor anterior para apresentar o valor no LCD.
     }
     aux += cont; //Incrementa com o valor que está sendo digitado
     IntToStr(aux,impressao);
     Lcd_Out(2,1,impressao); //Imprimi o valor
}

void definirValoresVetor(char *msg, int vetor[]){ //Define os valores do vetor de acordo com a variável cont
   Lcd_Out(1,1,msg);
   if(Button(&PORTB, 1, 100, 0) && cont < 9){ //Incrementa o valor
       cont++;
   } else if (Button(&PORTB, 0, 100, 0) && cont > 0){ //Decrementa o valor
       if(i==0){
           if(cont > 1) cont--;
       }
       else cont--;
   } else if (Button(&PORTB, 3, 100, 0)){ //Inserir valor
       vetor[i] = cont;
       i++;
       cont = 0;
   } else if (Button(&PORTB, 4, 100, 0)){ //Apagar/voltar valor
       if(i>0) i--;
       vetor[i] = -1;
       if(i==0) cont = 1;
       else cont = 0;
   }
}

int conferirSenhaELogin(){ //Verifica se o valor digitado para login é o mesmo que o da senha
    int j;
    for(j=0; j<tamSenha; j++){
        if(senha[j] != login[j])
            return -1; //Retorna (-1) se não for igual
    }
    return 1; //Retorna 1 se for igual
}

void logar(){
   int conferirLogin = 1; //Variável de controle para login
   i = 0; //Indica que a quantidade de dígitos inseridos para senha/login é zero
   cont = 1; //Inicia o valor digitado para inserção no vetor como 1
   Lcd_Cmd(_LCD_CLEAR); //Apagar o LCD
   while(conferirLogin == 1){ //Enquanto não acertar o login, irá pedir para inserir a senha
       definirValoresVetor("Login:", &login);
       if(i>=tamSenha){ //Após inserido todos os dígitos, confere a senha
           if(conferirSenhaELogin()==1){ //Se estiver certo, sai do loop
               conferirLogin = 0;
               Lcd_Out(1,1,"Senha correta");
               Delay_ms(500);
               Lcd_Cmd(_LCD_CLEAR);
           } else{ //Senão continua com a inserção da senha
               i = 0;
               cont = 1;
               Lcd_Out(1,1,"Senha incorreta");
               Lcd_Out(2,1,"Tente novamente");
               Delay_ms(500);
               Lcd_Cmd(_LCD_CLEAR);
           }
       } else imprimirSenha(&login); //Imprime os valores que já foram digitados
   }
}

void definirTemperatura(){
    //Vetor que armazena os valores correspondentes ao número para ser mostrado no display de 7 segmentos
                           //  "0"  "1"  "2"  "3"  "4"  "5"  "6"  "7"  "8"  "9"
    unsigned char ucMask[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
    temperaturaDefinida = ADC_Read(1); //Le o valor do AN1 (trimpot)
    temperaturaDefinida *= 0.068; // 69/1023 = 0,068
    //Unidade
    PORTD = ucMask[temperaturaDefinida%10];  // Pega modulo (resto) da divisão por 10 e coloca o valor no PORTD.
    PORTA.RA5 = 1;                           // Liga o transistor associado ao display 1.
    Delay_ms(2);                             // Delay para escrita no display.
    PORTA.RA5 = 0;                           // Desliga o transistor associado ao display 1.
    //Dezena
    PORTD = ucMask[temperaturaDefinida/10];
    PORTA.RA4 = 1;
    Delay_ms(2);
    PORTA.RA4 = 0;
}

void mostrarTemperatura(){
    unsigned int leituraAD;
    leituraAD = ADC_Read(2);                  // Lê Canal AD 2
    leituraAD/=2;                             // Converte valor do sensor LM35
    WordToStr(leituraAD, mensagem);           // Converte o valor lido no A/D em string
    strcpy(mensagem,strcat(mensagem, "C"));
    Lcd_Out(1,1,"Temp.:");
    Lcd_Out(1,8,mensagem);
}

void mostrarRotacao(){
     WordToStr(iReg_timer1, mensagem);  // Converte o valor lido no iReg_timer1 em string
     Lcd_Out(2,1,mensagem);             // Imprime no LCD o valor da RPM.
     Lcd_Out_CP("RPM");                 // Unidade "RPM".
     Delay_10us;
}

void funcGravarEEPROM(){ //Gravar na EEPROM, a última temperatura lida
     EEPROM_Write(posWriteEEPROM,0x30+ultimaTemperatura/10);   // Grava a dezena
     posWriteEEPROM++;
     EEPROM_Write(posWriteEEPROM,0x30+ultimaTemperatura%10);   // Grava a unidade
     posWriteEEPROM++;
}

void leituraTemperatura(int posRead){ //De acordo com a posição, imprime o valor da temperatura armazenada
    if(posWriteEEPROM!=0){ //Imprime a temperatura
        Lcd_Out(1,1,"Temperaturas");
        IntToStr(posRead/2+1,impressao);
        Lcd_Out(2,-3,impressao);                //Imprime qual a posição da temperatura lida
        Lcd_Chr(2,5,EEPROM_Read(posRead));      //Imprime a dezena
        Lcd_Chr(2,6,EEPROM_Read(posRead+1));    //Imprime a unidade
        Lcd_Out_CP("C");
    }
    else Lcd_Out(1,1,"Sem valores"); //Imprime a mensagem, indicando que não há temperaturas lidas até o momento
}

void controlarTemperatura(){ //Controla a temperatura de acordo com a temperatura definida
    unsigned int leituraAD;
    leituraAD = ADC_Read(2);          // Lê Canal AD 2
    leituraAD/=2;                     // Converte valor do sensor LM35
    ultimaTemperatura = leituraAD;    // Guarda a última temperatura lida
    if(temperaturaDefinida > leituraAD){ 
        PORTC.RC5 = 1; //Liga a resistência de aquecimento
        PWM = 0; //Define o valor do PWM como zero
    }
    else{
        PORTC.RC5 = 0; //Desliga a resistência de aquecimento
        if(PWM < 255) PWM++; //Incrementa o valor do PWM
    }
    PWM1_Set_Duty(PWM); //Define a potência da ventoinha de acordo com o PWM
}

void interrupt(){
   if (INTCON.TMR0IF == 1){          // Se o flag de estouro do TIMER0 for igual a 1, então
      TMR0L = 0X7B;                  // Carrega valores de contagem
      TMR0H = 0XE1;                  // Carrega valores de contagem
      INTCON.TMR0IF = 0;             // Apaga flag de entouro do TIMER0
      iReg_timer1 = TMR1L*(60/9);    // Pega valor lido do timer1 e multiplica por 60 para saber rotação por minuto.
                                     // e divide por 9 pois a ventoinha para dar uma volta completa realiza 9 pulsos.
      TMR1L = 0;                     // Limpa contador.
      gravarEEPROM++;                // Incrementa o valor para escrita na EEPROM
   }
}

//Rotina Principal
void main(){
     int logado;            //Verifica se está logado
     int inserirSenha;      //Indica quando deve-se inserir a senha
     int menu;              //Guarda a posição do menu
     int leituraTemp;       //Variável auxiliar para diferentes situações: definir a temperatura; ver temperaturas guardadas; ver a temperatura atual e a rotação da ventoinha
     int leituraEEPROM;     //Define a posição que será lida da EEPROM
     TRISB = 0b11111111;    //PORTB como entrada
     TRISA.RA4=0;           // Define o pino RA4 do PORTA como saida(Seleção Display 3).
     TRISA.RA5=0;           // Define o pino RA5 do PORTA como saida(Seleção Display 4).
     TRISD = 0;             // Define PORTD como saida.
     TRISE = 0;             // Define PORTE como saida.
     TRISC.RC0 = 1;         // Define PORTC.RC0 como entrada.
     TRISC.RC2 = 0;         // Define PORTC.RC2 como saida.
     TRISC.RC1 = 0;         // Define PORTC.RC1 como saida.
     TRISC.RC5 = 0;         // Define PORTC.RC5 como saida.
     ADCON0 = 0b00000001;   // Configura conversor A/D Canal 0, conversão desligada, A/D ligado.
     ADCON1 = 0b11001100;   // Configura todos canais como Digital menos AN0, AN1, AN2 e REF Interna.
     ADCON2 = 0b10111110;   // Configura conversor A/D para resultado justificado a direita, clock de 20 TAD, clock de Fosc/64.
     // Configuração das interrupções
     INTCON.GIEH = 1;      // Habilita as interrupções e a interrupção de alta prioridade.
     INTCON.GIEL = 1;      // Habilita as interrupções e a interrupção de baixa prioridade
     RCON.IPEN = 1;        // Configura 2 niveis de interrupção.
     // Timer 0
     INTCON2.TMR0IP = 1;   //Alta prioridade da Interrupção do TIMER0
     INTCON.TMR0IE = 1;    //Habilita interrupção do TIMER0 por ocorrência de estouro de contagem (overflow).
     T0CON = 0b10000100;   // Configura timer modo 16 bits, com prescaler 1:32
     TMR0L = 0x7B;         // Carrega valores de contagem
     TMR0H = 0xE1;         // Carrega valores de contagem
     INTCON.TMR0IF = 0;    // Apaga flag de estouro do TIMER0
     // Timer 1
     T1CON = 0b10000011;  // Liga TIMER1 como Contador em RC0, prescaler 1:1, modo 16bits.
     TMR1L = 0;           // Carrega valor de contagem baixa do TIMER1
     TMR1H = 0;           // Carrega valor de contagem alta do TIMER1
     PIR1.TMR1IF = 0;     // Apaga flag de estouro do TIMER1

     PORTA = 0;                 //Inicia os valores do PORTA como zero
     PWM = 0;                   //Inicia o valor do PWM como zero
     posWriteEEPROM = 0;        //Inicia a posição de escrita na EEPROM como zero
     temperaturaDefinida = 30;  //Inicialmente, a temperatura definida é 30
     ultimaTemperatura = 0;     //Inicia a última temperatura como zero
     inicializarVetor(&senha);  //Inicializa o vetor de senha
     inicializarVetor(&login);  //Inicializa o vetor de login
     Lcd_Init();                //Inicializa o LCD
     Lcd_Cmd(_LCD_CLEAR);       // Limpa o display
     Lcd_Cmd(_LCD_CURSOR_OFF);  // Desliga o Cursor
     PWM1_Init(5000);           // Inicializa módulo PWM com 5Khz
     PWM1_Start();              // Start PWM
     while(1){
        inserirSenha = 1;       // Define que deve ser definida a senha
        logado = 0;             // Define que não está logado
        i = 0;                  // Define a posição do dígito que a senha será inserida
        cont = 1;               // Contador é inicialmente definido como 1
        gravarEEPROM = 0;       // Define a posição que será escrita na EEPROM
        while(inserirSenha == 1){ //Gravar senha
            definirValoresVetor("Definir senha:", &senha); //Definir valores do vetor senha
            if(i>=tamSenha){
               inserirSenha = 0; //Sai do loop
               Lcd_Cmd(_LCD_CLEAR);
               Lcd_Out(1,1,"Senha definida");
               Delay_ms(500);
               Lcd_Cmd(_LCD_CLEAR);
            } else imprimirSenha(&senha); //Imprime senha que está sendo inserida
        }
        while(1){
            menu = ADC_Read(0);      // Lê Canal AD 0
            menu *= 0.0039;          // 3/1023 = 0.0039
            Lcd_Cmd(_LCD_CLEAR);
            controlarTemperatura();  //Verifica a temperatura atual para: ligar/desligar resistência de aquecimento ou ligar/desligar ventoinha 
            if(menu==0){ //Mostrar logar or deslogar
                if(logado == 0){ //Não está logado
                    Lcd_Out(1,1,">Logar");
                    if(Button(&PORTB, 2, 100, 0)){ //Ao pressionar o botão de confirmar, será executado a ação de logar.
                        logar(); //Logar
                        logado = 1;
                    }
                }
                else{ //Logado
                    Lcd_Out(1,1,">Deslogar");
                    if(Button(&PORTB, 2, 100, 0)){ //Ao pressionar o botão de confirmar, será executado a ação de deslogar.
                        inicializarVetor(&login); //Inicializa o vetor login com (-1)
                        logado = 0;
                    }
                }
                Lcd_Out(2,1,"Ler temp/rot");
            }
            else if(menu == 1){ //Opção para ler temperatura e rotação
                Lcd_Out(1,1,">Ler temp/rot");
                Lcd_Out(2,1,"Temperaturas");
                 if(Button(&PORTB, 2, 100, 0)){ 
                         leituraTemp = 1; //Ao pressionar o botão de confirmar, será apresentado no LCD, os valores de temperatura e rotação atuais
                         Lcd_Cmd(_LCD_CLEAR);
                         while(leituraTemp == 1){
                             if(Button(&PORTB, 2, 100, 0)) 
                                  leituraTemp = 0; //Volta para o menu
                             mostrarTemperatura(); //Mostrar temperatura no LCD
                             mostrarRotacao(); //Mostrar rotação da ventoinha no LCD
                             controlarTemperatura(); //De acordo com a temperatura estabelecida
                             //Liga o resistor para aquecer ou liga a ventoinha
                         }
                 }
            }
            else if (menu == 2){
                if(logado == 1){
                    Lcd_Out(1,1,">Temperaturas");
                    Lcd_Out(2,1,"Alterar temp.");
                }
                else{
                    Lcd_Out(1,1,"Ler temp/rot");
                    Lcd_Out(2,1,">Temperaturas");
                }
                if(Button(&PORTB, 2, 100, 0)){ //Leitura das temperaturas
                    Lcd_Cmd(_LCD_CLEAR);
                    leituraTemp = 1; //Ao pressionar o botão de confirmar, será apresentado no LCD, os valores das temperaturas lidas
                    leituraEEPROM = 0; //Seta que o valor lido da EEPROM será a primeira posição
                    while(leituraTemp == 1){
                        if(Button(&PORTB, 2, 100, 0)) //Sai do loop
                            leituraTemp = 0;
                        else if(Button(&PORTB, 1, 100, 0)){ //Incrementa para a proxima posição que foi gravada
                            if((leituraEEPROM + 2) < posWriteEEPROM)
                                leituraEEPROM=leituraEEPROM+2;
                        }
                        else if(Button(&PORTB, 0, 100, 0)){ //Decrementa para a posição anterior que foi gravada
                            if(leituraEEPROM > 1)
                                leituraEEPROM=leituraEEPROM-2;
                        }
                        leituraTemperatura(leituraEEPROM); //Apresenta o valor da temperatura lida
                    }
                }
            }
            else {
               if(logado == 1){
                   Lcd_Out(1,1,"Temperaturas");
                   Lcd_Out(2,1,">Alterar temp.");
                   if(Button(&PORTB, 2, 100, 0)){ //Alterar a temperatura
                        leituraTemp = 1; //Ao pressionar o botão de confirmar, será definido o valor da temperatura
                        while(leituraTemp == 1){
                            if(Button(&PORTB, 2, 100, 0)) //Sai do loop
                                 leituraTemp = 0;
                            definirTemperatura(); //Define o valor da temperatura (valor apresentado no display de 7 segmentos)
                            controlarTemperatura(); //Controla a temperatura
                        }
                   }
               }
               else{
                   Lcd_Out(1,1,"Ler temp/rot");
                   Lcd_Out(2,1,">Temperaturas");
                   if(Button(&PORTB, 2, 100, 0)){ //Ao pressionar o botão de confirmar, será apresentado as tempeaturas
                        Lcd_Cmd(_LCD_CLEAR);
                        leituraTemp = 1; //Ao pressionar o botão de confirmar, será apresentado no LCD, os valores das temperaturas lidas
                        leituraEEPROM = 0; //Seta que o valor lido da EEPROM será a primeira posição
                        while(leituraTemp == 1){
                            if(Button(&PORTB, 2, 100, 0)) //Sai do loop
                               leituraTemp = 0;
                            else if(Button(&PORTB, 1, 100, 0)){ //Incrementa para a proxima posição que foi gravada
                                if((leituraEEPROM + 2) < posWriteEEPROM)
                                    leituraEEPROM=leituraEEPROM+2;
                            }
                            else if(Button(&PORTB, 0, 100, 0)){ //Decrementa para a posição anterior que foi gravada
                                if(leituraEEPROM > 1)
                                    leituraEEPROM=leituraEEPROM-2;
                            }
                            leituraTemperatura(leituraEEPROM); //Apresenta o valor da temperatura lida
                        }
                   }
               }
            }
            if(gravarEEPROM >= 100){ //Grava na EEPROM se o tempo de contagem é maior que 12s
               gravarEEPROM = 0; //Inicia a nova contagem
               funcGravarEEPROM(); //Grava na EEPROM o valor da temperatura atual
            }
            Delay_ms(50);
        }
     }
}
