#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>
#define SIZE 10

char* buffer[SIZE];
int in = 0;
int out = 0;


sem_t empty;
sem_t full;


void* prodecteur(void* arg){
	for(int i = 0; i < 10; i++){
		char* item = malloc(20);
		sprintf(item, "Pro%d", i);

		sem_wait(&empty);
		
		buffer[in] = item;
		in = (in + 1) % SIZE;

		sem_post(&full);

		sleep(1);
	}

	printf("\nProcduction fini ...\n");

return NULL;
}
void* consomateur(void* arg){
	for(int i = 0; i < 10; i++){
		sem_wait(&full);

		char* item = buffer[out];
		out = (out + 1) % SIZE;
		
		sem_post(&empty);
		
		printf("\nConsume %s\n", item);
		free(item);

		sleep(2);
	}

	printf("\nComsomateur fini\n");

	return NULL;
}

int main(){
	pthread_t pro, con;
	
	sem_init(&empty, 0, SIZE);
	sem_init(&full, 0, 0);

	pthread_create(&pro, NULL, prodecteur, NULL);
	pthread_create(&con, NULL, consomateur, NULL);
	
	pthread_join(pro, NULL);
	pthread_join(con, NULL);
return 0;	
}
