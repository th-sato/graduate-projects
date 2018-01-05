/*Universidade Federal de S�o Paulo - UNIFESP

    Pedro Dousseau Guedes de Melo - RA: 95737
    Thiago Hideki Sato - RA: 92341
    Victor de S� Nunes - RA: 92350

    Projeto 3: Redes de Neur�nios Acoplados

    Modelagem Computacional
    Professor Marcos Gon�alves Quiles
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define theta 0.5
#define alpha 6.0
#define epsilon 0.02
#define beta 0.1
#define w_ij 0.5
#define ro 0.0
#define I_ativo 0.2
#define I_inativo -0.02
#define delta_t 0.01
#define Tmax 2000

typedef struct Digrafo{
    int V; //n�mero de v�rtices
    int A; //n�mero de arcos ou de arestas
    int **adj; //ponteiro para a matriz de adjac�ncia
}Digrafo;

typedef struct oscilador_relaxamento{
    float info;
    float I; //inativo ou ativo
}oscilador_relaxamento;

Digrafo* Inicializa_Cria_Digrafo (int V){ //inicia e cria o grafo
    int i, j;
    Digrafo *G = (Digrafo*)malloc(sizeof(Digrafo));
    G->V = V;
    G->A = 0;
    G->adj = (int**)malloc(V*sizeof(int*));
    for(i=0; i<V; i++){
        G->adj[i]=(int*)malloc(V*sizeof(int));
    }
    for(i=0; i<V; i++){
        for(j=0; j<V; j++){
            G->adj[i][j] = 0;
        }
    }
    return G;
}

void InsereDigrafo (Digrafo *G, int v, int w){ //Inserir aresta
    if(v!=w && G->adj[v][w]==0){
        G->adj[v][w]=1;
        G->A++;
    }
}

/*
    n = n�mero de v�rtices - Neur�nios
    k = Grau m�dio (2E/n), onde E � o n�mero de arestas (conex�es)
    O  grau  de um v�rtice � o n�mero de arestas que incidem no v�rtice
    2E = soma dos graus de todos os v�rtices de um grafo
    E = (k*n)/2
    Oscilador de Relaxamento: la�o de realimenta��o entre a vari�vel excitat�ria (x) e uma vari�vel inibit�ria (y).
    I: est�mulo externo
    p: sinal de ru�do
    S: acoplamento
    W_ij: for�a de acoplamento
    N(i): vizinhan�a do neur�nio i
    H() Heaviside function. H(v)=1, se v>0 e H(v)=0, caso contr�rio.
    theta: limiar de corte
    alpha e beta: par�metros do modelo
    epsilon: n�mero positivo pequeno
*/

int** GeraRedeRegular (int n, int k){ //Todos os n v�rtices devem ter k arestas
    Digrafo *G = Inicializa_Cria_Digrafo(n);
    int i, j=0, t;
    if(k>1){
        for(i=1; i<n; i++){ //diagonal principal da matriz
            if(i+k-1<=n){
                for(t=i; t<(i+k-1);t++){
                    if(t!=j){
                        InsereDigrafo (G, t, j);
                        InsereDigrafo (G, j, t);
                    }
                }
            }
            else if (i<n){
                t=i;
                while(i<n){
                    InsereDigrafo (G, i, j);
                    InsereDigrafo (G, j, i);
                    i++;
                }
                i=t;
            }
            j++;
        }
        for (j=0; j<k-1;j++){
            for(i=n-1; i>n+j-k; i--){ //Pontas da matriz
                if(i!=j){
                    InsereDigrafo(G, i, j);
                    InsereDigrafo(G, j, i);
                }
            }
        }
    }
    return G->adj;
}

int** GeraRedeAleatorio (int n, int k){
    int v, w;
    srand(time(NULL));
    int E = k*n; //Na liga��o dos v�rtices, ligamos tanto a ida quanto a volta. Dessa forma, ligar um v�rtice ao outro � contado 2 vezes.
    Digrafo *G = Inicializa_Cria_Digrafo(n);
    if(k>1){
        while(G->A < E){
            v = rand( )% n;
            w = rand( )% n;
            if(v!=w){
                InsereDigrafo(G, v, w);
                InsereDigrafo(G, w, v);
            }
        }
    }
    return G->adj;
}

int buscaBinaria(int *v, int valor, int n){ //Passar vetor ordenado, buscar o valor da probabilidade
    int ini=0, fim = n-1, meio;
    while (ini<=fim){
        meio = (ini+fim)/2;
        if(v[meio]==valor) return meio;
        if(v[meio]<valor) ini = meio+1;
        else fim = meio-1;
    }
    return fim+1; //Observa��o: busca bin�ria adaptada
}

int calcula_vertice(int** matriz, int tamanho, int posicao){ //Calcular a quantidade de arestas de um v�rtice
    int i, cont=0;
    for(i=0; i<tamanho; i++){
        if (matriz[posicao][i]==1)cont++;
    }
    return cont;
}

int** GeraRedeLivreDeEscala (int n, int k){
    int i = k+1; //Quantidade de v�rtices iniciais
    srand(time(NULL));
    int E, v, w, j;
    E = k*i;
    Digrafo *G = NULL;
    int *vet;
    if(k>1){
        while (i<=n){
            if (G==NULL){ //Iniciar a rede com n0 v�rtices inicias conectados
                G = Inicializa_Cria_Digrafo(n);
                for(v=0; v<i; v++){
                    for(w=0; w<i; w++){
                        if(v!=w){
                            InsereDigrafo(G, v, w);
                            InsereDigrafo(G, w, v);
                        }
                    }
                }
            }
            else { //Adicionar v�rtice
                //AdicionarVertice (G, i-1, 1);
                vet = (int*)calloc(i-1, sizeof(int));
                for(j=0; j<i-1; j++){
                    vet[j] = calcula_vertice(G->adj, i, j);
                    if (j!=0) vet[j] += vet [j-1];
                }
                while (G->A < E){ //Colocar a condi��o para que todos os v�rtices tenham pelo menos uma liga��o
                    v = buscaBinaria(vet, rand()%(vet[j-1]+1), i);
                    w = i-1;
                    if(v!=w){
                        InsereDigrafo(G, v, w);
                        InsereDigrafo(G, w, v);
                    }
                }
            }
            i++;
            E = k*i;
        }
    }
    return G->adj;
}

float* calcula_acoplamentos(int** matriz, oscilador_relaxamento* x ,int n){
    float *s = (float*)malloc(n*sizeof(float));
    int i, j;
    for(i=0; i<n; i++){
        s[i]=0.0;
        for(j=0; j<n; j++){
            if(i==j) continue;
            else if (matriz[i][j]==1 && x[j].info>=theta){
                s[i]+=w_ij;
            }
        }
    }
    return s;
}

float oscilador_x(oscilador_relaxamento* x, float y, float s, int i, int n){
    float dx;
    dx = (3*x[i].info - pow(x[i].info, 3) + 2 - y + x[i].I + ro + s)*delta_t;
    return dx;
}

float oscilador_y(float x, float y){
    float delta_y;
    delta_y = (epsilon*(alpha*(1+tanh(x/beta))-y))*delta_t;
    return delta_y;
}

void integra_osciladores(oscilador_relaxamento *x, float *y, float *s, int n){
    int i;
    float *deltaX = (float*)malloc(n*sizeof(float));
    float *deltaY = (float*)malloc(n*sizeof(float));
    for (i=0; i<n; i++){
        deltaY[i] = oscilador_y(x[i].info, y[i]);
        deltaX[i] = oscilador_x(x, y[i], s[i], i, n);
    }
    for (i=0; i<n; i++){
        y[i] += deltaY[i];
        x[i].info += deltaX[i];
    }
}

float somatorio(oscilador_relaxamento *x, int n){
    //Verificar se os neur�nios est�o atingindo um estado de sincronia. Se o somat�rio ir� aproximar zero, os neur�nios est�o sincronizados, caso contr�rio, se o valor ficar alto (eles est�o em fases distintas).
    int i, j = 1;
    float s=0.0;
    for(i=0; i<n; i++){
        s += fabs(x[i].info - x[j].info);
        j++;
    }
    return s;
}

int main(){
    srand(time(NULL));
    int i, j, n=500, k=2, cont=0;
    int impressao = n*0.1; //Imprimir 10% dos dados de x
    int **GRA, **GRR, **GRLR;
    GRA = GeraRedeAleatorio(n, k);
    GRR = GeraRedeRegular(n, k);
    GRLR = GeraRedeLivreDeEscala(n, k);
    int *vet = (int*)malloc(n*sizeof(int));

    /*for (i=0; i<n; i++){ //Imprimir a matriz
        for (j=0; j<n; j++){
            printf("%d ", a[i][j]); //a = matriz de adjacencia
        }
        printf("\n");
    }*/

    printf("Matrizes de adjac�ncias geradas\n");
    FILE *arq;
    oscilador_relaxamento *x = (oscilador_relaxamento*)malloc(n*sizeof(oscilador_relaxamento));
    float *y = (float*)malloc(n*sizeof(float));
    float t, *s;
    int v;


/*    REDE ALET�RIA
*/
    /*arq = fopen("GRA.txt", "w");
    for (i=0; i<n; i++){ //Iniciar valores para os neur�nios
        x[i].info = ((float)rand()/(float)RAND_MAX)*4.0;
        x[i].info += ((float)rand()/(float)RAND_MAX);
        x[i].info -= 3.0;

        //Ativar todos os neur�nios
        x[i].I = I_ativo;

        //Neur�nio ativo e inativo (sele��o aleat�ria)
        //if (rand()%2 == 0) x[i].I = I_ativo;
        //else x[i].I = I_inativo;

        //Neur�nio ativo e inativo (sele��o guiada)
        //vet[i] = calcula_vertice(GRA, n, i);
        //if (i!=0) vet[i] += vet[i-1];
        //x[i].I = I_inativo; //Inicia tudo inativo, para no pr�ximo for, ativar alguns neur�nios.

        y[i] = ((float)rand()/(float)RAND_MAX)*5;
        y[i] += ((float)rand()/(float)RAND_MAX);
        y[i] -= 1;
    }

    //Continua��o da sele��o guiada
    //for (j=0; j<n; j++){ //Ativa o neur�nio, aquele que tem mais v�rtices, tem maior probabilidade de ficar ativo
        //v = buscaBinaria(vet, rand()%(vet[i-1]+1), i);
        //x[v].I = I_ativo; //Ativa o neur�nio
    ///}

    for (t=0.0; t<Tmax; t+=delta_t){ //Imprimir 10% de n
        s = calcula_acoplamentos(GRA, x, n);
        integra_osciladores(x, y, s, n);
        if (cont%100==0) { //Filtrar a quantidade de dados;
            fprintf(arq, "%f ", t);
            for (i=0; i<impressao; i++){ //Imprimir 10%
                fprintf(arq, "%f ", x[10*i].info);
            }
            fprintf(arq, "\n");
        }
        cont++;
    }
    printf("%f\n", somatorio(x,n)); //Verificar se os neur�nios est�o em sincronia
    fclose(arq);
    printf("Rede aleat�rio pronta.\n");*/


/*
    REDE REGULAR
*/
    /*arq = fopen("GRR.txt", "w");
    for (i=0; i<n; i++){
        x[i].info = ((float)rand()/(float)RAND_MAX)*4.0;
        x[i].info += ((float)rand()/(float)RAND_MAX);
        x[i].info -= 3.0;

        //Ativar todos os neur�nios
        x[i].I = I_ativo;

        //Neur�nio ativo e inativo (sele��o aleat�ria)
        //if (rand()%2 == 0) x[i].I = I_ativo;
        //else x[i].I = I_inativo;

        //Neur�nio ativo e inativo (sele��o guiada)
        //vet[i] = calcula_vertice(GRR, n, i);
        //if (i!=0) vet[i] += vet[i-1];
        //x[i].I = I_inativo; //Inicia tudo inativo, para no pr�ximo for, ativar alguns neur�nios.

        y[i] = ((float)rand()/(float)RAND_MAX)*5;
        y[i] += ((float)rand()/(float)RAND_MAX);
        y[i] -= 1;
    }

    //Continua��o da sele��o guiada
    //for (j=0; j<n; j++){//Ativa o neur�nio, aquele que tem mais v�rtices, tem maior probabilidade de ficar ativo
        //v = buscaBinaria(vet, rand()%(vet[i-1]+1), i);
        //x[v].I = I_ativo; //Ativa o neur�nio
    ///}

    for (t=0.0; t<Tmax; t+=delta_t){ //Imprimir 10% de n
        s = calcula_acoplamentos(GRLR, x, n);
        integra_osciladores(x, y, s, n);
        if (cont%100==0) { //Filtrar a quantidade de dados;
            fprintf(arq, "%f ", t);
            for (i=0; i<impressao; i++){ //Imprimir 10%
                fprintf(arq, "%lf ", x[10*i].info);
            }
            fprintf(arq, "\n");
        }
        cont++;
    }
    printf("%f\n", somatorio(x,n)); //Verificar se os neur�nios est�o em sincronia
    printf("Rede regular pronta.\n");
    fclose(arq);*/

/*
    REDE LIVRE DE ESCALA
*/
    arq = fopen("GRLR.txt", "w");
    for (i=0; i<n; i++){
        x[i].info = ((float)rand()/(float)RAND_MAX)*4.0;
        x[i].info += ((float)rand()/(float)RAND_MAX);
        x[i].info -= 3.0;

        //Ativar todos os neur�nios
        x[i].I = I_ativo;

        //Neur�nio ativo e inativo (sele��o aleat�ria)
        //if (rand()%2 == 0) x[i].I = I_ativo;
        //else x[i].I = I_inativo;

        //Neur�nio ativo e inativo (sele��o guiada)
        //vet[i] = calcula_vertice(GRLR, n, i);
        //if (i!=0) vet[i] += vet[i-1];
        //x[i].I = I_inativo; //Inicia tudo inativo, para no pr�ximo for, ativar alguns neur�nios.

        y[i] = ((float)rand()/(float)RAND_MAX)*5;
        y[i] += ((float)rand()/(float)RAND_MAX);
        y[i] -= 1;
    }
    //Continua��o da sele��o guiada
    //for (j=0; j<n; j++){
        //v = buscaBinaria(vet, rand()%(vet[i-1]+1), i);
        //x[v].I = I_ativo; //Ativa o neur�nio
    ///}
    for (t=0.0; t<Tmax; t+=delta_t){ //Imprimir 10% de n
        s = calcula_acoplamentos(GRLR, x, n);
        integra_osciladores(x, y, s, n);
        if (cont%100==0) { //Filtrar a quantidade de dados;
            fprintf(arq, "%f ", t);
            for (i=0; i<impressao; i++){ //Imprimir 10%
                fprintf(arq, "%lf ", x[10*i].info);
            }
            fprintf(arq, "\n");
        }
        cont++;
    }
    printf("%f\n", somatorio(x,n)); //Verificar se os neur�nios est�o em sincronia
    printf("Rede livre de escala pronta.\n");
    fclose(arq);

    return 0;
}
