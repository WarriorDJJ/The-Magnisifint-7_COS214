#ifndef ROCKETMOTOR_H
#define ROCKETMOTOR_H

#include "Engine.h"

class RocketMotor : public Engine {
protected:
    double chamberPressure;

public:
    RocketMotor();

    void setChamberPressure(double chamberPressure);
    virtual double getChamberPressure();
    virtual void update();
    RocketMotor * clone() override;

    double getThrust(double externalPressure) override;
};

#endif
