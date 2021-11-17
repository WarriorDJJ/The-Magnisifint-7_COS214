#ifndef BELL_H
#define BELL_H

#include "Engine.h"

class Bell : public Engine {

protected:
	int len;
	int diameter;
	Engine motor;

public:
    Bell(int thrust, int len, int diameter);
    virtual void addComponent()
    virtual int getThrust(int a);
    virtual Engine * clone();
};

#endif poes
