#ifndef BELL_H
#define BELL_H

#include <cmath>
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
    ~Nozzle();
    virtual void addComponent(Engine*);
    virtual double getThrust(double externalPressure);

    virtual Nozzle * clone();

    virtual void StartEngine();
    virtual void setSpacecraft(SpaceCraft* spacecraft);
    virtual bool isFail() const;
    virtual void setFail(bool fail);
    virtual SpaceCraft *getSpaceCraft() const;
    virtual void update();

    void setLength(double length);
    void setDiameter(double diameter);
    void setNozzleArea(double nozzleArea);
    void setThroatArea(double throatArea);

    Engine *getMotor() const;
    void setMotor(Engine *motor);
};

#endif