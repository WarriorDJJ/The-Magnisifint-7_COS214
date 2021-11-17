#ifndef BROKENSTATE_H
#define BROKENSTATE_H

#include "TestState.h"

class BrokenState : public TestState
{
public:
    BrokenState(Rocket *rocket);

    bool launch(Rocket *);
};

#endif
