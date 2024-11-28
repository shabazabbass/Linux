#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int global;
void* routine(void*);

int main(){
	pthread_t t1;
	int ret_val, *ptr;
	int a[5] = {2, 4, 6, 8, 10};

	ret_val = pthread_create(&t1, NULL, routine, a);
	if(ret_val != 0){
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}

	ret_val = pthread_join(t1, (void **)&ptr);
	if(ret_val != 0){
		perror("pthread_join");
		exit(EXIT_FAILURE);
	}
	printf("the value which is returned is %d\n",*ptr);
}

void* routine(void *arg){
	int *ptr = (int*)arg;
	for(int i = 0;i < 5; i++){
		printf("%d\n",*(ptr + i));
	}
	global = 10;
	pthread_exit(&global);
}
