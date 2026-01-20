#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

#define MAX 5

sem_t S,T;
int count;

void* print_zero(void* arg){

    while(1){
        sem_wait(&S);   //Acquire 00 - block

        if (count >= MAX)
        {
            sem_post(&T);
            break;
        }

        printf("00");

        sem_post(&T);   // Release 11

    }

    return NULL;

}


void* print_one(void* arg){

    while(1){
        sem_wait(&T);

        if (count >= MAX)
        {
            sem_post(&S);
            break;
        }
        count++;

        printf("11");

        sem_post(&S);

    }

    return NULL;

}



int main(){

    pthread_t t1,t2;
    sem_init(&S,0,1);
    sem_init(&T,0,0);

    pthread_create(&t1, NULL, print_zero,NULL);
    pthread_create(&t2,NULL,print_one,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    sem_destroy(&S);
    sem_destroy(&T);
    
    return 0;
}