#ifndef ROCKETBUILDERDIRECTOR_H
#define ROCKETBUILDERDIRECTOR_H

class RocketBuilderDirector {

private:
	BuildStrategy* strategy;

public:
	void setStrategy(BuildStrategy* s);

	void build();
};

#endif
