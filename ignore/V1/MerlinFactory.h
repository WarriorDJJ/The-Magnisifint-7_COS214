#ifndef MERLINFACTORY_H
#define MERLINFACTORY_H

#include "MotorFactory.h"

class MerlinFactory : public MotorFactory {


public:
	RocketMotor* createMotor() override;
};

#endif
