#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

int LCS (char str1[], char str2[]){
    int i, j;
    int tam1 = strlen(str1);
    int tam2 = strlen(str2);
    int matriz[tam1+1][tam2+1];
    for(i=0; i<=tam1; i++)
        matriz[i][0] = 0;
    for(i=1; i<=tam2; i++)
        matriz[0][i] = 0;
    for(i=1; i<=tam1; i++){
        for(j=1; j<=tam2; j++){
            if(str1[i-1]==str2[j-1])
                matriz[i][j] = matriz[i-1][j-1] + 1;
            else{
                if (matriz[i-1][j] > matriz[i][j-1]) matriz[i][j] = matriz[i-1][j];
                else matriz[i][j] = matriz[i][j-1];
            }
        }
    }
    for(i=0; i<=tam1; i++){
        for(j=0; j<=tam2; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    return matriz[tam1][tam2];
}

int main(void){
    char *c1 = (char*)malloc(6*sizeof(char));
    char *c2 = (char*)malloc(5*sizeof(char));
    std::cin >> c1;
    std::cin >> c2;
    printf("%d\n", LCS(c1, c2));
    return 0;
}
