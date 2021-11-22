#ifndef PAYLOAD_H
#define PAYLOAD_H

#include "SpaceCraft.h"

class Payload : public SpaceCraft {


public:
	virtual void Activate() = 0;
    virtual void LoadFuel();
    virtual double GetFuel();
    virtual void VentFuel() = 0;
	virtual Payload * clone() = 0;
    virtual string getName();
};

#endif
