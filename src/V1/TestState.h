#ifndef TESTSTATE_H
#define TESTSTATE_H

#include "SpaceCraft.h"
//#include "TestStrat.h"
#include "Rocket.h"
#include "Simulation.h"
//#include "BrokenState.h"
//#include "WorkingState.h"

//class WorkingState;
//class BrokenState;
class TestState {

private:
	Rocket* rocketForTest;
//	TestStrat* testS;
    string stateOfRocket;

public:
    TestState(Rocket*);

    bool runStaticTest();

	TestState* getWorkingState();

    void checkState();

	TestState* getBrokenState();
};

#endif
