#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	printf("parent process has been started\n");
	pid_t pid = fork();
	if(pid == 0){
		exit(0);
	}
	else{
		int status;
		waitpid(pid,&status,0);//default beahviour od wait waits untill teh process of particular id has been terminated
		perror("waitpid function:");

	}
}
