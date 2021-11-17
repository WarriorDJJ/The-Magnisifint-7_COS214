#include "Simulation.h"

void Simulation::launch() {
	// TODO - implement Simulation::launch
	throw "Not yet implemented";
}

void Simulation::launch(Rocket* myRocket)
{

    rocketForSim = myRocket;

    vector<Engine*> engineList;
    int numberOfEngines = engineList.size();

    for (int i = 0; i < numberOfEngines; ++i)
    {
        rocketForSim->engines[i]->StartEngine();
        if (rocketForSim->engines[i]->isFail())
        {
            rocketForSim->rocketState = "faulty";

            return;
        }
    }

}


void Simulation::setState(bool working) {
	// TODO - implement Simulation::setState
	throw "Not yet implemented";
}
