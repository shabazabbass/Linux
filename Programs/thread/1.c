#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int global;
void* routine(void*);

int main(){
	int *res, ret_val;
	pthread_t t1;

	ret_val = pthread_create(&t1, NULL, routine, NULL);
	if(ret_val != 0){
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}

	ret_val = pthread_join(t1, (void **)&res);
	if(ret_val != 0){
		perror("pthread_join");
		exit(EXIT_FAILURE);
	}

	printf("the returned value is %d\n",*res);

}

void* routine(void* arg){
	printf("routine is executing\n");
	global = 10;
	pthread_exit((int*)&global);
}
