#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int idata=100;
int main(){
	int sdata=100;
	pid_t pid;
	printf("the program has been started");
	pid = fork();
	switch(pid ){
		case 0: 
			idata += 100;
			sdata += 100;
			break;
		case -1:
			perror("fork:");
			break;
		default:
			idata += 50;
			sdata += 50;
			break;
	}
	pid == 0 ? printf("child process idata: %d sdata : %d\n",idata,sdata):printf("parent process idata: %d sdata : %d\n",idata,sdata); 
}
