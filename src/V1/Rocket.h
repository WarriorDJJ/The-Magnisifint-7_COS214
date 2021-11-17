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
    vector<Engine*> engines;
    string rocketState;

    virtual ~Rocket();
};

#endif
