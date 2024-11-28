#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	printf("start of the program\n");
	pid_t pid = wait(NULL);
	if(pid == -1){
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	else{
		exit(EXIT_SUCCESS);
	}
}
