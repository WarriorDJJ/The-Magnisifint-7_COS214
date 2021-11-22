#ifndef SIMSTORE_H
#define SIMSTORE_H

#include "StoredSim.h"

class SimStore {

private:
	StoredSim* _mem;

public:
    ~SimStore();
	void storeSim(StoredSim* mem);
	StoredSim* getSim();
};

#endif
