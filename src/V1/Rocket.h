#ifndef ROCKET_H
#define ROCKET_H

using namespace std;
#include "SpaceCraft.h"
#include "Engine.h"
#include <string>
#include <vector>

class Rocket : public SpaceCraft {

protected:
    double length;
    double diameter;
    double wetMass;
    double dryMass;
	SpaceCraft* NextStage;
    string name;

public:
    Rocket();
    Rocket(string name, double length = 0, double diameter = 0, double wetMass = 0, double dryMass = 0);

    void DestroyRocket();

    //engine part
    void AddEngine(Engine * engine) override;
    void RemoveEngine(Engine * engine) override;
    Engine * getEngine(int i) override;
    int getNumEngines() override;

    virtual void AddStage(SpaceCraft* s);
    virtual Rocket * SeperateStage();
    virtual SpaceCraft * GetNextStage();
	virtual void Activate();

	Rocket * clone() override;

    void appendStage(SpaceCraft *s) override;

    double getThrust(double externalPressure) override;

    void LoadFuel() override;
    double GetFuel() override;
    void VentFuel() override;
    virtual void notify(Engine * engine);

    vector<Engine*> engines;
    string rocketState;

    virtual ~Rocket();
};

#endif
