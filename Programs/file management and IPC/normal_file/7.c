#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define BUFFER_SIZE 1
int main(){
	int fd;
	char c;
	fd = open("file.txt", O_RDONLY);
	if(fd == -1){
		perror("open function");
		exit(EXIT_FAILURE);
	}
	while(read(fd, &c,BUFFER_SIZE) > 0){
		write(STDOUT_FILENO, &c, BUFFER_SIZE);
	}
	close(fd);
	printf("end of the program\n");
}
