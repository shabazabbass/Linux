#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
	pid_t  pid,pgpid;
	pid = getpid();
	pgpid = getpgid(pid);
	printf("process id: %d group id : %d\n",pid,pgpid);
	pid_t new_pgid = 1234;
	if(setpgid(0,pid) == -1){
		perror("setpgid :");
	}
	pgpid = getpgid(pid);
	printf("process id: %d new group id : %d\n",pid,pgpid);
}

