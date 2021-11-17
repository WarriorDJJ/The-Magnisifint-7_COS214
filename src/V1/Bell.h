#ifndef BELL_H
#define BELL_H

#include "Engine.h"


class Bell : public Engine {

protected:
	double length;
	double diameter;
    double isp;
	Engine* motor;

public:
    Bell();
    virtual void addComponent(Engine*);
    virtual double getThrust(double altitude);
    virtual Engine * clone();

    int getLength() const;
    void setLength(int length);
    int getDiameter() const;
    void setDiameter(int diameter);
    int getIsp() const;
    void setIsp(int isp);
    Engine *getMotor() const;
    void setMotor(Engine *motor);
};

#endif