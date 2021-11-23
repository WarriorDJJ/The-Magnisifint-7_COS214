#ifndef CARGODRAGON_H
#define CARGODRAGON_H

#include "Dragon.h"

class CargoDragon : public Dragon {
private:
    double mass;
public:
    virtual void LoadFuel();
    virtual double GetFuel();
    virtual void VentFuel();
    CargoDragon(double m);
    virtual void Activate();
    virtual Payload * clone();
    virtual string getName();
};

#endif
