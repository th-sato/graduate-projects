#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NThreads 2
#define N 1000

int request = 0;
int respond = 0;
int contador = 0;

void* client_process(void *id){
    int i;
    long thID = (long) id;
    for(i = 0; i < N; i++){
        printf("Secao nao-critica, Thread %ld\n", thID);
        while(respond != thID){
        	request = thID;
        }
        printf("Secao critica, Thread %ld. ", thID);
        contador++;
        printf("Contador: %d\n\n", contador);
        respond = 0;
    }
    pthread_exit(0);
}

void* server_process(){
    long i;
    pthread_t client[NThreads];
    for(i=1; i<=NThreads; i++){
        pthread_create(&client[i], NULL, client_process, (void *) i);
    }

    for(i=0; i<NThreads*N; i++){
        while(request == 0);
        respond = request;
        while(respond != 0);
        request = 0;
    }
    for(i=1; i<=NThreads; i++){
        pthread_join(client[i],NULL);
    }
    pthread_exit(0);
}

int main(void){
    int i;
    pthread_t server;
    pthread_create(&server, NULL, server_process, NULL);
    pthread_join(server,NULL);
    return 0;
}
