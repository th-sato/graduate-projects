/* Projeto Iluminação Automatizada */
const int LDR = 0;
const int Led = 6;
int ValorLido = 0;
int pwm = 0;

void setup() {
  pinMode(Led, OUTPUT);
}

void loop() {
  ValorLido = analogRead(LDR);
  if (ValorLido < 400){
    analogWrite(Led, pwm);
    pwm++;
    delay(100);
  }
  else{
    digitalWrite(Led, LOW);
    pwm = 0;
  }
  if(pwm > 255){
    pwm=255;
  }
}
