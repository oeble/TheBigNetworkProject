/*
 * main.c
 *
 *  Created on: Feb 25, 2010
 *      Author: laurynas
 */

/***
 * Simple symphony usage example
 */
#include <stdio.h>
#include <unistd.h>
#include <iostream>

#include "ns3/symphony-module.h"
#include "ns3/core-module.h"
#include "ns3/mobility-module.h"
#include "ns3/network-module.h"

#include "ns3/wifi-module.h"

using namespace ns3;

int
main(int argc, char *argv[])
{

  std::string nodeModel = "/home/ondra/symphony/release/ns-3.14/build/symphony.xml";
  std::string sensorNodeImage = "/home/ondra/symphony/release/ns-3.14/build/sensorNode.so";
  std::string TOSGWNodeImage = "/home/ondra/symphony/release/ns-3.14/build/gatewayTOS.so";
  uint64_t simLength = 10000;
  bool realTime = true;
  CommandLine cmd;
  cmd.AddValue("nodeModel", "model of the node in XML format", nodeModel);
  cmd.AddValue("sensorNodeImage", "node image", sensorNodeImage);
  cmd.AddValue("TOSGWNodeImage", "node image", TOSGWNodeImage);
  cmd.AddValue("simLength", "the length of the simulation", simLength);
  cmd.AddValue("realTime", "true to use real time simulation", realTime);
  cmd.Parse(argc, argv);
  //Create TosNodeContainer

  if (realTime)
    {
      GlobalValue::Bind("SimulatorImplementationType",
          StringValue("ns3::RealtimeSimulatorImpl"));
    }
  
  TosNodeContainer sensorNodes;
  sensorNodes.Add(CreateObject<TosNode> (10, MilliSeconds(0), sensorNodeImage.c_str() ));
  sensorNodes.Add(CreateObject<TosNode> (47, MilliSeconds(1000), sensorNodeImage.c_str() ));

  TosNodeContainer TOSGWNode;
  //Create nodes
  TOSGWNode.Create(1, TOSGWNodeImage.c_str());
  //sensorNodes.Create(1, sensorNodeImage.c_str());



  //Create helper
  TosHelper wifi;
  SymphonySensorContainer sc = wifi.InstallSensors(1,sensorNodes,"/home/ondra/symphony/release/ns-3.14/bin_pkt/");
  //sett standart for the communications
  wifi.SetStandard(ZIGBEE_PHY_STANDARD_802154);
  //wifi.EnableLogComponents ();
  //Set node model
  wifi.SetNodeModel(nodeModel);

  //Create physical layer
  YansTosPhyHelper wifiPhy = YansTosPhyHelper::Default();
  wifiPhy.Set("RxGain", DoubleValue(0));
  // ns-3 supports RadioTap and Prism tracing extensions for 802.11b
  //wifiPhy.SetPcapDataLinkType (YansWifiPhyHelper::DLT_IEEE802_11_RADIO);
  //Create channel
  YansWifiChannelHelper wifiChannel;
  //Add propagation
  wifiChannel.SetPropagationDelay("ns3::ConstantSpeedPropagationDelayModel");
  wifiChannel.AddPropagationLoss("ns3::FixedRssLossModel", "Rss",
      DoubleValue(-80));
  wifiPhy.SetChannel(wifiChannel.Create());

  //Create devices
  TosNetDeviceContainer devices = wifi.Install(wifiPhy, sensorNodes);
  TosNetDeviceContainer TOSGWdevice = wifi.Install(wifiPhy, TOSGWNode);
  //Add mobility
  TosMobilityHelper mobility;
  Ptr<ListPositionAllocator> positionAlloc =
      CreateObject<ListPositionAllocator>();
  positionAlloc->Add(Vector(0.0, 0.0, 0.0));
  positionAlloc->Add(Vector(50.0, 0.0, 0.0));
  mobility.SetPositionAllocator(positionAlloc);
  mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
  //Install it
  mobility.Install(sensorNodes);
  mobility.Install(TOSGWNode);

  //Set run-time for the simulation
  ns3::Simulator::Stop(ns3::Seconds(simLength));
  //Run simulation
  ns3::Simulator::Run();
  //Clean up all objects
  ns3::Simulator::Destroy();
  return 0;
}
