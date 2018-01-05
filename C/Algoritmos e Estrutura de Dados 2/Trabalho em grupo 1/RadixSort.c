#include <stdio.h>
#include <stdlib.h>
typedef struct Radix{
int N;
int aloc;
int** x;
}Radix;

void AddtoRadix(Radix*r, int* k){

r->N ++;
r->x = realloc(r->x,(r->N)*sizeof(int*));
r->x[r->N-1] = k;
}

int* CountingSort(int*A,int n, long long int exp){
    int i,j,k,m;
    Radix*B = malloc(sizeof(Radix)*10);
    int* C = malloc(n*sizeof(int));
    for(i=0;i<10;i++)
    {
        B[i].x = NULL;
        B[i].N = 0;
    }

    for(i=0;i<n;i++){
       m = (A[i]%exp)/(exp/10);
        AddtoRadix(&B[m],&A[i]);
    }
    k=0;
    for(i=0;i<10;i++){
        for(j=0;j<B[i].N ;j++){
            C[k] = B[i].x[j][0];
            k++;
        }
    }

return C;
}

int GetMax(int*A,int n){
int i;
int MAX = A[0];
for(i=0;i<n;i++){
    if(A[i]>MAX)
        MAX = A[i];
}
return MAX;
}
int GetMin(int*A,int n){
int i;
int MIN = A[0];
for(i=0;i<n;i++){
    if(A[i]<MIN)
        MIN = A[i];
}
return MIN;
}
void OffsetArray(int*A,int n, int d){
int i;
for(i=0;i<n;i++){
A[i] = A[i] + d;
}
}


int*RadixSort(int*A,int n){

int max = GetMax(A,n);
long long  int exp = 1;
do{
    exp*=10;
    A= CountingSort(A,n,exp);

}
while(max>=exp);
return A;
}
void PrintArray(int* A,int ak,int*B,int bk){
int i;
printf("\n");


for(i=bk-1;i>=0;i--){
    printf("%i\n",-B[i]);
}

for(i=0;i<ak;i++){
    printf("%i\n",A[i]);

}

}


int main()
{
    int n,i,min;
    int*A;
    int*B;
    int k;
    int ak = 0;
    int bk = 0;

    scanf("%i",&n);
    A = malloc(n*sizeof(int));
    B = malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%i",&k);
        if(k>=0){
            A[ak] = k;
            ak++;
        }
         else{
            B[bk] =-k;
            bk++;
         }
    }

    A = RadixSort(A,ak);
    B = RadixSort(B,bk);

    PrintArray(A,ak,B,bk);
}
