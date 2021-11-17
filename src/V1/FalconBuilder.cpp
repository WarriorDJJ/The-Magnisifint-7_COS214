#include "FalconBuilder.h"

void FalconBuilder::createRocket() {
    double wet = 0;//needs falcon 9 values
    double dry = 0;
    double fuel = 0;
    string name = "Falcon 9";
    rocket = new Rocket(fuel, wet, dry, name);//to here
}

void FalconBuilder::createEngines() {
	// TODO - implement FalconBuilder::createEngines
	throw "Not yet implemented";
}
