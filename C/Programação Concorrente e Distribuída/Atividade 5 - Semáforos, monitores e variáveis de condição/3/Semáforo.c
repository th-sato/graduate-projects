#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t t1, t2;
pthread_mutex_t S_C, S_E, S_R, S_O;

//ACERO ou ACREO

void *processo1(){
    pthread_mutex_lock(&S_C);
    printf("C");
    pthread_mutex_unlock(&S_R);
    //sleep(1);
    printf("E");
    pthread_mutex_unlock(&S_O);
    pthread_exit(NULL);
}

void *processo2(){
    printf("A");
    pthread_mutex_unlock(&S_C);
    pthread_mutex_lock(&S_R);
    printf("R");
    pthread_mutex_lock(&S_O);
    printf("O\n");
    pthread_exit(NULL);
}



int main(){
    pthread_mutex_lock(&S_C);
    pthread_mutex_lock(&S_E);
    pthread_mutex_lock(&S_R);
    pthread_mutex_lock(&S_O);
    pthread_create(&t1,NULL,&processo1,NULL);
    pthread_create(&t2,NULL,&processo2,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;
}

