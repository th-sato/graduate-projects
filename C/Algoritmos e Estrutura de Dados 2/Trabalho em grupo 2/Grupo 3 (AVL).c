#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct tree{
    int num;
    int pos;
    int h;
    struct tree *left;
    struct tree *right;
}tree;

int height (tree *T);
tree* rotate_left(tree *T);
tree* rotate_right(tree *T);
void fix_height(tree *T);
tree* createNode(int data,int pos);
tree *treeInsertion(tree *T, int data,int pos);
tree* rebalance_right(tree *T);
tree* rebalance_left(tree *T);

int height (tree *T){
    if (T==NULL) return 0;
    return T->h;
}

tree* rotate_left(tree *T){ //Rotação a esquerda
    tree *root = T->right;
    T->right = root->left;
    root->left = T;
    fix_height(root->left); //corrigir altura
    fix_height(root);
    return root;
}

tree* rotate_right(tree *T){ //rotação a direita
    tree *root = T->left;
    T->left = root->right;
    root->right = T;
    fix_height (root->right); //corrigir a altura
    fix_height (root);
    return root;
}

void fix_height(tree *T){
    int hl = height(T->left);
    int hr = height(T->right);
    if(hl>hr) T->h = hl+1;
    else T->h = hr+1;
}

tree* createNode(int data, int pos){ //aloca memória, inicializa um nó e retorna endereço deste espaço
    tree* node = (tree*)malloc(sizeof(tree));
    node->num = data;
    node->h = 1;
    node->pos = pos;
    node->left = NULL;
    node->right = NULL;
    return node;
}

tree* treeInsertion(tree *T, int data, int pos){ //insere um novo nó na árvore AVL e chama função para rebalanceamento no retorno das recursões.
    if(T == NULL) return createNode(data,pos);
    if(data < T->num){
        T->left=treeInsertion(T->left,data,pos);
        T = rebalance_left(T);
    }
    else{
        T->right=treeInsertion(T->right,data,pos);
        T = rebalance_right(T);
    }
    return T;
}

tree* rebalance_right(tree *T){ //verifica se a invariante de altura foi violada para o nó apontado por T, realiza as rotações adequadas em cada caso e corrige alturas.
    tree *r = T->right;
    int hl = height(T->left);
    int hr = height(T->right);
    if(hr>hl+1){
        if(height(r->right) > height(r->left)){ //caso 1
            T = rotate_left(T);
            return T;
        }
        else{ // caso 2
            T->right = rotate_right(T->right);
            T = rotate_left(T);
            return T;
        }
    }
    fix_height(T);
    return T;
}

int TreeSearch(tree* t, int k){
    tree* ptr = t;
    while(ptr != NULL){
        if(k < ptr->num){
            ptr = ptr->left;
        }
        else if (k > ptr->num)
            ptr = ptr->right;
        else return ptr->pos;
    }
    return 0;
}

tree* rebalance_left(tree *T){
    tree *r = T->left;
    int hl = height(T->left);
    int hr = height(T->right);
    if(hl>hr+1){
        if(height(r->left) > height(r->right)){ //caso 1
        T = rotate_right(T);
        return T;
        }
        else{ // caso 2
            T->left = rotate_left(T->left);
            T = rotate_right(T);
            return T;
        }
    }
    fix_height(T);
    return T;
}

int main(){
    int N, i, M, j, k, f;
    clock_t start_t, end_t, total_t;
    char* str = malloc(15*sizeof(char));
    FILE *arq = fopen("Time - Grupo 3 (AVL).txt", "w");
    float *I=(float*)malloc(3*sizeof(float)), *S=(float*)malloc(3*sizeof(float));
    for (j=1; j<=4; j++){
        for (k=1; k<=3; k++){
            printf("Input %i - Teste %i\n", j, k);
            sprintf(str, "input%i.txt", j);
            FILE* PFile = fopen(str,"r");
            fscanf(PFile,"%i",&N);
            sprintf(str,"Output%i_Teste%i.txt",j,k);
            FILE* p = fopen(str,"w");
            fprintf(p, "Input %i\n", j);
            fprintf(arq, "Input %i - Teste %i\n", j,k);
            start_t = clock();
            tree* t;
            fscanf(PFile, "%i",&f);
            t = treeInsertion(NULL,f,1);
            for(i=1;i<N;i++){
                fscanf(PFile,"%i",&f);
                t = treeInsertion(t,f,i+1);
            }
            end_t = clock();
            total_t = (double)(end_t - start_t);
            fprintf(p,"Insertion Time: %f\n", total_t/(float)CLOCKS_PER_SEC);
            fprintf(arq,"  Insertion Time: %f\n", total_t/(float)CLOCKS_PER_SEC);
            I[k-1] = total_t/(float)CLOCKS_PER_SEC;
            start_t = clock();
            fscanf(PFile,"%i",&M);
            fprintf(p, "Index numbers:\n");
            for(i=0;i<M;i++){
                fscanf(PFile,"%i",&f);
                fprintf(p, "%i\n", TreeSearch(t,f));
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
        fprintf(arq,"\n\n");
    }
    fclose(arq);
    return 0;
}
