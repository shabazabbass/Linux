#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
	pid_t pid;
	pid = fork();
	if(pid == 0){
		printf("child process\n");
	}
	else if(pid > 0) {
		printf("parent process\n");
	}
	else{
		perror("Process not created because: ");
	}
}
