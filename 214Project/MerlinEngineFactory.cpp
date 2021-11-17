#include "MerlinEngineFactory.h"

Engine* MerlinEngineFactory::createVacuumEngine() const{
	// TODO - implement MerlinEngineFactory::createVacuumEngine
	throw "Not yet implemented";
}

Engine* MerlinEngineFactory::createStandardEngine() const{
	// TODO - implement MerlinEngineFactory::createStandardEngine
    return new Engine;
}
