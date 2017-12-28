#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>
#define MIN_VALUE -9999999

double *array;
double *retorno;
int MAX_THREADS;
int N;

void *calculoLog(void *tid) {
  long thid;
  long i;
  double maxloc;

  thid = (long) tid;

  maxloc = MIN_VALUE;

  for(i=thid; i<N; i+=MAX_THREADS){
     retorno[i] = log10(array[i]);
     if (retorno[i]>maxloc)
        maxloc = retorno[i];
  }

  retorno[thid] = maxloc;

  pthread_exit(0);
} 

int main(int argc, char *argv[]){
  pthread_t *t;
  double maxglobal;
  long i;
  long th;

  struct timeval inicio, final;
  int tmili;
  
  if(argc != 3){
     printf("Indique o número de threads e o tamanho do vetor, nesta ordem\n");
     exit(1);
  }
  
  MAX_THREADS = atoi(argv[1]);
  N = atoi(argv[2]);

  array = (double*) malloc(N*sizeof(double));
  retorno = (double*) malloc(N*sizeof(double));
  t = (pthread_t*) malloc(MAX_THREADS*sizeof(pthread_t));

  srand(time(NULL));

  for(i=0; i<N; i++){ 
     array[i] = rand ();
  }

  gettimeofday(&inicio, NULL);
  
  for(th=0; th<MAX_THREADS; th++) {
    pthread_create(&t[th], NULL, calculoLog, (void *) th);
  }

  maxglobal = retorno[0];
  for(th=0; th<MAX_THREADS; th++) {
    pthread_join(t[th],NULL);
    if (retorno[th]>maxglobal)
        maxglobal = retorno[th];
  }

  gettimeofday(&final, NULL);
  tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
  
  printf("Número de threads: %d\n", MAX_THREADS);

  printf("Maior valor: %lf\n", maxglobal);

  printf("Tempo decorrido: %d milisegundos\n", tmili);

  return 0;
}  
