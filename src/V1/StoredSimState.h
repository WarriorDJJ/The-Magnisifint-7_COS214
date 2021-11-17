#ifndef STOREDSIMSTATE_H
#define STOREDSIMSTATE_H
#include "TestState.h"
#include "Payload.h"
class StoredSimState {

private:
	TestState* testState;
	Payload* payload;
};

#endif
