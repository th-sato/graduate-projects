#include <stdio.h>
#include "mpi.h"

#define N 100000000
#define u 2.0

int main(int argc, char *argv[]) {

  double t1, t2;
  double passo, soma_parcial, soma_global, x;
  int i;
  int processId;    /* Rank dos processos */
  int noProcesses;  /* Numero dos processos */

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &noProcesses);
  MPI_Comm_rank(MPI_COMM_WORLD, &processId);

  if (processId == 0)
    t1 = MPI_Wtime();

  passo = (u-1) / (double) N;
  soma_parcial = 0;
  for(i = processId; i < N; i+=noProcesses){
    x=1+i*passo;
    soma_parcial = soma_parcial + 0.5*(1/x+1/(x+passo));
  }
  MPI_Reduce(&soma_parcial, &soma_global, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  if(processId == 0)
    printf("ln %f = %20.15f\n", u, passo*soma_global);

  if (processId == 0)
  {
    t2 = MPI_Wtime();
    printf( "O tempo decorrido foi: %f\n", t2 - t1 );
  }

  MPI_Finalize();

  return 0;
}
