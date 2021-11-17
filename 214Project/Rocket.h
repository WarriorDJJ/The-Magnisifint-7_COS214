#ifndef ROCKET_H
#define ROCKET_H

using namespace std;
#include <vector>
#include "SpaceCraft.h"
#include "Engine.h"
#include <string>

class Rocket : public SpaceCraft {

private:
    double fuel;
    double wetMass;
    double dryMass;
	SpaceCraft* NextStage;
    string name;

public:
    vector<Engine*> engines;
    Rocket(double f, double wm, double dm, string n);
	void Activate();
	void clone();
};

#endif
