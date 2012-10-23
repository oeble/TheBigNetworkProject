#include "SensorNode.h" 

module SpliterC @safe() {
    provides interface Split;

    uses{
		interface Timer<TMilli> as MilliTimer;
		interface Receive;
		interface SplitControl as AMControl;
		interface AMSend;
		interface Packet;
		interface AMPacket;	
		interface Ns3Application;		
	}
}
implementation {
	//ON CLIENT
	void task send();
	message_t packetS;
    	uint8_t dest=0;
        uint16_t partNr=0;
	bool locked;
	uint8_t sender;
	uint16_t left;

	uint8_t *dataToSend;
	uint16_t sizeOfData;
	uint32_t timestamp; 

 	event void AMControl.startDone(error_t err) {
		if (err == SUCCESS) {			
		  	printf("AMControl.startDone: TOS_NODE_ID == %d TOS_NODE_ADDR == %d\n ", TOS_NODE_ID,call AMPacket.address());
			signal Split.StartDone();
		}else {
			call AMControl.start();
		}
	}
		
	event void AMControl.stopDone(error_t err) {
		// do nothing
	}
 
        event void MilliTimer.fired() {		
	}


	void task send(){
		printf("SPLITERC::void task send() TOS_NODE_ID::%d  - DEST::%d\n", TOS_NODE_ID, dest);
		if (locked) {
			printf("LOCKED\n");
			return;
		}
		else {
			radio_data_msg_t* sP = (radio_data_msg_t*)call Packet.getPayload(&packetS, sizeof(radio_data_msg_t));
  			if (sP == NULL) {
				printf("sP == NULL\n");
				return;
			     }
			sP->sender = TOS_NODE_ID;
			sP->partNr = partNr;

			if(partNr == 0)
			{
			  //send the first packet containing size of the data to be sended			  
			  printf("TOSNODE:: %d CREATING PACKET LEN %d SIZEOFDATA: %d\n",TOS_NODE_ID, sizeof(radio_data_msg_t),sizeOfData);			
			  
//?			  //This can lead to endianess problems-->maybe fix later
			  *((nx_uint16_t*)(&(sP->data[0]))) = sizeOfData;
			  *((nx_uint32_t*)(&(sP->data[2]))) = timestamp;			
			}
			else{
				printf("TOSNODE:: %d CREATING SENDED: %d PARTNR %d\n",TOS_NODE_ID, 25*(partNr-1),partNr);
				//continue with sending parts				
				left = sizeOfData-((partNr-1)*25);
				memcpy((sP->data), &(dataToSend[(partNr-1)*25]),(left>25)?25:left);
			}
			if (call AMSend.send(dest, &packetS, sizeof(radio_data_msg_t)) == SUCCESS) {
				locked = TRUE;
			     }
			return;			
		} 	
 	}
        

	event message_t* Receive.receive(message_t* bufPtr, void* payload, uint8_t len) {
		if(partNr == 1){
		  post send();	
		}
		return bufPtr;			
	}
	
	event void AMSend.sendDone(message_t* bufPtr, error_t error) {
		if (&packetS == bufPtr) {
		    locked = FALSE;
		    printf("event void AMSend.sendDone %d\n",TOS_NODE_ID);	
		    partNr++;
		    //Check if all was sent
		    if(partNr != 1){
			if((partNr-1)*25 <= sizeOfData){
				post send();
			}
			//If yes signal
			else{
				partNr = 0;
				signal Split.SendDone();
			}		
		     }			
		}
	}

	command void Split.Start()
	{
		call AMControl.start();
	}
	
	command void Split.SplitAndSend(uint8_t* buffer, uint16_t size, uint32_t timest)
	{		
		timestamp = timest;
		dataToSend = buffer;
		sizeOfData = size;
		post send();	
                
	}
	
}
