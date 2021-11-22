#ifndef TESTSTATE_H
#define TESTSTATE_H

#include "SpaceCraft.h"
//#include "TestStrat.h"
#include "Rocket.h"
//#include "Simulation.h"
//class WorkingState;
//class BrokenState;
using namespace std;

//class Simulation;


class TestState {

private:
    Rocket* rocketForTest;

public:
    TestState(Rocket*);

    //virtual void launch(Simulation *sim) = 0;
    virtual TestState* launch() = 0;

    bool runStaticTest();

    TestState* getWorkingState();

    void checkState();

    TestState* getBrokenState();
};

#endif
