#ifndef LAUNCHCOMMAND_H
#define LAUNCHCOMMAND_H

class LaunchCommand : public Command {


public:
	LaunchCommand(SpaceCraft* s);

	void execute();
};

#endif
