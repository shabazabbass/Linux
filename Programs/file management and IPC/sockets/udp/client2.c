#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>

int main(){
	char str[20];
	int sock_id, ret_val;
	struct sockaddr_in addr,server_addr;
	socklen_t len = sizeof(addr);
	sock_id = socket(AF_INET,SOCK_DGRAM,0);
	if(sock_id == -1){
		perror("socket ");
		exit(EXIT_FAILURE);
	}
	addr.sin_family = AF_INET;
	addr.sin_port = htons(5000);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	ret_val = bind(sock_id, (struct sockaddr*)&addr,len);
	if(ret_val == -1){
		perror("bind");
		close(sock_id);
		exit(EXIT_FAILURE);
	}
	len = sizeof(server_addr);
	while(1){
		printf("wait to recive the data..\n");
		ret_val =recvfrom(sock_id, str,sizeof(str),0,(struct sockaddr*)&server_addr,&len);
		if(ret_val == -1){
			perror("recvfrom");
			exit(EXIT_FAILURE);
		}
		str[ret_val] = '\0';
		printf("the message recived from the server is %s\n",str);
		if(strcmp("end",str) == 0){
			break;
		}
	}
	ret_val = close(sock_id);
	if(ret_val == -1){
		perror("close ");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
