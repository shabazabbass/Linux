#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/msg.h>
#include<sys/ipc.h>

#define MSG_SIZE 20
struct msg_struct{
	long int msg_id;
	char msg[MSG_SIZE]; 
}msg_buff;

int main(){
	key_t key;
	key = 123;
	int msg_id, result;
	msg_id = msgget(key, IPC_CREAT | 0666);
	if(msg_id == -1){
		perror("msgget ");
		exit(EXIT_FAILURE);
	}
	result = msgrcv(msg_id, (void*)&msg_buff,MSG_SIZE,1,0);
	if(result == -1){
		perror("msgrcv");
		exit(EXIT_FAILURE);
	}
	printf("the message from the quue is %s\n",msg_buff.msg);

	result = msgctl(msg_id,IPC_RMID,0);
	if(result == -1){
		perror("msgctl ");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);


}
