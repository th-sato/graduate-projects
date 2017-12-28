#include <stdio.h>
#include <pthread.h>

//mutex => garante exclusao mutua nas variáveis de condição
pthread_mutex_t sb=PTHREAD_MUTEX_INITIALIZER;  
//duas variáveis de condição
pthread_cond_t  vcA=PTHREAD_COND_INITIALIZER;
pthread_cond_t  vcB=PTHREAD_COND_INITIALIZER;
int libera=0;

typedef struct {
  char nome[3];
  int tempo;
} dados;

void *mostra(void *d){
  dados *pd=(dados*)d;
  while (1) {
    pthread_mutex_lock(&sb); // entra na regiao critica
       // teste para bloqueio na variavel de condicao
    if ((libera!=0)&&(pd->nome[0]=='A')) 
       pthread_cond_wait(&vcA, &sb);
    if ((libera!=1)&&(pd->nome[0]=='B')) 
       pthread_cond_wait(&vcB, &sb);    
    usleep (pd->tempo);
    printf("Mostra para %s ",  pd->nome); fflush(stdout);
    usleep (50000);
    printf("Acabei para %s\n", pd->nome); fflush(stdout);
      // altera o estado da variavel de controle
    libera=(libera+1)%2;
    if (pd->nome[0]=='A') pthread_cond_signal(&vcB);
    if (pd->nome[0]=='B') pthread_cond_signal(&vcA);
    pthread_mutex_unlock(&sb); // sai da regiao critica
  }  
}

int main(void){
   pthread_t t1,t2;  // duas threads
   dados A={"A",10000},B={"B",500000};
   pthread_create(&t1,NULL,&mostra,&A); // cria thread 1
   pthread_create(&t2,NULL,&mostra,&B); // cria thread 2
   pthread_join(t1,NULL);  // espera termino da thread 1
   pthread_join(t2,NULL);  // espera termino da thread 2
   pthread_cond_destroy(&vcA);
   pthread_cond_destroy(&vcB);
   return 0;
} 
