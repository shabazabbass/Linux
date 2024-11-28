#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void signal_handler(int);
int main(){
	signal(SIGINT, signal_handler);
	raise(SIGINT);
}

void signal_handler(int signal_number){
	printf("signal number %d is called\n",signal_number);
	exit(0);
}
