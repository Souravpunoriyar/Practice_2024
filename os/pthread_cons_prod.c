#include<stdio.h>
#include<pthread.h>
#include <semaphore.h>
#include<stdlib.h>


#define BUFFER_SIZE 10

sem_t empty, full;
pthread_mutex_t mutex;
int buffer[BUFFER_SIZE]={0};
int in =0;
int out =0;



void *prod(void *arg) {
    int item;
    for(int i =0; i< BUFFER_SIZE; i++) {
        item = rand()%10;
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        /*Critical section*/
        buffer[in] = item;
        in++;
        /*Critical section end*/
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
        printf("Prod [%d] \r\n", item);
    }
    pthread_exit(NULL);
}


void *cons(void *arg) {
    int item;
    for(int i =0; i< 5; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        /*Critical section*/
        item = buffer[out];
        buffer[out] = 0;
        out++;
        /*Critical section end*/
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
        printf("Consume [%d] [%s]\r\n", item, (char *)arg);
    }
    pthread_exit(NULL);
}



int main() {
    pthread_t producer;
    pthread_t consumer1;
    pthread_t consumer2;

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&producer, 0, &prod, NULL);
    pthread_create(&consumer1, 0, &cons, "1");
    //pthread_create(&consumer2, 0, &cons, "2");

    pthread_join(producer,0);
    pthread_join(consumer1,0);
    pthread_join(consumer2,0);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    printf("main thread end \r\n");
    return 0;
}