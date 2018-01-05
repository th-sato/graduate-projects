#include <stdio.h>
#include <stdlib.h>

void bubble (int *v, int n){
	int i, j, aux,end;
	end = 0;
	for (i=n-1; i>0; i--){
		for(j=0; j<i; j++){
			end = 1;            
			if(v[j]>v[j+1]){
				end = 0;                
				aux=v[j];
			 	v[j]=v[j+1];
				v[j+1]=aux;
			    }
		}
		if( end == 1) return;
	    }
	}



int main(){
    int i, n;
    scanf("%d", &n);
    int *v=malloc(n*sizeof(int));
    for (i=0; i<n; i++){
        scanf("%d", &v[i]);
    }
    bubble (v, n);
    for (i=0; i<n; i++){
        printf("%d\n", v[i]);
    }
    return 0;
}

