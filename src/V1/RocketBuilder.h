#ifndef ROCKETBUILDER_H
#define ROCKETBUILDER_H

#include "Rocket.h"
#include "EngineFactory.h"
#include "MerlinEngineFactory.h"

class RocketBuilder
{

protected:
	Rocket* rocket;

public:
	virtual void createRocket() = 0;

	Rocket* getRocket();//test to see if this needs Virtual

	virtual void createEngines() = 0;

	void attachPayload(SpaceCraft* p);
};

#endif
