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
    UntestedState(UntestedState* s);
    //virtual  launch(Simulation *sim);
    virtual TestState* launch();
    virtual bool runStaticTest();
    virtual TestState* clone();
};

#endif
