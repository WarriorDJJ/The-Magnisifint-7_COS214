#include "Nozzle.h"

using namespace std;
double Nozzle::getThrust(double externalPressure) {
    double thrustAtSeaLevel = 854; //100% thrust at sea level = 845kN
    diameter = 0.92;  //diameter at sea level
    double thrust = nozzleArea * diameter * length * 42069 * thrustAtSeaLevel;    //calculating the thrust vector of the individual bell
    return thrust;
}

Engine * Nozzle::clone() {
    Nozzle * temp = new Nozzle();
    temp->motor = this->motor->clone();
    temp->diameter = this->diameter;
    temp->length = this->length;
    temp->nozzleArea = this->nozzleArea;
    temp->throatArea = this->throatArea;
    return temp;
}

Nozzle::Nozzle() : Engine(){}


void Nozzle::addComponent(Engine * e) {
    if(motor != nullptr) {
        delete motor;
        motor = nullptr;
    }
    motor = e;

}

//

Engine *Nozzle::getMotor() const {
    return motor;
}

void Nozzle::setMotor(Engine *motor) {
    Nozzle::motor = motor;
}

void Nozzle::StartEngine() {
    motor->StartEngine();

}

void Nozzle::setSpacecraft(SpaceCraft *spacecraft) {
    motor->setSpacecraft(spacecraft);
}

bool Nozzle::isFail() const {
    return motor->isFail();
}

void Nozzle::setFail(bool fail) {
    motor->setFail(fail);
}

SpaceCraft *Nozzle::getSpaceCraft() const {
    return motor->getSpaceCraft();
}

void Nozzle::update() {
    motor->getSpaceCraft()->notify(this);
}


