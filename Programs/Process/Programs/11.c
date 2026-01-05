#include<stdio.h>
#include<setjmp.h>
jmp_buf buff;
void abc();
int main(){
	printf("inside the main program\n");
	int v = setjmp(buff);
	printf("the value returned by setjmp is %d\n",v);
	abc();
	printf("end of the program\n");
}

void abc(){
	printf("inside the function abc");
	longjmp(buff,2);
	printf("end of the function program\n");
}
