#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	printf("parent process has been started : %d\n",getpid());
	if(fork()  == 0){
		printf("child process has been started : %d\n",getpid());
		while(1);
	}
	else{
		int status;
		printf("parent process has been started\n");
		pid_t pid = waitpid(-1,&status,WCONTINUED);
		if(pid == -1){
			perror("waitpid:");
			exit(EXIT_FAILURE);
		}
		if(WIFCONTINUED(status)){
			printf("%d process has been stopped and continued\n",pid);
		}
		printf("parent file has been exited\n");
	}
}
