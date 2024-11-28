#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	pid_t parent_pid;
	parent_pid = getpid();
	printf("main parent id : %d\n",parent_pid);
	for(int i = 0;i < 5 ; i++ ){
		if(getpid() == parent_pid){
			sleep(2);
			pid_t pid = fork();
			if( pid == 0){
				printf("child%d : %d parentid: %d\n",i,getpid(),getppid());
			}
		}
	}
}
