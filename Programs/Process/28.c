// creating a executable file (exfile) for execl family

#include<stdio.h>
int main(int n ,char *argv[]){
	printf("program has been started\n");
	printf("Number of arguments is %d\n",n);
	printf("the arguments are :\n");
	for(int i = 0; i < n;i++ ){
		printf("%d : %s\n",i,argv[i]);
	}
	printf("the program has been finished\n");
}

