#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    FILE* arq = fopen("rand.txt", "w");
long int r;
int i,size;
scanf("%i",&size);
fprintf(arq, "%i\n", size);
    for(i=0;i<size;i++){
        r = rand()%400000001;
        r = r*10;
        r += rand()%10;
        r -= 2000000000;
        fprintf(arq,"%li\n",r);
    }
    fclose(arq);
    return 0;
}
