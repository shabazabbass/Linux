#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>

int main(){
	FILE *file_ptr;
	char file_name[25];
	printf("Enter the name of the file\n");
	scanf(" %[^\n]s",file_name);
	file_ptr = fopen(file_name,"r");
	if(file_ptr == NULL){
		perror("File: ");
		printf("the error number is %d\n",errno);
	}
	else{
		pid_t pid;
		char data;
		data = fgetc(file_ptr);
		pid = fork();
		while(data != EOF){
			pid == 0 ? printf("child process fetched %c\n",data):printf("parent proces fetched %c\n",data);
			data = fgetc(file_ptr);	
		}
		if(pid == 0){
			printf("child process has finished its task succesfully\n");
		}
		else{
			printf("parent process has finished its task succesfully\n");

		}	
	}
}

