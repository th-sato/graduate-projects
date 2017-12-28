#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 100                 //Número de elementos produzidos
#define N_Produtores 1        //Número de produtores
#define N_Consumidores 2      //Número de consumidores
#define NaoVazio 0
#define NaoCheio 100
#define MAX_NUMBER 100000000  //Número máximo: 10^8

pthread_t P[N_Produtores], C[N_Consumidores];  //Threads
pthread_mutex_t S;                             //Semáforo mutex
pthread_mutex_t gateNV, gateNC;                //Controla o semáforo geral
int countNV = NaoVazio, countNC = NaoCheio;    //Valor positivo do semáforo geral
int inicio = 0;                                //Posição inicial da fila
int final = 0;                                 //Posição final da fila
int N_Total = N + N_Consumidores;              //Tamanho do vetor
int *fila;                                     //Buffer

void waitNV(){ //barzAlgorithmGeneralSemaphores
  pthread_mutex_lock(&gateNV);
  pthread_mutex_lock(&S);
  countNV--;
  if(countNV>0)
    pthread_mutex_unlock(&gateNV);
  pthread_mutex_unlock(&S);
}

void waitNC(){ //barzAlgorithmGeneralSemaphores
  pthread_mutex_lock(&gateNC);
  pthread_mutex_lock(&S);
  countNC--;
  if(countNC>0)
    pthread_mutex_unlock(&gateNC);
  pthread_mutex_unlock(&S);
}

void signalNV(){ //barzAlgorithmGeneralSemaphores
  pthread_mutex_lock(&S);
  countNV++;
  if(countNV == 1)
    pthread_mutex_unlock(&gateNV);
  pthread_mutex_unlock(&S);
}

void signalNC(){ //barzAlgorithmGeneralSemaphores
  pthread_mutex_lock(&S);
  countNC++;
  if(countNC == 1)
    pthread_mutex_unlock(&gateNC);
  pthread_mutex_unlock(&S);
}

void* produtor(void *tid){
  int d;
  long i, thid = (long) tid;
  for(i = thid; i < N; i+=N_Produtores){
    d = rand()%MAX_NUMBER + 1; //Gerar valores entre 1 e 10^8
    waitNC();
    fila[final] = d; //Adicionar o valor ao buffer
    final = (final + 1);
    signalNV();
    printf("Produtor %ld. Valor: %d. Posição: %d\n", thid, d, final);
  }
}

void *consumidor(void *tid){
  int d;
  long thid = (long) tid;
  while(1){
    waitNV();
    d = fila[inicio]; //Ler dado do buffer
    inicio = (inicio + 1);
    signalNC();
    printf("Consumidor %ld. Valor: %d. Posição: %d\n", thid, d, inicio);
    if(d < 0) pthread_exit(0);
  }
}

int main (void){
  long i;
  srand(time(NULL));
  printf("RAND_MAX: %d\n", RAND_MAX);
  pthread_mutex_lock(&gateNV);
  fila = (int*)malloc(N_Total*sizeof(int));
  //Criação das threads: produtores e consumidores
  for(i=0; i<N_Produtores; i++)
    pthread_create(&P[i], NULL, produtor, (void*) (i));
  for(i=0; i<N_Consumidores; i++)
    pthread_create(&C[i], NULL, consumidor, (void*) (i));
  for(i=0; i<N_Produtores; i++)
    pthread_join(P[i], NULL);
  for(i=0; i<N_Consumidores; i++){
    //Produção de número negativos
    fila[N+i] = -1;
    //Incrementar o semáforo para que o consumidor pare a execução ao ler os valores negativos
    signalNV();
  }
  for(i=0; i<N_Consumidores; i++)
    pthread_join(C[i], NULL);
  return 0;
}
