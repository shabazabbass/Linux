#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
int main(){
	printf("parent process :  %d\n",getpid());
	raise(SIGSTOP);
}
