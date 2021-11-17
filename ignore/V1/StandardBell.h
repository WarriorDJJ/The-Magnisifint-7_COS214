#ifndef STANDARDBELL_H
#define STANDARDBELL_H

#include "Bell.h"

class StandardBell : public Bell {


public:
	int getThrust(int a);

	void clone();
};

#endif
