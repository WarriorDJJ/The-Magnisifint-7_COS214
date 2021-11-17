#ifndef FULLSTACKBUILDSTRATEGY_H
#define FULLSTACKBUILDSTRATEGY_H
#include "BuildStrategy.h"
class FullStackBuildStrategy : public BuildStrategy {

protected:
    SpaceCraft* payload;

public:
	virtual void build();
	FullStackBuildStrategy(RocketBuilder *b, SpaceCraft *payload);
};

#endif
