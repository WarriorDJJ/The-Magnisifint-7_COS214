#ifndef FALCONHEAVYBUILDER_H
#define FALCONHEAVYBUILDER_H

#include "RocketBuilder.h"
#include "FalconHeavy.h"

class FalconHeavyBuilder : public RocketBuilder{

private:
    Rocket* LeftBooster;
    Rocket* RightBooster;
public:
	virtual void createRocket();
	virtual void createEngines();
    Rocket* getLeft();
    Rocket* getRight();
};

#endif
