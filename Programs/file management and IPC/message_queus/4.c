#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

#define MSG_MAX_SIZE 20
struct msg_struct{
	long int msg_id;
	char msg[MSG_MAX_SIZE];
}msg_buff;
int main(){
	key_t key = 123;
	int ret_val, msg_id;
	char str[MSG_MAX_SIZE];
	msg_id = msgget(key, IPC_CREAT | 0666);
	if(msg_id == -1){
		perror("msgget ");
		exit(EXIT_FAILURE);
	}
	msg_buff.msg_id = 1;
	while(1){
		ret_val = msgrcv(msg_id, (void*)&msg_buff, MSG_MAX_SIZE, 1, 0);
		printf("the message 1:%s\n",msg_buff.msg);
		if(ret_val == -1){
			perror("msgrcv");
			exit(EXIT_FAILURE);
		}
		if(strcmp(msg_buff.msg,"end") == 0){
			break;
		}
	}
	ret_val = msgctl(msg_id, IPC_RMID, 0);
	exit(EXIT_SUCCESS);
}
