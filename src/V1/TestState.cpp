#include "TestState.h"

Rocket *TestState::getRocket() {
    return rocketForTest;
}

TestState::TestState(Rocket *r) {
    rocketForTest = r;
}

string TestState::checkState() {
    return state;
}
