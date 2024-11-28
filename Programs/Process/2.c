#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
	printf("parent process is running\n");
	fork();
	printf("this is after fork\n");
	while(1);
}

