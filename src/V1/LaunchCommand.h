#ifndef LAUNCHCOMMAND_H
#define LAUNCHCOMMAND_H

#include "Command.h"

class LaunchCommand : public Command {


public:
	LaunchCommand(SpaceCraft *s);

	void execute();
};

#endif
