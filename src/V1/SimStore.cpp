#include "SimStore.h"

SimStore::~SimStore()
{
    delete _mem;
}

void SimStore::storeSim(StoredSim* mem) {
    _mem = mem;
}

StoredSim* SimStore::getSim() {
	// TODO - implement SimStore::getSim
	return _mem;
}
