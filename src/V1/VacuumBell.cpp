#include "VacuumBell.h"

using namespace std;

double VacuumBell::getThrust(double externalPressure) {
	// TODO - implement VacuumBell::getThrust
//    double thrustInVacuum = 981; // 100% thrust level in vacuum = 981kN
//    nozzleArea = externalPressure;
//    diameter = 3.3; //diameter in vacuum
//    double thrust = nozzleArea * diameter * length * 420 * thrustInVacuum; //calculating the thrust
//	return thrust;
    double Pt = 101325; //Total Pressure
	double Tt = 300000; //Total Temperature
	double Po = 9.7; //Free Steam Pressure
	double Y = 16; //Specific Heat Ratio
	double R = 8314; //Universal Gas Constant
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

VacuumBell *VacuumBell::clone() {
    VacuumBell * temp = new VacuumBell();
    temp->motor = this->motor->clone();

    temp->diameter = this->diameter;
    temp->length = this->length;
    temp->nozzleArea = this->nozzleArea;
    temp->throatArea = this->throatArea;
    return temp;
}
