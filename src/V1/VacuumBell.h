#ifndef VACUMEBELL_H
#define VACUMEBELL_H

#include "Nozzle.h"

class VacuumBell : public Nozzle {

public:
    virtual double getThrust(double externalPressure);

    virtual VacuumBell *clone();
};

#endif
