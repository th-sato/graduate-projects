/* Módulo 5 */
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int LM35 = 0;
float temperatura = 0;
int ADClido = 0;

void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL1V1);
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(0,0);
  ADClido = analogRead(LM35);
  temperatura = ADClido * 0.1075268817;
  lcd.print(temperatura);
  lcd.print(" *C");
  Serial.print("Temperatura = ");
  Serial.print(temperatura);
  Serial.println(" *C");
  delay(100);
}
