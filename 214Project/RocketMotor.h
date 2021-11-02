#ifndef ROCKETMOTOR_H
#define ROCKETMOTOR_H

class RocketMotor : Engine {

public:
	int ISP;

	int getISP();

	int getThrust(int a);

	void clone();
};

#endif
