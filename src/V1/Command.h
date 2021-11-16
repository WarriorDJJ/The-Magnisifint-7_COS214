#ifndef COMMAND_H
#define COMMAND_H

class Command {

private:
	SpaceCraft* receiver;

public:
	SpaceCraft* getReceiver();

	void execute();

	Command(SpaceCraft* s);
};

#endif
