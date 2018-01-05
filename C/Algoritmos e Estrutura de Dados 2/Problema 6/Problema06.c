#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produtos{
    int produto;
    struct produtos *prox;
}produtos;

typedef struct pos_prod{
    produtos *inicio, *fim;
}pos_prod;

typedef struct elementos_lista{
    char *nome;
    pos_prod *products; //Quantidade de produtos adquiridos pelo cliente
    struct elementos_lista *prox;
}elementos_lista;

typedef struct lista{
    elementos_lista *inicio, *fim;
}lista;

int hash (char *v, int m, int b){
    int h=0, i;
    for (i=0; i<strlen(v); i++){
        h = (h*b + v[i]) % m;
    }
    return h;
}

lista* inicializa_lista (lista* l){
    l->inicio = NULL;
    l->fim = NULL;
    return l;
}

lista* cria_lista(lista *l, char *nome, int produto){
    elementos_lista *aux = malloc(sizeof(elementos_lista));
    aux->prox = malloc(sizeof(elementos_lista));
    aux->nome = malloc(15*sizeof(char));
    strcpy (aux->nome, nome);
    aux->prox = NULL;
    insere_produtos (aux, produto);
    l->inicio = aux;
    l->fim = aux;
    return l;
}

void insere_produtos (elementos_lista *l, int produto){
    l->products = malloc(sizeof(pos_prod));
    l->products->inicio = malloc(sizeof(produtos));
    l->products->inicio->prox = malloc(sizeof(produtos));
    l->products->fim = malloc(sizeof(produtos));
    l->products->fim->prox = malloc(sizeof(produtos));
    l->products->inicio->produto = produto;
    l->products->inicio->prox = NULL;
    l->products->fim->produto = produto;
    l->products->fim->prox = NULL;
}

void insere_produtos_novos (pos_prod *l, int produto){
    produtos* aux = malloc(sizeof(produtos));
    aux->prox = malloc(sizeof(produtos));
    aux->produto = produto;
    aux->prox = NULL;
    l->fim->prox = aux;
    l->fim = aux;
    if(l->inicio->prox==NULL)l->inicio->prox = l->fim;
}

lista* lista_insere (lista *l, char *nome, int produto){
    elementos_lista *aux = malloc(sizeof(elementos_lista));
    elementos_lista *aux2 = malloc(sizeof(elementos_lista));
    elementos_lista *aux3 = malloc(sizeof(elementos_lista));
    if (l->inicio==NULL && l->fim==NULL) { //Lista vazia
        l=cria_lista(l, nome, produto);
    }
    else if (strcmp(l->fim->nome, nome)<0){ //Nome depois do final da lista
        aux->nome = malloc(15*sizeof(char));
        aux->prox = malloc(sizeof(elementos_lista));
        strcpy(aux->nome, nome);
        aux->prox = NULL;
        insere_produtos (aux, produto);
        l->fim->prox = aux;
        l->fim = aux;
        if (l->inicio->prox==NULL)l->inicio->prox = l->fim;
    }
    else if (strcmp(l->inicio->nome, nome)>0){ //Nome antes do começo da lista
        aux->nome = malloc(15*sizeof(char));
        aux->prox = malloc(sizeof(elementos_lista));
        strcpy(aux->nome, nome);
        aux->prox = l->inicio;
        insere_produtos(aux, produto);
        l->inicio = aux;
        if (l->inicio->prox==NULL) l->inicio->prox = l->fim;
    }
    else if (strcmp(l->inicio->nome, nome)==0){ //Nome está no início da lista
        insere_produtos_novos(l->inicio->products, produto);
    }
    else if (strcmp(l->fim->nome, nome)==0){ //Nome está no final da lista
        insere_produtos_novos(l->fim->products, produto);
    }
    else{ //O nome está entre o início e o final da lista
        aux = l->inicio;
        while(strcmp(l->inicio->nome, nome)<0){
            aux2 = l->inicio;
            l->inicio = l->inicio->prox;
        }
        if (strcmp(l->inicio->nome,nome)==0){ //Nome encontrado
            insere_produtos_novos(l->inicio->products, produto);
            l->inicio = aux;
        }
        else { //Nome não encontrado
            aux3->nome = malloc(15*sizeof(char));
            strcpy (aux3->nome, nome);
            aux3->prox = malloc(sizeof(elementos_lista));
            insere_produtos(aux3, produto);
            aux3->prox = l->inicio;
            aux2->prox = aux3;
            l->inicio = aux2;
            l->inicio = aux;
        }
    }
    return l;
}

produtos* busca_lista (lista *l, char *nome){
    elementos_lista *aux = (elementos_lista*)malloc(sizeof(elementos_lista));
    if(l->inicio==NULL) return NULL;
    else if(strcmp(l->inicio->nome, nome)==0){
        return l->inicio->products->inicio;
    }
    else if (strcmp(l->fim->nome, nome)==0){
        return l->fim->products->inicio;
    }
    else if (strcmp(l->inicio->nome, nome)>0 || strcmp(l->fim->nome, nome)<0){
        return NULL;
    }
    else{
        aux=l->inicio;
        while(strcmp(aux->nome, nome)<0){
            aux = aux->prox;
        }
        if(strcmp(aux->nome, nome)==0){
            return aux->products->inicio;
        }
        else return NULL;
    }
}

void imprimir_produtos(produtos *t){
    if (t==NULL) printf("0");
    while (t!=NULL){
        printf("%d ", t->produto);
        t = t->prox;
    }
    printf("\n");
}

void imprimir_nomes(lista *l){
    elementos_lista *aux = l->inicio;
    while (aux!=NULL){
        printf("%s ", aux->nome);
        aux = aux->prox;
    }
    //free(aux);
    printf("\n");
}

int main(){
    int a, b, d, e = 128; //a: operação / b: valor de m / d: nova quantidade de produtos adquiridos pelo cliente / e: base 128 (ASCII)
    scanf("%d", &b);
    scanf("%d", &a);
    char *c = malloc(15*sizeof(char)); //Guardar o nome temporariamente
    //char c[15];
    int f; //Posição a ser colocado o nome
    //lista *v = malloc(b*sizeof(lista));
    lista **v = (lista**)malloc(b*sizeof(lista*));
    int i;
    for (i=0; i<b; i++){
        v[i] = (lista*)malloc(sizeof(lista));
        v[i] = inicializa_lista(v[i]);
    }
    produtos *t = malloc(sizeof(produtos));
    while(a!=0){
        if(a==1){
            scanf("%s %d", c, &d);
            f = hash (c, b, e);
            v[f] = lista_insere(v[f], c, d);
        }
        else if (a==2){
            scanf("%s", c);
            f = hash (c, b, e);
            t = busca_lista(v[f], c);
            imprimir_nomes(v[f]);
            imprimir_produtos(t);
        }
        scanf("%d", &a);
    }
    return 0;
}
