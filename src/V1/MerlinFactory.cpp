#include "MerlinFactory.h"

RocketMotor* MerlinFactory::createMotor() {
	// TODO - implement MerlinFactory::createMotor
    return new RocketMotor();
}