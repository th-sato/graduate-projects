/* Código realizado por:
- Thiago Hideki Sato (RA: 92341)
- Tiago Alexander Leal Ruzzon (RA: 92346)
- Tiago da Silva Cardoso (RA: 92347) */

#include <stdio.h>
#include <stdlib.h>

#define tam 1.0
#define dx 0.00001
#define dt 0.000001
#define kappa 0.000045
#define T  0.01


__global__ void calculo (float *u, float *u_prev, int N)
{
    int index = threadIdx.x + blockIdx.x * blockDim.x + 1;
    if (index < N + 1)
       u[index] = u_prev[index]+kappa*dt/(dx*dx)*(u_prev[index-1]-2*u_prev[index]+u_prev[index+1]);
}


int main(void) {
  float *tmp, *u, *u_prev; //Variáveis locais
  float *d_u, *d_u_prev; //PONTEIROS PARA CUDA
  float x, t, tempo;
  long int i, n, maxloc;
  cudaEvent_t start, stop; //Cálculo do tempo
  int size_vet; //Tamanho do vetores
  int threads_por_bloco = 512;

  /* Calculando quantidade de pontos */
  n = tam/dx;
  size_vet = (n+1) * sizeof(float);

  cudaEventCreate (&start);
  cudaEventCreate (&stop);

  cudaMalloc ((void**)&d_u, size_vet);
  cudaMalloc ((void**)&d_u_prev, size_vet);

  /* Alocando vetores */
  u = (float *) malloc((n+1)*sizeof(float));
  u_prev = (float *) malloc((n+1)*sizeof(float));

  printf("Inicio: qtde=%ld, dt=%g, dx=%g, dx²=%g, kappa=%f, const=%f\n",
	 (n+1), dt, dx, dx*dx, kappa, kappa*dt/(dx*dx));
  printf("Iteracoes previstas: %g\n", T/dt);

  x = 0;
  for (i=0; i<n+1; i++) {
    if (x<=0.5) u_prev[i] = 200*x;
    else        u_prev[i] = 200*(1.0-x);
    x += dx;
  }

  printf("dx=%g, x=%g, x-dx=%g\n", dx, x, x-dx);
  printf("u_prev[0,1]=%g, %g\n",u_prev[0],u_prev[1]);
  printf("u_prev[n-1,n]=%g, %g\n",u_prev[n-1],u_prev[n]);

  t = 0.;

  cudaEventRecord(start);
  while (t<T) {
    x = dx;

    cudaMemcpy(d_u, u, size_vet, cudaMemcpyHostToDevice);
    cudaMemcpy(d_u_prev, u_prev, size_vet, cudaMemcpyHostToDevice);

    calculo <<< (n + threads_por_bloco - 1) / threads_por_bloco, threads_por_bloco  >>> (d_u, d_u_prev, n);

    cudaMemcpy(u, d_u, size_vet, cudaMemcpyDeviceToHost);

    u[0] = u[n] = 0.; /* forca condicao de contorno */
    tmp = u_prev; u_prev = u; u = tmp; /* troca entre ponteiros */

    t += dt;
  }
  cudaEventRecord(stop);

  //CALCULANDO O TEMPO
  cudaEventSynchronize(stop);
  tempo = 0;
  cudaEventElapsedTime(&tempo, start, stop);
  printf("\nNúmero de threads por bloco: %d\n", threads_por_bloco);
  printf("Tempo decorrido (parte paralelizada): %f ms\n\n", tempo);

  /* Calculando o maior valor e sua localizacao */
  maxloc = 0;
  for (i=1; i<n+1; i++) {
    if (u[i] > u[maxloc]) maxloc = i;
  }
  printf("Maior valor u[%ld] = %g\n", maxloc, u[maxloc]);

  return 0;
}
