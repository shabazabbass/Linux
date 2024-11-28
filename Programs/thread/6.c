#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int global = 10;
#define R1TURN 0
#define R2TURN 1
int turn = R1TURN;
void* routine1(void*);
void* routine2(void*);

int main(){
	pthread_t t1,t2;
	int ret_val;
	ret_val = pthread_create(&t1, NULL, routine1, NULL);
	if(ret_val != 0){
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}
	ret_val = pthread_create(&t2, NULL, routine2, NULL);
	if(ret_val != 0){
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}
	ret_val = pthread_join(t1, NULL);
	if(ret_val != 0){
		perror("pthread_join");
		exit(EXIT_FAILURE);
	}
	ret_val =pthread_join(t2, NULL);
	if(ret_val != 0){
		perror("pthread_join");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);

}

void* routine1(void* arg){
	void **ret_value = (void**)&(global);
	for(int i = 0; i < 10; i++){
		while(turn == R2TURN);
		printf("routine1 : %d\n",i);
		sleep(1);
		turn = R2TURN;
	}
	pthread_exit(ret_value);
}

void* routine2(void* arg){
	void **ret_value = (void**)&global;
	for(int i = 0; i < 10; i++){
		while(turn == R1TURN);
		printf("routine2 : %d\n",i);
		sleep(1);
		turn = R1TURN;
	}
	pthread_exit(ret_value);
}
