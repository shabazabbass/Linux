#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	printf("parent process has been started\n");
	if(fork() == 0){
		printf("child process is excuting\n");
		int *p = NULL;
		*p = 99;
	}
	else{
		int status;
		printf("parent process is being executed\n");
		pid_t pid = wait(&status);
		if(pid == -1){
			perror("wait error:");
			exit(EXIT_FAILURE);
		}	
		printf("WCOREDUMP : %d\n",WCOREDUMP(status));
		
	}
}
