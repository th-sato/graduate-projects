#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
void indicar (bool *indicados, int *vetor, int n){
    int i;
    for (i=0; i<n; i++){
        indicados[i] = false;
    }
    for (i=0; i<n; i++){
        indicados[vetor[i]] = true;
    }
}
 
void atualizarIndicacao (bool *indicados, int *vetor, int n){
    int i, cont;
    bool trocou = true;
    bool *aux = (bool*)malloc(n*sizeof(bool));
    while (trocou){
        cont = 0;
        for (i=0; i<n; i++){
            aux[i] = false;
        }
        for (i=0; i<n; i++){
            if (indicados[i])
                aux[vetor[i]] = true;
        }
        for (i=0; i<n; i++){
            if(indicados[i]==aux[i]) cont++;
            indicados[i] = aux[i];
            //printf("%d ", indicados[i]);
        }
        //printf("\n");
        if (cont == n) trocou = false;
        //printf("%d %d\n", cont, cont2);
    }
    free(aux);
}
 
void printar (bool *indicar, int *vetor, int n){
    int i;
    for (i=0; i<n; i++){
        if(indicar[i])
            printf("%d ", i+1);
    }
    printf("\n");
}
 
int main(){
    int a, i, *vetor, aux, aux2;
    bool *indicacao;
    scanf("%d", &a);
    indicacao = (bool*)malloc(a*sizeof(bool));
    vetor = (int*)malloc(a*sizeof(int));
    for (i=0; i<a; i++){
        scanf ("%d %d", &aux, &aux2);
        vetor[aux-1] = aux2 - 1;
    }
    indicar(indicacao, vetor, a);
    atualizarIndicacao(indicacao, vetor, a);
    printar(indicacao, vetor, a);
    free(vetor);
    free(indicacao);
    return 0;
}