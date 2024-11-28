#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
int main(){
	pid_t pid;
	pid = fork();
	if(pid == -1){
		printf("fork has failed due to this reason and the error code is %d\n",errno);
		return errno;
	}
	if(pid == 0){
		printf("child process is running\n");
		//return 0;
	}
	else{
		printf("parent process is running\n");
		//return 0;
	}
	printf("common code\n");
	while(1);
}
