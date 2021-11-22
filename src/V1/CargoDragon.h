#ifndef CARGODRAGON_H
#define CARGODRAGON_H

#include "Dragon.h"

class CargoDragon : public Dragon {
private:
    double mass;
public:
    CargoDragon(double m);
    virtual void Activate();
    virtual Payload * clone();
};

#endif
