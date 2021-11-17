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
    virtual void StartEngine();
    virtual void setSpacecraft(SpaceCraft* spacecraft);

    virtual double getThrust(double altitude);
	virtual Engine * clone();
    virtual void update();

    virtual bool isFail() const;
    virtual void setFail(bool fail);
    virtual SpaceCraft *getSpaceCraft() const;
};

#endif
