#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(){
	if(wait(NULL) == -1){
		perror("wait:");
	}
}
