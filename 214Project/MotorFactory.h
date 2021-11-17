#ifndef MOTORFACTORY_H
#define MOTORFACTORY_H

#include "RocketMotor.h"

class MotorFactory {


public:
	virtual RocketMotor* createMotor() = 0;
};

#endif
