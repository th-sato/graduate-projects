/* Módulo 5 */
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int botoes [] = {7, 8, 9, 10};
const String menu [] = {"Opcao 1", "Opcao 2", "Opcao 3", "Opcao 4"};
const String subMenu [] = {".1", ".2", ".3", ".4"};
int menuBotoes [] = {0, 0, 0, 0};
int marcadorLocal = 0;
String marcador = " *";
int posicaoMP = 0;
int posicaoSM = 0;
bool menuPrincipal = true;

// 7: Descer menu (primeiro)
// 8: Voltar (segundo)
// 9: Confirmar (terceiro)
// 10: Subir menu (quarto)

void setup() {
  for(int i=0; i<4; i++){
    pinMode(botoes[i], INPUT);
  }
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Iniciando...");
  delay(500);
}

void loop() {
  for(int i=0; i<4; i++){
    menuBotoes[i] = digitalRead(botoes[i]);
  }
  
  if(menuBotoes[0]) { //Subir menu
    if(menuPrincipal){
      if(posicaoMP<3) posicaoMP++;
      if(marcadorLocal <3) marcadorLocal++;
    }
    else{
      if(posicaoSM<3) posicaoSM++;
      if(marcadorLocal <3) marcadorLocal++;
    }
  }
  else if (menuBotoes[1]) { //Voltar
    menuPrincipal = true;
    posicaoMP = 0;
    posicaoSM = 0;
    marcadorLocal = 0;
  }
  else if (menuBotoes[2]){ //Enter
    menuPrincipal = false;
    
  }
  else if (menuBotoes[3]){ //Abaixar menu
    if(menuPrincipal){
      if(posicaoMP>0) posicaoMP--;
      if(marcadorLocal>0) marcadorLocal--;
    }
    else{
      if(posicaoSM>0) posicaoSM--;
      if(marcadorLocal>0) marcadorLocal--;
    }
    
  }
  
  if(menuPrincipal) {
    lcd.clear();
    lcd.setCursor(0,0);
    if(posicaoMP < 3){
      lcd.print(menu[posicaoMP]);
      if(marcadorLocal < 3) lcd.print(marcador);
      lcd.setCursor(0,1);
      lcd.print(menu[posicaoMP+1]);
      if(marcadorLocal >= 3) lcd.print(marcador);
    }
    else{
      lcd.print(menu[posicaoMP-1]);
      if(marcadorLocal < 3) lcd.print(marcador);
      lcd.setCursor(0,1);
      lcd.print(menu[posicaoMP]);
      if(marcadorLocal >= 3) lcd.print(marcador);
    }
    delay(200);
  }
  else {
    lcd.clear();
    lcd.setCursor(0,0);
    if(posicaoSM < 3){
      lcd.print(menu[posicaoMP]);
      lcd.print(subMenu[posicaoSM]);
      if(marcadorLocal < 3) lcd.print(marcador);
      lcd.setCursor(0,1);
      lcd.print(menu[posicaoMP]);
      lcd.print(subMenu[posicaoSM+1]);
      if(marcadorLocal >= 3) lcd.print(marcador);
    }
    else{
      lcd.print(menu[posicaoMP]);
      lcd.print(subMenu[posicaoSM-1]);
      if(marcadorLocal < 3) lcd.print(marcador);
      lcd.setCursor(0,1);
      lcd.print(menu[posicaoMP]);
      lcd.print(subMenu[posicaoSM]);
      if(marcadorLocal >= 3) lcd.print(marcador);
    }
    delay(200);
  }
}
