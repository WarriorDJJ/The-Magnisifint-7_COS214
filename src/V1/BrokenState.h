#ifndef BROKENSTATE_H
#define BROKENSTATE_H

#include "TestState.h"

class BrokenState : public TestState
{
protected:
    Rocket* myRocket;
public:
    BrokenState(Rocket *rocket);
    virtual void launch();
};

#endif
