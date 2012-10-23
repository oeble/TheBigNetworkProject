#include "SensorNode.h"
#include "Timer.h"

configuration gatewayTOSApp
{
}
implementation {
  components MainC, gatewayTOSC as App;
  components new AMSenderC(AM_GROUPNR);
  components new AMReceiverC(AM_GROUPNR);
  components new TimerMilliC() as TempTimer;//Should be removed when the node model is repaired
  components CombinerC as sp;
  components ActiveMessageC;
  components ActiveMessageAddressC;

  App.Boot -> MainC.Boot;
  App.Combine -> sp;
  App.ActiveMessageAddress -> ActiveMessageAddressC;
	
  sp.Receive -> AMReceiverC;
  sp.AMSend -> AMSenderC;
  sp.AMControl -> ActiveMessageC;
  sp.MilliTimer -> TempTimer;
  sp.Packet -> AMSenderC;
  sp.AMPacket -> AMSenderC;

}
