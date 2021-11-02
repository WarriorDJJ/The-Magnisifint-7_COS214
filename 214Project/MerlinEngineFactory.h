#ifndef MERLINENGINEFACTORY_H
#define MERLINENGINEFACTORY_H

class MerlinEngineFactory : EngineFactory {


public:
	Engine* createVacuumEngine();

	Engine* createStandardEngine();
};

#endif
