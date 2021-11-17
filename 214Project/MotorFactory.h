#ifndef MOTORFACTORY_H
#define MOTORFACTORY_H

class MotorFactory {


public:
	virtual RocketMotor* createMotor() = 0;
};

#endif
