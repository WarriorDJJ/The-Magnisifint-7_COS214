#ifndef STOREDSIMSTATE_H
#define STOREDSIMSTATE_H
#include "TestState.h"
#include "Payload.h"
class StoredSimState {
    public:
        StoredSimState(TestState* t, Payload* p);
        TestState* getTestState();
        Payload* getPayload();
        void setTestState(TestState* t);
        void setPayload(Payload *p);
    private:
        TestState* testState;
        Payload* payload;
};

#endif
