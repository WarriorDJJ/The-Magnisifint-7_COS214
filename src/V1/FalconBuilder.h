#ifndef FALCONBUILDER_H
#define FALCONBUILDER_H
#include "RocketBuilder.h"
class FalconBuilder : public RocketBuilder {

public:
	virtual void createRocket();

	virtual void createEngines();

   // virtual void attachPayload(SpaceCraft *p);
};

#endif
