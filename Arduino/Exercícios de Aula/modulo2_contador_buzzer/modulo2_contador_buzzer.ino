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
int BotaoPressionadoAnt;
int Tom = 100; //Variavel para armazenar a nota musical
int contador_buzzer = 0;

void acionar_buzzer (){
  for (int i=0; i<contador_buzzer; i++){
    digitalWrite(Buzzer, HIGH);
    delayMicroseconds(Tom);
    delay(200);
    digitalWrite(Buzzer, LOW);
    delayMicroseconds(Tom);
    delay(200);
  }
}

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
    digitalWrite(ledPin1, HIGH);
    delay(200);
    contador_buzzer++;
    BotaoPressionadoAnt = millis();
  }
  if(EstadoBotao2 && !EstadoBotao1 && !EstadoBotao3) {
    digitalWrite(ledPin2, HIGH);
    delay(200);
    contador_buzzer++;
    BotaoPressionadoAnt = millis();
  }
  if(EstadoBotao3 && !EstadoBotao2 && !EstadoBotao1) {
    digitalWrite(ledPin3, HIGH);
    delay(200);
    contador_buzzer++;
    BotaoPressionadoAnt = millis();
  }
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  if(millis()-BotaoPressionadoAnt>2000){
    acionar_buzzer();
    contador_buzzer=0;
  }
}
