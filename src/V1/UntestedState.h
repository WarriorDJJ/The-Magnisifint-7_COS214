#ifndef UNTESTEDSTATE_H
#define UNTESTEDSTATE_H
#include "TestState.h"
#include "Rocket.h"
#include "BrokenState.h"
#include "WorkingState.h"
class UntestedState : public TestState
{
    
public:
    UntestedState(Rocket* r);
    //virtual  launch(Simulation *sim);
    TestState* launch() override;
    bool runStaticTest() override;
};

#endif
