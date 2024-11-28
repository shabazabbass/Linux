#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
	int fd = open("nonexisting file\n",O_RDONLY);
	printf("file descriptor: %d\n",fd);
	if(fd == -1){
		perror("open function:");
	}
}
