#ifndef ENGINEFACTORY_H
#define ENGINEFACTORY_H
#include "Engine.h"
class EngineFactory {


public:
	Engine* createVacuumEngine();

	Engine* createStandardEngine();
};

#endif
