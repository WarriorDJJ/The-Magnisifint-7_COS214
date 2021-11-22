#ifndef SIMULATION_H
#define SIMULATION_H
//#include "TestState.h"
#include "WorkingState.h"
#include "BrokenState.h"
#include "UntestedState.h"
#include "Payload.h"
#include "Rocket.h"

using namespace std;

class TestState;

class Simulation {

protected:
    TestState* state;
    Payload* payload;
    Rocket* rocketForSim;

public:
    Simulation(Rocket *myRocket, Payload *p);
    bool launch();
    //void setState(bool working);
    void StaticTest();
    Payload* getPayload();
    TestState* getState();
};

#endif
