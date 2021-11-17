#include "VacumeBell.h"

double VacumeBell::getThrust(double externalPressure) {
	// TODO - implement VacumeBell::getThrust
    double thrustInVacuum = 981; // 100% thrust level in vacuum = 981kN
    nozzleArea = externalPressure;
    diameter = 3.3; //diameter in vacuum
    double thrust = nozzleArea * diameter * length * 420 * thrustInVacuum; //calculating the thrust
	return thrust;
}

Engine *VacumeBell::clone() {
    return Nozzle::clone();
}
