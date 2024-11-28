#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

unsigned long int count = 0; 
void* routine(void*);
int global;

int main(){
	pthread_t t1, t2;
	int ret_val;

	ret_val = pthread_create(&t1, NULL, routine, NULL);
	if(ret_val != 0){
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}

	ret_val = pthread_create(&t2, NULL, routine, NULL);
	if(ret_val != 0){
		perror("pthread_create");
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
	// you will get irregular value because of race condition
	printf("the final value of count is %ld\n",count);
}

void* routine(void* arg){
	void **ret_value = (void**)&(global);
	for(unsigned long int i = 0 ;i < 1000000 ;i++ ){
		count++;
	}
	pthread_exit(ret_value);
}
