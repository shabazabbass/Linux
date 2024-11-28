#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	pid_t pid;
	pid = fork();
	if(pid == 0){
		printf("child process is running\n");
		while(1);
	}
	else if (pid > 0){
		printf("parent process is runnimg\n");
		sleep(10);
		kill(pid, SIGINT);
		wait(NULL);
		printf("child process exited succesfully\n");
		printf("parent process also exited succesfully\n");
		exit(EXIT_SUCCESS);
	}
}
