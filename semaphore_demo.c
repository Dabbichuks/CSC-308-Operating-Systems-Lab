#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int counter = 0;
sem_t sem;

void *increment(void *arg)
{
    sem_wait(&sem);

    counter++;

    sem_post(&sem);

    return NULL;
}

int main()
{
    pthread_t threads[10];

    sem_init(&sem,0,1);

    for(int i=0;i<10;i++)
        pthread_create(&threads[i],NULL,increment,NULL);

    for(int i=0;i<10;i++)
        pthread_join(threads[i],NULL);

    printf("Counter = %d\n",counter);

    sem_destroy(&sem);

    return 0;
}
