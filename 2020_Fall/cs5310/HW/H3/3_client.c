#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main(int argc,char *argv[])  {

    int bufferSize = 2981;

	struct sockaddr_in serveraddr;
	
	memset(&serveraddr,0x0, sizeof(struct sockaddr_in));

	int sockfd;
	
	char sendbuff[bufferSize];
	
	memset(&sendbuff,0x0, bufferSize);
	
	strcpy(sendbuff, "Hello server, do you like Texas BBQ? \n");

	struct sockaddr_in sa;
	ssize_t send;

	if( (sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
		printf("failed to create socket\n");
		exit(1);
	}
	// CONNECT TO SERVER ON 0x0408 (1032)
	unsigned short port = 0x0469;
	
	memset(&sa, 0, sizeof(sa));
	
	sa.sin_family = AF_INET;
	
	sa.sin_port = htons(port);
	
	sa.sin_addr.s_addr = inet_addr("127.1.1.1");

	if(connect(sockfd, (struct sockaddr*)&sa, sizeof(sa)) < 0) {
		printf("failed connection to localhost:%d\n",port);
		exit(1);
	} else {
		printf("good connection to localhost:%d\n",port);
	}

	if( (send = write(sockfd, sendbuff, strlen(sendbuff))) < 0) {
		printf("write error found");
		exit(1);
	}

	if( send  < 0) {
		
		printf("write failed\n");
	} else if(send == strlen(sendbuff)) {
		
		printf("write OK!!\n");
		
	}
	
	
	close(sockfd);
}
