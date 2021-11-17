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
public:
    Engine();
    void StartEngine();
    void setSpacecraft(SpaceCraft* spacecraft);
    virtual int getThrust(int a);
	virtual Engine * clone();
    void update();
};

#endif
