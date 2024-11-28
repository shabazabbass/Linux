#include<stdio.h>
#include<stdlib.h>
#include"mymath.h"
int main(){
	int a = 2, b = 2; 
	printf("add : %d\n",add(a, b));
	printf("sub : %d\n",sub(a, b));
	printf("mul : %d\n",mul(a, b));
	printf("div : %d\n",my_div(a, b));
	printf("mod : %d\n",mod(a, b));
}
