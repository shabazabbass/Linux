#include<stdio.h>
#include<string.h>

#define MAX_STR_SIZE 20
int main(){
	char str[MAX_STR_SIZE];
	while(1){
		printf("Enter the string\n");
		scanf("%[^\n]s",str);
		getchar();
		if(strcmp("end",str) == 0){
			break;
		}
	};
}
