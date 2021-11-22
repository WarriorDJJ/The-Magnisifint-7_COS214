#ifndef LAUNCHCOMMAND_H
#define LAUNCHCOMMAND_H

#include "Command.h"

class LaunchCommand : public Command {


public:
	LaunchCommand(Payload *s, Rocket *r);
	void execute() override;
};

#endif
