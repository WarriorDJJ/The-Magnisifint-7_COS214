#include <iostream>
using namespace std;
#include "Nozzle.h"
#include "BrokenState.h"
#include "BuildStrategy.h"
#include "CargoDragon.h"
#include "Command.h"
#include "CrewDragon.h"
#include "Dragon.h"
#include "Engine.h"
#include "EngineFactory.h"
#include "Falcon9TS.h"
#include "FalconBuilder.h"
#include "FalconHeavy.h"
#include "FalconHeavyBuilder.h"
#include "FalconHeavyTS.h"
#include "FullStackBuildStrategy.h"
#include "Invoker.h"
#include "Iterator.h"
#include "LaunchCommand.h"
#include "LinkedList.h"
#include "MerlinEngine.h"
#include "MerlinEngineFactory.h"
#include "MerlinFactory.h"
#include "MotorFactory.h"
#include "Payload.h"
#include "Rocket.h"
#include "RocketBuilder.h"
#include "RocketBuilderDirector.h"
#include "RocketMotor.h"
#include "Satelite.h"
#include "SimStore.h"
#include "Simulation.h"
#include "SingleRocketBuildStrategy.h"
#include "SpaceCraft.h"
#include "StandardBell.h"
#include "StandardSimulation.h"
#include "Starlink.h"
#include "StarlinkSimulationAdapter.h"
#include "StoredSim.h"
#include "StoredSimState.h"
#include "TestState.h"
#include "UntestedState.h"
#include "UpperStageBuilder.h"
#include "VacumeBell.h"
#include "WorkingState.h"
#include "TestStrat.h"
#include <stdlib.h>     /* srand, rand */

void Starlink(){

}

void Falcon9(){

}

void FalconHeavy(){

}

int main() {
    cout << "Hello, World!" << endl;
    //MotorFactory* merlinFact = new MerlinFactory();
    //RocketMotor* yeet = merlinFact->createMotor();
    //cout << yeet->getChamberPressure();

    //Keelan testing his Builder and Strategy

    RocketBuilder* FHbuilder = new FalconHeavyBuilder();
    SpaceCraft* myPayload = new Satelite();
    BuildStrategy* myStrat = new FullStackBuildStrategy(FHbuilder , myPayload);
    RocketBuilderDirector* director = new RocketBuilderDirector();
    director->setStrategy(myStrat);
    director->build();

    delete director;
    return 0;
}
