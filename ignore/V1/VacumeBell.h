#ifndef VACUMEBELL_H
#define VACUMEBELL_H

#include "Bell.h"

class VacumeBell : public Bell {


public:
	int getThrust(int a);

	void clone();
};

#endif
