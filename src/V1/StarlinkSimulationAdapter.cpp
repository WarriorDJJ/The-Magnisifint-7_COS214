#include "StarlinkSimulationAdapter.h"

StarlinkSimulationAdapter::StarlinkSimulationAdapter(Starlink* starlink) {
	this->starlink = starlink;
}

void StarlinkSimulationAdapter::launch() {
    Simulation::launch();
	starlink->release();
}
