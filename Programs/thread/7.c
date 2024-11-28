#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

int global = 10;
void* routine(void*);
sem_t s;
unsigned long int count = 0; 

int main(){
	pthread_t t1, t2;
	sem_init(&s, 0 , 1);
	int ret_val;
	ret_val = pthread_create(&t1, NULL, routine, NULL);
	if(ret_val != 0){
		perror("pthread create");
		exit(EXIT_FAILURE);
	}
	ret_val = pthread_create(&t2, NULL, routine ,NULL);
	if(ret_val != 0){
		perror("pthread create");
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
	sem_destroy(&s);
	printf("the final value of count is %ld\n",count);
	exit(EXIT_SUCCESS);

}

void *routine(void *arg){
	void **ret_value = (void**) &global;
	for(unsigned int i = 0; i < 1000000; i++){
		sem_wait(&s);
		count++;
		sem_post(&s);
	}
	pthread_exit(ret_value);
}
