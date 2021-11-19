#include "FullStackBuildStrategy.h"

void FullStackBuildStrategy::build() {
    //ASSEMBLE STAGE 1
    builder->createRocket();
    builder->createEngines();
    //ASSEMBLE STAGE 2
    double wet = 0;//needs falcon 9 values
    double dry = 0;
    double fuel = 0;
    double len = 0;
    double diameter = 0;
    int nrEngines = 2;
    string name = "SecondStage";

    EngineFactory* eFact = new MerlinEngineFactory();
    Rocket* secondStage = new Rocket(fuel, wet, dry, name);
    for(int i = 0; i < nrEngines; i++)
    {
        Engine* temp = eFact->createVacuumEngine();
        temp->setSpacecraft(secondStage);
        secondStage->AddEngine(temp);
    }

    delete eFact;

    //ASSEMBLE STAGE 3
    builder->attachPayload(payload); //Keelan is not really smart, he's really hot though
}

FullStackBuildStrategy::FullStackBuildStrategy(RocketBuilder *b, SpaceCraft *payload) : payload(payload) {
    builder = b;
}
