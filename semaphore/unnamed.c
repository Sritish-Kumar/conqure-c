#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

// global var
int counter = 0;
sem_t mutex;

void *increment(void *arg)
{
    
    // lock mutex
    for (size_t i = 0; i < 100000; i++)
    {
        sem_wait(&mutex);

        counter++;

        sem_post(&mutex);
    }

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    sem_init(&mutex, 0, 1);

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&mutex);

    printf("Value %d ",counter);
    return 0;
}