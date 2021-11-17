#ifndef ROCKETMOTOR_H
#define ROCKETMOTOR_H
#include "Engine.h"
class RocketMotor : public Engine {
private:
    int ISP;
    int chamberPressure;
public:
    RocketMotor(int cp);
	int getISP();
    int getChamberPressure();

	int getThrust(int a);

	void clone();
};

#endif
