#ifndef SPACECRAFT_H
#define SPACECRAFT_H

class SpaceCraft {

private:
	bool isFinalStage;

public:
	void AddStage(SpaceCraft* s);

	void SeperateStage();

	SpaceCraft* GetNextStage();

	void LoadFuel();

	int GetFuel();

	void VentFuel();

	void Activate();

	void clone();
};

#endif
