#include<stdio.h>
#include<stdlib.h>

void cleanup1(void);
void cleanup2(void);
void cleanup3(void);

int main(){
	printf("program has been started\n");
	int result;
	result = atexit(cleanup1);
	printf("result : %d\n",result);
	result = atexit(cleanup2);
	printf("result : %d\n",result);
	result = atexit(cleanup3);
	printf("result : %d\n",result);
	printf("main program has been ended\n");
}

void cleanup1(void){
	printf("cleanup1 is called\n");
	return;
}

void cleanup2(void){
	printf("cleanup2 is called\n");
	return;
}

void cleanup3(void){
	printf("cleanup3 is called\n");
	return;
}
