#ifndef SPACECRAFT_H
#define SPACECRAFT_H
#include <iostream>

class Engine;
class SpaceCraft {
protected:
	bool isFinalStage;
    int EnginesFailed;
    int statusCode;

public:
    SpaceCraft();
    virtual void AddStage(SpaceCraft* s);
    virtual SpaceCraft * SeperateStage();
    virtual SpaceCraft* GetNextStage();

    virtual int getStatusCode();//0: No Problems, 1: Some Problems but still Working, 2: Not Working, 3: Exploded

    virtual void LoadFuel()=0;
    virtual double GetFuel()=0;
    virtual void VentFuel()=0;
    virtual void Activate()=0;

    virtual SpaceCraft * clone()=0;

    virtual void notify(Engine * engine);

    //end ll
    virtual void appendStage(SpaceCraft* s);

    virtual double getThrust(double externalPressure);

    virtual void AddEngine(Engine * engine);
    virtual void RemoveEngine(Engine * engine);
    virtual Engine * getEngine(int i);
    virtual int getNumEngines();
};

#endif
