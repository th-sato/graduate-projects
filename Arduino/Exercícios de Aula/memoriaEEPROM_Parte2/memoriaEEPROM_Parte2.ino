#include <EEPROM.h>

const int LM35 = 0;
float temperatura = 0;
int ADClido = 0;
int i = 0;
int tempoAnteriorLeitura = 0;
int tempoAtual;
int parteInteira;
int parteDecimal;
float media = 0;
bool impressao = true;

void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL1V1);  
}

void loop() {
  ADClido = analogRead(LM35);
  temperatura = ADClido * 0.1075268817;
  tempoAtual = millis();
  if((tempoAtual - tempoAnteriorLeitura >= 500) && (tempoAtual <= 10000)){
    Serial.println(temperatura);
    tempoAnteriorLeitura = tempoAtual;
    parteInteira = (int) temperatura;
    parteDecimal = (int) ((temperatura - parteInteira)*100);
    EEPROM.write(i, parteInteira);
    i++;
    EEPROM.write(i, parteDecimal);
    i++;
  }
  if(tempoAtual > 10000 && impressao){
    Serial.println("Valor guardado");
    for(int j=0; j<40; j+=2){
      Serial.print(EEPROM.read(j));
      Serial.print(".");
      Serial.println(EEPROM.read(j+1));
      temperatura = EEPROM.read(j) + (EEPROM.read(j+1)/100);
      media += temperatura;
    }
    media = media/20;
    Serial.print("Media da temperatura: ");
    Serial.println(media);
    impressao = false;
  }
}
