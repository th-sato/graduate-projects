#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define INFINITY 999999999

int cortandoBarras (int v[], int n){ //Solução top-down
    if (n==0) return 0;
    else{
        int valor = -INFINITY, i;
        for (i=0; i<n; i++)
            valor = std::max(valor, v[i]+cortandoBarras(v, n-i-1));
        return valor;
    }
}

int BarrasMemoryAux (int v[], int n, int aux[]){
    if(aux[n]>=0) return aux[n];
    if(n==0) return 0;
    else{
        int i, q = -INFINITY;
        for(i=0; i<n; i++)
            q = std::max(q, v[i]+BarrasMemoryAux(v, n-i-1, aux));
        aux[n] = q;
        return q;
    }
}

int BarrasMemory (int vetor[], int n){
    int i, aux[n+1];
    for (i=0; i<=n; i++)
        aux[i] = -1; //Indica que ainda não foi calculado
    return BarrasMemoryAux(vetor, n, aux);
}

int BarrasBottomUp (int v[], int n){
    int i, j, aux[n+1], valor=0;
    aux[0] = 0;
    for (i=0; i<n; i++){
        valor = -INFINITY;
        for (j=0; j<=i; j++){
            valor = std::max(valor, v[j]+aux[i-j]);
        }
        aux[j] = valor;
    }
    return valor;
}

int BarrasBottomUp2 (int v[], int n){ //Guardar as soluções
    int i, j, valor=0, aux[n+1], aux2[n];
    aux[0] = 0;
    for(i=0; i<n; i++){
        valor = -INFINITY;
        for(j=0; j<=i; j++){
            if(valor < v[j]+aux[i-j]){
                valor = v[j]+aux[i-j];
                aux2[i] = j;
            }
        }
        aux[j] = valor;
    }
    /*for(i=0; i<n; i++){
        printf("%d ", aux2[i]);
    }
    printf("\n");*/
    return valor;
}

int main (void){
    int n = 10;
    int v[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    printf("%d\n", cortandoBarras(v, n));
    printf("%d\n", BarrasMemory(v, n));
    printf("%d\n", BarrasBottomUp(v, n));
    printf("%d\n", BarrasBottomUp2(v, n));
    return 0;
}
