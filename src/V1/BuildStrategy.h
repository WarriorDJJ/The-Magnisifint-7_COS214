#ifndef BUILDSTRATEGY_H
#define BUILDSTRATEGY_H

#include "RocketBuilder.h"

class BuildStrategy {

protected:
	RocketBuilder* b;

public:
	BuildStrategy(RocketBuilder* b);

	virtual void build() = 0;
};

#endif
