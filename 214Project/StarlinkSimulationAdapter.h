#ifndef STARLINKSIMULATIONADAPTER_H
#define STARLINKSIMULATIONADAPTER_H

class StarlinkSimulationAdapter : public Simulation {

public:
	Starlink* starlink;

	StarlinkSimulationAdapter(Starlink* starlink);

	void launch();
};

#endif
