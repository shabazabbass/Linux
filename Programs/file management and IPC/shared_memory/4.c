#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>

#define SHM_SIZE 1024
int main(){
	pid_t pid;
	char *string = NULL;
	key_t key = 1234;
	int shm_id,result;
	shm_id = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
	if(shm_id < 0){
		perror("shmget ");
		exit(EXIT_FAILURE);
	}
	
	string = shmat(shm_id, NULL, 0);
	if(string == (char*)-1){
		perror("shmat");
		exit(EXIT_FAILURE);
	}

	pid = fork();
	if(pid == 0){
		printf("Enter the message you want to send to parent ");
		scanf("%[^\n]s",string);
		exit(EXIT_SUCCESS);
	}
	else{
		int status;
		pid_t wait_pid = wait(&status);
		if(wait_pid == -1){
			perror("wait ");
			exit(EXIT_FAILURE);
		}
		printf("the message send by child is %s\n",string);
		result = shmdt(string);
		if(result == -1){
			perror("shmdt ");
			exit(EXIT_FAILURE);
		}
		result = shmctl(shm_id, IPC_RMID, 0);
		if(result == -1){
			perror("shmctl ");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}	
}
