#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int compteur = 0;

void* increment(void* arg){
	for(int i = 0; i < 100000; i++){
		compteur++;
	}

return NULL;
}

void* decrement(void* arg){
	for(int i = 0; i < 100000; i++){
		compteur--;
	}

return NULL;
}



int main(){
	pthread_t t1, t2;
	
	pthread_create(&t1, NULL, increment, NULL);
	pthread_create(&t2, NULL, decrement, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("Compteur = %d\n", compteur);

return 0;
}
