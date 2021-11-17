#ifndef VACUMEBELL_H
#define VACUMEBELL_H

#include "Nozzle.h"

class VacuumBell : public Nozzle {

public:
	double getThrust(double externalPressure);
};

#endif
