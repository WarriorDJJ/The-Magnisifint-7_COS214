#ifndef STOREDSIM_H
#define STOREDSIM_H

class StoredSim {

private:
	StoredSimState* _state;

public:
	StoredSim(TestState* testState, Payload* payload);

	~StoredSim();
};

#endif
