#ifndef VACUMEBELL_H
#define VACUMEBELL_H

#include "Bell.h"

class VacumeBell : public Bell {


public:
	double getThrust(double altitude);
	Engine* clone() override;
};

#endif
