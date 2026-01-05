#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(){
	printf("main program has been started\n");
	if(fork() == 0){
		printf("Child process has been started\n");
		exit(1);
	}
	else{
		int status;
		wait(&status);
		printf("WIFEXITED : %d\n",WIFEXITED(status));
		printf("WIFSIGNALED : %d\n",WIFSIGNALED(status));
	}
}
