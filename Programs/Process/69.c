#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	int time;
	printf("parent process has been started\n");
	srand(getpid());
	if(fork() == 0){
		time = rand() % 10 + 1;
		sleep(time);
		exit(1);
	}
	else{
		if(fork() == 0){
			time = rand() % 10 + 1;
		        sleep(time);
			exit(2);

		}
		else{
			if(fork() == 0){
				time = rand() % 10 + 1;
				sleep(time);
				exit(3);
			}
			else{
				int status;
				while(wait(&status) != -1){
					int ret = WEXITSTATUS(status);
					if(ret == 1){
						printf("child1  exited\n");
					}
					else if (ret == 2){
						printf("child2 exited\n");
					}
					else if (ret == 3){
						printf("child3 exited\n");
					}
					sleep(2);
				}
				printf("parent exited\n");
			}
		}	
	}
}
