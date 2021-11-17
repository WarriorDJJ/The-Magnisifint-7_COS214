#ifndef ENGINEFACTORY_H
#define ENGINEFACTORY_H

class EngineFactory {


public:
	Engine* createVacuumEngine();

	Engine* createStandardEngine();
};

#endif
