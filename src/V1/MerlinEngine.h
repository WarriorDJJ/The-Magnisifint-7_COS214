#ifndef MERLINENGINE_H
#define MERLINENGINE_H

#include "RocketMotor.h"

class MerlinEngine : public RocketMotor {
public:
    MerlinEngine();

    MerlinEngine * clone() override;
    virtual void StartEngine();
};

#endif
