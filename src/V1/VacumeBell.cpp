#include "VacumeBell.h"

double VacumeBell::getThrust(double altitude) {
	// TODO - implement VacumeBell::getThrust
    //i'm doing research about rockets quick - fourie
    double thrustInVacuum = 981; // 100% thrust level in vacuum = 981kN
    VacumeBell::isp = altitude;
    VacumeBell::diameter = 3.3;
    double thrust = isp * diameter * length * 420 * thrustInVacuum; //calculating the thrust
	return thrust;
}

void VacumeBell::clone() {
	// TODO - implement VacumeBell::clone
	throw "Not yet implemented";
}








//:) :p (.Y.) (* Y *) (  .  Y  .  ) bigger is better, though not actually, not always no xd

