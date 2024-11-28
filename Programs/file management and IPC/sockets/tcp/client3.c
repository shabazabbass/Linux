#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>

int main(){
	int sock_id, ret_val;
	struct sockaddr_in addr;
	socklen_t len;
	char str[20];

	sock_id = socket(AF_INET, SOCK_STREAM, 0);
	if(sock_id == -1){
		perror("socket");
		exit(EXIT_FAILURE);
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(5000);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	len = sizeof(addr);

	ret_val = connect(sock_id, (struct sockaddr*)&addr, len);
	if(ret_val == -1){
		perror("connect");
		exit(EXIT_FAILURE);
	}

	pid_t pid;
	pid = fork();

	if(pid == 0){
		while(1){
			printf("Enter the message:\n");
			scanf("%[^\n]s",str);
			getchar();
			ret_val = send(sock_id, str, sizeof(str), 0);
			if(ret_val == -1){
				perror("send");
				exit(EXIT_FAILURE);
			}
		}
	}

	else if(pid > 0){
		while(1){
			ret_val = recv(sock_id, str, 20, 0);
			if(ret_val == -1){
				perror("recv");
				exit(EXIT_FAILURE);
			}
			str[ret_val] = '\0';
			printf("string recieved : %s\n",str);
		}
	}

	else{
		perror("fork");
		exit(EXIT_FAILURE);
	}
}
