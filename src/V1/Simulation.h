#ifndef SIMULATION_H
#define SIMULATION_H
#include "TestState.h"
#include "Payload.h"
class Simulation {

private:
	TestState* state;
	Payload* payload;

public:
	void launch();

	void setState(bool working);
};

#endif
