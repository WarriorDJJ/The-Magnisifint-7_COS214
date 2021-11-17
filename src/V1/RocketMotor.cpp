#include "RocketMotor.h"

RocketMotor::RocketMotor(int cp) {
    chamberPressure = cp;
}

int RocketMotor::getChamberPressure() {
    return chamberPressure;
}

int RocketMotor::getISP() {
	return ISP;
}

int RocketMotor::getThrust(int a) {
	// TODO - implement RocketMotor::getThrust
	throw "Not yet implemented";
}

void RocketMotor::clone() {
	// TODO - implement RocketMotor::clone
	throw "Not yet implemented";
}
