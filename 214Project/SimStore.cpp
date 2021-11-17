#include "SimStore.h"

void SimStore::storeSim(StoredSim* mem) {
    _mem = mem;
}

StoredSim* SimStore::getSim() {
	// TODO - implement SimStore::getSim
	return _mem;
}
