#include "SensorNode.h"
#include "Timer.h"

configuration SensorNodeApp
{
}
implementation {
  components MainC, SensorNodeC as App;
  components new AMSenderC(AM_GROUPNR);
  components new AMReceiverC(AM_GROUPNR);
  components new TimerMilliC() as TempTimer;//Should be removed when the node model is repaired
  components new TimerMilliC() as StampTimer;
  components SpliterC as sp;
  components ActiveMessageC;
  components ActiveMessageAddressC;
  components MagnetomiterC;

  App.Boot -> MainC.Boot;
  App.Split -> sp;
  App.ActiveMessageAddress -> ActiveMessageAddressC;
	
  sp.Receive -> AMReceiverC;
  sp.AMSend -> AMSenderC;
  sp.AMControl -> ActiveMessageC;
  sp.MilliTimer -> TempTimer;
  sp.Packet -> AMSenderC;
  sp.AMPacket -> AMSenderC;

  App.SensorControl -> MagnetomiterC.SplitControl;
  App.DataIn -> MagnetomiterC.InterruptWithData;
  App.LocTimer -> StampTimer;
}
