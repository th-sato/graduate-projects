#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
	int *vetor;
	int numero;
	int atual;
}elemento;

void Min_Heap(elemento **vetor, int i, int heap_size){
    int l = 2*i + 1; //esquerda
    int r = 2*i + 2; //direita
    //printf("%d %d %d\n", l, r, heap_size);
    int menor;
    elemento *aux;
    if (l < heap_size && vetor[l]->vetor[vetor[l]->atual] < vetor[i]->vetor[vetor[i]->atual]) menor = l; //Menor está a esquerda
    else menor = i;
    if (r < heap_size && vetor[r]->vetor[vetor[r]->atual] < vetor[menor]->vetor[vetor[menor]->atual]) menor = r;
    if (menor!=i){
        aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;
        Min_Heap(vetor, menor, heap_size);
    }
}

void Build_Min_Heap(elemento **vetor, int n){
    int i;
    for (i = n/2; i>=0; i--){
        Min_Heap(vetor, i, n);
    }
}

int Heap_Atualiza(elemento **vetor, int i, int n){
    if (n>0){
		if (vetor[i]->atual < vetor[i]->numero-1){
			vetor[i]->atual++;
			Min_Heap(vetor, 0, n);
		}
		else {
			vetor[0] = vetor [n-1];
			n--;
			Min_Heap(vetor, 0, n);
		}
		return n;
	}
}

void Heapsort (elemento **vetor, int n){
    Build_Min_Heap (vetor, n);
    int i, heap_size = n;
    elemento *aux;
    for (i=n-1; i>0; i--){
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        heap_size--;
        Min_Heap(vetor, 0, heap_size);
    }
}

int main(){
	int K, i, j, k, a;
    scanf("%d %d", &K, &i);
    elemento **v = (elemento**)malloc(K*sizeof(elemento*));
    for (j=0; j<K; j++){
		v[j] = (elemento*)malloc(sizeof(elemento));
        scanf("%d", &a);
        v[j]->vetor = (int*)malloc(a*sizeof(int));
        v[j]->numero = a;
        v[j]->atual = 0;
        for (k=0; k<a; k++){
            scanf("%d", &v[j]->vetor[k]);
        }
        if (a==0){
			j--;
			K--;
        }
    }
	Build_Min_Heap(v, K);
	for (j=0; j<i-1; j++){
		K = Heap_Atualiza(v, 0, K);
	}
	//Impressao
	Heapsort(v, K);
	for (j=K-1; j>=0; j--){
        printf("%d ", v[j]->vetor[v[j]->atual]);
	}
	return 0;
}
