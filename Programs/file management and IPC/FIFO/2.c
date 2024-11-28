#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
	int fd;
	char write_str[] = "hello world";

	fd = open("myfifo",O_WRONLY);
	if(fd == -1){
		perror("open:");
		exit(EXIT_FAILURE);
	}

	int result = write(fd, write_str, sizeof(write_str));
	if(result == -1){
		perror("write:");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}

