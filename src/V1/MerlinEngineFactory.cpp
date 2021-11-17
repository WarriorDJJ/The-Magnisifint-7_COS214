#include "MerlinEngineFactory.h"

Engine* MerlinEngineFactory::createVacuumEngine(){
	// TODO - implement MerlinEngineFactory::createVacuumEngine
    return new Engine(0);
}

Engine* MerlinEngineFactory::createStandardEngine(){
	// TODO - implement MerlinEngineFactory::createStandardEngine
    return new Engine(0);
}
