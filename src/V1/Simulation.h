#ifndef SIMULATION_H
#define SIMULATION_H
#include "TestState.h"
#include "Payload.h"
#include "Rocket.h"

class Simulation {

protected:
	//TestState* state;
	Payload* payload;
    Rocket* rocketForSim;

public:
	void launch();

    void launch(Rocket*);

	void setState(bool working);
};

#endif
