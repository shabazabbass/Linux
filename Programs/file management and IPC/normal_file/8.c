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
	fd = open("file2.txt",O_WRONLY| O_TRUNC);
	if(fd == -1){
		perror("open ");
		fd = open("file2.txt",O_CREAT|O_WRONLY| O_TRUNC, S_IRWXU);
		//exit(EXIT_FAILURE);
	}
	printf("write the content of the file\n");
	while(read(STDIN_FILENO,&c,BUFFER_SIZE)>0){
		write(fd,&c,BUFFER_SIZE);
	}
	close(fd);
}
