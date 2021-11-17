#ifndef MERLINENGINEFACTORY_H
#define MERLINENGINEFACTORY_H

class MerlinEngineFactory : public EngineFactory {


public:
	Engine* createVacuumEngine();

	Engine* createStandardEngine();
};

#endif
