#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void check_error(int );
int main(){
	int result;
	//result = execl("./non_existing_file","sv",NULL);
	//check_error(result);
	//result = execl("./exfile","exfile",NULL);
	//check_error(result);
	//result = execl("./","exfile",NULL);
	//check_error(result);
	//result = execl("./exfile","ddd","dd",NULL);
	//check_error(result);
	//result = execl("/bin/ls","ddd","-l",NULL);
	//check_error(result);
	//result = execl("/bin/ls","ddd",NULL);
	//check_error(result);
	result = execl("/bin/ls",NULL);// this it will not allow
	check_error(result);
}
void check_error(int result){
	if(result == -1){
		perror("Exec Error:");
	}
	return;
}
