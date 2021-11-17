#ifndef FULLSTACKBUILDSTRATEGY_H
#define FULLSTACKBUILDSTRATEGY_H

class FullStackBuildStrategy : public BuildStrategy {


public:
	void build();

	FullStackBuildStrategy(RocketBuilder* b, SpaceCraft* payload);
};

#endif
