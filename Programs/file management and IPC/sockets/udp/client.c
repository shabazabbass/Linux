#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
int main(){
	int sock_id, status;
	char msg[20] = "hello";
	struct sockaddr_in add;
	sock_id = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock_id == -1){
		perror("socket ");
		exit(EXIT_FAILURE);
	}
	add.sin_family = AF_INET;
	add.sin_port = htons(5000);
	add.sin_addr.s_addr = inet_addr("127.0.0.1");

	status = sendto(sock_id, msg, strlen(msg), 0, (struct sockaddr*)&add,sizeof(add));
	if(status == -1){
		perror("sendto");
		exit(EXIT_FAILURE);
	}
	status = close(sock_id);
	if(status == -1){
		perror("close ");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
