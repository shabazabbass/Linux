#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
int main(){
	pid_t pid;
	printf("Parent process id : %d \n",getpid());
	pid = fork();
	if(pid == 0){
		perror("Child creation ");
		printf("child id : %d parent id : %d \n",getpid(),getppid());
		pid = fork();
		if(pid == 0){
			perror("Grand Child creation ");
			printf("Grand child id : %d parent id : %d \n",getpid(),getppid());
			return EXIT_SUCCESS;
		}
		else if(pid > 0){
			sleep(2);
			return EXIT_SUCCESS;
		}
		else{
			perror("Grand Child creation ");
			return errno;
		}
	}
	else if(pid > 0){
		sleep(2);
		return EXIT_SUCCESS;
	}
	else{
		perror("Child creation ");
		return errno;
	}
	
}

