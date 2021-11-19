#include "VacuumBell.h"

double VacuumBell::getThrust(double externalPressure) {
	// TODO - implement VacuumBell::getThrust
    double thrustInVacuum = 981; // 100% thrust level in vacuum = 981kN
    nozzleArea = externalPressure;
    diameter = 3.3; //diameter in vacuum
    double thrust = nozzleArea * diameter * length * 420 * thrustInVacuum; //calculating the thrust
	return thrust;
}

VacuumBell *VacuumBell::clone() {
    VacuumBell * temp = new VacuumBell();
    temp->motor = this->motor->clone();

    temp->diameter = this->diameter;
    temp->length = this->length;
    temp->nozzleArea = this->nozzleArea;
    temp->throatArea = this->throatArea;
    return temp;
}
