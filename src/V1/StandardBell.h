#ifndef STANDARDBELL_H
#define STANDARDBELL_H

#include "Nozzle.h"

class StandardBell : public Nozzle {
public:
	double getThrust(double externalPressure) override;

    StandardBell *clone() override;
};

#endif
