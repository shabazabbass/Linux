// this program will teach us how to create the shared memory 

#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<sys/ipc.h>

#define SHM_SIZE 1024

int main(){
	key_t key = 1234;

	int shm_id = shmget(key,SHM_SIZE,IPC_CREAT | 0666);
	//int shm_id = shmget(key, SHM_SIZE, 0666);
	
	if(shm_id < 1){
		perror("shmget ");
		exit(EXIT_FAILURE);
	}

	printf("the shm_id  is %d\n",shm_id);
	int result = shmctl(shm_id,IPC_RMID,NULL);
	if(result == -1 ){
		perror("shmctl ");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
