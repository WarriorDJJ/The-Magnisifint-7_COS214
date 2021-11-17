#ifndef FALCONHEAVYBUILDER_H
#define FALCONHEAVYBUILDER_H

#include "RocketBuilder.h"
#include "FalconHeavy.h"

class FalconHeavyBuilder : public RocketBuilder{

public:
	virtual void createRocket();

	virtual void createEngines();
};

#endif
