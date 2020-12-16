/*
 * common.h
 *
 *  Created on: Nov 20, 2018
 *      Author: lwang
 */

#ifndef PROJECT_CSP_SP_COMMON_H_
#define PROJECT_CSP_SP_COMMON_H_

#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

enum frame_type {
	FRAME_TYPE_REQUEST = 	1,
	FRAME_TYPE_DATA,
	FRAME_TYPE_POSITIVE_REPLY,
	FRAME_TYPE_NEGATIVE_REPLY
} ;

#define FRAME_DATA_LEN  64

int sequence = 1;
struct frame {
	int type;
	int sequence_number;
	int source;   // source station number of frame
	int destination; // destination station number
	char data[FRAME_DATA_LEN];
};

/**
 * get sequence number
 */
int get_sequence_number () {
	return sequence ++;
}
/**
 * print frame for debugging
 */
void print_frame(struct frame *data) {
	printf("type:%d, sequece_number:%d, source:%d, destination:%d, data:%s\n",
			data->type, data->sequence_number, data->source, data->destination, data->data);
}

/*
 * set the content of a frame
 */
void set_frame(struct frame* a_frame, int type, int source, int dest, char* data){
	memset(a_frame, 0x0, sizeof(struct frame));
	a_frame->sequence_number = get_sequence_number();
	a_frame->type = type;
	a_frame->source = source;
	a_frame->destination = dest;
	if(data != NULL)
		strncpy(a_frame->data, data,FRAME_DATA_LEN );
}



#define ERR_EXIT( ...) \
		do{ \
			printf(__VA_ARGS__); \
			exit(1); \
		}while(0)


#endif /* PROJECT_CSP_SP_COMMON_H_ */
