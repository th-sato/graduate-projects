//Programa para gerar o grid
#include <stdio.h>
#include <stdlib.h>

typedef struct { //Estrutura com as informações dos estados
    char atual; //Estado atual
    char prox; //Proximo estado
    int cont; //Contador temporal para o ṕróximo estado
}Estado;

/* Tipos de estado:
    0: Árvore
    1: Água
    2: Fogo/Incêndio
    3: Cinzas*/

/* Distribuição dos estados:
    0: 75%
    1: 25%
    2: 0%. inicialmente não há fogo
    3: 0%, consideramos que não cinzas, pois ainda não houve focos de incêndios
*/

Estado** inicializaEstado(int n){
    int i, j;
    Estado **m;
    m = (Estado**)malloc(n*sizeof(Estado*));
    for(i=0; i<n; i++){
        m[i] = (Estado*)malloc(n*sizeof(Estado));
    }
    for(i=0; i<n; i++){ //Inicia tudo como árvore
        for(j=0; j<n; j++){
            m[i][j].atual = '0';
            m[i][j].prox = 'a'; //Considere 'a' como indeterminado
            m[i][j].cont = '0';
        }
    }
    return m;
}

void estado1 (Estado** M, int n){ //Água junta e separada das árvores.
    float a = 0.25 * n * n, c=0.0;
    int i, j, k=0;
    for(i=0; i<k+1; i++){
        for(j=0; j<k+1; j++){
            if (c>=a) break;
            if (M[i][j].atual != '1'){
                M[i][j].atual = '1';
                c++;
            }
        }
        if (c < a && k<n-1) k++;
    }
}

void estado2 (Estado** M, int n){ //Organização aleatória (adaptação da rede aleatória)
    srand(time(NULL));
    float a = 0.25 * n * n, c=0.0;
    int i, j;
    while (c < a){
        i = rand()%n;
        j = rand()%n;
        if (M[i][j].atual=='0'){
            M[i][j].atual = '1';
            c++;
        }
    }
}

void imprimirMatriz (Estado **m, int n){
    int i, j;
    FILE *arq = fopen("matriz3.txt", "w");
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            printf("%c ", m[i][j].atual);
            fprintf(arq, "%c ", m[i][j].atual);
        }
        printf ("\n");
        fprintf(arq, "\n");
    }
    fclose(arq);
}

int main(){
    Estado **m;
    int n = 1000; //Definir um valor para n.
    m = inicializaEstado(n);
    estado2(m, n);
    imprimirMatriz (m, n);
    return 0;
}
