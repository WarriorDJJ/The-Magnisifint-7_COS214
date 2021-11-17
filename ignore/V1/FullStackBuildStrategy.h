#ifndef FULLSTACKBUILDSTRATEGY_H
#define FULLSTACKBUILDSTRATEGY_H
#include "BuildStrategy.h"
class FullStackBuildStrategy : public BuildStrategy {


public:
	void build();

	FullStackBuildStrategy(RocketBuilder *b, SpaceCraft *payload);
};

#endif
