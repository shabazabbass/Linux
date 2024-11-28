#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	pid_t pid = waitpid(-1,NULL,WNOHANG);
	if(pid == -1){
		perror("waitpid function:");
	}
}
