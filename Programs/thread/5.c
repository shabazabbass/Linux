#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t mutex;

void* routine(void*);

int main(){
	pthread_t t[4];
	int ret_val;
	ret_val = pthread_mutex_init(&mutex, NULL);
	if(ret_val != 0){
		perror("pthread_mutex ");
		exit(EXIT_FAILURE);
	}

	for(int i = 0;i < 4;i++){
		ret_val = pthread_create(&t[i], NULL, routine, NULL);
		if(ret_val != 0){
			perror("pthread_create");
			exit(EXIT_FAILURE);
		}
	}

	for(int i = 0;i < 4;i++){
		ret_val = pthread_join(t[i], NULL);
		if(ret_val != 0){
			perror("pthread_join ");
			exit(EXIT_FAILURE);
		}
	}
	pthread_mutex_destroy(&mutex);

}

void* routine(void* arg){
	if(pthread_mutex_trylock(&mutex) == 0){
		printf("mutex is unlocked succesfully\n");
	}
	else{
		printf("mutex is not properly achieved\n");
	}
}
