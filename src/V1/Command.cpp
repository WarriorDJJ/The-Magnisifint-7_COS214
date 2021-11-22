#include "Command.h"

Payload* Command::getReceiver() {
	return this->receiver;
}

Command::Command(Payload* p, Rocket* r) : Simulation(r, p){
	// TODO - implement Command::Command
	this->receiver = p;
    this->rocketReceiver = r;
}
