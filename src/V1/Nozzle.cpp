#include "Nozzle.h"

using namespace std;
double Nozzle::getThrust(double externalPressure) {
    double Pt = 101325; //Total Pressure
	double Tt = 3500; //Total Temperature
	double Po = 9.7; //Free Steam Pressure
	double Y = 16; //Specific Heat Ratio
	double R = 8.314; //Universal Gas Constant
	double ASmall = M_PI*pow((0.22/2),2); //Nozzle Throat Area
	double ABig = M_PI*pow((0.97/2),2); //Nozzle Exit Area
	double Me = 100000; // ??????

	//Mass Flow Rate: m* = (A*Pt)/sqrt(Tt) * (sqrt(Y/R)) * ((Y+1)/2)^(-((Y+1)/2(Y-1)))
	double power = (-((Y+1)/(2*(Y-1))));
	double base = ((Y+1)/2);
	double MFR = (ASmall*Pt)/sqrt(Tt) * (sqrt(Y/R)) * pow(base,power);
	//Exit Mach: Ae/ASmall
	double secondPart = (((Y-1)/2)*(pow(Me,2))) + 1;
	double EM = pow(base,power) * ((pow(secondPart,power))/Me);
			EM *= ASmall;
	//Exit Temperature
	double ET = pow(secondPart,-1);
			ET *= Tt;
	//Exit Pressure
	double EP = pow(secondPart,(-Y/(Y-1)));
	//Exit Velocity
	double EV = Me*(sqrt(Y*R*ET));
	//Thrust
	double F = MFR * EV + (EP - Po) * EM;

	cout << "Nozzle Throat Area: " << ASmall << endl;
	cout << "Nozzle Exit Area: " << ABig << endl;
	cout << "Mass Flow Rate: " << MFR << endl;
	cout << "Exit Mach: " << EM << endl;
	cout << "Exit Temperature: " << ET << endl;
	cout << "Exit Pressure: " << EP << endl;
	cout << "Exit Velocity: " << EV << endl;
	cout << "Thrust: " << F << endl;
	return F;
}

Nozzle * Nozzle::clone() {
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

Engine *Nozzle::getMotor() const {
    return motor;
}

void Nozzle::setMotor(Engine *motor) {
    Nozzle::motor = motor;
}

void Nozzle::StartEngine() {
    motor->StartEngine();
    update();

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
    this->spaceCraft = motor->getSpaceCraft();
    Engine::update();
}

void Nozzle::setLength(double length) {
    Nozzle::length = length;
}

void Nozzle::setDiameter(double diameter) {
    Nozzle::diameter = diameter;
}

void Nozzle::setNozzleArea(double nozzleArea) {
    Nozzle::nozzleArea = nozzleArea;
}

void Nozzle::setThroatArea(double throatArea) {
    Nozzle::throatArea = throatArea;
}


