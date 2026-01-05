// zombie process

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	printf("start of the program\n");
	if(fork() == 0){
		printf("child process id : %d\n",getpid());
		printf("child process has been ended\n");
		exit(0);
	}
	else{
		printf("parent process id: %d\n",getpid());
		sleep(30);
		printf("parent process has been ended\n");
		exit(0);
	}
}
