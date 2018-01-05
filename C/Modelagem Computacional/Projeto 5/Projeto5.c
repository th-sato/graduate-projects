/*Universidade Federal de São Paulo - UNIFESP

    Pedro Dousseau Guedes de Melo - RA: 95737
    Thiago Hideki Sato - RA: 92341
    Victor de Sá Nunes - RA: 92350

    Projeto 4: Propagação de incêndios

    Modelagem Computacional
    Professor Marcos Gonçalves Quiles
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define num_estados 5 //Números de estados
#define T 100000
#define deltaT 1

typedef struct { //Estrutura com as informações dos estados
    char atual; //Estado atual
    char prox; //Proximo estado
    char chuva; //Há chuva? '0' - Não, '1' - Sim
    char vento; //Há vento? '0' - Não, '1' - Sim
    int cont; //Contador temporal para o ṕróximo estado
}Estado;

/* Tipos de estado:
    0: Árvore
    1: Água
    2: Fogo/Incêndio - Nível 1
    3: Cinzas
    4: Fogo/Incêndio - Nível 2*/

/* Distribuição dos estados:
    0: 75%
    1: 25%
    2: 0%. inicialmente não há fogo
    3: 0%, consideramos que não cinzas, pois ainda não houve focos de incêndios
*/

void imprimirMatriz (Estado **m, int n){
    int i, j;
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            printf("%c ", m[i][j].atual);
        }
        printf ("\n");
    }
}

void imprimirMatriz_arquivo (Estado **m, int n, int k, int l, int r, int num_incendios){
    int i, j;
    char *str = (char*)malloc(50*sizeof(char));
    sprintf(str, "Matriz%i_Incendios%i_Teste%i_Estado%i.txt", k, num_incendios, r, l+1);
    FILE *arq = fopen(str, "w");
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            //printf("%c ", m[i][j].atual);
            fprintf(arq, "%c ", m[i][j].atual);
        }
        //printf ("\n");
        fprintf(arq, "\n");
    }
    fclose(arq);
}

void imprimirMatriz_arquivo_diretorio (Estado **m, int n, int k, int l, int r, int num_incendios){
    int i, j;
    char *str = (char*)malloc(300*sizeof(char));
    sprintf(str, "C:/Users/Tiago/Desktop/Modelagem Computacional/Matriz %i/Matriz%i_Incendios%i_Teste%i_Estado%i.txt", k, k, num_incendios, r, l+1);
    FILE *arq = fopen(str, "w");
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            //printf("%c ", m[i][j].atual);
            fprintf(arq, "%c ", m[i][j].atual);
        }
        //printf ("\n");
        fprintf(arq, "\n");
    }
    fclose(arq);
}

void imprimirMatriz_vento_arquivo (Estado **m, int n, int k, int l, int r, int num_incendios){
    int i, j;
    char *str = (char*)malloc(70*sizeof(char));
    sprintf(str, "Matriz%i_Incendios%i_Teste%i_Estado%i_Vento.txt", k, num_incendios, r, l+1);
    FILE *arq = fopen(str, "w");
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            fprintf(arq, "%c ", m[i][j].vento);
        }
        fprintf(arq, "\n");
    }
    fclose(arq);
}

void imprimirMatriz_chuva_arquivo (Estado **m, int n, int k, int l, int r, int num_incendios){
    int i, j;
    char *str = (char*)malloc(70*sizeof(char));
    sprintf(str, "Matriz%i_Incendios%i_Teste%i_Estado%i_Chuva.txt", k, num_incendios, r, l+1);
    FILE *arq = fopen(str, "w");
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            fprintf(arq, "%c ", m[i][j].chuva);
        }
        fprintf(arq, "\n");
    }
    fclose(arq);
}

Estado** inicializaEstado(int n){
    int i, j;
    Estado **m;
    m = (Estado**)malloc(n*sizeof(Estado*));
    for(i=0; i<n; i++){
        m[i] = (Estado*)malloc(n*sizeof(Estado));
    }
    for(i=0; i<n; i++){ //Inicia tudo como árvore
        for(j=0; j<n; j++){
            m[i][j].atual = '0';
            m[i][j].prox = 'a'; //Considere 'a' como indeterminado
            m[i][j].chuva = '0';
            m[i][j].vento = '0';
            m[i][j].cont = 0;
        }
    }
    return m;
}

/*
void estado1 (Estado** M, int n){ //Água junta e separada das árvores.
    float a = 0.25 * n * n, c=0.0;
    int i, j, k=0;
    for(i=0; i<k+1; i++){
        for(j=0; j<k+1; j++){
            if (c>=a) break;
            if (M[i][j].atual != '1'){
                M[i][j].atual = '1';
                c++;
            }
        }
        if (c < a && k<n-1) k++;
    }
}

void estado2 (Estado** M, int n){ //Organização aleatória (adaptação da rede aleatória)
    srand(time(NULL));
    float a = 0.25 * n * n, c=0.0;
    int i, j;
    while (c < a){
        i = rand()%n;
        j = rand()%n;
        if (M[i][j].atual=='0'){
            M[i][j].atual = '1';
            c++;
        }
    }
}
*/

void mudarEstado(Estado** M, int n){
//Colocar o próximo estado na matriz inteira, devolve um inteiro para ver quantos estados foram alterados
    int i, j;
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            if (M[i][j].prox != 'a'){
                if (M[i][j].prox=='2'){
                    if (M[i][j].atual=='0'){
                        M[i][j].atual = M[i][j].prox;
                        M[i][j].cont = 0;
                    }
                    else if (M[i][j].atual=='2'){
                        M[i][j].cont++;
                        if (M[i][j].cont == 100) {
                            M[i][j].prox = '3';
                            M[i][j].cont =0;
                        }
                    }
                }
                else if (M[i][j].prox=='4'){
                    if(M[i][j].atual=='0'){
                        M[i][j].atual = M[i][j].prox;
                        M[i][j].cont = 0;
                    }
                    else if (M[i][j].atual=='2'){
                        M[i][j].atual = M[i][j].prox;
                        M[i][j].cont = M[i][j].cont/2;
                        /*
                        M[i][j].cont = (M[i][j].cont/100)*50;
                        */
                    }
                    else if (M[i][j].atual=='4'){
                        M[i][j].cont++;
                        if (M[i][j].cont == 50) {
                            M[i][j].prox = '3';
                            M[i][j].cont = 0;
                        }
                    }
                }
                else if (M[i][j].prox=='3'){
                    M[i][j].atual = M[i][j].prox;
                }
            }
        }
    }
}

void proximoEstado (Estado** M, int i, int j, int n, char estado){ //Programar a alteração do estado
    if (estado=='2'){//Fogo - Nível 1
        if (M[i][j].vento=='1'){ //Vento: se propaga somente para a esquerda, assim como o fogo.
            if (j-1 <= n-1 && j-1 >= 0 && M[i][j-1].atual=='0' && M[i][j-1].chuva=='0') M[i][j-1].prox = estado;
            if (j-2 <= n-1 && j-2 >= 0 && M[i][j-2].atual=='0' && M[i][j-2].chuva=='0') M[i][j-2].prox = estado;
        }
        else {
            if (j-1 <= n-1 && j-1 >= 0 && M[i][j-1].atual=='0' && M[i][j-1].chuva=='0') M[i][j-1].prox = estado;
            if (j+1 <= n-1 && j+1 >= 0 && M[i][j+1].atual=='0' && M[i][j+1].chuva=='0') M[i][j+1].prox = estado;
        }
        if (i-1 <= n-1 && i-1 >= 0 && M[i-1][j].atual=='0' && M[i-1][j].chuva=='0') M[i-1][j].prox = estado;
        if (i+1 <= n-1 && i+1 >= 0 && M[i+1][j].atual=='0' && M[i+1][j].chuva=='0') M[i+1][j].prox = estado;
    }
    else if (estado=='4'){//Fogo - Nível 2
        if (M[i][j].vento=='1'){ //Vento: se propaga somente para a esquerda, assim como o fogo.
            if (j-1 <= n-1 && j-1 >= 0 && (M[i][j-1].atual=='0' || M[i][j-1].atual=='2') && M[i][j-1].chuva=='0') M[i][j-1].prox = estado;
            if (j-2 <= n-1 && j-2 >= 0 && (M[i][j-2].atual=='0' || M[i][j-2].atual=='2') && M[i][j-2].chuva=='0') M[i][j-2].prox = estado;
        }
        else {
            if (j-1 <= n-1 && j-1 >= 0 && (M[i][j-1].atual=='0' || M[i][j-1].atual=='2') && M[i][j-1].chuva=='0') M[i][j-1].prox = estado;
            if (j+1 <= n-1 && j+1 >= 0 && (M[i][j+1].atual=='0' || M[i][j+1].atual=='2') && M[i][j+1].chuva=='0') M[i][j+1].prox = estado;
        }
        if (i-1 <= n-1 && i-1 >= 0 && (M[i-1][j].atual=='0' || M[i-1][j].atual=='2') && M[i-1][j].chuva=='0') M[i-1][j].prox = estado;
        if (i+1 <= n-1 && i+1 >= 0 && (M[i+1][j].atual=='0' || M[i+1][j].atual=='2') && M[i+1][j].chuva=='0') M[i+1][j].prox = estado;
    }
}

int anda_vento(Estado **m, char wind, int n){
    int i;
    for(i=0; i<n; i++){
        m[i][wind].vento = '0';
        if (wind-1>=0 || wind-1<=n) m[i][wind-1].vento = '1';
    }
    wind--;
    return wind;
}

int main(void){
    Estado **m; //m = matriz
    int i, j, n = 1000, incendio; //n = tamanho da matriz.
    int t, impressao;
    //t: tempo
    //impressao: controlar a impressão de matrizes
    int k, l, a, s, cont, cont2, cont3, r, num_incendios, h, wind=0, rain=0, fire_level, imp;
    //k e l: geram as posições do incendio aleatoriamente
    //s: Quantidade de impressões da amatriz
    //a: Quantidade de arquivos para ler
    //cont: quantidade de cinzas no final da matriz
    //cont2: quantidade de '1' (água)
    //cont3: contador para ver se a matriz está mudando ou não
    //r: variável para fazer testes
    //num_incendios: quantidade de incêndios iniciais
    //h: controlar a quantidade de incêndios
    //wind: localização do vento
    //rain: calcular a quantidade de chuva
    //imp: Imprimir todos os estados de uma matriz
    char *str = (char*)malloc(50*sizeof(char)); //Usar para guardar os dados dos arquivos
    char *str2 = (char*)malloc(50*sizeof(char)); //Usar para guardar os tempos
    /*
    Matriz1 é a matriz com árvores concentradas.
    Matriz2 e Matriz3 são aleatórias.
    */
    for (a=1; a<4; a++){
        for (h=1; h<=7500; h*=10){
            num_incendios = 100*h;
            sprintf (str2, "Matriz%i_Incendio%i_Tempo.txt", a, num_incendios);
            FILE *arq2 = fopen(str2, "w");
            fprintf(arq2, "\n");
            fprintf(arq2, "Quantidade de incêndio inicial: %i\n", num_incendios);
            for (r=1; r<4; r++){ //Testes
                if (num_incendios==100) impressao=100;
                else impressao=50;
                cont=0; cont2=0; cont3=0; s=0; incendio=0, imp=0;
                printf("Matriz%i em processo - Quantidade de incêndio inicial: %i - Teste %i\n", a, num_incendios, r);
                m = inicializaEstado(n);
                sprintf (str, "Matriz%i.txt", a);
                FILE *arq = fopen(str, "r");
                for (i = 0; i < n; i++){
                    for (j = 0; j < n; j++){
                        fscanf (arq, "%c ", &m[i][j].atual);
                        m[i][j].prox = m[i][j].atual;
                        if(m[i][j].atual=='1') cont2++;
                    }
                }
                //Colocar a chuva: 1/16 de chuva
                k = n/2;
                l = n/2;
                rain=0;
                for (i=k; i<(k+n/4); i++){
                    for (j=l; j<(l+n/4); j++){
                        if (m[i][j].chuva =='0'){
                            m[i][j].chuva ='1';
                            rain++;
                        }
                    }
                }
                //Colocar os focos de incêndio
                srand(time(NULL));
                while (incendio<num_incendios){ //Inserir incendios
                    k = rand()%n;
                    l = rand()%n;
                    fire_level = rand()%2;
                    if (m[k][l].atual == '0' && m[k][l].chuva == '0'){
                        if (fire_level==0){
                            m[k][l].atual = '2';
                            m[k][l].prox = '2';
                            incendio++;
                        }
                        else{
                            m[k][l].atual = '4';
                            m[k][l].prox = '4';
                            incendio++;
                        }
                    }
                }
                imprimirMatriz_chuva_arquivo(m, n, a, s, r, num_incendios);
                //Colocar o vento
                while (wind<n/10 && wind>n/10){
                    wind = rand()%n;
                }
                for (i=0; i<n; i++){
                    m[i][wind].vento = '1';
                }
                for (t=0; t<T; t+=deltaT){
                    if (r==1 && h==10){
                        imprimirMatriz_arquivo_diretorio(m, n, a, imp, r, num_incendios);
                        imp++;
                    }
                    if (t%impressao==0) {
                        imprimirMatriz_arquivo (m, n, a, s, r, num_incendios);
                        imprimirMatriz_vento_arquivo(m, n, a, s, r, num_incendios);
                        s++;
                    }
                    for (i = 0; i < n; i++){
                        for (j = 0; j < n; j++){
                            if (m[i][j].atual=='2' && m[i][j].prox!='3') proximoEstado(m, i, j, n, '2');
                            else if (m[i][j].atual=='4' && m[i][j].prox!='3') proximoEstado(m, i, j, n, '4');
                            else if (m[i][j].atual=='3') cont++;
                            if (m[i][j].atual==m[i][j].prox && m[i][j].atual!='2' && m[i][j].atual != '4') cont3++;
                        }
                    }
                    mudarEstado(m, n);
                    if (t%10==0 && wind!=0){
                        wind =  anda_vento(m, wind, n);

                    }
                    if (cont==(n*n-cont2)){ //Não há mais árvores para queimar
                        printf("Teste %i - Tempo para haver somente cinzas e água: %i\n", r, t);
                        fprintf(arq2, "Teste %i - Tempo para haver somente cinzas e água: %i\n", r, t);
                        break;
                    }
                    else if (cont3==n*n){ //Parar a execução, pois a matriz não está mudando mais.
                        printf("Teste %i - A matriz do espaço não se altera mais. Ainda há árvores.\n", r);
                        printf("   Tempo de execução: %i\n", t);
                        fprintf(arq2, "Teste %i - A matriz do espaço não se altera mais. Ainda há árvores.\n", r);
                        fprintf(arq2, "   Tempo de execução: %i\n", t);
                        break;
                    }
                    cont=0;
                    if (cont3!=n*n) cont3=0;
                }
                if (cont3==0){//A matriz ainda continua se alterando
                    printf ("Teste %i - Ainda há árvores. Tempo de execução: %i\n", r, t);
                    fprintf(arq2, "Teste %i - Ainda há árvores. Tempo de execução: %i\n", r, t);
                }
                imprimirMatriz_arquivo (m, n, a, s, r, num_incendios);
                free(arq);
                fclose(arq);
                printf("Matriz%i terminada - Quantidade de incêndio inicial: %i - Teste %i\n", a, num_incendios, r);
            }
            printf("\n\n");
            free(arq2);
            fclose(arq2);
        }
    }
    return 0;
}
