### Converta o programa serial para calcular a condução de calor 1D (Arquivo: "fcts.c") para executar em uma GPU.

_OBSERVAÇÃO:_ Preocupe-se em converter apenas o trecho responsável pelo cálculo das linhas 41 até 46:

for (i=1; i<n; i++) {
  u[i]=u_prev[i]+kappa*dt/(dx*dx)*(u_prev[i-1]-2*u_prev[i]+u_prev[i+1]);
  x += dx;
}
u[0] = u[n] = 0.; /*forca condicao de contorno*/
tmp = u_prev; u_prev = u; u = tmp; /* troca entre ponteiros */

> Faça testes com diferentes configurações de grade e blocos variando a quantidade de threads por bloco da seguinte forma: 512, 256, 128, 64.

> Verifique em que situação o algoritmo melhorou o desempenho.
