#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct BucketEl;
typedef struct Bucket{
struct BucketEl* first;
struct BucketEl* last;
}Bucket;
typedef struct BucketEl{
int N;
struct BucketEl* next;
}BucketEl;


BucketEl* NewBucketEl(int k){

BucketEl* el =malloc(sizeof(BucketEl));
el->N = k;
el->next = NULL;

}

void AddtoBucket(Bucket*b,int k){
BucketEl* el = NewBucketEl(k);
if(b->first == NULL)
    b->first = b->last = el;
else {
    BucketEl* ptr = b->first;
    BucketEl*tptr = NULL;
    while((ptr != NULL) && (ptr->N < k) ){
        tptr = ptr;
        ptr = ptr->next;
    }
    if(ptr == NULL){
         b->last->next =el;
        b->last = el;
    }
    else if(tptr == NULL){
        el->next = b->first;
        b->first = el;
    }
    else{
        tptr ->next = el;
        el->next = ptr;
    }
    }

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

int* BucketSort(int*A,int n, int M){
int i,j,key;
Bucket*Buckets = malloc(M*sizeof(Bucket));
for(i=0;i<M;i++){
    Buckets[i].first = NULL;
    Buckets[i].last = NULL;
}
int max =GetMax(A,n);
for(i=0;i<n;i++){
        key = (int)((float)A[i]/(float) (max+1)*M);
    AddtoBucket(&Buckets[key],A[i]);
}
j = 0;
BucketEl* ptr;
for(i=0;i<M;i++){
   ptr = Buckets[i].first;
    while(ptr!=NULL){
         A[j] = ptr->N;
         j++;
         ptr = ptr->next;
    }
}
return A;
}



int main()
{
    int n,i,min;
    int*A;
    int*B;
    int k;
    int ak = 0;
    int bk = 0;
    int m;
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
    if(ak>100000)
        m = 100000;
    else m =ak;
    A = BucketSort(A,ak,m);
        if(bk>100000)
        m = 100000;
    else m =bk;
    B = BucketSort(B,bk,m);

    PrintArray(A,ak,B,bk);
}
