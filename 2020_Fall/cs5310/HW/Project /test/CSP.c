/*
 * CSP.c
 *
 *  Created on: Nov 20, 2018
 *  Author: lwang
 */
#include "common.h"
#include <signal.h>
#define MAX_QUEUE_SIZE  100
#define MAX_STATION_NUMBER 10
#define CSP_STATION_NUMBER 0
#define BUFFER_SIZE 1024

int ACTUAL_QUEUE_SIZE = 4;

// store the fd from client, index from 1 to 10, index 0 is CSP
// fd = -1 means not used yet
int client_socket_fds[MAX_STATION_NUMBER + 1 ] ;
int listen_fd;

// queue structure, data queue and request queue have the same structure
struct frame_queue {
	struct frame data[MAX_QUEUE_SIZE];
	int used[MAX_QUEUE_SIZE];  // indicate if certain spot in queue is used
	int count ;  // number of frames in the queue,
} data_queue, request_queue;

// for statistic
int total_data_frame_forwarded = 0;
int total_data_frame_received = 0;
int total_positive_reply = 0;
int total_negative_reply = 0;

/**
 *	frame queue initialization
 */
void init_queue(struct frame_queue *queue) {
	int i;
	for(i = 0; i< ACTUAL_QUEUE_SIZE ; i++) {
		memset(&queue->data[i], 0x0, sizeof(struct frame));
		queue->used[i] = 0;
	}
	queue->count = 0;
}

/*
 * handle SIGINT (control+c)
 */
void clean_up()
{
	// clean up
	int station;
	for(station = 1; station <= MAX_STATION_NUMBER; station++) {
			if(client_socket_fds[station] != -1) {
				close(client_socket_fds[station]);
			}
	}
	close(listen_fd);
    printf("Server Stop!\n");
    printf("total data frame received:%d, total data frame forward: %d\n", total_data_frame_received, total_data_frame_forwarded);
    printf("total positive reply:%d, total negative reply: %d\n", total_positive_reply, total_negative_reply);
    exit(0);
}


/**
 *  global initialization
 */
void init() {
	int i;
	for(i = 1; i<= MAX_STATION_NUMBER; i++)
		client_socket_fds[i] = -1;
	init_queue(&data_queue);
	init_queue(&request_queue);
    signal(SIGINT,clean_up);
}

/**
 * use this function to check if grant positive reply to data request
 *
 * in the multiplexing condition, free spot(ACTUAL_QUEUE_SIZE - data_queue.count) might not be enough
 *
 */
int data_queue_available() {
	//printf("positive_reply:%d, data_received:%d, free_spots:%d\n", total_positive_reply, total_data_frame_received, (ACTUAL_QUEUE_SIZE - data_queue.count));
	return ( total_positive_reply - total_data_frame_received) <  (ACTUAL_QUEUE_SIZE - data_queue.count) ? 1 : 0;
}

/**
 * put a frame into queue (data or request)
 * return 0 - Actual queue size:  OK
 * return -1: failed.
 */
int put_frame_to_queue(struct frame_queue *queue, struct frame *frame) {
	int i;
	if(frame->destination > MAX_STATION_NUMBER) {
		printf("Invalid frame destination: %d\n", frame->destination);
		return -1;
	}
	for(i = 0 ;i < ACTUAL_QUEUE_SIZE; i++) {
		if(!queue->used[i]) {
			queue->used[i] = 1;
			memcpy(&queue->data[i], frame, sizeof(struct frame));
			queue->count++;
			return i;
		}
	}
	printf("Attempt to put frame into a full queue, frame dropped\n");
	return -1;
}


/**
 *  assign a station to SP when connected
 *  return the station index(number from 1 to 10) assigned
 *  or -1 if failed.
 */
int assign_station(int fd) {
	int i ;
	for(i = 1; i <= MAX_STATION_NUMBER ; i++) {
		if(client_socket_fds[i] == -1)  {
			client_socket_fds[i] = fd;
			return i;
		}
	}
	return -1;
}


/**
 * read from client station
 */
int handle_readable_station(int station) {
	struct frame receive_frame;
	struct frame send_frame;
	char buffer[BUFFER_SIZE] ={0x0};
	int n_write;
	int n_read = read(client_socket_fds[station], buffer, sizeof(struct frame));
	if (n_read <= 0) {
		printf("Read error or connection closed on station: %d\n", station);
		return -1;
	} else if(n_read == sizeof(struct frame)) {
		memcpy(&receive_frame, buffer, sizeof(struct frame));
		if(receive_frame.type == FRAME_TYPE_REQUEST) {
			printf("Receive request from SP %d\n", receive_frame.source);
			//print_frame(&receive_frame);
			if(data_queue_available() ) {
				set_frame(&send_frame, FRAME_TYPE_POSITIVE_REPLY, CSP_STATION_NUMBER, station, NULL);
				n_write = write(client_socket_fds[station], &send_frame, sizeof(struct frame));
				total_positive_reply++;
				if(n_write == sizeof(struct frame)) {
					printf("Send positive reply to SP %d\n", station);
				}
			}else if(request_queue.count < ACTUAL_QUEUE_SIZE) { // put request to request queue
				int position = put_frame_to_queue(&request_queue, &receive_frame) ;
				printf("Put to request queue:%d\n",position);
			} else { // reject
				set_frame(&send_frame, FRAME_TYPE_NEGATIVE_REPLY, 0, station, NULL);
				n_write = write(client_socket_fds[station], &send_frame, sizeof(struct frame));
				total_negative_reply ++;
				if(n_write == sizeof(struct frame)) {
					printf("Send negative reply to SP %d\n", station);
				}
			}
		} else if(receive_frame.type == FRAME_TYPE_DATA) {
			printf("Receive data from frame from SP %d to SP %d\n", receive_frame.source, receive_frame.destination);
			//print_frame(&receive_frame);
			total_data_frame_received ++;
			int position = put_frame_to_queue(&data_queue, &receive_frame);
			//printf("Put to data queue:%d\n", position );
		}
	} else {
		printf("Wrong size read from client:%d\n", n_read);
		write(client_socket_fds[station], buffer, n_read);

	}
	return n_read;
}


/**
 * handle the data queue and request queue for a specific station/fd
 * write data frame to and reply request
 */
int handle_data_request_queue() {

	int index;
	// handle data queue
	for(index = 0 ;index < ACTUAL_QUEUE_SIZE; index++) {
		if( data_queue.used[index] ) {
			int destination  = data_queue.data[index].destination;
			if(client_socket_fds[destination] != -1) {
				int n_write = write(client_socket_fds[destination], &data_queue.data[index], sizeof(struct frame));
				if(n_write == sizeof(struct frame)) {
					printf("Forward data frame (from SP %d ) to SP %d\n", data_queue.data[index].source, data_queue.data[index].destination);
					data_queue.used [index] = 0;
					data_queue.count --;
					total_data_frame_forwarded ++;
				}
			}
		}
	}

	// handle request queue
	struct frame reply;
	if(request_queue.count > 0   && data_queue.count < ACTUAL_QUEUE_SIZE) { // Have request and have spot in data queue
		for(index = 0 ;index< ACTUAL_QUEUE_SIZE; index++) {
			if(request_queue.used[index] ) {
				if(data_queue_available() ) {
					//printf("data queue not full %d\n", data_queue.count );
					int source  = request_queue.data[index].source;
					set_frame(&reply, FRAME_TYPE_POSITIVE_REPLY, 0, source, NULL);
					int n_write = write(client_socket_fds[source], &reply, sizeof(struct frame));
					total_positive_reply++;
					if(n_write == sizeof(struct frame)) {
						printf("Send positive reply for queued request to SP %d\n", source);
						request_queue.used[index] = 0; // release the spot in request queue.
						request_queue.count --;
					}
				} else {
					printf("Data queue is still full\n");
					break;
				}
			}
		}
	}
	return 0;
}

/**
 * main function
 */
int main(int argc,char *argv[]) {

	if(argc < 3) {
		ERR_EXIT("Usage:\t./CSP listen_address listen_port queue_size(optional,max:100)\nExample:./CSP 127.0.0.1 53000\nExample:./CSP 127.0.0.1 53000 100\n");
	}
	init();
	struct sockaddr_in servaddr;
	// init server socket
	if( (listen_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		ERR_EXIT("socket error");
	// if queue size is provided
	if(argc == 5) {
		ACTUAL_QUEUE_SIZE = atoi(argv[4]);
		if(ACTUAL_QUEUE_SIZE > MAX_QUEUE_SIZE) {
			ACTUAL_QUEUE_SIZE = MAX_QUEUE_SIZE;
		}
	}
	printf("ACTUAL QUEUE SIZE:%d\n",ACTUAL_QUEUE_SIZE);

	char *address = argv[1];
	int port =  atoi(argv[2]);
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	servaddr.sin_addr.s_addr = inet_addr(address);

	// bind
	if(bind(listen_fd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0)
		ERR_EXIT("bind error");
	printf("CSP server bind successfully on %s:%u\n", address, port);
	// listen
	if(listen(listen_fd, SOMAXCONN) < 0)
		ERR_EXIT("listen error");
	printf("CSP server listen successfully on %s:%u\n", address, port);


	fd_set all_read_set; // persistence set
	fd_set r_set; //temp set for each loop;

	int maxfd;

	FD_ZERO(&all_read_set);
	FD_SET(listen_fd, &all_read_set);
	maxfd = listen_fd;
	int station;

	struct frame send_frame;
	char buffer[BUFFER_SIZE] ={0x0};
	char message[BUFFER_SIZE] ={0x0};

	int n_read, n_write;

	while (1) {
		r_set = all_read_set;
		int n_ready = select(maxfd + 1, &r_set, NULL, NULL, NULL);
		if (n_ready < 0) {
			perror("Select error");
			continue;
		}
		// for new connection from client
		if (FD_ISSET(listen_fd, &r_set)) {
			int client_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);
			if (client_fd < 0) {
				perror("accept error");
				continue;
			}
			int station = assign_station(client_fd);
			if(station == -1) {
				sprintf(message,"too many connection: %d", MAX_STATION_NUMBER);
				write(client_fd, message, strlen(message));
				close(client_fd);
			} else {
				set_frame(&send_frame,FRAME_TYPE_POSITIVE_REPLY,  CSP_STATION_NUMBER, station, "Station number assigned");
				write(client_fd, &send_frame, sizeof(struct frame)); // set the initial reply to assign the station number
				printf("Station: %d connected\n", station);
				if (client_fd > maxfd)
					maxfd = client_fd;
				FD_SET(client_fd, &all_read_set);
			}
		}

		//client socket readable,  read from client
		for (station = 1; station<=  MAX_STATION_NUMBER; station++) {
			if (client_socket_fds[station] != -1) {
				if (FD_ISSET(client_socket_fds[station], &r_set)) {
					int result = handle_readable_station(station) ;
					if(result < 0) {
						FD_CLR(client_socket_fds[station], &all_read_set);
						close(client_socket_fds[station]);
						client_socket_fds[station] = -1;
					}
				}
			}
		}

		// handle data and request queue
		handle_data_request_queue();
	}
	// clean up
	clean_up();
	return 0;
}

