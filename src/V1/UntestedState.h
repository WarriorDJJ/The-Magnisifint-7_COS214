#ifndef UNTESTEDSTATE_H
#define UNTESTEDSTATE_H
#include "TestState.h"
#include "Rocket.h"
class UntestedState : public TestState
{

protected:
    Rocket* thisRocket;
public:
    UntestedState(Rocket* r);
    //virtual  launch(Simulation *sim);
    TestState launch() override;
};

#endif
