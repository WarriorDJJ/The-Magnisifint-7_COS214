#ifndef MERLINENGINEFACTORY_H
#define MERLINENGINEFACTORY_H

#include "EngineFactory.h"

class MerlinEngineFactory : public EngineFactory {


public:
	virtual Engine* createVacuumEngine();
	virtual Engine* createStandardEngine();
};

#endif
