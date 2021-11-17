#ifndef BUILDSTRATEGY_H
#define BUILDSTRATEGY_H

#include "RocketBuilder.h"

class BuildStrategy {

protected:
	RocketBuilder* builder;

public:
	virtual void build() = 0;
    void setBuilder(RocketBuilder* rb);
};

#endif
