#include "FalconBuilder.h"

void FalconBuilder::createRocket() {
    double wet = 0;//needs falcon 9 values
    double dry = 0;
    double fuel = 0;
    string name = "Falcon 9";
    rocket = new Rocket(fuel, wet, dry, name);//to here
}

void FalconBuilder::createEngines() {
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
