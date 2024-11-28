#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	int fd[2];
	int status = pipe(fd);
	if (status == -1){
		perror("pipe ");
		exit(EXIT_FAILURE);
	}
	char string[] = "hello world\n",str2[20];
	//close(fd[1]);
	status = write(fd[1],string,sizeof(string));
	if(status == -1){
		perror("pipe write ");
		exit(EXIT_FAILURE);
	}
	//close(fd[0]);
	status = read(fd[0],str2,sizeof(string));
	if(status == -1){
		perror("pipe read ");
		exit(EXIT_FAILURE);
	}
	printf("%s \n",str2);
}
