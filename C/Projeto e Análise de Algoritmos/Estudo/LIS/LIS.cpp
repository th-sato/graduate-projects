#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//http://www.geeksforgeeks.org/dynamic-programming-set-3-longest-increasing-subsequence/

int LIS (int v[], int n){
    int i, j, aux[n], valor=0;
    for (i=0; i<n; i++)
        aux[i] = 1;
    for (i=1; i<n; i++){
        for (j=0; j<i; j++){
            if (v[i] < v[j] && aux[i] < aux[j]+1){
                aux[i] += 1;
            }
        }
    }
    /*for (i=0; i<n; i++){
        printf("%d ", aux[i]);
    }
    printf("\n");*/
    for (i=0; i<n; i++){
        if (valor < aux[i]) valor = aux[i];
    }
    return valor;
}

int LIS2 (int v[], int n){
    int i, j, aux[n], valor=0;
    for(i=0; i<n; i++)
        aux[i] = 1; //Caso base
    for(i=0; i<n; i++){
        for(j=0; j<i; j++){
            if(v[i] > v[j] && i>j)
                aux[i]++;
        }
    }
    /*for (i=0; i<n; i++){
        printf("%d ", aux[i]);
    }
    printf("\n");*/
    for (i=0; i<n; i++){
        if (valor < aux[i]) valor = aux[i];
    }
    return valor;
}

int main(void){
    int N = 8;
    int v[] = {-7, 10, 9, 2, 3, 8, 8, 1};
    printf("%d\n", LIS(v, N));
    printf("%d\n", LIS2(v, N));
    return 0;
}
