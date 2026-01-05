#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	printf("parent process has been started\n");
	if(fork () == 0){
		printf("child process has been started : %d\n",getpid());
		//exit(2);// exit normally 
		while(1);// exit abnormally
	}
	else{
		int status;
		printf("in parent process\n");
		pid_t pid = wait(&status);
		if(pid == -1){
			perror("wait function : ");
			exit(EXIT_SUCCESS);
		}
		if(WIFEXITED(status)){
			printf("exited normally by exit status: %d\n",WEXITSTATUS(status));
		}
		else if(WIFSIGNALED(status)){
			printf("exited abnormally by the signal %d\n",WTERMSIG(status));
		}	
	}
}
