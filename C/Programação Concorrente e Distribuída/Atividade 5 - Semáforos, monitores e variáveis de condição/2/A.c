#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <omp.h>
#define MAX_THREADS 8
#define N 10000000

double arrayA[N], arrayB[N];

int main(int argc, char *argv[]){
  long i;
  double start, end;
  double prodEsc, result = 0;

  omp_set_num_threads(MAX_THREADS);

  srand(time(NULL));

  for(i=0; i<N; i++){ 
     arrayA[i] = rand();
     arrayB[i] = rand();
  }

  start = omp_get_wtime();
  
  #pragma omp parallel for default(none) private(i, prodEsc), shared(arrayA, arrayB, result) 
  for(i=0; i<N; i++) {
    prodEsc = arrayA[i] * arrayB[i];
    #pragma omp critical
      result += prodEsc;
  }

  end = omp_get_wtime();
  
  printf("Número de threads: %d\n", MAX_THREADS);

  printf("Tamanho do vetor: %d\n", N);

  printf("Tempo decorrido: %.4g segundos\n", end-start);

  printf("Produto escalar = %f\n", result);

  return 0;
}  
