#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define N 100000

double *arrayA, *arrayB;
int MAX_THREADS;

void *produtoEscalar(void *tid) {
  long thid;
  long i;
  double prodEsc;

  thid = (long) tid;

  prodEsc = 0;
  for(i=thid; i<N; i+=MAX_THREADS)
     prodEsc += arrayA[i] * arrayB[i];

  arrayA[thid] = prodEsc;

  pthread_exit(0);
} 

int main(int argc, char *argv[]){
  pthread_t *t;
  double result;
  long i;
  long th;

  struct timeval inicio, final;
  int tmicro;
  
  if(argc == 1){
     printf("Passe o número de threads\n");
     return 0;
  }
  
  MAX_THREADS = atoi(argv[1]);

  arrayA = (double*) malloc(N*sizeof(double));
  arrayB = (double*) malloc(N*sizeof(double));
  t = (pthread_t*) malloc(MAX_THREADS*sizeof(pthread_t));
  result = 0;

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
    result += arrayA[th];
  }

  gettimeofday(&final, NULL);
  tmicro = (int) (final.tv_usec - inicio.tv_usec);
  
  printf("Número de threads: %d\n", MAX_THREADS);

  printf("Tempo decorrido: %d microsegundos\n", tmicro);

  printf("Produto escalar = %f\n", result);

  return 0;
}  
