# include <stdio.h>
# include <stdlib.h>

int main(){
int i,j,N,menor,aux;
     scanf("%d",&N);
     int vet[N];
     for(i=0;i<N;i++)
        scanf("%d",&vet[i]);
     for(i=0;i<N;i++){
        menor=i;
     for(j=i+1; j<N;j++){
        if(vet[j]<vet[menor])
          menor=j;
     }
        if(menor!=i){
           aux=vet[menor];
           vet[menor]=vet[i];
           vet[i]=aux;
        }
    }
     for(i=0;i<N;i++)
        printf("%d\n",vet[i]);

return 0;
}
