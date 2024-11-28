#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


void wait_check(int);
int main(){
	if(fork() == 0){
		printf("child1 : %d\n",getpid());
		sleep(10);
		exit(EXIT_SUCCESS);
	}
	else{
		if(fork() == 0){
			printf("child2 : %d\n",getpid());
			sleep(6);
			exit(EXIT_SUCCESS);
		}
		else{
			if(fork() == 0){
				printf("child3: %d\n",getpid());
				sleep(8);
				exit(EXIT_SUCCESS);
			}
			else{
				int ret_val;
				ret_val = wait(NULL);
				wait_check(ret_val);
				ret_val = wait(NULL);
				wait_check(ret_val);
				ret_val = wait(NULL);
				wait_check(ret_val);
				ret_val = wait(NULL);
				wait_check(ret_val);
			}
		}
	}
}

void wait_check(int ret_val){
	if(ret_val == -1){
		perror("Error: ");
		return;
	}
	else{
		printf("%d process has beeen terminated\n",ret_val);
	}
}
