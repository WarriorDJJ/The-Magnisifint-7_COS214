#include "Command.h"

SpaceCraft* Command::getReceiver() {
	return this->receiver;
}

Command::Command(SpaceCraft* s) {
	// TODO - implement Command::Command
	this->receiver = s;
}
