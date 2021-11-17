#ifndef SPACECRAFT_H
#define SPACECRAFT_H

class Engine;
class SpaceCraft {
private:
	bool isFinalStage;

public:
    SpaceCraft();
    virtual void AddStage(SpaceCraft* s);
    virtual void SeperateStage();
    virtual SpaceCraft* GetNextStage();
    virtual void LoadFuel()=0;
    virtual int GetFuel()=0;
    virtual void VentFuel()=0;
    virtual void Activate()=0;
    virtual void notify(Engine * engine)=0;
    virtual SpaceCraft * clone()=0;
};

#endif
