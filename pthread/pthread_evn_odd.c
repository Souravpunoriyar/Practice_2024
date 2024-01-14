#include<stdio.h>
#include<pthread.h>

int max = 100;
volatile int count = 0;

pthread_mutex_t mutex, even_mutex, odd_mutex;
pthread_cond_t cond;

void printeven(void *arg) {
    while(count < max){
        pthread_mutex_lock(&mutex);
        while(count %2 !=0) {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("%d ", count++);
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);

    }
}



void printodd(void *arg) {
    while(count < max){
        pthread_mutex_lock(&mutex);
        while(count %2 !=1) {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("%d ", count++);
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);

    }
}



void printevenm(void *arg) {
    while(count < max){       
        if(count %2 ==0) {
            printf("%s \n", __FUNCTION__);
            pthread_mutex_lock(&mutex);
            printf("%d ", count++);    
            pthread_mutex_unlock(&mutex);

        }        

    }
}



void printoddm(void *arg) {
    while(count < max){
        
        if(count %2 !=0) {
            printf("%s \n", __FUNCTION__);
            pthread_mutex_lock(&mutex);
            printf("%d ", count++);    
            pthread_mutex_unlock(&mutex);
        
        }                
    }
}            



int main() {

    pthread_t thread1;
    pthread_t thread2;

    pthread_create(&thread1, 0, &printevenm, NULL);
    pthread_create(&thread1, 0, &printoddm, NULL);

    pthread_join(thread1, 0);
    pthread_join(thread2, 0);

}