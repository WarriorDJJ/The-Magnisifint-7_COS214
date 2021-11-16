#ifndef SIMULATION_H
#define SIMULATION_H

class Simulation {

private:
	TestState* state;
	Payload* payload;

public:
	void launch();

	void setState(bool working);
};

#endif
