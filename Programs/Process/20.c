#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

void cleanup_fun(void);

int main(){
	printf("the program has been started succesfully\n");
	atexit(cleanup_fun);
	int *p=NULL;
	//*p =23;
	printf("the program has been ended\n");

}
void cleanup_fun(void){
	printf("the exit is done after all the clean up\n");
	return ;
}
