#include<stdio.h>
#include<setjmp.h>

jmp_buf buffer;

int add(int,int);
int sub(int,int);
int div(int,int);
int mul(int,int);

int main(){
	int a,b,op,result;
	printf("program has been started\n");
	result = setjmp(buffer);

	if(result == 2){
		printf("error in division operation\n");
	}
	else if (result == 1){
		printf("error in multiplication operation\n");
	}

	printf("Enter the value of a\n");
	scanf(" %d",&a);

	printf("Enter the value of b\n");
	scanf(" %d",&b);

	printf("Press 1 for addition\n"
	       "Press 2 for substraction\n" 
	       "Press 3 for multiplication\n" 
	       "Press 4 for division\n");
	scanf(" %d",&op);

	if(op == 1){
		printf("the sum is %d\n",add(a,b));
	}
	else if(op == 2){
		printf("the difference is %d\n",sub(a,b));
	}
	else  if(op == 3){
		printf("the product is %d\n",mul(a,b));
	}
	else if(op == 4){
		printf("the quosint is %d\n",div(a,b));
	}
	else{
		printf("invalid operation\n");
	}
}

int add(int a, int b){
	printf("addition is being performed\n");
	return a+b;
}

int sub(int a,int b){
	printf("substraction is being performed\n");
	return a-b;
}

int mul(int a,int b){
	printf("multiplication is being performed\n");
	if((a == 0) || (b == 0)){
		longjmp(buffer,1);
	}
	return a*b;
}

int div(int a, int b){
	printf("division is being performed\n");
	if(b == 0){
		longjmp(buffer,2);
	}
	return a/b;
}


