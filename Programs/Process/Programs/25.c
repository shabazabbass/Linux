#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void cleanup1(void);
void cleanup2(void);
void cleanup3(void);

int main(){
	long result;
	result = sysconf(_SC_ATEXIT_MAX);
	printf("the number od exit function which can be called is %ld\n", result);
	atexit(cleanup1);
	result = sysconf(_SC_ATEXIT_MAX);
	printf("the number od exit function which can be called is %ld\n", result);
	atexit(cleanup2);
	result = sysconf(_SC_ATEXIT_MAX);
	printf("the number od exit function which can be called is %ld\n", result);
	atexit(cleanup3);
	result = sysconf(_SC_ATEXIT_MAX);
	printf("the number od exit function which can be called is %ld\n", result);

}

void cleanup1(void){
	printf("cleanup function1 is called\n");
	return;
}

void cleanup2(void){
	printf("cleanup function2 is called\n");
	return;
}

void cleanup3(void){
	printf("cleanup function3 id called\n");
}



	
