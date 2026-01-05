#include<stdio.h>
#include<stdlib.h>
void cleanup1(void);
void cleanup2(void);

int main(){
	atexit(cleanup1);
	atexit(cleanup2);
}

void cleanup1(void){
	printf("cleanup function1 is called\n");
	return;
}

void cleanup2(void){
	printf("cleanup function2 is called\n");
	return;
}


