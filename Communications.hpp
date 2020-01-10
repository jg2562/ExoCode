#ifndef COMMUNICATIONS_HEADER
#define COMMUNICATIONS_HEADER
#include "Transceiver.hpp"
#include "Transmission.hpp"
#include "Commands.hpp"

class Communications{
private:
  Transceiver* transceiver;
  TransmissionFactory* transmission_creator;
	CommandFactory* cmd_factory;

	void receiveMessage(ExoMessageBuilder* msg_builder, ExoReport* report);
  void processMessage(CommandCode code, ExoMessageBuilder* msg_builder, ExoReport* report);
public:
  Communications(Transceiver* transceiver);
  ~Communications();

  ExoMessage* receiveMessages(ExoReport* report);
  void sendReport(ExoReport* report);
};

#endif