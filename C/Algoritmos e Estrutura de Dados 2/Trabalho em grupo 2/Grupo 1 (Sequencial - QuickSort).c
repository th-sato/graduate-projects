#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct local{
    int info;
    int pos;
}local;

void Swap(local* A, int j, int i){
    local x  = A[j];
    A[j] = A[i];
    A[i] = x;
}

int Partition(local*A,int b, int e){
    int Pivot = b + rand()%(e-b);
    int i,marker;
    Swap(A,Pivot,e);
    marker = b-1;
    for(i=b;i<e;i++){
        if(A[i].info < A[e].info){
            marker++;
            Swap(A,marker,i);
        }
    }
    Swap(A,e,marker+1);
    return marker+1;
}

void Quicksort(local *A, int b, int e){
    int marker;
    if(b<e){
        marker = Partition(A,b,e);
        Quicksort(A,b,marker-1);
        Quicksort(A,marker+1,e);
    }
}

PrintArray(int* A, int N){
    int i;
    for (i=0;i<N;i++)
        printf("\n%i",A[i]);
}

int SequentialSearch(local *v, int N, int value){
    int i;
    if(value > v[N-1].info || value < v[0].info){
        return 0;
    }
    for (i=0; i<N; i++){
        if (v[i].info==value) return v[i].pos;
        else if (v[i].info>value) return 0;
    }
    return 0;
}

int main(){
    local *A;
    int N, M, i, j, f, a, k;
    clock_t start_t, end_t, total_t;
    char *str = malloc(15*sizeof(char));
    FILE *arq = fopen("Time - Grupo 1 (Sequencial - QuickSort).txt", "w");
    float *I=(float*)malloc(3*sizeof(float)), *S=(float*)malloc(3*sizeof(float));
    for (j=1; j<=4; j++){
        for (k=1; k<=3; k++){
            printf("Input %i - Teste %i\n", j, k);
            sprintf(str, "input%i.txt", j);
            FILE* PFile = fopen(str,"r");
            fscanf(PFile,"%i",&N);
            A = malloc(sizeof(local)*N);
            sprintf(str,"Output%i_Teste%i.txt",j,k);
            FILE* p = fopen(str,"w");
            fprintf(p, "Input %i\n", j);
            fprintf(arq, "Input %i - Teste %i\n", j,k);
            start_t = clock();
            for(i=0;i<N;i++){
                fscanf(PFile,"%i", &A[i].info);
                A[i].pos = i+1;
            }
            Quicksort(A, 0, N-1);
            end_t = clock();
            total_t = (double)(end_t - start_t);
            fprintf(p,"Insertion Time: %f\n", total_t/(float)CLOCKS_PER_SEC);
            fprintf(arq,"  Insertion Time: %f\n", total_t/(float)CLOCKS_PER_SEC);
            I[k-1] = total_t/(float)CLOCKS_PER_SEC;
            start_t = clock();
            fscanf(PFile,"%i", &M);
            fprintf(p, "Index numbers:\n");
            for(i=0;i<M;i++){
                fscanf(PFile,"%i",&f);
                a = SequentialSearch(A, N, f);
                fprintf(p, "%d\n", a);
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
