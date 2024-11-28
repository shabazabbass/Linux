#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	printf("parent process has been stated : %d\n",getpid());
	if( fork() == 0){
		printf("child 1: %d  parent : %d\n",getpid(),getppid());
		exit(2);
	}
	else{
		if(fork() == 0){
			printf("child 2: %d parent : %d\n",getpid(),getppid());
			while(1);
		}
		else{
			if(fork() == 0){
				printf("child 3: %d parent : %d\n",getpid(),getppid());
				while(1);
			}
			else{
				printf("for loop : %d\n",getpid());
				pid_t pid;
				int status;
				for(int i = 0; i < 4; i++){
					pid = wait(&status);
					if(pid == -1){
						perror("wait function:");
					}
					else if (WIFEXITED(status)){
						printf("the %d has been normally exited with status :%d\n",pid,WEXITSTATUS(status));
					}
					else if (WIFSIGNALED(status)){
						printf("the %d has been abnormally exited with signal : %d\n",pid,WTERMSIG(status));
					}
				}
			}
		}
	}

}
