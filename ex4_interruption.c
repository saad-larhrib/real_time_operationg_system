#include <stdio.h>
#include <pthread.h>

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int data_ready = 0;
int value = 0;

// Producer
void* producer(void* arg){
    pthread_mutex_lock(&mutex);

    value = 42; // produire une valeur
    data_ready = 1;

    printf("Producteur: valeur produite = %d\n", value);

    pthread_cond_signal(&cond); // notifier consommateur

    pthread_mutex_unlock(&mutex);

    return NULL;
}

// Consumer
void* consumer(void* arg){
    pthread_mutex_lock(&mutex);

    while(data_ready == 0){
        printf("Consommateur: en attente...\n");
        pthread_cond_wait(&cond, &mutex);
    }

    printf("Consommateur: valeur reçue = %d\n", value);

    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(){
    pthread_t prod, cons;

    pthread_create(&cons, NULL, consumer, NULL);
    pthread_create(&prod, NULL, producer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    return 0;
}
