#include "RocketMotor.h"

RocketMotor::RocketMotor(int cp) : Engine(-1){
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

Engine * RocketMotor::clone() {
	// TODO - implement RocketMotor::clone
	throw "Not yet implemented";
}
