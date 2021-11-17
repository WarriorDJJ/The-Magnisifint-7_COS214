//
// Created by djjor on 2021-11-17.
//
#include "StoredSimState.h"
StoredSimState::StoredSimState(TestState *t, Payload *p) {
    testState = t;
    payload = p;
}

TestState *StoredSimState::getTestState() {
    return testState;
}

Payload *StoredSimState::getPayload() {
    return payload;
}

void StoredSimState::setPayload(Payload *p) {
    payload = p;
}

void StoredSimState::setTestState(TestState *t) {
    testState = t;
}


