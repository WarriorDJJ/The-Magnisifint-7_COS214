#include "FalconHeavyBuilder.h"
#include <iostream>

using namespace std;

void FalconHeavyBuilder::createRocket() {
    string name = "Falcon 9";

    EngineFactory* eFact = new MerlinEngineFactory();
    Rocket* lb = new Rocket(name);
    LeftBooster = lb;
    for(int i = 0; i < 9; i++)
    {
        Engine* temp = eFact->createStandardEngine();
        temp->setSpacecraft(LeftBooster);
        LeftBooster->AddEngine(temp);
    }

    Rocket* rb = new Rocket(name);
    RightBooster = rb;
    for(int i = 0; i < 9; i++)
    {
        Engine* temp = eFact->createStandardEngine();
        temp->setSpacecraft(RightBooster);
        RightBooster->AddEngine(temp);
    }

	rocket = new FalconHeavy(lb, rb);

    delete eFact;
}

void FalconHeavyBuilder::createEngines(){

    if(rocket == nullptr)
    {
        cout<<"Rocket is empty, please create it!"<<endl;
        return;
    }
    else
    {
        EngineFactory* eFact = new MerlinEngineFactory();
        for(int i = 0; i < 9; i++)
        {
            Engine* temp = eFact->createStandardEngine();
            temp->setSpacecraft(rocket);
            rocket->AddEngine(temp);
        }
        delete eFact;
    }
}

Rocket* FalconHeavyBuilder::getLeft() {
    return LeftBooster;
}

Rocket* FalconHeavyBuilder::getRight() {
    return RightBooster;
}

Rocket *FalconHeavyBuilder::getRocket() {
    return rocket;
}
