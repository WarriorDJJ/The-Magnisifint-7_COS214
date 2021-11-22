#ifndef WORKINGSTATE_H
#define WORKINGSTATE_H

#include "TestState.h"

class WorkingState : public TestState {
protected:
    Rocket* myRocket;
public:
    WorkingState(Rocket *rocket);
    virtual void launch();
};

#endif
