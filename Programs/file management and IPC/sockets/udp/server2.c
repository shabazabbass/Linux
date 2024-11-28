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
	int sock_id,ret_val;
	struct sockaddr_in addr;
	sock_id = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock_id == -1){
		perror("sockid");
		exit(EXIT_FAILURE);
	}
	addr.sin_family = AF_INET;
	addr.sin_port = htons(5000);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	while(1){
		printf("Enter the message you want to send\n");
		scanf("%[^\n]s",str);
		getchar();
		ret_val = sendto(sock_id, str, strlen(str), 0, (struct sockaddr*)&addr, sizeof(addr));
		if(ret_val == -1){
			perror("sendto");
			close(sock_id);
			exit(EXIT_FAILURE);
		}
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

