#ifndef ROCKETMOTOR_H
#define ROCKETMOTOR_H

#include "Engine.h"

class RocketMotor : public Engine {
protected:
    int ISP;
    int chamberPressure;
public:
    RocketMotor(int cp);
    virtual int getISP();
    virtual int getChamberPressure();

    virtual int getThrust(int a);

	Engine * clone() override;
};

#endif
