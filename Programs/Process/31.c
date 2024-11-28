#include<stdio.h>
extern char **environ;

int main(int argn, char *argvar[],char *envar[]){
	int i = 0;
	while(environ[i] != NULL){
		printf("%d : %s\n",i,environ[i++]);
	}
	i = 0;
	while(envar[i] != NULL){
		printf("%d : %s\n",i,envar[i++]);
	}

}
