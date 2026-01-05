#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	printf("parent process has been started\n");
	if(fork() == 0){
		sleep(5);
		exit(0);
	}
	else{
		sleep(2);
		pid_t pid = waitpid(-1,NULL,WNOHANG);
		if((pid == -1) || (pid == 0)){
			perror("waitpid:");
		}
		if(pid == 0){
			printf("no process has been exited now we will use wait\n");
			wait(NULL);
		}
		printf("parent exited\n");

	}
}
