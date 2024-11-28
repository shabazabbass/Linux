// just creating  the fifo file 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	int result;
	result = mkfifo("myfifo",0666);
	if(result == -1){
		perror("mkfifo "); 
	}
	else{
		printf("fifo has been created succesfullly\n");
	}

}
