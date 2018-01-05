#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct mutacao{
    int valor;
    int qtd_mutacao;
}mutacao;

int qtd = 2001;

int maiorSubsequencia (char *str1, char *str2){
    int i, j, maior;
    int matriz[strlen(str1)+1][strlen(str2)+1];
    for (i=0; i<=strlen(str1); i++)
        matriz[0][i] = 0;
    for (i=1; i<=strlen(str2); i++)
        matriz[i][0] = 0;
    for (i=1; i<=strlen(str1); i++){
        for(j=1; j<=strlen(str2); j++){
            if(str1[i-1]==str2[j-1]) matriz[i][j] = matriz[i-1][j-1]+1;
            else if (matriz[i-1][j] >= matriz[i][j-1]) matriz[i][j] = matriz[i-1][j];
            else matriz[i][j] = matriz[i][j-1];
        }
    }
    maior = matriz[strlen(str1)][strlen(str2)];
    return maior;
}

char* inverteChar (char *str){
    int i, j=strlen(str)-1;
    char *str2 = (char*)malloc(strlen(str)*sizeof(char));
    for(i=0; i<strlen(str); i++){
        str2[j] = str[i];
        j--;
    }
    str2[i] = '\0';
    return str2;
}

int palindromoMaiorSubsequencia (char *vetor){
    return maiorSubsequencia(vetor, inverteChar(vetor));
}

mutacao compara1(bool *mut, int i, int j){
    mutacao resultado;
    resultado.valor = 2;
    if(mut[i] && mut[j]) resultado.qtd_mutacao = 2;
    else if(mut[i] || mut[j]) resultado.qtd_mutacao = 1;
    else resultado.qtd_mutacao = 0;
    return resultado;
}

mutacao compara2(mutacao x, mutacao y){
    if (x.qtd_mutacao > y.qtd_mutacao) return x;
    else if (x.qtd_mutacao == y.qtd_mutacao && x.valor > y.valor) return x;
    else return y;
}

mutacao compara3 (mutacao x, mutacao y, mutacao z, bool *mut, int i, int j){
    mutacao resultado;
    if (x.qtd_mutacao > y.qtd_mutacao && x.qtd_mutacao > z.qtd_mutacao){
        resultado = x;
        if(mut[j]) resultado.qtd_mutacao++;
    }
    else if (y.qtd_mutacao > x.qtd_mutacao && y.qtd_mutacao > z.qtd_mutacao){
        resultado = y;
        if(mut[i]) resultado.qtd_mutacao++;
    }
    else if (z.qtd_mutacao > x.qtd_mutacao && z.qtd_mutacao > y.qtd_mutacao){
        resultado = z;
        //if(mut[i] || mut[j]) resultado.qtd_mutacao++;
    }
    else{ //Quantidade de mutações iguais
        if(x.valor > y.valor && x.valor > z.valor){
            resultado = x;
            if(mut[j]) resultado.qtd_mutacao++;
        }
        else if (y.valor > x.valor && y.valor > z.valor){
            resultado = y;
            if(mut[i]) resultado.qtd_mutacao++;
        }
        else if (z.valor > x.valor && z.valor > y.valor){
            resultado = z;
            //if(mut[i]||mut[j]) resultado.qtd_mutacao++;
        }
        else{ //Valores iguais
            resultado = z;
            //if(mut[i]||mut[j]) resultado.qtd_mutacao++;
        }
    }
    return resultado;
}

int palindromoMaiorMutacao (char *str, bool *mut){ //lps
    int i, j, k;
    int tam = strlen(str);
    mutacao matriz[tam][tam];
    for (i=0; i<tam; i++){
        matriz[i][i].valor = 1;
        if(mut[i]) matriz[i][i].qtd_mutacao = 1;
        else matriz[i][i].qtd_mutacao = 0;
    }
    for(i=1; i<tam; i++){ //range
        for(j=0, k=i; k<tam; j++, k++){ //j: linha; k: coluna.
            if (str[j] == str[k] && i==1)
                matriz[j][k] = compara1(mut, j, k);
            else if (str[j] == str[k]){
                matriz[j][k] = matriz[j+1][k-1];
                matriz[j][k].valor += 2;
                if(mut[j] && mut[k]) matriz[j][k].qtd_mutacao+=2;
                else if(mut[j] || mut[k]) matriz[j][k].qtd_mutacao++;
                matriz[j][k] = compara3(matriz[j][k-1], matriz[j+1][k], matriz[j][k], mut, j, k);
            }
            else{
                matriz[j][k] = compara2(matriz[j][k-1], matriz[j+1][k]);
            }
        }
    }
    /*for(i=0; i<tam; i++){
        for(j=0; j<i; j++){
            printf("  ");
        }
        for(j=i; j<tam; j++){
            printf("%d ", matriz[i][j].valor);
        }
        printf("\n");
    }
    printf("\n\n");
    for(i=0; i<tam; i++){
         for(j=0; j<i; j++){
            printf("  ");
        }
        for(j=i; j<tam; j++){
            printf("%d ", matriz[i][j].qtd_mutacao);
        }
        printf("\n");
    }*/
    return matriz[0][tam-1].valor;
}

int subsequenciaMutacao (char *str, bool *mut){
    return palindromoMaiorMutacao(str, mut);
}

int main (void){
    int qtd_mutacao, valor, i;
    char *DNA = (char*)malloc(qtd*sizeof(char));
    bool *mut = (bool*)malloc(qtd*sizeof(bool));
    for(i=0; i < qtd; i++){
        mut[i] = false;
    }
    scanf("%s", DNA);
    scanf("%d", &qtd_mutacao);
    for (i=0; i<qtd_mutacao; i++){
        scanf("%d", &valor);
        mut[valor-1] = true;
    }
    if (qtd_mutacao == 0) printf("%d\n", palindromoMaiorSubsequencia (DNA));
    else printf("%d\n", subsequenciaMutacao (DNA, mut));
    return 0;
}
