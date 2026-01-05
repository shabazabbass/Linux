#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

extern char **environ;
int main(){
	execle("./exfile","ddd","hello",NULL,environ);
	perror("run");
}
