#include<stdio.h>
#include<stdlib.h>

void cleanup(int);

int main(){
	int result = atexit((void (*)(void))cleanup);
	printf("result is %d\n",result);

}
void cleanup(int x){
	printf("cleanup function is called\n");
	printf("the value of x is %d\n",x);
	return ;
}
