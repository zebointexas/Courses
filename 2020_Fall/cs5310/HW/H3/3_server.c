#include <sys/socket.h>
#include <arpa/inet.h>

#include <sys/types.h>
#include <stdio.h>

#include <string.h>
#include <stdlib.h>

typedef union {
	short s;
	char  c[sizeof(short)];
} unionnn ;

/**
 * to check the bit order
 * return the name of bit order if applicable
 */
char* check( unionnn input, char high_bit, char low_bit) {
	if (sizeof(short) == 2) {
		if (input.c[0] == high_bit  && input.c[1] == low_bit)
			return "BE";   /* "Big-endian" */
		else if (input.c[0] == low_bit  && input.c[1] == high_bit)
			return "LE";   /* "Little-endian" */
		else
			return "unknown";
	}else {
		return "short size not equals to 2 - error!";
	}
}
 
int main(int argc,char *argv[])  {

	int bufferSize = 2981;
	
	unionnn port_host, port_network;

	struct sockaddr_in sa;
	char buffer[bufferSize+1];
	int listenfd, connfd;

	memset(&sa,0x0, sizeof(struct sockaddr_in));

	port_host.s = 0x0469;
	
	printf("host bit order: %s\n", check(port_host, 4, 8));

	port_network.s =  htons(port_host.s);
	
	printf("network bit order: %s\n", check(port_network, 4, 8));
 
	printf("number of argc: %d\n", argc);
	
	if(argc > 1 ) {
		printf("Apply host bit order for the port   \n");
		sa.sin_port= port_host.s ;
	} else {
		printf("Apply network bit for the port\n");
		sa.sin_port= port_network.s ;
	}
	sa.sin_family=AF_INET;
	sa.sin_addr.s_addr=htonl(INADDR_ANY);

	if((listenfd=socket(AF_INET,SOCK_STREAM,0))<=0)  	{
		printf("create socket failed \n");
		return 0;
	}

	if( bind(listenfd,(struct sockaddr*)&sa,sizeof(sa)) < 0) {
		printf("Bad bind with port: %u\n", port_host.s);
		exit(1) ;
	}
	
	printf("Good bind with port: %u\n", port_host.s);

	if( listen(listenfd, 5) < 0) {
		
		printf("listen failed!\n");
		exit(1) ;
	}
	
	printf("listening good with port: %u\n", port_host.s);
	
	for(   ;   ;  ) {
		
		memset(&buffer,0x0,bufferSize);
		connfd=accept(listenfd,(struct sockaddr*) NULL, NULL);
		
		int n = 0;
		
		if ( (n = read(connfd, buffer, bufferSize)) < 0) {
			
			printf("read failed !\n");

			break;
			
		} else if (n == 0) {
			
			printf("connection closed!\n");
			
			break;
		}
		
		printf("Got message from a client: %s\n",buffer);
		close(connfd);
	}
	return 0;
}
