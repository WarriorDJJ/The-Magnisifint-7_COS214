#ifndef SINGLEROCKETBUILDSTRATEGY_H
#define SINGLEROCKETBUILDSTRATEGY_H

class SingleRocketBuildStrategy : BuildStrategy {


public:
	SingleRocketBuildStrategy(RocketBuilder* b);

	void build();
};

#endif
