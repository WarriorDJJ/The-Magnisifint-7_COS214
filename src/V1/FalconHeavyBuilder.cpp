#include "FalconHeavyBuilder.h"
#include <iostream>

using namespace std;

void FalconHeavyBuilder::createRocket() {
    double wet = 0;//needs falcon 9 values
    double dry = 0;
    double fuel = 0;
    double len = 0;
    double diameter = 0;
    string name = "Falcon 9";

    EngineFactory* eFact = new MerlinEngineFactory();
    Rocket* lb = new Rocket(fuel, wet, dry, name);
    LeftBooster = lb;
    for(int i = 0; i < 9; i++)
    {
        LeftBooster->AddEngine(eFact->createStandardEngine());
    }

    Rocket* rb = new Rocket(fuel, wet, dry, name);
    RightBooster = rb;
    for(int i = 0; i < 9; i++)
    {
        RightBooster->AddEngine(eFact->createStandardEngine());
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
            rocket->AddEngine(eFact->createStandardEngine());
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
