#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>
int main(){
	pid_t pid;
	pid = fork();
	if(pid == -1){
		printf("Error Description: %s \n",strerror(errno));
		perror("Fork Failed");
		return errno;
	}
	if(pid == 0){
		perror("Child Process: ");
		printf("child process is running\n");
		//return 0;
	}
	else{
		perror("Parent Process: ");
		printf("parent process is running\n");
		//return 0;
	}
	printf("common code\n");
	while(1);
}
