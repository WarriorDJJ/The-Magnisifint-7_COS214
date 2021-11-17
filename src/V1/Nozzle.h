#ifndef BELL_H
#define BELL_H

#include "Engine.h"


class Nozzle : public Engine {

protected:
	double length;
	double diameter;
    double nozzleArea;
    double throatArea;
	Engine* motor;

public:
    Nozzle();
    virtual void addComponent(Engine*);
    virtual double getThrust(double externalPressure);
    virtual Engine * clone();

    virtual void StartEngine();
    virtual void setSpacecraft(SpaceCraft* spacecraft);
    virtual bool isFail() const;
    virtual void setFail(bool fail);
    virtual SpaceCraft *getSpaceCraft() const;
    virtual void update();

    void setAttributes();

    Engine *getMotor() const;
    void setMotor(Engine *motor);
};

#endif