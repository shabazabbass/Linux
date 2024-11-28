#include<stdio.h>
#include<unistd.h>
int main(){
	char *arg[]={"hello","bii",NULL};
	int result = execv("./exfile",arg);
	if(result == -1){
		perror("Error :");
	}
}
