
#include "SensorNode.h" 
#include "Timer.h"

module SensorNodeC @safe() {
	uses {
		interface Boot;
		interface Split;	
		interface ActiveMessageAddress;
		interface InterruptWithData as DataIn;
		interface SplitControl as SensorControl;  
		interface Timer<TMilli> as LocTimer;	
	}
}
implementation {
    	void task Send();	
	uint8_t* dataToSend;
	uint16_t sizeOfData;
	bool busy;
	uint32_t timestamp; 

	event void Boot.booted() {
		printf("App: booted calling SplitAndSend%d\n", TOS_NODE_ID);
		//Set the address of the node
		 call ActiveMessageAddress.setAddress(AM_GROUPNR,  TOS_NODE_ID); 
		
	
	}
	
	async event void ActiveMessageAddress.changed()
	{
          	//Startup the sensor
		 call Split.Start();	 	 
	}

	async event void Split.StartDone()
	{
		call SensorControl.start();
	}
	
	event void SensorControl.startDone(error_t err) {
          if (err == SUCCESS) {
          	printf("SensorControl.startDone: TOS_NODE_ID == %d\n", TOS_NODE_ID);
         	 fflush(stdout);		
       	 }else {
         	   call SensorControl.start();
       	 }
    	}

    	async event void DataIn.interruptWithData(error_t result, uint16_t length, void * buffer) {
	    ///////////////
/*remove*/	//int i;
		//for (i = 0; i < length; i++)
		//{
   		//     printf("%x", ((nx_uint8_t *)buffer)[i]);
		//}

		
	    //////////////////////
	    if(result == SUCCESS){
	    	timestamp = call LocTimer.getNow();
            	printf("event void InterruptWithData.interruptWithData NODE_ID %d - data lenght %d timestamp %d \n",TOS_NODE_ID, length, timestamp);	   
	    	sizeOfData = length;
	    	dataToSend = (uint8_t*)buffer;
	    	post Send();
	    }
    	}	

	void task Send()
	{
	  //Let the Split module take care of rest
	  printf("Buffer has: %dX%d bytes\n", sizeof(uint8_t), sizeOfData);	
	  if(!busy){
	  call Split.SplitAndSend(dataToSend, sizeOfData, timestamp);
	  busy = 1;
	  }
	}

	event void Split.SendDone() 	
	{
		busy = 0;
/**/		printf("event Split.SendDone()");
	}
	
	 event void SensorControl.stopDone(error_t err) {
        // do nothing
    	}

	 event void LocTimer.fired() {		
	//should never happen
	}
}




