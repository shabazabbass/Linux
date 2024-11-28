// first parent will executte completely then the child will execute

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	pid_t pid;
	printf("the program is has been started\n");

	pid = fork();
	if(pid == 0){
		sleep(5);
		printf("instruction1 of the child process\n");
		printf("instruction2 of the child process\n");
		printf("instruction3 of the child process\n");
	}
	else{
		printf("instruction1 of the parent process\n");
		printf("instruction2 of the parent process\n");
		printf("instruction3 of the parent process\n");
	}

	pid == 0 ? printf("child has been ended\n"):printf("parent has been ended\n"); 
	while(1);
}
