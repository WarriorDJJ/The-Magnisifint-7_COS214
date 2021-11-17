#ifndef INVOKER_H
#define INVOKER_H

#include "Command.h"

class Invoker {

private:
	Command* command;

public:
	Invoker(Command* c);

	void press();
};

#endif
