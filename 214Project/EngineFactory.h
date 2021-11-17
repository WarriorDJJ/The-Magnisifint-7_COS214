#ifndef ENGINEFACTORY_H
#define ENGINEFACTORY_H
#include "Engine.h"
class EngineFactory {

public:
	virtual Engine* createVacuumEngine() = 0;

	 virtual Engine* createStandardEngine() = 0;
};

#endif
