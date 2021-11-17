#ifndef ROCKET_H
#define ROCKET_H

using namespace std;
#include <vector>
#include "SpaceCraft.h"
#include "Engine.h"
#include <string>

class Rocket : public SpaceCraft {

private:
    int EnginesFailed;
    double fuel;
    double wetMass;
    double dryMass;
	SpaceCraft* NextStage;
    string name;
protected:
    vector<Engine*> engines;

public:
    Rocket();
    Rocket(double f, double wm, double dm, string n);
    void AddEngine(Engine * engine);
    void RemoveEngine(Engine * engine);
    virtual void AddStage(SpaceCraft* s);
    virtual void SeperateStage();
    virtual SpaceCraft * GetNextStage();
	virtual void Activate();
	virtual Rocket * clone();

    void LoadFuel() override;
    int GetFuel() override;
    void VentFuel() override;
    void notify(Engine * engine) override;
};

#endif
