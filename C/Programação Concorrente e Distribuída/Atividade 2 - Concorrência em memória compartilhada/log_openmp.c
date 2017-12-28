#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <omp.h>
#include <sys/time.h>
#define MIN_VALUE -9999999

double *array;
double *retorno;
int MAX_THREADS;
int N;

int main(int argc, char *argv[]){
  double maxglobal;
  double start, end;
  long i;

  //struct timeval inicio, final;
  //int tmili;
  
  if(argc != 3){
     printf("Indique o número de threads e o tamanho do vetor, nesta ordem\n");
     exit(1);
  }
  
  MAX_THREADS = atoi(argv[1]);
  N = atoi(argv[2]);

  omp_set_num_threads(MAX_THREADS);

  array = (double*) malloc(N*sizeof(double));
  retorno = (double*) malloc(N*sizeof(double));

  srand(time(NULL));

  for(i=0; i<N; i++){ 
    array[i] = rand ();
  }

  start = omp_get_wtime();
  //gettimeofday(&inicio, NULL);
  
  #pragma omp parallel for default(none) shared(N,array,maxglobal,retorno) private(i)
  for(i=0; i<N; i++){
     retorno[i] = log10(array[i]);
     if (retorno[i]>maxglobal)
        maxglobal = retorno[i];
  }

  end = omp_get_wtime();
  //gettimeofday(&final, NULL);
  //tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
  
  printf("Número de threads: %d\n", MAX_THREADS);

  printf("Maior valor: %f\n", maxglobal);

  printf("Tempo decorrido: %.4g segundos\n", end-start);

  return 0;
}  
