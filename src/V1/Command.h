#ifndef COMMAND_H
#define COMMAND_H
#include "SpaceCraft.h"

class Command {

protected:
	SpaceCraft* receiver;

public:
	SpaceCraft* getReceiver();
	virtual void execute()=0;
	Command(SpaceCraft* s);

};

#endif
