#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int main(){
	signal(SIGINT, SIG_DFL);
	while(1);
}
