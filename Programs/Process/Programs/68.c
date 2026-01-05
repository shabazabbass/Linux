#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	printf("parent process is started :%d\n",getpid());
	pid_t child_id[3],pid;
	pid = fork();
	if(pid == 0){
		printf("child process1: %d\n",getpid());
		while(1);
	}
	else{
		child_id[0] = pid;
		pid = fork();
		if(pid == 0){
			printf("child process2: %d\n",getpid());
			while(1);
		}
		else{
			child_id[1] = pid ;
			pid  = fork();
			if(pid == 0){
				printf("child process3: %d\n",getpid());
				while(1);
			}
			else{
				child_id[2] = pid;
				/*for(int i = 0; i < 3; i++ ){
					printf("from parent : %d\n",child_id[i]);
				}*/
				for(int i = 0; i < 3;i++){
					int status;
					printf("wait for %d to exit\n",child_id[i]);
					pid_t w_pid = waitpid(child_id[i],&status,WUNTRACED);
					if(w_pid == -1){
						perror("error waitpid function:");
					}
					if(WIFSIGNALED(status)){
						printf("the %d process is abnormally using signal %d\n",w_pid,WTERMSIG(status));
					}
				}
				printf("parent has been exited\n");
				//while(1);
			}
		}

	}
}
