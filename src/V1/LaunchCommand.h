#ifndef LAUNCHCOMMAND_H
#define LAUNCHCOMMAND_H

class LaunchCommand : Command {


public:
	LaunchCommand(Spacecraft* s);

	void execute();
};

#endif
