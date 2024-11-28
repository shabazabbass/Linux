#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

#define MSG_MAX 20
struct msgstr{
	long int msg_type;
	char msg[MSG_MAX];
}msg_var;

int main(){
	key_t key = 123;
	int msg_id, ret_value;	
	msg_id = msgget(key, IPC_CREAT| 0666);
	if(msg_id == -1){
		perror("msgget ");
		exit(EXIT_FAILURE);
	}
	msg_var.msg_type = 1;
        strcpy(msg_var.msg, "hello");
	ret_value = msgsnd(msg_id, (void*)&(msg_var), MSG_MAX, 0);
	if(ret_value == -1){
		perror("msgsend ");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}


