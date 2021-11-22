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
    virtual ~FalconHeavy();

//    virtual Rocket * SeperateStage();
    virtual SpaceCraft * GetNextStageMain();
	virtual void Activate();

	virtual FalconHeavy * clone();

    virtual double getThrust(double externalPressure);
    virtual Engine *getEngine(int i);
    virtual int getNumEngines();

    virtual void LoadFuel();
    virtual double GetFuel();
    virtual void VentFuel();
    virtual void useFuel(double Percent);
};

#endif
