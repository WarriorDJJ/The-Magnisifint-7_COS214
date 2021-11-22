#ifndef WORKINGSTATE_H
#define WORKINGSTATE_H

#include "TestState.h"
#include "BrokenState.h"


class WorkingState : public TestState {

public:
    WorkingState(Rocket *rocket);
    TestState* launch() override;
    bool runStaticTest() override;
};

#endif
