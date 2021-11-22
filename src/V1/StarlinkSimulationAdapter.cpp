#include "StarlinkSimulationAdapter.h"

StarlinkSimulationAdapter::StarlinkSimulationAdapter(Starlink* starlink, Rocket* r) : Simulation(r){
	this->starlink = starlink;
}

void StarlinkSimulationAdapter::launch() {
    if(Simulation::launch()) {
        starlink->release();
    }
}
