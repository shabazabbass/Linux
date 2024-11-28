#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	printf("the program has been started\n");
	if(fork() == 0){
		printf("child process has been started\n");
		exit(58);
	}
	else{
		int status;
		pid_t pid = wait(&status);
		if(pid == -1){
			perror("wait function:");
			exit(EXIT_SUCCESS);
		}
		printf("exit status WEXITSTATUS : %d\n",WEXITSTATUS(status));
		printf("exit status %d\n",status>>8 );

	}
}
