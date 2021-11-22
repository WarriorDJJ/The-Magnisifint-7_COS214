#ifndef BROKENSTATE_H
#define BROKENSTATE_H

#include "TestState.h"
#include "UntestedState.h"
class BrokenState : public TestState
{
public:
    BrokenState(Rocket *rocket);
    TestState* launch() override;
    bool runStaticTest() override;

};
// love you james keelan damian francois fourie (and zelda if she codes) -- Caleb
#endif
