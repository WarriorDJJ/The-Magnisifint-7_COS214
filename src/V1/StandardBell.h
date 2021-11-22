#ifndef STANDARDBELL_H
#define STANDARDBELL_H

#include "Nozzle.h"

class StandardBell : public Nozzle {
public:
	virtual double getThrust(double externalPressure);

    virtual StandardBell *clone();
};

#endif
