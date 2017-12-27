/* Módulo 4 */
const int PinoPotenciometro = A0;
const int Buzzer = 12;
const int LED[] = {2,3,4,5,6,7,8,9,10,11};
int ValorPot = 0;

void setup() {
  //analogReference(INTERNAL1V1);
  //pinMode(PinoPotenciometro, INPUT);
  pinMode(Buzzer, OUTPUT);
  for(int x=0; x<10; x++){
    pinMode(LED[x], OUTPUT);
  }
}
void loop() {
  ValorPot = analogRead(PinoPotenciometro);
  //digitalWrite(Buzzer, HIGH); //Ligar buzzer
  //delayMicroseconds(ValorPot); // Espera o tempo proporcional ao comprimento de onda da nota musical em milisegundos
  
  if(ValorPot > 0){
    pinMode(LED[0], HIGH);
    digitalWrite(Buzzer, HIGH); //Ligar buzzer
    tone(Buzzer, 50);
  }
  else{
    pinMode(LED[0], LOW);
    digitalWrite(Buzzer, LOW); //Ligar buzzer
  }
    
  if(ValorPot > 100){
    pinMode(LED[1], HIGH);
    tone(Buzzer, 100);
  }
  else 
    pinMode(LED[1], LOW);
    
  if(ValorPot > 200){
    pinMode(LED[2], HIGH);
    tone(Buzzer, 150);
  }
  else 
    pinMode(LED[2], LOW);
    
  if(ValorPot > 300){
    pinMode(LED[3], HIGH);
    tone(Buzzer, 200);
  }
  else 
    pinMode(LED[3], LOW);
    
  if(ValorPot > 400){
    pinMode(LED[4], HIGH);
    tone(Buzzer, 250);
  }
    
  else 
    pinMode(LED[4], LOW);
    
  if(ValorPot > 500){
    pinMode(LED[5], HIGH);
    tone(Buzzer, 300);
  }
  else 
    pinMode(LED[5], LOW);
    
  if(ValorPot > 600){
    pinMode(LED[6], HIGH);
    tone(Buzzer, 350);
  }
  else 
    pinMode(LED[6], LOW);
    
  if(ValorPot > 700){
    pinMode(LED[7], HIGH);
    tone(Buzzer, 400);
  }
  else 
    pinMode(LED[7], LOW);
    
  if(ValorPot > 800){
    pinMode(LED[8], HIGH);
    tone(Buzzer, 450);
  }
  else 
    pinMode(LED[8], LOW);
    
  if(ValorPot > 900){
    pinMode(LED[9], HIGH);
    tone(Buzzer, 500);
  }
  else 
    pinMode(LED[9], LOW);
}
