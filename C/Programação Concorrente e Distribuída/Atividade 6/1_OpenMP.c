#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <omp.h>
#define N 100                 //Número de elementos produzidos
#define N_Produtores 2        //Número de produtores
#define N_Consumidores 4      //Número de consumidores
#define MAX_NUMBER 100000000  //Número máximo: 10^8

omp_lock_t lockPC;            //Lock para produtor e consumidor
int NThreads = N_Produtores + N_Consumidores;
int buffer[N];
int count = 0;
int first = 0;
int last = 0;

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

void produtor(int tid){
  int i, d;
  for(i = tid; i < N; i+=N_Produtores){
    d = rand()%MAX_NUMBER + 1; //Gerar valores entre 1 e 10^8
    while(count == N) omp_set_lock(&lockPC);
    buffer[last] = d; //Adicionar o valor ao buffer
    last = (last + 1) % N;
    count = count + 1;
    omp_unset_lock(&lockPC);
    printf("Produtor %d. Valor: %d. Posição: %d.\n\n", tid, d, last);
  }
}

void consumidor(int tid){
  int i, d;
  for(i = tid; i < N; i+=N_Consumidores){
    while(count == 0) omp_set_lock(&lockPC);
    d = buffer[first]; //Ler dado do buffer
    first = (first + 1)%N;
    count = count - 1;
    omp_unset_lock(&lockPC);
    printf("Consumidor %d. Valor: %d. Posição: %d.\n", tid, d, first);
    numero_primo(d); //usar dados
  }
}

void produtor_consumidor(){
  int id;
  #pragma omp parallel default(none) private (id) num_threads(NThreads)
  {
    id = omp_get_thread_num();
    if(id < N_Produtores) produtor(id);
    else consumidor(id-N_Produtores);
  }
}

int main(){
  int i;
  srand(time(NULL));
  omp_init_lock(&lockPC);
  printf("RAND_MAX: %d\n", RAND_MAX);
  produtor_consumidor();
  return 0;
}
