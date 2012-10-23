#ifndef SENSORNODE_H
#define SENSORNODE_H

enum{
        AM_GROUPNR = 6
};

typedef nx_struct radio_data_msg {
	nx_uint8_t sender;
	nx_uint16_t partNr;
	nx_uint8_t data[25];
} radio_data_msg_t;

typedef nx_struct radio_conf_msg {
} radio_conf_msg_t;

typedef struct packet_msg {
	nx_uint16_t nodeID;
	nx_uint32_t timestamp;
	nx_uint32_t size;
	nx_uint8_t rawData[];
} packet_msg_t;	

#endif

