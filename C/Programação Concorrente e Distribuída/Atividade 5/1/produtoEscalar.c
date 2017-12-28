#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#define MAX_THREADS 2
#define N 10000000

double arrayA[N], arrayB[N];
double result = 0;
pthread_mutex_t sb;

void *produtoEscalar(void *tid) {
  long thid;
  long i;
  double prodEsc;

  thid = (long) tid;

  prodEsc = 0;
  for(i=thid; i<N; i+=MAX_THREADS)
     prodEsc += arrayA[i] * arrayB[i];
  
  pthread_mutex_lock(&sb);
  result += prodEsc;
  pthread_mutex_unlock(&sb);

  pthread_exit(0);
} 

int main(int argc, char *argv[]){
  pthread_t t[MAX_THREADS];
  long i;
  long th;

  struct timeval inicio, final;
  int tmicro;
  
  srand(time(NULL));

  for(i=0; i<N; i++){ 
     arrayA[i] = rand();
     arrayB[i] = rand();
  }

  gettimeofday(&inicio, NULL);
  
  for(th=0; th<MAX_THREADS; th++) {
    pthread_create(&t[th], NULL, produtoEscalar, (void *) th);
  }

  for(th=0; th<MAX_THREADS; th++) {
    pthread_join(t[th],NULL);
  }

  gettimeofday(&final, NULL);
  tmicro = (int) (final.tv_usec - inicio.tv_usec);
  
  printf("Número de threads: %d\n", MAX_THREADS);

  printf("Tamanho do vetor: %d\n", N);

  printf("Tempo decorrido: %d microsegundos\n", tmicro);

  printf("Produto escalar = %f\n", result);

  return 0;
}  
