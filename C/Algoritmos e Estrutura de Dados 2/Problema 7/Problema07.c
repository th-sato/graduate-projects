#include <stdio.h>
#include <stdlib.h>

int cont=0;

typedef struct Lista{
    struct Lista *prox;
    int num;
}Lista; //No para vértice adjacente

typedef struct ListaAdj{
    Lista **adj; //Vetor de lista de adjacências
}ListaAdj;

void inicializaGrafo(ListaAdj *G, int n){
    int i;
    G->adj = (Lista**)malloc(n*sizeof(Lista*));
    for(i=0; i<n; i++){
        G->adj[i] = NULL;
    }
}

Lista* criaNo (int num){
    Lista *no = (Lista*)malloc(sizeof(Lista));
    no->num = num;
    no->prox = NULL;
    return no;
}

void insereAresta(ListaAdj *G, int u, int v){
    Lista *no = G->adj[u]; //guarda endereco do primeiro da lista
    G->adj[u] = criaNo(v); //insere novo no no inicio da lista
    G->adj[u]->prox = no; //concatena com a lista de adjacencia anterior
}

void DFS(ListaAdj *G, int v, int *visitado){
    Lista *no = G->adj[v];
    visitado[v] = 1;
    //printf("Visita no v: %d\n", v);
    while(no!=NULL){
        //printf("no: %d    ", no->num);
        if(visitado[no->num]!=1){
            //printf("num: %d\n", no->num);
            cont++;
            DFS(G, no->num, visitado);
        }
        //printf("\n");
        no = no->prox;
    }
}

/*int verificar(ListaAdj* G, int a, int b){ //Verificar se duas ruas estão ligando as mesmas interseçções
    Lista *no = G->adj[a];
    while(no!=NULL){
        if(no->num == b) return 1;
        no = no->prox;
    }
    return 0; //Não existe o vértice
}*/

int main(){
    int N, M; //N: Número de intersecções e M: Número de ruas
    do{
        scanf("%d %d", &N, &M);
    }while(N<2 && N>2000 && M<2 && M>1999*1000);
    ListaAdj *g = (ListaAdj*)malloc(sizeof(ListaAdj));
    inicializaGrafo(g, N);
    int *visitado = (int*)calloc(N, sizeof(int));
    int a, b, c; //Variáveis que guardam a informação temporariamente
    int i;
    for (i=0; i<M; i++){
        scanf("%d %d %d", &a, &b, &c); a--; b--;
        if(c==1){
            //if(a!=b && verificar(g, a, b)==0) insereAresta(g, a, b);
            insereAresta(g, a, b);
        }
        else if(c==2){
            if(a!=b){
                //if (verificar(g, a, b)==0) insereAresta(g, a, b);
                //if (verificar(g, b, a)==0) insereAresta(g, b, a);
                insereAresta(g, b, a);
                insereAresta(g, a, b);
            }
        }
    }
    int j;
    for(j=0; j<N; j++){
        for(i=j; i<N; i++){
            //printf("%d\n", i);
            if(visitado[i]!=1){
                //printf("i: %d  ", i);
                DFS(g, i, visitado);
                //printf("\ncont: %d\n", cont);
            }
        }
        for(i=0; i<N; i++){
            visitado[i]=0;
        }
        if (cont!=(j+1)*(N-1)) break;
    }
    //printf("%d ", cont);
    if(cont==N*(N-1)) printf("1\n");
    else printf("0\n");
    return 0;
}
