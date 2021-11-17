#ifndef ROCKETBUILDERDIRECTOR_H
#define ROCKETBUILDERDIRECTOR_H

#include "BuildStrategy.h"

class RocketBuilderDirector {

private:
	BuildStrategy* strategy;

public:
    RocketBuilderDirector();
	void setStrategy(BuildStrategy* s);
	void build();
};

#endif
