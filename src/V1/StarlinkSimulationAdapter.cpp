#include "StarlinkSimulationAdapter.h"

StarlinkSimulationAdapter::StarlinkSimulationAdapter(Starlink* starlink) {
	this->starlink = starlink;
}

void StarlinkSimulationAdapter::launch(Rocket* r) {
    Simulation::launch(r);
	starlink->release();
}
