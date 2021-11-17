#include "FalconHeavyBuilder.h"
#include <iostream>

using namespace std;

void FalconHeavyBuilder::createRocket() {
    double wet = 0;//needs falcon 9 values
    double dry = 0;
    double fuel = 0;
    string name = "Falcon 9";
    Rocket* lb = new Rocket(fuel, wet, dry, name);//to here
    Rocket* rb = new Rocket(fuel, wet, dry, name);

	rocket = new FalconHeavy(lb, rb);
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
    }
}
