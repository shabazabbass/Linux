#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t mutex;
unsigned long int count = 0;
void* routine(void*);

int main(){
	pthread_t t1, t2;
	int ret_val;
	ret_val = pthread_mutex_init(&mutex, NULL);
	if(ret_val != 0){
		perror("pthread_mutex_init");
		exit(EXIT_FAILURE);
	}

	ret_val = pthread_create(&t1, NULL, routine, NULL);
	if(ret_val != 0){
		perror("pthread_create ");
		exit(EXIT_FAILURE);
	}
	
	ret_val = pthread_create(&t2, NULL, routine, NULL);
	if(ret_val != 0){
		perror("pthread_create ");
		exit(EXIT_FAILURE);
	}

	ret_val = pthread_join(t1, NULL);
	if(ret_val != 0){
		perror("pthread_join");
		exit(EXIT_FAILURE);
	}

	ret_val = pthread_join(t2, NULL);
	if(ret_val != 0){
		perror("pthread_join");
		exit(EXIT_FAILURE);
	}

	printf("the final value of count is %ld\n",count);
	pthread_mutex_destroy(&mutex);

}

void* routine(void *arg){
	for(unsigned long int i = 0;i< 1000000; i++){
		pthread_mutex_lock(&mutex);
		count++;
		pthread_mutex_unlock(&mutex);
	}
}

