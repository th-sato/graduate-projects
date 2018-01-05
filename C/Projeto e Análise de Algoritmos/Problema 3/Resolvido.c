#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ponto{
    int x, y;
}ponto;

int build_candidates_permutation (int *vetor, int N, int *vetor2){
    int i, num_cand=0;
    bool *v = (bool*)malloc(N*sizeof(bool)); //Quem está na permutação?
    //print_solution(vetor, N);
    for(i=0; i<N; i++) v[i] = false;
    for(i=0; i<N; i++){
        if (vetor[i]!=0) v[vetor[i]-1] = true; //Não está disponível para a permutação
        //printf("%d ", vetor[i]);
    }
    //printf("\n");
    //print_solution(v, N);;
    for(i=0; i<N; i++){
        if (v[i]==false){
            vetor2[num_cand++] = i+1; //Guarda o número do candidato a permutação
            //printf("%d\n", vetor2[num_cand-1]);
        }
    }
    //print_solution(vetor2, num_cand);
    //printf("\n\n");
    return num_cand;
}

bool is_a_solution (int *vetor, int n){
    int i;
    for (i=0; i<n; i++){
        if (vetor[i]==0) return false;
    }
    return true;
}

void print_solution(int *vetor, int k){
    int i;
    for (i=0; i<k; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void backtrack (int *vetor, int k, int input){ //input: pode ser o tamanho do problema
    int i, num_cand, *vetor2 =(int*)malloc(input*sizeof(int));
    if (is_a_solution(vetor, input)){//Teste se os primeiros k elementos do vetor a formam uma solução para um dado problema.
        print_solution(vetor, input); //Imprimir a solução.
    }
    else{
        num_cand = build_candidates_permutation(vetor, input, vetor2); //Constroi o vetor vetor2 com todos possíveis candidatos para a k-ésima posição do vetor A.
        for(i=0; i<num_cand; i++){
            if(vetor[k]==0){ //Está disponível? Se for zero, sim.
                vetor[k] = vetor2[i];
                //printf("%d\n", vetor2[i]);
                //make_move(vetor, k, input); //Acrescenta um novo elemento a solução.
                backtrack(vetor, k, input); //Chamada recursiva
                //print_solution(vetor, input);
                //printf("%d %d\n", k, input);
                vetor[k] = 0;
                //unmake_move(vetor, k, input);//Desfaz a adição do novo elemento para a busca por novas soluções que não incluam o elementos escolhido no passos atual.
                //if(finished) return; //Termina antes
            }
            else{
                k++;
                i--;
            }
        }
        //printf("\n\n");
    }
}

int main(){
    int N, M, i;
    scanf("%d %d", &N, &M);
    int *vetor = (int*)calloc(N, sizeof(int));
    ponto *p = (ponto*)malloc(M*sizeof(ponto));
    for(i=0; i<M; i++){
        scanf("%d %d", &p[i].x, &p[i].y);
        vetor[(p[i].y)-1] = p[i].x;
    }
    backtrack(vetor, 0, N);
    return 0;
}
