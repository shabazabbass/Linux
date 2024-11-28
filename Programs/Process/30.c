// in order to use execlp you have add youe exe file path to the PATH variable

#include<stdio.h>
#include<unistd.h>

int main(){
	printf("program has been started\n");
	//execlp("exfile","hello",NULL);
	execlp("ls","ls",NULL);
	perror("execlp:");
}
