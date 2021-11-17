#ifndef ROCKETBUILDER_H
#define ROCKETBUILDER_H

#include "Rocket.h"
#include "MerlinEngineFactory.h"

class RocketBuilder
{

protected:
	Rocket* rocket;

public:
	virtual void createRocket() = 0;

	virtual Rocket* getRocket() = 0;

	virtual void createEngines() = 0;

	virtual void attachPayload(SpaceCraft* p) = 0;
};

#endif
