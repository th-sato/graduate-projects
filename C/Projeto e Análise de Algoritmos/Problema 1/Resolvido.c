#include <stdio.h>
#include <stdlib.h>

int lucroDivisao(int *vetor, int low, int mid, int high){
	int lucro;
	int left_sum = -999999, sum = 0, i;
	for (i=mid; i>=low; i--){
		sum += vetor[i];
		if (sum > left_sum){
			left_sum = sum;
		}
	}
	int right_sum = -999999;
	sum = 0;
	for (i=mid+1; i<=high; i++){
		sum += vetor[i];
		if (sum > right_sum){
			right_sum = sum;
		}
	}
	lucro = left_sum + right_sum;
	return lucro;
}

int lucroMaximo (int *receita, int inicio, int N){
	int mid, esquerda, direita, divisao;
	if (inicio==N) return (receita[inicio]); //Um elemento
	else {
		mid = (inicio + N)/2;
		esquerda = lucroMaximo (receita, inicio, mid);
		direita = lucroMaximo(receita, mid+1, N);
		divisao = lucroDivisao (receita, inicio, mid, N);
		if (esquerda >= direita && esquerda >= divisao) return esquerda;
		else if (direita >= esquerda && direita >= divisao) return direita;
		else return divisao;
	}
}

int main(){
	int N, C, i, *receita, lucro;
	//N: número de dia que Christopher poderá decidir sobre a exibição do filme.
	//C: Taxa a ser paga para cada dia em que o filme ficou em exbição.
	//Os dias de exibição devem consecutivos.
	scanf("%d %d", &N, &C);
	receita = (int*)malloc(N*sizeof(int));
	for (i=0; i<N; i++){
		scanf("%d", &receita[i]);
		receita[i]-=C;
	}
	lucro = lucroMaximo(receita, 0, N-1);
	if (lucro > 0) printf("%d\n", lucro);
	else  printf("0\n");
	return 0;
}
