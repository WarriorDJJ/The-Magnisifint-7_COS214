#ifndef UNTESTEDSTATE_H
#define UNTESTEDSTATE_H

class UntestedState : TestState {


public:
	bool launch();

	TestState* getBrokenState();

	TestState* getWorkingState();
};

#endif
