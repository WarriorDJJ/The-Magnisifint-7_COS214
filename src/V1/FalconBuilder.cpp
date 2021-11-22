#include "FalconBuilder.h"

void FalconBuilder::createRocket(){
    string name = "Falcon 9";
    rocket = new Rocket(name);//to here
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
            Engine* temp = eFact->createStandardEngine();
            temp->setSpacecraft(rocket);
            rocket->AddEngine(temp);
        }
        delete eFact;
    }
}
