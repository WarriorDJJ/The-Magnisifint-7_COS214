#ifndef WORKINGSTATE_H
#define WORKINGSTATE_H

#include "TestState.h"
#include "BrokenState.h"


class WorkingState : public TestState {

public:
    WorkingState(Rocket *rocket);
    WorkingState(WorkingState* s);
    virtual TestState* launch();
    virtual bool runStaticTest();
    virtual TestState* clone();
};

#endif
