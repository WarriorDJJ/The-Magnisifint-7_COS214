#include "Invoker.h"

Invoker::Invoker(Command* c) {
	command = c;
}

void Invoker::press() {
	command->execute();
}
