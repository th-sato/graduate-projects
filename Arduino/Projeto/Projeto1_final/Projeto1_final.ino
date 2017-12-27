#include <LiquidCrystal.h>
#include <EEPROM.h>


LiquidCrystal lcd(9, 8, 5, 4, 3, 2);
const int MAX_POT = 1024; //Máxima resistência no potenciômetro.
const int NUM_CARS = 2; //Número de carros
const int LARG_LCD = 16; //Largura do LCD
const int potentiometer1 = A0; //Pino do potênciometro de controle do carro
const int BUZZER = 11; //Pino do buzzer
const int LED = 10;
const int potentiometer2 = A1; //Pino do potênciometro para controle da velocidade
const int motor = 6; //Pino do motor
const int number_buttons = 2; //Número de botões
const int buttons [number_buttons] = {7, 12}; //Botões do jogo
const int number_max_records = 5; //Quantidade de records armazenada
const String main_menu[3] = {" Diverting cars ", "Start game", "Best Scores"}; //Apresentar records
char cars[NUM_CARS][LARG_LCD]; //Carros
bool empty = false; //Variável que controla a geração de novos carros
bool collision = false; //Indica a colisão dos carros
bool first_menu = true; //Indica apresentar o menu principal
bool score_menu = false; //Indica as pontuações
bool game = false; //Iniciar jogo
bool pause = false; //Pausar o jogo
bool led_on = false; //Variável para indicar se o LED será aceso ou não
int menuBotoes [number_buttons] = {0, 0}; //Menu dos botões
int statusButtons[number_buttons]; //Status anterior do botão
int space = 0; //Espaço entre os carros
int pot_car_player = 0; //Valor do potenciômetro para deslocar o carro
int pot_menu = 0; //Valor do potenciômetro para deslocar o menu
int pot_motor = 0; //Controlar o motor
int car_pos_zero[2] = {0, 0}; //Indica a posição do carro anterior
int record; //Record
int pot_delay = 300; //Valor do potenciômetro para controlar a velocidade do carro
unsigned long timeControl; //Tempo para guardar a última atualização da rua
unsigned long now; //Tempo para atualizar a rua

void setup() {
  lcd.begin(16,2);  // Inicia o LCD de 16X2.
  initialize_EEPROM(); //Inicializa a EEPROM com valores zeros
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  for(int i = 0; i < number_buttons; i++){
    pinMode(buttons[i], INPUT);
  }
}

void loop() {
  if(first_menu){
    show_menu(); //Mostrar menu do jogo
    first_menu = false;
    score_menu = true;
    delay(500);
  }
  
  for(int i = 0; i < number_buttons; i++){
    menuBotoes[i] = digitalRead(buttons[i]);
  }

  if(game){
    now = millis();
    pot_car_player = map(analogRead(potentiometer1), 0, MAX_POT-1, 0, 2);
    pot_delay = map(analogRead(potentiometer2), 0, MAX_POT-1, 200, 700);
    pot_motor = map(analogRead(potentiometer2), 0, MAX_POT-1, 255, 0);
    if(!collision && !pause){
      cars_street(); //Constroi a pista do carro
      check_position(); //Identifica as colisões
    }
    else if (pause){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("   Game paused  ");
      pot_motor = 0;
      delay(300);
    }
    else if (collision){
      tone(BUZZER, 50, 500); //Indicar a batida
      pot_motor = 0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Car crash!!");
      lcd.setCursor(0,1);
      lcd.print("Score ");
      lcd.print(record);
      if(record > EEPROM.read(0)){ //Piscar LED
        for(int i = 0; i <= 5; i++){
          led_on = !led_on;
          digitalWrite(LED, led_on);
          delay(200);
        }
      }
      delay(3000);
      addRecordEEPROM(); //Guardar record se estiver entre os 5 maiores valores
      lcd.clear();
      first_menu = true;
      game = false;
    }
    if(menuBotoes[0] && !statusButtons[0]){ 
      if(pause == false){ //Pausar o jogo
        pause = true;
        pot_motor = 0;
      }
      else{ //Voltar o jogo
        pause = false;
      }
      delay(200);
    }
    else if (menuBotoes[1] && !statusButtons[1]){ //Sair do jogo
      lcd.clear();
      first_menu = true;
      game = false;
      pot_motor = 0;
      delay(200);
    }
    analogWrite(motor, pot_motor);
  }
  else if(score_menu){ //Menu com pontuações e início do jogo
    pot_menu = map(analogRead(potentiometer1), 0, MAX_POT-1, 0, 5);
    if(pot_menu==0){
      if(menuBotoes[1] && !statusButtons[1]){ //Inicializa o jogo
        score_menu = false;
        game = true;
        collision = false;
        lcd.clear();
        delay(250);
        record = 0;
        initialize_cars(); //Inicializa os carros com espaços no vetor
        timeControl = millis(); //Controla a velocidade dos carros
      }
      else { //Mostra o menu
        show_menu();
        delay(200);
      }      
    }
    else if (pot_menu>0){ //Apresentar records
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(main_menu[2]);
      lcd.setCursor(0,1);
      lcd.print(pot_menu);
      lcd.print("* ");
      lcd.print(EEPROM.read(pot_menu-1));
      delay(200);
    }
  }
  
  for(int i = 0; i < number_buttons; i++){
    statusButtons[i] = menuBotoes[i];
  }
}


void initialize_EEPROM(){ //Guarda os valores zero nas posições 0 a 4 da EEPROM
  for(int i = 0; i<number_max_records; i++){
    EEPROM.write(i, 0);
  }
}

void addRecordEEPROM(){ //Adiciona o valor na EEPROM
  int i = 0;
  bool updateEEPROM = true;
  while((i < number_max_records) && updateEEPROM){
    if(EEPROM.read(i) < record){ //Verifica se o valor do record é maior que o valor armazenado na EEPROM
      for(int j=(number_max_records - 1); j > i ; j--){ //Se for menor, desloca os outros valores
        EEPROM.write (j, EEPROM.read(j-1));
      }
      EEPROM.write(i, record); //Guarda o valor na EEPROM
      updateEEPROM = false; //Valor já adicionado, sair da função
    }
    i++;
  }
}

void show_menu(){ //Mostrar menu principal
  lcd.setCursor(0,0); //Coluna, linha.
  lcd.print(main_menu[0]);
  lcd.setCursor(0,1);
  lcd.print(">");
  lcd.print(main_menu[1]); //Colocar a maior pontuação
}


void initialize_cars(){ //Coloca espaços no vetor dos carros para não apresentar nada
  for(int i=0; i<NUM_CARS; i++){
    for(int j=0; j<LARG_LCD; j++){
      cars[i][j] = ' ';
    }
  }
  car_pos_zero[0] = 0;
  car_pos_zero[1] = 0;
}

void check_position (){ //Verifica a posição. Se o car_pos_zero (posição do carro que está vindo na segunda coluna) for a mesma posição do carro do jogador, então colisão.
  if(car_pos_zero[0] == 1 && cars[0][0] == '>') collision = true;
  else if(car_pos_zero[1] == 1 && cars[1][0] == '>') collision = true;
}

void cars_street (){
  if(now-timeControl>pot_delay){
    if(car_pos_zero[0] == 1 || car_pos_zero[1] == 1) record++;
    fill_position_to_collide(); //preenche o car_pos_zero que guarda a posição que o carro que está vindo
    space_to_generate_new_car();
    shift_cars();
    generate_cars_according_to_space();
    timeControl = now;
  }
  update_car_player();
  lcd.setCursor(0,0);
  lcd.print(cars[0]);
  lcd.setCursor(0,1);
  lcd.print(cars[1]);
}

void space_to_generate_new_car(){ //Espaço para gerar novo carro
  if(space == 0){ 
    empty = true; //Será adicionado um novo carro
    space = random(4,7); //Gera uma quantidade aleatória de espaços entre 4 e 7
  }
  else{
    space--; //Decrementa o valor do espaço. Quando cheguar a zero, será adicionado um carro
    empty = false; //Não será adicionado um novo carro
  }
}

void fill_position_to_collide(){ //Preenche car_pos_zero para a função check_position() verificar.
  if(cars[0][1] == '<'){
    car_pos_zero[0] = 1;
    car_pos_zero[1] = 0;
  }
  else if(cars[1][1] == '<'){
    car_pos_zero[0] = 0;
    car_pos_zero[1] = 1;
  }
  else {
    car_pos_zero[0] = 0;
    car_pos_zero[1] = 0;
  }
}

void shift_cars(){ //Deslocar carros
  for(int i=0; i<NUM_CARS; i++){
    for(int j=1; j<LARG_LCD-1; j++){
      cars[i][j] = cars[i][j+1];
    }
  }
}

void generate_cars_according_to_space(){ //Gera carros de acordo com o espaçamento
  if(empty){ //Adiciona um carro na pista
    int pos_car = random(0,NUM_CARS); //Gera uma posição
    cars[pos_car][LARG_LCD-1] = '<'; //Adiciona o carro
    if(pos_car == 0) cars[pos_car+1][LARG_LCD-1] = ' '; //Adiciona o espaço na outra linha
    else cars[pos_car-1][LARG_LCD-1] = ' '; //Adiciona o espaço na outra linha
  }
  else{ //Adiciona espaços
    cars[0][LARG_LCD-1] = ' ';
    cars[1][LARG_LCD-1] = ' ';
  }
}


void update_car_player(){ //Atualiza a matriz cars, atualizando a posição do carro do jogador.
  if(pot_car_player == 0){
    cars[0][0] = '>';
    if(car_pos_zero[1] == 1) cars[1][0] = '<';
    else cars[1][0] = ' ';
    
  }
  else{
    cars[1][0] = '>';
    if(car_pos_zero[0] == 1) cars[0][0] = '<';
    else cars[0][0] = ' ';
  }
}

