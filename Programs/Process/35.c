#include<stdio.h>
#include<unistd.h>

int main(){
	printf("Program has been started\n");
	char *argv[]={"hello","bii",NULL};
	int result = execvp("exfile",argv);
	if(result == -1){
		perror("error:");
	}

}
