#include <EEPROM.h>

const int LM35 = 0;
const int n_leitura = 20;
float temperatura;
float media;
int ADClido;
int j;
int parteInteira;
int parteDecimal;
bool ler_imprimir = true;

void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL1V1);  
}

void loop() {
  if(ler_imprimir){
    j = 0;
    media = 0;
    for(int i=0; i<n_leitura; i++){
      ADClido = analogRead(LM35);
      temperatura = ADClido * 0.1075268817;
      Serial.print("Valor lido ");
      Serial.print(i+1);
      Serial.print(": ");
      Serial.println(temperatura);
      parteInteira = int(temperatura);
      parteDecimal = int((temperatura - float(parteInteira))*100);
      EEPROM.write(j, parteInteira);
      j++;
      EEPROM.write(j, parteDecimal);
      j++;
      delay(500);
    }
    Serial.println("Os valores estao na EEPROM");
    for(int k=0; k<j; k=k+2){
      Serial.print("Temperatura ");
      Serial.print(k/2+1);
      Serial.print(": ");
      temperatura = float(EEPROM.read(k)) + (float(EEPROM.read(k+1)))/100;
      Serial.println(temperatura);
      media += temperatura;
    }
    media = media/n_leitura;
    Serial.print("Media da temperatura: ");
    Serial.println(media);
    ler_imprimir = false;
  }
}
