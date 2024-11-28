// this program is to demonstrate orphan process

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main(){
	printf("start of the program\n");
	if(fork() == 0){
		printf("child process id: %d \n",getpid());
	}
	else{
		printf("parent process id: %d \n",getpid());
		exit(EXIT_SUCCESS);
	}
	while(1);

}
