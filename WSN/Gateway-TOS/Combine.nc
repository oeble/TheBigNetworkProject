#include "SensorNode.h" 

interface Combine {
	async event void DataReady(packet_msg_t* buffer);
	command void StartWork();
}
