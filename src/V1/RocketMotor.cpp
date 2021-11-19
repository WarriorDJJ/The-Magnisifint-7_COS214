#include "RocketMotor.h"

RocketMotor::RocketMotor(){
    chamberPressure = 0;
}

double RocketMotor::getChamberPressure() {
    return chamberPressure;
}

RocketMotor * RocketMotor::clone() {
    RocketMotor * temp = new RocketMotor();

    temp->chamberPressure = this->chamberPressure;
    temp->fail = this->fail;
    temp->spaceCraft = this->spaceCraft;

    return temp;
}

void RocketMotor::setChamberPressure(double chamberPressure) {
    chamberPressure = chamberPressure;
}

double RocketMotor::getThrust(double externalPressure) {
    return 0;
}

void RocketMotor::update() {
    Engine::update();
}