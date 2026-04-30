#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;

void* thread(void* arg){
	sem_wait(&sem); //enter resources
	printf("\nThread %ld use the rsources\n", (long)arg);

	sleep(2);

	printf("Thread %ld free resources\n", (long)arg);

	sem_post(&sem); // free resources 
	return NULL;
}

int main(){
	pthread_t t[5];
	sem_init(&sem, 0, 3);
	for(int i = 0; i < 5; i++){
		pthread_create(&t[i], NULL, thread, (void*)(long)i);
	}
	
	for(int i = 0; i < 5; i++){
		pthread_join(t[i], NULL);
	}

	sem_destroy(&sem);
}	
