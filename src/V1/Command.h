#ifndef COMMAND_H
#define COMMAND_H
#include "Simulation.h"

class Command : public Simulation{

protected:
    SpaceCraft* receiver;

public:
    SpaceCraft* getReceiver();
	virtual void execute()=0;
	Command(Payload* p, Rocket* r);

};

#endif
