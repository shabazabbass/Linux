#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void signal_handler(int );

int main(){
	signal(SIGINT, signal_handler);
	while(1);
}

void signal_handler(int sig_num){
	printf("signal  %d is called\n", sig_num);
	exit(0);
}
