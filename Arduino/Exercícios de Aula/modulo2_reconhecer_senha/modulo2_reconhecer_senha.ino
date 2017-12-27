/* Módulo 2 */
const int ledPin1 = 13;
const int ledPin2 = 12;
const int ledPin3 = 11;
const int Botao1 = 2;
const int Botao2 = 3;
const int Botao3 = 4;
int EstadoBotao1 = 0;
int EstadoBotao2 = 0;
int EstadoBotao3 = 0;
bool EstadoAnt1 = false;
bool EstadoAnt2 = false;
bool EstadoAnt3 = false;
bool senha1 = false;
bool senha2 = false;
bool senhaCorreta = false;
int contador = 0;

void setup(){
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
  //Senha: VM, VR, AM.
  if(EstadoBotao1 && !estadoAnt1){ //Vermelho
    senha1 = true;
    if(senha2){
      senha2 = false;
    }
    delay(300);
  }
  else if(EstadoBotao2 && !estadoAnt2){ //Verde
    if(senha2){
      senha1 = false;
      senha2 = false;
    }
    else if(senha1){
      senha2 = true;
    }
    delay(300);
  }
  else if(EstadoBotao3 && !estadoAnt3){ //Amarelo
    if(senha2){
      senhaCorreta = true;
    }
    delay(300);
  }
  estadoAnt1 = EstadoBotao1;
  estadoAnt2 = EstadoBotao2;
  estadoAnt3 = EstadoBotao3;
  /*//Erro: VM, VR, VM, AM. --> Corrigir
  if(EstadoBotao1 || EstadoBotao2 || EstadoBotao3){ //Pelo menos um botão foi pressionado
      if(EstadoBotao1){ //Vermelho
        senha1 = true;
        delay(300);
      }
      else if(EstadoBotao2 && senha1){ //Verde
        senha2 = true;
        delay(300);
      }
      else if(EstadoBotao3 && senha2){ //Amarelo
        senhaCorreta = true;
        delay(300);
      }
      else{
        senha1 = false;
        senha2 = false;
        delay(300);
      }
  }*/
  if(senhaCorreta){
    digitalWrite(ledPin1, true);
    digitalWrite(ledPin2, true);
    digitalWrite(ledPin3, true);
    delay(300);
    digitalWrite(ledPin1, false);
    digitalWrite(ledPin2, false);
    digitalWrite(ledPin3, false);
    delay(300);
    contador++;
    if(contador == 5){
      contador = 0;
      senhaCorreta = false;
      senha1 = false;
      senha2 = false;
    }
  }
}
