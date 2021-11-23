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

protected:
    Rocket* rocketForTest;
    string state;
public:
    TestState(Rocket*);
    //virtual void launch(Simulation *sim) = 0;
    virtual TestState* launch() = 0;
    virtual bool runStaticTest() = 0;
    string checkState();
    Rocket* getRocket();
    TestState* clone() = 0;
};

#endif
