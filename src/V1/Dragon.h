#ifndef DRAGON_H
#define DRAGON_H

#include "Payload.h"

class Dragon : public Payload{
protected:

public:
    virtual void Activate() = 0;
    virtual Payload * clone() = 0;

    void LoadFuel() override;
    double GetFuel() override;
    void VentFuel() override;
};

#endif
