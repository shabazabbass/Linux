#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main(){
	// 0 -- stdin
	// 1 -- stoutput
	// 2 -- stderr
	char string[] = "hello\n";
	write(2,string,strlen(string));
	write(2,string,3);
	write(2,"\n",1);
	write(2,string,10);
}
