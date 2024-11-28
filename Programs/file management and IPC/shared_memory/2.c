#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define SHM_SIZE 1024

int main(){
	key_t key = 1234;
	int *ptr = NULL, result;
	
	int shm_id = shmget(key,SHM_SIZE, IPC_CREAT | 0666);
	if(shm_id == -1){
		perror("error shmget:");
		exit(EXIT_FAILURE);
	}

	ptr = shmat(shm_id, NULL, 0);
	
	if(ptr == (int*)-1){
		perror("allocate:");
		result = shmctl(shm_id, IPC_RMID, NULL);
		if(result == -1){
			perror("shmctl:");
		}
		exit(EXIT_FAILURE);
	}

	result = shmdt(ptr);

	if(result == -1){
		perror("deallocate");
	}
	
	result = shmctl(shm_id, IPC_RMID, NULL);
	
	if(result == -1){
		perror("shmtl ");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
