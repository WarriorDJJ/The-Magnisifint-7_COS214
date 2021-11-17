#ifndef WORKINGSTATE_H
#define WORKINGSTATE_H

#include "TestState.h"

class WorkingState : public TestState {
public:
    WorkingState(Rocket *rocket);

    bool launch();
};

#endif
