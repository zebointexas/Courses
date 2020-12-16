/*
 * SP.c
 *
 *  Created on: Nov 20, 2018
 *      Author: lwang
 */

#include "common.h"

#define BUFFER_SIZE 1024

FILE *fp;  // for input file
int file_fd; // for input file

int socket_fd;  // socket_fd to CSP
int station_number = -1 ;  // own station number

int total_data_frame_sent = 0; // total data sent
int total_data_frame_received = 0; // total data received

/**
 * read from client socket
 * this is just for read and display, no need to care about the content
 * return: number of byte read or -1 if failed.
 */
int read_from_socket(int fd, struct frame *read_frame) {
	memset(read_frame, 0x0, sizeof(struct frame) );
	int n_read = read(fd, read_frame, sizeof(struct frame) );
	if( n_read <= 0 ) {
		printf("Receiving error, connection closed! %d\n", n_read);

		return -1;
	} else if(n_read == sizeof(struct frame)) { // read a frame
		if(station_number == -1) { // use the first frame to assign a station number
			station_number = read_frame->destination;
			printf("Station number assigned:%d\n",station_number);
		}
	}
	return n_read;
}


/**
 * read a line/command from input file
 * and execute the command, which can be send a frame or waiting
 *
 * return 0: EOF
 * return 1: OK
 */
int read_from_file() {
	char line[BUFFER_SIZE] = {0x0};

	struct frame receive_frame;
	struct frame send_frame;

	if( fgets(line,BUFFER_SIZE,fp) == NULL )          {
		printf("SP end, reach EOF.\n");
		return  0 ;
	}  else   {
		int lens = strlen(line);
		if (line[lens-1] == '\n') // trip the line break if any
			line[lens-1] = '\0';
		printf("read a line:%s\n",line);
		// parse the command, expected format:
		// Frame 1, To SP 3
		// Wait for receiving 2 frames
		char frame_data[BUFFER_SIZE] = {0x0};
		int destination_station = 0;
		int wait_times = 0;
		char * comma = strstr(line,  ",");
		if(comma != NULL) {  // Send command, "SP" is keyword
			int data_len = (comma - line);
			if(data_len > FRAME_DATA_LEN)
				data_len = FRAME_DATA_LEN;
			strncpy(frame_data, line, data_len ); // frame data;
			char * sp = strstr(line, "SP");
			int destination_station = atoi(sp + 2) ; //  SP X

			printf("Command: send data:%s, to station:%d\n", frame_data, destination_station);
			set_frame(&send_frame, FRAME_TYPE_REQUEST, station_number, destination_station, NULL);
			int n_write = write(socket_fd, &send_frame, sizeof(struct frame));
			printf("Send request to CSP to send data %s to SP %d\n", frame_data, destination_station);
			int retry_times = 0;
			while (read_from_socket( socket_fd, &receive_frame) == sizeof(struct frame)) {
				if(receive_frame.type == FRAME_TYPE_POSITIVE_REPLY)  {  // ok to go
					printf("Receive positive reply from CSP to send data %s to SP %d\n", frame_data, destination_station);
					set_frame(&send_frame, FRAME_TYPE_DATA, station_number, destination_station, frame_data);
					n_write = write(socket_fd, &send_frame, sizeof(struct frame));
					printf("Send (Via CSP) data  %s to SP %d\n", frame_data, destination_station);
					total_data_frame_sent ++;
					break;
				} else if(receive_frame.type == FRAME_TYPE_NEGATIVE_REPLY){ // needs to retry
					printf("Receive reject reply from CSP to send data to SP %d, retry times:%d\n", destination_station, retry_times);
					retry_times++;
					if(retry_times ==3 ) {
						printf("Rejected 3 times, abandon this frame.\n");
						break;
					}
					sleep(1);
					set_frame(&send_frame, FRAME_TYPE_REQUEST, station_number, destination_station, NULL);
					write(socket_fd, &send_frame, sizeof(struct frame));
				} else if(receive_frame.type == FRAME_TYPE_DATA) {
					printf("Receive (via CSP) data frame from %d while sending frame\n", receive_frame.source);
					total_data_frame_received++ ;
				}
			}
		} else { // wait command which "Wait for receiving 2 frames, "receiving" and "frame" are keyword
			char * receiving = strstr(line, "receiving");
			char * frame = strstr(line, "frame");
			if(receiving  != NULL  && frame != NULL) {
				strncpy(frame_data, receiving + strlen("receiving"), frame - receiving - strlen("receiving"));
				int wait_frame = atoi(frame_data);
				printf("Wait for receiving:  %d frame\n", wait_frame);
				while(wait_frame) {
					if(read_from_socket(socket_fd, &receive_frame) == sizeof(struct frame)) {
						printf("Receive (via CSP) frame from %d while waiting, remaining %d:\n", receive_frame.source, wait_frame);
						total_data_frame_received ++;
						wait_frame--;
					} else {
						return -1;
					}
				}
			} else {
				printf("Unrecognized command:%s\n", line);
			}

		}
		return 1;
	}

}

/*
 * main function
 */
int main(int argc,char *argv[])  {

	if(argc < 4) {
		ERR_EXIT("Usage:./SP CSP_server_ip  port input_file\nExample:./SP 127.0.0.1 53000 input.txt\n");
	}
	char *server_address = argv[1];
	int server_port =  atoi(argv[2]);
	char *input_file = argv[3];


	// initial socket
	struct sockaddr_in serveraddr;
	memset(&serveraddr,0x0, sizeof(struct sockaddr_in));
	struct sockaddr_in servaddr;
	if( (socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		ERR_EXIT("failed to create socket\n");

	// connect to server
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(server_port);
	servaddr.sin_addr.s_addr = inet_addr(server_address);

	if(connect(socket_fd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
		ERR_EXIT("failed to connect to %s:%d \n", server_address, server_port);
	}
	printf("connect successfully to %s:%d\n", server_address, server_port);

	// open input file
	if((fp = fopen(input_file,"r")) == NULL)   {
		ERR_EXIT("failed to open input file:%s\n", input_file);
	} else {
		printf("input file opened successfully\n");
	}
	file_fd = fileno(fp);

	// prepare for select
	fd_set r_set;
	int maxfd = ( (file_fd > socket_fd ? file_fd: socket_fd)  + 1 );

	struct frame receive_frame; // receive buffer
	while(1)  {
		FD_ZERO(&r_set);
		FD_SET(file_fd, &r_set);
		FD_SET(socket_fd, &r_set);

		if( select( maxfd, &r_set, NULL, NULL, NULL ) == -1 )   {
			ERR_EXIT("Client Select Error.\n");
		}
		// ready to read from socket
		if( FD_ISSET( socket_fd, &r_set ) ) {
			if( read_from_socket(socket_fd, &receive_frame) <= 0) { // socket closed
				break;
			}
		}
		// ready to read from file
		if( FD_ISSET( file_fd, &r_set ) ) {
			if(read_from_file() <= 0) { // end of file, or socket closed
				break;
			}
		}
	}
	fclose(fp);
	close(socket_fd);
	printf("Total data frame sent:%d, total data   frame received: %d\n", total_data_frame_sent, total_data_frame_received);
}
