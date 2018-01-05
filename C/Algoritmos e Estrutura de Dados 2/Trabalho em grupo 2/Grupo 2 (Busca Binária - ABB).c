#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct arv{
    int info;
    int pos;
    struct arv *esq, *dir;
}arv;

typedef struct raizArv{
    arv *raiz;
}raizArv;

void inicializaArv (raizArv *arv){
    arv->raiz = NULL;
}

arv* criaNo(int num, int posicao){
    arv *no = (arv*)malloc(sizeof(arv));
    no->info = num;
    no->pos = posicao;
    no->dir = NULL;
    no->esq = NULL;
    return no;
}

arv* add_elemento (arv *arvore, int info, int pos){
    if (arvore==NULL){
        arvore = criaNo (info, pos);
    }
    else if (info < arvore->info){
        arvore->esq = add_elemento(arvore->esq, info, pos);
        //if (arvore->esq!=NULL) add_elemento(arvore->esq, info, pos);
        //else arvore->esq = criaNo(info, pos);
    }
    else{
        arvore->dir = add_elemento(arvore->dir, info, pos);
        //if(arvore->dir!=NULL) add_elemento(arvore->dir, info, pos);
        //else arvore->dir = criaNo(info, pos);
    }
    return arvore;
}

int BinarySearch(arv *v, int value){
    if (v==NULL) return 0;
    else if (value == v->info) return v->pos;
    else if (value < v->info) BinarySearch(v->esq, value);
    else BinarySearch(v->dir, value);
}

int main(){
    raizArv *arvore = (raizArv*)malloc(sizeof(raizArv));
    int m, n, i, a, b, j, k;
    clock_t start_t, end_t, total_t;
    char *str = malloc(15*sizeof(char));
    FILE *arq = fopen("Time - Grupo 2 (Busca Binária - ABB).txt", "w");
    float *I=(float*)malloc(3*sizeof(float)), *S=(float*)malloc(3*sizeof(float));
    for (j=1; j<=4; j++){
        for (k=1; k<=3; k++){
            inicializaArv(arvore);
            printf("Input %i - Teste %i\n", j, k);
            sprintf(str, "input%i.txt", j);
            FILE* PFile = fopen(str,"r");
            fscanf(PFile,"%i",&n);
            sprintf(str,"Output%i_Teste%i.txt",j,k);
            FILE* p = fopen(str,"w");
            fprintf(p, "Input %i\n", j);
            fprintf(arq, "Input %i - Teste %i\n", j,k);
            start_t = clock();
            for (i=0; i<n; i++){
                fscanf(PFile, "%d", &a);
                arvore->raiz = add_elemento (arvore->raiz, a, i+1);
            }
            end_t = clock();
            total_t = (double)(end_t - start_t);
            fprintf(p,"Insertion Time: %f\n", total_t/(float)CLOCKS_PER_SEC);
            fprintf(arq,"  Insertion Time: %f\n", total_t/(float)CLOCKS_PER_SEC);
            I[k-1] = total_t/(float)CLOCKS_PER_SEC;
            start_t = clock();
            fscanf(PFile,"%i", &m);
            fprintf(p, "Index numbers:\n");
            for (i=0; i<m; i++){
                fscanf(PFile, "%d", &b);
                b = BinarySearch(arvore->raiz, b);
                fprintf(p, "%d\n", b);
            }
            fprintf(p, "Finish\n");
            fclose(PFile);
            end_t = clock();
            total_t = (double)(end_t - start_t);
            fprintf(p,"Search Time: %f\n", total_t/(float)CLOCKS_PER_SEC);
            fprintf(arq,"  Search Time: %f\n", total_t/(float)CLOCKS_PER_SEC);
            S[k-1] = total_t/(float)CLOCKS_PER_SEC;
            fclose(p);
        }
        fprintf(arq,"\n");
        fprintf(arq, "Mean - Input %i:\n", j);
        for(k=1; k<3; k++){
            I[k]+=I[k-1];
            S[k]+=S[k-1];
        }
        fprintf(arq, "  Insertion Time: %f\n  Search Time: %f\n", (I[2]/3), (S[2]/3));
        fprintf(arq, "\n\n");
    }
    fclose(arq);
    return 0;
}
