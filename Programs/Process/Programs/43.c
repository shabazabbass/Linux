#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(){
	printf("Program has been started\n");
	if(fork() == 0){
		printf("instruction1 of the child has been executed\n");
		printf("instruction2 of the child has been executed\n");
		printf("instruction3 of the child has been executed\n");
		exit(0);
	}
	else{
		wait(NULL);
		printf("instruction1 of the parent has been executed\n");
		printf("instruction2 of the parent has been executed\n");
		printf("instruction3 of the parent has been executed\n");
	}
}
