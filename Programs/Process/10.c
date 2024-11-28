#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
	int x = 10;
	if(fork() == 0){
		x=100;
		printf("child process x: %d\n",x);
	}
	else{
		printf("parent process x: %d\n",x);
	}
	while(1);
}
