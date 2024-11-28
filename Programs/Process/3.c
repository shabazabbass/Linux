#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
	printf("parent process id : %d \n",getpid());
	if(fork() == 0){
		printf("child process id : %d parent process id : %d \n",getpid(),getppid());
	}
	else{
		if(fork() == 0){
			printf("child process id : %d parent process id : %d \n",getpid(),getppid());
		}
		else{
			;
		}
		while(1);
	}
}

