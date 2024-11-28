#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
	int fd, result;
	char read_string[20];
	fd = open("myfifo",O_RDONLY);
	if(fd == -1){
		perror("open ");
		exit(EXIT_FAILURE);
	}
	result = read(fd, read_string, sizeof(read_string));
	if(result == -1){
		perror("read ");
		exit(EXIT_FAILURE);
	}
	printf("the data whih has been recived is %s\n",read_string);
	exit(EXIT_SUCCESS);
}
