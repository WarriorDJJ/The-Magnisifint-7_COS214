#ifndef ROCKET_H
#define ROCKET_H

#include <vector>
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
