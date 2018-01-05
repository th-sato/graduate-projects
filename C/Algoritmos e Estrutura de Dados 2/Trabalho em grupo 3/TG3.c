#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct buffer_no{
    int info;
    struct buffer_no *prox;
}buffer_no;

typedef struct buffer{
    buffer_no *inicio, *fim;
}buffer;

void inicializa_fila (buffer *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
}

void remove_fila(buffer *fila){
    buffer_no *aux;
    if(fila->inicio==fila->fim && fila->inicio!=NULL){
        fila->fim = NULL;
        fila->inicio = NULL;
    }
    else if(fila->inicio!=NULL){
        aux=fila->inicio;
        fila->inicio=aux->prox;
    }
}

void inserir_fila(buffer *fila, int valor){
    buffer_no *no = (buffer_no*)malloc(sizeof(buffer_no));
    no->info = valor;
    if(fila->inicio == NULL){
        no->prox = NULL;
        fila->inicio = no;
        fila->fim = no;
    }
    else {
        fila->fim->prox = no;
        fila->fim = no;
        fila->fim->prox = NULL;
    }
}

void merge (int *v, int p, int q, int r){
    int i=p, j=q, k;
    int *t = (int*)malloc((r-p)*sizeof(int));
    for(k=0; i<q && j<r; k++){
        if(v[i] <= v[j]){
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

void mergesort (int *v, int p, int r){
    int q;
    if(p < r-1){
        q = (p+r)/2;
        mergesort(v, p, q);
        mergesort(v, q, r);
        merge(v, p, q, r);
    }
}

void imprimir_arquivo (int *v, int M, int j, int cont){ //Gerar arquivos para vetores
    int k;
    char *str = (char*)malloc(40*sizeof(char));
    sprintf(str, "output%i_parte1_intermediate%i.txt", j, cont);
    FILE *arq = fopen (str, "w");
    for(k=0; k<M; k++){
        fprintf(arq, "%d\n", v[k]);
    }
    fclose(arq);
}

void imprimir_arquivo_fila (buffer *fila, int j, int processo, int cont){
    buffer *aux = (buffer*)malloc(sizeof(buffer));
    aux = fila;
    char *str = (char*)malloc(40*sizeof(char));
    sprintf (str, "output%i_parte%i_intermediate%i.txt", j, processo, cont);
    FILE *arq = fopen (str, "a");
    while (aux->inicio!=NULL){
        fprintf(arq, "%d\n", aux->inicio->info);
        aux->inicio = aux->inicio->prox;
    }
    free(aux);
    fclose (arq);
}

int gera_arquivos (FILE *arq, int M, int j){//Leitura de dados e ordenamento
    int i, valor, *v, cont=0;
    v = (int*)calloc(M, sizeof(int));
    for (i=0; feof(arq)==0; i++){ //feof = indica o fim do arquivo
        fscanf(arq, "%i\n", &valor);
        v[i] = valor;
        if(i==M-1){
            cont++;
            mergesort(v, 0, M);
            imprimir_arquivo(v, M, j, cont);
            i=-1;
        }
    }
    if (i!=0){
        cont++;
        mergesort(v, 0, i-1);
        imprimir_arquivo(v, i, j, cont);
    }
    return cont;
}

buffer* intercalar_filas(buffer *fila1, buffer *fila2){
    buffer *aux = (buffer*)malloc(sizeof(buffer));
    if (fila1->fim->info < fila2->inicio->info){
        aux = fila1;
        aux->fim->prox = fila2->inicio;
        aux->fim = fila2->fim;
        return aux;
    }
    else if (fila1->inicio->info > fila2->fim->info){
        aux = fila2;
        aux->fim->prox = fila1->inicio;
        aux->fim = fila1->fim;
        return aux;
    }
    inicializa_fila(aux);
    while (fila1->inicio!=NULL && fila2->inicio!=NULL){
        if (fila1->inicio->info > fila2->inicio->info){
            inserir_fila(aux, fila2->inicio->info);
            remove_fila(fila2);
        }
        else {
            inserir_fila(aux, fila1->inicio->info);
            remove_fila(fila1);
        }
    }
    return aux;
}

buffer* gerar_filas (FILE *arq, int M){
    int valor, cont=0;
    buffer *fila = (buffer*)malloc(sizeof(buffer));
    inicializa_fila(fila);
    while (cont<(M/2) || feof(arq)==0){
        fscanf(arq, "%d\n", &valor);
        inserir_fila(fila, valor);
        cont++;
    }
    return fila;
}

void leitura_ordenamento_arquivo(FILE *arq, FILE *arq2, int M, int j, int processo, int impressao){
    buffer *fila1 = (buffer*)malloc(sizeof(buffer)), *fila2 = (buffer*)malloc(sizeof(buffer)), *aux = (buffer*)malloc(sizeof(buffer));
    processo++;
    while (feof(arq)==0 || feof(arq2)==0){
        if (feof(arq)==0 && feof(arq2)==0){
            fila1 = gerar_filas (arq, M);
            fila2 = gerar_filas (arq2, M);
            aux = intercalar_filas(fila1, fila2);
            imprimir_arquivo_fila(aux, j, processo, impressao);
            if (fila1->inicio==NULL && fila2->inicio!=NULL){
                imprimir_arquivo_fila(fila2, j, processo, impressao);
                free(fila2);
            }
            else if (fila2->inicio==NULL && fila1->inicio!=NULL){
                imprimir_arquivo_fila(fila1, j, processo, impressao);
                free(fila1);
            }
        }
        else if (feof(arq)==0){
            fila1 = gerar_filas (arq, M);
            imprimir_arquivo_fila(fila1, j, processo, impressao);
            free(fila1);
        }
            else if (feof(arq2)==0){
                fila2 = gerar_filas (arq2, M);
                imprimir_arquivo_fila(fila2, j, processo, impressao);
                free(fila2);
            }
    }
}

int intercalar (int qtd_arquivos, int M, int j, int processo){
    int cont=0, i, valor;
    char *str = (char*)malloc(40*sizeof(char));
    char *str2 = (char*)malloc(40*sizeof(char));
    buffer *aux1, *aux2;
    if(qtd_arquivos%2==0){
        for (i=1; i<=qtd_arquivos; i+=2){
            sprintf(str, "output%i_parte%i_intermediate%i.txt", j, processo, i);
            sprintf(str2, "output%i_parte%i_intermediate%i.txt", j, processo, i+1);
            FILE *arq = fopen(str, "r");
            FILE *arq2 = fopen(str2, "r");
            cont++;
            leitura_ordenamento_arquivo(arq, arq2, M, j, processo, cont);
            fclose(arq);
            fclose(arq2);
            remove(str);
            remove(str2);
        }
    }
    else {
        for (i=1; i<qtd_arquivos; i+=2){
            sprintf(str, "output%i_parte%i_intermediate%i.txt", j, processo, i);
            sprintf(str2, "output%i_parte%i_intermediate%i.txt", j, processo, i+1);
            FILE *arq = fopen(str, "r");
            FILE *arq2 = fopen(str2, "r");
            cont++;
            leitura_ordenamento_arquivo(arq, arq2, M, j, processo, cont);
            fclose(arq);
            fclose(arq2);
            remove(str);
            remove(str2);
        }
        sprintf(str, "output%i_parte%i_intermediate%i.txt", j, processo, qtd_arquivos);
        FILE *arq = fopen(str, "r");
        qtd_arquivos = (qtd_arquivos/2)+1;
        sprintf(str2, "output%i_parte%i_intermediate%i.txt", j, processo+1, qtd_arquivos);
        FILE *arq2 = fopen(str2, "w");
        while (feof(arq)==0){ //feof = indica o fim do arquivo
            fscanf(arq, "%i\n", &valor);
            fprintf(arq2, "%i\n", valor);
        }
        fclose(arq);
        fclose(arq2);
        remove(str);
        cont++;
    }
    return cont;
}

int main (void){
    int M=5000, j, i, num_arq, cont;
    //num_arq: numero de arquivos
    //cont: quantidade de vezes que cada registro é lido e escrito no disco.
    clock_t start_t, end_t, total_t;
    char *str = (char*)malloc(20*sizeof(char));
    char *str2 = (char*)malloc(20*sizeof(char));
    sprintf(str2, "Dados.txt");
    FILE *arq2 = fopen (str2, "w");
    fprintf(arq2,"Tempos de execução e quantidade de vezes que cada registro é lido e escrito no disco:\n");
    //Leitura
    for(j=1; j<4; j++){
        fprintf(arq2,"  * Entrada %i:\n", j);
        printf("Input%i\n", j);
        start_t = clock();
        cont=0;
        sprintf(str, "input%i.txt", j);
        FILE *arq = fopen(str, "r");
        num_arq = gera_arquivos(arq, M, j); //Divide o arquivo
        fclose(arq);
        while(num_arq!=1){
            cont++;
            num_arq = intercalar(num_arq, M, j, cont);
        }
        cont++;
        end_t = clock();
        total_t = (double)(end_t - start_t);
        fprintf(arq2,"     * Tempo de execução: %f\n", total_t/(float)CLOCKS_PER_SEC);
        fprintf(arq2,"     * Quantidade de vezes que cada registro é lido e escrito no disco: %i\n", cont);
        fprintf(arq2, "\n\n");
    }
    fclose(arq2);
    return 0;
}
