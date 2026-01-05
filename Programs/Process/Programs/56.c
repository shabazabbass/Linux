#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	printf("parent process has been started\n");
	if(fork() == 0){
		printf("child has been started : %d\n",getpid());
		while(1);
	}
	else{
		int status;
		printf("parent process has been started\n");
		pid_t pid = wait(&status);
		if(pid == -1){
			perror("wait error:");
			exit(EXIT_SUCCESS);
		}	
		printf("WTERMSIG : %d\n",WTERMSIG(status));
	}
}
