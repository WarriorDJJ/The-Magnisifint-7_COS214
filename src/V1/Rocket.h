#ifndef ROCKET_H
#define ROCKET_H

using namespace std;
#include "SpaceCraft.h"
#include "Engine.h"
#include <string>
#include <vector>

class Rocket : public SpaceCraft {

protected:
    double length; /*!< This is the length of the rocket */
    double diameter; /*!< This is the diameter of the rocket */
    double wetMass; /*!< ---- */
    double dryMass; /*!< ---- */
	SpaceCraft* NextStage; /*!< ---- */
    string name; /*!< The name of the rocket */

public:
    Rocket();
    Rocket(string name, double length = 0, double diameter = 0, double wetMass = 0, double dryMass = 0);


    void DestroyRocket();

    virtual string getName();

    //engine part
    virtual void AddEngine(Engine * engine);
    virtual void RemoveEngine(Engine * engine);
    virtual Engine * getEngine(int i);
    virtual int getNumEngines();

    virtual void AddStage(SpaceCraft* s);
    virtual Rocket * SeperateStage();
    virtual SpaceCraft * GetNextStage();
    virtual SpaceCraft * GetNextStageMain();
	virtual void Activate();

	virtual Rocket * clone();

    virtual void appendStage(SpaceCraft *s);

    virtual double getThrust(double externalPressure);

    virtual void LoadFuel();
    virtual double GetFuel();
    virtual void VentFuel();
    virtual void notify(Engine * engine);

    vector<Engine*> engines;
    string rocketState;

    virtual ~Rocket();
};

#endif
