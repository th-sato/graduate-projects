#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree{
    char *nome;
    int qtd_anos; //quantidade de anos que o profissional ganhou
    int *anos; //vetor dinâmico que guarda os anos vencidos
    int h; //altura
    struct tree *left;
    struct tree *right;
}TREE;

//Funções usadas
int height (TREE *T);
TREE* rotate_left(TREE *T);
TREE* rotate_right(TREE *T);
void fix_height(TREE *T);
TREE* createNode(char *data, int year);
TREE* treeInsertion(TREE *T, char *data, int year);
TREE* rebalance_right(TREE *T);
TREE* rebalance_left(TREE *T);
TREE* comparar(TREE* T, char* b);
void imprimir_anos(TREE* T);
int tam_inicial = 5;

int height (TREE *T){
    if (T==NULL) return 0;
    return T->h;
}

TREE* rotate_left(TREE *T){ //Rotação a esquerda
    TREE *root = T->right;
    T->right = root->left;
    root->left = T;
    fix_height(root->left); //corrigir altura
    fix_height(root);
    return root;
}

TREE* rotate_right(TREE *T){ //rotação a direita
    TREE *root = T->left;
    T->left = root->right;
    root->right = T;
    fix_height (root->right); //corrigir a altura
    fix_height (root);
    return root;
}

void fix_height(TREE *T){
    int hl = height(T->left);
    int hr = height(T->right);
    if(hl>hr) T->h = hl+1;
    else T->h = hr+1;
}

TREE* createNode(char *data, int year){ //aloca memória, inicializa um nó e retorna endereço deste espaço
    TREE* node = malloc(sizeof(TREE));
    node->anos = malloc(tam_inicial*sizeof(int));
    node->nome = malloc(16*sizeof(char));
    node->qtd_anos=0;
    node->anos[node->qtd_anos] = year;
    node->qtd_anos++;
    strcpy(node->nome, data);
    node->h = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TREE* treeInsertion(TREE *T, char *data, int year){ //insere um novo nó na árvore AVL e chama função para rebalanceamento no retorno das recursões.
    if(T == NULL) return createNode(data, year);
    else if (strcmp(data, T->nome)==0){
        T->qtd_anos++;
        T->anos = realloc(T->anos, (T->qtd_anos)*sizeof(int));
        T->anos[T->qtd_anos-1] = year;
    }
    else if(strcmp(data, T->nome)<0){
        T->left=treeInsertion(T->left,data,year);
        T = rebalance_left(T);
    }
    else{
        T->right=treeInsertion(T->right,data,year);
        T = rebalance_right(T);
    }
    return T;
}

TREE* rebalance_right(TREE *T){ //verifica se a invariante de altura foi violada para o nó apontado por T, realiza as rotações adequadas em cada caso e corrige alturas.
    TREE *r = T->right;
    int hl = height(T->left);
    int hr = height(T->right);
    if(hr>hl+1){
        if(height(r->right) > height(r->left)){ //caso 1
            T = rotate_left(T);
            return T;
        } else{ // caso 2
            T->right = rotate_right(T->right);
            T = rotate_left(T);
            return T;
        }
    }
    fix_height(T);
    return T;
}

TREE* rebalance_left(TREE *T){
    TREE *r = T->left;
    int hl = height(T->left);
    int hr = height(T->right);
    if(hl>hr+1){
        if(height(r->left) > height(r->right)){
            T = rotate_right(T);
            return T;
        } else{
            T->left = rotate_left(T->left);
            T = rotate_right(T);
            return T;
        }
    }
    fix_height(T);
    return T;
}

TREE* comparar(TREE* T, char* b){
    if(T == NULL) return NULL;
    else if (strcmp(b, T->nome)==0){
        return T;
    }
    else if(strcmp(b, T->nome)<0){
        return comparar(T->left,b);
    }
    else{
        return comparar(T->right,b);
    }
}

void imprimir_anos(TREE* T){
    printf("%d ", (T->h));
    int i;
    for (i=0; i<(T->qtd_anos);i++){
        printf("%d ", T->anos[i]);
    }
    printf("\n");
}

int main(){
    int a, c, n=16; //a: operação
    TREE *nomes = NULL;
    TREE *d=NULL; //d: arvore auxiliar
    scanf("%d", &a);
    char b[n]; //b:guardar a string temporariamente
    while(a!=0){
        if(a==1){
            scanf("%s %d", &b, &c);
            nomes = treeInsertion(nomes, b, c);
        }
        else if (a==2){
            scanf("%s", &b);
            d=comparar(nomes, b);
            if (d==NULL) printf("0\n");
            else imprimir_anos (d);
        }
        scanf("%d", &a);
    }
    return 0;
}
