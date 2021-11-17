#ifndef MERLINENGINEFACTORY_H
#define MERLINENGINEFACTORY_H

#include "EngineFactory.h"

class MerlinEngineFactory : public EngineFactory {


public:
	Engine* createVacuumEngine();

	Engine* createStandardEngine();
};

#endif
