#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	int fd[2];
	int result = pipe(fd);
	if(result == -1){
		perror("result : %d\n");
	}
	else{
		printf("pipe is created succesfully\n");
	}
}
