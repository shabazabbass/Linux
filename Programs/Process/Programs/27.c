#include<stdio.h>
int main(){
	FILE *p;
	fprintf(stdout,"hello world\n");
	fprintf(stderr,"error world\n");
	p = fopen("non_existing_file","r");
	if(p == NULL){
		fprintf(stderr,"the file \n");
		perror("ERROR");
	}
}
