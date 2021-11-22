#ifndef SPACECRAFT_H
#define SPACECRAFT_H
#include <iostream>

using namespace std;

class Engine;
class SpaceCraft {
protected:
    double fuel;
	bool isFinalStage;
    int EnginesFailed;
    int statusCode;

public:
    SpaceCraft();
    virtual string getName() = 0;
    virtual void AddStage(SpaceCraft* s);
    virtual SpaceCraft * SeperateStage();
    virtual SpaceCraft* GetNextStage();
    virtual SpaceCraft * GetNextStageMain();

    virtual int getStatusCode();//0: No Problems, 1: Some Problems but still Working, 2: Not Working, 3: Exploded

    virtual void LoadFuel();
    virtual double GetFuel();
    virtual void VentFuel();
    virtual void Activate()=0;

    virtual void useFuel(double Percent);

    virtual SpaceCraft * clone()=0;

    virtual void notify(Engine * engine);

    //end ll
    virtual void appendStage(SpaceCraft* s);

    virtual double getThrust(double externalPressure);

    virtual void AddEngine(Engine * engine);
    virtual void RemoveEngine(Engine * engine);
    virtual Engine * getEngine(int i);
    virtual int getNumEngines();

    void setFuel(double fuel);
};

#endif
