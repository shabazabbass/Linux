#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
int main(){
	FILE *p = fopen("dbjv","r");
	fprintf(stderr, "Error opening file: %s\n", strerror(errno));
}
