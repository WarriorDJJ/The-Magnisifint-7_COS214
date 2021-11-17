#ifndef TESTSTATE_H
#define TESTSTATE_H

class TestState {

private:
	SpaceCraft* rocket;
	TestStrat* testS;

public:
	bool launch();

	TestState* getWorkingState();

	TestState* getBrokenState();
};

#endif
