#include<stdio.h>
#include<unistd.h>

extern char **environ;

int main(){
	printf("program has been started\n");
	char *argv[]={"hello","bii",NULL};
	execve("./exfile",argv,environ);
}
