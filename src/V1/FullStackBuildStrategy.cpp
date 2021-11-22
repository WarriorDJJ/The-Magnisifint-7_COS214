#include "FullStackBuildStrategy.h"

void FullStackBuildStrategy::build() {
    //ASSEMBLE STAGE 1
    builder->createRocket();
    builder->createEngines();
    //ASSEMBLE STAGE
    int nrEngines = 1;
    string name = "SecondStage";

    EngineFactory* eFact = new MerlinEngineFactory();
    Rocket* secondStage = new Rocket(name);
    for(int i = 0; i < nrEngines; i++)
    {
        Engine* temp = eFact->createVacuumEngine();
        temp->setSpacecraft(secondStage);
        secondStage->AddEngine(temp);
    }

    delete eFact;

    builder->appStage(secondStage);
    //ASSEMBLE STAGE 3
    builder->attachPayload(payload); //Keelan is not really smart, he's also not really hot
}

FullStackBuildStrategy::FullStackBuildStrategy(RocketBuilder *b, SpaceCraft *payload) : payload(payload) {
    builder = b;
}
