#ifndef STARLINKSIMULATIONADAPTER_H
#define STARLINKSIMULATIONADAPTER_H

class StarlinkSimulationAdapter : Simulation {

public:
	Starlink* starlink;

	StarlinkSimulationAdapter(Starlink* starlink);

	void launch();
};

#endif
