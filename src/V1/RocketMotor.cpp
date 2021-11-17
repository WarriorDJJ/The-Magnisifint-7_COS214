#include "RocketMotor.h"

RocketMotor::RocketMotor(){
    chamberPressure = 0;
}

double RocketMotor::getChamberPressure() {
    return chamberPressure;
}

Engine * RocketMotor::clone() {
	// TODO - implement RocketMotor::clone
	throw "Not yet implemented";
}

void RocketMotor::setChamberPressure(double chamberPressure) {
    chamberPressure = chamberPressure;
}

double RocketMotor::getThrust(double externalPressure) {
    return 0;
}
