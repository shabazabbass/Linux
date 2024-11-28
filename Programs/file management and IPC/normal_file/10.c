#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
	int fd = open("file.txt",O_RDONLY);
	if(fd == -1){
		perror("open ");
		exit(EXIT_FAILURE);
	}
	fd = dup(fd);
	printf("fd : %d\n",fd);
	perror("dup");
	fd =dup2(fd,0);
	perror("dup2");
	printf("fd : %d\n",fd);
}
