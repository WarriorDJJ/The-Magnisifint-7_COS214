#ifndef MERLINENGINEFACTORY_H
#define MERLINENGINEFACTORY_H

#include "EngineFactory.h"
#include "MerlinEngine.h"
#include "VacuumBell.h"
#include "StandardBell.h"

class MerlinEngineFactory : public EngineFactory {
public:
	Engine* createVacuumEngine() override;
	Engine* createStandardEngine() override;
};

#endif
