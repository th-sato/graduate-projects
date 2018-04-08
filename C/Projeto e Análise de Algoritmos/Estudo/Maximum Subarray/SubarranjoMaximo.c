#include <stdio.h>
#include <stdlib.h>

typedef struct Maximo{
    double maxSeq;
    double maxSuf;
}Maximo;

Maximo subarranjoMaximo (double v[], int n){ //Encontrar a soma máxima contígua dado um conjunto.
    Maximo soma;
    if(n == 1){
        if(v[0]<0){
            soma.maxSeq = 0;
            soma.maxSuf = 0;
        }
        else {
            soma.maxSeq = v[0];
            soma.maxSuf = v[0];
        }
    }
    else{
        soma = subarranjoMaximo(v, n-1);
        soma.maxSuf += v[n-1];
        if (soma.maxSuf > soma.maxSeq) soma.maxSeq = soma.maxSuf;
        else if (soma.maxSuf < 0) soma.maxSuf = 0;
    }
    return soma;
}

int main(void){
    int n = 8;
    double v[] = {2, -3, 1.5, -1, 3, -2, -3, 3};
    Maximo aux = subarranjoMaximo(v, n);
    if(aux.maxSuf > aux.maxSeq)
        printf("%.2f\n", aux.maxSuf);
    else
        printf("%.2f\n", aux.maxSeq);
    return 0;
}
