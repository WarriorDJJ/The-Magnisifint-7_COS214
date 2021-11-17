#ifndef STOREDSIM_H
#define STOREDSIM_H

#include "StoredSimState.h"

class StoredSim {

private:
	StoredSimState* _state;

public:
	StoredSim(TestState* testState, Payload* payload);
    StoredSimState* getState();
	~StoredSim();
};

#endif
