#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	if(fork() == 0){
		printf("child process id : %d  group id : %d\n",getpid(),getpgid(getpid()));
	}
	else{
		printf("parent process id : %d  group id : %d\n",getpid(),getpgid(getpid()));
	}
}
