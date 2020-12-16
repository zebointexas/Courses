#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <pthread.h>
 
#define exit_if_error(m) \
		do{ \
			perror(m); \
			exit(1); \
		}while(0)


short portCus = 0x0498;
int bufferSize = 1112;
 
void* handler_fd(void* arg) {
	 
	int sock=*((int*)arg);
	
	pthread_detach(pthread_self());
	
	char buf[bufferSize] ;
	
	while(1) {

		memset(buf, 0x0, bufferSize);
		
		ssize_t nr = read(sock,buf, bufferSize - 1);
		
		if(nr > 0) {
			
			printf("read from client: %d, %s\n",     nr, buf);
			
			ssize_t nw = write(sock, buf, nr);
			
			if(nw != nr)
				exit_if_error("write err");
			
			printf("write back to client: %d\n",   nw);
			
		} else 	{
			
			printf("Client quit!\n");
			close(sock);
			break;
		}
	}
}

int main() {
	
	int listenfd, connfd;
	struct sockaddr_in sa;
	char buffer[bufferSize];

	if( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		exit_if_error("socket error");

	memset(&sa, 0, sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_port = htons(portCus);
	sa.sin_addr.s_addr = INADDR_ANY;
	
	// bind
	if(bind(listenfd, (struct sockaddr*)&sa, sizeof(sa)) < 0)
		exit_if_error("bind error");
	
	printf("bind with %u\n", portCus);
	
	// listen
	if(listen(listenfd, SOMAXCONN) < 0)
		exit_if_error("listen error");
	
	printf("listen with : %u\n", portCus);

	while (1) {
		
		if( (connfd = accept(listenfd, (struct sockaddr*)NULL, NULL)) < 0)
			exit_if_error("accept error");
		
		pthread_t tid;
		 
		int ret=pthread_create(&tid,NULL,handler_fd,&connfd);
		if(ret<0)
			exit_if_error("pthread error");
		 
		pthread_detach(tid);

	}
	
	close(connfd);
	close(listenfd);
	
	return 0;
}
