#include <stdio.h>
#include <stdlib.h>

main(){
    int n, i, a;
    scanf ("%d", &n);
    int v[n];
    for (i=0; i<n; i++){
        scanf ("%d", &v[i]);
    }
    a=bolha(v, n);
    if (a%2==0)
        printf("Carlos\n");
    else
        printf("Marcelo\n");
}


int bolha (int v[], int n){
    int i, j, cont=0, aux;
    for(i=n-1; i>0; i--){
        for(j=0; j<i; j++){
            if (v[j]>v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1]=aux;
                cont++;
            }
        }
    }
    return cont;
}
