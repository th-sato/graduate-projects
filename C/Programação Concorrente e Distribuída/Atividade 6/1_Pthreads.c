#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <stdbool.h>
#define N 100                 //Número de elementos produzidos
#define N_Produtores 4        //Número de produtores
#define N_Consumidores 2      //Número de consumidores
#define MAX_NUMBER 100000000  //Número máximo: 10^8

pthread_t P[N_Produtores], C[N_Consumidores]; //Threads
pthread_mutex_t lockPC;                       //Semáforo mutex
int N_Total = N + N_Consumidores;             //Tamanho do vetor
int *fila;                                    //Buffer

int inicio = 0; //Posição inicial da fila
int final = 0;  //Posição final da fila
int count = 0;  //Quantidade de números inteiros na fila

void numero_primo(int x){
  int d;
  bool primo = true;
  if (x <= 1 || (x != 2 && x % 2 == 0)) //Verificar se é 0, 1 ou 2.
    primo = false;
  else
    primo = true;
  d = 3; //Começa a testar a partir do 3.
  while (primo && d <= x / 2) {
    if (x % d == 0)
      primo = false;
    d = d + 2; //Testa somente números ímpares
  }
  if(primo)
    printf("O número %d é primo!\n", x);
  else
    printf("O número %d não é primo!\n", x);
}

void* TP (void *tid){ //Gerar números aleatórios e inserir na fila.
  int d;
  long i, thid = (long) tid;
  for(i = thid; i < N; i+=N_Produtores){
    d = rand()%MAX_NUMBER + 1; //Gerar valores entre 1 e 10^8
    while(count == N) pthread_mutex_lock(&lockPC);
    fila[final] = d; //Adicionar o valor ao buffer
    final = (final + 1);
    count = count + 1;
    pthread_mutex_unlock(&lockPC);
    printf("Produtor %ld. Valor: %d. Posição: %d\n\n", thid, d, final);
  }
}

void* TC (void *tid){ //Retirar (se houver) dados da fila e verificar se este é primo.
  int d;
  long thid = (long) tid;
  while(1){
    while(count == 0) pthread_mutex_lock(&lockPC);
    d = fila[inicio]; //Ler dado do buffer
    inicio = (inicio + 1);
    count = count - 1;
    pthread_mutex_unlock(&lockPC);
    printf("Consumidor %ld. Valor: %d. Posição: %d\n", thid, d, inicio);
    if(d < 0) pthread_exit(0);
    else numero_primo(d); //usar dados
  }
}

int main (void){
  long i;
  srand(time(NULL));
  printf("RAND_MAX: %d\n", RAND_MAX);
  fila = (int*)malloc(N_Total*sizeof(int));
  //Criação das threads: produtores e consumidores
  for(i=0; i<N_Produtores; i++)
    pthread_create(&P[i], NULL, TP, (void*) i);
  for(i=0; i<N_Consumidores; i++)
    pthread_create(&C[i], NULL, TC, (void*) i);
  for(i=0; i<N_Produtores; i++)
    pthread_join(P[i], NULL);
  for(i=0; i<N_Consumidores; i++){
    fila[N+i] = -1; //Produção de número negativos
    count++;
  }
  for(i=0; i<N_Consumidores; i++)
    pthread_join(C[i], NULL);
  return 0;
}
