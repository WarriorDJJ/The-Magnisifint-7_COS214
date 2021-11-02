#ifndef FALCONHEAVY_H
#define FALCONHEAVY_H

class FalconHeavy : Rocket {

private:
	Rocket* LeftBooster;
	Rocket* RightBooster;

public:
	void SeperateStage();

	void Activate();

	void clone();
};

#endif
