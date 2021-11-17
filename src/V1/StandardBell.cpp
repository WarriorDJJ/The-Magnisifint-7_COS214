#include "StandardBell.h"

double StandardBell::getThrust(double externalPressure) {
    return Nozzle::getThrust(externalPressure);
}
