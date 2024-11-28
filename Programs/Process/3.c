#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
int main(){
	pid_t pid;
	pid = getpid();
	printf("parent process id : %u\n",pid);
	pid = fork();
	if(pid == 0){
		perror("child 1 creation  ");
		printf("child 1 pid : %u parent pid %u \n ",getpid(),getppid());
		return EXIT_SUCCESS;
	}
	else if(pid > 0){
		pid  = fork();
		if(pid ==  0){
			perror("child 2 creation  ");
			printf("child 2 pid : %u parent pid %u \n ",getpid(),getppid());
			return EXIT_SUCCESS;	
		}
		else if(pid >  0) {
//			sleep(10);
			return EXIT_SUCCESS;
		}
		else{
			perror("child 2 creation ");
			return errno;
		}
	
	}
	else{
		perror("child 1 creation : ");
		return errno ;
	}
}
