#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void cleanup(void);

int main(){
	printf("the program has been started\n");
	atexit(cleanup);
	_exit(0);
}

void cleanup(void){
	printf("cleanup function is called\n");
	return;
}

