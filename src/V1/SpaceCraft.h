#ifndef SPACECRAFT_H
#define SPACECRAFT_H
#include <iostream>

class Engine;
class SpaceCraft {
private:
	bool isFinalStage;
    int EnginesFailed;

public:
    SpaceCraft();
    virtual void AddStage(SpaceCraft* s);
    virtual void SeperateStage();
    virtual SpaceCraft* GetNextStage();
    virtual void LoadFuel()=0;
    virtual int GetFuel()=0;
    virtual void VentFuel()=0;
    virtual void Activate()=0;
    virtual void notify(Engine * engine);
    virtual SpaceCraft * clone()=0;

    //end ll
    virtual void appendStage(SpaceCraft* s);

    virtual double getThrust(double externalPressure);

    virtual void AddEngine(Engine * engine);
    virtual void RemoveEngine(Engine * engine);
    virtual Engine * getEngine(int i);
    virtual int getNumEngines();
};

#endif
