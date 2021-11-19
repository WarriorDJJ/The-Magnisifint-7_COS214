#ifndef ROCKET_H
#define ROCKET_H

using namespace std;
#include "SpaceCraft.h"
#include "Engine.h"
#include <string>
#include <vector>

class Rocket : public SpaceCraft {

private:
    int EnginesFailed;
    double fuel;
    double wetMass;
    double dryMass;
	SpaceCraft* NextStage;
    string name;

public:
    Rocket();
    Rocket(double f, double wm, double dm, string n);

    void DestroyRocket();
    //engine part
    void AddEngine(Engine * engine) override;
    void RemoveEngine(Engine * engine) override;
    Engine * getEngine(int i) override;
    int getNumEngines() override;

    virtual void AddStage(SpaceCraft* s);
    virtual void SeperateStage();
    virtual SpaceCraft * GetNextStage();
	virtual void Activate();

	virtual Rocket * clone();

    void appendStage(SpaceCraft *s) override;

    virtual double getThrust(double externalPressure);

    void LoadFuel() override;
    int GetFuel() override;
    void VentFuel() override;
    virtual void notify(Engine * engine);
    vector<Engine*> engines;
    string rocketState;

    virtual ~Rocket();
};

#endif
