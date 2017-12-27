/* Módulo 2 */
const int ledPin1 = 13;
const int ledPin2 = 12;
const int ledPin3 = 11;
const int Botao1 = 2;
const int Botao2 = 3;
const int Botao3 = 4;
int EstadoBotao1 = 0;
int EstadoBotao2 = 0;
int EstadoBotao3 = 0;
bool led1 = false;
bool led2 = false;
bool led3 = false;
bool botaoAnt1 = false;
bool botaoAnt2 = false;
bool botaoAnt3 = false;

void setup(){
  pinMode(ledPin1, OUTPUT);
  pinMode(Botao1, INPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(Botao2, INPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(Botao3, INPUT);
}

void loop(){
  EstadoBotao1 = digitalRead(Botao1);
  EstadoBotao2 = digitalRead(Botao2);
  EstadoBotao3 = digitalRead(Botao3);
  if (EstadoBotao1 && !botaoAnt1){
    led1 = !led1;
    delay(300);
  }
  if (EstadoBotao2 && !botaoAnt2){
    led2 = !led2;
    delay(300);
  }
  if (EstadoBotao3 && !botaoAnt3){
    led3 = !led3;
    delay(300);
  }
  botaoAnt1 = EstadoBotao1;
  botaoAnt2 = EstadoBotao2;
  botaoAnt3 = EstadoBotao3;
  digitalWrite(ledPin1, led1);
  digitalWrite(ledPin2, led2);
  digitalWrite(ledPin3, led3);
}
