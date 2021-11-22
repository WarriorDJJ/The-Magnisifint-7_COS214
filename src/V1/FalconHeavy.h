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

    Rocket * SeperateStage() override;
    virtual SpaceCraft * GetNextStage();
	void Activate() override;

	FalconHeavy * clone() override;

    double getThrust(double externalPressure) override;
    Engine *getEngine(int i) override;
    int getNumEngines() override;

    void LoadFuel() override;
    double GetFuel() override;
    void VentFuel() override;
    void useFuel(double Percent) override;
};

#endif
