#include<stdio.h>
#include<setjmp.h>
jmp_buf buff;
void abc();

int main(){
	printf("the program has been started\n");
	int var = setjmp(buff);
	printf("var return by setjmp is %d\n",var);
	abc();
	printf("end of main\n");

}

void abc(){
	static int var = 0;
	var++;
	if(var < 3){
		longjmp(buff,var);
	}
	printf("end of the abc\n");
}
