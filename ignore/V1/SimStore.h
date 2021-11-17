#ifndef SIMSTORE_H
#define SIMSTORE_H

class SimStore {

private:
	StoredSim* _mem;

public:
	void storeSim(StoredSim* mem);

	StoredSim* getSim(int index);
};

#endif
