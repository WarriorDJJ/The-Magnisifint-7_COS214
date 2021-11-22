#ifndef BROKENSTATE_H
#define BROKENSTATE_H

#include "TestState.h"
#include "UntestedState.h"
class BrokenState : public TestState
{
public:
    BrokenState(Rocket *rocket);
    virtual TestState* launch();
    virtual bool runStaticTest();

};
// love you james keelan damian francois fourie (and zelda if she codes) -- Caleb
#endif
