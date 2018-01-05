#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node{
    int x;
    int pos;
    struct Node* next;
}Node;

Node* NewNode(int x, int pos){
    Node* c = malloc(sizeof(Node));
    c->next = NULL;
    c->x = x;
    c->pos = pos;
    return c;
}

int hash(int x, int m){
    return x%m;
}

void Insert(Node** l, int x, int i,int m){
    Node* c;
    int pos = hash(x,m);
    Node* ptr = l[pos];
    Node*lptr = NULL;
    if(ptr == NULL ) {
        l[pos] = NewNode(x,i);
        return;
    }
    while(ptr != NULL){
        if(x < ptr->x){
            c = NewNode(x,i);
            c->next = ptr;
            if(lptr!= NULL) lptr->next = c;
            else l[pos] = c;
            return;
        }
        lptr = ptr;
        ptr = ptr->next;
    }
    lptr->next = NewNode(x,i);
}

int Search(Node** l, int x,int m){
    int pos = hash(x,m);
    Node* ptr = l[pos];
    while(ptr != NULL){
        if(ptr->x==x){
            return ptr->pos;
        }
        else if(ptr->x > x) return 0;
        ptr = ptr->next;
    }
    return 0;
}

int main(){
    int m, mod, n, i, a, b, j, k;
    mod = 10009;
    Node** l = malloc(mod*sizeof(Node));
    clock_t start_t, end_t, total_t;
    char* str = malloc(15*sizeof(char));
    FILE *arq = fopen("Time - Grupo 4 (Tabela Hash com Encadeamento).txt", "w");
    float *I=(float*)malloc(3*sizeof(float)), *S=(float*)malloc(3*sizeof(float));
    for (j=1; j<=4; j++){
        for (k=1; k<=3; k++){
            for(i=0;i<mod;i++){
                l[i] = NULL;
            }
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
                Insert(l,a,i+1,mod);
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
                fprintf(p, "%i\n", Search(l,b,mod));
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
