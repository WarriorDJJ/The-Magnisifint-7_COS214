#ifndef ROCKET_H
#define ROCKET_H
using namespace std;
#include <vector>
#include "SpaceCraft.h"
#include "Engine.h"

class Rocket : public SpaceCraft {

public:
	SpaceCraft* NextStage;
	vector<Engine*> engines;
public:
	int Fuel;

	void Activate();

	void clone();
};

#endif
