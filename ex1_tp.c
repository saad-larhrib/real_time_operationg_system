#include <stdio.h>
#include <pthread.h>
#include <unistd.h>



void* handler_1(void* arg){
	for(int i = 5; i > 0; i--){
	
		printf("\nThread 1 en cours...\n");
		sleep(1);
	}

return NULL;
}


void* handler_2(void *arg){
	for(int i = 3; i > 0; i--){
		printf("\nThread 2 en cours...\n");
		sleep(2);
	}
return NULL;
}


int main(){
	pthread_t t1, t2;

	pthread_create(&t1, NULL, handler_1, NULL);
	pthread_create(&t2, NULL, handler_2, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

return 0;
}
