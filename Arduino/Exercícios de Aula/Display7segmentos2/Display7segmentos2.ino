/* Display 7 Segmentos 2 */
const int a = 4;
const int b = 5;
const int c = 6;
const int d = 7;
const int botaoSoma = 3;
const int botaoSubtracao =  2;

int estadoBotaoSoma = 0;
int estadoBotaoSubtracao = 0;
int contador = 0;

void setup(){
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(botaoSoma, INPUT);
  pinMode(botaoSubtracao, INPUT);
}

void loop(){
  estadoBotaoSoma = digitalRead(botaoSoma);
  estadoBotaoSubtracao = digitalRead(botaoSubtracao);

  if(estadoBotaoSoma && !estadoBotaoSubtracao){
    if(contador == 9) contador = 0;
    else contador++;
    delay(250);
  }

  if(estadoBotaoSubtracao && !estadoBotaoSoma){
    if(contador != 0) contador--;
    delay(250);
  }
  switch (contador){
    case 0:
      digitalWrite(a, LOW);//DIGITO 0
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
     break;
     case 1:
      digitalWrite(a, HIGH);//DIGITO 1
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
     break;
     case 2:
      digitalWrite(a, LOW);//DIGITO 2
      digitalWrite(b, HIGH);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
     break;
     case 3:
      digitalWrite(a, HIGH);//DIGITO 3
      digitalWrite(b, HIGH);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
     break;
     case 4:
      digitalWrite(a, LOW);//DIGITO 4
      digitalWrite(b, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
     break;
     case 5:
      digitalWrite(a, HIGH);//DIGITO 5
      digitalWrite(b, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
     break;
     case 6:
      digitalWrite(a, LOW);//DIGITO 6
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
     break;
     case 7:
      digitalWrite(a, HIGH);//DIGITO 7
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
     break;
     case 8:
      digitalWrite(a, LOW);//DIGITO 8
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
     break;
     case 9:
      digitalWrite(a, HIGH); //DIGITO 9
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
     break;
     default:
     break;
  }
}
