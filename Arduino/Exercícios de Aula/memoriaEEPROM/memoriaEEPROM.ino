#include <EEPROM.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  for(int i=0; i<4096; i++){
    EEPROM.write(i,255);
  }
  
  for(int i=0; i<4096; i++){
    Serial.print(i);
    Serial.print(", ");
    Serial.println(EEPROM.read(i));
  }
}
