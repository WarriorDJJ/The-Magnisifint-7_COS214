#include "MerlinEngineFactory.h"
#include "VacuumBell.h"
#include "StandardBell.h"
Engine* MerlinEngineFactory::createVacuumEngine(){
	VacuumBell* nozzle = new VacuumBell();
    nozzle->setDiameter(2.5);
    nozzle->setLength(2.7);
    nozzle->setNozzleArea(4.91);
    nozzle->setThroatArea(0.042);
    MerlinEngine* motor = new MerlinEngine();
    nozzle->addComponent(motor);

    return nozzle;
}

Engine* MerlinEngineFactory::createStandardEngine(){
    StandardBell* nozzle = new StandardBell();
    nozzle->setDiameter(1.07);
    nozzle->setLength(1.35);
    nozzle->setNozzleArea(0.9);
    nozzle->setThroatArea(0.042);
    MerlinEngine* motor = new MerlinEngine();
    nozzle->addComponent(motor);

    return nozzle;
}
