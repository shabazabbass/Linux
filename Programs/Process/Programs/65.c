#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	printf("parent process has been started id : %d\n",getpid());
	pid_t pid;
	pid = fork();
	if(pid == 0){
		printf("child process is running : %d \n",getpid());
		//exit(1);
		while(1);
	}
	else{
		int status;
		pid_t pid = waitpid(-1,&status,WUNTRACED);
		if(pid == -1){
			perror("waitpid function:");
		}
		if(WIFEXITED(status)){
			printf("%d exited normally with status  %d\n",pid,WEXITSTATUS(status));
		}
		else if(WIFSIGNALED(status)){
			printf("%d exited abnormally with status %d\n",pid,WTERMSIG(status));
		}
		else if(WIFSTOPPED(status)){
			printf("%d  is stopped by %d signal\n",pid,WSTOPSIG(status));
		}
		printf("parent exited\n");
	}

}
