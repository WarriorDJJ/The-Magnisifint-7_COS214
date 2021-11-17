#ifndef VACUMEBELL_H
#define VACUMEBELL_H

#include "Nozzle.h"

class VacumeBell : public Nozzle {


public:
	double getThrust(double externalPressure);
	Engine* clone() override;
};

#endif
