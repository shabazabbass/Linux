#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>

int main(){
	int socket_id, ret_val;
	struct sockaddr_in server_addr,client_addr;
	socklen_t server_len, client_len;
	pid_t pid;
	char str[20];
	
	socket_id = socket(AF_INET, SOCK_DGRAM, 0);
	if(socket_id == -1){
		perror("socket ");
		exit(EXIT_FAILURE);
	}
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(5000);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_len = sizeof(server_addr);
	
	client_addr.sin_family = AF_INET;
	client_addr.sin_port = htons(5001);
	client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	client_len = sizeof(client_addr);
	
	ret_val = bind(socket_id, (struct sockaddr*)&server_addr, server_len);
	if(ret_val == -1){
		perror("bind ");
		exit(EXIT_FAILURE);
	}

	pid = fork();
	if(pid == 0){
		while(1){
			scanf("%[^\n]s",str);
			getchar();
			ret_val = sendto(socket_id, str, strlen(str), 0, (struct sockaddr*)&client_addr, client_len);
			if(ret_val == -1){
				perror("sendto ");
				exit(EXIT_FAILURE);
			}
			if(strcmp("end",str) == 0){
				break;
			}
		}
		ret_val = close(socket_id);
		if(ret_val == -1){
			perror("close ");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);

	}
	else if(pid > 0){
		while(1){
			ret_val = recvfrom(socket_id, str, 20, 0, (struct sockaddr*)&client_addr, &client_len);
			if(ret_val == -1){
				perror("recvfrom ");
				exit(EXIT_FAILURE);
			}
			str[ret_val] = '\0';
			printf("message recieved: %s\n",str);
			if(strcmp("end",str) == 0){
				break;
			}
		}
		ret_val = close(socket_id);
		if(ret_val == -1){
			perror("close ");
			exit(EXIT_FAILURE);
		}
		wait(NULL);
		exit(EXIT_SUCCESS);
	}
	else{
		perror("fork ");
		exit(EXIT_SUCCESS);
	}
}

