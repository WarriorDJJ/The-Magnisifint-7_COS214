#ifndef COMMAND_H
#define COMMAND_H
#include "SpaceCraft.h"

class Command {

private:
	SpaceCraft* receiver;

public:
	SpaceCraft* getReceiver();

	void execute();

	Command(SpaceCraft* s);

};

#endif
