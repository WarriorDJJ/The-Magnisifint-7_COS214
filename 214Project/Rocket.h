#ifndef ROCKET_H
#define ROCKET_H

class Rocket : SpaceCraft {

public:
	SpaceCraft* NextStage;
	Vector<Engine*> engines;
public:
	int Fuel;

	void Activate();

	void clone();
};

#endif
