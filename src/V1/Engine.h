#ifndef ENGINE_H
#define ENGINE_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "SpaceCraft.h"

class Engine {
protected:
    SpaceCraft * spaceCraft;
    bool fail;
    int thrust;
public:
    Engine(int thrust);
    void setSpacecraft(SpaceCraft* Spacecraft);
    virtual int getThrust(int a);
	virtual Engine * clone();
};

#endif
