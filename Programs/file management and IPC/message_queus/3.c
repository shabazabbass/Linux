#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/stat.h>
#include<string.h>

#define MSG_MAX_SIZE 20
struct msg_struct{
	long int msg_type;
	char msg[MSG_MAX_SIZE];
}msg_buff;

int main(){
	key_t key = 123;
	char str[20];
	int msg_id, ret_type;
	msg_id = msgget(key, IPC_CREAT | 0666);
	if(msg_id == -1){
		perror("message get ");
		exit(EXIT_FAILURE);
	}
	msg_buff.msg_type = 1;
	while(1){
		printf("Enter the string\n");
		scanf("%[^\n]s",str);
		getchar();
		strcpy(msg_buff.msg, str);
		ret_type = msgsnd(msg_id, (void*)&msg_buff, MSG_MAX_SIZE, 1);
		if(ret_type == -1){
			perror("msgsnd");
			exit(EXIT_FAILURE);
		}
		if(strcmp("end",str) == 0){
			break;
		}
	}
	exit(EXIT_SUCCESS);

	
}
