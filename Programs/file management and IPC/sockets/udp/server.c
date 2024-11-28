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
	char str[20];
	socklen_t addr_len;
	sock_id = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock_id == -1){
		perror("socket ");
		exit(EXIT_FAILURE);
	}
	struct sockaddr_in adr,client_adr;
	adr.sin_family = AF_INET;
	adr.sin_port = htons(5000);
	adr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	status = bind(sock_id, (struct sockaddr*)&adr, sizeof(adr));

	if(status == -1){
		perror("bind ");
		close(sock_id);
		exit(EXIT_FAILURE);
	}
	addr_len = sizeof(client_adr);
	status=recvfrom(sock_id, str, 20, 0, (struct sockaddr*)&client_adr, &addr_len);
	if(status == -1){
		perror("recfrm");
		close(sock_id);
		exit(EXIT_FAILURE);
	}
	printf("the message recived from the client is %s\n",str);
	status = close(sock_id);
	if(status == -1){
		perror("close ");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);

}

