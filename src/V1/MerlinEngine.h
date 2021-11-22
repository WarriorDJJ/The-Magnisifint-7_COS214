#ifndef MERLINENGINE_H
#define MERLINENGINE_H

#include "RocketMotor.h"

class MerlinEngine : public RocketMotor {
public:
    MerlinEngine();

    virtual MerlinEngine * clone();
    virtual void StartEngine();
};

#endif
