#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int result;
	result = unlink("myfifo");
	if(result == -1){
		perror("unlink ");
		exit(EXIT_FAILURE);
	}
	else{
		printf("was succesfully able delete mkfifo\n");
		exit(EXIT_SUCCESS);
	}
}
