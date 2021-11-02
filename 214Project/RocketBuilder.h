#ifndef ROCKETBUILDER_H
#define ROCKETBUILDER_H

class RocketBuilder {

private:
	Rocket* rocket;

public:
	void createRocket();

	Rocket* getRocket();

	void createEngines();

	void attachPayload(SpaceCraft* p);
};

#endif
