#ifndef STARLINKSIMULATIONADAPTER_H
#define STARLINKSIMULATIONADAPTER_H
#include "Simulation.h"
#include "Starlink.h"
class StarlinkSimulationAdapter : public Simulation {

public:
	Starlink* starlink;

	StarlinkSimulationAdapter(Starlink* starlink, Rocket* r);

	void launch();
};

#endif
