#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

sem_t sem;
void* routine(void*);
int global;
int main(){
	int ret_val;
	pthread_t t[10];
	ret_val = sem_init(&sem, 0, 4);
	if(ret_val != 0){
		perror("sem_init");
		exit(EXIT_FAILURE);
	}

	for(int i = 0; i< 10 ; i++){
		int *p = malloc(sizeof(int));
		*p = i;
		ret_val = pthread_create(&t[i], NULL, routine, p);
		if(ret_val != 0){
			perror("pthread_create");
			exit(EXIT_FAILURE);
		}
	}

	for(int i = 0; i < 10; i++ ){
		ret_val = pthread_join(t[i], NULL);
		if(ret_val != 0){
			perror("pthread_join");
			exit(EXIT_FAILURE);
		}
	}
	sem_destroy(&sem);
	exit(EXIT_SUCCESS);
}

void* routine(void* arg){
	void *ret_val = &global;
	sem_wait(&sem);
	printf("%d thread is runnig\n",*(int*)arg);
	sleep(3);
	printf("%d thread is being released\n",*(int*)arg);
	sem_post(&sem);
	pthread_exit(ret_val);
}

