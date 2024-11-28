#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/wait.h>
#include<string.h>

int main(){
        char str[20];
        pid_t pid;
        int sock_id, ret_val;
        struct sockaddr_in addr;
        socklen_t len;
        len = sizeof(addr);

        sock_id = socket(AF_INET, SOCK_DGRAM, 0);
        if(sock_id == -1){
        	perror("socket");
                exit(EXIT_FAILURE);
	}

        addr.sin_family = AF_INET;
        addr.sin_port = htons(5000);
        addr.sin_addr.s_addr = inet_addr("127.0.0.1");

        pid = fork();
        if(pid == 0){
                ret_val = bind(sock_id, (struct sockaddr*)&(addr), len);
                if(ret_val == -1){
                        perror("bind");
                        exit(EXIT_FAILURE);
                }
                printf("enter the data :\n");
                while(1){
                        fflush(stdout);
                        scanf("%[^\n]s",str);
                        getchar();
                        ret_val = sendto(sock_id, str, strlen(str), 0 , (struct sockaddr*)&addr , len);
                        if(ret_val == -1){
                                perror("sentto");
                                exit(EXIT_FAILURE);
                        }
                        if(strcmp("end",str) == 0 ){
                                break;
                        }
                }
		ret_value = close(sock_id);
		if(ret_value == -1){
			perror("close ");
			exit(EXIT_FAILURE);
		}
		printf("child succesfully exited..\n");
                exit(EXIT_SUCCESS);
        }
        else if(pid > 0){

                pid_t w_pid;
                while(1){
                        w_pid = waitpid(pid, 0, WNOHANG);
                        if(w_pid == -1){
                                w_pid = waitpid(pid, 0, 0);
                                perror("waitpid");
                                exit(EXIT_FAILURE);
                        }
                        ret_val = recvfrom(sock_id, str, 20, 0, (struct sockaddr*)&addr, &len);
                        if(ret_val == -1){
                                w_pid = waitpid(pid, 0, 0);
                                perror("recvfrom");
                                exit(EXIT_FAILURE);
                        }
                        str[ret_val] = '\0';
                        printf("Recived string : \n%s\n",str);
                        if(strcmp("end",str) == 0){
                                break;
                        }

                        printf("enter the data :\n");
                }
                w_pid = waitpid(pid, &ret_val, 0);
                if(w_pid == -1){
                        perror("waitpid");
                        exit(EXIT_FAILURE);
                }
                if(WIFEXITED(ret_val)){
			ret_val = close(sock_id);
			if(ret_val == -1){
				perror("close ");
				exit(EXIT_FAILURE);
			}
			printf("parent succesfully exited..\n");
                        exit(WEXITSTATUS(ret_val));
                }
        }
        else{
                perror("fork");
                exit(EXIT_FAILURE);
        }
}
