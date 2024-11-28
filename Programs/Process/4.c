#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	if(fork() == 0){
		printf("chid pid : %d main parent pid : %d\n",getpid(),getppid());
		if(fork() == 0){
			printf("childs child pid : %d his parent pid : %d\n",getpid(),getppid());
		}
	}
	else{
		printf("main parent pid : %d his parent pid  : %d ",getpid(),getppid());
		
	}
	while(1);
}
