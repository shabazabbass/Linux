#include<stdio.h>
#include<unistd.h>
int main(){
	char a[10];
	read(1,a,10);
	write(2,a,10);
}
