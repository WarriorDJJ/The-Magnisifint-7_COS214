#ifndef TESTSTATE_H
#define TESTSTATE_H

#include "SpaceCraft.h"
#include "TestStrat.h"

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
