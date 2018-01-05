#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int time1, time2;
}placar;

void QuickSort (int v[], int p, int r);
int Partition (int v[], int p, int r);

void QuickSort (int v[], int p, int r){
    int q;
    if(p<r){
        q=Partition(v, p, r);
        QuickSort(v, p, q-1);
        QuickSort(v, q+1, r);
    }
}

int Partition (int v[], int p, int r){
    int x = v[r], aux;
    int i=p-1, j;
    for (j=p; j<r; j++){
        if(v[j]<=x){
            i++;
            aux=v[i];
            v[i]=v[j];
            v[j]=aux;
        }
    }
    aux=v[i+1];
    v[i+1]=v[r];
    v[r]=aux;
    return i+1;
}

main(){
    int a, b, i, j=-1, v=0, e=0; //v=numero de vitorias e e=numero de empates
    scanf("%d %d", &a, &b); //a = numero de jogos e b =numero de gols que o time pode comprar
    placar v1[a];
    int z[a];
    for(i=0; i<a; i++){
        scanf("%d %d", &v1[i].time1, &v1[i].time2);
        if(v1[i].time1>v1[i].time2) v++;
        else{
            j++;
            z[j]=v1[i].time2-v1[i].time1;
        }
    }
    QuickSort(z, 0, j);
    for(i=0; i<=j; i++){
        if(z[i]==0 && b>0){
            b--;
            v++;
        }
        else if (z[i]==0 && b==0){
            e++;
        }
        else if (z[i]>0){
            while (z[i]>=0 && b>0){
                z[i]--;
                b--;
            }
            if(z[i]<0) v++;
            else if (z[i]==0) e++;
        }
    }
    printf("%d\n", e+3*v);
}
