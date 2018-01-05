#include <stdio.h>
#include <stdlib.h>

void ShellSort(int *v, int n){
    int h=1, i, x, j;
    do{
        h=h*3+1;
    }while(h<n);
    do{
        h=h/3;
        for(i=h+1; i<=n; i++){
            x=v[i];
            j=i;
            while(v[j-h]>x){
                v[j]=v[j-h];
                j=j-h;
                if(j<=h) break;
            }
            v[j]=x;
        }
    }while(h!=1);
}



int main(){
    int i, n;
    scanf("%d", &n);
    int *v=malloc(n*sizeof(int));
    for (i=1; i<=n; i++){
        scanf("%d", &v[i]);
    }
    ShellSort(v, n);
    for (i=1; i<=n; i++){
        printf("%d\n", v[i]);
    }
    return 0;
}

