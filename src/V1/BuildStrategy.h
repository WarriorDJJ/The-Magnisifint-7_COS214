#ifndef BUILDSTRATEGY_H
#define BUILDSTRATEGY_H

#include "RocketBuilder.h"

class BuildStrategy {

private:
	RocketBuilder* b;

public:
	BuildStrategy(RocketBuilder* b);

	void build();
};

#endif
