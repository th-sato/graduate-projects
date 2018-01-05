#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct local{
    int info;
    int pos;
}local;

void merge (local *v, int p, int q, int r){
    int i=p, j=q, k;
    local *t = (local*)malloc((r-p)*sizeof(local));
    for(k=0; i<q && j<r; k++){
        if(v[i].info <= v[j].info){
            t[k] = v[i];
            i++;
        }
        else{
            t[k] = v[j];
            j++;
        }
    }
    while (i<q){
        t[k] = v[i];
        k++; i++;
    }
    while (j<r){
        t[k]=v[j];
        k++; j++;
    }
    for(i=p; i<r; i++) v[i] = t[i-p];
    free(t);
}

void mergesort (local *v, int p, int r){
    int q;
    if(p < r-1){
        q = (p+r)/2;
        mergesort(v, p, q);
        mergesort(v, q, r);
        merge(v, p, q, r);
    }
}

int BinarySearch(local *v, int value, int n){
    int first = 0, end = n-1, mid;
    while (first<=end){
        mid = (first+end)/2;
        if(v[mid].info == value) return v[mid].pos;
        if(v[mid].info < value) first = mid+1;
        else end = mid-1;
    }
    return 0;
}

int main(){
    int i, j, k, m, n, a;
    local *v;
    clock_t start_t, end_t, total_t;
    char *str = malloc(15*sizeof(char));
    FILE *arq = fopen("Time - Grupo 2 (Busca Binária - Merge).txt", "w");
    float *I=(float*)malloc(3*sizeof(float)), *S=(float*)malloc(3*sizeof(float));
    for (j=1; j<=4; j++){
        for (k=1; k<=3; k++){
            printf("Input %i - Teste %i\n", j, k);
            sprintf(str, "input%i.txt", j);
            FILE* PFile = fopen(str,"r");
            fscanf(PFile,"%i",&n);
            v = (local*)malloc(n*sizeof(local));
            sprintf(str,"Output%i_Teste%i.txt",j,k);
            FILE* p = fopen(str,"w");
            fprintf(p, "Input %i\n", j);
            fprintf(arq, "Input %i - Teste %i\n", j,k);
            start_t = clock();
            for (i=0; i<n; i++){
                fscanf(PFile, "%d", &v[i].info);
                v[i].pos = i+1;
            }
            mergesort(v, 0, n);
            end_t = clock();
            total_t = (double)(end_t - start_t);
            fprintf(p,"Insertion Time: %f\n", total_t/(float)CLOCKS_PER_SEC);
            fprintf(arq,"  Insertion Time: %f\n", total_t/(float)CLOCKS_PER_SEC);
            I[k-1] = total_t/(float)CLOCKS_PER_SEC;
            start_t = clock();
            fscanf(PFile,"%i", &m);
            fprintf(p, "Index numbers:\n");
            for(i=0; i<m; i++){
                fscanf(PFile, "%d", &a);
                fprintf(p, "%d\n", BinarySearch(v, a, n));
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
