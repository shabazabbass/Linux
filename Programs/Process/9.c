#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
	printf("start of the program\n");
	for(int i = 0;i < 3;i++){
		if(fork() == 0){
			printf("child \n");
		}
		else{
			return 0;
		}
	}
	while(1);
}