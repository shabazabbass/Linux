#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	if(fork() == 0){
		//exit(EXIT_SUCCESS);
	//	exit(EXIT_FAILURE);
		//exit(10);
		return 88;
	}
	else{
		int status;
		wait(&status);
		printf("status is %d\n",status);
		exit(EXIT_SUCCESS);
	}
}
