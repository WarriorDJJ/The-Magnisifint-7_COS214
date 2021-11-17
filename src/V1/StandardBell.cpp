#include "StandardBell.h"

Engine *StandardBell::clone() {
    return Nozzle::clone();
}

double StandardBell::getThrust(double externalPressure) {
    return Nozzle::getThrust(externalPressure);
}
