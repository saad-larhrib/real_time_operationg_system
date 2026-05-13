#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int compteur = 0;
pthread_mutex_t mutex;


void* increment(void* arg){
	
	for(int i = 0; i < 100000; i++){
		pthread_mutex_lock(&mutex);
		compteur++;
		pthread_mutex_unlock(&mutex);
	}

return NULL;
}

void* decrement(void* arg){
	for(int i = 0; i < 100000; i++){
		pthread_mutex_lock(&mutex);
		compteur--;
		pthread_mutex_unlock(&mutex);
	}

return NULL;
}


int main(){
	pthread_t t1, t2;
	pthread_mutex_init(&mutex, NULL);

	
	pthread_create(&t1, NULL, increment, NULL);
	pthread_create(&t2, NULL, decrement, NULL);


	pthread_join(t1, NULL);
	pthread_join(t2, NULL);


	printf("Compteur = %d\n", compteur);
	pthread_mutex_destroy(&mutex);
	
return 0;
}

