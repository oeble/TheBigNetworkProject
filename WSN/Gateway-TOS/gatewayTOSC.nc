
#include "SensorNode.h" 
#include "Timer.h"

module gatewayTOSC @safe() {
	uses {
		interface Boot;
		interface Combine;	
		interface ActiveMessageAddress;
	}
}
implementation {

	event void Boot.booted() {		
		//Set the address of the node
		 call ActiveMessageAddress.setAddress(AM_GROUPNR,  TOS_NODE_ID);		
		//Start listening for data
		call Combine.StartWork();	
	}
	
	async event void ActiveMessageAddress.changed()
	{
	}
	
	async event void Combine.DataReady(packet_msg_t* buffer) 	
	{
		int i;		
		//printf("buffer addr %d\n", buffer);
		printf("\nGWTOS DATA READY SIZE %d Timestamp %d NodeId %d\n",(buffer->size),(buffer->timestamp),(buffer->nodeID));
		//for (i = 0; i < (buffer->size); i++)
		//{
   		//     printf("%x\n", (buffer->rawData)[i]);
		//}
		////NOW PASS IT TO THE NS3
	}	
}


