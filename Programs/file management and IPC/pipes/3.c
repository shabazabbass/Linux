#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>

int main(){
	printf("start of the program\n");
	sleep(1);
	printf("creating pipe..\n");
	sleep(1);
	int fd[2];
	int result = pipe(fd);
	if(result == -1){
		perror("pipe function ");
		exit(EXIT_FAILURE);
	}
	else{
		printf("pipe has been created succesfully\n");
		sleep(1);
		printf("read = %d , write = %d\n",fd[0],fd[1]);
		sleep(1);
	}
	printf("creating the child fom the parent whose pid is %d\n",getpid());
	pid_t pid = fork();
	if(pid == 0 ){
		close(fd[0]);
		char child_string[30] = "Hello from the child ";
		printf("chid process has been craeted with pid %d\n",getpid());
		sleep(1);
		result = write(fd[1],child_string,sizeof(child_string));
		if(result == -1 ){
			perror("write_function ");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else if(pid > 0){
		close(fd[1]);
		char parent_string[30];
		int status;
		result = wait(&status);
		if(result == -1){
			perror("wait function: ");
			exit(EXIT_FAILURE);
		}
		if(WIFEXITED(status)){
			printf("the child has exited normally with status : %d\n",WEXITSTATUS(status));
			sleep(1);
		}
		printf("child process : has been succesfully exit\n");
		sleep(1);
		result = read(fd[0],parent_string,sizeof(parent_string));
		if(result == -1){
			perror("read failure:");
			exit(EXIT_FAILURE);
		}
		printf("the string which we recived  from the child is %s\n",parent_string);
		sleep(1);
		exit(EXIT_SUCCESS);
	}
	else{
		perror("fork function ");
	}

}

