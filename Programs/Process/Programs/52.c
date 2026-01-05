// here i am demonstrating the three macros
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


int main(){
	printf("start of the program\n");
	if(fork() == 0){
		printf("child process is executing : %d\n",getpid());
		//exit(EXIT_SUCCESS);// exit normally
		//exit(EXIT_FAILURE);//exit normally
		while(1);// exit using signal 

		// exit using stop is done in next program
	}
	else{
		int status;
		printf("parent process is excuting and wait for child to exit\n");
		pid_t pid = wait(&status);
		if(pid == -1){
			perror("wait function ERROR : ");
			exit(EXIT_FAILURE);
		}
		if(WIFEXITED(status)){
			printf("child process exited normally : %d\n",WIFEXITED(status));
		}
		else if(WIFSIGNALED(status)){
			printf("child proceess exited because of signal : %d\n",WIFSIGNALED(status));
		}
		else if(WIFSTOPPED(status)){
			printf("child process exited because of stopp : %d \n",WIFSTOPPED(status));
		}
		printf("parent exited succesully\n");
		//while(1);
		exit(EXIT_SUCCESS);
	}
}
