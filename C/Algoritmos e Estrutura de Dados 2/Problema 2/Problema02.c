#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[15];
}guardarNome;

int contador;
void Quicksort (guardarNome v1[], int a, int b);
int Partition(guardarNome v1[], int a, int b);

main(){
    int a, i, j;
    scanf ("%d", &a);
    guardarNome *v = malloc(a*sizeof(guardarNome));
    for (i=0; i<a; i++){
        scanf ("%s", v[i].nome);
        //Deixar as letras minusculas
        for (j=0; j<strlen(v[i].nome); j++){
            if (v[i].nome[j]>='A' && v[i].nome[j]<='Z'){
                v[i].nome[j]= (v[i].nome[j]-'A') +'a';
            }
        }
    }
    int b, c;
    scanf("%d %d", &b, &c);
    Quicksort(v, 0, a-1);
    printf("%d\n", contador);
    for (i=b-1; i<(b+c-1); i++){
        printf("%s\n", v[i].nome);
    }
}

void Quicksort (guardarNome v1[], int a, int b){
    if (b>a){
        int q;
        q = Partition(v1, a, b);
        Quicksort(v1, a, q-1);
        Quicksort(v1, q+1, b);
    }
}

int Partition(guardarNome v1[], int a, int b){
    guardarNome pivo = v1[b], aux;
    int topo = a-1, i;
    for (i=a; i<b; i++){
        if ((strcmp(v1[i].nome, pivo.nome)<=0)){
            topo++;
            aux = v1[topo];
            v1[topo]=v1[i];
            v1[i]=aux;
        }
    }
    aux=v1[topo+1];
    v1[topo+1]=v1[b];
    v1[b]=aux;
    contador++;
    return (topo+1);
}
