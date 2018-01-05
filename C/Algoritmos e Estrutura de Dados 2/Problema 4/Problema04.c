#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[16];
}guardarNome;

void countingSort(guardarNome* v, guardarNome* v2, int k, int a, int analisar);
guardarNome* radixSort(guardarNome* v, int maior, int a);
int converterCaracteres(char c);
int main();

int main(){
    int a, i, j, k=0, maior;
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
        k++;
        if (k==1) maior = strlen(v[i].nome);
        else if (k>1){
            if (maior < strlen(v[i].nome)){
                maior = strlen(v[i].nome);
            }
        }
    }
    //Colocar o espaço em branco
    for (i=0; i<a; i++){
        if (strlen(v[i].nome)!=maior){
            int b=strlen(v[i].nome);
            while(b<=maior){
                if (b!=maior) v[i].nome[b] = ' ';
                else v[i].nome[b] ='\0';
                b++;
            }
        }
    }
    int b, c;
    scanf("%d %d", &b, &c);
    v = radixSort(v, maior, a);
    for (i=b-1; i<(b+c-1); i++){
        printf("%s\n", v[i].nome);
    }
    return 0;
}

int converterCaracteres(char c){
    if (c==' ') return 0;
    else return ((c-'a')+1);
}

//passo o vetor com nomes, maior e o tamanho dele.
guardarNome* radixSort(guardarNome* v, int maior, int a){
    int i, k=27;
    guardarNome *v2 = malloc(a*sizeof(guardarNome));
    for(i=maior-1; i>=0; i--){
        countingSort(v, v2, k, a, i);
    }
    return v2;
}


void countingSort(guardarNome* v, guardarNome* v2, int k, int a, int analisar){
    int i, valor, pos;
    int *C = malloc(k*sizeof(int));
    for(i=0; i<k; i++){
        C[i]=0;
    }
    for(i=0; i<a; i++){
        C[converterCaracteres(v[i].nome[analisar])]++;
    }
    for(i=1; i<k; i++){
        C[i]=C[i]+C[i-1];
    }
    for(i=0; i<k; i++){
        printf ("%d ", C[i]);
    }
    printf ("\n");
    for (i=a-1; i>=0; i--){
        valor=converterCaracteres(v[i].nome[analisar]);
        C[valor]--;
        pos=C[valor];
        strcpy(v2[pos].nome, v[i].nome);
    }
    for (i=a-1; i>=0; i--){
        strcpy(v[i].nome, v2[i].nome);
    }
}

