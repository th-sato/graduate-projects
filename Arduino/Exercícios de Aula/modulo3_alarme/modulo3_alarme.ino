/* Projeto Alarme */
const int LM35 = 0;
float temperatura = 0;
int ADClido = 0;
const int LEDVermelho = 8;
const int LEDVerde = 9;
void setup(){
  analogReference(INTERNAL1V1);
  Serial.begin(9600);
  pinMode(LEDVermelho, OUTPUT);
  pinMode(LEDVerde, OUTPUT);
}
void loop(){
  ADClido = analogRead(LM35);
  temperatura = ADClido * 0.1075268817204301; //no Leonardo use 0.4887585532
  Serial.print("Temperatura = ");
  Serial.print(temperatura);
  Serial.println(" *C");
  if(temperatura <= 27){ // setei como 25oC
    digitalWrite(LEDVerde, HIGH);
    digitalWrite(LEDVermelho, LOW);
  }
  else{
    digitalWrite(LEDVermelho, HIGH);
    digitalWrite(LEDVerde, LOW);
  }
}
