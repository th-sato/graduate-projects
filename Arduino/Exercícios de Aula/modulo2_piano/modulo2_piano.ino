/* Projeto Piano */
const int ledPin1 = 12; //vermelho
const int ledPin2 = 11; //verde
const int ledPin3 = 13; //amarelo
const int Botao1 = 4;
const int Botao2 = 3;
const int Botao3 = 2;
const int Buzzer = 10; //O buzzer está colocado no pino 10
int EstadoBotao1 = 0;
int EstadoBotao2 = 0;
int EstadoBotao3 = 0;
int Tom = 0; //Variavel para armazenar a nota musical

void setup() {
  pinMode(Buzzer, OUTPUT);
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
  if(EstadoBotao1 && !EstadoBotao2 && !EstadoBotao3) {
    Tom = 100;
    digitalWrite(ledPin1, HIGH);
  }
  if(EstadoBotao2 && !EstadoBotao1 && !EstadoBotao3) {
    Tom = 200;
    digitalWrite(ledPin2, HIGH);
  }
  if(EstadoBotao3 && !EstadoBotao2 && !EstadoBotao1) {
    Tom = 500;
    digitalWrite(ledPin3, HIGH);
  }
  if(Tom > 0) { //enquanto Tom for maior que zero faça o que esta descrit o baixo:
    digitalWrite(Buzzer, HIGH);
    // Liga buzzer
    delayMicroseconds(Tom);
    // Espera o tempo proporcional ao comprimento de onda da nota musical em milisegundos
    digitalWrite(Buzzer, LOW);
    // Desliga buzzer
    delayMicroseconds(Tom);
    // Espera o tempo proporcional ao comprimento de onda da nota musical em milisegundos
    Tom = 0;
    // Reseta o Tom para zero, para sair do loop while e nao tocar o som constantemente
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  }
}
