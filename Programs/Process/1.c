#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
	pid_t id;
	id = fork();
	if(id == 0){
		printf("child process is running\n");
	}
	else{
		printf("parent process is running\n");
	}
	printf("common code\n");
	while(1);
}
