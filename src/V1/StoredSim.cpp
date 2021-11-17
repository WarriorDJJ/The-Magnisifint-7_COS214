#include "StoredSim.h"

StoredSim::StoredSim(TestState* testState, Payload* payload) {
	_state = new StoredSimState(testState, payload);
}

StoredSim::~StoredSim() {
	delete _state;
}

StoredSimState *StoredSim::getState() {
    return _state;
}
