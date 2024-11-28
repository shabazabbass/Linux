#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(){
	int fd;
	fd = open("file.txt",O_RDONLY|O_WRONLY|O_RDWR);
	perror("open");
}
