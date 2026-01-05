#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>

int main(){
	if(fork() == 0){
		printf("child process has been started pid : %d\n",getpid());
		raise(SIGSTOP);
		exit(0);
		while(1);

	}
	else{
		int status;
		pid_t pid = wait(&status);
		if(pid == -1){
			perror("wait function:");
			exit(EXIT_SUCCESS);
		}
		printf("WIFEXITED : %d\n",WIFEXITED(status));
		printf("WIFSIGNALED : %d\n",WIFSIGNALED(status));
		printf("WIFSTOPPED : %d\n",WIFSTOPPED(status));
	}
}
