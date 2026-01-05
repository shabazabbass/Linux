#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	printf("the program has been started\n");
	if(fork() == 0){
		printf("child process: %d\n",getpid());
		while(1);
	}
	else{
		int status;
		wait(&status);
		printf("WIFEXITED : %d\n",WIFEXITED(status));
		printf("WIFSIGNALLED : %d\n",WIFSIGNALED(status));
	}
}
