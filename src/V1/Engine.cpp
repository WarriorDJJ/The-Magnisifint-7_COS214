#include "Engine.h"
using namespace std;

double Engine::getThrust(double externalPressure){
    double Pt = 101325; //Total Pressure
	double Tt = 3500; //Total Temperature
	double Po = 9.7; //Free Steam Pressure
	double Y = 16; //Specific Heat Ratio
	double R = 8314; //Universal Gas Constant
	double ASmall = (3.14)*pow((0.22/2),2); //Nozzle Throat Area
	double ABig = (3.14)*pow((0.97/2),2); //Nozzle Exit Area
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

//	cout << "Nozzle Throat Area: " << ASmall << endl;
//	cout << "Nozzle Exit Area: " << ABig << endl;
//	cout << "Mass Flow Rate: " << MFR << endl;
//	cout << "Exit Mach: " << EM << endl;
//	cout << "Exit Temperature: " << ET << endl;
//	cout << "Exit Pressure: " << EP << endl;
//	cout << "Exit Velocity: " << EV << endl;
//	cout << "Thrust: " << F << endl;
	return F;
}

 Engine * Engine::clone(){
	Engine * newEngine = new Engine();

    newEngine->spaceCraft = this->spaceCraft;
    newEngine->fail = this->fail;

    return newEngine;
}

Engine::Engine(){
    this->fail = false;
    this->spaceCraft = nullptr;
}

void Engine::setSpacecraft(SpaceCraft *spacecraft) {
    this->spaceCraft = spacecraft;
}

void Engine::update() {
    if(spaceCraft== nullptr) cout<<"spacecraft not set"<<endl;
    else this->spaceCraft->notify(this);
}

void Engine::StartEngine() {
    int rand1 = rand() % 100 + 1;
    if(rand1 >=95 && rand1 <=100){
        cout << "Engine Failed!"<<endl;
        this->fail = true;
        this->update();
    }
    else {
        cout << "Engine started successfully!"<<endl;
        this->fail = false;
    }
}

bool Engine::isFail() const {
    return fail;
}

void Engine::setFail(bool fail) {
    Engine::fail = fail;
}

SpaceCraft *Engine::getSpaceCraft() const {
    return spaceCraft;
}
