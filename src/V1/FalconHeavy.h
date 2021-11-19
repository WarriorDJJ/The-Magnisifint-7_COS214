#ifndef FALCONHEAVY_H
#define FALCONHEAVY_H

#include "Rocket.h"
class FalconHeavy : public Rocket
{

protected:
	Rocket* LeftBooster;
	Rocket* RightBooster;

public:
    FalconHeavy(Rocket* lb, Rocket* rb);

	void SeperateStage();

	void Activate();

	virtual FalconHeavy * clone();

    virtual double getThrust(double externalPressure);

    Engine *getEngine(int i) override;

    int getNumEngines() override;
};

#endif
