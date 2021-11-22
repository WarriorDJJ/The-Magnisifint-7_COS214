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

    Rocket * SeperateStage() override;
    virtual SpaceCraft * GetNextStage();

	void Activate() override;

	FalconHeavy * clone() override;

    double getThrust(double externalPressure) override;

    Engine *getEngine(int i) override;

    int getNumEngines() override;
};

#endif
