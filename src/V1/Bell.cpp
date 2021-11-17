#include "Bell.h"

using namespace std;
double Bell::getThrust(double altitude) {
    double thrustAtSeaLevel = 854; //100% thrust at sea level = 845kN
    Bell::isp = altitude;
    Bell::diameter = 0.92;
    double thrust = isp * diameter * length * 420 * thrustAtSeaLevel;    //calculating the thrust vector of the individual bell
    return thrust;
}

Engine * Bell::clone() {
	// TODO - implement Bell::clone
	return Engine::clone();
}

Bell::Bell(): Engine(){}

void Bell::addComponent(Engine *) {


}

int Bell::getLength() const {
    return length;
}

void Bell::setLength(int length) {
    Bell::length = length;
}

int Bell::getDiameter() const {
    return diameter;
}

void Bell::setDiameter(int diameter) {
    Bell::diameter = diameter;
}

int Bell::getIsp() const {
    return isp;
}

void Bell::setIsp(int isp) {
    Bell::isp = isp;
}

Engine *Bell::getMotor() const {
    return motor;
}

void Bell::setMotor(Engine *motor) {
    Bell::motor = motor;
}


