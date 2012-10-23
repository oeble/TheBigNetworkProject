#include "SensorNode.h" 

module CombinerC @safe() {
    provides interface Combine;

    uses{
		interface Timer<TMilli> as MilliTimer;
		interface Receive;
		interface SplitControl as AMControl;
		interface AMSend;
		interface Packet;
		interface AMPacket;		
	}
}
implementation {
          
        void task sendConfirm();
	uint16_t sender;
	bool locked;
	bool started;
	message_t packetS;
	packet_msg_t *dataBank[100];

 	event void AMControl.startDone(error_t err) {
		if (err == SUCCESS) {		
 		printf("COMBINER AMControl.startDone: TOS_NODE_ID == %d TOS_NODE_ADDR == %d\n", TOS_NODE_ID,call AMPacket.address());
		  }
		else{
			call AMControl.start();
		}
	}
		
	event void AMControl.stopDone(error_t err) {
		// do nothing
	}
 
        event void MilliTimer.fired() {		
	}

	void task sendConfirm(){
		
 	}
        

	event message_t* Receive.receive(message_t* bufPtr, void* payload, uint8_t len) {
		long i;
		nx_uint16_t partNr;	
		nx_uint16_t size;	
		radio_conf_msg_t *sP; 	
		radio_data_msg_t *msg =  ((radio_data_msg_t*)payload);				
		sender = msg->sender;
		partNr = msg->partNr;
		printf("COMBINER:: RECEIVED SENDER:%d PARTNR: %d\n",sender, partNr);
		
		if(partNr == 0){
			//COPY DATA FROM PACKET TO DATABANK
			//COPUY 2 BYTES AS SIZE
			memcpy(&size,msg->data,2);
			//ALLOCATA MEMORY IN DATABANK
			dataBank[sender] = (packet_msg_t*)malloc(sizeof(packet_msg_t)+size);	
			printf("Raw addr %d %d\n",dataBank[sender],(dataBank[sender]->rawData));
			dataBank[sender]->nodeID = sender;
			printf("Allocated\n");
			//COPY 4 BYTES AS TIMESTAMP 			
			memcpy(&(dataBank[sender]->timestamp),(msg->data)+sizeof(nx_uint16_t),sizeof(nx_uint32_t));
			dataBank[sender]->size = size;		
			printf("SAVED TO DATABANK sender: %d timestamp: %d size: %d\n",dataBank[sender]->nodeID,dataBank[sender]->timestamp,dataBank[sender]->size);
/**/			///////////////////////////MAYBE SHOULD BE IN THE TASK BUT ANOTHER CONNECTION ????COULD REVRITE SENDER????	
			printf("COMBINER::void send conf to %d\n", sender);
			if(locked == 1){
				printf("LOCKED::%x\n", TOS_NODE_ID);
				return bufPtr;
			}	
			sP =  (radio_conf_msg_t*)call Packet.getPayload(&packetS, sizeof(radio_conf_msg_t));
			if (call AMSend.send(sender, &packetS, sizeof(radio_conf_msg_t)) == SUCCESS) {
					locked = TRUE;
			}	
			/////////////////////////////////////
		}
		else{											
			uint16_t left = (dataBank[sender]->size) - (25*(partNr-1));
			printf("WRITE OFFSET:%d LEFT:%d\n", ((partNr-1)*25),left);	
			memcpy((dataBank[sender]->rawData)+((partNr-1)*25),(msg->data),(left>25)?25:left);
			if(left < 26){
			printf("COMBINER SIGNALING DATAREADY\n");
			signal Combine.DataReady(dataBank[sender]);
			//dataBank[sender] = 0;
			}
		}

		return bufPtr;			
	}
	
	event void AMSend.sendDone(message_t* bufPtr, error_t error) {
		if (error==SUCCESS) {
			locked = FALSE;
			printf("COMBINER event void AMSend.sendDone %d\n",TOS_NODE_ID);
		}

	}

	command void Combine.StartWork()
	{	
		call AMControl.start();
	}
	
}
