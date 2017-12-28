# Atividade 9: Programação em MPI

1. Considere o código sequencial para calcular numericamente ln 2:
```
#include <stdio.h>
#define N 100000000
#define u 2.0
int main(void) {
    double passo, soma,x;
    int i;
    passo = (u-1) / (double) N;
    for (i=0; i<N;i++) {
        x=1+i*passo;
        soma=soma+0.5*(1/x+1/(x+passo));
    }
    printf("ln %f = %20.15f\n", u, passo*soma);
    return 0; 
}
```

> Faça um programa em linguagem C com MPI para o código acima, dividindo a soma igualmente por todos os processos. As somas parciais devem ser enviadas ao processo 0, que deve calcular o resultado final e indicar o tempo total gasto em milissegundos.
> Utilize o número de processos igual ao número de processadores. Teste com 1, 2, 4, 6 e 8 processos (acima de 4 deve-se usar pelo menos duas máquinas interconectadas em rede). Mostre o tempo de execução, speedup e eficiência atingidos na forma de gráficos.

2. O programa anexo no moodle chamado "ftcs.c", faz o cálculo numérico de um problema unidimensional de condução de calor por diferenças finitas através do método FTCS. Deve-se construir uma versão distribuida deste código usando MPI. Teste o programa concorrente com 1, 2, 4, 6 e 8 processos (acima de 4 deve-se usar pelo menos duas máquinas interconectadas em rede). Mostre o tempo de execução, speedup e eficiência atingidos na forma de gráficos.
> _Obsservação:_ Cuidado para evitar deadlocks com a troca de dados entre processos adjacentes.
