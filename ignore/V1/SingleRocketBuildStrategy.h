#ifndef SINGLEROCKETBUILDSTRATEGY_H
#define SINGLEROCKETBUILDSTRATEGY_H

#include "BuildStrategy.h"

class SingleRocketBuildStrategy : public BuildStrategy {


public:
	SingleRocketBuildStrategy(RocketBuilder *b);

	void build();
};

#endif
