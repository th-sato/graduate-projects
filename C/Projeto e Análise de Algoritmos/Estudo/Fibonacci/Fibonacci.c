#include <stdio.h>

int Fibonacci(int n){
    if (n<=1) return n;
    else return (Fibonacci(n-1) + Fibonacci(n-2));
}

int FibonacciTopDown (int vetor[], int n){ //Fibonacci Top-Down com Memorização
    if (vetor[n] >= 0) return vetor[n]; //Fibonacci já calculado
    if (n <= 1) return n;
    vetor[n] = FibonacciTopDown(vetor, n-1) + FibonacciTopDown(vetor, n-2);
    return vetor[n];
}

int FTopDown (int n){
    int i, vetor[n+1];
    for (i=0; i<=n; i++)
        vetor[i] = -1;
    return FibonacciTopDown(vetor, n);
}

int FibonacciBottomUp(int n){
    int i;
    int vetor[n+1];
    vetor[0] = 0;
    vetor[1] = 1;
    for (i=2; i<=n; i++)
        vetor[i] = vetor[i-1] + vetor[i-2];
    return vetor[n];
}

int FibonacciBottomUp2(int n){
    int i, a = 0, b = 1;
    int resultado;
    for (i=2; i<=n; i++){
        resultado = a + b;
        a = b;
        b = resultado;
    }
    return resultado;
}

int main(void){
    printf("%d\n", Fibonacci(10));
    printf("%d\n", FTopDown(10));
    printf("%d\n", FibonacciBottomUp(10));
    printf("%d\n", FibonacciBottomUp2(10));
    return 0;
}
