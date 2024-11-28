#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>

#define SHM_SIZE 1024

int main(){
	key_t key = 1234;
	int shm_id, result;
	char *string = NULL;
	shm_id = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
	if(shm_id == -1){
		perror("shmget ");
		exit(EXIT_FAILURE);
	}

	string = shmat(shm_id, NULL, 0);

	if(string == (char*) -1){
		perror("shmat:");
		exit(EXIT_FAILURE);
	}

	strcpy(string,"hello");

	result = shmdt(string);
	if(result == -1){
		perror("shmdt");
		exit(EXIT_FAILURE);
	}

	result = shmctl(shm_id, IPC_RMID, 0);
	if(result == -1){
		perror("shmctl");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
