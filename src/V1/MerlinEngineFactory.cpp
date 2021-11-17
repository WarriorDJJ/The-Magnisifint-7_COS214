#include "MerlinEngineFactory.h"
#include "VacumeBell.h"
#include "StandardBell.h"
Engine* MerlinEngineFactory::createVacuumEngine(){
	// TODO - implement MerlinEngineFactory::createVacuumEngine
    //return new Engine(0);
    return new VacumeBell();
}

Engine* MerlinEngineFactory::createStandardEngine(){
	// TODO - implement MerlinEngineFactory::createStandardEngine
    return new StandardBell();
}
