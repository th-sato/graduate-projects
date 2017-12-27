/*Módulo 1*/

const int ledPin = 13; //led no pino 13
const int Botao = 2; //botao no pino 2
int EstadoBotao = 0; //Variavel para ler o status do pushbutton
bool ledStatus = false;
bool botaoStatus = false;

void setup(){
  pinMode(ledPin, OUTPUT); //Pino do led será saída
  pinMode(Botao, INPUT); //Pino com botão será entrada
}
void loop(){
  EstadoBotao = digitalRead(Botao);
  if (EstadoBotao && !botaoStatus){
    ledStatus = !ledStatus;
    delay(300);
  }
  botaoStatus = EstadoBotao;
  digitalWrite(ledPin, ledStatus);
}
