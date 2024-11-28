#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
int main(){
	int sock_id, new_sock_id, ret_val;
	struct sockaddr_in addr;
	socklen_t len;
	char str[20];

	sock_id = socket(AF_INET, SOCK_STREAM, 0);
	if(sock_id == -1){
		perror("socket ");
		exit(EXIT_FAILURE);
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(5000);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	len = sizeof(addr);

	ret_val = bind(sock_id, (struct sockaddr*)&addr, len);
	if(ret_val == -1){
		perror("bind");
		exit(EXIT_FAILURE);
	}

	ret_val = listen(sock_id, 2);

	if(ret_val == -1){
		perror("listen ");
		exit(EXIT_FAILURE);
	}

	printf("waiting for client...\n");
	new_sock_id = accept(sock_id, (struct sockaddr*)&addr, &len);

	if(new_sock_id == -1){
		perror("accept");
		exit(EXIT_FAILURE);
	}

	while(1){
		printf("Enter the data you want to send\n");
		scanf("%[^\n]s",str);
		getchar();
		ret_val = send(new_sock_id, str, sizeof(str), 0);
		if(ret_val == -1){
			perror("send");
			exit(EXIT_FAILURE);
		}
	}
}
