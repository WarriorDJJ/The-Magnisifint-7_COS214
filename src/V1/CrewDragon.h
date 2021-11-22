#ifndef CREWDRAGON_H
#define CREWDRAGON_H

#include "Dragon.h"

class CrewDragon : public Dragon {
private:
    int crewCount;
public:
    virtual void LoadFuel();
    virtual double GetFuel();
    virtual void VentFuel();
    CrewDragon(int cc);
    virtual void Activate();
    virtual Payload * clone();
};

#endif
