#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Swap(int* A, int j, int i){
          int x  = A[j];
          A[j] = A[i];
          A[i] = x;


          }



int Partition(int*A,int b, int e){

int Pivot = b + rand()%(e-b);
int i,marker;
Swap(A,Pivot,e);
marker = b-1;
for(i=b;i<e;i++){
    if(A[i] < A[e] ){
            marker++;
        Swap(A,marker,i);

    }
}

Swap(A,e,marker+1);
return marker+1;

}

void Quicksort(int*A,int b, int e){
int marker;
if(b<e){
    marker = Partition(A,b,e);
    Quicksort(A,b,marker-1);
     Quicksort(A,marker+1,e);

}

}





PrintArray(int* A, int N){
int i;
for (i=0;i<N;i++)
    printf("\n%i",A[i]);

}



int main()
{
    int* A;
    int N,i;
    srand(time(NULL));
    scanf("%i",&N);
    A = malloc(sizeof(int)*N);
    for(i=0;i<N;i++)
        scanf("%i",&A[i]);
 Quicksort(A,0,N-1);
  PrintArray(A,N);

    return 0;
}
